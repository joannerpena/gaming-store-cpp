#include <iostream>
#include <iomanip>
#include <string>
#include "Game.h"
using namespace std;

Game gameList;

void displayReport(){
    cout << setw(5) << "Game's Name" << setw(15) << "Console" << setw(15) << "Price";
    cout << setw(15) << "Available" << endl;
    cout << "*-------------------------------------------------------*\n";
    gameList.displayGames();
    cout << "*-------------------------------------------------------*\n";
    cout << endl << endl;
}

int main() {
    string name,console;
    float price;
    bool availability;
    bool loopLock = true;
    int ans;

    while(loopLock){
        cout << "****************************************\n";
        cout << "** Welcome to the Gaming Store System **\n";
        cout << "****************************************\n";

        cout << "\nPlease select a number from the menu: " << endl;

        cout << "*---------------------------------------------*\n";
        cout << "| [1] Insert New Game                         |\n";
        cout << "| [2] Modify A Game                           |\n";
        cout << "| [3] Delete A Game                           |\n";
        cout << "| [4] Find A Specific Game                    |\n";
        cout << "| [5] Display Report of Games                 |\n";
        cout << "| [6] Exit Application                        |\n";
        cout << "*---------------------------------------------*\n";

        cout << endl;
        cout << "Selection: ";
        cin >> ans;
        cout << endl;

        string temp;
        int tmp;
        switch (ans){
            case 1:
                if(gameList.isEmpty()){
                    cout << "Enter the Game's Name: ";
                    cin.get();
                    getline(cin,name);


                    cout << "\nEnter the Console (Xbox,Ps4,Switch): ";
                    cin >> console;

                    cout << "\nEnter price (Ex: 59.99): ";
                    cin >> price;

                    cout << "\nIs it the game available in the store? (Y or N): ";
                    char answ;
                    cin >> answ;
                    cout << endl << endl;

                    if(answ == 'y' || answ == 'Y')
                        availability = true;
                    else
                        availability = false;

                    gameList.createGame(name,console,price,availability);
                    displayReport();
                }
                else{
                    cout << "\nHow would you like to insert?" << endl;
                    cout << "*-------------------------------*\n";
                    cout << "|[1] Insert at the end          |\n";
                    cout << "|[2] Insert after the first one |\n";
                    cout << "*-------------------------------*\n";
                    cout << "\nSelection: ";
                    cin >> tmp;

                    if(tmp == 1){
                        cout << "\nEnter the Game's Name: ";
                        cin.get();
                        getline(cin,name);

                        cout << "\nEnter the Console (Xbox,Ps4,Switch): ";
                        cin >> console;

                        cout << "\nEnter price (Ex: 59.99): ";
                        cin >> price;

                        cout << "\nIs it the game available in the store? (Y or N): ";
                        char answ;
                        cin >> answ;

                        if(answ == 'y' || answ == 'Y')
                            availability = true;
                        else
                            availability = false;

                        gameList.createGame(name,console,price,availability);
                        displayReport();
                    }
                    else{
                        cout << "Enter the Game's Name: ";
                        cin.get();
                        getline(cin,name);

                        cout << "\nEnter the Console (Xbox,Ps4,Switch): ";
                        cin >> console;

                        cout << "\nEnter price (Ex: 59.99): ";
                        cin >> price;

                        cout << "\nIs it the game available in the store? (Y or N): ";
                        char answ;
                        cin >> answ;

                        if(answ == 'y' || answ == 'Y')
                            availability = true;
                        else
                            availability = false;

                        gameList.insertGame(name,console,price,availability,2);
                        displayReport();
                    }
                }
                break;

            case 2:
                if(gameList.isEmpty()){
                    cout << "\nNo Game Listed" << endl << endl;
                }
                else{
                    cout << "*-------------------------------------------------------*\n";
                    gameList.displayGames();
                    cout << "*-------------------------------------------------------*\n";
                    cout << "\nEnter the name of the game you like to change:  ";
                    cin.get();
                    getline(cin,temp);

                    cout << "Enter the Game's Name: ";
                    cin.get();
                    getline(cin,name);

                    cout << "\nEnter the Console (Xbox,Ps4,Switch): ";
                    cin >> console;

                    cout << "\nEnter price (Ex: 59.99): ";
                    cin >> price;

                    cout << "\nIs it the game available in the store? (Y or N): ";
                    char answ;
                    cin >> answ;

                    if(answ == 'y' || answ == 'Y')
                        availability = true;
                    else
                        availability = false;

                    gameList.modGame(temp,name,console,price,availability);
                    displayReport();
                }
                break;

            case 3:
                if(gameList.isEmpty()){
                    cout << "\nNo Game Listed" << endl << endl;
                }
                else{
                    cout << "*-------------------------------------------------------*\n";
                    gameList.displayForDeleteMenu();
                    cout << "*-------------------------------------------------------*\n";
                    cout << "\nEnter the position of the game you like to delete:  ";
                    cin >> tmp;

                    gameList.delGame(tmp);
                    displayReport();
                }
                break;

            case 4:
                if(gameList.isEmpty()){
                    cout << "\nNo Game Listed" << endl << endl;
                }
                else{
                    cout << "\n Enter A Game's Name: ";
                    cin.get();
                    getline(cin,temp);

                    gameList.findGame(temp);
                }
                break;

            case 5:
                if(gameList.isEmpty()){
                    cout << "\nNo Game Listed" << endl << endl;
                }
                else{
                    displayReport();
                }
                break;

            case 6:
                loopLock = false;
                break;

            default:
                exit(0);
        }
    }

    cin.get();
    return 0;
}