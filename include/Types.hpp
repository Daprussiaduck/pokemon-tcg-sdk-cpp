#ifndef __TYPES_HPP__
#define __TYPES_HPP__

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include <pokemon-tcg-sdk-cpp/api/URLS.hpp>
#include <pokemon-tcg-sdk-cpp/Api.hpp>

namespace pokemon_tcg_sdk {
    namespace Types {
        /**
         * Returns a list of all of the different types that the Pokemon TCG SDK assigns to cards
         * https://docs.pokemontcg.io/api-reference/types/get-types#sample-response
         * @param api The API object to use
         * 
         * @return A list of the given type information
         */
        std::vector<std::string> all(API* api);
    };
};

#endif /*__TYPES_HPP__*/