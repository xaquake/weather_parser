#ifndef WEATHER_PARSER_H
#define WEATHER_PARSER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "cJSON.c"

/* json keys for parsing weather */
#define LOCATION "location"
#define CURRENT "current"
#define TEMP_C "temp_c"
#define TEMP_F "temp_h"
#define WIND_MPH "wind_mph"
#define WIND_KPH "wind_kph"
#define WIND_DEGREE "wind_degree"
#define WIND_DIR "wind_dir"
#define PRESSURE_MB "pressure_mb"
#define PRESSURE_IN "pressure_in"
#define HUMIDITY "humidity"
#define CLOUD "cloud"
#define FEELSLIKE_C "feelslike_c"
#define FEESLIKE_F "feelslike_f"

/* recommended buffer size */
#define WEATHER_SIZE 800
#define TEMP_SIZE 10

/* for curl */
size_t write_callback(const char *ptr, const size_t size, const size_t nmemb, char *restrict userdata);

/* getting weather api url response */
void get_weather(CURL *curl, const char *api_key, const char *city, char *restrict buff);

/* parsing response with keys */
void parse_weather_data(const char *string, const char *symbol, const char *key, const size_t size, char *restrict buff);

#ifdef __cplusplus
}
#endif

#endif
