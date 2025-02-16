#ifndef __RARITIES_HPP__
#define __RARITIES_HPP__

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "api/URLS.hpp"
#include "Api.hpp"

namespace pokemon_tcg_sdk {
    namespace Rarities {
        std::vector<std::string> all(API* api);
    };
};

#endif /*__RARITIES_HPP__*/