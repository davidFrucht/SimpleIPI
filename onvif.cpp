#include "onvif.h"
#include <curl/curl.h>
#include <string>


#define MOVE_TILT 0
#define MOVE_PAN 1

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define STOP_MOVEMENT 5
#define ZOOM_IN 6
#define ZOOM_OUT 7

char post[100];
char* urlOnvifCamera;
char* userNameOnVif;
char* passwordOnVif;
std::string profileOnVif;

inline void onvifInit(char post[100]);

void moveDirection(int direction)
{
	switch (direction)
	{
	case UP:
		sprintf(post, "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope xmlns:s=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:tptz=\"http://www.onvif.org/ver20/ptz/wsdl\" xmlns:tt=\"http://www.onvif.org/ver10/schema\"> <s:Body> <tptz:ContinuousMove> <tptz:ProfileToken>%s</tptz:ProfileToken> <tptz:Velocity> <tt:PanTilt y=\"1\" /></tptz:Velocity> TIMEOUT </tptz:ContinuousMove></s:Body></s:Envelope>", profileOnVif.c_str());
		break;
	case DOWN:
		sprintf(post, "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope xmlns:s=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:tptz=\"http://www.onvif.org/ver20/ptz/wsdl\" xmlns:tt=\"http://www.onvif.org/ver10/schema\"> <s:Body> <tptz:ContinuousMove> <tptz:ProfileToken>%s</tptz:ProfileToken> <tptz:Velocity> <tt:PanTilt y=\"-1\" /></tptz:Velocity> TIMEOUT </tptz:ContinuousMove></s:Body></s:Envelope>", profileOnVif.c_str());
		break;
	case LEFT:
		sprintf(post, "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope xmlns:s=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:tptz=\"http://www.onvif.org/ver20/ptz/wsdl\" xmlns:tt=\"http://www.onvif.org/ver10/schema\"> <s:Body> <tptz:ContinuousMove> <tptz:ProfileToken>%s</tptz:ProfileToken> <tptz:Velocity> <tt:PanTilt x=\"-1\" /></tptz:Velocity> TIMEOUT </tptz:ContinuousMove></s:Body></s:Envelope>", profileOnVif.c_str());
		break;
	case RIGHT:
		sprintf(post, "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope xmlns:s=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:tptz=\"http://www.onvif.org/ver20/ptz/wsdl\" xmlns:tt=\"http://www.onvif.org/ver10/schema\"> <s:Body> <tptz:ContinuousMove> <tptz:ProfileToken>%s</tptz:ProfileToken> <tptz:Velocity> <tt:PanTilt x=\"1\" /></tptz:Velocity> TIMEOUT </tptz:ContinuousMove></s:Body></s:Envelope>", profileOnVif.c_str());
		break;
	case STOP_MOVEMENT:
		sprintf(post, "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope xmlns:s=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:tptz=\"http://www.onvif.org/ver20/ptz/wsdl\" xmlns:tt=\"http://www.onvif.org/ver10/schema\"> <s:Body> <tptz:Stop> <tptz:ProfileToken>%s</tptz:ProfileToken> <tptz:PanTilt>true</tptz:PanTilt> <tptz:Zoom>true</tptz:Zoom> </tptz:Stop></s:Body></s:Envelope>", profileOnVif.c_str());
		break;
	case ZOOM_IN:
		sprintf(post, "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope xmlns:s=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:tptz=\"http://www.onvif.org/ver20/ptz/wsdl\" xmlns:tt=\"http://www.onvif.org/ver10/schema\"> <s:Body> <tptz:ContinuousMove> <tptz:ProfileToken>%s</tptz:ProfileToken> <tptz:Velocity> <tt:Zoom x=\"1\" /></tptz:Velocity> TIMEOUT </tptz:ContinuousMove></s:Body></s:Envelope>", profileOnVif.c_str());
		break;
	case ZOOM_OUT:
		sprintf(post, "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope xmlns:s=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:tptz=\"http://www.onvif.org/ver20/ptz/wsdl\" xmlns:tt=\"http://www.onvif.org/ver10/schema\"> <s:Body> <tptz:ContinuousMove> <tptz:ProfileToken>%s</tptz:ProfileToken> <tptz:Velocity> <tt:Zoom x=\"-1\" /></tptz:Velocity> TIMEOUT </tptz:ContinuousMove></s:Body></s:Envelope>", profileOnVif.c_str());
		break;
	}

	onvifInit(post);
}

void moveDirectionAbselute(int var, int axisPanTiltOrZoom)
{
	float degreesToMove;

	if (var > 180)
		degreesToMove = ((1 * float(var)) / 359);
	if (var == 180)
		degreesToMove = 0;
	if (var < 180)
		degreesToMove = (-1 * float(var)) / 359;

	switch (axisPanTiltOrZoom)
	{
	case MOVE_TILT:
		sprintf(post, "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope xmlns:s=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:tptz=\"http://www.onvif.org/ver20/ptz/wsdl\" xmlns:tt=\"http://www.onvif.org/ver10/schema\"> <s:Body> <tptz:AbsoluteMove> <tptz:ProfileToken>%s</tptz:ProfileToken> <tptz:Velocity> <tt:PanTilt y=\"%.2f\" /></tptz:Velocity> TIMEOUT </tptz:ContinuousMove></s:Body></s:Envelope>", profileOnVif.c_str(), degreesToMove);
		break;

	case MOVE_PAN:
		sprintf(post, "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope xmlns:s=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:tptz=\"http://www.onvif.org/ver20/ptz/wsdl\" xmlns:tt=\"http://www.onvif.org/ver10/schema\"> <s:Body> <tptz:AbsoluteMove> <tptz:ProfileToken>%s</tptz:ProfileToken> <tptz:Position> <tt:PanTilt x=\"%.2f\" y=\"1\"/> </tptz:Position>  </tptz:AbsoluteMove></s:Body></s:Envelope>", profileOnVif.c_str(), degreesToMove);
		break;
	}
	onvifInit(post);

}

inline void onvifInit(char post[100])
{
	CURL* curl;
	CURLcode res;

	curl = curl_easy_init();

	if (curl)
	{
		struct curl_slist* slist = NULL;

		slist = curl_slist_append(slist, "Accept: */*");
		slist = curl_slist_append(slist, "Content-Type: application/x-www-form-urlencoded");
		slist = curl_slist_append(slist, "Content-Type: text/xml");

		curl_easy_setopt(curl, CURLOPT_USERNAME, userNameOnVif);
		curl_easy_setopt(curl, CURLOPT_PASSWORD, passwordOnVif);
		curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_ANY);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
		curl_easy_setopt(curl, CURLOPT_HEADER, 0);
		curl_easy_setopt(curl, CURLOPT_URL, urlOnvifCamera);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post);
		res = curl_easy_perform(curl);

		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));

		curl_easy_cleanup(curl);
		curl_slist_free_all(slist);

	}
}


