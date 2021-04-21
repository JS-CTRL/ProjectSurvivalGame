#include <iostream>
#include <algorithm>
#include "lands.h"
#include "player.h"

using namespace std;

enum PlayerChoice {NORTH, SOUTH, EAST, WEST};

void clearTerminal(){
    for(int i = 0; i < 5; i++){
        cout << endl;
    }
}

bool getPlayerInput(PlayerChoice &playerChoice){
    // 0 = North, 1 = South, 2 = East, 3 = West
    string input;
    cout << "Which direction will you go?" << endl;
    cout << "Enter N, S, E, or W" << endl;
    cin >> input;
    
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    
    if(input == "n"){
        playerChoice = NORTH;
    } else if(input == "s"){
        playerChoice = SOUTH;
    } else if(input == "e"){
        playerChoice = EAST;
    } else if(input == "w"){
        playerChoice = WEST;
    } else {
        cout << "Invalid input." << endl;
        return false;
    }
    
    return true;
}


int main(){
    int turns=0;
    const unsigned int MAP_SIZE = 20;
    unsigned int mapBoundry=MAP_SIZE-1;
    Player player(Player::DEFAULT_HEALTH, 
                  Player::DEFAULT_HUNGER, 
                  Player::DEFAULT_THIRST, 
                  MAP_SIZE/2, MAP_SIZE/2);
    
    //Build Map
    Land* map[MAP_SIZE][MAP_SIZE];
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            map[i][j] = getRandomLand();
        }
    }
    
    cout << "You wake up in a " << 
        map[player.getX()][player.getY()]->getShortDescription() <<
        " with no memory of how you got there." << endl;
        
    while(1){
        clearTerminal();
        player.newTurn();
         
        // Give description of surroundings
        unsigned int x = player.getX();
        unsigned int y = player.getY();
        
        cout << map[x][y]->getLongDescription() << endl << endl;
        cout << map[x][y]->visit(player) << endl << endl;
        
        cout << player.printStats() << endl << endl;
        if (player.isAlive()==0){break;}
        cout<<"Turn survival count: "<<turns<<endl<<endl<<endl;
        
        // TODO: Handle boundry conditions
        
        if (player.getY()==mapBoundry){
            cout << "To the north you see a " << map[x][0]->getShortDescription() << endl;
            }
        if (player.getY()<mapBoundry){
        cout << "To the north you see a " << map[x][y+1]->getShortDescription() << endl;
            
        }
        if (player.getY()==0){
            cout << "To the south you see a " << map[x][mapBoundry]->getShortDescription() << endl;
        }
        if (player.getY()>0){
            cout << "To the south you see a " << map[x][y-1]->getShortDescription() << endl;
        }
        
        
        
        
        if (player.getX()==mapBoundry){
            cout << "To the east you see a " << map[0][y]->getShortDescription() << endl;
            }
        if (player.getX()<mapBoundry){
        cout << "To the east you see a " << map[x + 1][y]->getShortDescription() << endl;
            
        }
        if (player.getX()==0){
            cout << "To the west you see a " << map[mapBoundry][y]->getShortDescription() << endl;
        }
        if (player.getX()>0){
            cout << "To the west you see a " << map[x - 1][y]->getShortDescription() << endl;
        }
        PlayerChoice playerChoice;
        while(!getPlayerInput(playerChoice));
        
        switch(playerChoice){
            case NORTH:
                 if (player.getY() == 19) {player.setY(0);} //Handles boundry conditions
                else {player.setY(player.getY() + 1);}
                break;
            case SOUTH:
                if (player.getY() == 0) {player.setY(19);} //Handles loop around 
                else { player.setY(player.getY() - 1);}
                break;
            case EAST:
                if (player.getX() == 19) {player.setX(0);} //Handles boundry conditions
                else {player.setX(player.getX() + 1);}
                break;
            case WEST:
                if (player.getX() == 0) {player.setX(19);} //Handles loop around 
                else { player.setX(player.getX() - 1);}
                break;
            default:
                cout << "Invalid input found: " << playerChoice << endl;
                break;
        }
        
    turns++;
   
    }
    cout<<"You dead!"<<endl;
    cout<<"Final number of turns survived: "<<turns<<endl;
    
    return 0;
}