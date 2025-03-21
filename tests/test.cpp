#include <pokemon-tcg-sdk.hpp>
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

#define assertm(exp, msg) assert((void(msg), exp))

int main(int argc, char** argv){
    std::cout << "Running The main test for pokemon-tcg-sdk" << std::endl;
    std::cout << "TESTING API FUNCTIONALITY" << std::endl;
    pokemon_tcg_sdk::API api;
    nlohmann::json data = nlohmann::json::parse("{}");
    std::cout << POKEMON_TCG_SDK_CARDS_URL << std::endl;
    //nlohmann::json j = api.get(POKEMON_TCG_SDK_CARDS_URL, data);
    //std::cout << j << std::endl;
    std::cout << "TESTING CARD FUNCTIONALITY" << std::endl;
    //nlohmann::json cardJSON = pokemon_tcg_sdk::Query::find(&api, POKEMON_TCG_SDK_CARDS_URL, "xy1-1");
    //std::cout << cardJSON << std::endl;
    // pokemon_tcg_sdk::Card xy1_1(&api);
    // pokemon_tcg_sdk::Card xy1_1 = pokemon_tcg_sdk::Card::find(&api, "xy1-1");
    // std::cout << xy1_1.to_string() << std::endl;
    // std::vector<pokemon_tcg_sdk::Card> yes = pokemon_tcg_sdk::Card::all(&api);
    // std::cout << yes.size() << std::endl;
    // std::ofstream test("../out.txt");
    // for (pokemon_tcg_sdk::Card card : yes){
    //     test << card.to_string() << std::endl;
    // }
    // test.close();
    std::vector<pokemon_tcg_sdk::Card> yes = pokemon_tcg_sdk::Card::where(&api, (std::string)"name:charizard");
    std::ofstream test("../out.txt");
    for (pokemon_tcg_sdk::Card card : yes){
        test << card.to_string() << std::endl;
    }
    test.close();
    // SET TESTS
    std::cout << "TESTING SET FUNCTIONALITY" << std::endl;
    // pokemon_tcg_sdk::Set xy1_1 = pokemon_tcg_sdk::Set::find(&api, "xy1");
    // std::cout << xy1_1.to_string() << std::endl;
    // std::vector<pokemon_tcg_sdk::Set> yes = pokemon_tcg_sdk::Set::all(&api);
    // std::cout << yes.size() << std::endl;
    // std::ofstream test("../out.txt");
    // for (pokemon_tcg_sdk::Set set : yes){
    //     test << set.to_string() << std::endl;
    // }
    // test.close();
    std::cout << "Main testing done." << std::endl;
    return 0;
}