#ifndef __POKEMON_TCG_SDK_API__
#define __POKEMON_TCG_SDK_API__

#ifndef POKEMON_TCG_SDK_API_KEY
    #define POKEMON_TCG_SDK_API_KEY std::getenv("POKEMON_TCG_API_KEY")
#endif

#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>

namespace pokemon_tcg_sdk {

    static std::string API_KEY = POKEMON_TCG_SDK_API_KEY == NULL ? "" : POKEMON_TCG_SDK_API_KEY;

    struct CURL_Memory {
        char* response;
        size_t size;
    };

    class API {
        public:
            API();
            ~API();

            nlohmann::json get(std::string url, nlohmann::json data);
        private:
            CURL* curlHandler;
            static size_t curlWriteCallback(char* data, size_t size, size_t nmemb, void* userdata);

    };
};

#endif /*__POKEMON_TCG_SDK_API__*/