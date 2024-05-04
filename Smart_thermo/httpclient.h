#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

// Contents of httpclient.h



char* createGetRequest(const char* jsonData);
char* createPostRequest(const char* jsonData);

#endif // HTTPCLIENT_H