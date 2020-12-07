#include <iostream>
#include <iostream>
#include "analizador.h"
#include "analizadorsemantico.h"
#include <windows.h>
using namespace std;

int main()
{

    analizadorsemantico myPrime;
    char opc;
    string nombreArchivo;

    system("Py02");

    do{

        cout << "\t\t ANALIZADOR SEMANTICO" << endl<<endl;
        cout << "1.-) Cargar codigo." << endl;
        cout << "0.-) Salir." << endl<<endl;
        cout << "Elige una opcion: ";
        cin>>opc;
        switch (opc)
        {
        case '1':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
            cout << "   Ingresa el nombre del archivo (nombreArchivo.txt): ";
            cin>>nombreArchivo;
            cout<< "\n\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
            cout << "\t\tRESULTADOS" << endl<<endl;
            myPrime.cargarSentencia(nombreArchivo);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            system("pause");
            system("cls");

            break;

        default:
            break;
        }
    cout << endl;
    }while(opc != '0');

    system("Fuegos");


//    myAS.cargarSentencia(); Pruebas de resultado variado

   /* Analizador myAnalizador; Mete basura
    string entrada;
    getline(cin, entrada);

    myAnalizador.verificarReservada(entrada);
    if(myAnalizador.getEsReservada()){
        cout << "Reservada" << endl;
    }
    else{
        myAnalizador.verficarNumero(entrada);
        if(myAnalizador.getEsNum()){
            cout << "Numero" << endl;
        }
        else{
            myAnalizador.verificarCaracter(entrada);
            if(myAnalizador.getEsCaracter()){
                cout << "Caracter" << endl;
            }
            else{
                myAnalizador.verificarIdentificador(entrada);
                if(myAnalizador.getEsIdentificador()){
                    cout << "Identificador" << endl;
                }
                else{
                    cout << "Palabra no valida" << endl; No da la Salida
                }
            }
        }
    }




    if(myAnalizador.verificador(entrada))
    {
        if(myAnalizador.esReservada(entrada))
        {
            cout << "La palabra "<< entrada<< " es reservada" << endl;
        }
        else{
            cout << "La palabra "<< entrada<< " es identificador" << endl;
        }

    }
    else if(myAnalizador.getEsNum()){
        cout << "La entrada "<< entrada<< " es Numero" << endl;
    }
    else{
        cout << "Palabra no valida" << endl;
    }*/



    return 0;
}
