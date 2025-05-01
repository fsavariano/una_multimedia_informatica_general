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
    cout << R"(                                                                                                                        
                                                                                                                        
                                                                                                                        
                    .                              ..';cllolll:,..                             ..'.,.'....              
                    .                           .':lcloddddddoolcoo;,..                  ...,...''',,,''.....           
             ..  ..... ...      .             'ooloolokkxdxxxkxddkxllxo.               .''..:;',;;;;;';:;.....''        
             ...........        .            ,okdoololoxkdOOkOOxOOxololo'             .....':c:;c::c:,c,'....'':.       
      .     .....'.......   .               .oxoockdoddkOxOOkkXkxkxdoolcxk:         .c...'.,;:;:c::::;c;''.'...,'.      
            ......... .. ...                ,:ldxooxxkxxOxxkk00xkkxdolcloxd'       .',.....,:;;:cc:;,;:,:;,''',...      
            .. . ...  .....                 ;ccodxxxxk0kxkdkOkxxkkOoollooc.          ......';,;,,::,';;c:;,,,,'...      
         .      .........  ..                ':clldOdxxkOOOxkOOkxddoodxl'             .';...'',:::;;:::;,,,;.....       
          .'',''..',,'.''......                ..;:ccoddooxOOkkxxxxdl:                  .;;::c:::cll;;::,'....          
          .;:coooolll:;;;',.'.                    .'.,';;;:lllolooc:;.                   '::looolllc;;:'',...           
           .;::locllc:;;,''...                    ...'',;;:cllcll::;.                    .,::clccll:;;,''...            
            ,;:ccllc:::'''...                      ...''':::cllcc:;,                      .;;cccll:::,'''...            
            .,;:clc:::;,''...                      ....',,:::ccc:;,.                       ';:cll:c:;,''...             
             ',;cc:c:,,,....                        ....,,,:c:cc;,'                        .,,:lcc::,,'....             
             .,;::cl:;,'....                        ....',;:lc::;,.                         ';;:ccc;,'....              
              .,;cl:;,,'...                          ...',,;clc;,.                           ';:ll;,,'....              
               ';cc:;;,'...                          ...',;;:cc;'                            .,:c:;;,,'..               
               .,;cc:;,'..                            ..',,:cc;,.                             ',:c:;,'..                
                .;c:;;'..                              ..';;:c;.                              .,:::;,'..                
                 ,:cc,'..                              ..',cc:,                                .;cc:'..                 
                 .:c:,..                                ..,:c:.                                 ,cc;'.                  
                  'c:,.                                  .,:c'                                  .:c,'.                  
                   ;c;.                                  .;c;                                    'c:'                   
                   'c'                                    'c'                                     c;.                   
                    .                                      .                                      ..                    
                                                                                                                       )";
    cout << "\n\n\n\n\n\n\n\n\n\n";

    cout << "\t\t\t\testa es la primera pantalla woooooooo\n";
    return;
}

void main_menu(){
    //esto hay que hacerlo con switch
    system("clear");

    int option = -1;

    enum dificultad{
        START=1,
        CREDITS,
        EXIT
    };

    cout << "Ingresá una opción...\n";
    cin >> option;

    switch (option)
    {
    case START:
        start_game();
        break;
    case CREDITS:
        cout << "esto todavía no está programado... \n";
        break;
    case EXIT:
        cout << "esto todavía no está programado... \n";
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
    
    main_menu();

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