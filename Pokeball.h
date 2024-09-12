

#ifndef UNTITLED2_POKEBALL_H
#define UNTITLED2_POKEBALL_H

#include "SetOfPokemon2.h"


class Pokeball : public SetOfPokemon {
private:
    Pokemon* tableau[];


public:
    Pokemon *getOnePokemonOfPokeball(string name);
    Pokemon *getOnePokemonOfPokeball(int id);

    ~Pokeball();

    Pokemon *gettableau(Pokemon *tableau);
};

#endif //UNTITLED2_POKEBALL_H