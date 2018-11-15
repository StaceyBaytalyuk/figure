#ifndef FIGURE_FIGURE_H
#define FIGURE_FIGURE_H

class Figure {
public:
    Figure(int x, int y, double radius);
    ~Figure(){}
    void show();
    void move(int dx, int dy) { _point[0].x += dx; _point[0].y += dy; }
    void zoom(double n) { _radius *= n; }
    void rotate(int deg) { _angle += deg; }

private:
    void _initPoints();
    void _hide();
    void _draw(); //рисует одну чертверть фигуры
    void _drawLine(int x1, int y1, int x2, int y2);
    void _drawArc(int x, int y, int radius, int start, int end);

    struct Point{
        double x;
        double y;
    } _point[8];
    double _radius;
    double _angle;
};

#endif //FIGURE_FIGURE_H