#ifndef __CARD_HPP__
#define __CARD_HPP__

#include <nlohmann/adl_serializer.hpp>
#include <nlohmann/json.hpp>
#include <format>
#include <string>
#include <vector>

#include "Legalities.hpp"
#include "api/Query.hpp"
#include "api/URLS.hpp"
#include "Set.hpp"

namespace pokemon_tcg_sdk {
    /**
     * Structure to store the Ability of the card
     * https://docs.pokemontcg.io/api-reference/cards/card-object#abilities-listhash
     */
    struct Ability {
        /**
         * The Name of the Ability
         */
        std::string name;

        /**
         * The Text of the Ability
         */
        std::string text;

        /**
         * The Type of the Ability
         */
        std::string type;

        /**
         * Returns a string representing the Ability
         */
        std::string to_string();
    };

    /**
     * Defines the functions to interchange JSON to the Ability structure and back
     */
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(Ability, name, text, type);

    /**
     * Structure to store the Ancient Trait of the card
     * https://docs.pokemontcg.io/api-reference/cards/card-object#ancienttrait-hash
     */
    struct AncientTrait {
        /**
         * The Name of the Ancient Trait
         */
        std::string name;

        /**
         * The Text of the Ancient Trait
         */
        std::string text;

        /**
         * Returns a string representing the Ancient Trait
         */
        std::string to_string();
    };

    /**
     * Defines the functions to interchange JSON to the AncientTrait structure and back
     */
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(AncientTrait, name, text);
    

    /**
     * Structure to hold an Attack on the card
     * https://docs.pokemontcg.io/api-reference/cards/card-object#attacks-listhash
     */
    struct Attack {
        /**
         * The Name of the Attack
         */
        std::string name;

        /**
         * The cost of the Attack
         */
        std::vector<std::string> cost;

        /**
         * The Energy Cost of the Attack converted to an integer
         */
        int convertedEnergyCost;

        /**
         * The Damage amount fog the Attack
         */
        std::string damage;

        /**
         * The text of the Attack
         */
        std::string text;

        /**
         * Returns a string representing the Attack
         */
        std::string to_string();
    };

    /**
     * Defines the functions to interchange JSON to the Attack structure and back
     */
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(Attack, cost, name, text, damage, convertedEnergyCost);

    /**
     * Structure to hold the images of the card
     * https://docs.pokemontcg.io/api-reference/cards/card-object#images-hash
     */
    struct CardImages {
        /**
         * URL to the small image of the card
         */
        std::string small;

        /**
         * URL to the large image of the card
         */
        std::string large;

        /**
         * Returns a string representing the card's images
         */
        std::string to_string();
    };

    /**
     * Defines the functions to interchange JSON to the Card Images structure and back
     */
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(CardImages, small, large);

    /**
     * Structure for the prices provided by Card Market from the API
     * https://docs.pokemontcg.io/api-reference/cards/card-object#cardmarket-hash
     */
    struct CardMarketPrices {
        /**
         * The Average Sell Price as shown in the website for non-foils
         */
        double averageSellingPrice;

        /**
         * The Lowest Price at the market for non-foils
         */
        double lowPrice;

        /**
         * The Trend Price as shown in the website for non-foils
         */
        double trendPrice;

        /**
         * The Lowest Sell Price from German Professional Sellers
         */
        double germanProLow;

        /**
         * The Suggested Price from the Card Market Algorithm
         */
        double suggestedPrice;

        /**
         * The Average Sell Price as Shown in the website for reverse holofoils
         */
        double reverseHoloSell;

        /**
         * The Lowest Price as shown at the website for reverse holofoils
         */
        double reverseHoloLow;

        /**
         * The Trend Price at the market as shown at the website for reverse holofoils
         */
        double reverseHoloTrend;

        /**
         * The Lowest Price at the market for non-foils with a condition of EX or better
         */
        double lowPriceExPlus;

        /**
         * The Average Sale Price over 1 day
         */
        double avg1;

        /**
         * The Average Sale Price over 7 days
         */
        double avg7;

        /**
         * The Average Sale Price over 30 days
         */
        double avg30;

        /**
         * The Average Sale Price over the past 1 day for reverse holofoils
         */
        double reverseHoloAvg1;

        /**
         * The Average Sale Price over the past 7 days for reverse holofoils
         */
        double reverseHoloAvg7;

        /**
         * The Average Sale Price over the past 30 days for reverse holofoils
         */
        double reverseHoloAvg30;

        /**
         * Returns a string representing the Card Market Prices 
         */
        std::string to_string();
    };

    /**
     * Defines the functions to interchange JSON to the CardMarketPrice structure and back
     */
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(CardMarketPrices,
        averageSellingPrice, lowPrice, trendPrice, germanProLow, suggestedPrice,
        reverseHoloSell, reverseHoloLow, reverseHoloTrend, lowPriceExPlus,
        avg1, avg7, avg30, reverseHoloAvg1, reverseHoloAvg7, reverseHoloAvg30);

    /**
     * Structure to store the information from cardmarket
     * https://docs.pokemontcg.io/api-reference/cards/card-object/#cardmarket-hash
     */
    struct CardMarket {
        /**
         * The URL to the cardmarket store page to purchase the card
         */
        std::string url;

        /**
         * The date that the price was last updated at. It is in the format of YYY/MM/DD
         */
        std::string updatedAt;

        /**
         * The Prices of the Card Market for the Card
         */
        struct CardMarketPrices prices;

        /**
         * Returns a string representing the Card Market 
         */
        std::string to_string();
    };

    /**
     * Defines the functions to interchange JSON to the CardMarket structure and back
     */
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(CardMarket, url, updatedAt, prices);

    /**
     * Structure to store the resistance of the card
     * https://docs.pokemontcg.io/api-reference/cards/card-object/#resistances-listhash
     */
    struct Resistance {
        /**
         * The Type of the Resistance
         */
        std::string type;

        /**
         * The Value of the Resistance
         */
        std::string value;

        /**
         * Returns a string representing the Resistance
         */
        std::string to_string();
    };

    /**
     * Defines the functions to interchange JSON to the Resistance structure and back
     */
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(Resistance, type, value);

    /**
     * Structure to hold the prices from TcgPlayer from the API
     * https://docs.pokemontcg.io/api-reference/cards/card-object/#tcgplayer-hash
     */
    struct TcgPlayerPrices {
        /**
         * The Low Price of the card
         */
        double low;

        /**
         * The Mid Price of the card
         */
        double mid;

        /**
         * The High Price of the card
         */
        double high;

        /**
         * The Market price of the card
         */
        double market;

        /**
         * The Direct Low of the card
         */
        double directLow;

        /**
         * Returns a string representing the price from TcgPlayer
         */
        std::string to_string();
    };

    /**
     * Defines the functions to interchange JSON to the TcgPlayerPrices structure and back
     */
    // NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(TcgPlayerPrices, low, mid, high, market, directLow);

    void to_json(nlohmann::json &jsonData, const TcgPlayerPrices &prices);

    void from_json(const nlohmann::json &jsonData, TcgPlayerPrices &prices);

    /**
     * Structure to hold the prices subObject from TcgPlayer
     * https://docs.pokemontcg.io/api-reference/cards/card-object/#tcgplayer-hash
     */
    struct TcgPlayerPricesContainer {
        /**
         * Price structure of a normal card
         */
        struct TcgPlayerPrices normal;

        /**
         * Price structure of a holofoil card
         */
        struct TcgPlayerPrices holofoil;

        /**
         * Price structure of a reverse holofoil card
         */
        struct TcgPlayerPrices reverseHolofoil;
        
        /**
         * Price structure of a first edition holofoil card
         */
        struct TcgPlayerPrices firstEditionHolofoil;
        
        /**
         * Price structure of a first edition normal card
         */
        struct TcgPlayerPrices firstEditionNormal;
        
        /**
         * Returns a string representing the mutiple prices of a card's options
         */
        std::string to_string();
    };

    /**
     * Converts a prices subObject from JSON to the TcgPricesContainer structure and back
     */
    void from_json(const nlohmann::json& j, TcgPlayerPricesContainer& tcgPlayer);

    /**
     * Converts a TcgPlayerPricesContainer structure to JSON and back
     */
    void to_json(nlohmann::json& j, const TcgPlayerPricesContainer& tcgPlayer);

    /**
     * Structure to hold the TcgPlayer information provided by the API
     * https://docs.pokemontcg.io/api-reference/cards/card-object/#tcgplayer-hash
     */
    struct TcgPlayer {
        /**
         * The URL to the TCGPlayer store page of the card
         */
        std::string url;

        /**
         * The date that the price was last updated at. It is in the format of YYY/MM/DD
         */
        std::string updatedAt;

        /**
         * The prices gotten from TCGPlayer
         */
        TcgPlayerPricesContainer prices;

        /**
         * Returns a string representing the TCGPlayer information for the card
         */
        std::string to_string();
    };

    /**
     * Defines the functions to interchange JSON to the TcgPlayer structure and back
     */
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(TcgPlayer, url, updatedAt, prices);

    /**
     * Structure to hold the Weakness information of the card
     * https://docs.pokemontcg.io/api-reference/cards/card-object/#weaknesses-listhash
     */
    struct Weakness {
        /**
         * The Type of the Weakness
         */
        std::string type;
        
        /**
         * The Value of the Weakness
         */
        std::string value;
        
        /**
         * Returns a string representing the Weakness of the card
         */
        std::string to_string();
    };

    /**
     * Defines the functions to interchange JSON to the Weakness structure and back
     */
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(Weakness, type, value);

    /**
     * Class to Store a Card from the Pokémon TCG API
     */
    class Card {
        public:
            /**
             * Returns all cards
             */
            static std::vector<Card> all(API* api, std::string orderBy = "", std::string select = "");

            /**
             * Returns the cards matching the provided ID
             */
            static Card find(API* api, std::string id);

            /**
             * Returns the cards matching the provided query
             */
            static std::vector<Card> where(API* api, std::string query, std::string orderBy="");

            /**
             * Returns the cards matching the provided query
             */
            static std::vector<Card> where(API* api, nlohmann::json query);
            
            /**
             * Returns the ID of the Card
             */
            std::string getID();

            /**
             * Returns the Name of the Card
             */
            std::string getName();

            /**
             * Returns a list of the Card's Sub-Types
             */
            std::vector<std::string> getSubTypes();

            /**
             * Returns the Level of the Card
             */
            std::string getLevel();

            /**
             * Returns the HP of the Card
             */
            std::string getHP();

            /**
             * Returns a list of the Card's Types
             */
            std::vector<std::string> getTypes();

            /**
             * Returns the Pokémon this Card Evolves From
             */
            std::string getEvolvesFrom();

            /**
             * Returns a list of the Pokémon this Card can Evolve To
             */
            std::vector<std::string> getEvolvesTo();

            /**
             * Returns a list of the Card's Rules
             */
            std::vector<std::string> getRules();

            /**
             * Returns the Ancient Trait of the Card
             */
            AncientTrait getAncientTrait();

            /**
             * Returns a list of the Card's Abilities
             */
            std::vector<Ability> getAbilities();

            /**
             * Returns a list of the Card's Attacks
             */
            std::vector<Attack> getAttacks();

            /**
             * Returns a list of the Card's Weaknesses
             */
            std::vector<Weakness> getWeaknesses();

            /**
             * Returns a list of the Card's Resistances
             */
            std::vector<Resistance> getResistances();

            /**
             * Returns a list of the Card's Retreat Cost
             */
            std::vector<std::string> getRetreatCost();

            /**
             * Returns the Converted Retreat of the Card
             */
            int getConvertedRetreatCost();

            /**
             * Returns the Set of the Card
             */
            Set getSet();

            /**
             * Returns the Number of the Card
             */
            std::string getNumber();

            /**
             * Returns the Artist of the Card
             */
            std::string getArtist();

            /**
             * Retuns the Rarity of the Card
             */
            std::string getRarity();

            /**
             * Returns the Flavor Text of the Card
             */
            std::string getFlavorText();

            /**
             * Returns a list of the National Pokédex Numbers of the Pokémon shown in the Card
             */
            std::vector<int> getNationalPokedexNumbers();

            /**
             * Returns the Legalities of the Card
             */
            Legality getLegalities();

            /**
             * Returns the Regulation Mark of the Card
             */
            std::string getRegulationMark();

            /**
             * Returns the Images of the Card
             */
            CardImages getImages();

            /**
             * Returns the TcgPlayer Information of the Card
             */
            TcgPlayer getTcgPlayer();

            /**
             * Returns the Card Market Information of the Card
             */
            CardMarket getCardmarket();

            /**
             * Returns a string representing the Card
             */
            std::string to_string();
            
            /**
             * Defines the functions to interchange JSON to the Card Class and back
             */
            NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(Card,
                id, name, supertype, subtypes, level, hp, types,
                evolvesFrom, evolvesTo, rules, ancientTrait,
                abilities, attacks, weaknesses, resistances, retreatCost, convertedRetreatCost,
                set, number, artist, rarity, flavorText, nationalPokedexNumbers,
                legalities, regulationMark, images, tcgplayer, cardmarket);
        private:
            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#id-string
             */
            std::string id;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#name-string
             */
            std::string name;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#supertype-string
             */
            std::string supertype;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#subtypes-liststring
             */
            std::vector<std::string> subtypes;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#level-string
             */
            std::string level;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#hp-string
             */
            std::string hp;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#types-liststring
             */
            std::vector<std::string> types;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#evolvesfrom-string
             */
            std::string evolvesFrom;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#evolvesto-liststring
             */
            std::vector<std::string> evolvesTo;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#rules-liststring
             */
            std::vector<std::string> rules;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#ancienttrait-hash
             */
            AncientTrait ancientTrait;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#abilities-listhash
             */
            std::vector<Ability> abilities;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#attacks-listhash
             */
            std::vector<Attack> attacks;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#weaknesses-listhash
             */
            std::vector<Weakness> weaknesses;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#resistances-listhash
             */
            std::vector<Resistance> resistances;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#retreatcost-liststring
             */
            std::vector<std::string> retreatCost;
            
            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#convertedretreatcost-integer
             */
            int convertedRetreatCost;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#set-hash
             */
            Set set;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#number-string
             */
            std::string number;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#artist-string
             */
            std::string artist;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#rarity-string
             */
            std::string rarity;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#flavortext-string
             */
            std::string flavorText;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#nationalpokedexnumbers-listinteger
             */
            std::vector<int> nationalPokedexNumbers;
            
            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#legalities-hash
             */
            Legality legalities;
            
            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#regulationmark-string
             */
            std::string regulationMark;
            
            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#images-hash
             */
            struct CardImages images;

            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#tcgplayer-hash
             */
            struct TcgPlayer tcgplayer;
            
            /**
             * https://docs.pokemontcg.io/api-reference/cards/card-object#cardmarket-hash
             */
            struct CardMarket cardmarket;
    };
};

#endif /*__CARD_HPP__*/