/**
 * @file SuperTypes.hpp
 * 
 * @brief This file contains the SuperTypes namespace and included API calls
 * 
 * @author Daprussiaduck
 */
#ifndef __SUPERTYPES_HPP__
#define __SUPERTYPES_HPP__

// Standard Library includes
#include <string>
#include <vector>

// External Library includes

// Current Library includes

namespace pokemon_tcg_sdk {
    
    /**
     * @brief The SuperType of the Card
     */
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