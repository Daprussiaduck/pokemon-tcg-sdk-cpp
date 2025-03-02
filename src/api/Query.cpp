#include "api/Query.hpp"

namespace pokemon_tcg_sdk {
    namespace Query {
        nlohmann::json find(API* api, std::string url, std::string id){
            std::cout << "URL: " << url + id << std::endl;
            nlohmann::json response = api -> get(url + id, nlohmann::json::parse("{}"));
            return response;
        }        
    };
};