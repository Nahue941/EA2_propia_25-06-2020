/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**         COMPLETE LA DECLARACIÓN DE LA CLASE          **//**//**//**/

#ifndef PRISMA_H_
#define PRISMA_H_

#include <iostream>
#include <string>

using namespace std;

class Prisma
{
private:
    int alto;
    int ancho;
    int profundidad;
    string color;     /// <--preferentemente, de lo contrario:  char *color;

public:
    Prisma();
    Prisma(string, int, int);
    Prisma(string, int, int, int);
    Prisma(const Prisma &);

    Prisma operator++(int);
    Prisma &operator =(const Prisma&);
    Prisma &operator--();

    friend ostream & operator<<(ostream &salida, const Prisma &);
    friend Prisma operator * (const int &i, const Prisma &obj);
};

#endif // PRISMA_H_

