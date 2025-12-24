/**
 * @file pokemon-tcg-sdk.hpp
 * 
 * @brief The main include to use the SDK, includes every thing to use the SDK in a project
 * 
 * @author Daprussiaduck
 * 
 * @defgroup pokemon-tcg-sdk-cpp Pokemon TCG SDK for C++
 * @brief The Pokemon TCG SDK written for C++
 * @{
 */
#ifndef __POKEMON_TCG_SDK__
#define __POKEMON_TCG_SDK__

// Standard Library includes

// External Library includes

// Check if the API key was compiled in
#ifndef POKEMON_TCG_SDK_API_KEY
    /**
     * @brief The define for the API key, can either be compiled in or set as an environment variable
     */
    #define POKEMON_TCG_SDK_API_KEY std::getenv("POKEMON_TCG_API_KEY")
#endif

// Current Library includes
#include "Card.hpp"
#include "Legalities.hpp"
#include "Query.hpp"
#include "Rarities.hpp"
#include "Set.hpp"
#include "SubTypes.hpp"
#include "SuperTypes.hpp"
#include "Types.hpp"

/**
 * @brief The main namespace for the API, to avoid collisions with other similar named objects
 */
namespace pokemon_tcg_sdk {};

#endif /*__POKEMON_TCG_SDK__*/
/**
 * @}
 */