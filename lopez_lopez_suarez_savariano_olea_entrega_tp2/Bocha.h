#pragma once

#include "ncurses.h"

class Bocha
{
  public:
    Bocha(int x, int y);
    void draw();
    void update();
    int get_x();
    int get_y();
    void set_x(int nuevo_x);
    void set_y(int nuevo_y);

  private:
    int _x;
    int _y;
    int _delay_caida; // cada cuántos frames bajan
};