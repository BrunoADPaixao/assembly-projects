#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
#include "funcoes.h"


int main(int argc, char** argv)
{
	int *V, N;
	cout << floor((0+9)/2)<<endl;
	cout << "Insira o tamanho do vetor:"<<endl;
	cin >> N;
	V = (int*) malloc(N * sizeof(int));
	initializeVector(V, N);
	V = fillVector(V, N);
	
	// bubbleSort(V, N);
	// cout << "Bubble Sort: " <<endl;
	// printVector(V, N);
	// insertionSort(V, N);
	// cout << "Insertion Sort: " <<endl;
	// printVector(V, N);
	// selectionSort(V, N);
	// cout << "Selection Sort: " <<endl;
	// printVector(V, N);

	mergeSort(V, 1, N);
	cout << "Selection Sort: " <<endl;
	printVector(V, N);	return 0;
}