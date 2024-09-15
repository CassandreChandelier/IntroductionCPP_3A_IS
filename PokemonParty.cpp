//
// Created by cassa on 12/09/2024.
//


#include "PokemonParty.h"
#include <iostream>

PokemonParty::PokemonParty(int arrayOfIndexInPokeball[6], Pokeball* pokeball) {
    // On construit l'équipe de Pokémon en fonction des indices donnés dans la Pokeball
    for (int i = 0; i < 6; ++i) {
        if (arrayOfIndexInPokeball[i] != -1) {
            Pokemon* pokemon = pokeball->takePokemonOutPokeball(arrayOfIndexInPokeball[i]);
            if (pokemon != nullptr) {
                arrayOfPokemon.push_back(pokemon);
            }
        }
    }
}


/*Pokemon* PokemonParty::getOnePokemonByName(const std::string& name, Pokeball* pokeball) {
    Pokemon* pokemon = pokeball->takePokemonOutPokeball(name);
    if (pokemon && !isPartyFull()) {
        arrayOfPokemon.push_back(pokemon);
    } else if (isPartyFull()) {
        std::cout << "Party is full, cannot add more Pokémon!" << std::endl;
    }
    return pokemon;
}*/


void PokemonParty::displayParty() const {
    std::cout << "Your Pokemon Party:" << std::endl;
    for (const auto& pokemon : arrayOfPokemon) {
        pokemon->displayInfo();
    }
}


PokemonParty::~PokemonParty() {
    for (Pokemon* pokemon : arrayOfPokemon) {
        delete pokemon;
    }
}


