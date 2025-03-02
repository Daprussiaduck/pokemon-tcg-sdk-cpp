#include <pokemon-tcg-sdk.hpp>
#include <iostream>
#include <cassert>
#include <string>

#define assertm(exp, msg) assert((void(msg), exp))

int main(int argc, char** argv){
    std::cout << "Running The main test for pokemon-tcg-sdk" << std::endl;
    pokemon_tcg_sdk::API api;
    nlohmann::json data = nlohmann::json::parse("{}");
    std::cout << POKEMON_TCG_SDK_CARDS_URL << std::endl;
    //nlohmann::json j = api.get(POKEMON_TCG_SDK_CARDS_URL, data);
    //std::cout << j << std::endl;
    //nlohmann::json cardJSON = pokemon_tcg_sdk::Query::find(&api, POKEMON_TCG_SDK_CARDS_URL, "xy1-1");
    //std::cout << cardJSON << std::endl;
    //pokemon_tcg_sdk::Card xy1_1(&api);
    pokemon_tcg_sdk::Card xy1_1 = pokemon_tcg_sdk::Card::find(&api, "xy1-1");
    std::cout << xy1_1.to_string() << std::endl;
    std::vector<pokemon_tcg_sdk::Card> yes = pokemon_tcg_sdk::Card::all(&api);
    std::cout << yes.size() << std::endl;
    std::cout << "Main testing done." << std::endl;
    return 0;
}