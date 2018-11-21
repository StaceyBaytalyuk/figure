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
    void _calculatePoints();
    void _hide();
    void _draw();

    struct Point{
        int x;
        int y;
    } _point[8];
    double _radius;
    int _angle;
};

#endif //FIGURE_FIGURE_H