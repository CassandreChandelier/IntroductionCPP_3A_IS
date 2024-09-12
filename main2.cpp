#include <iostream>
#include "Pokemon2.h"
#include "Pokedex2.h"
#include "Pokeball.h"

#include <vector>
#include <cstdlib>


using std::vector;

int main() {

    srand (time(NULL));

    std::cout << "******* Jeu Pokemon *******" << std::endl;

    Pokedex *pokedexInstance = Pokedex::getInstance();

    // std::cout <<"Nombre de Pokemon en memoire : " << Pokemon::getNumberOfPokemon() << std::endl;



    // combien de pokemons dans la pokeball

    std::cout << "Combien de pokemon veux-tu dans ta pokeball ?" << std::endl;
    int nombrepoke = 0;
    std::cin >> nombrepoke;

    // TABLEAU DES POKEMONS DE TA POKEBALL
    Pokemon *pokelist[nombrepoke];

    Pokemon* Pokeball::gettableau(pokelist);



    std::cout << "Tu vas choisir qui tu prends dans ta pokeball" << std::endl;

    // CHOIX DES POKEMONS POUR LA POKEBALL

    int state = 0;
    do {
        int aleatoire = rand() % 721 + 1;
        Pokemon *idpok2 = Pokedex::getInstance()->getOnePokemonById(aleatoire);
        std::cout << "Veux-tu le Pokemon : " << idpok2->getName() << " dans ta pokeball ?" << std::endl;

        string answer = "";
        std::cin >> answer;

        if (answer == "oui"||"o") {
            pokelist[state] = idpok2;
            state++;
        }

    } while (state != nombrepoke);

    std::cout << "tu as dans ta pokeball:  " << std::endl;

    int display = 0;

    while (display != nombrepoke) {
        Pokemon *idpok2 = Pokedex::getInstance()->getOnePokemonById(display);
        std::cout << "Pokemon: " << pokelist[display]->getName()
        <<" | \t ID : " << pokelist[display]->getId()
        <<" | \t hitPoint : " << pokelist[display]->getHitPoint()
        <<" | \t attackValue : " << pokelist[display]->getattackValue()
        <<" | \t defense : " << pokelist[display]->getdefense()
        << std::endl;
        display ++;
    }

    // CHOIX DES POKEMONS POUR LE COMBAT

    std::cout << "Qui veux-tu envoyer au combat ?  Choisis 6 pokemons avec leur ID ! "  << std::endl;

    int choix = 0;
    Pokemon *pokecombat[6];
    for (choix = 0; choix < 6; choix++) {
        int choixID = 0;
        std::cout << "Choisi un " << choix+1 << " ° Pokemon" << std::endl;
        std::cin >> choixID;


        pokecombat[choix] = getOnePokemonOfPokeball(choixID);

    }





    return 0;

}






    //std::cout << "Quel pokemon veux-tu ?" << std::endl;




/*
    int idpokemon(-1);
    while (idpokemon == -1) {
        std::cin >> idpokemon;
        Pokemon* idpok = Pokedex::getInstance()->getOnePokemonById(idpokemon);
        if (idpok != nullptr) {
            idpok->displayInfo();
        } else {
            std::cout << "Le Pokemon avec l'ID " << idpokemon << " n'a pas ete trouve." << std::endl;
        }

    }  */


   /* int idpokemon(0);
    Pokemon* idpok = nullptr;
    std::cin >> idpokemon;
    idpok = Pokedex::getInstance()->getOnePokemonById(idpokemon);

    if (idpok == nullptr) {
        idpokemon=idpok->getId();
        std::cout << "Le Pokemon avec le nom " << idpokemon << " n'a pas ete trouve." << std::endl;
    } else if (idpok != nullptr) {
        idpok->displayInfo();
    } */

/*
    string nompokemon("");
    Pokemon* nompok = nullptr;
    std::cin >> nompokemon;
    nompok = Pokedex::getInstance()->getOnePokemonByName(nompokemon);

    if (nompok == nullptr) {
        nompokemon=nompok->getName();
        std::cout << "Le Pokemon avec le nom " << nompokemon << " n'a pas ete trouve." << std::endl;
    } else if (nompok != nullptr) {
            nompok->displayInfo();
    }
*/



/*

    //testGet = Pokedex::getInstance()->getOnePokemonByName("Mewtwo");
   // testGet->displayInfo();

    //std::cout <<"Nombre de Pokemon en memoire : " << Pokemon::getNumberOfPokemon() << std::endl;


    // Gestion de Pokeball
    Pokeball pokeball;
    Pokemon* pikachu = pokedexInstance->getOnePokemonByName("Pikachu");
    if (pikachu != nullptr) pokeball.addPokemon(pikachu);

    std::cout << "\nPokémon dans la Pokeball : " << std::endl;
    pokeball.displayList();

    // Création d'une équipe de Pokémon (PokemonParty)
    int pokemonIndices[6] = {15, -1, -1, -1, -1, -1}; // Indices fictifs
    PokemonParty party(pokemonIndices, &pokeball);

    std::cout << "\nPokémon dans l'équipe : " << std::endl;
    party.displayParty();

    std::cout << "Nombre de Pokémon en mémoire : " << Pokemon::getNumberOfPokemon() << std::endl;

    delete testGet;  // Gestion mémoire */





