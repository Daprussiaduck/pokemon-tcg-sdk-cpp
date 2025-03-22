#include "Legalities.hpp"

namespace pokemon_tcg_sdk {
    std::string Legality::to_string(bool set = false){
        std::ostringstream out;
        out << (set ? "\t" : "") << "\tLegality Standard: " << standard << std::endl;
        out << (set ? "\t" : "") << "\tLegality Expanded: " << expanded << std::endl;
        out << (set ? "\t" : "") << "\tLegality Unlimited: " << unlimited << std::endl;
        return out.str();
    }

    void from_json(const nlohmann::json &json, Legality &legality){
        if (json.contains("standard") && !(json.at("standard").is_null())){
            legality.standard = json.value("standard", "");
        }
        if (json.contains("expanded") && !(json.at("expanded").is_null())){
            legality.expanded = json.value("expanded", "");
        }
        if (json.contains("unlimited") && !(json.at("unlimited").is_null())){
            legality.unlimited = json.value("unlimited", "");
        }
    }

    void to_json(nlohmann::json &json, const Legality &legality){
        json["standard"] = legality.standard;
        json["expanded"] = legality.expanded;
        json["unlimited"] = legality.unlimited;
    }
};