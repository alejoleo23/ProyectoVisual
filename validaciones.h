#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#endif
int LeerEntero()
{
	char car,dato[100];
	int n=0;
	do{
		car=getch();
		if(car>='0' && car<='9')
		{
			cout<<car;
			dato[n]=car;
			n++;
		}
		else
		   if(car==8 && n>0)
		{
			cout<<car;
			cout<<" ";
			cout<<car;
			n--;
		}
		   else
			  if(car==13)
			  cout<<endl;
	} while(car!=13);
	dato[n]=0;
	return atoi(dato);
}
int LeerEntero(int x)
{
	int t=0;
	char car,dato[100];
	int n=0;
	do{
		car=getch();
		if(car>='0' && car<='9' &&t<x)
		{
			cout<<car;
			dato[n]=car;
			n++;
			t++;
		}
		else
		   if(car==8 && n>0 && t<=x)
		{
			cout<<car;
			cout<<" ";
			cout<<car;
			n--;
			t--;
		}
		   else
			  if(car==13)
			  cout<<endl;
	} while(car!=13);
	dato[n]=0;
	return atoi(dato);
}
int LeerEntero(int x,char a,char b)
{
	int t=0;
	char car,dato[100];
	int n=0;
	do{
		car=getch();
		if(car>=a && car<=b &&t<x)
		{
			cout<<car;
			dato[n]=car;
			n++;
			t++;
		}
		else
		   if(car==8 && n>0 && t<=x)
		{
			cout<<car;
			cout<<" ";
			cout<<car;
			n--;
			t--;
		}
		   else
			  if(car==13)
			  cout<<endl;
	} while(car!=13);
	dato[n]=0;
	return atoi(dato);
}
float LeerReal()
{
	char car,dato[100];
	int n=0,punto=0;
	do{
		car=getch();
		if(car>='0' && car <='9')
		{
			cout<<car;
			dato[n]=car;
			n++;
		}
		else
		   if(car=='.' && punto==0)
		{
			cout<<car;
			dato[n]=car;
			n++;
			punto++;
		}
		   else
			  if(car==8 && n>0)
		   {
			   cout<<car;
			   cout<<" ";
			   cout<<car;
			   if(dato[n-1]=='.')
			   {
				   punto--;
				   n--;
			   }
		   }
			  else
				 if(car==13)
				 cout<<endl;
	} while(car!=13);
	dato[n]=0;
	return atof(dato);
}
void LeerLetrasYNumeros(char dato[])
{
	char car;
	int n=0;
	do{
		car=getch();
		if((car>='0' && car<='9')||car==' '||(car>='a'&&car<='z')||(car>='A' && car<='Z'))
		{
			cout<<car;
			dato[n]=car;
			n++;
		}
		else
		if(car==8 && n>0)
		{
			cout<<car;
			cout<<" ";
			cout<<car;
			n--;
		}
		else
		if(car==13)
		cout<<endl;
	} while(car!=13);
	dato[n]=0;
}
void validarescritcontra(char dato[])
{
	char car;
	int n=0;
	do{
		car=getch();
		if((car>='0' && car<='9')||car==' '||(car>='a'&&car<='z')||(car>='A' && car<='Z'))
		{
			cout<<"*";
			dato[n]=car;
			n++;
		}
		else
			if(car==8 && n>0)
		{
			cout<<car;
			cout<<" ";
			cout<<car;
			n--;
		}
			else
			if(car==13)
				cout<<endl;
	} while(car!=13);
	dato[n]=0;
}
