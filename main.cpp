#include "teamPicker.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>

//things to add: age checker to see if the player is the same one
//               check if the player has actually played at the club or not (not that important)
//               add other leagues (would involve scraping data)
//               if we make it a website, add drop-down thing so it's easier
//                                
using namespace std;
int main(){

    pair<int, pair<string, string>> firstTeam;
    pair<int, pair<string, string>> secondTeam;

    vector<string> playerNameVector;
    // pair<string, string> secondTeam;
    cout << "What league is the first team in?\n";
    firstTeam = pickTeam();
    cout << "What league is the second team in?\n";
    secondTeam = pickTeam();

    cout<< "Let's see if there's a link between " << firstTeam.second.first <<" and "<<secondTeam.second.second<<endl;

    //after you get the string pair of their name and name in club_name whatever
    //then you check if there's any direct transfer
    cout<<firstTeam.second.second<<endl;
    playerNameVector = directTransferCheck(firstTeam.first, firstTeam.second.first, secondTeam.second.second);
    if (playerNameVector.empty()) {
        std::cout << "No Direct Transfers found." << std::endl;
    } else {
        std::cout << "Direct Transfers found: ";
        std::string output;

        for (size_t i = 0; i < playerNameVector.size(); ++i) {
            output += playerNameVector[i];
            if (i != playerNameVector.size() - 1) {
                output += ", ";
            } else {
                output += ".";
            }
        }

        std::cout << output << std::endl;
    }
   
    //then check if the second team appears anywhere in other lists...
    //...by using the name of the players in the transfers for..
    //...the team in their league csv. (you know what i mean)

    // function not done
    playerNameVector = indirectTransferCheck(firstTeam, secondTeam);
    if (playerNameVector.empty()) {
        std::cout << "No links found. Sorry." << std::endl;
    } else {
        std::cout << "Indirect Transfers found: ";
        std::string output;

        for (size_t i = 0; i < playerNameVector.size(); ++i) {
            output += playerNameVector[i];
            if (i != playerNameVector.size() - 1) {
                output += ", ";
            } else {
                output += ".";
            }
        }

        std::cout << output << std::endl;
    }


    return 0;
}