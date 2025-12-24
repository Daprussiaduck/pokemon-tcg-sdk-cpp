/**
 * @file Rarities.hpp
 * 
 * @brief This contains the definition for the Rarities of the API
 * 
 * @author Daprussiaduck
 */
#ifndef __RARITIES_HPP__
#define __RARITIES_HPP__

// Standard Library includes
#include <string>
#include <vector>

// External Library includes

// Current Library includes


namespace pokemon_tcg_sdk {

    /**
     * @brief The Rarities of the Pokemon Cards
     */
    namespace Rarities {
        /**
         * @brief Returns a list of all of the different Rarities that the Pokemon TCG SDK assigns to cards
         * 
         * https://docs.pokemontcg.io/api-reference/rarities/get-rarities#sample-response
         * 
         * @return A list of the given rarity information
         */
        std::vector<std::string> all();
    };
};

#endif /*__RARITIES_HPP__*/