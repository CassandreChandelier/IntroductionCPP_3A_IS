

#include <fstream>
#include <iostream>
#include <sstream>
#include "Pokedex2.h"

Pokedex* Pokedex::instance = nullptr;

Pokedex::Pokedex(string fileName):SetOfPokemon() {

    //std::cout << "*** Constructeur du Pokedex ***" << std::endl;

    std::ifstream file(fileName);
    if(!file.is_open()){
        std::cerr<<"File "<<fileName<<" not found "<<std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
    //    std::cout << line << std::endl;
        std::stringstream inputstringstream(line);
        std::string cell;
        std::vector<std::string> lineData;

        while(std::getline(inputstringstream,cell,',')){
            lineData.push_back(cell);
        }
        int id = std::stoi(lineData.at(0));
        double attackValue = std::stod(lineData.at(6));
        double hitPoint = std::stod(lineData.at(5));
        double defenseValue = std::stod(lineData.at(7));
        int generation = std::stoi(lineData.at(11));

        arrayOfPokemon.push_back(new Pokemon(lineData.at(1),id,hitPoint,attackValue,
                                             defenseValue,generation));
    }
}

Pokedex* Pokedex::getInstance() {
    if (instance== nullptr){
        instance = new Pokedex("C:/Users/cassa/CLionProjects/untitled1/ressources/pokedex.csv");
    }
    return instance;
}

Pokemon* Pokedex::getOnePokemonByName(string name) {
    int indexInList=this->findPositionInArrayByName(name);
    if (indexInList!=-1){
        return new Pokemon(*(this->arrayOfPokemon.at(indexInList)));
    }
    return nullptr;
}
Pokemon* Pokedex::getOnePokemonById(int id) {
    int indexInList=this->findPositionInArrayById(id);
    if (indexInList!=-1){
        return new Pokemon(*(this->arrayOfPokemon.at(indexInList)));
    }
    return nullptr;
}

Pokedex::~Pokedex(){

}





