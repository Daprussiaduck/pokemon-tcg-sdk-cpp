/**
 * @file Set.hpp
 * 
 * @brief This file contains the Set class definitions
 */
#ifndef __SET_HPP__
#define __SET_HPP__

#include <nlohmann/json.hpp>
#include <string>

#include <pokemon-tcg-sdk-cpp/Legalities.hpp>
#include <pokemon-tcg-sdk-cpp/api/Query.hpp>
#include <pokemon-tcg-sdk-cpp/api/URLS.hpp>

namespace pokemon_tcg_sdk {

    /**
     * @brief Structure to store the Images of the Set
     * 
     * https://docs.pokemontcg.io/api-reference/sets/set-object#images-hash
     */
    struct SetImages {

        /**
         * @brief The Symbol Image of the Set
         */
        std::string symbol;
        
        /**
         * @brief The Logo Image of the Set
         */
        std::string logo;
        
        /**
         * @brief Returns a string representing the Set Images structure
         * 
         * @param card Should this print as part of a card or as standalone
         * 
         * @return A string representing the SetImages structure
         */
        std::string to_string(bool card = false);
    };

    /**
     * @brief Converts a JSON object to a SetImages struct
     * 
     * @param json The nlohmann::json object to convert from
     * @param setImages The SetImages structure to convert into
     */
    void from_json(const nlohmann::json &json, SetImages &setImages);

    /**
     * @brief Converts a SetImages struct into a JSON object
     * 
     * @param json The nlohmann::json object to convert to
     * @param setImages The SetImages structure to convert from
     */
    void to_json(nlohmann::json &json, const SetImages &setImages);

    /**
     * @brief Class to Store a Set from the Pokémon TCG API
     */
    class Set{
        public:

            /**
             * @brief Returns all sets
             * 
             * https://docs.pokemontcg.io/api-reference/sets/search-sets#query-parameters
             * 
             * @param orderBy How to order the Sets (or blank for no/default Order)
             * @param select A Database like selection of the Sets (or blank for all Sets)
             * 
             * @return A vector of strings representing the Sets returned by the query
             */
            static std::vector<Set> all(std::string orderBy = "", std::string select = "");

            /**
             * @brief Returns the sets matching the provided ID
             * 
             * @param id The Id to search for
             * 
             * @return A Set object matching the ID found, or None if not found
             */
            static Set find(std::string id);

            /**
             * @brief Returns the sets matching the provided query
             * 
             * @param query The string query to lookup through the API
             * @param orderBy The order to return (Or blank for no/default order)
             * @param select A Database like selection of the Sets (Or blank for all Sets)
             * 
             * @return A vector of Sets that match the given query, and sorted/selected by the given input parameters
             */
            static std::vector<Set> where(std::string query, std::string orderBy = "", std::string select = "");

            /**
             * @brief Returns the Sets matching the provided query
             * 
             * @param query The nlohmann::json query to lookup through the API
             * @param orderBy The order to return (Or blank for no/default order)
             * @param select A Database like selection of the Sets (Or blank for all Sets)
             * 
             * @return A vector of Sets that match the given query, and sorted/selected by the given input parameters
             */
            static std::vector<Set> where(nlohmann::json query, std::string orderBy = "", std::string select = "");
            
            /**
             * @brief Returns the ID of the Set
             * 
             * @return A string with the ID of the Set
             */
            std::string getID();

            /**
             * @brief Returns the Name of the Set
             * 
             * @return A string with the Name of the set
             */
            std::string getName();

            /**
             * @brief Returns the Series of the Set
             * 
             * @return A string with the series of the Set
             */
            std::string getSeries();

            /**
             * @brief Returns the Printed Total of the Set
             * 
             * @return A integer with the official number of Cards in the Set
             */
            int getPrintedTotal();

            /**
             * @brief Retruns the actual Total of the Set
             * 
             * @return An integer with the actual number of Cards in the Set
             */
            int getTotal();

            /**
             * @brief Returns the Legalities of the Set
             * 
             * @returns A Legality Structure of the Set's overall Legality
             */
            Legality getLegalities();

            /**
             * @brief Returns the Pokemon Trading Card Game Online Code of the Set
             * 
             * @return A string containing the Set's PTCGo Code
             */
            std::string getPTCGoCode();

            /**
             * @brief Returns the Release Date of the Set
             * 
             * @return A string containing the Release Date of the set
             */
            std::string getReleaseDate();

            /**
             * @brief Returns the Date of which the Set was last Updated
             * 
             * @return A string containing the Last date the Set was updated at
             */
            std::string getUpdatedAt();

            /**
             * @brief Returns the Images of the Set
             * 
             * @return A SetImages structure of the Set's Images
             */
            SetImages getImages();

            /**
             * @brief Returns a string representing the Set
             * 
             * @param card Is this print out part of a Card?
             * 
             * @return A string representing the Set
             */
            std::string to_string(bool card = false);
            
            /**
             * @brief Converts a JSON object into a Set class
             * 
             * @param json The nlohmann::json object to convert from
             * @param set The Set class to convert to
             */
            friend void from_json(const nlohmann::json &json, Set &set);

            /**
             * @brief Converts a Set class into a JSON object
             * 
             * @param json The nlohmann::json object to convert into
             * @param set The Set class to convert into
             */
            friend void to_json(nlohmann::json &json, const Set &set);

        private:
            /**
             * @brief The ID of the Set
             * 
             * https://docs.pokemontcg.io/api-reference/sets/set-object#id-string
             */
            std::string id;
            
            /**
             * @brief The Name of the Set
             * 
             * https://docs.pokemontcg.io/api-reference/sets/set-object#name-string
             */
            std::string name;
            
            /**
             * @brief The Series of Set
             * 
             * https://docs.pokemontcg.io/api-reference/sets/set-object#series-string
             */
            std::string series;
            
            /**
             * @brief The Number of Printed Cards in the Set
             * 
             * https://docs.pokemontcg.io/api-reference/sets/set-object#printedtotal-integer
             */
            int printedTotal;
            
            /**
             * @brief The Total number of Cards in the Set
             * 
             * https://docs.pokemontcg.io/api-reference/sets/set-object#total-integer
             */
            int total;
            
            /**
             * @brief The Legalities of the Set
             * 
             * https://docs.pokemontcg.io/api-reference/sets/set-object#legalities-hash
             */
            Legality legalities;
            
            /**
             * @brief The Code the Pokémon Trading Card Game Online uses to identify a Set
             * 
             * https://docs.pokemontcg.io/api-reference/sets/set-object/#ptcgocode-string
             */
            std::string ptcgoCode;
            
            /**
             * The Date when the Set was released in the USA (Format is YYYY/MM/DD)
             * https://docs.pokemontcg.io/api-reference/sets/set-object/#releasedate-string
             */
            std::string releaseDate;
            
            /**
             * @brief The Date and Time the Set was last updated
             * 
             * Format is YYYY/MM/DD HH:MM:SS
             * https://docs.pokemontcg.io/api-reference/sets/set-object/#updatedat-string
             */
            std::string updatedAt;
            
            /**
             * @brief The Images associated with the Set
             * 
             * https://docs.pokemontcg.io/api-reference/sets/set-object/#images-hash
             */
            struct SetImages images;
    };
};

#endif /*__SET_HPP__*/