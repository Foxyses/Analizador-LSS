#ifndef ANALIZADOR_H
#define ANALIZADOR_H

#include<list>
#include<string>
#include <algorithm>

using namespace std;

class analizador
{
public:
    analizador();
    // Verificadores  checar Reservada no toma valor
    string verificador(string);
    void verificarReservada(string);
    void verficarNumero(string);
    void verificarCaracter(string);
    void verificarIdentificador(string);

    void reset();

    bool getEsNum();
    bool getEsIdentificador();
    bool getEsCaracter();
    bool getEsReservada();


private:
    list<string> caracteresEspeciales;
    list<string> reservadas;
    std :: list < string > :: iterator pos;
    //No mover++
    bool esNumero;
    bool esCarac;
    bool esIdent;
    bool esReserv;
};

#endif // ANALIZADOR_H
