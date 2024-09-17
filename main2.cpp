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

    std::cout << UNDERLINE << BOLD << "******* POKEMON GAME *******" << RESET << std::endl;

    Pokedex *pokedexInstance = Pokedex::getInstance();

  /*
   *   Entrée : Sélection des Pokemons
   *   combien de pokemons dans la pokeball
   */

    sleep_for(seconds(1));

    std::cout <<  BOLD << "You are having a road in Pokemon Land... " << RESET <<  std::endl;

    sleep_for(seconds(3));

    std::cout <<  BOLD << "How many pokemons do you want in your pokeball ? Give a number higher than 6" << RESET <<  std::endl;
    int nombrepoke = 0;
    std::cin >> nombrepoke;

    // TABLEAU DES POKEMONS DE TA POKEBALL

    Pokeball* pokelist = new Pokeball();     //C EST MA POKEBALL AVEC TOUS MES POKEMONS CAPTURES

    std::cout << BOLD << "You're going to chose your pokemons" << std::endl;

    // CHOIX DES POKEMONS POUR LA POKEBALL

    int state = 0;
    do {
        int aleatoire = rand() % 721 + 1;
        Pokemon *idpok2 = Pokedex::getInstance()->getOnePokemonById(aleatoire);
        //sleep_for(seconds(1));
        std::cout <<  BOLD << "You meet a wild " << idpok2->getName() << ". Do you want him ? Answer by YES, yes, Y, y" << RESET <<  std::endl;

        string answer = "";
        std::cin >> answer;

        if (answer == "YES"||answer == "yes"||answer == "y"||answer == "Y") {
            //sleep_for(seconds(1));
            pokelist->addPokemonInPokeball(idpok2);
            state++;
        }

    } while (state != nombrepoke);

    std::cout << BOLD << RED << "You have in your pokeball:" << RESET << std::endl;

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


    std::cout << BOLD << "Who do you want to send into battle?  Choose 6 Pokemons by their ID ! "  << RESET << std::endl;

    int CHOIX[6] = {0};

    int choix = 0;
    Pokeball* pokesquad = new Pokeball();            // C EST LES 6 POKEMONS QUE J ENVOIE AU COMBAT

    while (choix < 6) {
        int choixID = 0;
        if (choix==0) {
            std::cout << BOLD << "Choose a " << choix+1 << "st Pokemon" << RESET << std::endl;
        } else if (choix==1) {
            std::cout << BOLD << "Choose a " << choix+1 << "nd Pokemon" << RESET << std::endl;
        } else if (choix==2){
            std::cout << BOLD << "Choose a " << choix+1 << "rd Pokemon" << RESET << std::endl;
        } else {
            std::cout << BOLD << "Choose a " << choix+1 << "th Pokemon" << RESET << std::endl;
        }


        std::cin >> choixID;
        bool found=false;
        for(int i=0; i<6;i++) {
            if (CHOIX[i]==choixID) { found=true;}
        }

        if (!found) {
            Pokemon *poke = pokelist->takePokemonOutPokeball(choixID);
            if (poke == nullptr) {
                std::cout << RED << " No Pokemon matches this ID!! Please try again. " << RESET << std::endl;
            } else {
                pokesquad->addPokemonInPokeball(poke);
                std::cout << BLUE << poke->getName()  << " enters the battle !!" << RESET << std::endl;
                CHOIX[choix]=choixID;
                choix++;
            }
        } else {
            std::cout << RED << "This Pokemon has already been selected !!" << RESET << std::endl;

        }

    }

    // Affichage de ceux qui vont combattre

    Pokemon* pokequip = pokesquad->getFirstPokemon();
    for(int i=0; i<6; i++) {
        std::cout << BOLD << "Your Pokemon number " << i+1 <<" is : " << pokequip->getName() << RESET << std::endl;
        pokequip = pokesquad->getNextPokemon();
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

    /*
     *  ATTAQUE !!!!!
     */

    Pokemon * sonPoke = pokesquadEnemy->getFirstPokemon();
    Pokemon * monPoke = pokesquad->getFirstPokemon();


    sleep_for(seconds(3));

    std::cout << BOLD << "  " << RESET << std::endl;
    std::cout << BOLD << "At each battle, the player who starts is determined randomly:"
                         " a number is drawn between 0 and 1. If it is 0, "
                         "the player starts; if it is 1, "
                         "the computer goes first " << RESET << std::endl;

    sleep_for(seconds(10));

    int successPlayer = 0;
    string answer;

    for (int i=0;i<6;i++) {
        std::cout << UNDERLINE << WHITE << "Battle number " << i + 1 << " :" << RESET << std::endl;
        std::cout << CYAN << "My Pokemon: " << monPoke->getName() << RESET << "   ** VS **  "
                  << MAGENTA << "Its Pokemon: " << sonPoke->getName() << RESET << std::endl;
        std::cout << " " << std::endl;
        sleep_for(seconds(1));
        std::cout << BOLD << "Are you ready ? Answer by YES, yes, Y, y " << RESET << std::endl;

        std::cin >> answer;
        if (answer == "YES" || answer == "yes" || answer == "y" || answer == "Y") {

            // combat entre monPoke et sonPoke
            int beginner = rand() % 2;

            int hitPoint = 1000;

            while (hitPoint > 0) {

                if (beginner == 0) {
                    std::cout << "My Pokemon attacks first : " << std::endl;
                    sleep_for(milliseconds(500));
                    monPoke->attack(*sonPoke);
                    hitPoint = sonPoke->getHitPoint();
                    if (hitPoint <= 0) {
                        successPlayer++;
                        std::cout  << "Its Pokemon "  << MAGENTA << sonPoke->getName() << RESET << " is K.O."  << std::endl;
                        std::cout << " " << std::endl;
                    }
                } else {
                    std::cout << "Its Pokemon attacks first : " << std::endl;
                    sleep_for(milliseconds (500));
                    sonPoke->attack(*monPoke);
                    hitPoint = monPoke->getHitPoint();
                    if (hitPoint <= 0) {
                        std::cout <<  "My Pokemon " << CYAN << monPoke->getName() << RESET << " is K.O." << std::endl;
                        std::cout << " " << std::endl;
                    }
                }

                sleep_for(seconds(1));
                beginner = (beginner == 0) ? 1 : 0;

            }
            pokelist->addPokemonInPokeball(monPoke);
            monPoke = pokesquad->getNextPokemon();
            sonPoke = pokesquadEnemy->getNextPokemon();


        }

    }


    std::cout << BOLD << RED << "You have in your pokeball:" << RESET << std::endl;

    int display2 = 0;

    // Affichage de la Pokelist

    Pokemon *idpok3 = pokelist->getFirstPokemon();

    while (idpok3 != nullptr) {

        std::cout << RED << "Pokemon: " << idpok3->getName()
                  <<" | \t ID : " << idpok3->getId()
                  <<" | \t hitPoint : " << idpok3->getHitPoint()
                  <<" | \t attackValue : " << idpok3->getattackValue()
                  <<" | \t defense : " << idpok3->getdefense()
                  << RESET << std::endl;
        display2 ++;

        idpok3 = pokelist->getNextPokemon();
    }


    if (successPlayer > 3){
        std::cout << CYAN << "Yeees, I win !! " << RESET << std::endl;
    } else if (successPlayer == 3) {
        std::cout << "Equality !! " << std::endl;
    } else  {
        std::cout << MAGENTA << "Oh damn, I lost !! " << RESET << std::endl;
    }

    return 0;

}

