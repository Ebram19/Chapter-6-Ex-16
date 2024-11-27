
// file name: Chapter 6 Ex 16
// programmer name : Ebram Azer
// Date: Nov 24
// Requirment:
//For this programming problem, download the following files from the book’s companion website :
//• Teams.txt—This file contains a list of several Major League baseball teams in alphabetical order.Each team listed in the file has won the World Series at least once.
//• WorldSeriesWinners.txt—This file contains a chronological list of the World Series’ winning teams from 1903 to 2012
//(The first line in the file is the name of the team that won in 1903, and the last line is the name of the team that won in 2012.
// Note the World Series was not played in 1904 or 1994.)
//the number of times that team has won the World Series in the time period from 1903 to 2012.
//TIP : Read the contents of the WorldSeriesWinners.txt file into an array or vector.When the user enters 
//the name of a team, the program should step through the array or vector counting the number of times the selected team appears.









#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> // For counting occurrences

using namespace std;

int main() {
    // File names
    const string teamsFile = "Teams.txt";
    const string winnersFile = "WorldSeriesWinners.txt";

    // Vectors to store team names and World Series winners
    vector<string> teams;
    vector<string> winners;

    // Open Teams.txt and read the teams
    ifstream inputTeams(teamsFile);
    if (!inputTeams) {
        cerr << "Error: Could not open file " << teamsFile << endl;
        return 1;
    }

    string line;
    while (getline(inputTeams, line)) {
        teams.push_back(line);
    }
    inputTeams.close();

    // Open WorldSeriesWinners.txt and read the winners
    ifstream inputWinners(winnersFile);
    if (!inputWinners) {
        cerr << "Error: Could not open file " << winnersFile << endl;
        return 1;
    }

    while (getline(inputWinners, line)) {
        winners.push_back(line);
    }
    inputWinners.close();

    // Display the teams
    cout << "List of Major League Baseball Teams:\n";
    for (const auto& team : teams) {
        cout << team << endl;
    }

    // Prompt the user to enter a team name
    cout << "\nEnter the name of a team to find out how many times it has won the World Series: ";
    string userTeam;
    getline(cin, userTeam);

    // Count the number of times the selected team has won
    int winCount = count(winners.begin(), winners.end(), userTeam);

    // Display the result
    if (winCount > 0) {
        cout << "\nThe team \"" << userTeam << "\" has won the World Series " << winCount << " times between 1903 and 2012.\n";
    }
    else {
        cout << "\nThe team \"" << userTeam << "\" has not won the World Series during the period 1903-2012.\n";
    }

    return 0;
}
