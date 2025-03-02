#ifndef __POKEMON_TCG_SDK_QUERY__
#define __POKEMON_TCG_SDK_QUERY__

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "Api.hpp"

namespace pokemon_tcg_sdk {
    namespace Query {
        nlohmann::json find(API* api, std::string url, std::string id);

        template <typename T>
        std::vector<T> where(API api, nlohmann::json query, std::string url);

        template <typename T>
        std::vector<T> where(API api, std::string query, std::string url);

        template <typename T>
        //std::vector<T> all(API* api, std::string url, std::string orderBy = "", std::string select = "");
        std::vector<T> all(API* api, std::string url, std::string orderBy, std::string select){
            std::vector<T> ret;
            std::string queryParams = "";
            queryParams += orderBy == "" ? "" : "&orderby=" + orderBy;
            queryParams += select == "" ? "" : "&select=" + select;
            int total = INT_MAX;
            int count = 0;
            int page = 1;
            nlohmann::json resp = api -> get(url + "?page=" + std::to_string(page) + queryParams, nlohmann::json::parse("{}"));
            while (count < total) {
                try {
                    if (!resp.is_null()){
                        int addCount = resp.at("count");
                        nlohmann::json data = resp.at("data");
                        // std::cout << data<< std::endl;
                        for (nlohmann::json::iterator it = data.begin(); it != data.end(); ++it){
                            std::cout << *it << std::endl;
                            ret.push_back(*it);
                        }
                        //ret.push_back(data.template get<T>());
                        if (total == INT_MAX){
                            total = resp.at("total");
                        }
                        count += addCount;
                        page++;
                    }    
                } catch (nlohmann::json::basic_json::out_of_range ex){
                    std::cout << "Data not found: " << ex.what() << std::endl;
                    break;
                }
            }
            return ret;
        }
    };
};

#endif /*__POKEMON_TCG_SDK_QUERY__*/