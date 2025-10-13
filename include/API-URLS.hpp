/**
 * @file API-URLS.hpp
 * 
 * @brief A File containing the collection of URLS the Pokemon TCG API uses
 * 
 * @author Daprussiaduck
 * 
 * @addtogroup pokemon-tcg-sdk-cpp
 * @{
 */
#ifndef __POKEMON_TCG_SDK_URLS__
#define __POKEMON_TCG_SDK_URLS__

/**
 * @brief The shared base url for all other urls
 * 
 * https://docs.pokemontcg.io/api-reference/cards/get-card#http-request
 */
#define POKEMON_TCG_SDK_BASE_URL "https://api.pokemontcg.io/v2/"

/**
 * @brief The URL for accessing card objects
 * 
 * https://docs.pokemontcg.io/api-reference/cards/get-card#http-request
 */
#define POKEMON_TCG_SDK_CARDS_URL POKEMON_TCG_SDK_BASE_URL "cards/"

/**
 * @brief The URL for accessing Set objects
 * 
 * https://docs.pokemontcg.io/api-reference/sets/get-set#http-request
 */
#define POKEMON_TCG_SDK_SETS_URL POKEMON_TCG_SDK_BASE_URL "sets/"

/**
 * @brief The URL for accessing Type information
 * 
 * https://docs.pokemontcg.io/api-reference/types/get-types#http-request
 */
#define POKEMON_TCG_SDK_TYPES_URL POKEMON_TCG_SDK_BASE_URL "types/"

/**
 * @brief The URL for accessing SubType information
 * 
 * https://docs.pokemontcg.io/api-reference/subtypes/get-subtypes#http-request
 */
#define POKEMON_TCG_SDK_SUBTYPES_URL POKEMON_TCG_SDK_BASE_URL "subtypes/"

/**
 * @brief The URL for accessing SuperType information
 * 
 * https://docs.pokemontcg.io/api-reference/supertypes/get-supertypes#http-request
 * 
 */
#define POKEMON_TCG_SDK_SUPERTYPES_URL POKEMON_TCG_SDK_BASE_URL "supertypes/"

/**
 * @brief The URL for accessing Rarity information
 * 
 * https://docs.pokemontcg.io/api-reference/rarities/get-rarities#http-request
 */
#define POKEMON_TCG_SDK_RARITIES_URL POKEMON_TCG_SDK_BASE_URL "rarities/"

#endif /*__POKEMON_TCG_SDK_URLS__*/
/**
 * @}
 */