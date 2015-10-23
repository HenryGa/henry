//
// Created by henry on 13/10/2015.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>

#define MAXFACTOR 101

template <typename T>
class Matrix {

protected:
    T ** table;
    int grammes;
    int sthles;
    int maxXpower;
    int maxYpower;

public:

    Matrix(){};
    ~Matrix();

	void allocate_Table( int , int);

	virtual void print_Table();

    int get_vathmos();

    int * get_element(int i ,int j ) { return &table[i][j]; }

    int get_int_element(int i ,int j ) { return table[i][j]; }

    int * get_table_pos(int x,int y) { return table[x][y]; }

    int * get_table_row( int row ) { return table[row]; }
    void insert( T , int , int );

    void set_maxYpower(int pow) { maxYpower = pow;}
    void set_maxXpower(int pow) { maxXpower = pow;}
    int get_maxYpower() { return maxYpower;}
    int get_maxXpower() { return maxXpower;}

    int get_grammes() { return grammes;}
    int get_sthles() { return sthles;}

    void reverse();

};


#endif //FUNCTION_TABLE_MATRIX_H
