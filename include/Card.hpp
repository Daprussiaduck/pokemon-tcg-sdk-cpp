/**
 * @file Card.hpp
 * 
 * @brief The public functions and Classes/Structures for a Card represented by the SDK
 * 
 * @author Daprussiaduck
 */
#ifndef __CARD_HPP__
#define __CARD_HPP__

// Standard includes
#include <format>
#include <string>
#include <vector>

// External Libraries includes
#include <nlohmann/adl_serializer.hpp>
#include <nlohmann/json.hpp>

// Current Library includes
#include "Legalities.hpp"
#include "Set.hpp"

namespace pokemon_tcg_sdk {
    /**
     * @brief Structure to store the Ability of the card
     * 
     * https://docs.pokemontcg.io/api-reference/cards/card-object#abilities-listhash
     */
    struct Ability {
        /**
         * @brief The Name of the Ability
         */
        std::string name;

        /**
         * @brief The Text of the Ability
         */
        std::string text;

        /**
         * @brief The Type of the Ability
         */
        std::string type;

        /**
         * @brief Returns a string representing the Ability
         * 
         * @return A Sring representation of the Ability
         */
        std::string to_string();
    };
    
    /**
     * @brief Converts the JSON object into an Ability struct
     * 
     * @param json The nlohmann::json object to convert from
     * @param ability The Ability objet to convert into
     */
    void from_json(const nlohmann::json &json, Ability &ability);
    
    /**
     * @brief Converts an Ability struct to a JSON object
     * 
     * @param json The nlohmann::json object to convert to
     * @param ability The Ability structure to convert from
     */
    void to_json(nlohmann::json &json, const Ability &ability);

    /**
     * @brief Structure to store the Ancient Trait of the card
     * 
     * https://docs.pokemontcg.io/api-reference/cards/card-object#ancienttrait-hash
     */
    struct AncientTrait {
        /**
         * @brief The Name of the Ancient Trait
         */
        std::string name;

        /**
         * @brief The Text of the Ancient Trait
         */
        std::string text;

        /**
         * @brief Returns a string representing the Ancient Trait
         * 
         * @return A String representation of the AncientTrait
         */
        std::string to_string();
    };

    /**
     * @brief Converts the JSON object into an AncientTrait strut
     * 
     * @param json The nlohmann::json objetct to convert from
     * @param ancientTrait The AncientTrait structure to convert into
     */
    void from_json(const nlohmann::json &json, AncientTrait &ancientTrait);

    /**
     * @brief Converts an AncientTrait struct into a JSON object
     * 
     * @param json The nlohmann::json object to convert into
     * @param ancientTrait The AncientTrait Structure to cinvert from
     */
    void to_json(nlohmann::json &json, const AncientTrait &ancientTrait);

    /**
     * @brief Structure to hold an Attack on the card
     * 
     * https://docs.pokemontcg.io/api-reference/cards/card-object#attacks-listhash
     */
    struct Attack {
        /**
         * @brief The Name of the Attack
         */
        std::string name;

        /**
         * @brief The cost of the Attack
         */
        std::vector<std::string> cost;

        /**
         * @brief The Energy Cost of the Attack converted to an integer
         */
        int convertedEnergyCost;

        /**
         * @brief The Damage amount for the Attack
         */
        std::string damage;

        /**
         * @brief The text of the Attack
         */
        std::string text;

        /**
         * @brief Returns a string representing the Attack
         * 
         * @return A String representation of the Attack structure
         */
        std::string to_string();
    };

    /**
     * @brief Converts a JSON object into an Attack struct
     * 
     * @param json The nlohmann::json object to convert from
     * @param attack The Attack Structure to convert to
     */
    void from_json(const nlohmann::json &json, Attack &attack);

    /**
     * @brief Converts an Attack struct onto a JSON object
     * 
     * @param json The nlohmann::json object to convert into
     * @param attack The Attack structure to convert from
     */
    void to_json(nlohmann::json &json, const Attack &attack);

    /**
     * @brief Structure to hold the images of the card
     * 
     * https://docs.pokemontcg.io/api-reference/cards/card-object#images-hash
     */
    struct CardImages {
        /**
         * @brief URL to the small image of the card
         */
        std::string small;

        /**
         * @brief URL to the large image of the card
         */
        std::string large;

        /**
         * @brief Returns a string representing the card's images
         * 
         * @return A string representation of the CardImages Structure
         */
        std::string to_string();
    };

    /**
     * @brief Converts a JSON object into a CardImages struct
     * 
     * @param json The nlohmann::json object to convert from
     * @param images The CardImages structure to convert into
     */
    void from_json(const nlohmann::json &json, CardImages &images);

    /**
     * @brief Converts a CardImages struct into a JSON object
     * 
     * @param json The nlohmann::json object to convert into
     * @param images The CardImages structure to convert from
     */
    void to_json(nlohmann::json &json, const CardImages &images);


    /**
     * @brief Structure for the prices provided by Card Market from the API
     * 
     * https://docs.pokemontcg.io/api-reference/cards/card-object#cardmarket-hash
     */
    struct CardMarketPrices {
        /**
         * @brief The Average Sell Price as shown in the website for non-foils
         */
        double averageSellingPrice;

        /**
         * @brief The Lowest Price at the market for non-foils
         */
        double lowPrice;

        /**
         * @brief The Trend Price as shown in the website for non-foils
         */
        double trendPrice;

        /**
         * @brief The Lowest Sell Price from German Professional Sellers
         */
        double germanProLow;

        /**
         * @brief The Suggested Price from the Card Market Algorithm
         */
        double suggestedPrice;

        /**
         * @brief The Average Sell Price as Shown in the website for reverse holofoils
         */
        double reverseHoloSell;

        /**
         * @brief The Lowest Price as shown at the website for reverse holofoils
         */
        double reverseHoloLow;

        /**
         * @brief The Trend Price at the market as shown at the website for reverse holofoils
         */
        double reverseHoloTrend;

        /**
         * @brief The Lowest Price at the market for non-foils with a condition of EX or better
         */
        double lowPriceExPlus;

        /**
         * @brief The Average Sale Price over 1 day
         */
        double avg1;

        /**
         * @brief The Average Sale Price over 7 days
         */
        double avg7;

        /**
         * @brief The Average Sale Price over 30 days
         */
        double avg30;

        /**
         * @brief The Average Sale Price over the past 1 day for reverse holofoils
         */
        double reverseHoloAvg1;

        /**
         * @brief The Average Sale Price over the past 7 days for reverse holofoils
         */
        double reverseHoloAvg7;

        /**
         * @brief The Average Sale Price over the past 30 days for reverse holofoils
         */
        double reverseHoloAvg30;

        /**
         * @brief Returns a string representing the Card Market Prices
         * 
         * @return A string representing the CardMarketPrices Structure
         */
        std::string to_string();
    };

    /**
     * @brief Converts a JSON object into a CardMarketPrices struct
     * 
     * @param json The nlohmann::json object to convert from
     * @param cardMarketPrices The CardMarketPrices Structure to convert into
     */
    void from_json(const nlohmann::json &json, CardMarketPrices &cardMarketPrices);

    /**
     * @brief Converts a CardMarketPrices struct into a JSON object
     * 
     * @param json The nlohmann::json object to convert into
     * @param cardMarketPrices The CardMarketPrices Structure to convert from
     */
    void to_json(nlohmann::json &json, const CardMarketPrices &cardMarketPrices);

    /**
     * @brief Structure to store the information from CardMarket
     * 
     * https://docs.pokemontcg.io/api-reference/cards/card-object/#cardmarket-hash
     */
    struct CardMarket {
        /**
         * @brief The URL to the cardmarket store page to purchase the card
         */
        std::string url;

        /**
         * @brief The date that the price was last updated at. It is in the format of YYY/MM/DD
         */
        std::string updatedAt;

        /**
         * @brief The Prices of the Card Market for the Card
         */
        struct CardMarketPrices prices;

        /**
         * @brief Returns a string representing the Card Market
         * 
         * @return A string representing the CardMarket structure
         */
        std::string to_string();
    };
    
    /**
     * @brief Converts a JSON object into a CardMarket struct
     * 
     * @param json The nlohmann::json object to convert from
     * @param cardMarket The CardMarket structure to convert to
     */
    void from_json(const nlohmann::json &json, CardMarket &cardMarket);

    /**
     * @brief Converts a CardMarket struct into a JSON object
     * 
     * @param json The nlohmann::json object to convert to
     * @param cardMArket The CardMarket structure to convert from
     */
    void to_json(nlohmann::json &json, const CardMarket &cardMarket);

    /**
     * @brief Structure to store the resistance of the card
     * 
     * https://docs.pokemontcg.io/api-reference/cards/card-object/#resistances-listhash
     */
    struct Resistance {
        /**
         * @brief The Type of the Resistance
         */
        std::string type;

        /**
         * @brief The Value of the Resistance
         */
        std::string value;

        /**
         * @brief Returns a string representing the Resistance
         * 
         * @return a string representing the Resistance structure
         */
        std::string to_string();
    };

    /**
     * @brief Converts a JSON object into a Resistance struct
     * 
     * @param json The nlohmann::json object to convert from
     * @param resistance The Resistance structure to convert into 
     */
    void from_json(const nlohmann::json &json, Resistance &resistance);

    /**
     * @brief Converts a Resistance struct into a JSON object
     * 
     * @param json The nlohmann::json object to convert into
     * @param resistance The Resistance structure to convert from
     */
    void to_json(nlohmann::json &json, const Resistance &resistance);

    /**
     * @brief Structure to hold the prices from TcgPlayer from the API
     * 
     * https://docs.pokemontcg.io/api-reference/cards/card-object/#tcgplayer-hash
     */
    struct TcgPlayerPrices {
        /**
         * @brief The Low Price of the card
         */
        double low;

        /**
         * @brief The Mid Price of the card
         */
        double mid;

        /**
         * @brief The High Price of the card
         */
        double high;

        /**
         * The Market price of the card
         */
        double market;

        /**
         * @brief The Direct Low of the card
         */
        double directLow;

        /**
         * @brief Returns a string representing the price from TcgPlayer
         * 
         * @return A string representing the TCGPlayerPrices structure
         */
        std::string to_string();
    };

    /**
     * @brief Converts a JSON object into a TcgPlayerPrices struct
     * 
     * @param json The nlohmann::json object to convert from
     * @param tcgPlayerPrices The TcgPlayerPrices structure to convert into
     */
    void to_json(nlohmann::json &json, const TcgPlayerPrices &tcgPlayerPrices);

    /**
     * @brief Converts a TcgPlayerPrices struct into a JSON object
     * 
     * @param json The nlohmann::json object to convert into
     * @param tcgPlayerPrices The TCGPlayerPrices Structure to convert from
     */
    void from_json(const nlohmann::json &json, TcgPlayerPrices &tcgPlayerPrices);

    /**
     * @brief Structure to hold the prices subObject from TcgPlayer
     * 
     * https://docs.pokemontcg.io/api-reference/cards/card-object/#tcgplayer-hash
     */
    struct TcgPlayerPricesContainer {
        /**
         * @brief Price structure of a normal card
         */
        struct TcgPlayerPrices normal;

        /**
         * @brief Price structure of a holofoil card
         */
        struct TcgPlayerPrices holofoil;

        /**
         * @brief Price structure of a reverse holofoil card
         */
        struct TcgPlayerPrices reverseHolofoil;
        
        /**
         * @brief Price structure of a first edition holofoil card
         */
        struct TcgPlayerPrices firstEditionHolofoil;
        
        /**
         * @brief Price structure of a first edition normal card
         */
        struct TcgPlayerPrices firstEditionNormal;
        
        /**
         * @brief Returns a string representing the mutiple prices of a card's options
         * 
         * @return A string representing the TcgPlayerPricesContainer structure
         */
        std::string to_string();
    };

    /**
     * @brief Converts a JSON object into a TcgPricesContainer struct
     * 
     * @param json The nlohmann::json object to convert from
     * @param tcgPlayerPricesContainer The TcgPlayerPricesContainer structure to convert into
     */
    void from_json(const nlohmann::json &json, TcgPlayerPricesContainer &tcgPlayerPricesContainer);

    /**
     * @brief Converts a TcgPlayerPricesContainer struct into a JSON object
     * 
     * @param json The nlohmann::json object to convert to
     * @param tcgPlayerPricesContainer The TcgPlayerPricesContainer structure to convert from
     */
    void to_json(nlohmann::json &json, const TcgPlayerPricesContainer &tcgPlayerPricesContainer);

    /**
     * @brief Structure to hold the TcgPlayer information provided by the API
     * 
     * https://docs.pokemontcg.io/api-reference/cards/card-object/#tcgplayer-hash
     */
    struct TcgPlayer {
        /**
         * @brief The URL to the TCGPlayer store page of the card
         */
        std::string url;

        /**
         * @brief The date that the price was last updated at. It is in the format of YYY/MM/DD
         */
        std::string updatedAt;

        /**
         * @brief The prices gotten from TCGPlayer
         */
        TcgPlayerPricesContainer prices;

        /**
         * @brief Returns a string representing the TCGPlayer information for the card
         * 
         * @return A string representing the TcgPlayerPrices structure
         */
        std::string to_string();
    };

    /**
     * @brief Converts a JSON object into a TcgPlayer struct
     * 
     * @param json The nlohmann::json object to convert from
     * @param tcgPlayer The TcgPlayer structure to convert into
     */
    void from_json(const nlohmann::json &json, TcgPlayer &tcgPlayer);

    /**
     * @brief Converts a TcgPlayer struct into a JSON object
     * 
     * @param json The nlohmann::json object to convert into
     * @param tcgPlayer The TcgPlayer structure to convert from
     */
    void to_json(nlohmann::json &json, const TcgPlayer &tcgPlayer);

    /**
     * @brief Structure to hold the Weakness information of the card
     * 
     * https://docs.pokemontcg.io/api-reference/cards/card-object/#weaknesses-listhash
     */
    struct Weakness {
        /**
         * @brief The Type of the Weakness
         */
        std::string type;
        
        /**
         * @brief The Value of the Weakness
         */
        std::string value;
        
        /**
         * @brief Returns a string representing the Weakness of the card
         * 
         * @return A string representing the Weakness structure
         */
        std::string to_string();
    };

    /**
     * @brief Converts a JSON object into a Weakness struct
     * 
     * @param json The nlohmann::json object to convert from
     * @param weakness The Weakness structure to convert into
     */
    void from_json(const nlohmann::json &json, Weakness &weakness);

    /**
     * @brief Converts a Weakness struct into a JSON object
     * 
     * @param json The nlohmann::json object to convert into
     * @param weakness The Weakness structure to convert from
     */
    void to_json(nlohmann::json &json, const Weakness &weakness);

    /**
     * @brief Class to Store a Card from the Pokémon TCG API
     * 
     * https://docs.pokemontcg.io/api-reference/cards/card-object
     */
    class Card {
        public:
            /**
             * @brief Returns all cards
             * 
             * https://docs.pokemontcg.io/api-reference/cards/search-cards#query-parameters
             * https://docs.pokemontcg.io/api-reference/cards/search-cards#ordering-data
             * 
             * @param orderBy How to order the Cards (Or blank for no/default ordering)
             * @param select A Database like selection of the Cards (Or blank for all Cards)
             * 
             * @return A vector of the Card Objects ordered and selected from the input parameters
             */
            static std::vector<Card> all(std::string orderBy = "", std::string select = "");

            /**
             * @brief Returns the cards matching the provided ID
             * 
             * @param id The Card id to search for in the API
             * 
             * @return A Card object that matches the provided ID
             */
            static Card find(API* api, std::string id);

            /**
             * @brief Returns the cards matching the provided query
             * 
             * @param query The string query to lookup through the API
             * @param orderBy The order to return (Or blank for no/default order)
             * @param select A Database like selection of the Cards (Or blank for all Cards)
             * 
             * @return A vector of Cards that match the given query, and sorted/selected by the given input parameters
             */
            static std::vector<Card> where(std::string query, std::string orderBy = "", std::string select = "");

            /**
             * @brief Returns the cards matching the provided query
             * 
             * @param query The nlohmann::json query to lookup through the API
             * @param orderBy The order to return (Or blank for no/default order)
             * @param select A Database like selection of the Cards (Or blank for all Cards)
             * 
             * @return A vector of Cards that match the given query, and sorted/selected by the given input parameters
             */
            static std::vector<Card> where(nlohmann::json query, std::string orderBy = "", std::string select = "");
            
            /**
             * @brief Returns the ID of the Card
             * 
             * @return A string with the ID of the Card
             */
            std::string getID();

            /**
             * @brief Returns the Name of the Card
             * 
             * @return A string with the Name of the Card
             */
            std::string getName();

            /**
             * @brief Returns a list of the Card's Sub-Types
             * 
             * @return A vector of Strings with the Cards SubTypes
             */
            std::vector<std::string> getSubTypes();

            /**
             * @brief Returns the Level of the Card
             * 
             * @return A String with the level of the Card
             */
            std::string getLevel();

            /**
             * @brief Returns the HP of the Card
             * 
             * @return A string with the HP of the Card
             */
            std::string getHP();

            /**
             * @brief Returns a list of the Card's Types
             * 
             * @return A vector of string with the Cards Types
             */
            std::vector<std::string> getTypes();

            /**
             * @brief Returns the Pokémon this Card Evolves From
             * 
             * @return A string with the Pokemon this Card evolves from
             */
            std::string getEvolvesFrom();

            /**
             * @brief Returns a list of the Pokémon this Card can Evolve To
             * 
             * @return A vector of strings with the Pokemon this Card can evolve to
             */
            std::vector<std::string> getEvolvesTo();

            /**
             * @brief Returns a list of the Card's Rules
             * 
             * @return A vector of strings with the additional rules this Card adds while in play
             */
            std::vector<std::string> getRules();

            /**
             * @brief Returns the Ancient Trait of the Card
             * 
             * @return The internal AncientTrait structure of the Card 
             */
            AncientTrait getAncientTrait();

            /**
             * @brief Returns a list of the Card's Abilities
             * 
             * @return A vector of the Ability structure containing all of the Abilities the Card has
             */
            std::vector<Ability> getAbilities();

            /**
             * @brief Returns a list of the Card's Attacks
             * 
             * @return A vector of the Attack structure containing all of the Attacks the Card has
             */
            std::vector<Attack> getAttacks();

            /**
             * @brief Returns a list of the Card's Weaknesses
             * 
             * @return A vector of the Weakness structure containing all of the Weaknesses the Card has
             */
            std::vector<Weakness> getWeaknesses();

            /**
             * @brief Returns a list of the Card's Resistances
             * 
             * @return A vector of the Resistance structure containing all of the Resistances the Card has 
             */
            std::vector<Resistance> getResistances();

            /**
             * @brief Returns a list of the Card's Retreat Cost
             * 
             * @return A vector of strings explaining the retreat cost of the Card
             */
            std::vector<std::string> getRetreatCost();

            /**
             * @brief Returns the Converted Retreat of the Card
             * 
             * As explained by the API, the converted retreat cost is simply the amount of energies that the Card needs to retreat, missing the type information
             * 
             * @return The converted retreat cost of the Card
             */
            int getConvertedRetreatCost();

            /**
             * @brief Returns the Set of the Card
             * 
             * @return The Set Structure containing the information of the Set this Card is a part of
             */
            Set getSet();

            /**
             * @brief Returns the Number of the Card
             * 
             * @return The number in the Set that the Card is
             */
            std::string getNumber();

            /**
             * @brief Returns the Artist of the Card
             * 
             * @return A string with the Artist of the Card's Artwork
             */
            std::string getArtist();

            /**
             * @brief Retuns the Rarity of the Card
             * 
             * @return A string with the Cards rarity
             */
            std::string getRarity();

            /**
             * @brief Returns the Flavor Text of the Card
             * 
             * @return A string with the Card's flavor text
             */
            std::string getFlavorText();

            /**
             * @brief Returns a list of the National Pokédex Numbers of the Pokémon shown in the Card
             * 
             * @return A vector of integers with the National Pokedex numbers of the Pokemon shown in the Card
             */
            std::vector<int> getNationalPokedexNumbers();

            /**
             * @brief Returns the Legalities of the Card
             * 
             * @return A Legality structure containing the Legality information of the Card
             */
            Legality getLegalities();

            /**
             * @brief Returns the Regulation Mark of the Card
             * 
             * @return A string with the Cards regulation mark
             */
            std::string getRegulationMark();

            /**
             * @brief Returns the Images of the Card
             * 
             * @return A CardImages structure containing the images of the Card
             */
            CardImages getImages();

            /**
             * @brief Returns the TcgPlayer Information of the Card
             * 
             * @return A TcgPlayer structure 
             */
            TcgPlayer getTcgPlayer();

            /**
             * @brief Returns the Card Market Information of the Card
             * 
             * @return The CardMarket structure about the Card
             */
            CardMarket getCardmarket();

            /**
             * @brief Returns a string representing the Card
             * 
             * @return A string representing the Card
             */
            std::string to_string();
            
            /**
             * @brief Converts a JSON object into a Card object
             * 
             * @param json The nlohmann::json object to convert from
             * @param card The Card class to convert to
             */
            friend void from_json(const nlohmann::json &json, Card &card);

            /**
             * @brief Converts a Card object into a JSON object
             * 
             * @param json The nlohmann::json object to convert to
             * @param card The Card class to convert from
             */
            friend void to_json(nlohmann::json &json, const Card &card);

        private:
            /**
             * @brief The ID of the Card
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#id-string
             */
            std::string id;

            /**
             * @brief The Name of the Card
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#name-string
             */
            std::string name;

            /**
             * @brief The Supertype of the Card
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#supertype-string
             */
            std::string supertype;

            /**
             * @brief The subtype of the Card
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#subtypes-liststring
             */
            std::vector<std::string> subtypes;

            /**
             * @brief The level of the Card
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#level-string
             */
            std::string level;

            /**
             * @brief The HP of the Card
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#hp-string
             */
            std::string hp;

            /**
             * @brief The types of the Card
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#types-liststring
             */
            std::vector<std::string> types;

            /**
             * @brief The Pokemon this Card evolves from
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#evolvesfrom-string
             */
            std::string evolvesFrom;

            /**
             * @brief The Pokemon this Card evolves to
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#evolvesto-liststring
             */
            std::vector<std::string> evolvesTo;

            /**
             * @brief Additional rules attached to this Card
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#rules-liststring
             */
            std::vector<std::string> rules;

            /**
             * @brief The Ancient Trait this Card has, if any
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#ancienttrait-hash
             */
            AncientTrait ancientTrait;

            /**
             * @brief The Ability this Card has, if any
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#abilities-listhash
             */
            std::vector<Ability> abilities;

            /**
             * @brief The Attacks this card has, if any
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#attacks-listhash
             */
            std::vector<Attack> attacks;

            /**
             * @brief The Weaknesses this Card has, if any
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#weaknesses-listhash
             */
            std::vector<Weakness> weaknesses;

            /**
             * @brief The Resistances this Card has, if any
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#resistances-listhash
             */
            std::vector<Resistance> resistances;

            /**
             * @brief The retreat cost of this Card
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#retreatcost-liststring
             */
            std::vector<std::string> retreatCost;
            
            /**
             * @brief The Retreat Cost of this Card, converted into simple number of energies
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#convertedretreatcost-integer
             */
            int convertedRetreatCost;

            /**
             * @brief The Set this Card is apart of
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#set-hash
             */
            Set set;

            /**
             * @brief The number this card is within the Set
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#number-string
             */
            std::string number;

            /**
             * @brief The Artist for this Card's Artwork
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#artist-string
             */
            std::string artist;

            /**
             * The Rarity of this Card
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#rarity-string
             */
            std::string rarity;

            /**
             * @brief The Flavor Text of this Card
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#flavortext-string
             */
            std::string flavorText;

            /**
             * @brief The National Pokedex Number of the Pokemon this Card represents
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#nationalpokedexnumbers-listinteger
             */
            std::vector<int> nationalPokedexNumbers;
            
            /**
             * @brief The legality of the Card (allowed in tournaments?)
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#legalities-hash
             */
            Legality legalities;
            
            /**
             * @brief The regulation mark of the Card, if any
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#regulationmark-string
             */
            std::string regulationMark;
            
            /**
             * @brief The Images of the Card
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#images-hash
             */
            struct CardImages images;

            /**
             * @brief The TCG-Player prices of the Card
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#tcgplayer-hash
             */
            struct TcgPlayer tcgplayer;
            
            /**
             * @brief The CardMarket prices of the Card
             * 
             * https://docs.pokemontcg.io/api-reference/cards/card-object#cardmarket-hash
             */
            struct CardMarket cardmarket;
    };

};

#endif /*__CARD_HPP__*/