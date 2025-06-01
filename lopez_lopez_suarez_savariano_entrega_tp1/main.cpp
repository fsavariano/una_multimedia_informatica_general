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
    cin.ignore(1000, '\n'); // creo que al usar una función auxiliar cin.ignore.get() hace
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

    float precio = generador_random() % 10000 + (generador_random() % 100) / 100.0;

    vector<string> sabores_normales = {"Frutilla", "Chocolate", "Vainilla"};
    vector<string> sabores_alcohol = {"Vino", "White Russian"};
    vector<string> sabores_raros = {"Trapo de Piso", "Hormiga, Damasco y Pimienta"};
    string opcion_normal = sabores_normales[generador_random() % sabores_normales.size()];
    string opcion_alcohol = sabores_alcohol[generador_random() % sabores_alcohol.size()];
    string opcion_raro = sabores_raros[generador_random() % sabores_raros.size()];

    while (volver == true)
    {
        volver = false;

        cout << R"(                                                        ■■■
                                                      ■■■ ■■■                    ■■                                     
                                                     ■■  ■  ■■                  ■■■                                     
                                                    ■■■■■ ■■■■■                ■■ ■■                                    
                                                   ■■         ■■               ■   ■                                    
                                                   ■    ■■■    ■              ■■   ■■                                   
                                                  • ■■■■■ ■■■■■■•            ■■     ■■                                  
                                                  •             •            ■■■■■■■■■                                  
                                                  •   ••• •••   •            ■■■    ■■                                  
                                                  •   • • • •   •              ■■  ■■                                   
                                                  •             •               ■  ■                                    
                                                   •  ••   ••  •               ■■■■■                                    
                                                    •  •••••  •              ••• ■•                                     
                                                     •        •              •    •                                     
                                              ••••■■■•••••••••■■■•          ••    •                                     
                                             •    ■ ■         ■ ■•••       ••    ••                                     
                                            •     ■ ■         ■ ■  •••    ••     •                                      
                                           •      ■ ■         ■ ■    ••••••     ••                                      
                                          •       ■ ■         ■ ■               •                                       
                                         •        ■ ■■■■■■■■■■■ ■             •••                                       
                                        •        ■              ■  •       ••••                                         
                                        •      •■                ■ •••••••••                                            
                                        •     •■                  ■•                                                    
                                        •    • ■                   ■                                                    
                                        •    • ■  ■ ■ ■■■ ■        ■                                                    
                                        •    • ■  ■■■ ■■  ■   ■■   ■                                                    
                                        •    • ■  ■ ■ ■■■ ■■■      ■                                                    
                                        •    • ■                   ■                                                    
                                        •    • ■   ■  ■■■ ■■■ ■■■  ■                                                    
                                        •••••• ■  ■■■ ■■■  ■  ■■   ■                                                    
                                         ••••  ■  ■ ■ ■ ■  ■  ■■■  ■                                                    
                                               ■                   ■                                                    
El Heladero: "¿Qué te sirvo?")"
             << endl
             << endl;
        cout << "1- Sabor " << opcion_normal << endl;
        cout << "2- Sabor " << opcion_alcohol << endl;
        cout << "3- Sabor " << opcion_raro << endl;
        cout << "4- Más sabores\n";

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
            system("clear");
            cout << "El Heladero: ¡Perfecto! Gran elección.\n"
                 << "El Heladero, en susurros: \"Ashh...qué aburrido...\"\n"
                 << "El Heladero comienza a hacer el cucurucho lento y con fatiga.\n"
                 << "Su técnica es buena; el helado es más prolijo con cada movimiento de su brazo...\n"
                 << "... y podés ver sus años de cansancio con cada movimiento de muñeca.\n"
                 << "No tenés mucho tiempo para esto, ¿cuánto más le faltará?\n"
                 << "Recordás que el TP de informática para mañana sigue sin compilar...\n"
                 << "Pero El Heladero ni se inmuta. Hunde, apoya, corrige y repite; sin pausa, con lentitud poderosa.\n"
                 << "Y al fin, todo lo vale: tu cucurucho empieza a verse más y más delicioso, y ya casi está listo.\n"
                 << "El Heladero: \"Uhh...\" *se le cae el helado*\n\n";
            cout <<
                R"(⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⢀⡄⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⢀⣾⡇⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⢠⡮⣟⡇⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⣠⡮⡮⣟⠁⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⣼⡮⡮⣫⣟⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⢀⣾⡮⡮⡮⣫⡏⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⣰⡮⡮⡮⡮⡮⣟⡇⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⣸⣾⡮⡮⡮⡮⡮⡮⣟⠃⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⢕⠿⠛⢿⡮⡮⡮⡮⣫⣫⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⢕⢕⢕⢀⣾⡮⡮⡮⡮⣫⡏⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⣼⣫⢕⣠⡮⠛⠛⡿⢀⡮⣫⡇⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⣼⣫⣫⣶⣫⡟⢕⢕⠁⣼⡮⣫⠁⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⣼⡏⢿⣫⣫⡿⠁⠕⢕⢕⢻⡮⡟⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⢠⣫⡇⣫⣫⡟⢕⢕⠕⠕⢕⠸⡮⠁⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⢸⣫⣇⣼⡮⣷⡀⢕⠕⢰⣶⢕⡮⠁⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⢿⣫⣫⡮⣫⣫⣫⣄⣤⣫⡿⠞⡇⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⣾⣫⣫⣫⣫⡮⣫⣫⣫⡟⢁⣷⡇⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⢸⣫⣫⣫⣫⡮⣫⣫⣫⣧⣼⣾⡇⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠸⣫⣫⣟⣫⣫⣫⣫⣫⣫⣫⣟⡁⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⢀⣠⣫⣫⣫⣟⣟⣫⣫⣫⣫⣟⣟⣷⡀⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⢀⣟⣟⣫⣫⣫⣫⣟⣟⣟⣟⣟⣟⣟⣟⣫⣦⣤⡀⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⢀⣼⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⡆⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⢸⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⠟⠃⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠈⠻⠿⠿⢿⣫⣫⣫⣫⣫⣫⣫⣫⣫⣫⣫⣫⣫⣫⡇⠶⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕
⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⢠⣶⡎⠉⠉⠉⠙⢻⡮⣫⣫⣫⣫⣫⡿⠃⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕⠕)"
                 << endl;
            cout << "El Heladero: \"...\"\n"
                 << "El Heladero: \"...  el precio es de $" << precio << " igual.\"\n\n";
            break;
        case ALCOHOL:
            cout << "El Heladero: \"Ok, pero para ese sabor te voy a tener hacer un par de "
                    "preguntas. ¿Listo?\" (s/n)\n";

            bool listo;
            listo = true;

            while (no_respondio == true)
            {
                cin >> respuesta;
                if (respuesta != "s" && respuesta != "S" && respuesta != "n" &&
                    respuesta != "N")
                {
                    cout << "El Heladero: \"Ey, hice una pregunta.\"\n";
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
                cout << "El Heladero: \"¿Qué edad tenés?\"\n";
                int edad;
                cin >> edad;
                if (edad < 18)
                {
                    cout << "El Heladero: \"Sos menor, mejor pedite otro sabor.\"\n\n";
                    volver = true;
                }
                else
                {
                    bool respondio_bien = false;
                    while (!respondio_bien)
                    {
                        cout << "El Heladero: \"¿Te gustan los gatitos?\"\n";
                        cin >> respuesta;
                        if (respuesta != "s" && respuesta != "S")
                        {
                            respondio_bien = false;
                        }
                        if (respondio_bien)
                        {
                            cout << "El Heladero: \"¿Tenes perros?\"\n";
                            cin >> respuesta;
                            if (respuesta != "s" && respuesta != "S")
                            {
                                respondio_bien = false;
                            }
                        }
                        if (respondio_bien)
                        {
                            cout << "El Heladero: \"¿Te gusta el mate?\"\n";
                            cin >> respuesta;
                            if (respuesta != "s" && respuesta != "S")
                            {
                                respondio_bien = false;
                            }
                        }
                        if (respondio_bien)
                        {
                            cout << "El Heladero: \"¿Amargo?\"\n";
                            cin >> respuesta;
                            if (respuesta != "s" && respuesta != "S")
                            {
                                respondio_bien = false;
                            }
                        }
                        if (respondio_bien)
                        {
                            cout << "El Heladero: \"¿Sos de Boca?\"\n";
                            cin >> respuesta;
                            if (respuesta != "s" && respuesta != "S")
                            {
                                respondio_bien = false;
                            }
                        }
                        if (respondio_bien)
                        {
                            cout << "El Heladero: \"¿De River?\"\n";
                            cin >> respuesta;
                            if (respuesta != "s" && respuesta != "S")
                            {
                                respondio_bien = false;
                            }
                        }

                        if (respondio_bien)
                        {
                            cout << "El Heladero: \"Genial, entonces sí, ¡un cucurucho de " << opcion_alcohol << "!\"\n";
                            cout << "...\n"
                                 << "... es un asco.\n"
                                 << "El Heladero: \"Bueno, eso sería $" << precio * 100 << ".\"\n"
                                 << "¿CUÁNTO?\n"
                                 << "Evidentemente El Heladero puede ver el horror reflejado en tu cara.\n"
                                 << "El Heladero: \"Y... es un alcohol de buena calidad, ¿qué esperabas?\n\n";
                            // alguna imagen?
                        }
                        else
                        {
                            cout << "El Heladero: \"No, no, vamos de nuevo.\"\n";
                        }
                    } // Hacer que mientras la respuenta sea S siga con el ciclo de preguntas
                    // sigue otra pregunta, sí es mayor
                }
            }
            else
            { // el usuario no está listo
                cout << "Entonces pedite otro sabor.\n";
                cout << "Presioná Enter para volver a elegir...\n";
                cin.ignore().get();//esto no funciona por alguna razón
                volver = true;
            }
            break;
        case RARO:
            cout << "\n\"¡Finalmente alguien pide los sabores buenos!\"\n";
            cout << "\"¡Vos sí que sabes ehh!\"\n";
            cout << "Probás el helado.\n"
                 << "\"...\"\n"
                 << "¡Está buenísimo! ¡¿Cómo no probaste esto antes?!\n\n"
                 << "¡Apretá Enter para disfrutar de un buen helado!\n";
            // Tendría que ir un enter antes de que salte la imagen?
            cin.ignore().get();
            system("clear");
            cout << R"(⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕
⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕
⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕
⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕
⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕
⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕
⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕
⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⣰⣶⣶⣷⣶⣶⡆⢕⢕⢕⢕⢕⢕⢕⢕
⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⣟⣿⡿⠉⢿⣿⣇⢕⢕⢕⢕⢕⢕⢕⢕
⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⣠⡄⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢸⣿⣿⣿⣿⣿⣿⣿⣟⢕⢕⠈⣿⣿⣿⣿⣿⣿⣿⣿⡆⢕
⢕⢕⢕⢕⢕⢕⢀⡀⣀⣀⣀⣀⣀⣀⣀⣠⣿⣧⣀⣀⣀⣀⣀⣀⣀⣀⣀⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢸⣿⠉⢻⡟⠋⢻⣿⣿⣆⢕⣴⣿⣿⡟⠙⣿⡏⠙⣿⡇⢕
⢕⢕⢕⢕⢕⢕⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢸⣟⢕⣸⣇⢕⣸⣿⣿⣿⣴⣿⣿⣿⡇⢕⣟⡇⢕⣟⡇⢕
⢕⢕⢕⢕⢕⢕⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢕
⢕⢕⢕⢕⢕⢕⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢸⣟⠁⢹⡏⠁⢹⣿⠉⠈⣿⠁⠸⣿⡏⠈⣿⡏⠈⣿⡇⢕
⢕⢕⢕⢕⢕⢕⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣾⣿⣿⣿⣿⡆⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢸⣟⡀⣸⣇⡀⣸⣿⣀⢀⣿⡀⢰⣿⣇⢀⣿⣇⢀⣿⡇⢕
⢕⢕⢕⢕⢕⢕⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⠛⠛⠛⣿⡇⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢕
⢕⢕⢕⢕⢕⢕⢸⣿⣿⣿⣿⣿⣿⣿⣿⡿⢕⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⢕⢕⢕⢼⡇⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢸⣟⢕⢹⡏⢕⢹⣿⣿⣿⣿⣿⣿⣿⡇⢕⣟⡇⢕⣟⡇⢕
⢕⢕⢕⢕⢕⢕⢸⣿⣿⣿⣿⣿⣿⣿⣿⢕⢕⢕⢕⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣀⣀⣀⣾⣧⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢸⣿⣀⣼⣧⣀⣼⣿⣟⠁⠉⠈⣿⣿⣧⣠⣿⣇⣠⣿⡇⢕
⢕⢕⢕⢕⢕⢕⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⢕⢰⣾⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣿⣿⣿⣿⣿⣦⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢸⣿⣿⣿⣿⣿⣿⣿⣟⢕⢕⢕⣿⣿⣿⣿⣿⣿⣿⣿⡇⢕
⢕⢕⢕⢕⢕⢕⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣿⣿⣿⣿⣿⣿⣧⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⣸⣿⣿⣿⣿⣿⣿⣿⣟⢕⢕⢕⣿⣿⣿⣿⣿⣿⣿⣿⡇⢕
⢕⢕⢕⢕⢕⢕⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣿⣿⣿⣿⣿⣿⣿⣧⡀⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⣿⣿⣿⣿⣿⣿⣿⣿⣫⢕⢕⢕⣿⣿⣿⣿⣿⣿⣿⣿⣷⢕
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⠉⠉⠉⠉⠙⠋⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉
⢕⢕⣀⣀⣀⣀⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣄⣀⣀⣀⣀⢕⢕⣀⣀⣀⣀⣀⣀⡀⢕⢕⢕⢕⣀⣀⣀⣀⢕⢕⢕⢕⢀⣀⣀⣀⣀⢕⢕⢕⢕⣀⣀⣀⣀⢕⢕⢕⢕⢀
⢕⢸⣿⣿⣿⣿⠋⠁⠉⠙⣿⣿⣿⣿⣿⣿⠉⠉⠻⣿⣿⣿⣿⠏⠉⠉⠙⣿⣿⣿⣿⣿⣿⣿⡟⠻⣿⣿⣿⣿⣿⣿⡇⢕⣿⣿⣿⣿⣿⣿⣿⢕⢕⢕⠰⣿⣿⣿⣿⡇⢕⢕⢕⢿⣿⣿⣿⣿⢕⢕⢕⠰⣿⣿⣿⣿⡇⢕⢕⢕⢾
⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⠈⢿⣿⣿⣿⡟⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⠘⣿⣿⣿⣿⡇⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕
⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣸⣿⣿⣿⣇⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣟⣿⣿⣿⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀
⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿
⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕
⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕
⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕⢕)"
                 << endl;
            cout << "Te levantás después de unas horas, acostado en una camilla y con al menos un par de órganos en situación comprometida.\n"
                 << "Revisás tus bolsillos. El celu y la SUBE siguen ahí: suspirás aliviado.\n"
                 << "Y al final el helado estaba rico así que... no salió tan mal, ¿no?\n"
                 << "Pero en uno encontrás algo más. Es un folletito de la heladería, y atrás dice \"NOS DEBÉS $" << precio << "\". Ah, bueh.\n"
                 << "Te incorporás como podés , sacás tu celular y empezás a tipear furiosamente en las reseñas de la heladería.\n"
                 << endl;
            break;
        case OTROS:
            system("clear");
            cout << R"(                                                        ■■■
                                                      ■■■ ■■■                    ■■                                     
                                                     ■■  ■  ■■                  ■■■                                     
                                                    ■■■■■ ■■■■■                ■■ ■■                                    
                                                   ■■         ■■               ■   ■                                    
                                                   ■    ■■■    ■              ■■   ■■                                   
                                                  • ■■■■■ ■■■■■■•            ■■     ■■                                  
                                                  •             •            ■■■■■■■■■                                  
                                                  •   ••• •••   •            ■■■    ■■                                  
                                                  •   • • • •   •              ■■  ■■                                   
                                                  •             •               ■  ■                                    
                                                   •  ••   ••  •               ■■■■■                                    
                                                    •  •••••  •              ••• ■•                                     
                                                     •        •              •    •                                     
                                              ••••■■■•••••••••■■■•          ••    •                                     
                                             •    ■ ■         ■ ■•••       ••    ••                                     
                                            •     ■ ■         ■ ■  •••    ••     •                                      
                                           •      ■ ■         ■ ■    ••••••     ••                                      
                                          •       ■ ■         ■ ■               •                                       
                                         •        ■ ■■■■■■■■■■■ ■             •••                                       
                                        •        ■              ■  •       ••••                                         
                                        •      •■                ■ •••••••••                                            
                                        •     •■                  ■•                                                    
                                        •    • ■                   ■                                                    
                                        •    • ■  ■ ■ ■■■ ■        ■                                                    
                                        •    • ■  ■■■ ■■  ■   ■■   ■                                                    
                                        •    • ■  ■ ■ ■■■ ■■■      ■                                                    
                                        •    • ■                   ■                                                    
                                        •    • ■   ■  ■■■ ■■■ ■■■  ■                                                    
                                        •••••• ■  ■■■ ■■■  ■  ■■   ■                                                    
                                         ••••  ■  ■ ■ ■ ■  ■  ■■■  ■                                                    
                                               ■                   ■                                                    )"
                 << endl;
            cout << "\n\n\n\n"
                 << "El Heladero: \"Claro, más sabores. Pero sólo puedo mostrarte tres. No preguntes.\"\n\n";
            cout << "Presioná Enter para volver a elegir...\n";
            cin.ignore().get();
            volver = true;
            opcion_normal = sabores_normales[generador_random() % sabores_normales.size()];
            opcion_alcohol = sabores_alcohol[generador_random() % sabores_alcohol.size()];
            opcion_raro = sabores_raros[generador_random() % sabores_raros.size()];
            system("clear");
            break;
        default:
            system("clear");
            cout << R"(⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢀⣤⣤⡀⠂⠂⠂⠂⠂⠂⠂⠌⣀⣤⣴⣤⣄⡀⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢀⣤⣤⡀⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢀⣾⠟⠻⣟⡄⠂⠂⠂⠂⠂⢀⣾⣟⠟⠛⠛⢿⣟⣦⠌⠂⠂⠂⠂⠂⠂⠂⠕⣟⠟⢻⣷⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢸⡟⠂⠂⢹⡇⠂⠂⠂⠂⢠⣟⠏⠂⠂⠂⠂⠂⠈⢻⣷⡀⠂⠂⠂⠂⠂⠂⠌⠁⠂⠌⢿⡇⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢸⣧⠂⠂⣸⡇⠂⠂⠂⠌⣾⠏⠂⠂⠂⠂⠂⠂⠂⠂⠹⣷⡀⠂⠂⠂⠂⠂⠂⠂⠂⠌⣾⠇⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠈⠛⠂⠕⣟⠁⠂⠂⠂⢸⡟⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢹⣧⠂⠂⠂⠂⠂⠌⣾⣦⣾⡿⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠌⢿⡆⠂⠂⠌⣾⠃⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠌⣫⡆⠂⠂⠂⠂⣸⡿⠛⠋⠁⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠘⠿⠌⠂⠌⣟⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠸⣧⠌⠂⠂⠌⠿⠁⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠌⠂⠂⠕⣟⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠌⣟⡀⠂⠂⠂⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠿⠌⠕⣟⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠌⢿⡇⠂⠕⡇⠌⠂⠂⣠⣶⣦⡀⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢠⣶⣦⡀⠂⠂⠌⠂⠌⣟⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢸⡇⠂⠂⠌⠂⠂⢠⡿⠋⢻⣷⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢠⣟⠛⠻⣷⠌⠂⠂⠂⠌⢿⡄⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢸⡇⠂⠂⠂⠂⠂⠌⠌⠂⠌⣟⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢸⡇⠂⠌⣫⡆⠂⠂⠂⠂⢸⣧⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠌⣾⡇⠂⠂⠂⠂⠂⠂⠌⠂⢰⣟⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢸⡇⠂⢀⣟⠁⠂⠂⠂⠂⠌⣫⡄⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠌⣟⠌⠂⠂⠂⠂⠂⠌⣾⣟⡿⠃⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠌⠁⠂⢼⡟⠂⠂⠂⠂⠂⠂⠸⣷⠌⠂⠂⠂⠂⢀⡀⠂⠂⠂⢸⡟⠂⠂⠂⠂⠂⠂⢸⡟⠉⠁⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠸⣫⠌⠂⠂⠂⠂⠂⠂⢹⣧⡀⠂⠂⢠⣟⣟⡆⠂⢠⣫⠃⠂⠂⠂⠂⠂⠌⠻⠁⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠌⢻⠕⠂⠂⠂⠂⠂⠂⠌⠻⣷⡄⠂⣾⡇⢸⣟⣤⣾⠏⠂⠂⠂⠂⠂⠂⠕⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠌⠌⠂⠂⠂⠂⠌⣠⠌⠙⢿⣟⣟⠌⣸⣿⡿⠃⠌⣄⠌⠂⠂⠂⠂⠟⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠸⠇⠂⠂⠂⢀⣼⡿⠌⢰⣟⣿⡇⠌⣫⠋⠁⠂⠌⢿⣧⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⣠⣟⠟⠌⠌⣟⠛⢿⠁⢸⣫⠂⠂⠂⠂⠌⠻⣷⡀⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢀⣴⡿⠋⠂⠂⠕⣟⠌⠈⠂⠘⣟⡄⠂⠂⠂⠂⠂⠙⣟⣆⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠌⣠⣟⠟⠌⠂⠂⠂⠕⣟⠌⠂⠂⠂⠸⣟⡀⠂⠂⠂⠂⠂⠈⢿⣧⡀⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢠⣾⡿⠁⠂⠂⠂⠂⠂⠕⣟⠌⠂⠂⠂⠂⢹⡇⠂⠂⠂⠂⠂⠂⠌⠹⣟⣦⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢠⣟⠏⠂⠂⠂⠂⠂⠂⠂⠕⣟⠌⠂⠂⠂⠌⣾⠇⠂⠂⠂⠂⠂⠂⠂⠂⠈⢻⣧⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠌⣟⠇⠂⠂⠂⠂⠂⠂⠂⠂⠌⣟⠌⠂⠂⠂⢠⡿⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠌⢿⡆⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠌⣟⠌⠂⠂⠂⠂⠂⠂⠂⠂⠕⣟⠌⠂⠂⠂⣼⡇⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢸⡇⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠕⣟⠌⠂⠂⠂⠂⠂⠂⠂⠂⢸⣿⣶⡄⠌⣰⡿⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢸⡇⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠕⣟⠌⠂⠂⠂⠂⢀⡀⠂⢀⣟⠋⠻⢿⣟⡿⠁⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢸⡇⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠕⣟⠌⠂⠂⠂⠂⠘⠁⠌⣼⡏⠂⠂⢸⣟⠁⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢸⡇⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠕⣟⠌⠂⠂⠂⠂⢀⠌⢰⡿⠌⠂⠂⢸⡏⠂⠂⠂⠂⠂⢀⣟⣟⣟⣟⣟⡆⠂⠂⢸⡇⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠕⣟⠌⠂⠂⠂⠂⣼⣇⣟⠃⠂⠂⠌⣼⠇⠂⠂⠂⠂⠂⠌⠉⠉⠉⠉⠉⠁⠂⠂⢸⡇⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠕⣟⠌⠂⠂⠂⠂⣫⣿⠏⠂⠂⠂⠌⣟⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢸⡇⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠕⣟⠌⠂⠂⠂⠂⢿⡿⠌⠂⠂⠂⢸⡟⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢸⡇⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠕⣟⠌⠂⠂⠂⠂⠘⠁⠂⠂⠂⠂⣼⡇⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢸⡇⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠕⣟⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠌⣫⠁⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⢸⡇⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠌⣟⣄⡀⠌⠌⠌⠌⠌⠌⠌⠌⣰⣟⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣼⡇⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂
⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠘⣟⣟⣟⣟⣟⣟⣟⣟⣟⣟⣿⣿⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣟⡟⠌⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂⠂)"
                 << endl;
            cout << "\nEl Heladero, con cara extrañada: \"No sé si te entendí.\"\n";
            cout << "Presioná Enter para volver a elegir...\n";
            cin.ignore().get();
            volver = true;
            system("clear");
            break;
        }
    }

    cout << "Gracias por jugar!\n"
         << "Apretá Enter para volver al menú...\n";
    cin.ignore(1000, '\n');

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
    cin >> opcion; // esto se va a romper si ingresan una string.
    cout << endl;

    switch (opcion)
    {
    case EMPEZAR:
        empezar_juego();
        break;
    case CREDITOS:
        cout << "Con ustedes: \n\n";
        cout << "Brenda Lopez,\n\n";
        cout << "Candela Suarez,\n\n";
        cout << "Francisco Savariano,\n\n";
        cout << "Tobias Lopez\n\n";
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