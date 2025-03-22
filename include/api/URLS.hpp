#ifndef __POKEMON_TCG_SDK_URLS__
#define __POKEMON_TCG_SDK_URLS__

/**
 * The shared base url for all other urls
 * https://docs.pokemontcg.io/api-reference/cards/get-card#http-request
 */
#define POKEMON_TCG_SDK_BASE_URL "https://api.pokemontcg.io/v2/"

/**
 * The URL for accessing card objects
 * https://docs.pokemontcg.io/api-reference/cards/get-card#http-request
 */
#define POKEMON_TCG_SDK_CARDS_URL POKEMON_TCG_SDK_BASE_URL "cards/"

/**
 * The URL for accessing Set objects
 * https://docs.pokemontcg.io/api-reference/sets/get-set#http-request
 */
#define POKEMON_TCG_SDK_SETS_URL POKEMON_TCG_SDK_BASE_URL "sets/"

/**
 * The URL for accessing Type information
 * https://docs.pokemontcg.io/api-reference/types/get-types#http-request
 */
#define POKEMON_TCG_SDK_TYPES_URL POKEMON_TCG_SDK_BASE_URL "types/"

/**
 * The URL for accessing SubType information
 * https://docs.pokemontcg.io/api-reference/subtypes/get-subtypes#http-request
 */
#define POKEMON_TCG_SDK_SUBTYPES_URL POKEMON_TCG_SDK_BASE_URL "subtypes/"

/**
 * The URL for accessing SuperType information
 * https://docs.pokemontcg.io/api-reference/supertypes/get-supertypes#http-request
 * 
 */
#define POKEMON_TCG_SDK_SUPERTYPES_URL POKEMON_TCG_SDK_BASE_URL "supertypes/"

/**
 * The URL for accessing Rarity information
 * https://docs.pokemontcg.io/api-reference/rarities/get-rarities#http-request
 */
#define POKEMON_TCG_SDK_RARITIES_URL POKEMON_TCG_SDK_BASE_URL "rarities/"


#endif /*__POKEMON_TCG_SDK_URLS__*/