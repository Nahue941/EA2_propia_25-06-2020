/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/


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



tNodo* buscar_menor_nodo_lista(tNodo* desde, int (*comparar)(const void*, const void*))
{
    tNodo* menor = desde;
    tNodo* p = desde->sig;

    while(p)
    {
        if(comparar(p->info, menor->info) < 0)
            menor = p;

        p = p->sig; ///LO AVANZO AL SIGUIENTE.
    }

    return menor;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarMovim_MIO(const void *d, FILE *fp)
{
    const tMovi* movim = d;
    fprintf(fp, "%s%10.2f\n", movim->ctaCte, movim->saldo);
}


int compararMovim_MIO(const void *d1, const void *d2)
{

}

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

int mostrarLista_MIO(const tLista *p,
                     void (*mostrar)(const void *, FILE *), FILE *fp)
{
    fprintf(fp,"Nro Cuenta Banc   Importe\n");
    int k = 0;//cantidad de items mostrados, k items
    while(*p){
        mostrar((*p)->info, fp);
        p = &(*p)->sig;
        k++;
    }
    return k;
}


void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    tLista *first = p;//guardo la posicion de la lista, es el que recorre la lista de manera ordenada

    if(!*p)
        return;

    while((*p)->sig){

        tNodo * men = buscar_menor_nodo_lista(*p, comparar);//devuelve p en la primer posicion

        if(*p == men){//p es igual al menor, por ende debo avanzarlo.
            first=&(*first)->sig;
            p=&(*p)->sig;
        }
        else{//quiere decir que p no es el menor, por ende no debo avanzarlo
            tLista *aux = p;
            while((*aux)->sig != men)//Avanzo aux hasta el anterior al menor
                aux=&(*aux)->sig;

            (*aux)->sig = men->sig;//puenteo el menor
            men->sig = *p;//engancho el menor al principio
            if(first == p){//primera vez, quiere decir que no se habia movido
                *first = men;
            }
            else{
                (*first)->sig = men;
                first= &(*first)->sig;
            }
        }
    }
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




