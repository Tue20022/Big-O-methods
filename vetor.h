#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <iostream>
 
using namespace std;

class Vetor{
	public:
			int tamanho;
			int* vet;	
	public:
			Vetor();	//construtor vazio
			void preencherVetor(int tamanho);
			void imprimirVetor();
			void bubbleSort();
			void selectSort();
			void insertSort();
			void quickSort(int* vetorAux, int inicio, int fim);
            void shellSort();
<<<<<<< HEAD
            void mergeSort(int* vetor, int inicio, int fim, int* vetorAux);
            void juntar(int* vetor, int ini, int meio, int fim, int* vetAux);
=======
            /*void mergeSort(int vetor, int l, int r);
            void intercalar(int* vetor, int l, int m, int r);*/
>>>>>>> 521f80b2b97cdb623b97c3aad14ef7ddf3a1ea66
            void radixSort();
            void tempoBB();
            void tempoSel();
            void tempoInsert();
            void tempoQuick();
            void tempoShell();
<<<<<<< HEAD
            void tempoMerge();
=======
            /*void tempoMerge();*/
>>>>>>> 521f80b2b97cdb623b97c3aad14ef7ddf3a1ea66
            void tempoRadix();
};
