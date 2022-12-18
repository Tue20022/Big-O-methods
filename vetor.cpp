#include "vetor.h"

Vetor::Vetor(){
	this->tamanho = 0;
	this->vet = (int*) malloc(this->tamanho * sizeof(int));
}

void Vetor::preencherVetor(int tamanho){
	this->tamanho = tamanho;
	this->vet = (int*) malloc(this->tamanho * sizeof(int));
	
	srand(time(0));
	
	  for (int i=0; i < this->tamanho; i++)
    {
        this->vet[i] = rand()%1000;
    }
}

void Vetor::imprimirVetor(){
	cout<<endl;
	printf("[");
	for (int i = 0; i < this->tamanho; i++)
	{
		printf(" %d -", this->vet[i]);
	}
	printf(" ]");
	
}

void Vetor::bubbleSort(){
    int k, j, aux;
	int* vetorAux = (int*) malloc(this->tamanho * sizeof(int));
	 
	for (int i=0; i < this->tamanho; i++){
        vetorAux[i] = this->vet[i];
    }
	
    for (k = 1; k < this->tamanho; k++) {
        for (j = 0; j < this->tamanho - 1; j++) {
            if (vetorAux[j] > vetorAux[j + 1]) {
                aux = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = aux;
            }
        }
    }
}

void Vetor::selectSort(){	
	int aux;
	int* vetorAux = (int*) malloc(this->tamanho * sizeof(int));
	 
	for (int i=0; i < this->tamanho; i++){
        vetorAux[i] = this->vet[i];
    }
	
	for(int i = 0; i < this->tamanho - 1; i++){
		for(int j = i + 1; j < this->tamanho; j++){
			if(vetorAux[i] > vetorAux[j]){
				aux = vetorAux[i];
				vetorAux[i] = vetorAux[j];
				vetorAux[j] = aux;
			}
		}
	}
}

void Vetor::insertSort(){
	int* vetorAux = (int*) malloc(this->tamanho * sizeof(int));
	 
	for (int i=0; i < this->tamanho; i++){
        vetorAux[i] = this->vet[i];
    }
    
	for(int i = 1; i < this->tamanho; i++){
		int tmp = vetorAux[i];
		int j = i;
		while(j > 0 && tmp < vetorAux[j - 1])
		{
			vetorAux[j] = vetorAux[j - 1];
			j--;
		}
		vetorAux[j] = tmp;
	}
}

void Vetor::quickSort(int* vetorAux, int inicio, int fim){  // Não consegui resolver o problema de criar outro vetor para receber o vetor original // Por isso está dando problema de tempo
    int i, j; 
    int pivo, aux;
    i = inicio;
    j = fim - 1;
 
    pivo = vetorAux[(inicio + fim) / 2];
    while(i <= j){
        while(vetorAux[i] < pivo && i < fim)
            i++;

        while(vetorAux[j] > pivo && j > inicio)
            j--;

        if(i <= j){
            aux = vetorAux[i];
            vetorAux[i] = vetorAux[j];
            vetorAux[j] = aux;
            i++;
            j--;
        }
    }
    if(j > inicio)
        quickSort(vetorAux, inicio, j + 1);
    if(i < fim)
        quickSort(vetorAux, i, fim);
}

void Vetor::shellSort(){
	int* vetorAux = (int*) malloc(this->tamanho * sizeof(int));
	int h, i, j, t;
	
	for (int i=0; i < this->tamanho; i++){
        vetorAux[i] = this->vet[i];
    }
    
    for (h = this->tamanho; h /= 2;)
	{
        for (i = h; i < this->tamanho; i++)
		{
            t = vetorAux[i];
            for (j = i; j >= h && t < vetorAux[j - h]; j -= h)
			{
                vetorAux[j] = vetorAux[j - h];
            }
            
            vetorAux[j] = t;
        }
    }
}

void Vetor::mergeSort(int* vetor, int inicio, int fim, int* vetorAux){

    if ((fim - inicio) < 2) return;
    
    int meio = ((inicio + fim)/2);
    mergeSort(vetor, inicio, meio, vetorAux);
    mergeSort(vetor, meio, fim, vetorAux);
    juntar(vetor, inicio, meio, fim, vetorAux);    
}

void Vetor::juntar(int* vetor, int ini, int meio, int fim, int* vetAux){
    int esq = ini;
    int dir = meio;
    for (int i = ini; i < fim; ++i) {
        if ((esq < meio) and ((dir >= fim) or (vetor[esq] < vetor[dir]))) {
            vetAux[i] = vetor[esq];
            ++esq;
        }
        else {
            vetAux[i] = vetor[dir];
            ++dir;
        }
    }
    //copiando o vetor de volta
    for (int i = ini; i < fim; ++i) {
        vetor[i] = vetAux[i];
    }
}

void Vetor::radixSort(){
	int i, baseExponencial = 1, m = 0, bucket[tamanho], vetorAux[tamanho];
	int* vetAux = (int*) malloc(this->tamanho * sizeof(int));
	
	for (int i=0; i < this->tamanho; i++){
        vetAux[i] = this->vet[i];
    }
    

	for(i = 0; i < this->tamanho; i++) {
		if(vetAux[i] > m) {
			m = vetAux[i];
		}
	}

	while((m/baseExponencial) > 0)
	{
		for (i = 0; i < this->tamanho; i++)
		{
			bucket[i] = 0;
		}
		
		for(i = 0; i < this->tamanho; i++)
		{
			bucket[(vetAux[i] / baseExponencial) % 10]++;
		}
		
		for(i = 1; i < this->tamanho; i++)
		{
			bucket[i] += bucket[i-1];
		}
		
		for(i = (this->tamanho - 1); i >= 0; i--)
		{
			vetorAux[--bucket[(vetAux[i] / baseExponencial) % 10]] = vetAux[i];
		}
		
		for(i = 0; i < this->tamanho; i++)
		{
			vetAux[i] = vetorAux[i];
		}
		baseExponencial *= 10;
	}
}

void Vetor::tempoBB(){
    clock_t inicio = clock();

    bubbleSort();

    clock_t fim = clock();

    double t = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

<<<<<<< HEAD
    cout <<"\nBubbleSort - Tempo: " << t << " segundos" <<endl;
=======
    printf("\nBubbleSort - Tempo: %f segundos\n", t);
>>>>>>> 521f80b2b97cdb623b97c3aad14ef7ddf3a1ea66
}

void Vetor::tempoSel(){
    clock_t inicio = clock();

    selectSort();

    clock_t fim = clock();

    double t = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

<<<<<<< HEAD
    cout <<"\nSelectSort - Tempo: " << t << " segundos" <<endl;
=======
    printf("\nSelectSort - Tempo: %f segundos\n", t);
>>>>>>> 521f80b2b97cdb623b97c3aad14ef7ddf3a1ea66
}

void Vetor::tempoInsert(){
    clock_t inicio = clock();

    insertSort();

    clock_t fim = clock();

    double t = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

<<<<<<< HEAD
    cout <<"\nInsertSort - Tempo: " << t << " segundos" <<endl;
=======
    printf("\nInsertSort - Tempo: %f segundos\n", t);
>>>>>>> 521f80b2b97cdb623b97c3aad14ef7ddf3a1ea66
}


void Vetor::tempoQuick(){
	int* vetorAux = (int*) malloc(this->tamanho * sizeof(int));
	for (int p=0; p < this->tamanho; p++){
        vetorAux[p] = this->vet[p];
    }

    clock_t inicio = clock();

    quickSort(vetorAux, 0, this->tamanho);

    clock_t fim = clock();

    double t = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

<<<<<<< HEAD
    cout <<"\nQuickSort - Tempo: " << t << " segundos" <<endl;
=======
    printf("\nQuickSort - Tempo: %f segundos\n", t);
>>>>>>> 521f80b2b97cdb623b97c3aad14ef7ddf3a1ea66
}

void Vetor::tempoShell(){
    clock_t inicio = clock();

    shellSort();

    clock_t fim = clock();

    double t = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

<<<<<<< HEAD
    cout <<"\nShellSort - Tempo: " << t << " segundos" <<endl;
    
}

void Vetor::tempoMerge(){
	
	int* vetor1 = (int*) malloc(this->tamanho * sizeof(int));
	for (int p=0; p < this->tamanho; p++){
        vetor1[p] = this->vet[p];
    }
    
    int* vetor2 = (int*) malloc(this->tamanho * sizeof(int));
    
    clock_t inicio = clock();

    mergeSort(vetor1, 0, this->tamanho, vetor2);
=======
    printf("\nShellSort - Tempo: %f segundos\n", t);
}

/*void Vetor::tempoMerge(){
    clock_t inicio = clock();

    mergeSort();
>>>>>>> 521f80b2b97cdb623b97c3aad14ef7ddf3a1ea66

    clock_t fim = clock();

    double t = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

<<<<<<< HEAD
    cout <<"\nMergeSort - Tempo: " << t << " segundos" <<endl << endl;
}
=======
    printf("\nBubbleSort - Tempo: %f segundos\n", t);
}*/
>>>>>>> 521f80b2b97cdb623b97c3aad14ef7ddf3a1ea66

void Vetor::tempoRadix(){
    clock_t inicio = clock();

    radixSort();

    clock_t fim = clock();

    double t = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

<<<<<<< HEAD
    cout <<"\RadixSort - Tempo: " << t << " segundos" <<endl;
=======
    printf("\nRadixSort - Tempo: %f segundos\n", t);
>>>>>>> 521f80b2b97cdb623b97c3aad14ef7ddf3a1ea66
}
