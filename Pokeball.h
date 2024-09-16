

#ifndef UNTITLED2_POKEBALL_H
#define UNTITLED2_POKEBALL_H

#include "SetOfPokemon2.h"


class Pokeball : public SetOfPokemon {

private:

    int NextPoke =0;

public:
    int number;
    Pokeball();
    void addPokemonInPokeball(Pokemon* pokemon);
    void DeletePokemonFromPokeball(Pokemon* pokemon);
    void DeletePokemonFromPokeballByName(string name);
    void DeletePokemonFromPokeballById(int id) ;
    Pokemon* takePokemonOutPokeball(string name);
    Pokemon* takePokemonOutPokeball(int id);
    Pokemon* getOnePokemonByName(string name) override;
    Pokemon* getOnePokemonById(int id) override;
    Pokemon* getFirstPokemon();
    Pokemon* getNextPokemon();


    ~Pokeball();

};

#endif //UNTITLED2_POKEBALL_H