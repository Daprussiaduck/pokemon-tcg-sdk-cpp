#ifndef __SUPERTYPES_HPP__
#define __SUPERTYPES_HPP__

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "api/URLS.hpp"
#include "Api.hpp"

namespace pokemon_tcg_sdk {
    namespace SuperTypes {
        std::vector<std::string> all(API* api);
    };
};

#endif /*__SUPERTYPES_HPP__*/