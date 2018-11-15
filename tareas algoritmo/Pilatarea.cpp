#include <iostream>
using namespace std;
 
struct Nodo{
    int Info;
    struct Nodo *sgte;
};
 
typedef Nodo *ptrPila; 
  

void Apilar( ptrPila &pila, int valor ) //push
{    
     ptrPila NuevoNodo;
     NuevoNodo = new(struct Nodo); 
     NuevoNodo->Info = valor;
     NuevoNodo->sgte = pila ;
     pila = NuevoNodo ;
     
     cout<<"\n elemento "<<valor<<"apilado correctamente \n";
  
}
 
int Desapilar( ptrPila &pila ) //pop
{
     int num ;
     ptrPila aux;
     
     aux = pila ;
     num = aux->Info;   
     
    // pila=pila->sgte;
     pila = aux->sgte ;
     delete(aux);

     return num;
     
}
 
void mostrar_pila( ptrPila &pila )
{
     ptrPila aux;
     aux = pila;    
     
     while( aux !=NULL )
     {
            cout<<"\t"<< aux->Info <<endl;
            aux = aux->sgte;
     }    
}
 
void destruir_pila( ptrPila &pila)
{
     ptrPila aux;
     
     while( pila != NULL)
     {
           aux = pila;
           pila = pila->sgte;
           //pila = aux->sgte;
           delete(aux);
     }
}
 
 void elim_dado(Nodo *pila){
 	
 	int elim;
	 ptrPila recorrer= pila;
	 ptrPila aux,anterior=NULL;
	 
	 cout<<"coloque numero a eliminar : ";cin>>elim;
	 while(recorrer!=NULL){
	 	
	 	
	 	if(recorrer->Info==elim){
	 		
			 anterior->sgte=recorrer->sgte;
	 		
		 }
	 	anterior=recorrer;
	 	recorrer=recorrer->sgte;
	 }}
 	
 	
 	
 	void elim_pares(Nodo *&pila){
 		ptrPila recorrer;
 		recorrer=pila;
 		ptrPila aux;
 		ptrPila pila2=NULL,pila3=NULL;
 		while(recorrer!=NULL){	
 			if(recorrer->Info%2!=0){
 				
 		ptrPila nuevo_nodo=new (struct Nodo);
 				nuevo_nodo->Info=recorrer->Info;
 				nuevo_nodo->sgte=pila2;
 				pila2=nuevo_nodo;
 		 }
 		recorrer=recorrer->sgte;
		 }
 		destruir_pila(pila);
 		aux=pila2;
 		while(aux!=NULL){
 			ptrPila otro=new (struct Nodo);
 			otro->Info=aux->Info;
			otro->sgte=pila3;
 			pila3=otro;
 			aux=aux->sgte;
		 }
 		pila=pila3;	
	 }
 	
 	
 	
 	void voltear(Nodo *&pila){
 		ptrPila pila2=NULL;
 		ptrPila aux;
 		
 		aux=pila;
 		while(aux!=NULL){
 			
 			ptrPila nuevo_nodo=new (struct Nodo);
 			nuevo_nodo->Info=aux->Info;
 			nuevo_nodo->sgte=pila2;
 			pila2=nuevo_nodo;
 			aux=aux->sgte;
		 }
 		pila=pila2;	
	 }
 	
 	void factorial(Nodo *&pila){
 		ptrPila aux;
 		aux=pila;
 		if(aux == NULL){
 			return;
		 }
 		cout<<"| "<<aux->Info<<" |"<<endl;
 		factorial(aux->sgte);
 		
	 }
 	
 	void hanoi(int num,char A,char C,char B)
{
    if(num==1)
    {
            cout<<"Mueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
             
    }
    else
    {
        hanoi(num-1,A,B,C);
        cout<<"Mueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
        hanoi(num-1,B,C,A);
    }
}
 	
 	
 	
 	
 	
 
 
void menu()
{
    cout<<"\n\t IMPLEMENTACION DE PILAS EN C++\n";
    cout<<" 1. APILAR ";
    cout<<" 2. DESAPILAR ";
    cout<<" 3. MOSTRAR PILA ";
    cout<<" 4. DESTRUIR PILA ";
    cout<<" 5. ELIMINAR ELEMENTO DADO :";
    cout<<" 6. ELIMINAR NUMERO PARES :";
    cout<<" 7. INVERTIR PILA :";
    cout<<" 8. RECURSIVIDAD :";
	cout<<" 9. TORRE HAMOI :";
	cout<<" 10. SALIR :";
 }
 
int main()
{
    ptrPila pila = NULL; 
    int dato;
    int op;
    int elementoDesapilado ; 
   
    do
    {
        menu();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n NUMERO A APILAR: "; cin>> dato;
                 Apilar( pila, dato );
                 mostrar_pila( pila );
            break;
 
 
            case 2:
 				if(pila!=NULL){
 					elementoDesapilado = Desapilar( pila );    
     				cout<<"\n ELEMENTO DESAPILADO \t:"<<elementoDesapilado<<endl<<endl;
  			      	mostrar_pila( pila );
				 }
 				
                 else {
                 	if(pila==NULL)
                 cout<<"\n LA PILA ESTA VACIA"<<endl;
				 }
                 
            break;
                 
 
            case 3:
 
                 cout << "\n\n MOSTRANDO PILA\n\n";
                 if(pila!=NULL)
                    mostrar_pila( pila );
                 else
                    cout<<"\n\n\tPila vacia..!"<<endl;
            break;
 
 
            case 4:
 
                 destruir_pila( pila );
                 cout<<"\n\n\t\tPila eliminada...\n\n";
            break;
            case 5:
            	elim_dado(pila);
            	break;
             case 6:
             	elim_pares(pila);
             	break;
			case 7:
			voltear(pila);
			break;       
			case 8:
				factorial(pila);
				break;    
			case 9:
				int n;
        char A,B,C;
 
        cout<<"Los torres son A B C\n";
        cout<<"Numero de discos: ";
        cin>>n;
        hanoi(n,'A','C','B');
         }
 
        cout<<endl<<endl;
 
    }while(op!=10);
  
    return 0;
}
