#ifndef __TYPES_HPP__
#define __TYPES_HPP__

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "api/URLS.hpp"
#include "Api.hpp"

namespace pokemon_tcg_sdk {
    namespace Types {
        std::vector<std::string> all(API* api);
    };
};

#endif /*__TYPES_HPP__*/