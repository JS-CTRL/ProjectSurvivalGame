#include "lands.h"

using namespace std;

Land* getRandomLand(){
    LandTypes selection = (LandTypes)(rand() % MAX_NUM_LANDS);
    
    switch(selection){
        case LAKE:
            return new Lake;
            break;
        case FOREST:
            return new Forest;
            break;
        case DESERT:
            return new Desert;
            break;
        case SWAMP:
            return new Swamp;
            break;
        case FIELD:
            return new Field;
            break;
        case CANYON:
            return new Canyon;
            break;
        case MOUNTAIN:
            return new Mountain;
            break;
        case TOWN:
            return new Town;
            break;
        default:
            return new Lake;
            break;
    }
    
}

//Lake
//=====================================================================================
string Lake::getShortDescription(){
    return "lake";
}

string Lake::getLongDescription(){
    return "You arrive at a large lake filled with clear sparkling water.";
}

string Lake::visit(Player& p){
    string description = "You drink from the lake, replenishing your thirst";
    p.setThirst(Player::DEFAULT_THIRST);
    return description;
}
//=====================================================================================



//Forest
//=====================================================================================
string Forest::getShortDescription(){
    
    return "forest";
}

string Forest::getLongDescription(){
    return "You arrive in dense forest filled with trees and foliage.";
}

string Forest::visit(Player& p){
    string description = "You forage for berries but find nothing.";
    
    int chance = rand() % 100;
    
    // Chance to find berries
    if(chance > 50){
        description = "You foraged for berries in the forest and found some!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    // Chance to get mauled by bear
    if(chance < 10 && chance > 5){
        description = "You are attacked by a hungry bear in the woods!";
        p.setHealth(p.getHealth() - 1);
    }
    
    // Chance to get double mauled
    if(chance < 5){
        description = "You are attacked by two very large bears!";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }
    
    
    return description;
}
//=====================================================================================


//Desert
//=====================================================================================
string Desert::getShortDescription(){
    
    return "desert";
}

string Desert::getLongDescription(){
    return "You arrive in a extremely hot, dry desert";
}

string Desert::visit(Player& p){
    string description = "The heat of the desert makes you dehydrated.";
    if (p.getThirst()>0){
    p.setThirst(p.getThirst() - 1);
    }

    return description;
}
//=====================================================================================



//Swamp
//=====================================================================================
string Swamp::getShortDescription(){
    return "swamp";
}

string Swamp::getLongDescription(){
    return "You arrive in muggy swamp full of slithering creatures, and begin searching for resources.";
}

string Swamp::visit(Player& p){
    string description = "";
    
    int chance = rand() % 100;
    
    // Chance to find berries
    if(chance > 40){
        description = "You find tasty swamp slugs";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    // Chance to get mauled by bear
    if(chance < 40 && chance > 5){
        description = "You find no resources";
    }
    
    // Chance to get double mauled
    if(chance < 5){
        description = "You are attacked by an alligator!";
        int newHealth = (int)p.getHealth() - 1;
        p.setHealth(p.getHealth() - 1);
    }
    
    return description;
}
//=====================================================================================


//Field
//=====================================================================================
string Field::getShortDescription(){
    return "field";
}

string Field::getLongDescription(){
    return "You arrive at a large field filled with pretty flowers, and begin searching for resources.";
}

string Field::visit(Player& p){
    int chance = rand() % 100;
    string description = "";
    // Reward
    if(chance > 40){
        description = "You find a rabit and eat it";
        p.setHunger(p.getHunger() + 1);
        return description;
        
    }
    
    // Nothing
    if(chance < 40 && chance > 5){
        description = "You find no resources";
        return description;
    }
    
    // Risk
    if(chance < 5){
        description = "You are attacked by a fox!";
        int newHealth = (int)p.getHealth() - 1;
        p.setHealth(p.getHealth() - 1);
        return description;
    }
}
//=====================================================================================


//Canyon
//=====================================================================================
string Canyon::getShortDescription(){
    return "canyon";
}

string Canyon::getLongDescription(){
    return "You arrive at a large canyon with steep cliffs, and begin searching for resources.";
}

string Canyon::visit(Player& p){
    int chance = rand() % 100;
    string description = "";
    // Reward
    if(chance > 40){
        description = "You find nothing";

        return description;
        
    }
    
    // Nothing
    if(chance < 40 && chance > 5){
        description = "You find a survival pack that a traveler must have dropped, it contains a first aid kit";
        p.setHealth(p.getHealth() + 1);
        return description;
    }
    
    // Risk
}
//=====================================================================================


//Mountain
//=====================================================================================
string Mountain::getShortDescription(){
    return "mountain";
}

string Mountain::getLongDescription(){
    return "You arrive at a large mountain that is so tall you cannot even see the peak, you begin searching for resources.";
}

string Mountain::visit(Player& p){
     int chance = rand() % 100;
    string description = "";
    // Reward
    if(chance > 40){
        description = "You search but find only amazing scenery..at least you feed your soul";
        return description;
        
    }
    
    // Nothing
    if(chance < 40 && chance > 5){
        description = "You stumble and fall down the mountain hitting many rocks on the way down";
        p.setHealth(p.getHealth() - 1);
        return description;
    }
    
    // Risk
    if(chance < 5){
        description = "You find some medicinal berries";

        p.setHealth(p.getHealth() + 1);
        return description;
    }
}
//=====================================================================================


//Town
//=====================================================================================
string Town::getShortDescription(){
    return "town";
}

string Town::getLongDescription(){
    return "You arrive at a small abandoned town, and begin searching for resources.";
}

string Town::visit(Player& p){
    int chance = rand() % 100;
    string description = "";
    // Reward
    if(chance > 40){
        description = "You find canned food and bottled water!";
        p.setHunger(p.getHunger() + 1);
        p.setThirst(p.getThirst() + 1);
        return description;
        
    }
    
    // Nothing
    if(chance < 40 && chance > 5){
        description = "You find no resources";
        return description;
    }
    
    // Risk
    if(chance < 5){
        description = "You are attacked by a crazed villager with a knife!";
        p.setHealth(p.getHealth() - 1);
        return description;
    }
    
}
//=====================================================================================