#include <iostream>
#include "Canvas.h"

using namespace std;

bool okc,okr;

Canvas::Canvas(int width,int height)
{
    this->width=width;
    this->height=height;
    for (int i=0; i<width; ++i)
        for (int j=0; j<height; ++j)
            this->a[i][j]=' ';
}

void filll(int n,int m,char a[][100],int x,int y,char ch)
{
    if (a[x][y]==' ')
    {
        a[x][y]=ch;
        filll(n,m,a,x-1,y,ch);
        filll(n,m,a,x+1,y,ch);
        filll(n,m,a,x,y-1,ch);
        filll(n,m,a,x,y+1,ch);
    }
}

void Canvas::DrawCircle(int xm,int ym,int r,char ch)
{
    //system("cls");
    int x=-r,y=0,err=2-2*r,r1=r;
    do
    {
      a[xm-x][ym+y]=ch;
      a[xm-x][ym-y]=ch;
      a[xm+x][ym-y]=ch;
      a[xm+x][ym+y]=ch;
      r = err;
      if (r <= y) err += ++y*2+1;
      if (r>x || err>y) err+=++x*2+1;
    }
    while (x<0);
    a[xm][ym-r1]=a[xm][ym+r1]=ch;
    okc=1;
}

void Canvas::FillCircle(int xm,int ym,int r,char ch)
{
    if (okc==0) return;
    filll(width,height,a,xm,ym,ch);
}

void Canvas::DrawRect(int left,int top,int right,int bottom,char ch)
{
    if (left<0 || right>width || top<0 || bottom>height) return;
    //system("cls");
    okr=1;
    int i;
    for (i=left; i<=right; ++i)
        a[i][top]=a[i][bottom]=ch;
    for (i=top; i<=bottom; ++i)
        a[left][i]=a[right][i]=ch;
}

void Canvas::FillRect(int left,int top,int right,int bottom,char ch)
{
    if (okr==0) return;
    filll(width,height,a,(left+right)/2,(top+bottom)/2,ch);
}

void Canvas::SetPoint(int x,int y,char ch)
{
    if (x<0 || x>width || y<0 || y>height) return;
    a[x][y]=ch;
}

void Canvas::DrawLine(int x1,int y1,int x2,int y2,char ch)
{
    int dx= abs(x2-x1),sx = x1<x2 ? 1 : -1;
    int dy=-abs(y2-y1),sy = y1<y2 ? 1 : -1;
    int err=dx+dy,e2;
    while(1)
    {
       a[x1][y1]=ch;
       if (x1==x2 && y1==y2) break;
       e2=2*err;
       if (e2>=dy) {err+=dy; x1+=sx;}
       if (e2<=dx) {err+=dx; y1+=sy;}
    }
}

void Canvas::Print()
{
    for (int i=0; i<width; ++i)
    {
        for (int j=0; j<height; ++j)
            cout << a[i][j];
        cout << '\n';
    }
}

void Canvas::Clear()
{
    for (int i=0; i<width; ++i)
        for (int j=0; j<height; ++j)
            a[i][j]=' ';
    okc=okr=0;
}
