//
// Created by Joanner Pena on 2019-08-06.
//
#include <iostream>
#include <iomanip>
#include <string>
#include "Game.h"
using namespace std;

void Game::createGame(string gName, string gConsole, float gPrice, bool gAva){
    node *tmp = new node;
    tmp->name = gName;
    tmp->console = gConsole;
    tmp->price = gPrice;
    tmp->available = gAva;
    tmp->next = NULL;

    if(head == NULL)
    {
        head = tmp;
        tail = tmp;
        tmp = NULL;
    }
    else
    {
        tail->next = tmp;
        tail = tmp;
    }
}

void Game::displayGames(){
    node *tmp = new node;
    tmp = head;
    int pos;
    string ava;

    while(tmp != NULL) {
        cout << setw(5) << tmp->name << setw(10) << tmp->console << setw(15) << "$" <<tmp->price;

        if(tmp->available == true){
            ava = "Yes";
        }
        else{
            ava = "No";
        }

        cout << setw(15) << ava;
        cout << endl;
        tmp = tmp->next;
    }
}

void Game::displayForDeleteMenu() {
    node *tmp = new node;
    tmp = head;
    int pos = 1;

    while(tmp != NULL)
    {
        cout << "(" << pos << ")" << setw(20) << tmp->name << setw(10) << tmp->console << setw(10) << "$" <<tmp->price;
        cout << setw(10) << tmp->available;
        cout << endl;
        tmp = tmp->next;
        pos++;
    }
}

void Game::insertGame(string gName, string gConsole, float gPrice, bool gAva, int pos){
    node *previous = new node;
    node *current = new node;
    node *tmp = new node;
    current = head;

    for(int i=1; i < pos; i++)
    {
        previous = current;
        current = current->next;
    }
    tmp->name = gName;
    tmp->console = gConsole;
    tmp->price = gPrice;
    tmp->available = gAva;

    previous->next = tmp;
    tmp->next = current;
}

void Game::delGame(int pos){
    node *current = new node;
    node *previous = new node;
    current = head;

    for(int i = 1; i < pos; i++)
    {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
}

void Game::findGame(string name){
    node *tmp = new node;
    tmp = head;

    int found = 0;  //TRUE

    while(tmp != NULL)
    {
        if (tmp->name == name)
        {
            found = 1;
            cout << "\n" <<setw(20) << tmp->name << setw(10) << tmp->console << setw(10) << "$" <<tmp->price;
            cout << endl << endl;
            break;
        }
        else
        {
            tmp = tmp->next;
        }

    }

    if(found == 0)
        cout << "Game not listed";
    cout << endl;
}

void Game::modGame(string name,string gName, string gConsole, float gPrice, bool gAva){
    node *tmp = new node;
    tmp = head;

    int found = 0;  //TRUE

    while(tmp != NULL)
    {
        if (tmp->name == name)
        {
            found = 1;
            tmp->name = gName;
            tmp->console = gConsole;
            tmp->price = gPrice;
            tmp->available = gAva;
            break;
        }
        else
        {
            tmp = tmp->next;
        }

    }

    if(found == 0)
        cout << "Game not listed";
    cout << endl;
}

bool Game::isEmpty() {
    bool tmp;
    if(head == NULL)
        tmp = true;
    else
        tmp = false;

    return tmp;
}