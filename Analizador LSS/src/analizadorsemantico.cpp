#include "analizadorsemantico.h"
#include <fstream>
#include <iostream>
#include <regex>
#include <windows.h>
#include "analizador.h"

analizadorsemantico::analizadorsemantico()
{
  sentencia = "";
  resultado = "";
}

void analizadorsemantico::cargarSentencia(string nombreArchivo)
{
    sentencia = "";
    ifstream archivo(nombreArchivo);
    if(archivo.good()){
        while(!archivo.eof()){
            getline(archivo,sentencia,'\n');
            cout << sentencia << "   ";
            analizarSentencia();
            cout << endl;
            if(archivo.eof()){
                break;
            }


        }
    }
}

void analizadorsemantico::analizarSentencia()
{

    if(sentencia  == "")
    {
        return;
    }
    analizador myAnalizador;
    string aux = "";
    string aux2 = "";
    string c = "";
    int tamanio = sentencia.size();
    for(int i = 0; i < tamanio; i++)
    {

        c = sentencia[i];
        myAnalizador.verificarCaracter(c);
        if(sentencia[i] != ' ' && !myAnalizador.getEsCaracter())
        {
            aux+= sentencia[i];
        }
        else
        {
            myAnalizador.reset();
            if(aux != ""){
                aux2 += myAnalizador.verificador(aux);

            }
            if(c[0] != ' '){
                aux2+=c;
            }
            aux = "";
            myAnalizador.reset();
        }
    }
    if(aux != ""){
         aux2 += myAnalizador.verificador(aux);
    }
    cout << estructuras(aux2);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);


}

string analizadorsemantico::estructuras(string entrada)
{
    //cout << "  " << entrada << " "; No quedo como se esperaba
    if(regex_match(entrada,regex("(if|while)[(]((I|N)(<|>|==|<=|>=|!=)(I|N|true|false)|N|I|true|false)((or|and)(I|N)(<|>|==|<=|>=|!=)(I|N|true|false)|N|I|true|false)*[)]")))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        return "Linea Correcta";
    }

    if(regex_match(entrada,regex("(listI|voidI|intI|floatI|boolI|doubleI|stringI|charI)[(](|(listI|voidI|intI|floatI|boolI|doubleI|stringI|charI)(,listI|,voidI|,intI|,floatI|,boolI|,doubleI|,stringI|,charI)*)[)];?")))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        return "Linea Correcta";
    }
    //Cambiar por uno regex reducida
    if(regex_match(entrada,regex("intI;|floatI;|boolI;|doubleI;|stringI;|charI;")))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        return "Linea Correcta";
    }

    if(regex_match(entrada,regex("stringI=(([\"].*[\"])|I);")))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        return "Linea Correcta";
    }

    if(regex_match(entrada,regex("intI=-?\\d+;")))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        return "Linea Correcta";
    }

    if(regex_match(entrada,regex("(double|float)I=-?\\d+(\\.\\d+)?;")))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        return "Linea Correcta";
    }
    //Correcto
    if(regex_match(entrada,regex("[{]|[}]")))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        return "Linea Correcta";
    }

    if(regex_match(entrada,regex("boolI=(true|false|I);")))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        return "Linea Correcta";
    }

    if(regex_match(entrada,regex("I((\\x2b\\x2b)|(--));")))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        return "Linea Correcta";
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    return "Error en esta linea";

}
