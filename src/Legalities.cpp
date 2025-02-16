#include "Legalities.hpp"

namespace pokemon_tcg_sdk {
    std::string Legality::to_string(bool set = false){
        std::ostringstream out;
        out << (set ? "\t" : "") << "\tLegality Standard: " << standard << std::endl;
        out << (set ? "\t" : "") << "\tLegality Expanded: " << expanded << std::endl;
        out << (set ? "\t" : "") << "\tLegality Unlimited: " << unlimited << std::endl;
        return out.str();
    }
};