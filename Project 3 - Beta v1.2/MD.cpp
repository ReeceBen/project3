//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class

//pseudo code:

/*

main driver:
    loops through the play fucnion while the player is still playing,
     becuase if they die they can be prompted to play again


//play functions gets the user playing
play()

    ////    before we start the game update loop, get the player set up     ////
    //like idk set players health to zero n shit


    ////    "game update loop"    ////
    //while our player is still playing, continue updating the game and looping through
    //each turn is 1 time going through this loop
    while loop{


        ////first display current stats and things

        ////second get the players response for the current turn they are on
        
        ////if they wanted to use an item or they're fighting a zombie or something similar then 
        //// have some kind of while loop going and call a funcion that gets input and just
        ////  has it so they are using an item


        ////call some kind of updateAllThings() funcion that updates everything going on
        ////like, it'll move the zombies and 


        ////like.. if(player.getDead?() == 1){ }
        ////    if they died then break the loops below:

        //if player dies.....
        
        //stop the loop with them playing the round
        
        //then ask if they want to play again
        
        
        

        //this is what we will return to our main funcion where this function was called
        //if they say they want to play again, then this variable will get returned, causing this fucnion to restart

*/




#include <iostream>
#include <cstring>
#include <fstream>
#include "Player.h"
#include "Map.h"

using namespace std;


bool play();
vector<Zombie> createZombiesVec();

void displayCurrentStatsAndThings();
bool checkForZombieOnPlayer();
Zombie findZombieOnPlayer();
void displayBasicMenu();
Map playerMoveMenu();
//void playerCheckInventoryMenu();


vector<Zombie> moveAllZombies();



//This fuction creates a vector of Zombies
//Its where all our zombies will be stored for each round
//each turn the zombies vector will be updated, and we will have each zombie move
vector<Zombie> createZombiesVec(int numZombiesToSpawn){
    vector<Zombie> zombiesVec;


    for(int i = 0; i < numZombiesToSpawn; i++){

        //we will add in a zombie with random stats
        Zombie randoZomb;
        randoZomb.setAllStatsRandom();

        zombiesVec.push_back(randoZomb);
    }

    return zombiesVec;

}


//this is what is displayed at the beginning of each turn
//Just some stats and things to keep the player updated
void displayCurrentStatsAndThings(Map mainGameMap, Player currentPlayer, int turns){
    cout << endl;
    cout << endl;
    cout << "Player Stats: " << endl;
    cout << "Player: " << currentPlayer.getPlayerName() << endl;
    cout << "Turn Number: " << turns << endl;
    cout << "Health: " << currentPlayer.getPlayerHealth() << endl;
    cout << "Stamina: " << currentPlayer.getPlayerStamina() << endl;
    cout << "Inventory Size: " << currentPlayer.getPlayerInventorySize() << endl;
    cout << "Number of Weapons: " << currentPlayer.getPlayerWeaponNum() << endl;
    cout << "Number of Keys: " << currentPlayer.getPlayerKeyCount() << endl;
    cout << "X: " << mainGameMap.getPlayerX() << " Y: " << mainGameMap.getPlayerY() << endl;
}

//This returns a value of 1 (true) if a zombie and a player are on the same coordinates
bool checkForZombieOnPlayer(vector<Zombie> zombiesVec, Map currentMap){

    //Return value
    bool rV = 0;

    //These varibales we will just temporarily set to values for the zombie that we are checking
    int zX = 0;
    int zY = 0;

    //these variables are just to make it easy to compare to the players X and Y
    int pX = currentMap.getPlayerX();
    int pY = currentMap.getPlayerY();

    for(int i = 0; i < zombiesVec.size(); i++){
        zX = zombiesVec.at(i).getX();
        zY = zombiesVec.at(i).getY();

        if(zX == pX && zY == pY){
            //cout << "we found a zombie on the player at: ";
            //cout << "X = " << zX << " Y = " << zY << endl;

            rV = 1;
        }
    }

    return rV;
}



Zombie findZombieOnPlayer(Map currentMap, vector<Zombie> zombiesVec){
    //this is the zombie we find on the player that we will return
    Zombie returnZombie;

    //these varibales we will just temporarily set to values for the zombie
    //that we are checking
    int zX = 0;
    int zY = 0;

    //these variables are just to make it easy to compare to the players X and Y
    int pX = currentMap.getPlayerX();
    int pY = currentMap.getPlayerY();

    for(int i = 0; i < zombiesVec.size(); i++){
        zX = zombiesVec.at(i).getX();
        zY = zombiesVec.at(i).getY();

        if(zX == pX && zY == pY){
            //cout << "we found a zombie on the player at: ";
            //cout << "X = " << zX << " Y = " << zY << endl;

            returnZombie = zombiesVec.at(i);
        }
    }

    return returnZombie;
}

//this is just a starting menu with things like...
//attack, move, use item, etc...
void displayBasicMenu(){

    //the requirements reads: "at least 5 manu options" 
    //cout << "whis is this causing an error?!?!?!" << endl;
    //cout << "Options: " << end;
    
    
    cout << "Options: " << endl;
    cout << "1: Move" << endl;
    cout << "2: Check Inventory" << endl;
    cout << "3: Check Weapons" << endl;
    cout << "4: Search for Items" << endl;
    cout << "5: SOME OTHER OPTION, MAYBE CHECK X AND Y? MAYBE DISPLAY SCOREBOARD OF PAST PLAYERS?" << endl;
    cout << "6: Quit" << endl;
}


//asks the player which direction they'd like to move in
//prompts them with a move menu
//returns an updated map with the players new X and Y 
Map playerMoveMenu(Map currentMap, Player currentPlayer){
    
    //this is what we'll return, its the map but updated with the new x and y positions
    Map updatedMap = currentMap;

    //this is where we will store the move direction the player selects

    //MAKE A WHILE LOOP MAKING SURE THEY DONT GO  THORUGH A WALL



    //this is where will save the users move direction input
    int moveDirection = 0;

    //this is to break / continue the while loop which checks for a valid move direction
    bool validDirection = 0;

    while(validDirection == 0){
        moveDirection = currentPlayer.displayPlayerMoveMenu();
        //1: up
        //2: down
        //3: left
        //4: right
        
        //depending on which  direction they chose, change the players X or Y coords
        //this set of if else statemtns also checks to see if their move direction was valid, ex invalid: 6
        //not only that, it checks to make sure they don't move through a wall/edge of the map
        if(moveDirection == 1){

            //up
            if(currentMap.getPlayerY() <= 0){
                cout << "You can't cross the edge of the map! Pick a different move direction." << endl;
            }else{
                validDirection = 1;
                updatedMap.setPlayerY(currentMap.getPlayerY() - 1);
            }
            
            
        }else if(moveDirection == 2){

            //down
            if(currentMap.getPlayerY() >= 14){
                cout << "You can't cross the edge of the map! Pick a different move direction." << endl;
            }else{
                validDirection = 1;
                updatedMap.setPlayerY(currentMap.getPlayerY() + 1);
            }

        }else if(moveDirection == 3){

            //left
            if(currentMap.getPlayerX() <= 0){
                cout << "You can't cross the edge of the map! Pick a different move direction." << endl;
            }else{
                validDirection = 1;
                updatedMap.setPlayerX(currentMap.getPlayerX() - 1);
            }

        }else if(moveDirection == 4){

            //right
            if(currentMap.getPlayerX() >= 26){
                cout << "You can't cross the edge of the map! Pick a different move direction." << endl;
            }else{
                validDirection = 1;
                updatedMap.setPlayerX(currentMap.getPlayerX() + 1);
            }

        }
    
    }


    

    


    return updatedMap;
}





vector<Zombie> moveAllZombies(vector<Zombie> ZZZ){
    for(int i = 0; i < ZZZ.size(); i++){
        ZZZ.at(i).moveRandomly();
    }

    return ZZZ;
}




//play functions gets the user playing
bool play(){



    //each turn will be counted here as a turn
    int turns = 0;

    //this is used to indicate if we should continue updating the game
    //if they die or win this will become a zero and break the "game update loop"
    bool stillPlayingRound = 1;

    //this is used to check if a response is valid
    //we will assign its value to true to break a while loop
    //then we will assign it to false again so we can immediatly re use it
    bool validResponse = 0;


    //this is what we will return to our main funcion where this function was called
    //if they say they want to play again, then this variable will get returned, causing this fucnion to restart
    bool wantToPlayAgain = 1;

    //if the player dies this will trigger a series of things that end the round
    bool playerDead = 0;

    //when we want some input from the player, we might want to use this for a response
    string response = " ";

    //this is to check if the player has won the game
    //if the player has won, slightly different things will occur at the very end
    bool playerHasWon = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////


    ////    before we start the game update loop, get the player set up     ////
    //like idk set players health to zero n shit
    //we'll also set up some other things, like spawning some zombies all over the map

    //create a new map to use for the game
    Map currentMap;

    //for testing purpouses:
    //lets give the player a specific location
    currentMap.setPlayerX(0);
    currentMap.setPlayerY(0);
    
    //make our player
    //later we can add the feature to enter your name and maybe select players with specialized stats or something
    Player currentPlayer;
    currentPlayer.setPlayerName("Jimmy");

    //lets make a vector of zombies, and spawn em all over the map
    //the int entered in is how many zombies we want to spawn
    vector<Zombie> zombiesVec = createZombiesVec(20);


    ////    "game update loop"    ////
    //while our player is still playing, continue updating the game and looping through
    //each turn is 1 time going through this loop
    while(stillPlayingRound == 1){
        
        //before we do anything, print out some lines to make it clear where tha last turn ended
        // and where this new turn begind
        cout << endl;
        cout << "///////////////////////////////////END OF TURN////////////////////////////////////////" << endl;
        cout << endl;
        

        
        //before anthing else, add 1 to the turn count
        turns++;

        ////first display current stats and things like the map
        //add more inputs to this function to display more things
        currentMap.displayMap();
        //^idk why the display map i being buggy when i pass it into the function so we'll just call it here
        displayCurrentStatsAndThings(currentMap, currentPlayer, turns);

        cout << endl;
        



        //this sees if a zombie and the player are on the same space
        //if they are it will initiate a battle sequence
        bool battleTime = checkForZombieOnPlayer(zombiesVec, currentMap);

        //now, if we found a zombie on the player, its battle time
        if(battleTime == 1){
            cout << "Oh no!" << endl;
            //cout << "Its battle time..." << endl;
            //we need to find the zombie that's on the player
            //and we need to pass that zombie into the Player.battle function to initiate a battle!
            Zombie zombieOnPlayer = findZombieOnPlayer(currentMap, zombiesVec);
            currentPlayer.battle(zombieOnPlayer);

        }











        ////second get the players response for the current turn they are on
        //have an ask for input function that prints a list of options
        //dependign on the option, print / update different things and stuff
        
        //lets display a menu of things for them to choose from
        //this will be like... move, attack, use item, etc.
        displayBasicMenu();

        //this loop does 2 jobs
        // it (1) checks to make sure the players response is valid
        // and (2) it will call functions and activate menus depending on the player response
                //ex: we call check weapons, then it calls the "check weapons menu" fucniton, 
                // which will display  more things etc...
        while(validResponse == 0){
            cin >> response;
            if(response == "1"){
                //move

                //OFFICIALLY DONE!
                //cout << "the player wants to move" << endl;
                currentMap = playerMoveMenu(currentMap, currentPlayer);
                validResponse = 1;

            }else if(response == "2"){
                //check inventory

                //POTENTIALLY SOME TESTING, BUT IF IT WAS DONE IN THE PLAYER CLASS, THIS IS DONE
                //cout << "the player wants to check their inventory" << endl;
                //playerCheckInventoryMenu(currentPlayer);
                currentPlayer.checkPlayerInventory();
                validResponse = 1;

            }else if(response == "3"){
                //check weapons

                //HOLY SHIT, SAME AS ABOVE^ REECE DEPENDING ON THE TESTING YOU DID THIS ONE IS DONE
                //cout << "the player wants to check their weapons" << endl;
                currentPlayer.checkPlayerWeapons();
                validResponse = 1;

            }else if(response == "4"){
                //search for item

                currentPlayer.pickUpItem();
                validResponse = 1;

            }else if(response == "5"){

                cout << "PUT SOMETHING IN HERE" << endl;
                validResponse = 1;

            }else if(response == "6"){

                cout << "Quitting game" << endl;
                playerDead = 1;
                validResponse = 1;
                //tell a message saying its going to save their game with number of moves
                // and they they didn't win

            }else{
                cout << "invalid response, please enter a number 1-6" << endl;
            }
        }

        //now reset valid response
        validResponse = 0;
        







        ////call some kind of updateAllThings() funcion that updates everything going on
        //actually, we might just need to update the zombies vec
        zombiesVec = moveAllZombies(zombiesVec);

        
        //this is usefull for testing:
        //this prints out the current zombie locations
        /*
        for(int w = 0; w < zombiesVec.size(); w++){
            cout << "ZX: " << zombiesVec.at(w).getX();
            cout << " ZY: " << zombiesVec.at(w).getY() << endl;
        }
        */
        






        //// things related to the game ending below ////





        //we need to check if the player has won the game
        if(currentPlayer.getPlayerKeyCount() >= 3){
            playerHasWon = 1;
        }

        //if the players health is zero or less, then they've died, so make the player dead variable a 1
        if(currentPlayer.getPlayerHealth() <= 0){
            playerDead = 1;
        }

        ////the below if statemnts n shit check to see if they payer has died, and if the player has won
        //everything below is jsut some concluding stuff to end the game
        if(playerDead == 1 || playerHasWon == 1){
            
            
            if(playerDead == 1){
                //if player dies.....
                cout << "You died lmao" << endl;
                cout << "Since you didn't win, your name and score will not be recorded in the Score Board" << endl;
                cout << "Try again to get your name in the leader boards!" << endl;
            }else{
                //else, they won!!!!!!!
                cout << "Congradulations! You won!!" << endl;
                //now that they've died, lets record their name in the scoreBoard.txt file
                //if you wanna see how that' done, check out the function below

                //lastly, since they won, automatily display the leaderboards sorted
                //def make this a function
                
            }
            



            








            //stop the loop with them playing the round
            stillPlayingRound = 0;
            //then ask if they want to play again
            string playerResponse = " ";

            bool validResponse2 = 0;

            while(validResponse2 == 0){
                cout << "you wanna keep playing? 1 = yes, 0 = no" << endl;
                cin >> playerResponse;

                if(playerResponse == "1" || playerResponse == "0"){
                    validResponse2 = 1;
                }
            }
            
            
            //quick lil while loop to check if they entered in a 1 or 0
            

            if(playerResponse == "1"){
                //this is what we will return to our main funcion where this function was called
                //if they say they want to play again, then this variable will get returned, causing this fucnion to restart
                wantToPlayAgain = 1;
                cout << endl;
                cout << "-----------------------------" << endl;
                cout << endl;
                cout << "CREATING NEW GAME...." << endl;
                cout << endl;
                cout << "-----------------------------" << endl;
                cout << endl;
            }else{
                wantToPlayAgain = 0;

                cout << endl;
                cout << "-----------------------------" << endl;
                cout << endl;
                cout << "TURNING OFF GAME DRIVER..." << endl;
                cout << endl;
                cout << "-----------------------------" << endl;
                cout << endl;
            }
        }

        



        
    

        
    }

    //this is what we will return to our main funcion where this function was called
    //if they say they want to play again, then this variable will get returned, causing this fucnion to restart
    return wantToPlayAgain;
}






int main(){

    bool stillPlaying = 1;

    while(stillPlaying == 1){
        //we should display a quick lil menu thing on how to play
        stillPlaying = play();
        
    }
    return 0;
}

//CURRENT UPDATE:

//Changed the include statements to not have the .cpp files just because the TA in recitation told us it was bad practice and you could easily define objects too many times. 
//So only the header files are included now, 
//When you compile type in the console:"g++ -std=c++11 MD.cpp Player.cpp Map.cpp Zombie.cpp Item.cpp Weapon.cpp" and it should compile perfectly.


/*
Anywheres Chances I made with this round of working were:
* Made it so the chance to get a key goes up slightly every time the player gets a key, since it starts off as a rare chance.
    Did this primarily so the game isn't too long
* I changed the amount of zombies spawning from 15 to 20 because I did a test run and in 63 turns I won and didn't run into a single zombie. I'd rather there be too many than too little zombies
* Also fixed a bug causing a segmentation fault in my inventory array
* Changed a few of your comments to look more presentable for when we upload, 
    but I didn't change many so you can feel free to change the rest of yours to look more presentable to the TAs, 
    I still need to add comments to the CPP files I made but I'll do that around when we're 100% finished
*Made some minor touch ups to the stats displayed every turn, mainly so they look more symetrical and also added the words end of turn at the bar that is displayed

Bugs that still need patching:
*Player run option is not working, battle still keeps happening even after using the run option
*When the player health hits negative values during battle, the fight keeps happening, this needs to not happen, instead the fight and the game should end immediately.
*Even with 20 zombies, it still feels light fights are rare, are all of them moving?
*Reloading gun doesn't always work for some reason
*/