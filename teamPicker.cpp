
#include "teamPicker.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, pair<string, string>> pickTeam(){

    vector<pair<string, string>> bundesligaTeams = {
        {"Borussia Dortmund", "B. Dortmund"}, {"Bayern Munich", "Bayern Munich"},
        {"RB Leipzig", "RB Leipzig"}, {"Union Berlin", "Union Berlin"},
        {"SC Freiburg", "SC Freiburg"}, {"Bayer 04 LeverKusen", "Bay. Leverkusen"},
        {"VfL Wolfsburg", "VfL Wolfsburg"}, {"Eintracht Frankfurt", "E. Frankfurt"},
        {"1.FSV Mainz 05", "1.FSV Mainz 05"}, {"1. FC Köln", "1. FC Köln"},
        {"Borussia Mönchengladbach", "Bor. M'gladbach"},
        {"SV Werder Bremen", "Werder Bremen"},
        {"TSG 1899 Hoffenheim", "TSG Hoffenheim"},
        {"FC Augsburg", "FC Augsburg"}, {"VfB Stuttgart", "VfB Stuttgart"},
        {"VfL Bochum", "VfL Bochum"}, {"FC Schalke 04", "FC Schalke 04"},
        {"Hertha BSC", "Hertha BSC"}
    };
    vector<pair<string, string>> eredivisieTeams = {
        {"Feyenoord Rotterdam", "Feyenoord"}, {"PSV Eindhoven", "PSV Eindhoven"},
        {"Ajax Amsterdam", "Ajax"}, {"AZ Alkmaar", "AZ Alkmaar"},
        {"Twente Enschede FC", "Twente FC"}, {"Sparta Rotterdam", "Sparta R."},
        {"FC Utrecht", "FC Utrecht"}, {"SC Heerenveen", "Heerenveen"},
        {"RKC Waalwijk", "RKC Waalwijk"}, {"Go Ahead Eagles", "Go Ahead Eagles"},
        {"NEC Nijmegen", "NEC Nijmegen"}, {"Vitesse Arnhem", "Vitesse"},
        {"Fortuna Sittard", "Fortuna Sittard"}, {"FC Volendam", "FC Volendam"},
        {"Excelsior Rotterdam", "Excelsior"}, {"FC Emmen", "FC Emmen"},
        {"FC Groningen", "FC Groningen"}, {"SC Cambuur-Leeuwarden", "SC Cambuur"}
    };
    vector<pair<string, string>> ligaNOSTeams = {
        {"SL Benfica", "Benfica"}, {"FC Porto", "FC Porto"},
        {"SC Braga", "SC Braga"}, {"Sporting CP", "Sporting CP"},
        {"Vitória Guimarães SC", "Vit. Guimarães"}, {"FC Arouca", "Arouca"},
        {"GD Chaves", "Chaves"}, {"FC Famalicão", "Famalicão"},
        {"Casa Pia AC", "Casa Pia"}, {"Boavista FC", "Boavista"},
        {"FC Vizela", "Vizela"}, {"Rio Ave FC", "Rio Ave FC"},
        {"Portimonense SC", "Portimonense"}, {"Gil Vicente FC", "Gil Vicente"},
        {"GD Estoril Praia", "Estoril Praia"}, {"CS Marítimo", "Marítimo"},
        {"FC Paços de Ferreira", "Paços Ferreira"}, {"CD Santa Clara", "Santa Clara"}
    };
    vector<pair<string, string>> ligue1Teams = {
        {"Paris Saint-Germain", "Paris SG"}, {"RC Lens", "Lens"},
        {"Olympique Marseille", "Marseille"}, {"AS Monaco", "Monaco"},
        {"LOSC Lille", "LOSC Lille"}, {"Stade Rennais FC", "Stade Rennais"},
        {"Olympique Lyon", "Olympique Lyon"}, {"Clermont Foot 63", "Clermont Foot"},
        {"OGC Nice", "OGC Nice"}, {"FC Lorient", "FC Lorient"},
        {"Stade Reims", "Stade Reims"}, {"Montpellier HSC", "Montpellier"},
        {"FC Toulouse", "Toulouse"}, {"Stade Brestois 29", "Stade Brestois"},
        {"RC Strasbourg Alsace", "R. Strasbourg"}, {"AJ Auxerre", "AJ Auxerre"},
        {"FC Nantes", "FC Nantes"}, {"ESTAC Troyes", "Troyes"},
        {"AC Ajaccio", "AC Ajaccio"}, {"Angers SCO", "Angers SCO"}
    };
    vector<pair<string, string>> premierLeagueTeams = {
        {"Manchester City", "Man City"}, {"Arsenal FC", "Arsenal"},
        {"Newcastle United", "Newcastle"}, {"Manchester United", "Man Utd"},
        {"Liverpool FC", "Liverpool"}, {"Brighton & Hove Albion", "Brighton"},
        {"Aston Villa", "Aston Villa"}, {"Tottenham Hotspur", "Spurs"},
        {"Brentford FC", "Brentford"}, {"Fulham FC", "Fulham"},
        {"Crystal Palace", "Crystal Palace"}, {"Chelsea FC", "Chelsea"},
        {"Wolverhampton Wanderers", "Wolves"}, {"West Ham United", "West Ham"},
        {"AFC Bournemouth", "Bournemouth"}, {"Nottingham Forest", "Nottm Forest"},
        {"Everton FC", "Everton"}, {"Leicester City", "Leicester"},
        {"Leeds United", "Leeds"}, {"Southampton FC", "Southampton"}
    };
    vector<pair<string, string>> laLigaTeams = {
        {"FC Barcelona", "Barcelona"}, {"Atlético de Madrid", "Atlético Madrid"},
        {"Real Madrid", "Real Madrid"}, {"Real Sociedad", "Real Sociedad"},
        {"Villarreal CF", "Villarreal"}, {"Real Betis Balompié", "Real Betis"},
        {"Athletic Bilbao", "Athletic"}, {"Girona FC", "Girona"},
        {"Sevilla FC", "Sevilla"}, {"CA Osasuna", "CA Osasuna"},
        {"Rayo Vallecano", "Rayo Vallecano"}, {"RCD Mallorca", "Mallorca"},
        {"Valencia CF", "Valencia"}, {"Celta de Vigo", "Celta Vigo"},
        {"UD Almería", "Almería"}, {"Cádiz CF", "Cádiz"},
        {"Real Valladolid CF", "Real Valladolid"}, {"Getafe CF", "Getafe"},
        {"RCD Espanyol Barcelona", "Espanyol"}, {"Elche CF", "Elche"}
    };
    vector<pair<string, string>> serieATeams = {
        {"SSC Napoli", "Napoli"}, {"SS Lazio", "Lazio"},
        {"FC Internazionale", "Inter"}, {"AC Milan", "AC Milan"},
        {"Atalanta BC", "Atalanta BC"}, {"AS Roma", "AS Roma"},
        {"Juventus FC", "Juventus"}, {"AC Monza", "Monza"},
        {"Bologna FC 1909", "Bologna"}, {"Torino Calcio", "Torino"},
        {"AC Fiorentina", "Fiorentina"}, {"Udinese Calcio", "Udinese"},
        {"US Sassuolo", "Sassuolo"}, {"Empoli FC", "Empoli"},
        {"US Salernitana 1919", "Salernitana"}, {"US Lecce", "Lecce"},
        {"Spezia Calcio", "Spezia Calcio"}, {"Hellas Verona", "Hellas Verona"},
        {"US Cremonese", "Cremonese"}, {"UC Sampdoria", "Sampdoria"}
    };

    vector<pair<string, string>> leaguePairVector;

    pair<int, pair<string, string>> teamPair{100, {"N/A", "N/A"}};
    
    int leagueNum;
    int teamNum;

    
    // cout << "What league is the first team in?\n";
    cout << "[1] Bundesliga\n";
    cout << "[2] Eredivisie\n";
    cout << "[3] Liga NOS (Portugal)\n";
    cout << "[4] Ligue 1\n";
    cout << "[5] Premier League\n";
    cout << "[6] La Liga\n";
    cout << "[7] Serie A\n";
    cin >> leagueNum;

    switch(leagueNum){
        case 1:
            // Bundesliga
            cout << "What Bundesliga team?\n";
            cout << "[1] Borussia Dortmund || ";
            cout << "[2] Bayern Munich || ";
            cout << "[3] RB Leipzig\n";
            cout << "[4] Union Berlin || ";
            cout << "[5] SC Freiburg || ";
            cout << "[6] Bayer 04 Leverkusen\n";
            cout << "[7] VfL Wolfsburg || ";
            cout << "[8] Eintracht Frankfurt || ";
            cout << "[9] 1.FSV Mainz 05\n";
            cout << "[10] 1. FC Köln || ";
            cout << "[11] Borussia Mönchengladbach || ";
            cout << "[12] SV Werder Bremen\n";
            cout << "[13] TSG 1899 Hoffenheim || ";
            cout << "[14] FC Augsburg || ";
            cout << "[15] VfB Stuttgart\n";
            cout << "[16] VfL Bochum || ";
            cout << "[17] FC Schalke 04 || ";
            cout << "[18] Hertha BSC\n";

            cin >> teamNum;

            leaguePairVector = bundesligaTeams;

            break;
        case 2:
            // Eredivisie
            cout << "What Eredivisie team?\n";
            cout << "[1] Feyenoord Rotterdam || ";
            cout << "[2] PSV Eindhoven || ";
            cout << "[3] Ajax Amsterdam\n";
            cout << "[4] AZ Alkmaar || ";
            cout << "[5] Twente Enschede FC || ";
            cout << "[6] Sparta Rotterdam\n";
            cout << "[7] FC Utrecht || ";
            cout << "[8] SC Heerenveen || ";
            cout << "[9] RKC Waalwijk\n";
            cout << "[10] Go Ahead Eagles || ";
            cout << "[11] NEC Nijmegen || ";
            cout << "[12] Vitesse Arnhem\n";
            cout << "[13] Fortuna Sittard || ";
            cout << "[14] FC Volendam || ";
            cout << "[15] Excelsior Rotterdam\n";
            cout << "[16] FC Emmen || ";
            cout << "[17] FC Groningen || ";
            cout << "[18] SC Cambuur-Leeuwarden\n";

            cin >> teamNum;

            leaguePairVector = eredivisieTeams;

            break;
        case 3:
            // Liga NOS
            cout << "What Liga NOS (Portugal) team?\n";
            cout << "[1] SL Benfica || ";
            cout << "[2] FC Porto || ";
            cout << "[3] SC Braga\n";
            cout << "[4] Sporting CP || ";
            cout << "[5] Vitória Guimarães SC || ";
            cout << "[6] FC Arouca\n";
            cout << "[7] GD Chaves || ";
            cout << "[8] FC Famalicão || ";
            cout << "[9] Casa Pia AC\n";
            cout << "[10] Boavista FC || ";
            cout << "[11] FC Vizela || ";
            cout << "[12] Rio Ave FC\n";
            cout << "[13] Portimonense SC || ";
            cout << "[14] Gil Vicente FC || ";
            cout << "[15] GD Estoril Praia\n";
            cout << "[16] CS Marítimo || ";
            cout << "[17] FC Paços de Ferreira || ";
            cout << "[18] CD Santa Clara\n";

            cin >> teamNum;

            leaguePairVector = ligaNOSTeams;

            break;
        case 4:
            // Ligue 1
            cout << "What Ligue 1 team?\n";
            cout << "[1] Paris Saint-Germain || ";
            cout << "[2] RC Lens || ";
            cout << "[3] Olympique Marseille\n";
            cout << "[4] AS Monaco || ";
            cout << "[5] LOSC Lille || ";
            cout << "[6] Stade Rennais FC\n";
            cout << "[7] Olympique Lyon || ";
            cout << "[8] Clermont Foot 63 || ";
            cout << "[9] OGC Nice\n";
            cout << "[10] FC Lorient || ";
            cout << "[11] Stade Reims || ";
            cout << "[12] Montpellier HSC\n";
            cout << "[13] FC Toulouse || ";
            cout << "[14] Stade Brestois 29 || ";
            cout << "[15] RC Strasbourg Alsace\n";
            cout << "[16] AJ Auxerre || ";
            cout << "[17] FC Nantes || ";
            cout << "[18] ESTAC Troyes\n";
            cout << "[19] AC Ajaccio || ";
            cout << "[20] Angers SCO\n";

            cin >> teamNum;

            leaguePairVector = ligue1Teams;

            break;
        case 5:
            // Premier League
            cout << "What Premier League team?\n";
            cout << "[1] Manchester City || ";
            cout << "[2] Arsenal FC || ";
            cout << "[3] Newcastle United\n";
            cout << "[4] Manchester United || ";
            cout << "[5] Liverpool FC || ";
            cout << "[6] Brighton & Hove Albion\n";
            cout << "[7] Aston Villa || ";
            cout << "[8] Tottenham Hotspur || ";
            cout << "[9] Brentford FC\n";
            cout << "[10] Fulham FC || ";
            cout << "[11] Crystal Palace || ";
            cout << "[12] Chelsea FC\n";
            cout << "[13] Wolverhampton Wanderers || ";
            cout << "[14] West Ham United || ";
            cout << "[15] AFC Bournemouth\n";
            cout << "[16] Nottingham Forest || ";
            cout << "[17] Everton FC || ";
            cout << "[18] Leicester City\n";
            cout << "[19] Leeds United || ";
            cout << "[20] Southampton FC\n";

            cin >> teamNum;

            leaguePairVector = premierLeagueTeams;

            break;
        case 6:
            // La Liga
            cout << "What La Liga team?\n";
            cout << "[1] FC Barcelona || ";
            cout << "[2] Atlético de Madrid || ";
            cout << "[3] Real Madrid\n";
            cout << "[4] Real Sociedad || ";
            cout << "[5] Villarreal CF || ";
            cout << "[6] Real Betis Balompié\n";
            cout << "[7] Athletic Bilbao || ";
            cout << "[8] Girona FC || ";
            cout << "[9] Sevilla FC\n";
            cout << "[10] CA Osasuna || ";
            cout << "[11] Rayo Vallecano || ";
            cout << "[12] RCD Mallorca\n";
            cout << "[13] Valencia CF || ";
            cout << "[14] Celta de Vigo || ";
            cout << "[15] UD Almería\n";
            cout << "[16] Cádiz CF || ";
            cout << "[17] Real Valladolid CF || ";
            cout << "[18] Getafe CF\n";
            cout << "[19] RCD Espanyol Barcelona || ";
            cout << "[20] Elche CF\n";

            cin >> teamNum;

            leaguePairVector = laLigaTeams;

            break;
        case 7:
            // Serie A
            cout << "What Italian team?\n";
            cout << "[1] SSC Napoli || ";
            cout << "[2] SS Lazio || ";
            cout << "[3] FC Internazionale\n";
            cout << "[4] AC Milan || ";
            cout << "[5] Atalanta BC || ";
            cout << "[6] AS Roma\n";
            cout << "[7] Juventus FC || ";
            cout << "[8] AC Monza || ";
            cout << "[9] Bologna FC 1909\n";
            cout << "[10] Torino Calcio || ";
            cout << "[11] AC Fiorentina || ";
            cout << "[12] Udinese Calcio\n";
            cout << "[13] US Sassuolo || ";
            cout << "[14] Empoli FC || ";
            cout << "[15] US Salernitana 1919\n";
            cout << "[16] US Lecce || ";
            cout << "[17] Spezia Calcio || ";
            cout << "[18] Hellas Verona\n";
            cout << "[19] US Cremonese || ";
            cout << "[20] UC Sampdoria\n";

            cin >> teamNum;

            leaguePairVector = serieATeams;

            break;
        default:
            cout<<"LEAGUE NOT RECOGNIZED";
            break;

    //given: teamNum, leagueNum

    }

    teamPair.first = leagueNum;
    teamPair.second = leaguePairVector[(teamNum-1)];
    
    // cout << teamPair.first << ", "<<teamPair.second<<endl;;
    return teamPair;

}

vector<string> directTransferCheck(int firstTeamLeagueNum, string firstTeamString, string secondTeamString){
    ifstream leagueFile;
    switch(firstTeamLeagueNum){
        case 1:
            // Bundesliga
            leagueFile.open("data/1-bundesliga.csv");

            break;
        case 2:
            // Eredivisie
            leagueFile.open("data/eredivisie.csv");

            break;
        case 3:
            // Liga NOS
            leagueFile.open("data/liga-nos.csv");

            break;
        case 4:
            // Ligue 1
            leagueFile.open("data/ligue-1.csv");

            break;
        case 5:
            // Premier League
            leagueFile.open("data/premier-league.csv");

            break;
        case 6:
            // La Liga
            leagueFile.open("data/primera-division.csv");

            break;
        case 7:
            // Serie A
            leagueFile.open("data/serie-a.csv");

            break;
        default:
            cout<<"ERROR";
            break;


    }
    

    //have: leagueFile, both team strings.
    string line;
    vector<string> playerVector;
    while (getline(leagueFile, line)) {
        istringstream iss(line);
        string clubName, playerName, clubInvolvedName, age, position;
        getline(iss, clubName, ',');
        getline(iss, playerName, ',');
        getline(iss, age, ',');
        getline(iss, position, ',');
        getline(iss, clubInvolvedName, ',');
        
        if (clubName == firstTeamString){
            // cout<<playerName<<", "<<clubInvolvedName<<", "<<secondTeamString<< endl;
            if (clubInvolvedName == secondTeamString) {
            playerVector.push_back(playerName);
            // std::cout << "Player Name: " << playerName << std::endl;
            }
        }
    }

    leagueFile.close();

    sort(playerVector.begin(), playerVector.end());
    playerVector.erase(unique(playerVector.begin(), playerVector.end()), playerVector.end());

    return playerVector;

}

vector<string> indirectTransferCheck(pair<int, pair<string, string>> firstTeam, pair<int, pair<string, string>> secondTeam){
    vector<string> playerNameVector;
    vector<string> resultVector;

    std::vector<std::string> fileVector = {
        "data/1-bundesliga.csv", "data/eredivisie.csv", "data/liga-nos.csv",
        "data/ligue-1.csv", "data/premier-league.csv", "data/primera-division.csv",
        "data/serie-a.csv"
    };

    //basically get every player that has transferred out and...
    //...check their name and if the second team appears...
    //...at all in the other files. if not, no link.
    ifstream leagueFile;
    int bracketNum = firstTeam.first-1;
    leagueFile.open(fileVector[bracketNum]);
    fileVector.erase(fileVector.begin()+bracketNum );

    string line;
    
    while (getline(leagueFile, line)) {
        istringstream iss(line);
        string clubName, playerName, clubInvolvedName, age, position;
        getline(iss, clubName, ',');
        getline(iss, playerName, ',');
        getline(iss, age, ',');
        getline(iss, position, ',');
        getline(iss, clubInvolvedName, ',');
        
        if (clubName == firstTeam.second.first && clubInvolvedName != secondTeam.second.second){
            // cout<<playerName<<", "<<clubInvolvedName<<", "<<secondTeamString<< endl;
            
            playerNameVector.push_back(playerName);
            // std::cout << "Player Name: " << playerName << std::endl;
            
        }
    }

    leagueFile.close();

    sort(playerNameVector.begin(), playerNameVector.end());
    playerNameVector.erase(unique(playerNameVector.begin(), playerNameVector.end()), playerNameVector.end());

    //check in other files

    for (const auto& otherLeagueFiles : fileVector) {
        // std::cout << "Current filename: " << otherLeagueFiles << std::endl;
        leagueFile.open(otherLeagueFiles);
        string bruh;
        while (getline(leagueFile, bruh)) {
        istringstream iss(bruh);
        string clubName, playerName, clubInvolvedName, age, position;
        getline(iss, clubName, ',');
        getline(iss, playerName, ',');
        getline(iss, age, ',');
        getline(iss, position, ',');
        getline(iss, clubInvolvedName, ',');
        for (const auto& curName : playerNameVector) {
        
        // Perform operations on the filename here
    
            if (curName == playerName){
                if(clubInvolvedName == secondTeam.second.second || clubName == secondTeam.second.second){
                // cout<<playerName<<", "<<clubInvolvedName<<", "<<secondTeamString<< endl;
                resultVector.push_back(playerName);
                // std::cout << "Player Name: " << playerName << std::endl;
                }
            }
        }
    }

    leagueFile.close();

    sort(resultVector.begin(), resultVector.end());
    resultVector.erase(unique(resultVector.begin(), resultVector.end()), resultVector.end());

    }

    return resultVector;
}