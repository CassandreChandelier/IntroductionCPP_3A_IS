
#ifndef UNTITLED2_POKEMONPARTY_H
#define UNTITLED2_POKEMONPARTY_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "SetOfPokemon2.h"
#include "Pokeball.h"


class PokemonParty : public SetOfPokemon {
private:
    std::vector<int> squad;

public:

    PokemonParty(int arrayOfIndexInPokeball[6], Pokeball* pokeball);

    Pokemon* getOnePokemonByName(const std::string& name, Pokeball* pokeball);

    Pokemon* getOnePokemonById(int id, Pokeball* pokeball);

    void displayParty() const; //affiche les pokemons de la partie (6)

    bool isPartyFull() const; //partie pleine ??

    void addPokemon(Pokemon* pokemon); //ajouter le pokemon depuis la pokeball

    ~PokemonParty();
};

#endif //UNTITLED2_POKEMONPARTY_H
