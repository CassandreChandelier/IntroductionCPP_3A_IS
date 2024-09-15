
#ifndef UNTITLED2_POKEMONPARTY_H
#define UNTITLED2_POKEMONPARTY_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "SetOfPokemon2.h"
#include "Pokeball.h"


class PokemonParty : public SetOfPokemon {

public:

    PokemonParty(int arrayOfIndexInPokeball[6], Pokeball* pokeball);

    //Pokemon* getOnePokemonByName(const std::string& name, Pokeball* pokeball);


    void displayParty() const; //affiche les pokemons de la partie (6)

    ~PokemonParty();
};

#endif //UNTITLED2_POKEMONPARTY_H
