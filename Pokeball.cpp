

#include <iostream>
#include "Pokeball.h"

Pokeball::Pokeball(){
    number=0;
}

void Pokeball::addPokemonInPokeball(Pokemon* pokemon){
    arrayOfPokemon.push_back(new Pokemon(pokemon->getName(),pokemon->getId(),pokemon->getHitPoint(),
                                         pokemon->getattackValue(),pokemon->getdefense(),pokemon->getGeneration()));
    //std::cout << "[DEBUG]: Ajout de   " << pokemon->getName() << std::endl;

    number ++;
}

void Pokeball::DeletePokemonFromPokeball(Pokemon* pokemon){
    int indexInList=this->findPositionInArrayByName(pokemon->getName());
    if (indexInList!=-1){
        delete this->arrayOfPokemon.at(indexInList);
        arrayOfPokemon.erase(arrayOfPokemon.begin()+indexInList);
        number --;}
}

void Pokeball::DeletePokemonFromPokeballByName(string name){
    int indexInList=this->findPositionInArrayByName(name);
    if (indexInList!=-1){
        delete this->arrayOfPokemon.at(indexInList);
        arrayOfPokemon.erase(arrayOfPokemon.begin()+indexInList);
        number --;}
}

void Pokeball::DeletePokemonFromPokeballById(int id){
    int indexInList=this->findPositionInArrayById(id);
    if (indexInList!=-1){
        delete this->arrayOfPokemon.at(indexInList);
        arrayOfPokemon.erase(arrayOfPokemon.begin()+indexInList);
        number --;}
}

Pokemon* Pokeball::takePokemonOutPokeball(string name) {
    int indexInList=this->findPositionInArrayByName(name);
    if (indexInList!=-1){
        Pokemon* pokemoninball = new Pokemon(*(this->arrayOfPokemon.at(indexInList)));
        delete this->arrayOfPokemon.at(indexInList);
        arrayOfPokemon.erase(arrayOfPokemon.begin()+indexInList);
        number --;
        return pokemoninball;

    }

    return nullptr;
}

Pokemon * Pokeball::takePokemonOutPokeball(int id) {
    int indexInList=this->findPositionInArrayById(id);
    if (indexInList!=-1){
        Pokemon* pokemoninball = new Pokemon(*(this->arrayOfPokemon.at(indexInList)));
        delete this->arrayOfPokemon.at(indexInList);
        arrayOfPokemon.erase(arrayOfPokemon.begin()+indexInList);
        number --;
        return pokemoninball;
    }

    return nullptr;

}

Pokemon* Pokeball::getOnePokemonByName(string name) {
    int indexInList=this->findPositionInArrayByName(name);
    if (indexInList!=-1){
        return new Pokemon(*(this->arrayOfPokemon.at(indexInList)));
    }
    return nullptr;
}
Pokemon* Pokeball::getOnePokemonById(int id) {
    int indexInList=this->findPositionInArrayById(id);
    if (indexInList!=-1){
        return new Pokemon(*(this->arrayOfPokemon.at(indexInList)));
    }
    return nullptr;
}

Pokemon* Pokeball::getFirstPokemon() {
    if (number >0) {
        NextPoke = 1;
        //std::cout << "[DEBUG]: get first de   " << 1 << std::endl;
        return arrayOfPokemon.at(0);
    } else {
        //std::cout << "[DEBUG]: get first fin   " << std::endl;
        return nullptr;
    }
};

Pokemon* Pokeball::getNextPokemon() {
    if (number > NextPoke) {
            NextPoke ++;
            //std::cout << "number  " << number << ";  NextPoke " << NextPoke << std::endl;
            //std::cout << "[DEBUG]: get next de   " << NextPoke-1 << std::endl;
            return arrayOfPokemon.at((NextPoke-1));
    } else {
        //std::cout << "[DEBUG]: get next fin   " << std::endl;
        return nullptr;
    }
};

Pokeball::~Pokeball() {
    for (Pokemon* p : arrayOfPokemon) {
        delete p;
    }
}