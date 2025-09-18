#include "Bocha.h"

Bocha::Bocha(int x, int y)
{
    _x = x;
    _y = y;
    _delay_caida = 3;
}

void Bocha::draw()
{
    mvprintw(_y, _x, "O");
}

void Bocha::update()
{
    _delay_caida--;
    if (_delay_caida <= 0)
    {
        _y++;
        _delay_caida = 3;
    }
}

int Bocha::get_x()
{
    return _x;
}

int Bocha::get_y()
{
    return _y;
}

void Bocha::set_x(int nuevo_x)
{
    _x = nuevo_x;
}

void Bocha::set_y(int nuevo_y)
{
    _y = nuevo_y;
}