#pragma once

#include <ncurses.h>

class Bocha
{
    public:
        Bocha(int x, int y);
        void draw();
        void update();
        int get_x();
        int get_y();

    private:
        int _x;
        int _y;
};