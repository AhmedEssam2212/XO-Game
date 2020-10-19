//
// Created by Ahmed Essam .
//
#include <iostream>

#ifndef XO_GAME_H
#define XO_GAME_H


class game {
    char arr[3][3];
    int visited = 0;

    char checkRows() const;
    char checkCols() const;
    char checkFirDiag() const;
    char checkSecDiag() const;
public:
    game();

    void clear();

    void first();

    void view() const;

    char winner() const;          //predicate function
    bool fail() const;            //predicate function
    bool player(int &, const char &);

    void computer(const char &);

};


#endif
