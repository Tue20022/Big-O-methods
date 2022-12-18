//Matheus Vianna Nunes - EDII
#include "vetor.h"
#include <locale>

void menu(){
	cout << "\nMenu - Escolha opção:\n" <<endl;
	cout << "1 - Escolha o tamanho do vetor que será ordenado" << endl;
	cout << "Qualquer outra para sair\n";
	cout << "Opção: ";
}


int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	int n;
	Vetor v; 
	
	int op(0);
	do{
		menu();
		cin >> op;
		
		switch(op){
			case 1: 
				cout<<"Digite o tamanho do vetor: ";
				cin >> n;
				v.preencherVetor(n);//preenchendo o vetor
				/*v.imprimirVetor();//imprimindo */
<<<<<<< HEAD
				cout<< endl;
=======
				cout<< endl<<endl;
>>>>>>> 521f80b2b97cdb623b97c3aad14ef7ddf3a1ea66
				v.tempoBB(); //implementando bb_sort
				v.tempoInsert();
				v.tempoSel();
				v.tempoQuick();
				v.tempoShell();
<<<<<<< HEAD
				v.tempoMerge();
=======
				//v.tempoMerge();
>>>>>>> 521f80b2b97cdb623b97c3aad14ef7ddf3a1ea66
				v.tempoRadix();
				break;
			
			default: cout << "Opção de término de programa!\n";		
		}
	}while(op==1);
	
	cout << "Fim de programa!\n";
	system("pause");
	return 0;
}
