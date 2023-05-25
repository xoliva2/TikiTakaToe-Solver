
#ifndef TEAMPICKER_H
#define TEAMPICKER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


pair<int, pair<string, string>> pickTeam();

vector<string> directTransferCheck(int firstTeamLeagueNum, string firstTeamString, string secondTeamString);

vector<string> indirectTransferCheck(pair<int, pair<string, string>> firstTeam, pair<int, pair<string, string>> secondTeam);

#endif