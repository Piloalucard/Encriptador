#include <iostream>
#include <fstream>
#include <windows.h>
#include "cifrador.h"
#include "User.h"
#include<vector>

using namespace std;


void pause()
{
    cout << " Presiona [ENTER] para continuar..." ;
    cin.ignore();
}

int main()
{
    Cifrador cfr;
    User usrs[40];
    int global=0;
    int op=0;
    while(op!=3)
    {

        string data;
        cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;
        cout << "\t\t\t| Login Test |" << endl << endl;
        cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;
        cout << "\t\tMENU PRINCIPAL" << endl << endl;
        cout << "\t[1] Iniciar Sesion " << endl;
        cout << "\t[2] Crear nuevo usuario" << endl;
        cout << "\t[3] SALIR " << endl << endl;
        cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;
        cout << "\tElija una opcion: ";

        cin >> op;
        cin.ignore();
        cout << endl;
        string u,p,q;
        switch(op)
        {
        case 1:
            cout << "Usuario: ";
            cin >> u;

            cout << "Contraseña: ";
            cin >> p;

            p = cfr.encripta(p);

            int j;
            for(j=0;j<40;j++)
            {

                if(usrs[j].getName()==u)
                {
                    if(usrs[j].getBrute() > 0)
                    {
                        if(usrs[j].getPassHash() == p)
                        {
                            cout << "Esta es tu informacion: " << usrs[j].getInfo();
                        }
                        else
                        {
                            cout << "Contraseña incorrecta" ;
                            usrs[j].decBrute();

                        }

                    }
                    else if(usrs[j].getBrute() > -1)
                    {
                        cout << "ESTA ES LA ULTIMA OPORTUNIDAD QUE TIENES PARA ENTRAR Y YA NO SE PODRA INGRESAR A ESTA CUENTA" << endl;
                        cout << "¿Cual es tu cancion o pelicula favorita?: ";
                        cin >> q;
                        if(usrs[j].isValidQS(q))
                        {
                            cout << "Esta es tu informacion, ya no sera mas accesible: " << usrs[j].getInfo();
                            usrs[j].decBrute();
                        }
                        else
                        {
                            cout << "Respuesta incorrecta" ;
                            usrs[j].decBrute();
                        }

                    }
                    else
                    {
                        cout << "Cuenta bloqueada";

                    }
                    break;
                }
                else if(j==39)
                {

                    cout << "Usuario no encontrado";
                }

            }


            break;
        case 2:
            cout << "Dame el nombre de usuario: ";
            cin >> data;
            usrs[global].setName(data);
            cout << "Ingresa tu contraseña: ";
            cin >> data;
            usrs[global].setPassword(data);
            cout << "Ingresa tu informacion confidencial: ";
            cin >> data;
            usrs[global].setInfo(data);

            cout << "¿Cual es tu cancion o pelicula favorita?: ";
            cin >> data;
            usrs[global].setQS(data);




            break;
        case 3:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion Invalida!" << endl;
            break;
        }
        cout << endl;
        fflush(stdin);
        pause();
        system("cls");
    }
    return 0;
}

