//Super Smash Bros - Tournament Tracker
//By Jordan Cole

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

//Function prototypes
int show_menu(vector<string>names, vector<int>&wins, vector<int>&kills, int total);
void display_scores(vector<string>names, vector<int>&wins, vector<int>&kills, int total);
void shuffle_players(vector<string>names);
void enter_wins(vector<string>names, vector<int>&wins, int total);
void enter_kills(vector<string>names, vector<int>&kills, int total);

int main()
{
    //Program introduction
    cout << "Super Smash Bros - Tournament Tracker" << endl;
    cout << "By Jordan Cole" << endl;
    cout << endl;
    
	//Create var for player count
	int total_players;

	//User input for player count (must be 1-8)
	do
	{
		cout << "Please enter total number of players (1-8): ";
		cin >> total_players;
		cout << endl;
	} while (total_players < 1 || total_players > 8);

	//Create vector for player names, wins, kills
	vector<string>player_names(total_players);
	vector<int>player_wins(total_players);
	vector<int>player_kills(total_players);

	//Loop to enter player names
	for (int i = 0; i < total_players; i++)
	{
		cout << "Player " << (i + 1) << ", please enter your name: ";
		cin >> player_names[i];
	}
	cout << endl;
    
    //Show menu options until Exit
    int show_menu_choice;
    do
    {
        show_menu_choice = show_menu(player_names, player_wins, player_kills, total_players);
    } while (show_menu_choice != 5);
    
    return 0;
}

//Function: Display menu options
int show_menu(vector<string>names, vector<int>&wins, vector<int>&kills, int total)
{
    int menu_choice;
    cout << "Please choose from the following options:" << endl;
    cout << "1. Display Current Standings" << endl;
    cout << "2. Shuffle Player Order" << endl;
    cout << "3. Enter Wins" << endl;
    cout << "4. Enter Kills" << endl;
    cout << "5. Exit" << endl;
    cout << "Select and Press Enter: ";
    cin >> menu_choice;
    cout << endl;
    if (menu_choice == 1)
    {
        display_scores(names, wins, kills, total);
    }
    else if (menu_choice == 2)
    {
        shuffle_players(names);
    }
    else if (menu_choice == 3)
    {
        enter_wins(names, wins, total);
    }
    else if (menu_choice == 4)
    {
        enter_kills(names, kills, total);
    }
    else if (menu_choice == 5)
    {
        cout << "Exit" << endl;
    }
    else
    {
        cout << "Invalid selection, please try again." << endl;
        cout << endl;
    }
    
    return menu_choice;
}

//Function: Display current standings
void display_scores(vector<string>names, vector<int>&wins, vector<int>&kills, int total)
{
    cout << "Current Standings:" << endl;
    for (int i = 0; i < total; i++)
	{
		cout << names[i] << endl;
		cout << "[Wins - " << wins[i] << ", Kills - " << kills[i] << "]" << endl;
		cout << endl;
	}
}

//Function: Shuffle player order and display
void shuffle_players(vector<string>names)
{
	int n = names.size();
	srand(time(0));
	cout << "The player order this round will be:" << endl;
	for (int i = 0; i < n; i++)
	{
		int j = i + rand() % (n - i);
		swap(names[i], names[j]);
		cout << (i + 1) << ". " << names[i] << endl;
	}
	cout << endl;
}

//Function: Enter win data
void enter_wins(vector<string>names, vector<int>&wins, int total)
{
    int menu_choice, num_wins;
    cout << "Please select a player to add wins:" << endl;
    for (int i = 0; i < total; i++)
	{
		cout << (i + 1) << ". " << names[i] << endl;
	}
	cout << "Select and Press Enter: ";
	cin >> menu_choice;
	cout << endl;
	if (menu_choice == 1)
	{
	    cout << "How many wins would you like to add for " << names[0] << "?" << endl;
	    cout << "Select and Press Enter: ";
	    cin >> num_wins;
	    wins[0] = wins[0] + num_wins;
	}
	else if (menu_choice == 2)
	{
	    cout << "How many wins would you like to add for " << names[1] << "?" << endl;
	    cout << "Select and Press Enter: ";
	    cin >> num_wins;
	    wins[1] = wins[1] + num_wins;
	}
	else if (menu_choice == 3)
	{
	    cout << "How many wins would you like to add for " << names[2] << "?" << endl;
	    cout << "Select and Press Enter: ";
	    cin >> num_wins;
	    wins[2] = wins[2] + num_wins;
	}
	else if (menu_choice == 4)
	{
	    cout << "How many wins would you like to add for " << names[3] << "?" << endl;
	    cout << "Select and Press Enter: ";
	    cin >> num_wins;
	    wins[3] = wins[3] + num_wins;
	}
	else if (menu_choice == 5)
	{
	    cout << "How many wins would you like to add for " << names[4] << "?" << endl;
	    cout << "Select and Press Enter: ";
	    cin >> num_wins;
	    wins[4] = wins[4] + num_wins;
	}
	else if (menu_choice == 6)
	{
	    cout << "How many wins would you like to add for " << names[5] << "?" << endl;
	    cout << "Select and Press Enter: ";
	    cin >> num_wins;
	    wins[5] = wins[5] + num_wins;
	}
	else if (menu_choice == 7)
	{
	    cout << "How many wins would you like to add for " << names[6] << "?" << endl;
	    cout << "Select and Press Enter: ";
	    cin >> num_wins;
	    wins[6] = wins[6] + num_wins;
	}
	else if (menu_choice == 8)
	{
	    cout << "How many wins would you like to add for " << names[7] << "?" << endl;
	    cout << "Select and Press Enter: ";
	    cin >> num_wins;
	    wins[7] = wins[7] + num_wins;
	}
	else
	{
        cout << "Invalid selection, please try again." << endl;
	}
    cout << endl;
}

//Function: Enter kill data
void enter_kills(vector<string>names, vector<int>&kills, int total)
{
    int menu_choice, num_kills;
    cout << "Please select a player to add kills:" << endl;
    for (int i = 0; i < total; i++)
	{
		cout << (i + 1) << ". " << names[i] << endl;
	}
	cout << "Select and Press Enter: ";
	cin >> menu_choice;
    cout << endl;
    if (menu_choice == 1)
	{
	    cout << "How many kills would you like to add for " << names[0] << "?" << endl;
	    cout << "Select and Press Enter: ";
	    cin >> num_kills;
	    kills[0] = kills[0] + num_kills;
	}
	else if (menu_choice == 2)
	{
	    cout << "How many kills would you like to add for " << names[1] << "?" << endl;
	    cout << "Select and Press Enter: ";
	    cin >> num_kills;
	    kills[1] = kills[1] + num_kills;
	}
	else if (menu_choice == 3)
	{
	    cout << "How many kills would you like to add for " << names[2] << "?" << endl;
	    cout << "Select and Press Enter: ";
	    cin >> num_kills;
	    kills[2] = kills[2] + num_kills;
	}
	else if (menu_choice == 4)
	{
	    cout << "How many kills would you like to add for " << names[3] << "?" << endl;
	    cout << "Select and Press Enter: ";
	    cin >> num_kills;
	    kills[3] = kills[3] + num_kills;
	}
	else if (menu_choice == 5)
	{
	    cout << "How many kills would you like to add for " << names[4] << "?" << endl;
	    cout << "Select and Press Enter: ";
	    cin >> num_kills;
	    kills[4] = kills[4] + num_kills;
	}
	else if (menu_choice == 6)
	{
	    cout << "How many kills would you like to add for " << names[5] << "?" << endl;
	    cout << "Select and Press Enter: ";
	    cin >> num_kills;
	    kills[5] = kills[5] + num_kills;
	}
	else if (menu_choice == 7)
	{
	    cout << "How many kills would you like to add for " << names[6] << "?" << endl;
	    cout << "Select and Press Enter: ";
	    cin >> num_kills;
	    kills[6] = kills[6] + num_kills;
	}
	else if (menu_choice == 8)
	{
	    cout << "How many kills would you like to add for " << names[7] << "?" << endl;
	    cout << "Select and Press Enter: ";
	    cin >> num_kills;
	    kills[7] = kills[7] + num_kills;
	}
	else
	{
        cout << "Invalid selection, please try again." << endl;
	}
    cout << endl;
}
