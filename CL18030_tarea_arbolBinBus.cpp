#include <iostream>
using namespace std;

struct nodo{
	int nro;
	struct nodo *izq, *der;	
};

typedef struct nodo *ABB; //alias a la estructura que construimos, arbol binario de busqueda.


class Abb{
	public:
		
ABB crearNodo(int x){
	ABB nuevoNodo = new(struct nodo); //reservamos el espacio en la memoria para el nuevo nodo
	nuevoNodo->nro = x;
	nuevoNodo->der = nuevoNodo->izq = NULL;
	return nuevoNodo;
}

void insertar(ABB &raiz, int x){
	if(!raiz){
		raiz = crearNodo(x);
		
	}
	else if(raiz->nro > x){
		insertar(raiz->izq,x);
	}
	else if(raiz->nro < x){
		insertar(raiz->der,x);
	}
}

void preOrden(ABB raiz){
	if(raiz){
		cout << raiz->nro << "\t";
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

void inOrden(ABB raiz){
	if(raiz){
		inOrden(raiz->izq);
		cout << raiz->nro << "\t";
		inOrden(raiz->der);
	}
}

void postOrden(ABB raiz){
	if(raiz){
		postOrden(raiz->izq);
		postOrden(raiz->der);
		cout << raiz->nro << "\t";
	}
}

void verArbol(ABB raiz, int n){
	if(!raiz){
		return;
	}
	verArbol(raiz->der,n+1);
	for(int i = 0; i < n; i++){ //espacios para darl eforma al arbol
		cout << " ";
	}
	cout << raiz->nro << endl;

	verArbol(raiz->izq, n+1);
	
}

void suma(ABB raiz,int &sum){
	if(raiz){
	suma(raiz->izq,sum);
	sum = sum + raiz->nro;
	suma(raiz->der,sum);
	}
}

//saca la altura 
int eshoja( struct nodo *hoja ){
	if( hoja->izq==NULL && hoja->der==NULL )
		return true;
	return false;
   }
   
int alturafull( struct nodo *hoja, int *altura ){
	auxaltura( hoja, altura, 1 );
	return *altura;
	}
	
void auxaltura( struct nodo *hoja, int *altura, int cont ){
	if( !hoja ) return;

	auxaltura( hoja->izq, altura, cont+1 );
	auxaltura( hoja->der, altura, cont+1 );
	if( (eshoja( hoja ) && cont)>*altura ) *altura= cont;
	if(cont > *altura) *altura = cont;
	}
//

void menur(ABB raiz){
	char op;
	cout << "1-Preorden\n2-Inorden\n3-Postorden\n->";
	cin >> op; 
	switch(op){
		case '1':
			preOrden(raiz);
			break;
		
		case '2':
			inOrden(raiz);
			break;
		
		case '3':
			postOrden(raiz);
			break;
	}
}

};

class Factory: public Abb{
			
	ABB arbol = NULL;
	int n, x , sum, altura;
	char op;
	
	public:
	Factory(){
	n = 0;
	sum = 0;
	while(true){
		cout << "El numero actual de nodos es de: " << n << endl;
		cout << "1-Ingresar un nodo\n2-Mostrar arbol\n3-Altura del arbol\n4-Menu de recorridos\n5-Salir\n->";
		cin>> op;	
		
	switch(op){
		case '1':
			cout << "Ingrese -1 para dejar de insertar nodos\n\n";
			while(x != (-1)){
				cout << "Ingrese el valor del nodo:";
				cin >> x;
				if(x != (-1)){	
					insertar(arbol,x);
					n++;	
				}
			}
			x = 0;
		break;
		
		case '2':
			cout << "El numero actual de nodos es de: " << n << endl;
			suma(arbol,sum);
			cout << "La suma de el valor de todos los nodos es de: " << sum << endl; sum = 0;
			verArbol(arbol,0); //hay que agregar lo de la suma total y lo del num de nodos
			break;
			
		case '3':
			altura = 0;
			cout << "\n\nLa Altura del Arbol es: " << alturafull( arbol, &altura ) << endl;
			altura = 0; 
			break;
		
		case '4':
			menur(arbol);
			break;
		
		case '5':
			exit(0);
	}
	system("pause");
	system("cls");	
	}
	}
};

int main(){
	Factory *fabric = new Factory();
	cout << "\n\n";
	system("pause");
	return 0;
} //Agregar todo a una clase

//ejercicio 8.3->
/* 
Determinar el numero de nodos en un arbol binario (En el menú principal, donde aparece las opciones de insertar, mostrar, recorridos(pre,in,post orden))
Sumar todas las claves de un árbol binario
Altura de un árbol binario
Determinar si el arbol binario es completo o no
Determinar si un árbol binario está lleno

arbol de expreión-> Almacena expresiones matematicas
arbol de busqueda->Tienen claves y valores ordenados de menor (izq) a mayor (der)


*/
