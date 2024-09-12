

#ifndef POKEMONIS_SETOFPOKEMON_H
#define POKEMONIS_SETOFPOKEMON_H

#include <vector>
#include "Pokemon2.h"

class SetOfPokemon {
protected :
    std::vector<Pokemon *> arrayOfPokemon;
    int findPositionInArrayByName(string name);
    int findPositionInArrayById(int id);
public :
    virtual Pokemon* getOnePokemonByName(string name)=0;
    virtual Pokemon* getOnePokemonById(int id)=0;
    void displayList() const;
    SetOfPokemon();

   virtual ~SetOfPokemon();
};


#endif //POKEMONIS_SETOFPOKEMON_H
