

#include "Pokeball.h"

Pokeball::Pokeball() {}

Pokemon* Pokeball::getOnePokemonOfPokeball(string name) {
    int indexInList=this->findPositionInArrayByName(name);
    if (indexInList!=-1){
        Pokemon* pokemoninball = new Pokemon(*(this->arrayOfPokemon.at(indexInList)));
        delete this->arrayOfPokemon.at(indexInList);
        arrayOfPokemon.erase(arrayOfPokemon.begin()+indexInList);
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
        return pokemoninball;
    }

    return nullptr;

}

Pokemon *Pokeball::gettableau(Pokemon* tableau){
    return tableau;
}

Pokeball::~Pokeball() {
    for (Pokemon* p : arrayOfPokemon) {
        delete p;
    }
}