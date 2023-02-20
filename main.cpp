#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "visual.h"
#include "validaciones.h"
#include "administrador.h"
#include "usuario.h"
struct cliente{
	
	char nombre[40];
	int DNI;
};
struct Producto{
	char nombre[40];
	int precio;
};
void mostrarPrecios();
void MenuPrincipal();
void MenuAdmin();
void CotizarPresios();
void CambiarContrasena();
void MenuAdminContra();
void seleccionarAnalizis();
void MenuUsuario();

int main(int argc, char *argv[]) {
	ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
	
	MenuPrincipal();
	
	return 0;
}
void seleccionarAnalizis()
{
	int v[100],i=0,a,j,aux,r,suma=0,c,w;
	cliente x;
	
	ifstream archi("precios");
	
	if(!archi)
		cout<<"No se ha encontrado el archivo"<<endl;
	
	gotoxy(80,9);
	cout<<"Analisis\t\t\t\t      Precios "<<endl;
	gotoxy(56,10);
	for(i=0;i<=93;i++)
	{
		cout<<(char)205;
	}
	cuadro(55,8,150,22);	
	mostrarPrecios();
	gotoxy(95,6);
	cout<<"ESCOGER ANALISIS"<<endl;
	cout<<endl;
	gotoxy(66,27);
	cout<<"Ingrese cero [0] para volver al Men"<<char(163)<<" Principal";
	gotoxy(66,25);
	cout<<"Ingrese el numero a escoger : ";
	Pintar();
	gotoxy(113,25);
	a=LeerEntero(1,'1','4');//aqui se puede cambiar si se añade mas analisis, luego pongo una variable en ves del 4
	gotoxy(80,9);
	cout<<"Analisis\t\t\t\t      Precios "<<endl;
	gotoxy(56,10);
	for(i=0;i<=93;i++)
	{
		cout<<(char)205;
	}
	mostrarPrecios();
	
	gotoxy(95,6);
	cout<<"ESCOGER ANALISIS"<<endl;
	cuadro(55,8,150,22);
	cout<<endl;
	gotoxy(66,31);
	cout<<"Ingrese el n"<<char(163)<<"mero del  Analisis : "<<endl;
	cout<<endl;
	for(i=0;i<a;i++)//aqui no c que hacen
	{
		gotoxy(69,33+i);
		cout<<(char)(97+i)<<") ";
			gotoxy(72,33+i);
			for(j=0;j<25;j++)
				cout<<(char)32;
			gotoxy(72,33+i);
			w=LeerEntero(1,'0','4');
			v[i]=w;
		if(v[i]==0)
			MenuUsuario();
	}
	
	for(i=0;i<a;i++)
	{
		for(i=j;j<a;j++)
		{
			if(v[i]>v[j])
			{
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;
			}
		}
	}
	i=0;
	archi.read((char*)&c,sizeof(c));
	while(archi)
	{
		r=(v[i]-1)*sizeof(c);
		archi.seekg(r);
		suma=suma+c;
		i++;
		archi.read((char*)&c,sizeof(c));
	}
	suma=suma-70;
	system("cls");
	cuadro(83,8,131,21);
	gotoxy(90,10);
	cout<<"¿Estas seguro que deseas continuar?"<<endl;
	gotoxy(90,13);
	cout<<"[1] SI"<<endl;
	gotoxy(90,15);
	cout<<"[2] No"<<endl;
	gotoxy(93,19);
	cout<<"Ingrese Número:  ";
	a=LeerEntero(1,'1','2');
	if(a==1)
	{
		cuadro(60,8,125,26);
		gotoxy(90,10);
		cout<<"Datos";
		gotoxy(65,15);
		cout<<"Ingrese el nombre del cliente : ";
		LeerLetrasYNumeros(x.nombre);//luego c limita a 40
		if(strcmp(x.nombre,"0")==0)
		{
			system("cls");
			seleccionarAnalizis();
		}
		gotoxy(75,47);
		cout<<"Ingrece cero para volver a Seleccionar el tipo de Análisis";
		gotoxy(65,18);
		cout<<"Ingrese el DNI del cliente : ";
		do{
			gotoxy(95,18);
			for(i=0;i<25;i++)
				cout<<(char)32;
			gotoxy(95,18);
			x.DNI=LeerEntero(8,'0','9');//8 digitos del cero al nueve
		} while((x.DNI!=0&&(x.DNI<=9999999)||x.DNI>100000000));//74705403
		if(x.DNI==0)
		{
			system("cls");
			seleccionarAnalizis();
		}
		system("cls");
		
		cuadro(55,8,125,30);
		gotoxy(70,10);
		cout<<"REPORTE - ANALISIS DE LABORATORIO CLINICO"<<endl;
		gotoxy(70,15);
		cout<<"Cliente : "<<x.nombre<<endl;
		gotoxy(70,17);
		cout<<"Con DNI : "<<x.DNI<<endl;
		gotoxy(70,19);
		cout<<"Monto a pagar : "<<suma<<endl;
		gotoxy(100,47);
	}
	system("pause>log");
	system("cls");
	{
		cuadro(75,8,134,22);
		gotoxy(90,10);
		cout<<"¿Que operacion desea realizar?"<<endl; 
		gotoxy(80,14);
		cout<<"[1] Volver a elegir analisis"<<endl;
		gotoxy(80,16);
		cout<<"[2] Ir al Menu Principal"<<endl;
		gotoxy(95,20);
		cout<<"Ingrese Numero : ";
		a=LeerEntero(1,'1','2');
		system("cls");
		if(a==1)
			seleccionarAnalizis();
		else
			MenuPrincipal();
	}
}
void MenuUsuario()
{
	int n,i;
	system("cls");
	cuadro(50,8,150,24);
	gotoxy(100,10);
	cout<<"M E N U"<<endl;
	gotoxy(60,13);
	cout<<"[1] Mostrar todos los analisis y precios"<<endl;
	gotoxy(60,15);
	cout<<"[2] Solicitar un analisis"<<endl;
	gotoxy(60,17);
	cout<<"[3] Volver al menu principal"<<endl;
	gotoxy(60,21);
	cout<<"Ingrese el n"<<char(163)<<"mero de opción:  ";
	n=LeerEntero(1,'1','3');
	system("cls");
	switch(n)
	{
	case 1:
		gotoxy(80,9);
		cout<<"Analisis\t\t\t\t      Precios "<<endl;
		gotoxy(56,10);
		for(i=0;i<=93;i++)
			cout<<(char)205;
		gotoxy(99,6);
		cout<<"PRECIOS"<<endl;
		cuadro(55,8,150,22);
		mostrarPrecios();
		cout<<endl;
		gotoxy(80,48);
		system("pause>log");
		system("cls");
		MenuUsuario();
		break;
	case 2:
		seleccionarAnalizis();
		break;
	case 3:
		MenuPrincipal();
		break;
	}
}
void mostrarPrecios()
{
	int c,i=1; char x[40];
	
	ifstream lectu("nombres");
	ifstream lectura("precios");
	
	if(!lectu||!lectura)
		cout<<"no se encontro el archivo";
	lectu.read((char*)&x,sizeof(x));
	lectura.read((char*)&c,sizeof(c));
	while(lectu)
	{
		gotoxy(75,11+(i+i));
		cout<<i<<". "<<x<<"\t\t\t\t\t"<<c<<endl;
		i++;
		lectu.read((char*)&x,sizeof(x));
		lectura.read((char*)&c,sizeof(c));
	}
	lectu.close();
	lectura.close();
	gotoxy(60,9+(i+i+2));
}
void MenuPrincipal()
{
	int n;
	system("cls");
	cuadro(30,8,150,25);
	gotoxy(90,10);
	cout<<"LABORATORIO CLINICO"<<endl;
	gotoxy(60,13);
	cout<<"[1]  ADMINISTRADOR"<<endl;
	gotoxy(60,15);
	cout<<"[2]  USUARIO"<<endl;
	gotoxy(60,17);
	cout<<"[0]  SALIR"<<endl;
	gotoxy(87,19);
	cout<<"Ingrese una opcion:"<<endl;
	gotoxy(60,21);
	cout<<"Opcion:  ";
	n=LeerEntero(1,'0','2');
	switch(n)
	{
	case 1:
		MenuAdminContra();
		break;
	case 2:
		MenuUsuario();
		break;
	case 0:
		system("cls");
		gotoxy(100,45);
		exit(0);
		break;
	}
}
void CambiarContrasena()
{
	int n;
	char x[10];
	ofstream archi("contrasena.txt");
	gotoxy(90,10);
	cout<<"CAMBIAR CONTRASEÑA"<<endl;
	gotoxy(60,13);
	cout<<"Ingrese Nueva Contrase"<<char(164)<<"a:  ";
	LeerLetrasYNumeros(x);
	system("cls");
	gotoxy(90,10);
	cout<<"¿Seguro que quiere cambiar la contraseña?"<<endl;
	gotoxy(60,13);
	cout<<"[1] SI"<<endl;
	gotoxy(60,15);
	cout<<"[2] NO"<<endl;
	gotoxy(60,17);
	cout<<" Ingrese Número:  ";
	n=LeerEntero(1,'0','2');
	if(n==1)
	{
		archi.write((char *)&x, sizeof(x));
		archi.close();
		system("cls");
		gotoxy(90,10);
		cout<<"CONTRASEÑA CAMBIADA EXITOSAMENTE";
		system("cls");
		MenuAdmin();
	}
	else
	{
		MenuAdmin();
	}
}


void CotizarPresios()
{
	int c,a,n; 
	char x[40],cad[40];
	bool enc=false;
	ifstream lectu("nombres");
	fstream lectura("precios",ios::in | ios::out);
	if(!lectu || !lectura)
		cout<<"no se encontro el archivo";
	gotoxy(80,9);
	cout<<"Analisis\t\t\t\t      Precios "<<endl;
	otracajita();
	mostrarPrecios();
	gotoxy(95,6);
	cout<<"COTIZAR PRECIOS"<<endl;
	cuadro(30,8,150,22);
	cout<<endl;
	gotoxy(83,25);
	cout<<"Ingrese el nombre del analisis a cambiar:";
	cuadro(93,27,111,29);
	gotoxy(81,46);
	cout<<"Ingrese cero [0] para volver al Menú Principal";//dice 5 :v
	gotoxy(96,28);
	LeerLetrasYNumeros(cad);
	n=atoi(cad);
	if(n==0)
		MenuAdmin();
	else
	{
		system("cls");
		lectu.read((char*)&x,sizeof(x));
		lectura.read((char*)&c,sizeof(c));
		while(lectu && !enc)
		{
			if(strcmp(cad,x)==0)
			{
				enc=true;
				cout<<"ingrese nuevo precio : ";
				c=LeerEntero(6,'0','9');
				system("cls");
				gotoxy(90,10);
				cout<<"¿Está seguro que quiere cambiar el precio?"<<endl;
				gotoxy(60,13);
				cout<<"[1] SI"<<endl;
				gotoxy(60,15);
				cout<<"[2] No"<<endl;
				gotoxy(60,17);
				cout<<" Ingrese Número:  ";
				a=LeerEntero(1,'1','2');
				if(a==1)
				{
					int r,actual,region;
					region=sizeof(c);
					actual=lectura.tellg();
					r=actual-region;
					lectura.seekg(r);
					lectura.write((char*)&c,sizeof(c));
					lectura.close();
					system("cls");
					gotoxy(90,10);
					cout<<"PRECIO CAMBIADO EXITOSAMENTE";
					system("cls");
					MenuPrincipal();
				}
				else
					MenuAdmin();
			}
			else
			{
				lectu.read((char*)&x,sizeof(x));
				lectura.read((char*)&c,sizeof(c));
			}
		}
		if(!enc)
		{
			cout<<endl;
			cout<<"No se ha encontrado el analisis"<<endl;
			system("pause");
			MenuAdmin();
		}
	}
	
}
void MenuAdmin()
{
	int n;
	system("cls");
	cuadro(30,8,150,28);
	gotoxy(100,10);
	cout<<"M E N U"<<endl;
	gotoxy(60,13);
	cout<<"[1] Cotizar Precios"<<endl;
	gotoxy(60,15);
	cout<<"[1.5] Agregar producto(no c puede por q es decimal xd)"<<endl;
	gotoxy(60,17);
	cout<<"[2] Cambiar contrase"<<char(164)<<"a"<<endl;
	gotoxy(60,19);
	cout<<"[2.5] Lista de productos comprados"<<endl;
	gotoxy(60,21);
	cout<<"[3] Volver al menu principal"<<endl;
	gotoxy(60,25);
	cout<<"Ingrese el n"<<char(163)<<"mero de opci"<<char(162)<<"n:  ";
	n=LeerEntero(1,'0','3');
	system("cls");
	switch(n)
	{
	case 1:
		CotizarPresios();
		break;
	case 2:
		CambiarContrasena();
		break;
	case 3:
		MenuPrincipal();
		break;
	}
}
void MenuAdminContra()
{
	system("color 0F");
	char contrasena[400],x[10];
	system("cls");
	cuadro(30,8,150,25);
	gotoxy(90,10);
	cout<<"LABORATORIO CLINICO"<<endl;
	gotoxy(77,28);
	cout<<"Ingrese cero [0] para volver al Menú Principal";
	gotoxy(60,15);
	cout<<"NOMBRE DE USUARIO:  ADMIN"<<endl;
	gotoxy(60,19);
	cout<<"CONTRASE"<<char(165)<<"A:  ";
	validarescritcontra(contrasena);
	if(strcmp(contrasena,"0")==0)
		MenuPrincipal();
	ifstream lectu("contrasena.txt");
	lectu.read((char *)&x,sizeof(x));
	if(!lectu)
	{
		system("cls");
		gotoxy(90,10);
		cout<<x;
		cout<<"Archivo no encontrado"<<endl;
	}
	else
	{
		if(strcmp(contrasena,x)==0)
		{
			lectu.close();
			MenuAdmin();
		}
		else
		{
			lectu.close();
			system("cls");
			gotoxy(78,19);
			system("color 0C");
			cout<<"****  Contraseña Incorrecta. Itente otra vez  ****"<<endl;
			gotoxy(10,45);
			system("pause");
			MenuAdminContra();
		}
	}
}
