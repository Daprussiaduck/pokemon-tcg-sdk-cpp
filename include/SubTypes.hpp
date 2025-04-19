#ifndef __SUBTYPES_HPP__
#define __SUBTYPES_HPP__

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include <pokemon-tcg-sdk-cpp/api/URLS.hpp>
#include <pokemon-tcg-sdk-cpp/Api.hpp>

namespace pokemon_tcg_sdk {
    namespace SubTypes {
        /**
         * Returns a list of all of the different Subtypes that the Pokemon TCG SDK assigns to cards
         * https://docs.pokemontcg.io/api-reference/subtypes/get-subtypes#sample-response
         * @param api The API object to use
         * 
         * @return A list of the given subtype information
         */
        std::vector<std::string> all(API* api);
    };
};

#endif /*__SUBTYPES_HPP__*/