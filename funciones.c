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

tNodo* buscarMenorNodoLista(tNodo* desde, int (*comparar)(const void*, const void*))
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
    while(*cad1==*cad2 && *cad1){//Funcion reciclada de la EA pasada :D
        cad1++;
        cad2++;
    }
    return *cad2?0:1;
}

char* strcpy_(char *s1, const char *s2)
{
    char *aux=s1;
    while (*s2)
        *s1++ = *s2++;

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
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/
void mostrarMovim_MIO(const void *d, FILE *fp)
{
    const tMovi* m = d;
    if (!m)
         fprintf(fp,"Nro Cuenta Banc   Importe\n");
    else
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

    cad += (strlen_(cad) - 3);//Retrocedo 3 posiciones porque se que la cadena es fija. Y necesito saber si los ultimos 3 digitos son "002"

    int ret = buscarSubcadena(cad,"002");//Si la comparacion fue exitosa devuelve 1, si no 0

    return ret;//1 si la cuenta es "002", 0 si no
}


int acumularMoviSaldo_MIO(void **dest, unsigned *tamDest,
                      const void *ori, unsigned tamOri)
{
    tMovi **movDest = (tMovi**) dest;
    tMovi *movOri = (tMovi*) ori;
    strcpy_((*movDest)->ctaCte,movOri->ctaCte);
    (*movDest)->saldo += movOri->saldo;

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
    mostrar(NULL, fp);
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

        tNodo * men = buscarMenorNodoLista(*p, comparar);//devuelve p en la primer posicion

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
        tMovi* pM = &totalCuenta;//Creo este Movimiento para guardar en:
                                //                     1- la cadena del movimiento: el codigo de cliente, el cual voy a comparar para ver si cambio de cliente.
                                //                     2- El saldo el cual voy a ir sumando para luego mostrar el total del acumulado.
        if (comparar2((*p)->info)){

            mostrar(NULL, fpPant); // de esta manera imprimo el encabezado de los movimientos
            totalCuenta.saldo=0; // igualo a 0 para "reiniciar" el saldo al cambiar de cuenta

            do{
                acumular((void*)&pM, (unsigned*)sizeof(tMovi), (*p)->info, sizeof(tMovi));

                mostrar((*p)->info, fpPant);

                tNodo* elim = *p;
                *p = elim->sig;
                free(elim->info);
                free(elim);
                cont++;
            }while (*p && comparar2((*p)->info) && (comparar((*p)->info, pM->ctaCte))==0);//Mientras que haya nodo && la cuenta sea 2 && no haya cambiado de cuenta

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
    int k = 0;//k cantidad de items eliminados y mostrados
    while(*p){
        tNodo* aux = *p;//Nodo auxiliar para liberar memoria

        k++;
        *p = aux->sig;
        if(mostrar && fp)
            mostrar(aux->info, fp);

        free(aux->info);
    }

    return k;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
