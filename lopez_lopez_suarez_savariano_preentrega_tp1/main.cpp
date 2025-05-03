#include <string>
#include <iostream>

using namespace std;


/*
CRITERIOS DE EVALUACIÓN
-al menos (?) 5 pantallas
-un par de imágenes
-hacerun menú con switch
-volver al menú cuando termina el juego
-uso de while, for, if-else, and/or, float/int/bool y consts/enums
-un título
*/

//VARIABLES GLOBALES:

bool salida = false;

void print_start_screen(){
    for (int j= 0; j < 20; j++){
        cout << endl;
    }
    cout << "\t \t \t \t Hola, apretá Enter para empezar...";
    for (int j = 20; j < 40; j++){
        cout << endl;
    }
    cin.ignore().get();
    
    return;
}


void start_game(){
    system("clear");
    // cout << R"(                                                                                                                        
                                                                                                                        
                                                                                                                        
    //                 .                              ..';cllolll:,..                             ..'.,.'....              
    //                 .                           .':lcloddddddoolcoo;,..                  ...,...''',,,''.....           
    //          ..  ..... ...      .             'ooloolokkxdxxxkxddkxllxo.               .''..:;',;;;;;';:;.....''        
    //          ...........        .            ,okdoololoxkdOOkOOxOOxololo'             .....':c:;c::c:,c,'....'':.       
    //   .     .....'.......   .               .oxoockdoddkOxOOkkXkxkxdoolcxk:         .c...'.,;:;:c::::;c;''.'...,'.      
    //         ......... .. ...                ,:ldxooxxkxxOxxkk00xkkxdolcloxd'       .',.....,:;;:cc:;,;:,:;,''',...      
    //         .. . ...  .....                 ;ccodxxxxk0kxkdkOkxxkkOoollooc.          ......';,;,,::,';;c:;,,,,'...      
    //      .      .........  ..                ':clldOdxxkOOOxkOOkxddoodxl'             .';...'',:::;;:::;,,,;.....       
    //       .'',''..',,'.''......                ..;:ccoddooxOOkkxxxxdl:                  .;;::c:::cll;;::,'....          
    //       .;:coooolll:;;;',.'.                    .'.,';;;:lllolooc:;.                   '::looolllc;;:'',...           
    //        .;::locllc:;;,''...                    ...'',;;:cllcll::;.                    .,::clccll:;;,''...            
    //         ,;:ccllc:::'''...                      ...''':::cllcc:;,                      .;;cccll:::,'''...            
    //         .,;:clc:::;,''...                      ....',,:::ccc:;,.                       ';:cll:c:;,''...             
    //          ',;cc:c:,,,....                        ....,,,:c:cc;,'                        .,,:lcc::,,'....             
    //          .,;::cl:;,'....                        ....',;:lc::;,.                         ';;:ccc;,'....              
    //           .,;cl:;,,'...                          ...',,;clc;,.                           ';:ll;,,'....              
    //            ';cc:;;,'...                          ...',;;:cc;'                            .,:c:;;,,'..               
    //            .,;cc:;,'..                            ..',,:cc;,.                             ',:c:;,'..                
    //             .;c:;;'..                              ..';;:c;.                              .,:::;,'..                
    //              ,:cc,'..                              ..',cc:,                                .;cc:'..                 
    //              .:c:,..                                ..,:c:.                                 ,cc;'.                  
    //               'c:,.                                  .,:c'                                  .:c,'.                  
    //                ;c;.                                  .;c;                                    'c:'                   
    //                'c'                                    'c'                                     c;.                   
    //                 .                                      .                                      ..                    
    //                                                                                                                    )";
    // cout << "\n\n\n\n\n\n\n\n\n\n";

    // cout << "\t\t\t\testa es la primera pantalla woooooooo\n";

    for (int i = 0; i < 30; i++){
        cout << endl;
    }

    bool volver;
    volver = true;

    while (volver == true){
        volver = false;
        cout << R"(Heladero: "¿Qué te sirvo?")" << endl << endl;
        cout << "1- Sabor Frutilla\n";
        cout << "2- Sabor Vino\n";
        cout << "3- Sabor Trapo de Piso\n\n";
        
        enum opciones_de_sabor{
            NORMAL=1,
            ALCOHOL,
            RARO
        };

        int opcion_elegida;

        string respuesta;
        bool no_respondio = true;
        
        cin >> opcion_elegida;
    
        switch (opcion_elegida){
            case NORMAL:
                cout << "¿Un helado de Frutilla? ¡Perfecto!\n";
                cout << "*se le cae el helado*\n";
                //acá viene otra imagen probablemente"
                break;
            case ALCOHOL:
                cout << "Ok, pero para ese sabor te voy a tener hacer un par de preguntas. ¿Listo? (s/n)\n";
                
                bool listo;
                listo = true;

                while (no_respondio == true){
                    cin >> respuesta;
                    if (respuesta == "s" || respuesta == "S"){
                        listo = true;
                        no_respondio = false;
                    }else if (respuesta == "n" || respuesta == "N"){
                        listo = false;
                        no_respondio = false;
                    }else{
                        cout << "Respondé mi pregunta flacx\n";
                    }
                }
            
            if (listo == true){ //el usuario está listo, entonces empiezo las preguntas
                cout << "¿Qué edad tenés?\n";
                int edad;
                cin >> edad;
                if (edad < 18){
                    cout << "Sos menor, mejor pedite otro sabor.\n\n";
                    volver = true;
                }else{
                    //sigue otra pregunta, sí es mayor
                    cout << "acá vienen más preguntas, ponele\n";
                }
            }else{      //el usuario no está listo
                cout << "Entonces pedite otro sabor.\n";
                volver = true;
            }
            break;
        case RARO:
            cout << "¡Finalmente alguien pide los sabores buenos!\n";
            cout << "Probás el helado.\n" << "...\n" << "¡Está buenísimo! ¡¿Cómo no probaste esto antes?!\n" << "...\n";
            //cambiamos a una imagen de un hospital
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

void main_menu(){
    //esto hay que hacerlo con switch
    system("clear");

    int option = -1;

    enum dificultad{
        START=1,
        CREDITS,
        SALIR
    };

    cout << "Ingresá una opción...\n" << "1- Comenzar\n" << "2- Créditos\n" << "3- Salir a la terminal\n";
    cin >> option;

    switch (option)
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


int main(){
    //la resolución del juego es de 120 x 40 caracteres
    system("clear");

    print_start_screen();
    
    while (salida == false){
        main_menu();
    }

    return 0;
}


/*
-POV del cliente

-una primera imagen de la heladería, o la entrada, o el cartel de entrada, o el nombre de la heladería

-una segunda imagen donde te preguntan "qué querés flacx"

-te dan las opciones: uno normal, uno alcóholico y otro exótico/falopa

-con el normal siempre sale algo mal, se cae al piso, se equivoca de sabor etc. -> imagen 
-con el de alcohol sos menor, o el que atiende piensa que sos menor y te llena de preguntas -> no necesita una imagen nueva
    -tu nombre?
    -tu documento?
    -tu grupo sanguíneo?
    -comida favorita?
    -nombre de tu perro?
    - dos opciones: responder y ser paciente o cortarla y pedir otra cosa
-con el raro lo comés tranquilo y sale todo bien, pero terminás en el hospital -> una imagen más


*/