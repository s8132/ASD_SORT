#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

const int size = 10000;

int tab[size];

void bubbleSort(){
	int tmp;
	for(int i=size-1; i>0; i--){
		for(int j=0; j<size-1; j++){
			if(tab[j]>tab[j+1]){
				tmp = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = tmp;
			}
		}
	}
}

int main(int argc, char* args[]){

	

	srand(time(NULL));

	for(int i=0; i<size; i++){
		tab[i] = rand()%100;
	}

	srand( time( 0 ) );
	
    clock_t start1 = clock();

	bubbleSort();

	cout << "Czas wykonania: " << int((clock() - start1 ) * CLOCKS_PER_SEC / 1000) << " ms";

	getch();
	return 0;
}

