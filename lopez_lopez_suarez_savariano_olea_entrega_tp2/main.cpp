/*CRITERIOS DE TP2
●​ Instrucciones del juego donde además se explique la idea del trabajo.
✓​ Uso variado de funciones de NCURSES
✓ Uso de CONSTANTES ENUMERADAS
✓ Uso de aleatoriedad con RANDOM
​✓ Uso del objeto STRING
✓ Uso de ARREGLOS
✓​​ Uso de VECTOR
✓​ Uso de FUNCIONES
✓ Uso de CLASES y OBJETOS (no es obligatorio)
✓ El videojuego deberá tener un título
●​ El juego, al perder o ganar, debe volver al menú principal para poder
jugar nuevamente.
*/

#include "Bocha.h"
#include "Cucurucho.h"
#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ncurses.h>
#include <vector>

using namespace std;

// consts/enum

const int ANCHO = 120;
const int ALTO = 40;
const int DELAY = 30; // en ms
const array<string, 7> SABORES = {"Frutilla", "Chocolate", "Vainilla", "Vino", "White Russian", "Trapo de Piso", "Hormiga, Damasco y Pimienta"};

enum TECLAS
{
    IZQ = KEY_LEFT,
    DER = KEY_RIGHT,
    TURBO = 'x',
    ESC = 27
};

// vars

bool game_over;
bool salir;
int puntaje;
int spawn_timer;
int popup_timer;
bool mostrar_sabor;
int sabor;

Cucurucho jugador;
vector<Bocha> bochas;

// funciones globales

void setup();
void input();
void update();
void draw();
void main_menu();
void dibujar_pantalla_inicio();
void gameover();
void print_hud();

int main()
{

    // setlocale(LC_ALL, ""); // capaz necesitemos esto

    srand(time(0)); // metemos semilla para rand

    // falopa de ncurses
    initscr();
    noecho();              // impide printear caracteres
    curs_set(FALSE);       // oculta mouse
    keypad(stdscr, TRUE);  // uso de keypad. stdscr es un puntero a la ventana
    nodelay(stdscr, TRUE); //?? más falopa

    noecho();
    if (LINES < ALTO || COLS < ANCHO) // copypasteado, previene jugar con dimensiones incorrectas
    {
        endwin(); //"sale" de ncurses
        printf("La terminal tiene que tener como mínimo %dx%d\n\n", ANCHO, ALTO);
        exit(1);
    }

    setup();

    dibujar_pantalla_inicio();

    salir = false;

    while (!salir) // esto funciona mejor que el choclo del tp1
    {
        while (!game_over)
        {
            input();
            update();
            draw();
        }
        gameover();
    }

    endwin(); //"sale" de ncurses

    cout << endl;
    return 0;
}

void setup()
{
    game_over = FALSE; // por qué en mayúsculas?

    jugador.setup();

    bochas.clear(); // limpia el vector
    bochas.push_back(Bocha(rand() % 118 + 1, 2));

    puntaje = 0;
    spawn_timer = 30 + rand() % 30;
    popup_timer = 60;
    mostrar_sabor = false;
    sabor = rand() % 7;
}

void input() //
{
    int tecla = getch();

    switch (tecla)
    {
    case IZQ:
        if (jugador.get_x() > 1)
            jugador.set_x(jugador.get_x() - jugador.get_speed());
        break;
    case DER:
        if (jugador.get_x() < ANCHO - 6)
            jugador.set_x(jugador.get_x() + jugador.get_speed());
        break;
    case ESC: // apretar escape para terminar el juego
        game_over = TRUE;
        break;
    case TURBO: // tecla x
        jugador.set_turbo(!jugador.get_turbo_status());
        break;
    default:
        break;
    }
}

void update() // gameplay
{
    jugador.update();

    for (int i = 0; i < bochas.size(); i++)
    {
        if (bochas[i].get_y() >= ALTO - 1)
        {
            game_over = true;
        }
    }

    if (spawn_timer > 0)
    {
        spawn_timer--;
    }
    else
    {
        bochas.push_back(Bocha(rand() % 118 + 1, 2));
        spawn_timer = 30 + rand() % 30;
    }

    for (int i = 0; i < bochas.size(); i++)
    {
        bochas[i].update();
        if (jugador.hay_colision(bochas[i]))
        {
            puntaje++;
            bochas.erase(bochas.begin() + i); // igual creo que siempre sería la primera...
            sabor = rand() % 7;
            mostrar_sabor = true;
            popup_timer = 60;
        }
    }
}

void draw() // gráficos
{
    // uso mvprint para strings y mvaddch para chars
    erase();
    box(stdscr, 0, 0); // dibujar bordes

    print_hud(); // más organizado

    jugador.draw();

    for (int i = 0; i < bochas.size(); i++)
    {
        bochas[i].draw();
    }

    if (popup_timer > 0)
    {
        popup_timer--;
        if (mostrar_sabor)
        {
            mvprintw(1, 1, "%s", (SABORES[sabor] + '!').c_str()); // finalmente :)
        }
    }
    else
    {
        mostrar_sabor = false;
    }

    refresh();
    delay_output(DELAY);
}

void print_hud()
{
    mvhline(2, 1, '~', 118);

    int cifras_puntaje = to_string(puntaje).length(); // menos complicado que hacerlo con cuenta
    mvprintw(1, 51, "[ PUNTUACION:     ]");
    for (int i = 0; i < 4 - cifras_puntaje; i++)
    {
        mvaddch(1, 64 + i, '0');
    }
    mvprintw(1, 68 - cifras_puntaje, "%d", puntaje);
    mvprintw(1, 100, "{ TURBO:      }");
    if (jugador.get_turbo_status())
    {
        mvprintw(1, 110, "SI");
    }
    else
    {
        mvprintw(1, 110, "NO");
    }
}

void gameover() // copio para tener un ejemplo por ahora
{
    for (int y = 10; y < 16; y++)
        mvhline(y, 40, ' ', 40);

    mvaddch(9, 39, ACS_ULCORNER);
    mvaddch(9, 80, ACS_URCORNER);
    mvaddch(16, 39, ACS_LLCORNER);
    mvaddch(16, 80, ACS_LRCORNER);

    mvhline(9, 40, ACS_HLINE, 40);
    mvhline(16, 40, ACS_HLINE, 40);

    mvvline(10, 39, ACS_VLINE, 6);
    mvvline(10, 80, ACS_VLINE, 6);

    mvprintw(12, 55, "GAME OVER");
    mvprintw(13, 50, "VOLVER A JUGAR? (S/N)");

    int opcion = getch();

    if (opcion == 's' || opcion == 'S')
    {
        game_over = false;
        setup();
    }
    else if (opcion == 'n' || opcion == 'N')
    {
        salir = TRUE;
    }
}

void dibujar_pantalla_inicio()
{
    vector<string> arte = {
        R"(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@%++%@@++%@*==+++*%@#*@@@@@@#++==*@@#==+=#@@@#+++=+++#%==++++#@@@@@@%+==#%@@@@@@%+-=#@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@# .%@%  *@= -**##@@=:@@@@@@- == :%@+ .#*-.=@@##: -#%@* .**##%@@@@@*-+*+..%@@@@= -#*. #@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@# :%@@. #@= +@@@@@@=:@@@@@%-.#% .%@+ :@@@: *@@@= =@@@* :@@@@@@@@@@@@@@%: %@@@@- +@@- *@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@% :%@@. #@= +@@@@@@-:@@@@@%::%@..#@* -@@@: *@@@= =@@@* :@@@@@@@@@@@@@@%: %@@@@- +@@- *@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@% .***. %@= -***#@@-:%@@@@%:-%@=.*@* -@@#:.#@@@+ +@@@* .***#@@@@@@@@@#+:-@@@@@- +@@- *@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@@ :*#*: %@= -**#%@@::%@@@@#.-*#=.*@* :=-.=#@@@@+ *@@@* .**##@@@@@@%+-=*#@@@@@@- +@@- *@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@@ -@@@- @@= +@@@@@@..#@@@@# -+++ +@# =@+ +@@@@@* #@@@* .@@@@@@@@@@+ =@@@@@@@@@- +@@- *@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@@.-@@@-.@@= =@@@@@@..#@@@@*.#@@@:=@% +@@-:@@@@@* #@@@# :@@@@@@@@@@= =@@@@@@@@@- +@@- *@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@@:=@@@=.@@= =%%@%@@ .*%%%@+:%@@@=-@% *@@#:*@@@@* %@@@* .%%%%@@@@@@= =%%%%@@*#@= =%%: *@@@@@@@@@@%#@@%%@)",
        R"(@@@@@@@@@@@@@@@@@@=+@@@+-@@+:-++**@@::-+++**+@@@@*=@@-#@@@*+@@@@#:@@@@#::=+++#@@@@@*.-+++*%%=*@#=-==-+%@@@@@@@@%##@@%%@@)",
        R"(@@@@@@@@@@@@@@@@@@%@@@@%%@@%%#%%%%@@###%%%%%%@@@@@%@@%@@@@@%@@@@@%@@@@@#%#%%%@@@@@@%#%#%%%@@%@@@@%##%@@@@@@%@@%*%@@%%@@@)",
        R"(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%@@#*%%%#@@@@@)",
        R"(@#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@##@@##@%##@@@@@@)",
        R"(@@#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#%@@*#@@##@@@@@@@)",
        R"(@@@%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@##%%@#%@%#%@%@@@@@@)",
        R"(@@@@@@%%@@@%##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#+=--=%@%##%%%@@@@@@)",
        R"(@@%@@%%%%@@@#**%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+:.    +@##%##@@@@@@@)",
        R"(@@%#%@%#%##@@@*=#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+.      -%#%*%@@@@@@@@)",
        R"(@@@%+#@@%@*+@*#%-+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#.       =@%+%@@@@@@@@@)",
        R"(@@@@@*=#%%@#*%*#%*=%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=       .#**@@@@@@@@@@@)",
        R"(@@@@@@%**%@@@#%##@#-+#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:       -*#@@@@@@@@@@@@)",
        R"(@@@@@@@@%*#@@@%@@+:. .-+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%-      -*%@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@%*%@@%=.      -#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%*-   -*%@@@@@@@@@@@@@@@)",
        R"(@@@@@@%%@@@*%@=.        :*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@####%@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@%*@@@%#:          :#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@#*%@@%-.          -@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@%+*@@*+.         .#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@%**%##+:         +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@#+#*==.        =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@%+#: :.       =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@%*#::*.     -*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@%%+*+-. .=*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@@@@%##=-+#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@@@@@@@%%@@@@@@@@@@@@@@@@"APRETA ENTER DOS VECES PARA EMPEZAR"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(no preguntes por que dos veces)@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",
        R"(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)"};

    // dibuja el ASCII en pantalla
    for (int i = 0; i < (int)arte.size(); i++)
    {
        mvprintw(i, 0, "%s", arte[i].c_str());
    }

    refresh();  // muestra en pantalla
    flushinp(); // limpia buffer de teclas
    getch();    // espera una tecla
}