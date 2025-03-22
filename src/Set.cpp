#include "Set.hpp"

namespace pokemon_tcg_sdk {
    std::string SetImages::to_string(bool card = false){
        std::ostringstream out;
        out << (card ? "\t" : "") << "\tSet Symbol Image URL: " << symbol << std::endl;
        out << (card ? "\t" : "") << "\tSet Logo Image URL: " << logo << std::endl;
        return out.str();
    }

    void from_json(const nlohmann::json &json, SetImages &setImages){
        if (json.contains("symbol") && !(json.at("symbol").is_null())){
            setImages.symbol = json.value("symbol", "");
        }
        if (json.contains("logo") && !(json.at("logo").is_null())){
            setImages.logo = json.value("logo", "");
        }
    }

    void to_json(nlohmann::json &json, const SetImages &setImages){
        json["symbol"] = setImages.symbol;
        json["logo"] = setImages.logo;
    }

    std::string Set::getID(){
        return id;
    }

    std::string Set::getName(){
        return name;
    }

    std::string Set::getSeries(){
        return series;
    }

    int Set::getPrintedTotal(){
        return printedTotal;
    }

    int Set::getTotal(){
        return total;
    }

    Legality Set::getLegalities(){
        return legalities;
    }

    std::string Set::getPTCGoCode(){
        return ptcgoCode;
    }

    std::string Set::getReleaseDate(){
        return releaseDate;
    }

    std::string Set::getUpdatedAt(){
        return updatedAt;
    }

    SetImages Set::getImages(){
        return images;
    }

    std::string Set::to_string(bool card = false){
        std::ostringstream out;
        out << (card ? "\t" : "") << "Set ID: " << id << std::endl;
        out << (card ? "\t" : "") << "Set Name: " << name << std::endl; 
        out << (card ? "\t" : "") << "Set Series: " << series << std::endl;
        out << (card ? "\t" : "") << "Set Printed Total: " << printedTotal << " cards" << std::endl;
        out << (card ? "\t" : "") << "Set Total: " << total << " cards" << std::endl;
        out << (card ? "\t" : "") << "Set Legality: " << std::endl << legalities.to_string(true);
        out << (card ? "\t" : "") << "Set Pokemon Trading Card Game Online Code: " << ptcgoCode << std::endl;
        out << (card ? "\t" : "") << "Set Release Date: " << releaseDate << std::endl;
        out << (card ? "\t" : "") << "Set Updated At: " << updatedAt << std::endl;
        out << (card ? "\t" : "") << "Set Images:" << std::endl << images.to_string(card);
        return out.str();
    }

    void from_json(const nlohmann::json &json, Set &set){
        nlohmann::json defaultNull = nlohmann::json::parse("{}");
        if (json.contains("id") && !(json.at("id").is_null())){
            set.id = json.value("id", "");
        }
        if (json.contains("name") && !(json.at("name").is_null())){
            set.name = json.value("name", "");
        }
        if (json.contains("series") && !(json.at("series").is_null())){
            set.series = json.value("series", "");
        }
        if (json.contains("printedTotal") && !(json.at("printedTotal").is_null())){
            set.printedTotal = json.value("printedTotal", 0);
        }
        if (json.contains("total") && !(json.at("total").is_null())){
            set.total = json.value("total", 0);
        }
        if (json.contains("legalities") && !(json.at("legalities").is_null())){
            set.legalities = json.value("legalities", defaultNull);
        }
        if (json.contains("ptcgoCode") && !(json.at("ptcgoCode").is_null())){
            set.ptcgoCode = json.value("ptcgoCode", "");
        }
        if (json.contains("releaseDate") && !(json.at("releaseDate").is_null())){
            set.releaseDate = json.value("releaseDate", "");
        }
        if (json.contains("updatedAt") && !(json.at("updatedAt").is_null())){
            set.updatedAt = json.value("updatedAt", "");
        }
        if (json.contains("images") && !(json.at("images").is_null())){
            set.images = json.value("images", defaultNull);
        }
    }

    void to_json(nlohmann::json &json, const Set &set){
        json["id"] = set.id;
        json["name"] = set.name;
        json["series"] = set.series;
        json["printedTotal"] = set.printedTotal;
        json["total"] = set.total;
        json["legalities"] = set.legalities;
        json["ptcgoCode"] = set.ptcgoCode;
        json["releaseDate"] = set.releaseDate;
        json["updatedAt"] = set.updatedAt;
        json["images"] = set.images;
    }
};