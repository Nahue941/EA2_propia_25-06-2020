/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**   DESARROOLLE LAS "FUNCIONES MIEMBRO" DE LA CLASE    **//**//**//**/

#include "Prisma.h"

Prisma::Prisma()
{
    alto=1;
    ancho=1;
    profundidad=1;
    color="Incoloro";
}

Prisma::Prisma(string _color, int _alto, int _ancho)
{
    color= _color;
    alto= _alto;
    profundidad=1;
    ancho= _ancho;
}

Prisma::Prisma(string _color, int _alto, int _ancho, int _profundidad)
{
    color= _color;
    alto= _alto;
    ancho= _ancho;
    profundidad= _profundidad;
}

Prisma::Prisma(const Prisma &obj)
{
    alto= obj.alto;
    ancho = obj.ancho;
    profundidad = obj.profundidad;
    color= obj.color;
}

ostream & operator <<(ostream &sal, const Prisma &obj)
{
    sal<<obj.alto <<"x"<<obj.ancho<<"x"<<obj.profundidad<<"-"<<obj.color;
    return sal;
}

Prisma& Prisma::operator = (const Prisma &obj)
{
    alto = obj.alto;
    ancho = obj.ancho;
    profundidad = obj.profundidad;
    color = obj.color;
    return *this;
}

Prisma Prisma::operator++(int)
{
    Prisma aux(*this);
    this->alto++;
    this->ancho++;
    this->profundidad++;
    return aux;
}

Prisma operator * (const int &i, const Prisma &obj)
{
    Prisma aux(obj.color,obj.alto*i,obj.ancho*i,obj.profundidad*i);
    return aux;
}

Prisma& Prisma::operator--()
{
    this->alto--;
    this->ancho--;
    this->profundidad--;
    return *this;
}
