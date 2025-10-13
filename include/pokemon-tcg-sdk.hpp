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

// Check if the API key was compiled in
#ifndef POKEMON_TCG_SDK_API_KEY
    /**
     * @brief The define for the API key, can either be compiled in or set as an environment variable
     */
    #define POKEMON_TCG_SDK_API_KEY std::getenv("POKEMON_TCG_API_KEY")
#endif

#include <pokemon-tcg-sdk-cpp/Api.hpp>
#include <pokemon-tcg-sdk-cpp/api/Query.hpp>
#include <pokemon-tcg-sdk-cpp/api/URLS.hpp>
#include <pokemon-tcg-sdk-cpp/Card.hpp>
#include <pokemon-tcg-sdk-cpp/Legalities.hpp>
#include <pokemon-tcg-sdk-cpp/Set.hpp>
#include <pokemon-tcg-sdk-cpp/Rarities.hpp>
#include <pokemon-tcg-sdk-cpp/SubTypes.hpp>
#include <pokemon-tcg-sdk-cpp/SuperTypes.hpp>
#include <pokemon-tcg-sdk-cpp/Types.hpp>

/**
 * @brief The main namespace for the API, to avoid collisions with other similar named objects
 */
namespace pokemon_tcg_sdk {};

#endif /*__POKEMON_TCG_SDK__*/
/**
 * @}
 */