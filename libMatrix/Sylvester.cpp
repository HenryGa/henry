//
// Created by henry on 18/10/2015.
//3+5*x+7*y-8*x*y-x^2+2*y^6
//4+3*x-8*y-x*y+10*x^7-y^2

#include "Sylvester.h"

using namespace std;

template < typename T >
Sylvester<T>::~Sylvester(){

    for (int i = 0; i < this->grammes; ++i) {
        delete[] this->table[i];
    }
    delete[] this->table;
}


/* +++++++++++++++++++++++++++++++++++++++++++++++++++++
    Sto kommati ayto tha prepei kanonika na prokypsei enas pinakas megethous (sylvester_grammes,1) alla
    o sxediasmos exei ginei ws enas pinakas (sylvester_grammes,maxSthles) me tis maxSthles na antiprosopeyoun
    thn dynamh ths krymenhs metavlhths kai oi grammes tou pinaka ena athroisma apo dianysmata polyonymwn sthn
    krymmenh metavlhth
 */
template < typename T >
int ** Sylvester <T> :: multiply(Matrix<int> & v){

    int vGrammes = v.get_grammes();
    int sylv_grammes = this->get_grammes();						//grammes sylvester
    int maxSthles;
    if(m1sthles>m2sthles)
        maxSthles=m1sthles;
    else
        maxSthles=m2sthles;										//maxsthles=sthles tou S*v

    resultGrammes = sylv_grammes;
    resultSthles = maxSthles;

    int ** Sv = new int*[sylv_grammes];
    for (int i = 0; i < sylv_grammes; ++i)						//desmeyoume xwro gia to Sv
    {
        Sv[i]=new int[maxSthles];
        for (int j = 0; j < maxSthles; ++j)
        {
            Sv[i][j]=0;											//arxikopoihsh me 0
        }
    }
    for ( int x = 0; x < m2grammes-1; ++x)
    {
        for ( int m = 0; m < m1sthles; ++m)
        {
            for (int j = 0; j < sylv_grammes; ++j)
            {
                if(this->table[x][j]!=NULL)
                {
                    Sv[x][m]+=this->table[x][j][m] * v.get_int_element(j,0);		//pollaplasiasmos pinakawn
                }                               
            }
        
        }
    }
    for (int i = m2grammes-1; i <sylv_grammes ; ++i)
    {
        for (int n = 0; n < m2sthles; ++n)
        {
            for (int j = 0; j < sylv_grammes; ++j)
            {
                if(this->table[i][j]!=NULL)
                {
                    Sv[i][n]+=this->table[i][j][n] * v.get_int_element(j,0);       //pollaplasiasmos pinakawn
                }                               
            }          
        }
    }
    return Sv;											//enas pinakas [sylv_grammes][maxSthles]
}


template < typename T >
void Sylvester <T> :: make_Sylvester( Matrix<int> &m1, Matrix<int> & m2 ,int d0 , int d1) {

    m1grammes = m1.get_grammes();
    m2grammes = m2.get_grammes();
    m1sthles = m1.get_sthles();
    m2sthles = m2.get_sthles();

    /*
     * 1o orisma = pyknh anaparastash ths ekshswshs pou 8elw na apo8hkeusw
     * 2o orisma= grammh sthn opoia ksekina na topo8etountai oi syntelestes ths ktymenh metavlhts
     * 3o orisma = grammes tou m1
     */
    fill_first_row_of_sylvester(m1, 0, m1grammes );

    shift_rest_first_half(); // gemisei mexri th grammh d1-1

    //------------- 2h eksiswsh ------------------

    fill_first_row_of_sylvester(m2, m2grammes-1 , m2grammes ); // grafw sth grammh d1 mexri th sthlh d1+1->gia akeraious

    shift_rest_second_half();

    //------------------------------------

}

/*
	 * 1o orisma = pyknh anaparastash ths ekshswshs pou 8elw na apo8hkeusw
	 * 2o orisma= grammh sthn opoia ksekina na topo8etountai oi eksiswseis me th ktymenh metavlhts
	 * 3o orisma = grammes tou m1
*/
template <typename T>
void Sylvester<T>::fill_first_row_of_sylvester(Matrix<int> &m1, int first_row_pos, int dimension) {

    /*
     * to dimension0 mou leei oti diavazw mexri th grammh dimensio0 tou pinaka syntelestwn m1
     * kai apo8hkeuw mexri th sthlh dimesnison0 -1  tou sylvester
    */

    int j = 0;
    for (j = 0; j < dimension ; j++ )
    {
        this->table[first_row_pos][j] = m1.get_table_row(dimension-j-1);
    }
    for (int i = dimension ; i < this->sthles; ++i) {
        this->table[first_row_pos][i] = NULL;
    }

}

/*
*shift silvester
*/
template <typename T>
void Sylvester<T>::shift_rest_first_half() {

    for( int i  = 1 ; i < m2grammes-1  ; i++  ) {

        this->table[i][0] = NULL;										//prwth sthlh ths i grammh deixnei se NULL

        int j=1;
        while(j < this->sthles)
        {
            this->table[i][j]=this->table[i-1][j-1];					//shift kata mia thesi deksia
            j++;
        }
    }

}

template <typename T>
void Sylvester<T>::shift_rest_second_half() {

    for( int i  = m2grammes ; i < this->grammes  ; i++  ) {

        this->table[i][0] = NULL;									//prwth sthlh ths i grammh deixnei se NULL

        int j=1;
        while( j < this->sthles)
        {
            this->table[i][j]=this->table[i-1][j-1];				//shift kata mia thesi deksia
            j++;
        }
    }

}

template <typename T>
void Sylvester<T>::print_Table(){

    cout << "Sylvester needs a variable in order to print\n";

}

//Ektypwsh pinaka sylvester
template <typename T>
void Sylvester<T>::print_Table(char variable ) {

    for( int i = 0 ; i < this->grammes ; i++ )
    {
        for ( int j  = 0  ; j < this->sthles ; j ++)
        {
            if ( this->table[i][j] == NULL)
                cout << "0 ";
            else
            {
                cout << "( " << this->table[i][j][0] << " ";
                if( i < m2grammes-1 )
                {
                    for (int k = 1; k < m1sthles; ++k)
                    {
                        if( this->table[i][j][k] == 0) {
                            continue;
                        }

                        if (this->table[i][j][k] > 0)
                            cout << "+ " << this->table[i][j][k] << variable<< "^" << k << " ";
                        else
                            cout << this->table[i][j][k] <<variable << "^" << k << " ";

                    }
                }
                else
                {
                    for (int k = 1; k < m2sthles; ++k)
                    {
                        if( this->table[i][j][k] == 0) {
                            continue;
                        }

                        if (this->table[i][j][k] > 0 )
                            cout << "+" << this->table[i][j][k] << variable <<"^" << k << " ";
                        else
                            cout << this->table[i][j][k] << variable << "^" << k << " ";

                    }
                }

                cout << ") ";
            }
        }
        cout << endl;
    }
}

/*+++++++++++++++++++++++++++*/
template <typename T>
void Sylvester<T>::print_Table_bonus(int ** Sv){
	
	int maxSthles;
	
	cout << "[Sylvester * v] =="<< '\n';
	if(m1sthles>m2sthles)
		maxSthles=m1sthles;
	else
		maxSthles=m2sthles;

	for (int i = 0; i < this->grammes; ++i)
	{
		for (int j = 0; j < maxSthles; ++j)
		{
			cout << Sv[i][j]<< " ";
		}
		cout << '\n';
	}

}