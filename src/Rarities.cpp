/**
 * @file Rarities.cpp
 * 
 * @brief This file contains the function definitions for the rarities
 * 
 * @author Daprussiaduck
 */
#include "Rarities.hpp"

// Standard Library includes

// External Library includes
#include <nlohmann/json.hpp>

// Current Library includes
#include "API-URLS.hpp"

namespace pokemon_tcg_sdk {
    namespace Rarities {
        std::vector<std::string> all(){
            // TODO: cpr
            nlohmann::json resp = api -> get(POKEMON_TCG_SDK_RARITIES_URL, nlohmann::json::parse("{}"));
            std::vector<std::string> ret;
            try {
                if (!resp.is_null()){
                    nlohmann::json data = resp.at("data");
                    ret = data.template get<std::vector<std::string>>();
                }
            } catch (nlohmann::json::basic_json::out_of_range ex){
                std::cout << "Data not found: " << ex.what() << std::endl; 
            }
            return ret;
        }
    };
};