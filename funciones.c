/**//* 22.333.444-PEREZ_DEL_RIO,JuanManuel-(07-2299) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
#define FALSE 0
#define TRUE 1


/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/



/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/
/**
void mostrarMovim_MIO(const void *d, FILE *fp)
{

}
 **/
/**
int compararMovim_MIO(const void *d1, const void *d2)
{

}
 **/
/**
int esCtaCte002_MIO(const void *d)
{

}
 **/
/**
int acumularMoviSaldo_MIO(void **dest, unsigned *tamDest,
                      const void *ori, unsigned tamOri)
{

}
 **/
/**
void mostrarTotal_MIO(const void *d, FILE *fp)
{

}
 **/

/**//* para el TDA LISTA                                                  *//**/
/**
int mostrarLista_MIO(const tLista *p,
                     void (*mostrar)(const void *, FILE *), FILE *fp)
{

}
 **/

void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    tLista* first=p;//Se guarda la primera posicion de la lista.
    tLista* aux=p;

    if(!*p)
        return;

    while((*p)->sig){
        tNodo ** men = buscar_menor_nodo_lista(pl, comparar);

        //avanzar un nodo hasta antes del menor.
        while((*aux)->sig != men){
            aux=&(*aux)->sig;
        }
        //puenteo el nodo a reubicar
        (*aux)->sig = (*men)->sig;
        //el siguiente del nodo a reubicar va a ser el "first"
        //condicion en la cual el primer nodo difiere del puntero actual.
        if(first != p)
            (*first)->sig = *men;

        *first = *men;
        //hacer funcion que enganche 3 nodos

				*listaOrdenada = menMov;
        (*men)->sig = *first;


        if(p != men)
        {
            reinsertar_nodo_menor(pl, men);
        }
        pl &(*p)->sig;
    }
    /**
    tLista* primero = p;
	tLista* listaOrdenada = p;
	tNodo* menMov;

	if(!*p)
		return;

	while((*primero)->sig){
		menMov = *primero;

			while(*p){

				if( (*p)->sig &&  comparar( menMov->info, (*p)->sig->info )>0 )
					menMov = *p;

				p = &(*p)->sig;
			}
			if(menMov != *primero){
				*p = menMov;
				menMov = menMov -> sig;
				(*p)->sig = menMov -> sig;
				menMov->sig = *primero;

				if(listaOrdenada != primero)
					(*listaOrdenada)->sig = menMov;

				*listaOrdenada = menMov;
			}
			else
				primero = &(*primero)->sig;

			p = &(*primero)->sig;
    }
    */
}

/**
int eliminarMostrarYMostrarSubTot_MIO(tLista *p, FILE *fpPant,
                                      int comparar(const void *, const void *),
                                      int comparar2(const void *d),
                                      int acumular(void **, unsigned *,
                                                   const void *, unsigned),
                                      void mostrar(const void *, FILE *),
                                      void mostrar2(const void *, FILE *))
{

}
 **/
/**
int  vaciarListaYMostrar_MIO(tLista *p,
                             void (*mostrar)(const void *, FILE *), FILE *fp)
{

}
 **/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

////////////////extras/////////////////////
//cad*
//
//int leerCadena (const char* cad, int* sucur, int* codCli, int* tipoCue, double* saldo)
//
//cad, sc
//leerCadena(Cad, &sucur1, &cli, )
//
//cli1==cli2;
//sucur1, sucur2


void reinsertar_nodo_menor(tLista * pl, tLista * men)
{
    tNodo * aux = *men;
    *men = aux->sig;
    aux->sig = *pl;
    *pl = aux;
}

tNodo ** buscar_menor_nodo_lista(const tLista * pl, int (*cmp)(const void*, const void*))
{
    const tLista * men = pl;
    if (!*pl)
    {
        return NULL;
    }
    pl=&(*pl)->sig;
    while(*pl)
    {
        if(cmp((*pl)->info, (*men)->info)<0)
        {
            men = pl;
        }
        pl=&(*pl)->sig;
    }
    return (tNodo **)men;
}

