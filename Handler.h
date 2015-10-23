//
// Created by henry on 21/10/2015.
//

#ifndef FUNCTION_TABLE_HANDLER_H
#define FUNCTION_TABLE_HANDLER_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "libMatrix/Matrix.h"
#include "libMatrix/Matrix.cpp"
#include "libMatrix/Pinakas_syntelestwn.hpp"
#include "libMatrix/Pinakas_syntelestwn.cpp"
#include "libMatrix/Polywnymo_mhtrwwn.h"
#include "libMatrix/Polywnymo_mhtrwwn.cpp"
#include "libMatrix/Pinakas_polywnymou_mhtrwwn.h"
#include "libMatrix/Pinakas_polywnymou_mhtrwwn.cpp"
#include "libMatrix/Sylvester.h"
#include "libMatrix/Sylvester.cpp"

#define BUFFSIZE 1000

class Handler {

private:

    int d0;
    int d1;

    char hidden_variable;           //krymmenh metavlhth
    int ** result;                 //S*v (bonus)

    Pinakas_syntelestwn<int> m1;  //Polywnymo m1
    Pinakas_syntelestwn<int> m2;  //Polywnymo m2
    Pinakas_syntelestwn<int> v;   //dianysma v
    Sylvester <int*> sylvester;   //pinakas sulvester

    Polywnymo_mhtrwwn< Pinakas_polywnymou_mhtrwwn<int*> *> Polywnymo_Mhtrwwn;

    char Read_synarthsh_from_file(char *filename );                         //anagnwsh apo arxeio

    void place_function_in_Matrix(char * buffer , Matrix<int> &);           //parser gia ton pinaka Matrix<int>

  /*+++++++++++++++++++++++++++++++*/
    char find_hidden_variable( Matrix<int> & m1 , Matrix<int> & m2);        //vriskoume thn krymmenh metavlhth

    void read( char * filename );                                           //kaloume thn Read_synarthsh_from_file(char *filename );

    void consola();                                                         //kaloume thn place_function_in_Matrix(char * buffer , Matrix<int> &);

    void generate();                                                        //paragoyme ta 2 polyonyma

public:

    ~Handler();

    void handle_input(int argc, char * argv[]);                             //epiloges ekkinhshs programmatos

    int getD0() const { return d0; }

    int getD1() const { return d1; }

    int getHidden_Variable() const { return hidden_variable; }

    Pinakas_syntelestwn<int> getM1() const { return m1; }

    Pinakas_syntelestwn<int> getM2() const { return m2; }

    void generate_Sylvester();                                              //ftiaxnoume Silvester

    void generate_Polywnymo_Mhtrwwn();                                      //ftiaxnoyme ta Ai (polyonuma mhtrwwn)

    /*++++++++++++++++++++++++++++++++*/
    void print();                                                           //ektypwsh epiloges xrhsth

    /*+++++++++++++++++++++++*/
    void generate_Bonus();                                                  //to bonus kommati

};


#endif //FUNCTION_TABLE_HANDLER_H
