#ifndef _PINAKAS_SYNTELESTWN_HPP_
#define _PINAKAS_SYNTELESTWN_HPP_

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "Matrix.h"
#include "Pinakas_polywnymou_mhtrwwn.h"

template <typename T>
class Pinakas_syntelestwn : public Matrix<T>{

public:

    ~Pinakas_syntelestwn();

    void print_Table();

    void create_Polywnymo( int vathmosPolywnymou );					//ftiaxnoume tyxaia polywnhma dedomenou d1 kai d2

    int get_element(int i, int j){ return this->table[i][j];}		

};

#endif