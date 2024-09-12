

#ifndef POKEMONIS_POKEDEX_H
#define POKEMONIS_POKEDEX_H

#include "SetOfPokemon2.h"

class Pokedex : public SetOfPokemon{
private :
    Pokedex(string name);
    static Pokedex * instance;

public:
    static Pokedex * getInstance();
    Pokemon* getOnePokemonByName(string name) override;
    Pokemon* getOnePokemonById(int id) override;
    ~Pokedex();
};


#endif //POKEMONIS_POKEDEX_H
