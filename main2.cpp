#include <iostream>
#include "Pokemon2.h"
#include "Pokedex2.h"
#include "Pokeball.h"

#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>

using std::vector;
using namespace std::chrono;
using namespace std::this_thread;

int main() {

    const std::string GREEN = "\033[32m";
    const std::string BLUE = "\033[34m";
    const std::string RED = "\033[31m";
    const std::string WHITE = "\033[37m";
    const std::string YELLOW = "\033[33m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";
    const std::string RESET = "\033[0m";
    const std::string BOLD = "\033[1m";
    const std::string UNDERLINE = "\033[4m";

    srand (time(NULL));

    std::cout << UNDERLINE << BOLD << "******* Jeu Pokemon *******" << RESET << std::endl;

    Pokedex *pokedexInstance = Pokedex::getInstance();


  /*
   *   Entrée : Sélection des Pokemons
   *   combien de pokemons dans la pokeball
   */

    std::cout <<  BOLD << "Combien de pokemon veux-tu dans ta pokeball ?" << RESET <<  std::endl;
    int nombrepoke = 0;
    std::cin >> nombrepoke;

    // TABLEAU DES POKEMONS DE TA POKEBALL

    Pokeball* pokelist = new Pokeball();     //C EST MA POKEBALL AVEC TOUS MES POKEMONS CAPTURES

    std::cout << BOLD << "Tu vas choisir qui tu prends dans ta pokeball" << std::endl;

    // CHOIX DES POKEMONS POUR LA POKEBALL

    int state = 0;
    do {
        int aleatoire = rand() % 721 + 1;
        Pokemon *idpok2 = Pokedex::getInstance()->getOnePokemonById(aleatoire);
        sleep_for(seconds(1));
        std::cout <<  BOLD << "Veux-tu le Pokemon : " << idpok2->getName() << " dans ta pokeball ?" << RESET <<  std::endl;

        string answer = "";
        std::cin >> answer;

        if (answer == "oui"||answer == "o") {
            sleep_for(seconds(1));
            pokelist->addPokemonInPokeball(idpok2);
            state++;
        }

    } while (state != nombrepoke);

    std::cout << BOLD << RED << "tu as dans ta pokeball:  " << RESET << std::endl;

    int display = 0;

    // Affichage de la Pokelist

    Pokemon *idpok2 = pokelist->getFirstPokemon();

    while (idpok2 != nullptr) {

        std::cout << RED << "Pokemon: " << idpok2->getName()
                  <<" | \t ID : " << idpok2->getId()
                  <<" | \t hitPoint : " << idpok2->getHitPoint()
                  <<" | \t attackValue : " << idpok2->getattackValue()
                  <<" | \t defense : " << idpok2->getdefense()
                << RESET << std::endl;
        display ++;

        idpok2 = pokelist->getNextPokemon();
    }


    /*
     *   CHOIX DES POKEMONS POUR LE COMBAT
     */


    std::cout << BOLD << "Qui veux-tu envoyer au combat ?  Choisis 6 pokemons avec leur ID ! "  << RESET << std::endl;

    int choix = 0;
    Pokeball* pokesquad = new Pokeball();            // C EST LES 6 POKEMONS QUE J ENVOIE AU COMBAT


    while (choix < 6) {
        int choixID = 0;
        if (choix==0) {
            std::cout << BOLD << "Choisi un " << choix+1 << "er Pokemon" << std::endl;

        } else {
            std::cout << "Choisi un " << choix+1 << "eme Pokemon"  << std::endl;

        }
        std::cin >> choixID;
        Pokemon* poke = pokelist->getOnePokemonById(choixID);
        if (poke== nullptr) {
            std::cout << "Aucun pokemon ne correspond a cet indice!!? recommencez " << RESET << std::endl;
        } else {
            pokesquad->addPokemonInPokeball(poke);
            std::cout << poke->getName() << "  rentre en jeu !!" <<  std::endl;
            choix++;
        }

    }

    // Affichage de ceux qui vont combattre

    Pokemon* pokequip = pokesquad->getFirstPokemon();
    for(int i=0; i<6; i++) {
        std::cout << "Votre pokemon numero " << i <<" est : " << pokequip->getName() <<std::endl;
        pokesquad->getNextPokemon();
    }

    /*
     *
     *   ADVERSAIRE
     *
     * CREATION DE L'EQUIPE ADVERSE
     *
     *
     */

    Pokeball* pokesquadEnemy = new Pokeball();           // C EST L EQUIPE ADVERSE (6 POKEMONS)

    // On choisit 6 Pokemons aléatoirement pour sa pokeball

    int stateEnemy = 0;
    do {
        int aleatoire = rand() % 721 + 1;
        Pokemon *idpok2 = Pokedex::getInstance()->getOnePokemonById(aleatoire);

        pokesquadEnemy->addPokemonInPokeball(idpok2);
        stateEnemy++;

    } while (stateEnemy < 6);

    // Affichage de sa liste de combattants

   /* Pokemon * poke = pokesquadEnemy->getFirstPokemon();
    int comptage = 0;
    while (comptage<6) {
        comptage++;
        poke = pokesquadEnemy->getNextPokemon();
    }
*/
    /*
     *  ATTAQUE !!!!!
     */

    Pokemon * sonPoke = pokesquadEnemy->getFirstPokemon();
    Pokemon * monPoke = pokesquad->getFirstPokemon();


    std::cout << "A chaque round, le joueur qui "
                 "commence est determine aleatoirement : "
                 "un nombre est tire entre 0 et 1. "
                 "Si c'est 0, le joueur commence, "
                 "si c'est 1, l'ordinateur prend la main. " << std::endl;

    int successPlayer = 0;

    for (int i=0;i<6;i++){
        std::cout<< UNDERLINE<<WHITE<< "Combat nr " << i+1 << " :" << RESET << std::endl;
        std::cout<< " Votre Pokemon: " << monPoke->getName() <<
                    "   ** VS **   " << sonPoke->getName() << std::endl;


        // combat entre monPoke et sonPoke
        int beginner = rand() % 2;

        int hitPoint = 1000;

        while (hitPoint > 0 ) {

            if (beginner == 0) {
                std::cout << "Mon pokemon attaque en premier : " << std::endl;
                monPoke->attack(*sonPoke);
                hitPoint = sonPoke->getHitPoint();
                if (hitPoint <=0) {
                    successPlayer++;
                    std::cout << "Son pokemon " << sonPoke->getName() <<  " est mort" << std::endl;
                }
            } else {
                std::cout << "Son pokemon attaque en premier : " << std::endl;
                sonPoke->attack(*monPoke);
                hitPoint = monPoke->getHitPoint();
                if (hitPoint <=0) {
                    std::cout << "Mon pokemon " << monPoke->getName() <<  " est mort" << std::endl;
                }
            }
            sleep_for(seconds(1));
            beginner = (beginner==0)? 1:0;

        }
        monPoke = pokesquad->getNextPokemon();
        sonPoke = pokesquadEnemy->getNextPokemon();


    }

    if (successPlayer > 3){
        std::cout << "J'ai gagne !! " << std::endl;
    } else if (successPlayer == 3) {
        std::cout << "Egalite !! " << std::endl;
    } else  {
        std::cout << "J'ai perdu !! " << std::endl;
    }






    return 0;

}




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





