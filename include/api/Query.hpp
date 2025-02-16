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
        std::vector<T> all(API api, std::string url);
    };
};

#endif /*__POKEMON_TCG_SDK_QUERY__*/