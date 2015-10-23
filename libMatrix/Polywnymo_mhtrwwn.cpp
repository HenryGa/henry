//
// Created by henry on 18/10/2015.
//

#include "Polywnymo_mhtrwwn.h"
#include "Pinakas_polywnymou_mhtrwwn.h"
#include "Matrix.h"

using namespace std;

template <typename T>
Polywnymo_mhtrwwn<T>::~Polywnymo_mhtrwwn(){

    for (int i = 0; i < this->sthles; ++i) {
        delete this->table[0][i] ;
    }
    delete this->table[0];
    delete this->table;
}

template <typename T>
void Polywnymo_mhtrwwn<T>::print_Table(int num){

        cout << "A["<<num<<"] = \n";
        this->table[0][num]->print_Table();
        cout << endl;
}

template <typename T>
void Polywnymo_mhtrwwn<T>::print_Table(){

    for (int i = 0; i < this->sthles; ++i) {
        cout << "A["<<i<<"] = \n";
        this->table[0][i]->print_Table();
        cout << endl;
    }

}

/*
	paragwgh tou Polywnymou Mhtrwwn
*/
template <typename T>
void Polywnymo_mhtrwwn<T>::generate( Matrix<int> & m1 , Matrix<int> & m2) {

    int m1sthles = m1.get_sthles();
    int m2sthles = m2.get_sthles();
    int m1grammes = m1.get_grammes();
    int m2grammes = m2.get_grammes();

    int maxYpower ;

    if( m1sthles > m2sthles){
        maxYpower = m1sthles;
        this->allocate_Table(1,m1sthles);				//pinakas pou deixnei sta Ai
    }
    else{
        maxYpower = m2sthles;
        this->allocate_Table(1,m2sthles);				//pinakas pou deixnei sta Ai
    }

    int mege8os_Ai = m1grammes + m2grammes - 2;			//megethos pinaka Ai---oso o Sylvester

    // paragwgh Ai
    for ( int i = 0; i < maxYpower; ++i) {

        Pinakas_polywnymou_mhtrwwn<int*> * a = new Pinakas_polywnymou_mhtrwwn<int*>();

        a->allocate_Table(mege8os_Ai,mege8os_Ai);   //desmeysh xwrou gia ton Ai

        a->generate_Mhtrwo(m1,m2 , i);			 

        this->table[0][i] = a;					//enas pinakas pou exei san stoixeia tous Ai pinakes

    }

}
