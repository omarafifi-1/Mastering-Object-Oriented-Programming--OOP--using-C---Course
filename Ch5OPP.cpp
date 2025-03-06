#include <iostream>
using namespace std;
#include <graphics.h>

class Point
{
    int x;
    int y;

    public:

    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int z , int d)
    {
        x = z;
        y = d;
    }
    void setx(int z)
    {
        x = z;
    }
    void sety(int d)
    {
        y = d;
    }
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
};

class Line
{
    Point start;
    Point end;
    
    public:

    Line(): start(), end()
    {
        cout<<"Line Created"<<endl;
    }
    Line(int x, int y, int z, int d): start(x, y), end(z, d)
    {
        cout<<"Line Created"<<endl;
    }
    void lineDraw()
    {
        line(start.getx() , start.gety() , end.getx() , end.gety());
    }
};

class Rect
{
    Point ul;
    Point lr;
    
    public:

    Rect(): ul(), lr()
    {
        cout<<"Rect Created"<<endl;
    }
    Rect(int x, int y, int z, int d): ul(x, y), lr(z,d)
    {
        cout<<"Rect Created"<<endl;
    }
    void rectDraw()
    {
        rectangle(ul.getx() , ul.gety() , lr.getx() , lr.gety());
    }
};

class Circle
{
    int radius;
    Point center;

    public:

    Circle(): center()
    {
        radius = 0;
        cout<<"Circle Created"<<endl;
    }
    Circle(int x, int y, int z): center(x, y)
    {
        radius = z;
        cout<<"Circle Created"<<endl;
    }
    void circleDraw()
    {
        circle(center.getx() , center.gety() , radius);
    }
};

class Picture
{
    int lcount;
    int rectcount;
    int circount;
    Line* pLines;
    Rect* pRects;
    Circle* pCircs;

    public:

    Picture()
    {
        lcount = 0;
        rectcount = 0;
        circount = 0;
        pLines = NULL;
        pRects = NULL;
        pCircs = NULL;
    }
    Picture(int lcoun, int rectcoun, int circoun, Line* pL, Rect* pR, Circle* pC)
    {
        lcount = lcoun;
        rectcount = rectcoun;
        circount = circoun;
        pLines = pL;
        pRects = pR;
        pCircs = pC;
    }
    void setLines(int lcoun, Line* pL)
    {
        lcount = lcoun;
        pLines = pL;
    }
    void setRects(int rectcoun, Rect* pR)
    {
        rectcount = rectcoun;
        pRects = pR;
    }
    void setCircs(int circoun, Circle* pC)
    {
        circount = circoun;
        pCircs = pC;
    }
    void drawPic()
    {
        for(int i = 0; i < lcount; i++)
        {
            pLines[i].lineDraw();
        }
        for(int i = 0; i < rectcount; i++)
        {
            pRects[i].rectDraw();
        }
        for(int i = 0; i < circount; i++)
        {
            pCircs[i].circleDraw();
        }
    }
    printPic()
    {
        cout<<"Lines: "<<lcount<<endl;
        cout<<"Rectangles: "<<rectcount<<endl;
        cout<<"Circles: "<<circount<<endl;
    }
};

int main() 
{
    Picture p;
    Circle cArr[3] = {Circle(100, 100, 50), Circle(200, 200, 100), Circle(300, 300, 150)};
    Line lArr[3] = {Line(100, 100, 200, 200), Line(200, 200, 300, 300), Line(300, 300, 400, 400)};
    Rect rArr[3] = {Rect(100, 100, 200, 200), Rect(200, 200, 300, 300), Rect(300, 300, 400, 400)};

    p.setLines(3, lArr);
    p.setRects(3, rArr);
    p.setCircs(3, cArr);

    p.drawPic();
    p.printPic();
    return 0;
}