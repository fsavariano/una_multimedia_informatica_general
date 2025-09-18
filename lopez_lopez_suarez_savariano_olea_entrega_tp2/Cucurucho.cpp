#include "Cucurucho.h"

// Cucurucho::Cucurucho()
// {
//     _turbo = false;
//     _x = 70;
//     _y = 20;
// }

void Cucurucho::setup()
{
    _turbo = false;
    _x = 70;
    _y = 36; // podría ser const pero va a putear corriendo setup()
}

void Cucurucho::update()
{
    // lógica del cucutrucho
}

void Cucurucho::draw()
{
    mvaddch(_y, _x + 1, ACS_HLINE);
    mvaddch(_y, _x + 2, ACS_HLINE);
    mvaddch(_y, _x + 3, ACS_HLINE);

    mvaddch(_y + 1, _x, '\\');
    mvaddch(_y + 1, _x + 1, ' ');
    mvaddch(_y + 1, _x + 2, ' ');
    mvaddch(_y + 1, _x + 3, ' ');
    mvaddch(_y + 1, _x + 4, '/');

    mvaddch(_y + 2, _x + 1, '\\');
    mvaddch(_y + 2, _x + 2, ' ');
    mvaddch(_y + 2, _x + 3, '/');
}

void Cucurucho::set_x(int nuevo_x)
{
    _x = nuevo_x;
}

void Cucurucho::set_turbo(bool status)
{
    _turbo = status;
}

bool Cucurucho::get_turbo_status()
{
    return _turbo;
}

bool Cucurucho::hay_colision(Bocha bocha)
{
    if (bocha.get_y() >= _y && bocha.get_y() <= _y + 2) // la bocha está entre las filas del cucu
    {
        if (bocha.get_x() >= _x && bocha.get_x() <= _x + 4) // si la bocha está entre los límites del cucurucho
        {
            return true;
        }
    }
    return false;
}

int Cucurucho::get_x()
{
    return _x;
}

int Cucurucho::get_speed()
{
    if (_turbo)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}