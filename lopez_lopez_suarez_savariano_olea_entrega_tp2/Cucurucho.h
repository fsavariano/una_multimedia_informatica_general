#pragma once

#include <ncurses.h>

class Cucurucho
{
  public:
    Cucurucho();

    void setup(); // no alcanza con el constructor porque voy a "resetearlo" cada vez que arranque el juego.
    void update();
    void draw();
    void set_x(int x);
    void turbo_on();
    void turbo_off();
    bool get_turbo_status();
    bool hay_colision(Bocha bocha);

    int get_x();
    int get_y();

  private:
    bool _turbo;
    int _x;
    int _y;
};