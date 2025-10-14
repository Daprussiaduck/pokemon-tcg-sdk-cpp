/**
 * @file SubTypes.hpp
 * 
 * @brief This file contains the namespace and functions for a Card's SubType
 * 
 * @author Daprussiaduck
 */
#ifndef __SUBTYPES_HPP__
#define __SUBTYPES_HPP__

#include <string>
#include <vector>

namespace pokemon_tcg_sdk {

    /**
     * @brief The SubType of the Card
     */
    namespace SubTypes {

        /**
         * @brief Returns a list of all of the different Subtypes that the Pokemon TCG SDK assigns to cards
         * 
         * https://docs.pokemontcg.io/api-reference/subtypes/get-subtypes#sample-response
         * 
         * @return A list of the given subtype information
         */
        std::vector<std::string> all();
    };
};

#endif /*__SUBTYPES_HPP__*/