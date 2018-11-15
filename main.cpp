#include <grx20.h>
#include <grxkeys.h>
#include "Figure.h"

int main() {
    GrSetMode( GR_default_graphics );
    Figure figure(200, 200, 50);
    figure.show();
    while(true){
        switch(GrKeyRead())
        {
            case 'w': figure.move(0, -25); break;
            case 's': figure.move(0, 25); break;
            case 'd': figure.move(25, 0); break;
            case 'a': figure.move(-25, 0); break;
            case 'l': figure.rotate(-5); break;
            case 'p': figure.rotate(5); break;
            case 't': figure.zoom(2); break;
            case 'r': figure.zoom(0.5); break;
            case 'q': return 0;
            default:break;
        }
        figure.show();
    }
}