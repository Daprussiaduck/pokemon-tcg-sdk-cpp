/**
 * @file Types.hpp
 * 
 * @brief This file includes the Types namespace and the Api calls for Types
 * 
 * @author Daprussiaduck
 */
#ifndef __TYPES_HPP__
#define __TYPES_HPP__

// Standard Library includes
#include <string>
#include <vector>

// External Library includes

// Current Library includes

namespace pokemon_tcg_sdk {

    /**
     * @brief The Types namespace
     */
    namespace Types {

        /**
         * @brief Returns a list of all of the different types that the Pokemon TCG SDK assigns to cards
         * 
         * https://docs.pokemontcg.io/api-reference/types/get-types#sample-response
         * 
         * @return A list of the given type information
         */
        std::vector<std::string> all();
    };
};

#endif /*__TYPES_HPP__*/