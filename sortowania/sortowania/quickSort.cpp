#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

const int size = 10000;

int tab[size];

void quickSort(int i_p, int i_k){
	
	int i, j, tmp;

  i = (i_p + i_k) / 2;

  tmp = tab[i]; tab[i] = tab[i_k];
  
  for(j = i = i_p; i < i_k; i++)
	if(tab[i] < tmp)
	{
		swap(tab[i], tab[j]);
		j++;
	}

	tab[i_k] = tab[j]; 
	tab[j] = tmp;

	if(i_p < j - 1)  quickSort(i_p, j - 1);
	if(j + 1 < i_k) quickSort(j + 1, i_k);
}

int main(int argc, char* args[]){


	srand(time(NULL));

	for(int i=0; i<size; i++){
		tab[i] = rand()%100;
	}

	srand( time( 0 ) );

    clock_t start1 = clock();
	
	quickSort(0, size-1);

	cout << "Czas wykonania: " << int((clock() - start1 ) * CLOCKS_PER_SEC / 1000) << " ms";

	getch();
	return 0;
}