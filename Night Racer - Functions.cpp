/*
Author: Max Edward
Email : maxedwar@uat.edu
Assignment Name : Interactive Simulation & Functions - Night Racer
*/

// Night Racer
// A personalized racing game

// Include libraries & header files
#include <iostream>
#include <string>

// Namespace Block
using namespace std;

// Variable Block

// Variables for player setup
string racer;
string rival;

// Variables for user input
string start = "";
string restart = "";
string trashCan = "";
string crowdStreet = "";
string bridgeCollapse = "";

// Variable for "speed up" section
string speedUp = "";
string currSpeedUp = speedUp;

// Variables for endings
string winChoice = "";
string lostChoice = "";

// Function Block

// Function for "speed" measurement
int currSpeed(int x) {
    int speed = 100 + x;
    return speed;
}

// Void functions for text readout
void opening() {
    cout << "\n------------------------------------\n\n";
    cout << "Welcome to Night Racer by Max Edward\n\n";
    cout << "The game will change depending on your choices.\n";
    cout << "You will start at 100% speed. Depending on the actions you make, you will either speed up or lose speed.\n";
    cout << "Have fun and good luck!\n\n";
    cout << "------------------------------------";
}

void raceStart() {
    cout << "\nWelcome all to tonights race!\n";
    cout << "We have some tough challengers tonight, so lets not waste any time!\n";
    cout << "On the left, we have " << racer << ", the all time Night City champion! And on the right we have " << rival << ", who seeks to be the new champ!\n";
    cout << "Tonights race will put each racer's skills to the test. Both racers will compete head-to-head in a race from the South end of Night City to the North end of the city.\n";
    cout << "Without further ado, lets make some noise and get racing!\n\n";
}

void trashCanScene() {
    cout << "\nAfter some time racing through downtown Night City, you catch back up with " << rival << ".\n";
    cout << "But as soon as you are neck-and-neck with " << rival << ", they drive through some trash cans knocking them all into your path.\n";
    cout << "You see a shortcut down an alley, but its risky as you cannot see where it will take you.\n";
    cout << "\nDo you take the shortcut and try and speed up, or do you drive straight through the trash cans?\n";
}

void crowdStreetScene() {
    cout << "\nEntering uptown Night City, it seems to be busier than expected. " << rival << " takes a sharp right and turns down an alley way to get around all of the street vendors.\n";
    cout << "You, however, do not see any other alley ways to drive down and have two options to move forward, but make them quick as you are falling behind!\n";
    cout << "\nYou can either drive through the crowded streets and hope to make it out without crashing, or you can take the highway and hope it doesn't lead you astray. Which do you choose?\n";
}

void brokenBridgeScene() {
    cout << "\nYou are nearing the North end of Night City - and with that, the finish line.\n";
    cout << "You see " << rival << " take the only bridge that goes from uptown Night City to the North end.\n";
    cout << "As you race up behind them, the bridge cables snap and you slam on your brakes to avoid driving into the river below.\n";
    cout << "As you watch " << rival << " drive off, nearing closer to the finish line every second, you feel as if all hope is lost.\n\n";
    cout << "Just as you put your car into reverse and begin to drive back to the South end, you see a ramp pointing towards the other side of the river.\n";
    cout << "It looks like your only chance to make it to the North end is to jump the river using this ramp.\n";
    cout << "You need to make a decision now or you won't have enough time to make up all of your lost speed.\n";
    cout << "\nDo you decide to take the ramp and risk everything to keep your title as Champion, or do you give up now and drive back home, forfeiting your title as Champion Racer of Night City?\n";
}

void ramp() {
    cout << "\nYou turn your car towards the ramp. Crossing your fingers that you'll make it. You put your foot on the gas and gun it towards the ramp.\n";
    cout << "As your car drives up and off the ramp, you feel weightless as you and your car soar through the air.\n";
    cout << "You feel your stomach churn as your car falls to the ground. As if it was by fate, your car hits the sand on the bank of the river.\n";
    cout << "You made it across the river in one piece! You waste no time celebrating and continue speeding onto the street towards the finish line.\n";
    cout << "The jump across the river gave you a big boost in speed! You now have " << currSpeed(50) << "% speed!\n";
}

// Prototype for playGame() function
string playGame();

// Functions for winning and losing endings.
string endingWin() {
    cout << "\nWith enough speed, you passed " << rival << " and made it through the finish line first! You kept your title as Champion Racer of Night City!\n";
    cout << "\nYou Won! Type restart to restart the game and try again to see different outcomes. Type quit to quit playing.\n\n";
    cin >> winChoice;
    if (winChoice == "restart" || winChoice == "Restart") {
        playGame();
    }
    if (winChoice == "quit" || winChoice == "Quit") {
        return winChoice;
    }
    else {
        // Needed return value at the end of all non-void functions as it was throwing a warning about control reaches the end of a non-void function. Does not impact gameplay.
        return winChoice;
    }
}

string endingLost() {
    cout << "\nYou lost! Type restart to restart the game and get another chance to keep your title as Champion! Type quit to quit playing.\n\n";
    cin >> lostChoice;
    if (lostChoice == "restart" || lostChoice == "Restart") {
        playGame();
    }
    if (lostChoice == "quit" || lostChoice == "Quit") {
        return lostChoice;
    }
    else {
        // Needed return value at the end of all non-void functions as it was throwing a warning about control reaches the end of a non-void function. Does not impact gameplay.
        return lostChoice;
    }
}

// Program Start
int main() {
    while (winChoice != "quit" || winChoice != "restart" || lostChoice != "quit" || lostChoice != "restart") {
        playGame();
        if (lostChoice == "quit" || winChoice == "quit") {
            return 0;
        }
    }
    // Needed return 0; at the end of all non-void functions as it was throwing a warning about control reaches the end of a non-void function. Does not impact gameplay.
    return 0;
}

// Actual game function
string playGame() {
    opening();

    // Getting racer and rival names.
    cout << "\n\nPlease enter the following information to get started on your racing adventure!\n";
    cout << "Enter your Racer's Name: ";
    cin >> racer;
    cout << "Enter your Rival's Name: ";
    cin >> rival;

    raceStart();
    (void)getchar();

    // First game challenge. Starting the engine.
    start = "";
    cout << "Racers, ready your engines!\n";
    cout << "\nTo ready your engine, type start.\n\n";
    // If the player types "start" or "Start", then the game will continue. If they do not, then it will loop until they do so. 
    while (start != "start") {
        cin >> start;
        if (start == "start" || start == "Start") {
            cout << "\nGood work!\n";
            break;
        }
        else {
            cout << "\nNot quite. Try typing start.\n\n";
        }
    }

    // Second game challenge. Engine stall and restart. Possible losing ending.
    restart = "";
    cout << "\n3...2...1...GO!\n";
    cout << "Both racers slam on the gas and their cars shoot out from the starting line. All is going well until... your car stalls!\n\n";
    cout << "Quick! Type restart to restart your engine!\n\n";
    // If the player types "restart" or "Restart", then the game will continue and they only recieve a small penalty. Otherwise, if they do not type it correctly, they lose a large amount of speed.
    cin >> restart;
    if (restart == "restart" || restart == "Restart") {
        cout << "\nGreat work! We can get back to racing. You only lost 10% speed. You now have " << currSpeed(-10) << "% speed.\n";
    }
    else {
        cout << "\nOh no! You didn't type start. You were able to start your car, but you lost 25% of your speed! You now have " << currSpeed(-25) << "% speed.\n";
    }

    // Third game challenge. Make a decision where you want to go. Possible losing ending.
    trashCan = "";
    trashCanScene();
    cout << "Type shortcut to take the shortcut. Type straight to drive over the trash cans.\n\n";
    // If the player types "shortcut" or "Shortcut", they go down one path. If they type "straight" or "Straight", then they go down the other path. If they do not type either, then they lose.
    while (trashCan != "shortcut" || trashCan != "straight") {
        cin >> trashCan;
        if (trashCan == "shortcut" || trashCan == "Shortcut") {
            cout << "\nYou took the shortcut. Down the alley you drove and to your surprise, it sped you up! You come out right next to " << rival << ". You now have " << currSpeed(10) << "% speed.\n";
            break;
        }
        if (trashCan == "straight" || trashCan == "Straight") {
            cout << "\nYou went straight through the trash cans. You wind up slightly behind " << rival << ". You didn't lose any speed, but you didn't gain any either. You now have " << currSpeed(0) << "% speed.\n";
            break;
        }
        else {
            cout << "\nIt looks like you didn't go anywhere. You wound up sitting in your car doing nothing. You forfiet your title as Champion to " << rival << ".\n";
            endingLost();
            return lostChoice;
        }
    }

    // Fourth game challenge. Make a decision where you want to go. Possible losing ending.
    crowdStreet = "";
    crowdStreetScene();
    cout << "Type street to take the crowded streets or type highway to jump on the I-10.\n\n"; \
        // If the player types "street" or "Street", they go down one path. If they type "highway" or "Highway", then they go down the other path. If they do not type either, then they lose.
        while (crowdStreet != "street" || crowdStreet != "highway") {
            cin >> crowdStreet;
            if (crowdStreet == "street" || crowdStreet == "Street") {
                cout << "\nYou decide to take your chances on the crowded streets. You weave your way in and out of street vendors but luckily did not crash into any of them.\n";
                cout << "Because you took your time to not crash into any of the street vendors, you lost a lot of speed. You now have " << currSpeed(-35) << "% speed.\n";
                break;
            }
            if (crowdStreet == "highway" || crowdStreet == "Highway") {
                cout << "\nYou jump on the I-10 and race through the empty freeway. You aren't getting slowed down by anyone and by only luck you see an exit that will take you to North Night City.\n";
                cout << "You've gained some speed and should now right behind " << rival << ". You now have " << currSpeed(15) << "% speed.\n";
                break;
            }
            else {
                cout << "\nIt looks like you didn't go anywhere. You wound up sitting in your car doing nothing. You forfiet your title as Champion to " << rival << ".\n";
                endingLost();
                return lostChoice;
            }
        }

    // Fourth game challenge. Make a decision where you want to go. Possible losing ending.
    bridgeCollapse = "";
    brokenBridgeScene();
    cout << "Type ramp to jump the river and have a chance to win the race or type home to drive back home, winning nothing.\n\n";
    // If the player types "ramp" or "Ramp", then they continue and have a chance to win. If they type "home" or "Home", they lose. If they do not type either, it will loop until they type one or the other.
    while (bridgeCollapse != "ramp" || bridgeCollapse != "home") {
        cin >> bridgeCollapse;
        if (bridgeCollapse == "ramp" || bridgeCollapse == "Ramp") {
            ramp();
            break;
        }
        if (bridgeCollapse == "home" || bridgeCollapse == "Home") {
            cout << "\nYou decide to cut your losses and turn towards home. Defeated, you know you'll be able to try again next time. At least you'll live another day.\n";
            endingLost();
            return lostChoice;
        }
        else {
            cout << "\nYou didn't make a decision, try again.\n\n";
        }
    }

    // Finishing line challenge. Player needs to speed up in order to pass rival.
    speedUp = "";
    cout << "\nYour speed boost from the river jump was just enough to get you neck-and-neck with " << rival << ".\n";
    cout << "You both see the finish line in sight. It's less than a mile away. If you want to win, you need to speed up!\n";
    cout << "\nType speed to speed up!\n\n";
    // If the player types "speed" or "Speed", then they advance. If they don't type that, then it loops.
    while (speedUp != "speed") {
        cin >> speedUp;
        if (speedUp == "speed" || speedUp == "Speed") {
            cout << "\nGreat, keep speeding up!";
            break;
        }
        else {
            cout << "\nOh no, you missed speeding up. Try again.\n\n";
        }
    }

    // Reset speedUp variable to empty as it was causing issues with reusing the variable.
    speedUp = currSpeedUp;

    // Finishing line challenge. Player needs to speed up in order to pass rival.
    cout << "\nType speed to speed up!\n\n";
    // If the player types "speed" or "Speed", then they advance. If they don't type that, then it loops.
    while (speedUp != "speed") {
        cin >> speedUp;
        if (speedUp == "speed" || speedUp == "Speed") {
            cout << "\nGood job, keep speeding up! You're almost there.";
            break;
        }
        else {
            cout << "\nOh no, you missed speeding up. Try again.\n\n";
        }
    }

    // Reset speedUp variable to empty as it was causing issues with reusing the variable.
    speedUp = currSpeedUp;

    // Finishing line challenge. Player needs to speed up in order to pass rival. Possible winning and losing endings.
    cout << "\nOne last time, type speed to speed up!\n\n";
    // If the player types "speed" or "Speed", then they win. If they don't type that, then they lose.
    while (speedUp != "speed") {
        cin >> speedUp;
        if (speedUp == "speed" || speedUp == "Speed") {
            cout << "\nExcellent! You should be past " << rival << " now!\n";
            endingWin();
            return winChoice;
        }
        else {
            cout << "\nOh no, you missed speeding up!\n";
            cout << rival << " is still ahead of you. They reached the finish line before you and claimed the title as Champion Racer of Night City.\n";
            endingLost();
            return lostChoice;
        }
    }
    // Needed return value at the end of all non-void functions as it was throwing a warning about control reaches the end of a non-void function. Does not impact gameplay.
    return playGame();
}