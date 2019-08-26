//
// Created by Joanner Pena on 2019-08-06.
//
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#ifndef PROJECTCPP_GAME_H
#define PROJECTCPP_GAME_H

struct node{
    string name;
    string console;
    float price;
    bool available;

    node *next;
};

class Game {
private:
    node *head,*tail;
public:
    Game(){ head = NULL; tail = NULL; }

    void createGame(string gName, string gConsole, float gPrice, bool gAva);
    void displayGames();
    void displayForDeleteMenu();
    void insertGame(string gName, string gConsole, float gPrice, bool gAva, int pos);
    void delGame(int pos);
    void findGame(string name);
    void modGame(string name,string gName, string gConsole, float gPrice, bool gAva);
    bool isEmpty();

};


#endif //PROJECTCPP_GAME_H
