#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

const int size = 10000;

int tab[size], tabtmp[size];

void mergeSort(int i_p, int i_k){

	int i_s, i1, i2, i;
	
	i_s = (i_p + i_k + 1) / 2;
	
	if(i_s - i_p > 1) mergeSort(i_p, i_s - 1);
	if(i_k - i_s > 0) mergeSort(i_s, i_k);
	
	i1 = i_p; i2 = i_s;
	
	for(i = i_p; i <= i_k; i++){
		tabtmp[i] = ((i1 == i_s) || ((i2 <= i_k) && (tab[i1] > tab[i2]))) ? tab[i2++] : tab[i1++];

	}

	for(i = i_p; i <= i_k; i++) tab[i] = tabtmp[i];
}

int main(int argc, char* args[]){


	srand(time(NULL));

	for(int i=0; i<size; i++){
		tab[i] = rand()%100;
	}

	srand( time( 0 ) );

    clock_t start1 = clock();
	
	mergeSort(0, size-1);
	cout << "Czas wykonania: " << int((clock() - start1 ) * CLOCKS_PER_SEC / 1000) << " ms";

	getch();
	return 0;
}
