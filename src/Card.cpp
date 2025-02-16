#include "Card.hpp"

namespace pokemon_tcg_sdk {
    std::string Ability::to_string(){
        std::ostringstream out;
        out << "\tAbility Name: " << name << std::endl;
        out << "\tAbility Text: " << text << std::endl;
        out << "\tAbility Type: " << type << std::endl;
        return out.str();
    }

    std::string AncientTrait::to_string(){
        std::ostringstream out;
        out << "\tAncient Trait Name: " << name << std::endl;
        out << "\tAncient Trait Text: " << text << std::endl;
        return out.str();
    }

    std::string Attack::to_string(){
        std::ostringstream out;
        out << "\tAttack Name: " << name << std::endl;
        out << "\t\tAttack Cost:" << std::endl;
        for (std::string energy : cost){
            out << "\t\t\t" << energy << std::endl;
        }
        out << "\t\tAttack Converted Cost: " << convertedEnergyCost << std::endl;
        out << "\t\tAttack Damage: " << damage << std::endl;
        out << "\t\tAttack Text: " << text << std::endl;
        return out.str();
    }

    std::string CardImages::to_string(){
        std::ostringstream out;
        out << "\tSmall Image URL: " << small << std::endl;
        out << "\tLarge Image URL: " << large << std::endl;
        return out.str();
    }

    std::string CardMarketPrices::to_string(){
        std::ostringstream out;
        out.imbue(std::locale(""));
        out << "\t\tAverage Selling Price: " << std::put_money(averageSellingPrice) << std::endl;
        out << "\t\tLow Price: " << std::put_money(lowPrice) << std::endl;
        out << "\t\tTrend Price: " << std::put_money(trendPrice) << std::endl;
        out << "\t\tGerman Pro Low Price: " << std::put_money(germanProLow) << std::endl;
        out << "\t\tSuggested Price: " << std::put_money(suggestedPrice) << std::endl;
        out << "\t\tReverse Holofoil  Sell Price: " << std::put_money(reverseHoloSell) << std::endl;
        out << "\t\tReverse Holofoil Low Price: " << std::put_money(reverseHoloLow) << std::endl;
        out << "\t\tReverse Holofoil Trend Price: " << std::put_money(reverseHoloTrend) << std::endl;
        out << "\t\tLow Price Ex Plus Price: " << std::put_money(lowPriceExPlus) << std::endl;
        out << "\t\tAverage 1 Day Price: " << std::put_money(avg1) << std::endl;
        out << "\t\tAverage 7 Day Price: " << std::put_money(avg7) << std::endl;
        out << "\t\tAverage 30 Day Price: " << std::put_money(avg30) << std::endl;
        out << "\t\tReverse Holofoil Average 1 Day Price: " << std::put_money(reverseHoloAvg1) << std::endl;
        out << "\t\tReverse Holofoil Average 7 Day Price: " << std::put_money(reverseHoloAvg7) << std::endl;
        out << "\t\tReverse Holofoil Average 30 Day Price: " << std::put_money(reverseHoloAvg30) << std::endl;
        return out.str();
    }

    std::string CardMarket::to_string(){
        std::ostringstream out;
        out << "\tCardMarket URL: " << url << std::endl;
        out << "\tCardMarket Updated At: " << updatedAt << std::endl;
        out << "\tCardMarket Prices:" << std::endl << prices.to_string();
        return out.str();
    }

    std::string Resistance::to_string(){
        std::ostringstream out;
        out << "\tResistance Type: " << type << std::endl;
        out << "\tResistance Value: " << value << std::endl;
        return out.str();
    }

    std::string TcgPlayerPrices::to_string(){
        std::ostringstream out;
        out.imbue(std::locale(""));
        out << "\t\tTcgPlayer Low Price: " << std::put_money(low) << std::endl;
        out << "\t\tTcgPlayer Mid Price: " << std::put_money(mid) << std::endl;
        out << "\t\tTcgPlayer High Price: " << std::put_money(high) << std::endl;
        out << "\t\tTcgPlayer Market Price: " << std::put_money(market) << std::endl;
        out << "\t\tTcgPlayer Direct Low Price: " << std::put_money(directLow) << std::endl;
        return out.str();
    }

    std::string TcgPlayerPricesContainer::to_string(){
        std::ostringstream out;
        out << "\tTcgPlayer Normal Prices:" << std::endl << normal.to_string();
        out << "\tTcgPlayer Holofoil Prices:" << std::endl << holofoil.to_string();
        out << "\tTcgPlayer Reverse Holofoil Prices:" << std::endl << reverseHolofoil.to_string();
        out << "\tTcgPlayer 1st Edition Holofoil Prices:" << std::endl << firstEditionHolofoil.to_string();
        out << "\tTcgPlayer 1st Edition Normal Prices:" << std::endl << firstEditionNormal.to_string();
        return out.str();
    }

    void from_json(const nlohmann::json& j, TcgPlayerPricesContainer& container){
        nlohmann::json defaultNull = nlohmann::json::parse("{}");
        j.value("normal", defaultNull).get_to(container.normal);
        j.value("holofoil", defaultNull).get_to(container.holofoil);
        j.value("reverseHolofoil", defaultNull).get_to(container.reverseHolofoil);
        j.value("1stEditionHolofoil", defaultNull).get_to(container.firstEditionHolofoil);
        j.value("1stEditionNormal", defaultNull).get_to(container.firstEditionNormal);
    }

    void to_json(nlohmann::json& j, const TcgPlayerPricesContainer& container){
        j = nlohmann::json{
            {"normal", container.normal},
            {"holofoil", container.holofoil},
            {"reverseHolofoil", container.reverseHolofoil},
            {"1stEditionHolofoil", container.firstEditionHolofoil},
            {"1stEditionNormal", container.firstEditionNormal},
        };
    }

    std::string TcgPlayer::to_string(){
        std::ostringstream out;
        out << "\tTcgPlayer URL: " << url << std::endl;
        out << "\tTcgPlayer Updated At: " << updatedAt << std::endl;
        out << prices.to_string();
        return out.str();
    }

    std::string Weakness::to_string(){
        std::ostringstream out;
        out << "\tWeakness Type: " << type << std::endl;
        out << "\tWeakness Value: " << value << std::endl;
        return out.str();
    }

    std::vector<Card> Card::all(API api){
        std::vector<Card> ret;
        return ret;
    }

    Card Card::find(API* api, std::string id){
        Card ret;
        nlohmann::json resp = Query::find(api, POKEMON_TCG_SDK_CARDS_URL, id);
        try {
            if (!resp.is_null()){
                nlohmann::json data = resp.at("data");
                ret = data.template get<Card>();
            }    
       } catch (nlohmann::json::basic_json::out_of_range ex){
            std::cout << "Data not found: " << ex.what() << std::endl; 
        }
        return ret;
    }

    std::string Card::to_string(){
        std::ostringstream out;
        out << "Card ID: " << id << std::endl;
        out << "Card Name: " << name << std::endl;
        out << "Card SuperType: " << supertype << std::endl;
        out << "Card SubTypes:" << std::endl;
        for (std::string subtype : subtypes){
            out << "\t" << subtype << std::endl;
        }
        out << "Card Level: " << level << std::endl;
        out << "Card HP: " << hp << std::endl;
        out << "Card Types:" << std::endl;
        for (std::string type : types){
            out << "\t" << type << std::endl;
        }
        out << "Card Evolves From: " << evolvesFrom << std::endl;
        out << "Card Evolves to:" << std::endl;
        for (std::string evolution : evolvesTo){
            out << "\t" << evolution << std::endl;
        }
        out << "Card Rules:" << std::endl;
        for (std::string rule : rules){
            out << "\t" << rule << std::endl;
        }
        out << "Card Ancient Trait:" << std::endl << ancientTrait.to_string();
        out << "Card Abilities:" << std::endl;
        for (Ability ability : abilities){
            out << ability.to_string();
        }
        out << "Card Attacks:" << std::endl;
        for (Attack attack : attacks){
            out << attack.to_string();
        }
        out << "Card Weaknesses:" << std::endl;
        for (Weakness weakness : weaknesses){
            out << weakness.to_string();
        }
        out << "Card Resistances:" << std::endl;
        for (Resistance resistance : resistances){
            out << resistance.to_string();
        }
        out << "Card Retreat Cost:" << std::endl;
        for (std::string energy : retreatCost){
            out << "\t" << energy << std::endl;
        }
        out << "Card Converted Retreat Cost: " << convertedRetreatCost << std::endl;
        out << "Card Set:" << std::endl << set.to_string(true);
        out << "Card Number: " << number << std::endl;
        out << "Card Artist: " << artist << std::endl;
        out << "Card Rarity: " << rarity << std::endl;
        out << "Card Flavor Text: " << flavorText << std::endl;
        out << "Card National Pokedex Numbers:" << std::endl;
        for (int num : nationalPokedexNumbers) {
            out << "\t" << num << std::endl;
        }
        out << "Card Legalities:" << std::endl << legalities.to_string(false);
        out << "Card Regulation Mark: " << regulationMark << std::endl;
        out << "Card Images:" << std::endl << images.to_string();
        out << "Card TcgPlayer:" << std::endl << tcgplayer.to_string();
        out << "Card CardMarket:" << std::endl << cardmarket.to_string();
        return out.str();
    }
}