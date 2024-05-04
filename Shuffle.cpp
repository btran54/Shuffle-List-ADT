/***
* Brian Tran
* btran54
* 2024 Winter CSE101 PA5
* Shuffle.cpp
* Shuffle file containing the main execution of List.cpp functions.
***/ 

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include "List.h"

using namespace std;

#define MAX_LEN 300


void shuffle(List& D);

int main(int argc, char * argv[]){
	int max;
	int order = 0;
	List O;
	List D;

	if(argc != 2){
		cerr << "Usage: " << argv[0] << " <max # of cards to shuffle>" << endl;
		return(EXIT_FAILURE);
	}

	max = atoi (argv[1]);
	cout << "deck size" << setw(20) << " shuffle count" << endl;
	cout << "------------------------------" << endl;

	for (int i = 1; i <= max; i++){
		D.insertBefore(i - 1);
		List O = D;

		if(O.length() == 1){
			order++;
		}

		else if (O.length() > 1){
			shuffle(O);
			order++;
			while((O == D) != true){
			shuffle(O);
			order++;
			}
		}

		cout << i << setw(20) << order << endl;
		order = 0;
	}
}

void shuffle(List& D){
	List F;
	List S;
	List N;
	D.moveFront();
    
	for(int i = 1; i <= D.length() / 2; i++){
		F.insertBefore(D.moveNext());
	}
	F.moveFront();

	for(int i = D.position(); i <= D.length() - 1; i++){
		S.insertBefore(D.moveNext());
	}
	S.moveFront();

	while (N.length() != D.length()){

		if(S.position() != S.length()){
			N.insertBefore(S.moveNext());
		}

		if(F.position() != F.length()){	
			N.insertBefore(F.moveNext());
		}
	}

	D = N;
}