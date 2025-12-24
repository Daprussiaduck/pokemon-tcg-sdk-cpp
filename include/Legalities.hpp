/**
 * @file Legalities.hpp
 * 
 * @brief This files contains the Structure for defining a Legality, of either a Set or a Card
 * 
 * @author Daprussiaduck
 */
#ifndef __LEGALITY_HPP__
#define __LEGALITY_HPP__

// Standard Library includes
#include <string>

// External Library includes
#include <nlohmann/json.hpp>

// Current Library includes

namespace pokemon_tcg_sdk{

    /**
     * @brief The Structure representing the legality of a Set or a Card
     */
    struct Legality {

        /**
         * @brief The standard game format
         * 
         * Possible Values are Legal
         * https://docs.pokemontcg.io/api-reference/cards/card-object#legalities-hash
         * https://docs.pokemontcg.io/api-reference/sets/set-object/#legalities-hash
         */
        std::string standard;

        /**
         * @brief The expanded game format
         * 
         * Possible Values are Legal
         * https://docs.pokemontcg.io/api-reference/cards/card-object#legalities-hash
         * https://docs.pokemontcg.io/api-reference/sets/set-object/#legalities-hash
         */
        std::string expanded;

        /**
         * @brief The unlimited game format
         * 
         * Possible Values are Legal
         * https://docs.pokemontcg.io/api-reference/cards/card-object#legalities-hash
         * https://docs.pokemontcg.io/api-reference/sets/set-object/#legalities-hash
         */
        std::string unlimited;

        /**
         * @brief Returns a string representing the Legalities
         * 
         * @param set Should the output be tabbed in
         */
        std::string to_string(bool set);
    };

    /**
     * @brief Converts a JSON object into a Legality struct
     * 
     * @param json The nlohmann::json object to convert
     * @param legalities The Legality structure to convert into
     */
    void from_json(const nlohmann::json &json, Legality &legalities);

    /**
     * @brief Converts a Legality struct into a JSON object
     * 
     * @param json The nlohmann::json object to convert to
     * @param Legality The Legality structure to convert from
     */
    void to_json(nlohmann::json &json, const Legality &legality);
};

#endif /*__LEGALITY_HPP__*/