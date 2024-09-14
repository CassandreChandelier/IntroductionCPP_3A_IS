
#include "Pokemon2.h"

#include <iostream>

int Pokemon::numberOfPokemon=0;

Pokemon::Pokemon(const string name, int id, double hitPoint, double attack, double defense, int generation) : name(
        name), id(id), hitPoint(hitPoint), attackValue(attack), defense(defense), generation(generation) {
  //  std::cout << "Ici le constructeur de " << name << std::endl;
    numberOfPokemon++;
}

Pokemon::Pokemon(const Pokemon& anotherPokemon) : name(anotherPokemon.name),id(anotherPokemon.id),
        hitPoint(anotherPokemon.hitPoint), attackValue(anotherPokemon.attackValue), defense(anotherPokemon.defense),
        generation(anotherPokemon.generation){
    // std::cout<<"Recopie de " << name <<std::endl;
    numberOfPokemon++;
}

Pokemon::Pokemon(const string name) : name(name){
    numberOfPokemon++;
}

void Pokemon::scream(){
    std::cout<<"Grrr ! I'm " << name << std::endl;
}

void Pokemon::displayInfo() const{
    std::cout << "*** Pokemon #" << id << " : " << name << ", hitPoint : "
    << hitPoint << std::endl;
}

Pokemon::~Pokemon() {
    //std::cout << "Ici le destructeur" << std::endl;
    numberOfPokemon--;
}

void Pokemon::attack(Pokemon &anotherPokemon) {
    if (this->attackValue > anotherPokemon.defense){
        anotherPokemon.sustainDamage(this->attackValue-anotherPokemon.defense);
    }
    else{
        std::cout << "Attack missed ! " << std::endl;
    }
}

int Pokemon::getNumberOfPokemon() {
    return numberOfPokemon;
}

void Pokemon::sustainDamage(int value) {
    hitPoint=(hitPoint-value)>0?hitPoint-value:0;
    std::cout << "Pokemon " << name << " sustained a " << value <<
    " damage. New hitPoint : " << hitPoint << std::endl;
}

const string &Pokemon::getName() {
    return name;
}

double Pokemon::getHitPoint() {
    return hitPoint;
}

double Pokemon::getattackValue(){
    return attackValue;
}

double Pokemon::getdefense(){
    return defense;

}

int Pokemon::getGeneration(){
    return generation;
}

int Pokemon::getId() const {
    return id;
}
