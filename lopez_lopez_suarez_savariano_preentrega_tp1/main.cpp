#include <iostream>
#include <string>
#include <vector>

using namespace std;

// VARIABLES GLOBALES:
bool salida = false; // esto se usa para salir del juego

void mostrar_pantalla_inicio()
{
    // una imagen linda :)
    for (int j = 0; j < 20; j++)
    {
        cout << endl;
    }
    cout << "\t \t \t \t \tHola, apretá Enter para empezar...";
    for (int j = 20; j < 40; j++)
    {
        cout << endl;
    }

    cin.get(); // creo que al usar una función auxiliar cin.ignore.get() hace
               // que necesites dos enter.

    return;
}

void start_game()
{
    system("clear");

    bool volver;
    volver = true;

    vector<string> sabores_normales = {"Frutilla"};

    while (volver == true)
    {
        volver = false;
        cout << R"(Heladero: "¿Qué te sirvo?")" << endl << endl;
        cout << "1- Sabor " << sabores_normales[0] << endl;
        cout << "2- Sabor Vino\n";
        cout << "3- Sabor Trapo de Piso\n\n";

        enum opciones_de_sabor
        {
            NORMAL = 1,
            ALCOHOL,
            RARO
        };

        int opcion_elegida;

        string respuesta;
        bool no_respondio = true;

        cin >> opcion_elegida;

        switch (opcion_elegida)
        {
        case NORMAL:
            cout << "¿Un helado de Frutilla? ¡Perfecto!\n";
            cout << "*se le cae el helado*\n";
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
            cout << "¡Finalmente alguien pide los sabores buenos!\n";
            cout << "Probás el helado.\n"
                 << "...\n"
                 << "¡Está buenísimo! ¡¿Cómo no probaste esto antes?!\n"
                 << "...\n";
            // cambiamos a una imagen de un hospital
            cout << "*acá cambiamos a un hospital o lápida o algo\n";
            break;
        default:
            cout << "escribí bien amigx";
            break;
        }
    }

    cout << "Gracias por jugar!\n" << "Apretá Enter para volver al menú...\n";
    cin.ignore().get();
    return;
}

void main_menu()
{
    system("clear");

    int opcion = -1;

    enum dificultad
    {
        START = 1,
        CREDITS,
        SALIR
    };

    cout << "Ingresá una opción...\n"
         << "1- Comenzar\n"
         << "2- Créditos\n"
         << "3- Salir a la terminal\n";
    cin >> opcion;

    switch (opcion)
    {
    case START:
        start_game();
        break;
    case CREDITS:
        cout << "esto todavía no está programado... \n";
        cout << "Apretá Enter para volver al menú...\n";
        cin.ignore().get();
        break;
    case SALIR:
        salida = true;
        cout << "¡¡Muchas gracias por jugar!!\n";
        break;
    default:
        cout << "escribí otro número gil\n";
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
        main_menu();
    }

    return 0;
}