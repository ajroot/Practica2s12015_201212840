#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

enum {IZQUIERDO, DERECHO};


typedef struct _nodo {
   int dato;
   int FE;
   struct _nodo *derecho;
   struct _nodo *izquierdo;
   struct _nodo *padre;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;
/*********Declarando funciones de arbol***************************/
void Insertar(Arbol *a, int dat);
void Borrar(Arbol *a, int dat);
int Buscar(Arbol a, int dat);
int Vacio(Arbol r);
int EsHoja(pNodo r);
int NumeroNodos(Arbol a, int* c);
int AlturaArbol(Arbol a, int* altura);
int Altura(Arbol a, int dat);
void InOrden(Arbol, void (*func)(int*));
void PreOrden(Arbol, void (*func)(int*));
void PostOrden(Arbol, void (*func)(int*));
void Equilibrar(Arbol *raiz, pNodo nodo, int, int);
void RSI(Arbol *raiz, pNodo nodo);
void RSD(Arbol *raiz, pNodo nodo);
void RDI(Arbol *raiz, pNodo nodo);
void RDD(Arbol *raiz, pNodo nodo);
void Podar(Arbol *a);
void auxContador(Arbol a, int*);
void auxAltura(Arbol a, int, int*);
void Mostrar(int *d);
/*****************************************************************/
/*********************Declarando metodos ListaDoble************************/
void insertarInicio(int value);
void insertarFin(int value);
int insertarDentro(int value, int loc);
int eliminarFinal();
int eliminarEnmedio(int value);
void ordenarQuick();
void mostrarInicio();
void mostrarFin();
/***************************************************************************/
float tiempoCargaArbol;
float tiempoRecorrido;
float tiempoRecorridoLista;
float tiempoCargaLista;
float tiempoOrdenQuick;
float tiempoOrdenBurbuja;
int tamanoL;

int main()
{
   Arbol ArbolInt=NULL;
   int altura;
   int nnodos;
   int cargo=0;
   int opcion;
		char palabra[100];
	system("clear");
	url:
	printf("***********************************************\n");
	printf("Ingresa la ruta de tu archivo: \n");
	scanf("%s",palabra); 
	int numero;
	FILE *fp;
	fp = fopen ( palabra, "r" );        
	if (fp==NULL) 
	{
		fputs ("Tu archivo no pudo ser cargado,\n verificar archivo y/o direccion.\n",stderr); 
		goto url;		
		//exit (1);
	}
	else
	{
		char caracter[100];
		while (feof(fp) == 0)
		{
			fgets(caracter,100,fp);
			numero=atoi(caracter);
			Insertar(&ArbolInt, numero);
			//insertarInicio(numero);
			insertarFin(numero);
			//printf("%s",caracter);
		}
		/*printf("\u2714 Carga exitosa.");*/
		cargo=1;
		printf("Se cargó correctamente el archivo\n");
	}
	menu:
	system("clear");
	if(cargo==1)
	{

		printf("***********************************************\n");
		printf("***** Se cargó correctamente el archivo *******\n");
		printf("**** Selecciona la acción que utilizaras ****** \n");
		printf("**                                           **\n");
		printf("**       1.Mostrar tiempos de carga          ** \n");
		printf("**       2.Mostrar Recorrido Arbol           **\n");
		printf("**       3.Mostrar Recorrido Lista Doble     **\n");
		printf("**       4.Mostrar Graficas                  **\n");
		printf("**       5.Ordenar Por QuicSort              **\n");
		printf("**       6.Ordenar por Burbuja               **\n");
		printf("**       0. salir                            **\n");
		printf("**                                           **\n");
		printf("***********************************************\n");
		printf("***********************************************\n");
		scanf("%d",&opcion); 
		
	}
	switch(opcion)
	{
		case 0:/***salir****/
			system("clear");
			printf("¿Seguro que quiere salir?\n");
			printf("      1.Si\n");
			printf("      2.No\n");	
			scanf("%d",&opcion); 
			if(opcion==1)
			{
				system("clear");
				printf("ADIOS\n");
			}
			else
			{
				goto menu;
			}
			
		break;
		case 1:/***Mostrar Gracias***/
				 system("clear");
				 printf("***Arbol\n");
				 printf("\t->Tiempo transcurrido: %f",tiempoCargaArbol,"\n");
				 printf("\n***Lista\n");
				 printf("\t->Tiempo transcurrido: %f",tiempoCargaLista,"\n");
   				 printf("\n\n\n\n*************************************************\n");
				 printf("¿Regresar a la Aplicacion?\n");
								printf("      1.Si\n");
								printf("      2.No\n");	
								scanf("%d",&opcion); 
				if(opcion==1)
							{
								goto menu;
							}
							else
							{
								system("clear");
								printf("ADIOS\n");
							}
		break;
		case 2:/***Mostrar Recorrido Arbol****/
			system("clear");
			printf("***Recorrido en orden del Arbol\n\t");
			clock_t startA = clock(); 
			InOrden(ArbolInt, Mostrar);
				tiempoRecorrido=(double)clock() - startA / CLOCKS_PER_SEC;
			 printf("\n***Tiempo Recorrido en Orden\n");
				 printf("\t->Tiempo transcurrido: %f",tiempoRecorrido,"\n");
				 printf("\n\n\n\n¿Regresar a la Aplicacion?\n");
								printf("      1.Si\n");
								printf("      2.No\n");	
								scanf("%d",&opcion); 
				if(opcion==1)
							{
								goto menu;
							}
							else
							{
								system("clear");
								printf("ADIOS\n");
							}
		break;
		case 3:/**Mostrar Recorrido lista Doble****/
			system("clear");
			printf("***Recorrido de lista Doble\n\t");
			clock_t startl = clock(); 
			mostrarInicio();
				tiempoRecorridoLista=(double)clock() - startl / CLOCKS_PER_SEC;
			 printf("\n***Tiempo Recorrido en Orden\n");
				 printf("\t->Tiempo transcurrido: %f",tiempoRecorridoLista,"\n");
				 printf("\n\n\n\n¿Regresar a la Aplicacion?\n");
								printf("      1.Si\n");
								printf("      2.No\n");	
								scanf("%d",&opcion); 
				if(opcion==1)
							{
								goto menu;
							}
							else
							{
								system("clear");
								printf("ADIOS\n");
							}
		break;
		case 4:/***Ordenar QuickSort***/
		break;
		case 5:/**Ordenar Burbuja***/
		break;
		case 6:/**Mostrar tiempo de Ordenado*/
		break;
	}
	
	fclose(fp);   

   return 0;
}

/*************************Metodos de arbol AVL****************************************/
void Podar(Arbol *a)
{
   if(*a) {
      Podar(&(*a)->izquierdo);
      Podar(&(*a)->derecho);  
      free(*a);              
      *a = NULL;
   }
}

void Insertar(Arbol *a, int dat)
{
   clock_t start = clock(); 
   pNodo padre = NULL;
   pNodo actual = *a;

   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat < actual->dato) actual = actual->izquierdo;
      else if(dat > actual->dato) actual = actual->derecho;
   }

   if(!Vacio(actual)) return;
   if(Vacio(padre)) {
      *a = (Arbol)malloc(sizeof(tipoNodo));
      (*a)->dato = dat;
      (*a)->izquierdo = (*a)->derecho = NULL;
      (*a)->padre = NULL;
      (*a)->FE = 0;
   }
   else if(dat < padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->izquierdo = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
      actual->padre = padre;
      actual->FE = 0;
      Equilibrar(a, padre, IZQUIERDO, TRUE);
   }

   else if(dat > padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->derecho = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
      actual->padre = padre;
      actual->FE = 0;
      Equilibrar(a, padre, DERECHO, TRUE);
  }
	tiempoCargaArbol=(double)clock() - start / CLOCKS_PER_SEC;
}

void Equilibrar(Arbol *a, pNodo nodo, int rama, int nuevo)
{
   int salir = FALSE;

   while(nodo && !salir) {
      if(nuevo)
         if(rama == IZQUIERDO) nodo->FE--;
         else                  nodo->FE++;
      else
         if(rama == IZQUIERDO) nodo->FE++;
         else                  nodo->FE--;
      if(nodo->FE == 0) salir = TRUE; 
      else if(nodo->FE == -2) { 
         if(nodo->izquierdo->FE == 1) RDD(a, nodo); 
         else RSD(a, nodo);                         
         salir = TRUE;
      }
      else if(nodo->FE == 2) {  
         if(nodo->derecho->FE == -1) RDI(a, nodo); 
         else RSI(a, nodo);                        
         salir = TRUE;
      }
      if(nodo->padre)
         if(nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
      nodo = nodo->padre;
   }
}

void RDD(Arbol *raiz, Arbol nodo)
{
   pNodo Padre = nodo->padre;
   pNodo P = nodo;
   pNodo Q = P->izquierdo;
   pNodo R = Q->derecho;
   pNodo B = R->izquierdo;
   pNodo C = R->derecho;

   if(Padre)
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else *raiz = R;

   Q->derecho = B;
   P->izquierdo = C;
   R->izquierdo = Q;
   R->derecho = P;

   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = Q;
   if(C) C->padre = P;

   switch(R->FE) {
      case -1: Q->FE = 0; P->FE = 1; break;
      case 0:  Q->FE = 0; P->FE = 0; break;
      case 1:  Q->FE = -1; P->FE = 0; break;
   }
   R->FE = 0;
}


void RDI(Arbol *a, pNodo nodo)
{
   pNodo Padre = nodo->padre;
   pNodo P = nodo;
   pNodo Q = P->derecho;
   pNodo R = Q->izquierdo;
   pNodo B = R->izquierdo;
   pNodo C = R->derecho;

   if(Padre)
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else *a = R;

   P->derecho = B;
   Q->izquierdo = C;
   R->izquierdo = P;
   R->derecho = Q;

   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = P;
   if(C) C->padre = Q;

   switch(R->FE) {
      case -1: P->FE = 0; Q->FE = 1; break;
      case 0:  P->FE = 0; Q->FE = 0; break;
      case 1:  P->FE = -1; Q->FE = 0; break;
   }
   R->FE = 0;
}

void RSD(Arbol *a, pNodo nodo)
{
   pNodo Padre = nodo->padre;
   pNodo P = nodo;
   pNodo Q = P->izquierdo;
   pNodo B = Q->derecho;

   if(Padre)
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else *a = Q;


   P->izquierdo = B;
   Q->derecho = P;

   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;

   P->FE = 0;
   Q->FE = 0;
}

void RSI(Arbol *a, pNodo nodo)
{
   pNodo Padre = nodo->padre;
   pNodo P = nodo;
   pNodo Q = P->derecho;
   pNodo B = Q->izquierdo;

   if(Padre)
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else *a = Q;

   P->derecho = B;
   Q->izquierdo = P;

   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;

   P->FE = 0;
   Q->FE = 0;
}

void Borrar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual;
   pNodo nodo;
   int aux;

   actual = *a;
   while(!Vacio(actual)) {
      if(dat == actual->dato) { 
         if(EsHoja(actual)) { 
            if(padre) 
               
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            free(actual);
            actual = NULL;
            if((padre->derecho == actual && padre->FE == 1) ||
               (padre->izquierdo == actual && padre->FE == -1)) {
               padre->FE = 0;
               actual = padre;
               padre = actual->padre;
            }
            if(padre)
               if(padre->derecho == actual) Equilibrar(a, padre, DERECHO, FALSE);
               else                         Equilibrar(a, padre, IZQUIERDO, FALSE);
            return;
         }
         else { 
            padre = actual;
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else { 
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
}

void InOrden(Arbol a, void (*func)(int*))
{
   if(a->izquierdo) InOrden(a->izquierdo, func);
   func(&(a->dato));
   if(a->derecho) InOrden(a->derecho, func);
}


void PreOrden(Arbol a, void (*func)(int*))
{
   func(&a->dato);
   if(a->izquierdo) PreOrden(a->izquierdo, func);
   if(a->derecho) PreOrden(a->derecho, func);
}


void PostOrden(Arbol a, void (*func)(int*))
{
   if(a->izquierdo) PostOrden(a->izquierdo, func);
   if(a->derecho) PostOrden(a->derecho, func);
   func(&a->dato);
}

int Buscar(Arbol a, int dat)
{
   pNodo actual = a;
   while(!Vacio(actual)) {
      if(dat == actual->dato) return TRUE; 
      else if(dat < actual->dato) actual = actual->izquierdo; 
      else if(dat > actual->dato) actual = actual->derecho;
   }
   return FALSE; 
}

int Altura(Arbol a, int dat)
{
   int altura = 0;
   pNodo actual = a;

   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura;
      else {
         altura++; 
         if(dat < actual->dato) actual = actual->izquierdo;
         else if(dat > actual->dato) actual = actual->derecho;
      }
   }
   return -1; 
}


int NumeroNodos(Arbol a, int *contador)
{
   *contador = 0;

   auxContador(a, contador);
   return *contador;
}


void auxContador(Arbol nodo, int *c)
{
   (*c)++;
   if(nodo->izquierdo) auxContador(nodo->izquierdo, c);
   if(nodo->derecho)   auxContador(nodo->derecho, c);
}

int AlturaArbol(Arbol a, int *altura)
{
   *altura = 0;

   auxAltura(a, 0, altura); 
   return *altura;
}

void auxAltura(pNodo nodo, int a, int *altura)
{
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1, altura);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1, altura);
   if(EsHoja(nodo) && a > *altura) *altura = a;
}

int Vacio(Arbol r)
{
   return r==NULL;
}


int EsHoja(pNodo r)
{
   return !r->derecho && !r->izquierdo;
}


void Mostrar(int *d)
{
   printf("%d, ", *d);
}
/*****************************************FIN DE METODOS ARBOL*******************************************/

/****************************************INICIO METODOS LISTA DOBLE**************************************/
#include <stdio.h>
//#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

struct nodo
{
	struct nodo *anterior;
	int dato;
	struct nodo *siguiente;
}*primero, *ultimo;

void insertarInicio(int value)
{
	struct nodo *var, *temp;
	var=(struct nodo *)malloc (sizeof(struct nodo));
	var->dato=value;
	if (primero==NULL)
	{
		primero=var;
		primero->anterior=NULL;
		primero->siguiente=NULL;
		ultimo=primero;
	}
	else
	{
		temp=var;
		temp->anterior=NULL;
		temp->siguiente=primero;
		primero->anterior=temp;
		primero=temp;
	}
}

void insertarFin(int value)
{
   clock_t start = clock(); 
	struct nodo *var,*temp;
	var=(struct nodo *)malloc(sizeof(struct nodo));
		var->dato=value;
	if(primero==NULL)
	{
		primero=var;
		primero->anterior=NULL;
		primero->siguiente=NULL;
		ultimo=primero;
	}
	else
	{
		ultimo=primero;
		while(ultimo!=NULL)
		{
			temp=ultimo;
			ultimo=ultimo->siguiente;
		}
		ultimo=var;
		temp->siguiente=ultimo;
		ultimo->anterior=temp;
		ultimo->siguiente=NULL;		
	}
	tiempoCargaLista=(double)clock() - start / CLOCKS_PER_SEC;
}

int insertarDentro(int value, int loc)
{
	struct nodo *temp,*var,*temp1;
	var=(struct nodo *)malloc(sizeof(struct nodo));
	var->dato=value;
	if(primero==NULL)
	{
		primero=var;
		primero->anterior=NULL;
		primero->siguiente=NULL;
	}
	else
	{
		temp=primero;
		while(temp!=NULL && temp->dato !=loc)
		{
			temp=temp->siguiente;
		}
		if(temp!=NULL)
		{
			temp1=temp->siguiente;
			temp->siguiente=var;
			var->anterior=temp;
			var->siguiente=temp1;
			temp1->anterior=var;
		}
	}
	ultimo=primero;
	while(ultimo->siguiente!=NULL)
	{
		ultimo=ultimo->siguiente;
	}
}
int eliminarFinal()
{
	struct nodo *temp;
	temp=ultimo;
	if(temp->anterior==NULL)
	{
		free(temp);
		primero=NULL;
		ultimo=NULL;
		return 0;
	}
	ultimo=temp->anterior;
	ultimo->siguiente=NULL;
	free(temp);
	return 0;
}

int eliminarEnmedio(int value)
{
	struct nodo *temp, *var,*t,*temp1;
	temp=primero;
	while(temp!=NULL)
	{
		if(temp->dato==value)
		{
			if(temp->anterior==NULL)
			{
				free(temp);
				primero=NULL;
				ultimo=NULL;
				return 0;
			}
			else
			{
				var->siguiente=temp1;
				temp1->anterior=var;
				free(temp);
				return 0;
			}
		}
		else
		{	
			var=temp;
			temp=temp->siguiente;
			temp1=temp->siguiente;
		}		
	}
}

void ordenarQuick()
{

}

/* main()
{
	int b=1;
	while(b!=0)
	{
		printf("Ingrese numero");
		scanf("%d",&b);
		insertarInicio(b);
	}
	
	mostrarInicio();
	mostrarFin();
}*/

void mostrarInicio()
{
	struct nodo *temp;
	temp=primero;
	while(temp!=NULL)
	{
		printf("->%d",temp->dato);
		temp=temp->siguiente;
	}

}

void mostrarFin()
{
	struct nodo *temp;
	temp=ultimo;
	while(temp!=NULL)
	{
		printf("->%d",temp->dato);
		temp=temp->anterior;
	}

}
void tamanoLista()
{
	int numero;
	struct nodo *temp;
	temp=ultimo;
	while(temp!=NULL)
	{
		numero++;
		temp=temp->anterior;
	}
	tamanoL=numero;

}

