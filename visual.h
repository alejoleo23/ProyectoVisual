#ifndef VISUAL_H
#define VISUAL_H
#include <iostream>
using namespace std;
#endif
void gotoxy(int,int);
void Pintar();
void cuadro(int,int,int,int);
void otracajita();
void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}
void Pintar()
{
	int i;
	cuadro(111,24,115,26);
	gotoxy(113,25);
	gotoxy(113,25);
	cout<<(char)32;
	cout<<(char)32;
	cout<<(char)186;
	for(i=0;i<25;i++)
		cout<<(char)32;
}
void cuadro(int x1, int y1, int x2, int y2)
{
	int i, a, c;
	gotoxy(x1,y1);
	cout<<(char)201;//esquina izquierda superior
	a=x2-x1;
	for(i=0;i<a-1;i++)
		cout<<(char)205;//parte de arriba
	c=y2-y1;
	for(i=1;i<=c;i++)
	{
		gotoxy(x1,y1+i);
		cout<<(char)186;//columna izquierda
	}
	gotoxy(x2,y1);
	cout<<(char)187;//parte derecha superior
	for(i=1;i<=c;i++)
	{
		gotoxy(x2,y1+i);
		cout<<(char)186;//columna derecha
	}
	gotoxy(x1,y2);
	cout<<(char)200;//esquina izquierda inferior
	for(i=1;i<=a-1;i++)
	{
		gotoxy(x1+i,y2);
		cout<<(char)205;//parte de abajo
	}
	gotoxy(x2,y2);
	cout<<(char)188;//parte inferior derecha
}
void otracajita()
{
	int i;
	gotoxy(30,10);
	for(i=0;i<=120;i++)
	{
		cout<<(char)205;
	}
}
