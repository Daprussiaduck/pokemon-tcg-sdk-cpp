#include "Card.hpp"

namespace pokemon_tcg_sdk {
    std::string Ability::to_string(){
        std::ostringstream out;
        out << "\tAbility Name: " << name << std::endl;
        out << "\tAbility Text: " << text << std::endl;
        out << "\tAbility Type: " << type << std::endl;
        return out.str();
    }

    void from_json(const nlohmann::json &json, Ability &ability){
        if (json.contains("name") && !(json.at("name").is_null())){
            ability.name = json.value("name", "");
        }
        if (json.contains("text") && !(json.at("text").is_null())){
            ability.text = json.value("text", "");
        }
        if (json.contains("type") && !(json.at("type").is_null())){
            ability.type = json.value("type", "");
        }
    }

    void to_json(nlohmann::json &json, const Ability &ability){
        json["name"] = ability.name;
        json["text"] = ability.text;
        json["type"] = ability.type;
    }

    std::string AncientTrait::to_string(){
        std::ostringstream out;
        out << "\tAncient Trait Name: " << name << std::endl;
        out << "\tAncient Trait Text: " << text << std::endl;
        return out.str();
    }

    void from_json(const nlohmann::json &json, AncientTrait &ancientTrait){
        if (json.contains("name") && !(json.at("name").is_null())){
            ancientTrait.name = json.value("name", "");
        }
        if (json.contains("text") && !(json.at("text").is_null())){
            ancientTrait.text = json.value("text", "");
        }
        
    }

    void to_json(nlohmann::json &json, const AncientTrait &ancientTrait){
        json["name"] = ancientTrait.name;
        json["text"] = ancientTrait.text;
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

    void from_json(const nlohmann::json &json, Attack &attack){
        if (json.contains("name") && !(json.at("name").is_null())){
            attack.name = json.value("name", "");
        }
        if (json.contains("cost") && !(json.at("cost").is_null())){
            attack.cost = json.value("cost", std::vector<std::string>());
        }
        if (json.contains("convertedEnergyCost") && !(json.at("convertedEnergyCost").is_null())){
            attack.convertedEnergyCost = json.value("convertedEnergyCost", 0);
        }
        if (json.contains("damage") && !(json.at("damage").is_null())){
            attack.damage = json.value("damage", "");
        }
        if (json.contains("text") && !(json.at("text").is_null())){
            attack.text = json.value("text", "");
        }
    }

    void to_json(nlohmann::json &json, const Attack &attack){
        json["name"] = attack.name;
        json["cost"] = attack.cost;
        json["convertedEnergyCost"] = attack.convertedEnergyCost;
        json["damage"] = attack.damage;
        json["text"] = attack.text;
    }

    std::string CardImages::to_string(){
        std::ostringstream out;
        out << "\tSmall Image URL: " << small << std::endl;
        out << "\tLarge Image URL: " << large << std::endl;
        return out.str();
    }

    void from_json(const nlohmann::json &json, CardImages &images){
        if (json.contains("small") && !(json.at("small").is_null())){
            images.small = json.value("small", "");
        }
        if (json.contains("large") && !(json.at("large").is_null())){
            images.large = json.value("large", "");
        }
    }

    void to_json(nlohmann::json &json, const CardImages &images){
        json["small"] = images.small;
        json["large"] = images.large;
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

    void from_json(const nlohmann::json &json, CardMarketPrices &cardMarketPrices){
        if (json.contains("averageSellingPrice") && !(json.at("averageSellingPrice").is_null())){
            cardMarketPrices.averageSellingPrice = json.value("averageSellingPrice", 0.0);
        }
        if (json.contains("lowPrice") && !(json.at("lowPrice").is_null())){
            cardMarketPrices.lowPrice = json.value("lowPrice", 0.0);
        }
        if (json.contains("trendPrice") && !(json.at("trendPrice").is_null())){
            cardMarketPrices.trendPrice = json.value("trendPrice", 0.0);
        }
        if (json.contains("germanProLow") && !(json.at("germanProLow").is_null())){
            cardMarketPrices.germanProLow = json.value("germanProLow", 0.0);
        }
        if (json.contains("suggestedPrice") && !(json.at("suggestedPrice").is_null())){
            cardMarketPrices.suggestedPrice = json.value("suggestedPrice", 0.0);
        }
        if (json.contains("reverseHoloSell") && !(json.at("reverseHoloSell").is_null())){
            cardMarketPrices.reverseHoloSell = json.value("reverseHoloSell", 0.0);
        }
        if (json.contains("reverseHoloLow") && !(json.at("reverseHoloLow").is_null())){
            cardMarketPrices.reverseHoloLow = json.value("reverseHoloLow", 0.0);
        }
        if (json.contains("reverseHoloTrend") && !(json.at("reverseHoloTrend").is_null())){
            cardMarketPrices.reverseHoloTrend = json.value("reverseHoloTrend", 0.0);
        }
        if (json.contains("lowPriceExPlus") && !(json.at("lowPriceExPlus").is_null())){
            cardMarketPrices.lowPriceExPlus = json.value("lowPriceExPlus", 0.0);
        }
        if (json.contains("avg1") && !(json.at("avg1").is_null())){
            cardMarketPrices.avg1 = json.value("avg1", 0.0);
        }
        if (json.contains("avg7") && !(json.at("avg7").is_null())){
            cardMarketPrices.avg7 = json.value("avg7", 0.0);
        }
        if (json.contains("avg30") && !(json.at("avg30").is_null())){
            cardMarketPrices.avg30 = json.value("avg30", 0.0);
        }
        if (json.contains("reverseHoloAvg1") && !(json.at("reverseHoloAvg1").is_null())){
            cardMarketPrices.reverseHoloAvg1 = json.value("reverseHoloAvg1", 0.0);
        }
        if (json.contains("reverseHoloAvg7") && !(json.at("reverseHoloAvg7").is_null())){
            cardMarketPrices.reverseHoloAvg7 = json.value("reverseHoloAvg7", 0.0);
        }
        if (json.contains("reverseHoloAvg30") && !(json.at("reverseHoloAvg30").is_null())){
            cardMarketPrices.reverseHoloAvg30 = json.value("reverseHoloAvg30", 0.0);
        }
    }

    void to_json(nlohmann::json &json, const CardMarketPrices &cardMarketPrices){
        json["averageSellingPrice"] = cardMarketPrices.averageSellingPrice;
        json["lowPrice"] = cardMarketPrices.lowPrice;
        json["trendPrice"] = cardMarketPrices.trendPrice;
        json["germanProLow"] = cardMarketPrices.germanProLow;
        json["suggestedPrice"] = cardMarketPrices.suggestedPrice;
        json["reverseHoloSell"] = cardMarketPrices.reverseHoloSell;
        json["reverseHoloLow"] = cardMarketPrices.reverseHoloLow;
        json["reverseHoloTrend"] = cardMarketPrices.reverseHoloTrend;
        json["lowPriceExPlus"] = cardMarketPrices.lowPriceExPlus;
        json["avg1"] = cardMarketPrices.avg1;
        json["avg7"] = cardMarketPrices.avg7;
        json["avg30"] = cardMarketPrices.avg30;
        json["reverseHoloAvg1"] = cardMarketPrices.reverseHoloAvg1;
        json["reverseHoloAvg7"] = cardMarketPrices.reverseHoloAvg7;
        json["reverseHoloAvg30"] = cardMarketPrices.reverseHoloAvg30;
        
    }

    std::string CardMarket::to_string(){
        std::ostringstream out;
        out << "\tCardMarket URL: " << url << std::endl;
        out << "\tCardMarket Updated At: " << updatedAt << std::endl;
        out << "\tCardMarket Prices:" << std::endl << prices.to_string();
        return out.str();
    }

    void from_json(const nlohmann::json &json, CardMarket &cardMarket){
        nlohmann::json defaultNull = nlohmann::json::parse("{}");
        if (json.contains("url") && !(json.at("url").is_null())){
            cardMarket.url = json.value("url", "");
        }
        if (json.contains("updatedAt") && !(json.at("updatedAt").is_null())){
            cardMarket.updatedAt = json.value("updatedAt", "");
        }
        if (json.contains("prices") && !(json.at("prices").is_null())){
            cardMarket.prices = json.value("prices", defaultNull);
        }
    }

    void to_json(nlohmann::json &json, const CardMarket &cardMarket){
        json["url"] = cardMarket.url;
        json["updatedAt"] = cardMarket.updatedAt;
        json["prices"] = cardMarket.prices;
    }

    std::string Resistance::to_string(){
        std::ostringstream out;
        out << "\tResistance Type: " << type << std::endl;
        out << "\tResistance Value: " << value << std::endl;
        return out.str();
    }

    void from_json(const nlohmann::json &json, Resistance &resistance){
        if(json.contains("type") && !(json.at("type").is_null())){
            resistance.type = json.value("type", "");
        }
        if(json.contains("value") && !(json.at("value").is_null())){
            resistance.value = json.value("value", "");
        }
    }

    void to_json(nlohmann::json &json, const Resistance &resistance){
        json["type"] = resistance.type;
        json["value"] = resistance.value;
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

    void from_json(const nlohmann::json &json, TcgPlayerPrices &tcgPlayerPrices){
        if (json.contains("low") && !json.at("low").is_null()){
            tcgPlayerPrices.directLow = json.value("low", 0.0);
        }
        if (json.contains("mid") && !json.at("mid").is_null()){
            tcgPlayerPrices.directLow = json.value("mid", 0.0);
        }
        if (json.contains("high") && !json.at("high").is_null()){
            tcgPlayerPrices.directLow = json.value("high", 0.0);
        }
        if (json.contains("market") && !json.at("market").is_null()){
            tcgPlayerPrices.directLow = json.value("market", 0.0);
        }
        if (json.contains("directLow") && !json.at("directLow").is_null()){
            tcgPlayerPrices.directLow = json.value("directLow", 0.0);
        }
    }

    void to_json(nlohmann::json &json, const TcgPlayerPrices &tcgPlayerPrices){
        json.at("low") = tcgPlayerPrices.low;
        json.at("mid") = tcgPlayerPrices.mid;
        json.at("high") = tcgPlayerPrices.high;
        json.at("market") = tcgPlayerPrices.market;
        json.at("directLow") = tcgPlayerPrices.directLow;
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

    void from_json(const nlohmann::json& json, TcgPlayerPricesContainer& tcgPlayerPricesContainer){
        nlohmann::json defaultNull = nlohmann::json::parse("{}");
        if (json.contains("normal") && !(json.at("normal").is_null())){
            tcgPlayerPricesContainer.normal = json.value("normal", defaultNull);
        }
        if (json.contains("holofoil") && !(json.at("holofoil").is_null())){
            tcgPlayerPricesContainer.holofoil = json.value("holofoil", defaultNull);
        }
        if (json.contains("reverseHolofoil") && !(json.at("reverseHolofoil").is_null())){
            tcgPlayerPricesContainer.reverseHolofoil = json.value("reverseHolofoil", defaultNull);
        }
        if (json.contains("firstEditionHolofoil") && !(json.at("firstEditionHolofoil").is_null())){
            tcgPlayerPricesContainer.firstEditionHolofoil = json.value("firstEditionHolofoil", defaultNull);
        }
        if (json.contains("firstEditionNormal") && !(json.at("firstEditionNormal").is_null())){
            tcgPlayerPricesContainer.firstEditionNormal = json.value("firstEditionNormal", defaultNull);
        }
    }

    void to_json(nlohmann::json &json, const TcgPlayerPricesContainer &tcgPlayerPricesContainer){
        json["normal"] = tcgPlayerPricesContainer.normal;
        json["holofoil"] = tcgPlayerPricesContainer.holofoil;
        json["reverseHolofoil"] = tcgPlayerPricesContainer.reverseHolofoil;
        json["firstEditionHolofoil"] = tcgPlayerPricesContainer.firstEditionHolofoil;
        json["firstEditionNormal"] = tcgPlayerPricesContainer.firstEditionNormal;
    }

    std::string TcgPlayer::to_string(){
        std::ostringstream out;
        out << "\tTcgPlayer URL: " << url << std::endl;
        out << "\tTcgPlayer Updated At: " << updatedAt << std::endl;
        out << prices.to_string();
        return out.str();
    }

    void from_json(const nlohmann::json &json, TcgPlayer &tcgPlayer){
        nlohmann::json defaultNull = nlohmann::json::parse("{}");
        if (json.contains("url") && !(json.at("url").is_null())){
            tcgPlayer.url = json.value("url", "");
        }
        if (json.contains("updatedAt") && !(json.at("updatedAt").is_null())){
            tcgPlayer.updatedAt = json.value("updatedAt", "");
        }
        if (json.contains("prices") && !(json.at("prices").is_null())){
            tcgPlayer.prices = json.value("prices", defaultNull);
        }
    }

    void to_json(nlohmann::json &json, const TcgPlayer &tcgPlayer){
        json["url"] = tcgPlayer.url;
        json["updatedAt"] = tcgPlayer.updatedAt;
        json["prices"] = tcgPlayer.prices;
    }

    std::string Weakness::to_string(){
        std::ostringstream out;
        out << "\tWeakness Type: " << type << std::endl;
        out << "\tWeakness Value: " << value << std::endl;
        return out.str();
    }

    void from_json(const nlohmann::json &json, Weakness &weakness){
        if (json.contains("type") && !(json.at("type").is_null())){
            weakness.type = json.value("type", "");
        }
        if (json.contains("value") && !(json.at("value").is_null())){
            weakness.value = json.value("value", "");
        }
    }

    void to_json(nlohmann::json &json, const Weakness &weakness){
        json["type"] = weakness.type;
        json["value"] = weakness.value;
    }

    std::vector<Card> Card::all(API* api, std::string orderBy, std::string select){
        return Query::all<Card>(api, POKEMON_TCG_SDK_CARDS_URL, orderBy, select);
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

    std::vector<Card> Card::where(API* api, std::string query, std::string orderBy){
        std::vector<Card> ret;
        return ret;
    }

    std::vector<Card> Card::where(API* api, nlohmann::json query){
        std::vector<Card> ret;
        return ret;
    }

    std::string Card::getID(){
        return id;
    }

    std::string Card::getName(){
        return name;
    }

    std::vector<std::string> Card::getSubTypes(){
        return subtypes;
    }

    std::string Card::getLevel(){
        return level;
    }

    std::string Card::getHP(){
        return hp;
    }

    std::vector<std::string> Card::getTypes(){
        return types;
    }

    std::string Card::getEvolvesFrom(){
        return evolvesFrom;
    }
    
    std::vector<std::string> Card::getEvolvesTo(){
        return evolvesTo;
    }

    std::vector<std::string> Card::getRules(){
        return rules;
    }

    AncientTrait Card::getAncientTrait(){
        return ancientTrait;
    }

    std::vector<Ability> Card::getAbilities(){
        return abilities;
    }

    std::vector<Attack> Card::getAttacks(){
        return attacks;
    }

    std::vector<Weakness> Card::getWeaknesses(){
        return weaknesses;
    }

    std::vector<Resistance> Card::getResistances(){
        return resistances;
    }

    std::vector<std::string> Card::getRetreatCost(){
        return retreatCost;
    }

    int Card::getConvertedRetreatCost(){
        return convertedRetreatCost;
    }

    Set Card::getSet(){
        return set;
    }

    std::string Card::getNumber(){
        return number;
    }

    std::string Card::getArtist(){
        return artist;
    }

    std::string Card::getRarity(){
        return rarity;
    }

    std::string Card::getFlavorText(){
        return flavorText;
    }

    std::vector<int> Card::getNationalPokedexNumbers(){
        return nationalPokedexNumbers;
    }

    Legality Card::getLegalities(){
        return legalities;
    }

    std::string Card::getRegulationMark(){
        return regulationMark;
    }

    CardImages Card::getImages(){
        return images;
    }

    TcgPlayer Card::getTcgPlayer(){
        return tcgplayer;
    }

    CardMarket Card::getCardmarket(){
        return cardmarket;
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

    void from_json(const nlohmann::json &json, Card &card){
        nlohmann::json defaultNull = nlohmann::json::parse("{}");
        if (json.contains("id") && !(json.at("id").is_null())){
            card.id = json.value("id", "");
        }
        if (json.contains("name") && !(json.at("name").is_null())){
            card.name = json.value("name", "");
        }
        if (json.contains("supertype") && !(json.at("supertype").is_null())){
            card.supertype = json.value("supertype", "");
        }
        if (json.contains("subtypes") && !(json.at("subtypes").is_null())){
            card.subtypes = json.value("subtypes", defaultNull);
        }
        if (json.contains("level") && !(json.at("level").is_null())){
            card.level = json.value("level", "");
        }
        if (json.contains("hp") && !(json.at("hp").is_null())){
            card.hp = json.value("hp", "");
        }
        if (json.contains("types") && !(json.at("types").is_null())){
            card.types = json.value("types", defaultNull);
        }
        if (json.contains("evolvesFrom") && !(json.at("evolvesFrom").is_null())){
            card.evolvesFrom = json.value("evolvesFrom", "");
        }
        if (json.contains("evolvesTo") && !(json.at("evolvesTo").is_null())){
            card.evolvesTo = json.value("evolvesTo", defaultNull);
        }
        if (json.contains("rules") && !(json.at("rules").is_null())){
            card.rules = json.value("rules", defaultNull);
        }
        if (json.contains("ancientTrait") && !(json.at("ancientTrait").is_null())){
            card.ancientTrait = json.value("ancientTrait", defaultNull);
        }
        if (json.contains("abilities") && !(json.at("abilities").is_null())){
            card.abilities = json.value("abilities", defaultNull);
        }
        if (json.contains("attacks") && !(json.at("attacks").is_null())){
            card.attacks = json.value("attacks", defaultNull);
        }
        if (json.contains("weaknesses") && !(json.at("weaknesses").is_null())){
            card.weaknesses = json.value("weaknesses", defaultNull);
        }
        if (json.contains("resistances") && !(json.at("resistances").is_null())){
            card.resistances = json.value("resistances", defaultNull);
        }
        if (json.contains("retreatCost") && !(json.at("retreatCost").is_null())){
            card.retreatCost = json.value("retreatCost", defaultNull);
        }
        if (json.contains("convertedRetreatCost") && !(json.at("convertedRetreatCost").is_null())){
            card.convertedRetreatCost = json.value("convertedRetreatCost", 0);
        }
        if (json.contains("set") && !(json.at("set").is_null())){
            card.set = json.value("set", defaultNull);
        }
        if (json.contains("number") && !(json.at("number").is_null())){
            card.number = json.value("number", "");
        }
        if (json.contains("artist") && !(json.at("artist").is_null())){
            card.artist = json.value("artist", "");
        }
        if (json.contains("rarity") && !(json.at("rarity").is_null())){
            card.rarity = json.value("rarity", "");
        }
        if (json.contains("flavorText") && !(json.at("flavorText").is_null())){
            card.flavorText = json.value("flavorText", "");
        }
        if (json.contains("nationalPokedexNumbers") && !(json.at("nationalPokedexNumbers").is_null())){
            std::vector<int> arrayNull;
            card.nationalPokedexNumbers = json.value("nationalPokedexNumbers", arrayNull);
        }
        if (json.contains("legalities") && !(json.at("legalities").is_null())){
            card.legalities = json.value("legalities", defaultNull);
        }
        if (json.contains("regulationMark") && !(json.at("regulationMark").is_null())){
            card.regulationMark = json.value("regulationMark", "");
        }
        if (json.contains("images") && !(json.at("images").is_null())){
            card.images = json.value("images", defaultNull);
        }
        if (json.contains("tcgplayer") && !(json.at("tcgplayer").is_null())){
            card.tcgplayer = json.value("tcgplayer", defaultNull);
        }
        if (json.contains("cardmarket") && !(json.at("cardmarket").is_null())){
            card.cardmarket = json.value("cardmarket", defaultNull);
        }
    }

    void to_json(nlohmann::json &json, const Card &card){
        json["id"] = card.id;
        json["name"] = card.name;
        json["supertype"] = card.supertype;
        json["subtypes"] = card.subtypes;
        json["level"] = card.level;
        json["hp"] = card.hp;
        json["types"] = card.types;
        json["evolvesFrom"] = card.evolvesFrom;
        json["evolvesTo"] = card.evolvesTo;
        json["rules"] = card.rules;
        json["ancientTrait"] = card.ancientTrait;
        json["abilities"] = card.abilities;
        json["weaknesses"] = card.weaknesses;
        json["resistances"] = card.resistances;
        json["retreatCost"] = card.retreatCost;
        json["convertedRetreatCost"] = card.convertedRetreatCost;
        json["set"] = card.set;
        json["number"] = card.number;
        json["artist"] = card.artist;
        json["rarity"] = card.rarity;
        json["flavorText"] = card.flavorText;
        json["nationalPokedexNumbers"] = card.nationalPokedexNumbers;
        json["legalities"] = card.legalities;
        json["regulationMark"] = card.regulationMark;
        json["images"] = card.images;
        json["tcgplayer"] = card.tcgplayer;
        json["cardmarket"] = card.cardmarket;
    }

}