#include "Pinakas_syntelestwn.hpp"

using namespace std;


template <typename T>
Pinakas_syntelestwn<T>::~Pinakas_syntelestwn(){

    for (int i = 0; i < this->grammes; ++i) {
        delete[] this->table[i];
    }
    delete[] this->table;

}

template <typename T>
void Pinakas_syntelestwn<T>::print_Table(){

    for( int i = 0; i < this->grammes ; i++ )
    {
        for ( int  j = 0; j < this->sthles ; j++ )
            cout << this->table[i][j] << " " ;
        cout << endl;
    }

}

/*
 * dhmiourgei mia pyksh anaparastash pinaka vathmosPolywnymou*vathmosPolywnymou
 * me tyxaious syntelestes
 * kai thn apo8hkeuei ston pinaka tou m
 */
template < typename T>
void Pinakas_syntelestwn<T>::create_Polywnymo( int vathmosPolywnymou ) {

    this->allocate_Table( vathmosPolywnymou+1 , vathmosPolywnymou+1 );

    int x , y;
    int c; // pairnei times apo -MAXFACTOR/2 mexri (MAXFACTOR-1) / 2

    for ( x = 0 ; x <= vathmosPolywnymou  ; x ++)
    {
        for ( y = 0 ; y <= vathmosPolywnymou ; y ++)
        {

            c = rand() % MAXFACTOR;

            // sta8eros oros den mporei na exei syntelesth 0
            if ( (x == 0 && y == 0)  )
            {

                while ( c == 0 )
                    c = rand() % MAXFACTOR;

            }

            if ( x + y > vathmosPolywnymou ) // ean eimai panw apo to miso tou pinaka vale mhden
            {
                this->insert(0,x,y);
                continue;
            }

            c = c - MAXFACTOR/2; // ry8mish proshmou

            this->insert(c,x,y);

        }

    }
}