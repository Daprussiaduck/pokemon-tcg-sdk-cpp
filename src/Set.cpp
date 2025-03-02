#include "Set.hpp"

namespace pokemon_tcg_sdk {
    std::string SetImages::to_string(bool card = false){
        std::ostringstream out;
        out << (card ? "\t" : "") << "\tSet Symbol Image URL: " << symbol << std::endl;
        out << (card ? "\t" : "") << "\tSet Logo Image URL: " << logo << std::endl;
        return out.str();
    }

    std::string Set::getID(){
        return id;
    }

    std::string Set::getName(){
        return name;
    }

    std::string Set::getSeries(){
        return series;
    }

    int Set::getPrintedTotal(){
        return printedTotal;
    }

    int Set::getTotal(){
        return total;
    }

    Legality Set::getLegalities(){
        return legalities;
    }

    std::string Set::getPTCGoCode(){
        return ptcgoCode;
    }

    std::string Set::getReleaseDate(){
        return releaseDate;
    }

    std::string Set::getUpdatedAt(){
        return updatedAt;
    }

    SetImages Set::getImages(){
        return images;
    }

    std::string Set::to_string(bool card = false){
        std::ostringstream out;
        out << (card ? "\t" : "") << "Set ID: " << id << std::endl;
        out << (card ? "\t" : "") << "Set Name: " << name << std::endl; 
        out << (card ? "\t" : "") << "Set Series: " << series << std::endl;
        out << (card ? "\t" : "") << "Set Printed Total: " << printedTotal << " cards" << std::endl;
        out << (card ? "\t" : "") << "Set Total: " << total << " cards" << std::endl;
        out << (card ? "\t" : "") << "Set Legality: " << std::endl << legalities.to_string(true);
        out << (card ? "\t" : "") << "Set Pokemon Trading Card Game Online Code: " << ptcgoCode << std::endl;
        out << (card ? "\t" : "") << "Set Release Date: " << releaseDate << std::endl;
        out << (card ? "\t" : "") << "Set Updated At: " << updatedAt << std::endl;
        out << (card ? "\t" : "") << "Set Images:" << std::endl << images.to_string(card);
        return out.str();
    }
};