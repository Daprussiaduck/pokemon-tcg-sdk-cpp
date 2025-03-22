#ifndef __SUPERTYPES_HPP__
#define __SUPERTYPES_HPP__

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "api/URLS.hpp"
#include "Api.hpp"

namespace pokemon_tcg_sdk {
    namespace SuperTypes {
        /**
         * Returns a list of all of the different SuperTypes that the Pokemon TCG SDK assigns to cards
         * https://docs.pokemontcg.io/api-reference/supertypes/get-supertypes#sample-response
         * @param api The API object to use
         * 
         * @return A list of the given supertype information
         */
        std::vector<std::string> all(API* api);
    };
};

#endif /*__SUPERTYPES_HPP__*/