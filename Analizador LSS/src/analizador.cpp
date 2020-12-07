#include "analizador.h"

analizador::analizador()
{
    reservadas.push_back("if");
    reservadas.push_back("switch");
    reservadas.push_back("for");
    reservadas.push_back("while");
    reservadas.push_back("do");
    reservadas.push_back("class");
    reservadas.push_back("int");
    reservadas.push_back("string");
    reservadas.push_back("bool");
    reservadas.push_back("char");
    reservadas.push_back("long");
    reservadas.push_back("double");
    reservadas.push_back("float");
    reservadas.push_back("void");
    reservadas.push_back("break");
    reservadas.push_back("case");
    reservadas.push_back("list");
    reservadas.push_back("main");
    reservadas.push_back("return");
    reservadas.push_back("public");
    reservadas.push_back("private");
    reservadas.push_back("queue");
    reservadas.push_back("stack");
    reservadas.push_back("new");
    reservadas.push_back("delete");
    reservadas.push_back("short");
    reservadas.push_back("size");
    reservadas.push_back("print");
    reservadas.push_back("scan");
    reservadas.push_back("else");
    reservadas.push_back("protected");
    reservadas.push_back("auto");
    reservadas.push_back("true");
    reservadas.push_back("false");
    reservadas.push_back("and");
    reservadas.push_back("or");



    caracteresEspeciales.push_back("(");
    caracteresEspeciales.push_back(")");
    caracteresEspeciales.push_back("{");
    caracteresEspeciales.push_back("}");
    caracteresEspeciales.push_back(";");
    caracteresEspeciales.push_back("=");
    caracteresEspeciales.push_back("+");
    caracteresEspeciales.push_back("-");
    caracteresEspeciales.push_back("/");
    caracteresEspeciales.push_back("*");
    caracteresEspeciales.push_back(".");
    caracteresEspeciales.push_back(" ");
    caracteresEspeciales.push_back("<");
    caracteresEspeciales.push_back(">");
    caracteresEspeciales.push_back("[");
    caracteresEspeciales.push_back("]");
    caracteresEspeciales.push_back("++");
    caracteresEspeciales.push_back("+=");
    caracteresEspeciales.push_back("--");
    caracteresEspeciales.push_back("==");
    caracteresEspeciales.push_back("!=");
    caracteresEspeciales.push_back("<=");
    caracteresEspeciales.push_back(">=");
    caracteresEspeciales.push_back("!");




    esNumero = false;
    esCarac = false;
    esIdent = false;
    esReserv = false;
}

bool analizador::getEsNum(){
    return esNumero;
}

string analizador::verificador(string cadena)
{
    verficarNumero(cadena);
    if(esNumero){
       //reset();
       return "N";
    }

    verificarReservada(cadena);
    if(esReserv){
        //reset();
        return cadena;
    }

    verificarCaracter(cadena);
    if(esCarac){
        //reset();
        return cadena;
    }

    verificarIdentificador(cadena);
    if(esIdent){
        //reset();
        return "I";
    }


    return "Error";
}
bool analizador::getEsIdentificador()
{
    return esIdent;
}

bool analizador::getEsCaracter()
{
    return esCarac;
}

bool analizador::getEsReservada()
{
    return esReserv;
}



void analizador::verificarReservada(string cadena)
{
    pos = find(reservadas.begin() , reservadas.end() , cadena);
    if(pos != reservadas.end() )
        esReserv = true;
}

void analizador::reset()
{
    esNumero = false;
    esCarac = false;
    esIdent = false;
    esReserv = false;
}



void analizador::verficarNumero(string cadena)
{
        for(unsigned int j = 0; j < cadena.size(); j++){
            if(cadena[j] < 48 or cadena[j] > 57){
                return;
            }
        }
      esNumero = true;
}

void analizador::verificarCaracter(string cadena)
{
    pos = find(caracteresEspeciales.begin() , caracteresEspeciales.end() , cadena);
    if(pos != caracteresEspeciales.end() )
        esCarac = true;
}

void analizador::verificarIdentificador(string cadena)
{
    for(unsigned int i=0; i < cadena.size(); i++)
    {
        if((cadena[i] >= 97 and cadena[i] <= 122) or (cadena[i] >= 65 and cadena[i] <= 90) or cadena[i] == 95 or (cadena[i] >= 48 and cadena[i] <= 57)){}
        else {
                return;
             }
    }
    esIdent = true;
}
