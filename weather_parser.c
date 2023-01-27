#ifndef WEATHER_PARSER_C
#define WEATHER_PARSER_C

#include "weather_parser.h"

size_t write_callback(const char *ptr, const size_t size, const size_t nmemb, char *restrict userdata)
{
	if (!ptr)
		return 0;
	memcpy(userdata, ptr, size * nmemb);
	return size * nmemb;
};

void get_weather(CURL *curl, const char *api_key, const char *city, char *restrict buff)
{
	char link[120] = "http://api.weatherapi.com/v1/current.json?key=";
	strcat(link, api_key);
	strcat(link, "&q=");
	strcat(link, city);
	strcat(link, "&aqi=no");
	curl_easy_setopt(curl, CURLOPT_URL, link);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, buff);
	curl_easy_perform(curl);
	curl_easy_reset(curl);
	memset(&link[0], 0, sizeof(link));
};

void parse_weather_data(const char *string, const char *symbol, const char *key, const size_t size, char *restrict buff)
{
	memcpy(buff, cJSON_Print(cJSON_GetObjectItemCaseSensitive(cJSON_GetObjectItemCaseSensitive(cJSON_ParseWithLength(string, size), symbol), key)), size);
};

#endif
