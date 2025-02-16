#ifndef __SET_HPP__
#define __SET_HPP__

#include <nlohmann/json.hpp>
#include <string>

#include "Legalities.hpp"

namespace pokemon_tcg_sdk {
    struct SetImages {
        std::string symbol;
        std::string logo;
        std::string to_string(bool card);
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(SetImages, symbol, logo);

    class Set{
        public:
            std::string to_string(bool card);
            NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(Set,
                id, name, series, printedTotal, total, legalities,
            ptcgoCode, releaseDate, updatedAt, images);
        private:
            std::string id;
            std::string name;
            std::string series;
            int printedTotal;
            int total;
            Legality legalities;
            std::string ptcgoCode;
            std::string releaseDate;
            std::string updatedAt;
            struct SetImages images;
    };
};

#endif /*__SET_HPP__*/