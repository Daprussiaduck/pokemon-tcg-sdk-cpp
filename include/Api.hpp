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
    /**
     * Holds the API_key for the Pokemon TCG SDK
     * https://docs.pokemontcg.io/getting-started/authentication
     */
    static std::string API_KEY = POKEMON_TCG_SDK_API_KEY == NULL ? "" : POKEMON_TCG_SDK_API_KEY;

    class API {
        public:
            /**
             * Constructs a new API object (initializes cURL)
             */
            API();

            /**
             * Destructs an API object (de-initalizes cURL)
             */
            ~API();
            
            /**
             * Essentially just a HTTP get request, but only allows JSON objects back
             */
            nlohmann::json get(std::string url, nlohmann::json data);
        private:
            /**
             * The handler for this usage of cURL
             */
            CURL* curlHandler;

            /**
             * The callback cURL uses to write data into our response
             */
            static size_t curlWriteCallback(char* data, size_t size, size_t nmemb, void* userdata);

    };
};

#endif /*__POKEMON_TCG_SDK_API__*/