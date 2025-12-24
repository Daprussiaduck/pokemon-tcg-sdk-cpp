/**
 * @file Query.hpp
 * 
 * @brief This file contains the function declarations and template definitions for the Queries
 */
#ifndef __POKEMON_TCG_SDK_QUERY__
#define __POKEMON_TCG_SDK_QUERY__

// Standard Library includes
#include <string>
#include <vector>

// External Library includes
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

// Current Library includes

namespace pokemon_tcg_sdk {

    /**
     * @brief This namespace is to contain the API requests
     */
    namespace Query {

        /**
         * Returns all of the objects from the given URL
         * @param api A pointer to the API object to use
         * @param url The URL to look at (Cards, Sets, etc.)
         * @param orderBy What should the returned objects be sorted by? (https://docs.pokemontcg.io/api-reference/cards/search-cards/#ordering-data)
         * @param select What data should the returned objects contain? (https://docs.pokemontcg.io/api-reference/cards/search-cards/#query-parameters) 
         * 
         * @return All of the objects at the given URL
         */
        template <typename T>
        std::vector<T> all(std::string url, std::string orderBy = "", std::string select = ""){
            std::vector<T> ret;
            int total = INT_MAX;
            int count = 0;
            int page = 1;
            while (count < total) {
                cpr::Parameters params;
                // TODO: Better way to do this?
                if (orderBy == "" && select == ""){
                    params = cpr::Parameters{{"page", std::to_string(page)}, {"orderBy", orderBy}, {"select", select}};
                } else if (orderBy == "") {
                    params = cpr::Parameters{{"page", std::to_string(page)}, {"orderBy", orderBy}};
                } else if (select == ""){
                    params = cpr::Parameters{{"page", std::to_string(page)}, {"select", select}};
                } else {
                    params = cpr::Parameters{{"page", std::to_string(page)}};
                }
                cpr::Response apiResp = cpr::Get(cpr::Url{url}, cpr::Header{{"X-Api-Key", POKEMON_TCG_SDK_API_KEY}}, params);
                if(apiResp.response_code != 200 || !(apiResp.header["Content-Type"].contains("application/json"))){
                    break;
                }
                nlohmann::json resp = nlohmann::json::parse(apiResp.text);
                try {
                    if (!resp.is_null()){
                        int addCount = resp.at("count");
                        nlohmann::json data = resp.at("data");
                        // std::cout << data<< std::endl;
                        for (nlohmann::json::iterator it = data.begin(); it != data.end(); ++it){
                            //std::cout << *it << std::endl;
                            ret.push_back(*it);
                        }
                        //ret.push_back(data.template get<T>());
                        if (total == INT_MAX){
                            total = resp.at("totalCount");
                        }
                        count += addCount;
                        // std::cout << "Found " << count << " out of " << total << " Cards in " << page << " pages." << std::endl;
                        page++;
                    } else {
                        break;
                    }
                } catch (nlohmann::json::basic_json::out_of_range ex){
                    // std::cout << "Data not found: " << ex.what() << std::endl;
                    break;
                }
            }
            // std::cout << "Found " << count << " out of " << total << " Cards" << std::endl;
            return ret;
        }

        /**
         * Returns all of the cards that match the given query
         * https://docs.pokemontcg.io/api-reference/cards/search-cards/
         * @param api A pointer to the API object to use
         * @param query The query to search for as a string
         * @param url The URL to look at (Cards, Sets, etc.)
         * @param orderBy What should the returned objects be sorted by? (https://docs.pokemontcg.io/api-reference/cards/search-cards/#ordering-data)
         * @param select What data should the returned objects contain? (https://docs.pokemontcg.io/api-reference/cards/search-cards/#query-parameters) 
         * 
         * @return The objects that match the query at the given URL
         */
        template <typename T>
        std::vector<T> where(std::string query, std::string url, std::string orderBy = "", std::string select = ""){
            std::vector<T> ret;
            int total = INT_MAX;
            int count = 0;
            int page = 1;
            while (count < total){
                cpr::Parameters params;
                // TODO: Better way to do this?
                if (orderBy == "" && select == ""){
                    params = cpr::Parameters{{"page", std::to_string(page)}, {"orderBy", orderBy}, {"select", select}};
                } else if (orderBy == "") {
                    params = cpr::Parameters{{"page", std::to_string(page)}, {"orderBy", orderBy}};
                } else if (select == ""){
                    params = cpr::Parameters{{"page", std::to_string(page)}, {"select", select}};
                } else {
                    params = cpr::Parameters{{"page", std::to_string(page)}}
                }
                cpr::Response apiResp = cpr::Get(cpr::Url{url}, cpr::Header{{"X-Api-Key", POKEMON_TCG_SDK_API_KEY}}, params);
                if(apiResp.response_code != 200 || !(apiResp.header["Content-Type"].contains("application/json"))){
                    break;
                }
                nlohmann::json resp = nlohmann::json::parse(apiResp.text);
                try {
                    if (!resp.is_null()){
                        int addCount = resp.at("count");
                        nlohmann::json data = resp.at("data");
                        for (nlohmann::json::iterator it = data.begin(); it != data.end(); ++it){
                            ret.push_back(*it);
                        }
                        if (total == INT_MAX){
                            total = resp.at("totalCount");
                        }
                        count += addCount;
                        page++;
                    } else {
                        break;
                    }
                } catch (nlohmann::json::basic_json::out_of_range ex){
                    break;
                }
            }
            return ret;
        }

        /**
         * Returns all of the cards that match the given query
         * https://docs.pokemontcg.io/api-reference/cards/search-cards/
         * @param api A pointer to the API object to use
         * @param query The query to search for as a JSON object
         * @param url The URL to look at (Cards, Sets, etc.)
         * @param orderBy What should the returned objects be sorted by? (https://docs.pokemontcg.io/api-reference/cards/search-cards/#ordering-data)
         * @param select What data should the returned objects contain? (https://docs.pokemontcg.io/api-reference/cards/search-cards/#query-parameters) 
         * 
         * @return The objects that match the query at the given URL
         */
        template <typename T>
        std::vector<T> where(nlohmann::json query, std::string url, std::string orderBy = "", std::string select = ""){
            std::string queryStr = "";
            for (nlohmann::json::iterator it = query.begin(); it != query.end(); ++it){
                queryStr += it.key() + ":" + (std::string)it.value() + " ";
            }
            return where<T>(queryStr, url, orderBy, select);
        }
    };
};

#endif /*__POKEMON_TCG_SDK_QUERY__*/