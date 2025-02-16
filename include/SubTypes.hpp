#ifndef __SUBTYPES_HPP__
#define __SUBTYPES_HPP__

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "api/URLS.hpp"
#include "Api.hpp"

namespace pokemon_tcg_sdk {
    namespace SubTypes {
        std::vector<std::string> all(API* api);
    };
};

#endif /*__SUBTYPES_HPP__*/