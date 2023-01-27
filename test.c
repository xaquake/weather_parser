#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "weather_parser.c"

#define curl curl_easy_init()
#define clearmem(buff)                     \
	{                                      \
		memset(&buff[0], 0, sizeof(buff)); \
	}

int main(void)
{
	const char *cities[5] = {
		"Sochi", "Moscow", "Perm",
		"Solikamsk", "Ekaterinburg"
	};
	CURL *curl;
	for (int i = 0; i < sizeof(*cities) + 1; i++)
	{
		char buff[WEATHER_SIZE];
		get_weather(curl, "YOUR API KEY", cities[i], &*(char *)buff);
		char temp[TEMP_SIZE];
		parse_weather_data(buff, CURRENT, TEMP_C, strlen(buff), &*(char *)temp);
		printf("Temp in %s: %s °C\n", cities[i], temp);
		clearmem(*(char *)&buff);
		clearmem(*(char *)&temp);
	}
	goto END;
END:
	printf("Parsing of %d objects is over", sizeof(*cities) + 1);
	return 0;
}
