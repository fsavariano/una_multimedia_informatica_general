#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

// VARIABLES GLOBALES:
bool salida = false; // esto se usa para salir del juego

void mostrar_pantalla_inicio()
{
    cout << R"(************************************************************************************************************************
************************************************************************************************************************
******  **    ****** ** **  ************************************ *** ***********************************  **************
  ***   **     ***   ** **  ***  *******************  ***** ***      *** ******  *** *******  ***    ***    **** *******
   **           **   **     **    *****  ****  *****   ***   **      **  ****    ***  ******  ***     *      **    *****
   **                **     **    *****  ****  ****     **                **     **    ** **  ***            **     ****
                     **     **    *****  ****  ***                        **     **    ** **   **            **     ****
                                  ****   ****  ***                                     **  *  .**            **      ***
                                  ****     **                                          **                            ***
                                  ****                                                 **         ,--~~-.             **
                                  ***                                                  **      .-~   ,~~*~.           **
                                  **                                                    *      *         -^~          **
                                   *                                                          ~           -^-         **
                                                                                             .~            ~*         **
                                                                                             ,-             *,.       **
                                                         BIENVENIDOS A                       .~               *,      **
                                                                                              -,              **      **
                                         ▀    ▀ ▀▀▀▀ ▀    ▀▀▀▀▀ ▀▀▀▀▀   ▀▀▀▀▀▀▀ ▀▀▀▀           ~,          -~-^~       *
                                         ▀    ▀ ▀    ▀    ▀   ▀ ▀   ▀▀     ▀    ▀               ~-        *^~*>.        
                                         ▀    ▀ ▀    ▀    ▀   ▀ ▀    ▀     ▀    ▀                *-  -~~~~*-,,^,        
             ,~.                  ,~.    ▀    ▀ ▀    ▀    ▀   ▀ ▀   ▀▀     ▀    ▀                ~*,-^^>>*-,-,^-        
          ,-^*^                  ~~*-    ▀▀▀▀▀▀ ▀▀▀  ▀    ▀▀▀▀▀ ▀ ▀▀▀      ▀    ▀▀▀               -~*>-**^*~,,*~        
       .-*~~~^*^,    .,        .*~*-     ▀    ▀ ▀    ▀    ▀   ▀ ▀   ▀      ▀    ▀                    ,^~^^^~-,*~        
       ~~-~~----*~ .*^-       ~*~~.      ▀    ▀ ▀    ▀    ▀   ▀ ▀   ▀▀     ▀    ▀                      -^~^^*,~*        
      .*-~~~*^^**^~~***.,~**-**~-        ▀    ▀ ▀    ▀    ▀   ▀ ▀    ▀▀    ▀    ▀                        ***^*~*        
      ~*-*^*~~~~~*-....->>>>>>=,         ▀    ▀ ▀    ▀    ▀   ▀ ▀     ▀    ▀    ▀                         ,^*,-*        
      ,*~^~-~~~~-~>-...,*>>>>>>>.        ▀    ▀ ▀▀▀▀ ▀▀▀▀ ▀   ▀ ▀     ▀    ▀    ▀▀▀▀                        **~~        
      *^>^*~~---~~^^....~>>>>>>>*                                                                            .,.        
      ~-,-~*****~~^^,...*>=>>>>>>                                                                                       
      .*, ,,,,---~*^~--**=>>>>>>^                                                                                       
       *- ,,,,,,,,,,--~*^>>>>>>=,                                                                                       
       ,* ,,,,,,,,,,,,,,,,--~~^>-                                                                                       
        *-,,,,,,,,,,,,,,,,,,-*~-                                                                                        
        -~,,,,,,,,,,,,,,,,,***.                                                                                         
         *--,,,,,,,,,,,,,-**~                                                                                           
         ..,--~~^**~--,-***.                                                                                            
               .,-~~****~~                                                                                              
                    ..,,,                  
                                                PRESIONA ENTER PARA COMENZAR                                            )";
    cin.get(); // creo que al usar una función auxiliar cin.ignore.get() hace
               // que necesites dos enter.

    return;
}

void empezar_juego()
{
    system("clear");

    random_device random;
    int semilla = random();
    default_random_engine generador_random(semilla);

    bool volver;
    volver = true;

    float precio = (generador_random() % 1000000) / 100;

    vector<string> sabores_normales = {"Frutilla", "Chocolate", "Vainilla"};
    vector<string> sabores_alcohol = {"Vino", "White Russian"};
    vector<string> sabores_raros = {"Trapo de Piso", "Hormiga, Damasco y Pimienta"};
    string opcion_normal = sabores_normales[generador_random() % sabores_normales.size()];
    string opcion_alcohol = sabores_alcohol[generador_random() % sabores_alcohol.size()];
    string opcion_raro = sabores_raros[generador_random() % sabores_raros.size()];

    while (volver == true)
    {
        volver = false;

        cout << "Heladero: \"¿Qué te sirvo?\"\n\n";
        cout << "1- Sabor " << opcion_normal << endl;
        cout << "2- Sabor " << opcion_alcohol << endl;
        cout << "3- Sabor " << opcion_raro << endl;
        cout << "4- Más sabores\n\n";

        enum opciones_de_sabor
        {
            NORMAL = 1,
            ALCOHOL,
            RARO,
            OTROS
        };

        int opcion_elegida;
        cout << endl;

        string respuesta;
        bool no_respondio = true;

        cin >> opcion_elegida;

        switch (opcion_elegida)
        {
        case NORMAL:
            cout << "¿Un helado de Frutilla? ¡Perfecto!\n"
                 << "\"Heladero, en susurros: \"Qué aburrido...\"\n"
                 << "*se le cae el helado*\n"
                 << "Heladero: \"...\"\n"
                 << "Heladero: \"...  El precio es de $" << precio << " igual.\"\n\n";
            // acá viene otra imagen probablemente"
            break;
        case ALCOHOL:
            cout << "Ok, pero para ese sabor te voy a tener hacer un par de "
                    "preguntas. ¿Listo? (s/n)\n";

            bool listo;
            listo = true;

            while (no_respondio == true)
            {
                cin >> respuesta;
                if (respuesta != "s" && respuesta != "S" && respuesta != "n" &&
                    respuesta != "N")
                {
                    cout << "Respondé con 's' o 'n', flacx\n";
                }
                else if (respuesta == "s" || respuesta == "S")
                {
                    listo = true;
                    no_respondio = false;
                }
                else if (respuesta == "n" || respuesta == "N")
                {
                    listo = false;
                    no_respondio = false;
                }
            }
            if (listo == true)
            { // el usuario está listo, entonces empiezo las preguntas
                cout << "¿Qué edad tenés?\n";
                int edad;
                cin >> edad;
                if (edad < 18)
                {
                    cout << "Sos menor, mejor pedite otro sabor.\n\n";
                    volver = true;
                }
                else
                {
                    // sigue otra pregunta, sí es mayor
                    cout << "acá vienen más preguntas, ponele\n";
                }
            }
            else
            { // el usuario no está listo
                cout << "Entonces pedite otro sabor.\n";
                volver = true;
            }
            break;
        case RARO:
            cout << "\"¡Finalmente alguien pide los sabores buenos!\"\n";
            cout << "Probás el helado.\n"
                 << "\"...\"\n"
                 << "¡Está buenísimo! ¡¿Cómo no probaste esto antes?!\n"
                 << "\"...\"\n";
            // cambiamos a una imagen de un hospital
            cout << "*acá cambiamos a un hospital o lápida o algo\n";
            break;
        case OTROS:
            cout << "Heladero: \"Claro, más sabores. Pero sólo puedo mostrarte "
                    "tres. No preguntes.\""
                 << endl;
            volver = true;
            opcion_normal = sabores_normales[generador_random() % sabores_normales.size()];
            opcion_alcohol = sabores_alcohol[generador_random() % sabores_alcohol.size()];
            opcion_raro = sabores_raros[generador_random() % sabores_raros.size()];
            break;
        default:
            cout << "\nEl heladero te mira con cara extrañada.\n"
                 << "Heladero: \"No sé si te entendí.\"\n";
            volver = true;
            break;
        }
    }

    cout << "Gracias por jugar!\n"
         << "Apretá Enter para volver al menú...\n";
    cin.ignore().get();

    return;
}

void menu_principal()
{
    system("clear");

    int opcion = -1;

    enum dificultad
    {
        EMPEZAR = 1,
        CREDITOS,
        SALIR
    };

    cout << "Ingresá una opción...\n"
         << "1- Comenzar\n"
         << "2- Créditos\n"
         << "3- Salir a la terminal\n\n";
    cin >> opcion;
    cout << endl;

    switch (opcion)
    {
    case EMPEZAR:
        empezar_juego();
        break;
    case CREDITOS:
        cout << "esto todavía no está programado... \n\n";
        cout << "Apretá Enter para volver al menú...\n";
        cin.ignore();
        cin.clear();
        cin.get();
        break;
    case SALIR:
        salida = true;
        cout << "¡¡Muchas gracias por jugar!!\n";
        break;
    default:
        cout << "Por favor, seleccioná una de las opciones.\n\n";
        cin.ignore().get();
        break;
    }
    return;
}

int main()
{
    system("clear");

    mostrar_pantalla_inicio();

    while (salida == false)
    {
        menu_principal();
    }

    return 0;
}