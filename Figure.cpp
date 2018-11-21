#include "Figure.h"
#include <cmath>
#include <grx20.h>
#include <grxkeys.h>
using namespace std;

Figure::Figure( int x, int y, double radius ) {
    _point[0].x = x;
    _point[0].y = y;
    _radius = radius;
    _angle = 0;
    _calculatePoints();
}

void Figure::_calculatePoints() {
    double deg = _angle*(M_PI/180);
    double sin1 = sin(deg);
    double cos1 = cos(deg);
    int x, y;

    x = 1.55 * _radius * cos1 - 1.55 * _radius * sin1;
    y = 1.55 * _radius * cos1 + 1.55 * _radius * sin1;
    _point[1].x = x + _point[0].x;
    _point[1].y = y + _point[0].y;

    x = 1.25 * _radius * cos1 - 1.25 * _radius * sin1;
    y = 1.25 * _radius * cos1 + 1.25 * _radius * sin1;
    _point[2].x = x + _point[0].x;
    _point[2].y = y + _point[0].y;

    x = 2.25 * _radius * cos1 - 2.25 * _radius * sin1;
    y = 2.25 * _radius * cos1 + 2.25 * _radius * sin1;
    _point[3].x = x + _point[0].x;
    _point[3].y = y + _point[0].y;

    x = 2 * _radius * cos1;
    y = 2 * _radius * sin1;
    _point[4].x = x + _point[0].x;
    _point[4].y = y + _point[0].y;

    x = 2.5 * _radius * cos1 + 0.5 * _radius * sin1;
    y = 2.5 * _radius * sin1 - 0.5 * _radius * cos1;
    _point[5].x = x + _point[0].x;
    _point[5].y = y + _point[0].y;

    x = 3 * _radius * cos1;
    y = 3 * _radius * sin1;
    _point[6].x = x + _point[0].x;
    _point[6].y = y + _point[0].y;

    x = 2.5 * _radius * cos1 - 0.5 * _radius * sin1;
    y = 0.5 * _radius * cos1 + 2.5 * _radius * sin1;
    _point[7].x = x + _point[0].x;
    _point[7].y = y + _point[0].y;
}

void Figure::show() {
    _hide();
    for(int i=0; i<4; i++){
        _calculatePoints();
        _draw();
        rotate(90);
    }
}

void Figure::_hide() {
    GrClearContext(GrWhite());
}

void Figure::_draw() {
    GrCircle(_point[0].x, _point[0].y, _radius, GrBlack());
    GrLine(_point[0].x, _point[0].y, _point[1].x, _point[1].y, GrBlack());
    GrLine(_point[0].x, _point[0].y, _point[4].x, _point[4].y, GrBlack());
    GrLine(_point[4].x, _point[4].y, _point[5].x, _point[5].y, GrBlack());
    GrLine(_point[5].x, _point[5].y, _point[6].x, _point[6].y, GrBlack());
    GrLine(_point[6].x, _point[6].y, _point[7].x, _point[7].y, GrBlack());
    GrLine(_point[7].x, _point[7].y, _point[4].x, _point[4].y, GrBlack());
    GrCircleArc(_point[2].x, _point[2].y, _radius, -10*_angle+2700, -10*_angle+3600, 0, GrBlack());
    GrCircleArc(_point[3].x, _point[3].y, _radius, -10*_angle+900, -10*_angle+1800, 0, GrBlack());
}