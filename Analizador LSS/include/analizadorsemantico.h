#ifndef ANALIZADORSEMANTICO_H
#define ANALIZADORSEMANTICO_H

#include <string>
#include <list>

using namespace std;

class analizadorsemantico{
private:
    string sentencia;
    string resultado;

    //list<string> estructuras; no sirvio el acomodo tomar de  referencia
   // std :: list < string > :: iterator pos;

public:
    analizadorsemantico();
    void cargarSentencia(string);
    void analizarSentencia();
    void validarResultado();
    string estructuras(string);
};
#endif // ANALIZADORSEMANTICO_H
