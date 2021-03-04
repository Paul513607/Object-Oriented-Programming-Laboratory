#include <iostream>
#include "Canvas.h"

using namespace std;

int main()
{
    Canvas myCanvas(25,25);
    myCanvas.DrawCircle(10,10,8,'#');
    myCanvas.FillCircle(10,10,8,'*');
    myCanvas.Print();
    myCanvas.Clear();
    myCanvas.DrawRect(10,10,20,20,'#');
    myCanvas.FillRect(10,10,20,20,'*');
    myCanvas.Print();
    myCanvas.Clear();
    myCanvas.SetPoint(5,5,'p');
    myCanvas.DrawLine(10,10,20,20,'l');
    myCanvas.Print();
    cout << "Scroll up to see all the tests.\n";
    return 0;
}
