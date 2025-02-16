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
    struct Ability {
        std::string name;
        std::string text;
        std::string type;
        std::string to_string();
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(Ability, name, text, type);

    struct AncientTrait {
        std::string name;
        std::string text;
        std::string to_string();
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(AncientTrait, name, text);
    
    struct Attack {
        std::string name;
        std::vector<std::string> cost;
        int convertedEnergyCost;
        std::string damage;
        std::string text;
        std::string to_string();
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(Attack, cost, name, text, damage, convertedEnergyCost);

    struct CardImages {
        std::string small;
        std::string large;
        std::string to_string();
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(CardImages, small, large);

    struct CardMarketPrices {
        double averageSellingPrice;
        double lowPrice;
        double trendPrice;
        double germanProLow;
        double suggestedPrice;
        double reverseHoloSell;
        double reverseHoloLow;
        double reverseHoloTrend;
        double lowPriceExPlus;
        double avg1;
        double avg7;
        double avg30;
        double reverseHoloAvg1;
        double reverseHoloAvg7;
        double reverseHoloAvg30;
        std::string to_string();
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(CardMarketPrices,
        averageSellingPrice, lowPrice, trendPrice, germanProLow, suggestedPrice,
        reverseHoloSell, reverseHoloLow, reverseHoloTrend, lowPriceExPlus,
        avg1, avg7, avg30, reverseHoloAvg1, reverseHoloAvg7, reverseHoloAvg30);

    struct CardMarket {
        std::string url;
        std::string updatedAt;
        struct CardMarketPrices prices;
        std::string to_string();
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(CardMarket, url, updatedAt, prices);

    struct Resistance {
        std::string type;
        std::string value;
        std::string to_string();
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(Resistance, type, value);

    struct TcgPlayerPrices {
        double low;
        double mid;
        double high;
        double market;
        double directLow;
        std::string to_string();
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(TcgPlayerPrices, low, mid, high, market, directLow);

    struct TcgPlayerPricesContainer {
        struct TcgPlayerPrices normal;
        struct TcgPlayerPrices holofoil;
        struct TcgPlayerPrices reverseHolofoil;
        struct TcgPlayerPrices firstEditionHolofoil;
        struct TcgPlayerPrices firstEditionNormal;
        std::string to_string();
    };

    void from_json(const nlohmann::json& j, TcgPlayerPricesContainer& tcgPlayer);
    void to_json(nlohmann::json& j, const TcgPlayerPricesContainer& tcgPlayer);

    struct TcgPlayer {
        std::string url;
        std::string updatedAt;
        TcgPlayerPricesContainer prices;
        std::string to_string();
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(TcgPlayer, url, updatedAt, prices);

    struct Weakness {
        std::string type;
        std::string value;
        std::string to_string();
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(Weakness, type, value);

    class Card {
        public:
            static std::vector<Card> all(API api);
            static Card find(API* api, std::string id);
            static std::vector<Card> where(API api, std::string query);
            static std::vector<Card> where(API api, nlohmann::json query);
            std::string to_string();
            NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(Card,
                id, name, supertype, subtypes, level, hp, types,
                evolvesFrom, evolvesTo, rules, ancientTrait,
                abilities, attacks, weaknesses, resistances, retreatCost, convertedRetreatCost,
                set, number, artist, rarity, flavorText, nationalPokedexNumbers,
                legalities, regulationMark, images, tcgplayer, cardmarket);
        private:
            std::string id;
            std::string name;
            std::string supertype;
            std::vector<std::string> subtypes;
            std::string level;
            std::string hp;
            std::vector<std::string> types;
            std::string evolvesFrom;
            std::vector<std::string> evolvesTo;
            std::vector<std::string> rules;
            AncientTrait ancientTrait;
            std::vector<Ability> abilities;
            std::vector<Attack> attacks;
            std::vector<Weakness> weaknesses;
            std::vector<Resistance> resistances;
            std::vector<std::string> retreatCost;
            int convertedRetreatCost;
            Set set;
            std::string number;
            std::string artist;
            std::string rarity;
            std::string flavorText;
            std::vector<int> nationalPokedexNumbers;
            Legality legalities;
            std::string regulationMark;
            struct CardImages images;
            struct TcgPlayer tcgplayer;
            struct CardMarket cardmarket;
    };
};

#endif /*__CARD_HPP__*/