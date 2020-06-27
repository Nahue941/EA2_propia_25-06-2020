/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
#include <stdlib.h>


/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/


int strcmp_(const char* s1, const char* s2)
{
    while (*s1 && *s1==*s2){
        s1++;
        s2++;
    }
    return * (char*)s1-* (char*)s2;
}

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

int buscarSubcadena(const char* cad1, const char* cad2)
{
    while(*cad1==*cad2 && *cad1){
        cad1++;
        cad2++;
    }
    return *cad2?0:1;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/
char* strcpy_(char *s1, const char *s2)
{
    char *aux=s1;
    while (*s2){
        *s1++ = *s2++;
        }
    *s1=*s2;
    return (char*)aux;
}

size_t strlen_(const char *cad)
{
    const char *p = cad;

    while (*cad)
        ++cad;

    return cad - p;
}

void mostrarMovim_MIO(const void *d, FILE *fp)
{
    const tMovi* m = d;
    fprintf(fp,"%s%10.2f\n", m->ctaCte, m->saldo);
}


int compararMovim_MIO(const void *d1, const void *d2)
{
    const char* s1 = d1,* s2 = d2;
    while (*s1 && *s1==*s2){
        s1++;
        s2++;
    }
    return *(char*)s1- *(char*)s2;
}



int esCtaCte002_MIO(const void *d)
{
    const tMovi* movim = d;
    const char* cad = movim->ctaCte;

    cad += (strlen_(cad) - 3);

    int ret = buscarSubcadena(cad,"002");

    return ret;
}


int acumularMoviSaldo_MIO(void **dest, unsigned *tamDest,
                      const void *ori, unsigned tamOri)
{
    tMovi* movDes = *dest;
    const tMovi* movimOri = ori;

    movDes->saldo += movimOri->saldo;

    return 1;
}


void mostrarTotal_MIO(const void *d, FILE *fp)
{
    const tMovi * m = d;
    fprintf(fp, " Total cliente:% 10.2f\n\n",m->saldo);
}


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


int eliminarMostrarYMostrarSubTot_MIO(tLista *p, FILE *fpPant,
                                      int comparar(const void *, const void *),
                                      int comparar2(const void *d),
                                      int acumular(void **, unsigned *,
                                                   const void *, unsigned),
                                      void mostrar(const void *, FILE *),
                                      void mostrar2(const void *, FILE *))
{
    int cont=0;//cantidad eliminados
    while (*p){
        tMovi totalCuenta;
        tMovi* pM = &totalCuenta;
        char cadAux[16];

        if (comparar2((*p)->info)){

            fprintf(fpPant,"Nro Cuenta Banc   Importe\n");
            totalCuenta.saldo=0;
            strcpy_(cadAux, (*p)->info);

            while (*p && comparar2((*p)->info) && (comparar((*p)->info, cadAux))==0){//Mientras que la cuenta sea 2 y no haya cambiado de cuenta

                acumular((void*)&pM, (unsigned*)sizeof(tMovi), (*p)->info, sizeof(tMovi));
                mostrar((*p)->info, fpPant);

                tNodo* elim = *p;
                *p = elim->sig;
                free(elim->info);
                free(elim);
                cont++;
            }
            mostrar2(&totalCuenta, fpPant);
        }
        else
            p = &(*p)->sig;
    }
    return cont;
}


int  vaciarListaYMostrar_MIO(tLista *p,
                             void (*mostrar)(const void *, FILE *), FILE *fp)
{
    int k = 0;//k cant
    while(*p){
        tNodo* aux = *p;

        k++;
        *p = aux->sig;
        if(mostrar && fp)
            mostrar(aux->info, fp);

        free(aux->info);
    }

    return k;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
