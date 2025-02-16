#include "Api.hpp"

namespace pokemon_tcg_sdk {
    API::API(){
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curlHandler = curl_easy_init();
        if (!curlHandler){
            curl_global_cleanup();
            throw std::runtime_error("CURL failed to initialize.");
        }
    }

    API::~API(){
        curl_easy_cleanup(curlHandler);
        curl_global_cleanup();
    }

    nlohmann::json API::get(std::string url, nlohmann::json data){
        curl_easy_setopt(curlHandler, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curlHandler, CURLOPT_CA_CACHE_TIMEOUT, 604800L);
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, ("X-Api-Key: " + API_KEY).c_str());
        std::string response;
        curl_easy_setopt(curlHandler, CURLOPT_WRITEFUNCTION, this -> curlWriteCallback);
        curl_easy_setopt(curlHandler, CURLOPT_WRITEDATA, &response);
        CURLcode resp = curl_easy_perform(curlHandler);
        if (resp != CURLE_OK){
            std::cerr << "Failed to perfrom HTTP(S) GET request. ErrorNo: " << resp << std::endl;
            return nlohmann::json::parse("null");
        }
        // std::cout << response.str() << std::endl;
        return nlohmann::json::parse(response);
    }

    size_t API::curlWriteCallback(char* data, size_t size, size_t nmemb, void* userdata){
        ((std::string*)userdata) -> append(data, size * nmemb);
        return size * nmemb;
    }

}
