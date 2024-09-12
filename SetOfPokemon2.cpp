//
// Created by antotauv on 09/09/2024.
//

#include "SetOfPokemon2.h"

#include <iostream>

SetOfPokemon::SetOfPokemon() {}

SetOfPokemon::~SetOfPokemon() {
    for (Pokemon* pokemon : arrayOfPokemon) {
        delete pokemon;
    }
}

void SetOfPokemon::displayList() const {
    std::cout << "*********************************"<< std::endl;
    for(Pokemon * pokemon : arrayOfPokemon){
        pokemon->displayInfo();
    }
}

int SetOfPokemon::findPositionInArrayByName(string name){
    for (int i=0;i<arrayOfPokemon.size();i++){
        if (name==arrayOfPokemon.at(i)->getName()){
            return i;
        }
    }
    return -1;
}

int SetOfPokemon::findPositionInArrayById(int id) {
    for (int i=0;i<arrayOfPokemon.size();i++){
        if (id==arrayOfPokemon.at(i)->getId()){
            return i;
        }
    }
    return -1;
}