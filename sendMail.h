#pragma once
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

#define FROM_ADDR    fromAddress
#define TO_ADDR      toAddress
#define FROM_MAIL "DFSL PLS " FROM_ADDR
#define TO_MAIL   "moshe " TO_ADDR

static char payload_text[11][70] = { "\0" };

struct upload_status {
    int lines_read;
};

static size_t payload_source(void* ptr, size_t size, size_t nmemb, void* userp)
{
    struct upload_status* upload_ctx = (struct upload_status*)userp;
    const char* data;

    if ((size == 0) || (nmemb == 0) || ((size * nmemb) < 1)) {
        return 0;
    }

    data = payload_text[upload_ctx->lines_read];

    if (data) {
        size_t len = strlen(data);
        memcpy(ptr, data, len);
        upload_ctx->lines_read++;

        return len;
    }

    return 0;
}

inline int sendMailSMTP(char fromAddress[], char toAddress[], char smtp[], char userName[], char password[], float azimuth, float range)
{

    CURL* curl;
    CURLcode res = CURLE_OK;
    struct curl_slist* recipients = NULL;
    struct upload_status upload_ctx;

    char azimuthChar[10];
    sprintf(azimuthChar, "%f", azimuth);
   
    char rangeChar[10]; 
    sprintf(rangeChar, "%f", range);

    sprintf(payload_text[0], "Date: Mon, 29 Nov 2010 21:54:29 +1100\r\n");
    sprintf(payload_text[1], "To: %s \r\n", toAddress);
    sprintf(payload_text[2], "From: %s \r\n", fromAddress);
    sprintf(payload_text[3], "Message-ID: <dcd7cb36-11db-487a-9f3a-e652a9458efd@");
    sprintf(payload_text[4], "rfcpedant.example.org>\r\n");
    sprintf(payload_text[5], "Subject: Intruder Deteced\r\n");
    sprintf(payload_text[6], "\r\n");
    sprintf(payload_text[7], "Intruder detected at range %f azimith %f.\r\n",range, azimuth);
    sprintf(payload_text[8], "\r\n");
   
    upload_ctx.lines_read = 0;

    curl = curl_easy_init();
    if (curl) {
       
        curl_easy_setopt(curl, CURLOPT_URL, smtp);
        curl_easy_setopt(curl, CURLOPT_USERNAME, userName);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
        
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, fromAddress);

        recipients = curl_slist_append(recipients, toAddress);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
        curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        //Send the message 
        res = curl_easy_perform(curl);

        //Check for errors
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

        curl_slist_free_all(recipients);

        curl_easy_cleanup(curl);
    }

    return (int)res;
}

