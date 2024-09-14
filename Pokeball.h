

#ifndef UNTITLED2_POKEBALL_H
#define UNTITLED2_POKEBALL_H

#include "SetOfPokemon2.h"


class Pokeball : public SetOfPokemon {

private:
    static int number;

public:

    Pokeball();
    void addPokemonInPokeball(Pokemon* pokemon);
    Pokemon* getOnePokemonOfPokeball(string name);
    Pokemon* getOnePokemonOfPokeball(int id);

    ~Pokeball();

};

#endif //UNTITLED2_POKEBALL_H