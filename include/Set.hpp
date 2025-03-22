#ifndef __SET_HPP__
#define __SET_HPP__

#include <nlohmann/json.hpp>
#include <string>

#include "Legalities.hpp"

namespace pokemon_tcg_sdk {
    /**
     * Structure to store the Images of the Set
     * https://docs.pokemontcg.io/api-reference/sets/set-object#images-hash
     */
    struct SetImages {
        /**
         * The Symbol Image of the Set
         */
        std::string symbol;
        
        /**
         * The Logo Image of the Set
         */
        std::string logo;
        
        /**
         * Returns a string representing the Set Images structure
         */
        std::string to_string(bool card);
    };

    /**
     * Converts a JSON object to a SetImages struct
     */
    void from_json(const nlohmann::json &json, SetImages &setImages);

    /**
     * Converts a SetImages struct into a JSON object
     */
    void to_json(nlohmann::json &json, const SetImages &setImages);

    /**
     * Class to Store a Set from the Pokémon TCG API
     */
    class Set{
        public:
            /**
             * Returns the ID of the Set
             */
            std::string getID();

            /**
             * Returns the Name of the Set
             */
            std::string getName();

            /**
             * Returns the Series of the Set
             */
            std::string getSeries();

            /**
             * Returns the Printed Total of the Set
             */
            int getPrintedTotal();

            /**
             * Retruns the Total of the Set
             */
            int getTotal();

            /**
             * Returns the Legalities of the Set
             */
            Legality getLegalities();

            /**
             * Returns the Pokemon Trading Card Game Online Code of the Set
             */
            std::string getPTCGoCode();

            /**
             * Returns the Release Date of the Set
             */
            std::string getReleaseDate();

            /**
             * Returns the Date of which the Set was last Updated
             */
            std::string getUpdatedAt();

            /**
             * Returns the Images of the Set
             */
            SetImages getImages();

            /**
             * Returns a string representing the Set
             */
            std::string to_string(bool card);
            
            /**
             * Converts a JSON object into a Set class
             */
            friend void from_json(const nlohmann::json &json, Set &set);

            /**
             * Converts a Set class into a JSON object
             */
            friend void to_json(nlohmann::json &json, const Set &set);

        private:
            /**
             * The ID of the Set
             * https://docs.pokemontcg.io/api-reference/sets/set-object#id-string
             */
            std::string id;
            
            /**
             * The Name of the Set
             * https://docs.pokemontcg.io/api-reference/sets/set-object#name-string
             */
            std::string name;
            
            /**
             * The Series of Set
             * https://docs.pokemontcg.io/api-reference/sets/set-object#series-string
             */
            std::string series;
            
            /**
             * The Number of Printed Cards in the Set
             * https://docs.pokemontcg.io/api-reference/sets/set-object#printedtotal-integer
             */
            int printedTotal;
            
            /**
             * The Total number of Cards in the Set
             * https://docs.pokemontcg.io/api-reference/sets/set-object#total-integer
             */
            int total;
            
            /**
             * The Legalities of the Set
             * https://docs.pokemontcg.io/api-reference/sets/set-object#legalities-hash
             */
            Legality legalities;
            
            /**
             * The Code the Pokémon Trading Card Game Online uses to identify a Set
             * https://docs.pokemontcg.io/api-reference/sets/set-object/#ptcgocode-string
             */
            std::string ptcgoCode;
            
            /**
             * The Date when the Set was released in the USA (Format is YYYY/MM/DD)
             * https://docs.pokemontcg.io/api-reference/sets/set-object/#releasedate-string
             */
            std::string releaseDate;
            
            /**
             * The Date and Time the Set was last updated (Format is YYYY/MM/DD HH:MM:SS)
             * https://docs.pokemontcg.io/api-reference/sets/set-object/#updatedat-string
             */
            std::string updatedAt;
            
            /**
             * The Images associated with the Set
             * https://docs.pokemontcg.io/api-reference/sets/set-object/#images-hash
             */
            struct SetImages images;
    };
};

#endif /*__SET_HPP__*/