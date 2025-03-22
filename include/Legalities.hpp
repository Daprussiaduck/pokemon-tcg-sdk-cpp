#ifndef __LEGALITY_HPP__
#define __LEGALITY_HPP__

#include <nlohmann/json.hpp>
#include <string>

namespace pokemon_tcg_sdk{
    struct Legality {

        /**
         * The standard game format
         * Possible Values are Legal
         * https://docs.pokemontcg.io/api-reference/cards/card-object#legalities-hash
         * https://docs.pokemontcg.io/api-reference/sets/set-object/#legalities-hash
         */
        std::string standard;

        /**
         * The expanded game format
         * Possible Values are Legal
         * https://docs.pokemontcg.io/api-reference/cards/card-object#legalities-hash
         * https://docs.pokemontcg.io/api-reference/sets/set-object/#legalities-hash
         */
        std::string expanded;

        /**
         * The unlimited game format
         * Possible Values are Legal
         * https://docs.pokemontcg.io/api-reference/cards/card-object#legalities-hash
         * https://docs.pokemontcg.io/api-reference/sets/set-object/#legalities-hash
         */
        std::string unlimited;

        /**
         * Returns a string representing the Legalities
         */
        std::string to_string(bool set);
    };

    /**
     * Converts a JSON object into a Legality struct
     */
    void from_json(const nlohmann::json &json, Legality &legalities);

    /**
     * Converts a Legality struct into a JSON object
     */
    void to_json(nlohmann::json &json, const Legality &legality);
    
    /**
     * Defines the functions to interchange JSON to the Legality structure and back
     */
    // NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(Legality, standard, expanded, unlimited);
};

#endif /*__LEGALITY_HPP__*/