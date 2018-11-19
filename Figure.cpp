#include "Figure.h"
#include <iostream>
#include <cmath>
#include <grx20.h>
#include <grxkeys.h>
using namespace std;

Figure::Figure( int x, int y, double radius ) {
    _point[0].x = x;
    _point[0].y = y;
    _radius = radius;
    _angle = 0;
    _initPoints();
}

void Figure::_initPoints() {
    _point[1].x = 1.55 * _radius;
    _point[1].y = 1.55 * _radius;

    _point[2].x = 1.25 * _radius;
    _point[2].y = 1.25 * _radius;

    _point[3].x = 2.25 * _radius;
    _point[3].y = 2.25 * _radius;

    _point[4].x = 2 * _radius;
    _point[4].y = 0;

    _point[5].x = 2.5 * _radius;
    _point[5].y = -0.5 * _radius;

    _point[6].x = 3 * _radius;
    _point[6].y = 0;

    _point[7].x = 2.5 * _radius;
    _point[7].y = 0.5 * _radius;
}

void Figure::show() {
    _hide();
    _initPoints(); //чтобы фигура не рассыпалась при зуме
    for(int i=0; i<4; i++){
        _draw();
        rotate(90);
    }
}

void Figure::_hide() { GrClearContext(GrWhite()); }

void Figure::_draw() {
    GrCircle(_point[0].x, _point[0].y, _radius, GrBlack());
    _drawLine(0, 0, _point[1].x, _point[1].y);
    _drawLine(0, 0, _point[4].x, _point[4].y);

    _drawArc(_point[2].x, _point[2].y, _radius, 2700, 3600);
    _drawArc(_point[3].x, _point[3].y, _radius, 900, 1800);

    _drawLine(_point[4].x, _point[4].y, _point[5].x, _point[5].y);
    _drawLine(_point[5].x, _point[5].y, _point[6].x, _point[6].y);
    _drawLine(_point[6].x, _point[6].y, _point[7].x, _point[7].y);
    _drawLine(_point[7].x, _point[7].y, _point[4].x, _point[4].y);
}

void Figure::_drawLine(int x1, int y1, int x2, int y2) {
    double deg = _angle*(M_PI/180);
    double SIN = sin(deg);
    double COS = cos(deg);
    int X1, Y1, X2, Y2;
    X1 = x1 * COS - y1 * SIN;
    Y1 = y1 * COS + x1 * SIN;
    X2 = x2 * COS - y2 * SIN;
    Y2 = y2 * COS + x2 * SIN;
    GrLine(X1+_point[0].x, Y1+_point[0].y, X2+_point[0].x, Y2+_point[0].y, GrBlack());
}

void Figure::_drawArc(int x, int y, int radius, int start, int end) {
    double deg = _angle*(M_PI/180);
    double SIN = sin(deg);
    double COS = cos(deg);
    int X, Y;
    X = x * COS - y * SIN;
    Y = y * COS + x * SIN;
    GrCircleArc(X+_point[0].x, Y+_point[0].y, radius, -10*_angle+start, -10*_angle+end, 0, GrBlack());
}