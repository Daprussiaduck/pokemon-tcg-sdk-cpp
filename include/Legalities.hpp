#ifndef __LEGALITY_HPP__
#define __LEGALITY_HPP__

#include <nlohmann/json.hpp>
#include <string>

namespace pokemon_tcg_sdk{
    struct Legality {
        std::string standard;
        std::string expanded;
        std::string unlimited;
        std::string to_string(bool set);
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(Legality, standard, expanded, unlimited);
};

#endif /*__LEGALITY_HPP__*/