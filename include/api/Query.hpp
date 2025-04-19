#ifndef __POKEMON_TCG_SDK_QUERY__
#define __POKEMON_TCG_SDK_QUERY__

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include <pokemon-tcg-sdk-cpp/Api.hpp>

namespace pokemon_tcg_sdk {
    namespace Query {
        /**
         * Finds something using the API, returns it as a JSON object
         * https://docs.pokemontcg.io/api-reference/cards/get-card#http-request
         * @param api A pointer to the API object to use
         * @param url The URL to look at (Cards, Sets, etc.)
         * @param id The ID to return (if it exists)
         * 
         * @return The object with ID from the given URL as a JSON object, if it was found
         */
        nlohmann::json find(API* api, std::string url, std::string id);

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
        std::vector<T> where(API* api, nlohmann::json query, std::string url, std::string orderBy = "", std::string select = ""){
            std::string queryStr = "";
            for (nlohmann::json::iterator it = query.begin(); it != query.end(); ++it){
                queryStr += it.key() + ":" + (std::string)it.value() + " ";
            }
            return where<T>(api, queryStr, url, orderBy, select);
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
        std::vector<T> where(API* api, std::string query, std::string url, std::string orderBy = "", std::string select = ""){
            std::vector<T> ret;
            int total = INT_MAX;
            int count = 0;
            int page = 1;
            std::string queryParams = "&q=" + query;
            queryParams += orderBy == "" ? "" : "&orderby=" + orderBy;
            queryParams += select == "" ? "" : "&select=" + select;
            while (count < total){
                nlohmann::json resp = api -> get(url + "?page=" + std::to_string(page) + queryParams, nlohmann::json::parse("{}"));
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
         * Returns all of the objects from the given URL
         * @param api A pointer to the API object to use
         * @param url The URL to look at (Cards, Sets, etc.)
         * @param orderBy What should the returned objects be sorted by? (https://docs.pokemontcg.io/api-reference/cards/search-cards/#ordering-data)
         * @param select What data should the returned objects contain? (https://docs.pokemontcg.io/api-reference/cards/search-cards/#query-parameters) 
         * 
         * @return All of the objects at the given URL
         */
        template <typename T>
        std::vector<T> all(API* api, std::string url, std::string orderBy = "", std::string select = ""){
            std::vector<T> ret;
            std::string queryParams = "";
            queryParams += orderBy == "" ? "" : "&orderby=" + orderBy;
            queryParams += select == "" ? "" : "&select=" + select;
            int total = INT_MAX;
            int count = 0;
            int page = 1;
            while (count < total) {
                nlohmann::json resp = api -> get(url + "?page=" + std::to_string(page) + queryParams, nlohmann::json::parse("{}"));
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
    };
};

#endif /*__POKEMON_TCG_SDK_QUERY__*/