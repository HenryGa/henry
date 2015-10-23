//
// Created by henry on 18/10/2015.
//

#ifndef FUNCTION_TABLE_PINAKAS_POLYWNYMOU_MHTRWWN_H
#define FUNCTION_TABLE_PINAKAS_POLYWNYMOU_MHTRWWN_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "Polywnymo_mhtrwwn.h"
#include "Matrix.h"

template <typename T>
class Pinakas_polywnymou_mhtrwwn : public Matrix<T> {

public:

    ~Pinakas_polywnymou_mhtrwwn();

    void print_Table();

    void generate_Mhtrwo(Matrix<int > & m1, Matrix<int> & m2, int column);			//ftiaxnoume kapoio Ai

};


#endif //FUNCTION_TABLE_PINAKAS_POLYWNYMOU_MHTRWWN_H
