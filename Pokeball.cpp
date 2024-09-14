

#include "Pokeball.h"

Pokeball::Pokeball(){}

int Pokeball::number=0;

void Pokeball::addPokemonInPokeball(Pokemon* pokemon){
    arrayOfPokemon.push_back(new Pokemon(pokemon->getName(),pokemon->getId(),pokemon->getHitPoint(),
                                         pokemon->getattackValue(),pokemon->getdefense(),pokemon->getGeneration()));
    number ++;
}

Pokemon* Pokeball::getOnePokemonOfPokeball(string name) {
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

Pokemon * Pokeball::getOnePokemonOfPokeball(int id){
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


Pokeball::~Pokeball() {
    for (Pokemon* p : arrayOfPokemon) {
        delete p;
    }
}