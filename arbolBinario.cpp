#include<iostream>

using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

void menu();
Nodo *crearNodo(int n);
void insertar(Nodo *&, int);
void mostrarArbol(Nodo *, int);

Nodo *arbol = NULL;

int main(){

menu();

return 0;
}

void menu(){
	
	int dato, opcion, contador = 0;
	do{
	
		cout<<"\t\t MENU..."<<endl;
		cout<<" 1. Insertar un nuevo nodo"<<endl;
		cout<<" 2. Mostar Arbol"<<endl;
		cout<<" 3.salir "<<endl;
		cout<<" Opcion: ";
		cin>>opcion;
	
		switch(opcion){
			case 1: 
				cout<<"Digite un numero ";
				cin>>dato;
				insertar(arbol , dato);
				cout<<"\n ";		
				break;
				
			case 2:
				cout<<"\nMostrando el Arbol: \n\n";
				mostrarArbol(arbol,contador);
				cout<<"\n";
				break;
		}
	}while(opcion != 3);
}




Nodo *crearNodo(int n){
	Nodo *nuevo = new Nodo();
	nuevo->dato = n;
	nuevo->der = NULL;	
	nuevo->izq = NULL;	
	
	return nuevo;
}

void insertar(Nodo *&arbol, int n){
	if(arbol == NULL){
		Nodo *nuevo = crearNodo(n);
		arbol = nuevo;		
	}
	else{
		int Raiz = arbol->dato;
		if(n < Raiz){
			insertar(arbol->izq,n);
		}
		else{
			insertar(arbol->der, n);
		}
	}

}

void mostrarArbol(Nodo *arbol, int contador){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der, contador+1);
		for(int i=0; i<contador;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq, contador+1);
	}
	
}
