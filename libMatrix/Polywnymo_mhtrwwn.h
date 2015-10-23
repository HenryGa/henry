//
// Created by henry on 18/10/2015.
//

#ifndef _POLYWNYMO_MHTRWWN_H
#define _POLYWNYMO_MHTRWWN_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "Matrix.h"

template <typename T>
class Polywnymo_mhtrwwn : public Matrix<T> {

public:

    ~Polywnymo_mhtrwwn();

    virtual void print_Table();

    void print_Table(int num);

    void generate(Matrix<int> &m1 , Matrix<int> &m2);		//ftiaxnoume enan pinaka pou exeis san stoixeia tou deiktes pou deixnoun stous pinakes Ai

};


#endif //FUNCTION_TABLE_POLYWNYMO_MHTRWWN_H
