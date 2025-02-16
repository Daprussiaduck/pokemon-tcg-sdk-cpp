#include "Legalities.hpp"

namespace pokemon_tcg_sdk {
    std::string Legality::to_string(){
        std::ostringstream out;
        out << "\tLegality Standard: " << standard << std::endl;
        out << "\tLegality Expanded: " << expanded << std::endl;
        out << "\tLegality Unlimited: " << unlimited << std::endl;
        return out.str();
    }
};