#pragma once // para no incluir cosas más de una vez

#include "Bocha.h"
#include <ncurses.h>

class Cucurucho
{
  public:
    void setup(); // no alcanza con el constructor porque se "resetea" cada vez que arranque el juego.
    void update();
    void draw();
    void set_x(int x);
    void set_turbo(bool estado);
    bool get_turbo_status();
    bool hay_colision(Bocha bocha);
    int get_x();
    // int get_y();
    int get_speed();

  private:
    int _x;
    int _y;
    bool _turbo;
    int _cant_bochas; // para dibujarlas
};