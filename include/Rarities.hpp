#ifndef __RARITIES_HPP__
#define __RARITIES_HPP__

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "api/URLS.hpp"
#include "Api.hpp"

namespace pokemon_tcg_sdk {
    namespace Rarities {
        /**
         * Returns a list of all of the different Rarities that the Pokemon TCG SDK assigns to cards
         * https://docs.pokemontcg.io/api-reference/rarities/get-rarities#sample-response
         * @param api The API object to use
         * 
         * @return A list of the given rarity information
         */
        std::vector<std::string> all(API* api);
    };
};

#endif /*__RARITIES_HPP__*/