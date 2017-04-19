/*
Sistemas Operativos I
Pedro Julio Rodriguez
Oscar Gomez
Gladys Rodriguez
*/

/*
Libreria estandar de c que contiene datos de entrada y salida.
*/
#include <iostream.h>

/*
Esta Libreria contiene dos funciones a las que se le puede accesar como clrscr y getch.
tambien clrscr, kbhit tambien gotoxy.
*/
#include <conio.h>

/*
Libreria que contiene las instrucciones basicas del lenguaje de programacion
como:
constantes,fucniones,tipo,variables
y tambien I/O de conexion con librerias .h de c++
*/
#include <stdio.h>

/*
Esta libreria contiene dos funciones que llevan acabo el control de interrupciones
como getvect y setvect. y textcolor, FP_OFF incluso se utilizar para comverir
void a int.
*/
#include <dos.h>


/*
Se utilizar para exit(0)y salir del programa.
*/
#include <stdlib.h>

/*
se utilizara para funciones de string

*/
#include <string.h>
#include <graphics.h>

/*Estructura del PCB*/
struct MyPCB
{
	int id; //identificacion del proceso
	int eestatus; // estados del proceso
	int Cquantum; //timempo disponible de servicio
	int spp; //a punta a la pila y control de registro.
	int offSet;
};

//vector de 6 procesos.
MyPCB proceso[6];

//Valor del cuantum
const Quantum = 10;

//asignacion de quantums para cada proceso

int quantum1 =0;
int quantum2 =0;
int quantum3 =0;
int quantum4 =0;
int quantum5 =0;
int quantum6 =0;
int enterflag=0;
int cadenal=0;
char cadena[100]="Comando:";
char ch[100] ="";
char comando[10]= "";
int valor =0;

int P1[10][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
int P2[10][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
int P3[10][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
int P4[10][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
int P5[10][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
int P6[10][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};










int procActualIndex; //desplazamiento actual del indice
int procIndexAux; //para comparar con el dezplazmiento acutal
int qActual; //quantum actual
int auxPila; //guarda la pila del programa.
int auxSPP; //guarda el sp de los procesos.
int desplazamientoIndice; //guarda la direccion del procesos.

int statusp1=0;
int statusp2=0;
int statusp3=0;
int statusp4=0;
int statusp5=0;
int statusp6=0;

union REGS in,out;  //uso y detectar mouse



/*Donde pienso guardar la interrupcion*/
void interrupt (*la_interrupcion)(...);


/*

Funcion inicializa mouse

*/
void detect_mouse()

{

	in.x.ax=0;
	int86 (0x33,&in,&out); // invoke interrupt


}


void showmouse_text()

{

	in.x.ax=1;
	int86 (0x33,&in,&out); //invoke interrupt


}


void detect ()
{
	int button;

		int x,y;
		in.x.ax=3;
		int86 (0x33,&in,&out);

		if (out.x.bx==1)
		{
		      x = out.x.cx;
		      y = out.x.dx;

		 }
		if ( y>= 3 && y <= 14 && x>=3 && x<= 37)
		{

		int p = 0;

		while (p!=1)
		{

		for(int f=0;f<100;f++)
		{
		 if ( P1[f][0] ==0)

			{
			 P1[f][1]= x;
			 P1[f][2]= y;
			 P1[f][0]= 1;
			f=100;
			p=1;
			}

		}


		}

		}


		delay(200);


}




/*
-------------------------------------------------------------------------------------------------------------------------------------------------

Acontinuacion se vienen las operaciones de los 6 porcesos  a emular.
Cada uno debera interpretar los click del mouse para pintar los puntos

-------------------------------------------------------------------------------------------------------------------------------------------------
*/
void num1_proceso()
{
	while(1)
	{


   	if (statusp1==1)
  	 {

		clrscr();
		gotoxy(2,2);
		textcolor(6);
		cprintf("|----------------------------------|\n");
		gotoxy(2,3);
		cprintf("|                                  |\n");
		gotoxy(2,4);
		cprintf("|                                  |\n");
		gotoxy(2,5);
		cprintf("|                                  |\n");
		gotoxy(2,6);
		cprintf("|                                  |\n");
		gotoxy(2,7);
		cprintf("|                                  |\n");
		gotoxy(2,8);
		cprintf("|                                  |\n");
		gotoxy(2,9);
		cprintf("|                                  |\n");
		gotoxy(2,10);
		cprintf("|                                  |\n");
		gotoxy(2,11);
		cprintf("|                                  |\n");
		gotoxy(2,12);
		cprintf("|                                  |\n");
		gotoxy(2,13);
		cprintf("|                                  |\n");
		gotoxy(2,14);
		cprintf("|                                  |\n");
		gotoxy(2,15);
		cprintf("|----------------------------------|\n");
		gotoxy (1,45);
		cprintf ("%s \n",cadena);

		for (int fp = 0; fp<10;fp++)
		{
		 if (P1[fp][0]==1)
			{
			 gotoxy(P1[fp][1],P1[fp][2]);
			 textcolor(10);
			 cprintf ("*");
			}

		  if (P1[fp][0]==0)
			{
			fp=10;
			}

		}


	}//end
  }//fin estado activo
}//end

void num2_proceso()
{
	while(1)
	{
	 if (statusp2==1)
	     {

		clrscr();
		gotoxy(38,2);
		textcolor(6);
		cprintf("|----------------------------------|\n");
		gotoxy(38,3);
		cprintf("|                                  |\n");
		gotoxy(38,4);
		cprintf("|                                  |\n");
		gotoxy(38,5);
		cprintf("|                                  |\n");
		gotoxy(38,6);
		cprintf("|                                  |\n");
		gotoxy(38,7);
		cprintf("|                                  |\n");
		gotoxy(38,8);
		cprintf("|                                  |\n");
		gotoxy(38,9);
		cprintf("|                                  |\n");
		gotoxy(38,10);
		cprintf("|                                  |\n");
		gotoxy(38,11);
		cprintf("|                                  |\n");
		gotoxy(38,12);
		cprintf("|                                  |\n");
		gotoxy(38,13);
		cprintf("|                                  |\n");
		gotoxy(38,14);
		cprintf("|                                  |\n");
		gotoxy(38,15);
		cprintf("|----------------------------------|\n");
		gotoxy (1,45);
		cprintf ("%s \n",cadena);
	    }

	}//end
}//end

void num3_proceso()
{
	while(1)
	{
	if (statusp3==1)
	 {

		clrscr();
		gotoxy(2,16);
		textcolor(6);
		cprintf("|----------------------------------|\n");
		gotoxy(2,17);
		cprintf("|                                  |\n");
		gotoxy(2,18);
		cprintf("|                                  |\n");
		gotoxy(2,19);
		cprintf("|                                  |\n");
		gotoxy(2,20);
		cprintf("|                                  |\n");
		gotoxy(2,21);
		cprintf("|                                  |\n");
		gotoxy(2,22);
		cprintf("|                                  |\n");
		gotoxy(2,23);
		cprintf("|                                  |\n");
		gotoxy(2,24);
		cprintf("|                                  |\n");
		gotoxy(2,25);
		cprintf("|                                  |\n");
		gotoxy(2,26);
		cprintf("|                                  |\n");
		gotoxy(2,27);
		cprintf("|                                  |\n");
		gotoxy(2,28);
		cprintf("|                                  |\n");
		gotoxy(2,29);
		cprintf("|----------------------------------|\n");
		gotoxy (1,45);
		cprintf ("%s \n",cadena);

	}
	}//end
}//end

void num4_proceso()
{
	while(1)
	{
	if (statusp4==1)
	 {

		clrscr();
		gotoxy(38,16);
		textcolor(6);
		cprintf("|----------------------------------|\n");
		gotoxy(38,17);
		cprintf("|                                  |\n");
		gotoxy(38,18);
		cprintf("|                                  |\n");
		gotoxy(38,19);
		cprintf("|                                  |\n");
		gotoxy(38,20);
		cprintf("|                                  |\n");
		gotoxy(38,21);
		cprintf("|                                  |\n");
		gotoxy(38,22);
		cprintf("|                                  |\n");
		gotoxy(38,23);
		cprintf("|                                  |\n");
		gotoxy(38,24);
		cprintf("|                                  |\n");
		gotoxy(38,25);
		cprintf("|                                  |\n");
		gotoxy(38,26);
		cprintf("|                                  |\n");
		gotoxy(38,27);
		cprintf("|                                  |\n");
		gotoxy(38,28);
		cprintf("|                                  |\n");
		gotoxy(38,29);
		cprintf("|----------------------------------|\n");
		gotoxy (1,45);
		cprintf ("%s \n",cadena);

		}
	}//end
}//end


void num5_proceso()
{
	while(1)
	{
	if (statusp5==1)
	 {

		clrscr();
		gotoxy(2,30);
		textcolor(6);
		cprintf("|----------------------------------|\n");
		gotoxy(2,31);
		cprintf("|                                  |\n");
		gotoxy(2,32);
		cprintf("|                                  |\n");
		gotoxy(2,33);
		cprintf("|                                  |\n");
		gotoxy(2,34);
		cprintf("|                                  |\n");
		gotoxy(2,35);
		cprintf("|                                  |\n");
		gotoxy(2,36);
		cprintf("|                                  |\n");
		gotoxy(2,37);
		cprintf("|                                  |\n");
		gotoxy(2,38);
		cprintf("|                                  |\n");
		gotoxy(2,39);
		cprintf("|                                  |\n");
		gotoxy(2,40);
		cprintf("|                                  |\n");
		gotoxy(2,41);
		cprintf("|                                  |\n");
		gotoxy(2,42);
		cprintf("|                                  |\n");
		gotoxy(2,43);
		cprintf("|----------------------------------|\n");
		gotoxy (1,45);
		cprintf ("%s \n",cadena);

	}
	}//end
}//end

void num6_proceso()
{
	while(1)
	{
			if (statusp6==1)
			 {

		clrscr();
		gotoxy(38,30);
		textcolor(6);
		cprintf("|----------------------------------|\n");
		gotoxy(38,31);
		cprintf("|                                  |\n");
		gotoxy(38,32);
		cprintf("|                                  |\n");
		gotoxy(38,33);
		cprintf("|                                  |\n");
		gotoxy(38,34);
		cprintf("|                                  |\n");
		gotoxy(38,35);
		cprintf("|                                  |\n");
		gotoxy(38,36);
		cprintf("|                                  |\n");
		gotoxy(38,37);
		cprintf("|                                  |\n");
		gotoxy(38,38);
		cprintf("|                                  |\n");
		gotoxy(38,39);
		cprintf("|                                  |\n");
		gotoxy(38,40);
		cprintf("|                                  |\n");
		gotoxy(38,41);
		cprintf("|                                  |\n");
		gotoxy(38,42);
		cprintf("|                                  |\n");
		gotoxy(38,43);
		cprintf("|----------------------------------|\n");
		}
	}//end
}//end


/*
----------------------------------------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------------------------------------
*/

//esto sirve para volvar a colocar la interrupcion original
void v_Normal()
{
  //la metemos adentro
  setvect(8, la_interrupcion);
  //---------------------------

  //limpiamos nuestra pantalla
  clrscr();
  //-----------------------------D
  //ledamos exit
  exit(0);
  //-------------------------------D
}//end
//--------------------------------------------------------

/*
Este es el metodo de nuestra interrupcion
*/
void interrupt funcion_interrupcion(...)
{

//desabilitamos all interrupcions
  disable();
  //aplicamos nuestra interrupcion
  la_interrupcion();

/////rompemos si se detecta mouse

/*int button;

		int x,y;
		in.x.ax=3;
		int86 (0x33,&in,&out);

		if (out.x.bx==1)
		{
		      x = out.x.cx;
		      y = out.x.dx;


		if ( y>= 3 && y <= 14 && x>=3 && x<= 37)
		{

		int p = 0;

		while (p!=1)
		{

		for(int f=0;f<100;f++)
		{
		 if ( P1[f][0] ==0)

			{
			 P1[f][1]= x;
			 P1[f][2]= y;
			 P1[f][0]= 1;
			f=100;
			p=1;
			}

		}


		}

		}


		delay(200);

		}

  */

////// termina rompimiento por mouse


 // Al dar el teclaso rompemos y paramos la interrupcion
  if (kbhit())

{
   enterflag=0;
      ch[0]= getch();

    if ( ch[0]== 0x0D)
   {

	 enterflag=1;
      if ( 0==strcmp(cadena,"Comando:exit"))
	{

	  v_Normal();
	}

	if (0==strcmp(cadena,"Comando:add<#1>"))
	{

	proceso[0].Cquantum=10;

	quantum1=10;
	 statusp1=1;

	}
	if (0==strcmp(cadena,"Comando:add<#2>"))
	{
	proceso[1].Cquantum=10;

	 quantum2=10;
	 statusp2=1;

	}
	if (0==strcmp(cadena,"Comando:add<#3>"))
	{
	proceso[2].Cquantum=10;

	 quantum3=10;
	 statusp3=1;
	}
	if (0==strcmp(cadena,"Comando:add<#4>"))
	{

	proceso[3].Cquantum=10;

	 quantum4=10;
	 statusp4=1;

	}
	if (0==strcmp(cadena,"Comando:add<#5>"))
	{
	proceso[4].Cquantum=10;

	 quantum5=10;
	 statusp5=1;

	}
	if (0==strcmp(cadena,"Comando:add<#6>"))
	{

	proceso[5].Cquantum=10;

	 quantum6=10;
	 statusp6=1;
	}
	if (0==strcmp(cadena,"Comando:pause<#1>"))
	{
	proceso[0].Cquantum=0;

	 quantum1=0;
	 statusp1=2;
	}
	if (0==strcmp(cadena,"Comando:pause<#2>"))
	{
	proceso[1].Cquantum=0;

	 quantum2=0;
	 statusp2=2;
	}
	if (0==strcmp(cadena,"Comando:pause<#3>"))
	{
	proceso[2].Cquantum=0;

	 quantum3=0;
	 statusp3=2;
	}


	if (0==strcmp(cadena,"Comando:pause<#4>"))
	{
	proceso[3].Cquantum=0;

	 quantum4=0;
	 statusp4=2;
	}
	if (0==strcmp(cadena,"Comando:pause<#5>"))
	{
	proceso[4].Cquantum=0;

	 quantum5=0;
	 statusp5=2;
	}
	if (0==strcmp(cadena,"Comando:pause<#6>"))
	{
	proceso[5].Cquantum=0;

	 quantum6=0;
	 statusp6=2;
	}
	if (0==strcmp(cadena,"Comando:remove<#1>"))
	{
	proceso[0].Cquantum=0;

	quantum1=0;
	statusp1=0;
	}

	if (0==strcmp(cadena,"Comando:remove<#2>"))
	{
	proceso[1].Cquantum=0;

	quantum2=0;
	statusp2=0;
	}

	if (0==strcmp(cadena,"Comando:remove<#3>"))
	{
	proceso[2].Cquantum=0;

	quantum3=0;
	statusp3=0;
	}

	if (0==strcmp(cadena,"Comando:remove<#4>"))
	{
	proceso[3].Cquantum=0;

	quantum4=0;
	statusp4=0;
	}

	if (0==strcmp(cadena,"Comando:remove<#5>"))
	{
	proceso[4].Cquantum=0;

	quantum5=0;
	statusp5=0;
	}

	if (0==strcmp(cadena,"Comando:remove<#6>"))
	{
	proceso[5].Cquantum=0;

	quantum6=0;
	statusp6=0;
	}
	if (0==strcmp(cadena,"Comando:clear<#1>"))
	{

	}
	if (0==strcmp(cadena,"Comando:clear<#2>"))
	{

	}
	if (0==strcmp(cadena,"Comando:clear<#3>"))
	{

	}
	if (0==strcmp(cadena,"Comando:clear<#4>"))
	{

	}
	if (0==strcmp(cadena,"Comando:clear<#5>"))
	{

	}
	if (0==strcmp(cadena,"Comando:clear<#6>"))
	{

	}
	if (cadena== "Comando:quantum<#1>")
	{

	}
	if (cadena== "Comando:quantum<#2>")
	{

	}

	if (cadena== "Comando:quantum<#3>")
	{

	}

	if (cadena== "Comando:quantum<#4>")
	{

	}

	if (cadena== "Comando:quantum<#5>")
	{

	}

	if (cadena== "Comando:quantum<#6>")
	{

	}

	if (0==strcmp(cadena,"Comando:stats<#1>"))
	{

	}

	if (0==strcmp(cadena,"Comando:stats<#2>"))
	{

	}

	if (0==strcmp(cadena,"Comando:stats<#3>"))
	{

	}

	if (0==strcmp(cadena,"Comando:stats<#4>"))
	{

	}

	if (0==strcmp(cadena,"Comando:stats<#5>"))
	{

	}

	if (0==strcmp(cadena,"Comando:stats<#6>"))
	{

	}


	if (0==strcmp(cadena,"Comando:stats<#0>"))
	{

	}


	if (cadena== "Comando:stats  <-1>")
	{

	}




       strcpy(cadena, "Comando:");

   }


 /* if ( ch[0]== 0x20)
   {

		int x,y;
		int x1=0;
		int y1=0;
		in.x.ax=3;
		int86 (0x33,&in,&out);

		      x = out.x.cx;
		      y = out.x.dx;
		      x1=x/10;
		      y1=y/10;

   gotoxy (10,10);
  cprintf ("Las coordenas detectadas son en x:%d en y:%d",x,y);
   delay(2000);

   strcpy(cadena,"Comando:");
   enterflag=1;


   }*/




  if (enterflag==0)
  {

  strcat (cadena,ch);

  }
   gotoxy (1,45);
   cprintf ("%s \n",cadena);

   delay(200);




}



	//vamos restanto al que esta en proceso
	//y cuando llega a cero otro proceso entra en cadena






  if (qActual > 0)
     qActual--;
  else
  {

  //guardamos el sp en la pila ps el proceso
    asm mov  auxPila,sp
    proceso[procActualIndex].spp = auxPila;
//----------------------------------------------
	//cuando esta en ejecucion pasa a listo
    if (proceso[procActualIndex].eestatus == 1)
      proceso[procActualIndex].eestatus = 2;
//----------------------------------------------
//se verica cuando pasa el control a otro proceso
    procIndexAux = procActualIndex;
    procActualIndex = ((procActualIndex+1)%5);
    if (proceso[procActualIndex].eestatus != 2)
      procActualIndex = ((procActualIndex+1)%5);
    qActual =proceso[procActualIndex].Cquantum;
//----------------------------------------------

//Se ejecuta un proceso
    if (procIndexAux != procActualIndex)
    {
		proceso[procActualIndex].eestatus = 1;
//--------------------------------------------------
		auxPila = proceso[procActualIndex].spp;
//--------------------------------------------------
		asm mov sp,auxPila
    }//end
  }//end
//-----------------------------------------------

  //se habilitan todas las interrupcion
  enable();//--------------------------
  //-----------------------------------
}

//metodo inicial de los procesos
void init_proc()
{
  //Asignando Pensum
  //---------------------------------------------
  proceso[0].Cquantum = quantum1;//-----------
  proceso[1].Cquantum = quantum2;
  proceso[2].Cquantum = quantum3;//-----------
  proceso[3].Cquantum = quantum4;
  proceso[4].Cquantum = quantum5;
  proceso[5].Cquantum = quantum6;

  //---------------------------------------------
  //FP_OFF
  //---------------------------------------------
  proceso[0].offSet = FP_OFF(num1_proceso);//----
  proceso[1].offSet = FP_OFF(num2_proceso);
  proceso[2].offSet = FP_OFF(num3_proceso);//----
  proceso[3].offSet = FP_OFF(num4_proceso);
  proceso[4].offSet = FP_OFF(num5_proceso);
  proceso[5].offSet = FP_OFF(num6_proceso);

  //----------------------------------------------
  //Asignando los ID's
  //----------------------------------------------

  proceso[5].id = 6;//----------------------------
  proceso[5].eestatus = 2;
  proceso[4].id = 5;//----------------------------
  proceso[4].eestatus = 2;
  proceso[3].id = 4;//----------------------------
  proceso[3].eestatus = 2;
  proceso[2].id = 3;
  proceso[2].eestatus = 2;
  proceso[1].id = 1; //---------------------------
  proceso[1].eestatus = 2;
  proceso[0].id = 0;//----------------------------
  proceso[0].eestatus = 1;
  proceso[0].spp = 0;
  //----------------------------------------------

  //Segmento de pila proceso 1
  asm mov auxPila,sp
  auxSPP=auxPila;
  auxSPP= auxSPP - 1048;
  desplazamientoIndice = proceso[1].offSet;
  asm {
   mov sp,auxSPP//sp
   pushf
   push cs
   push desplazamientoIndice//desplaza
   push ax
   push bx
   push cx
   push dx
   push es
   push ds
   push si
   push di
   push bp
   mov auxSPP, sp
   mov sp, auxPila //restaura el SP//
  }//end
  proceso[1].spp = auxSPP;
  //segmento e pila 1
  auxSPP = auxSPP - 1048;
  desplazamientoIndice = proceso[2].offSet;


//Segmento de pila proceso 2
  asm {
   mov sp,auxSPP//sp
   pushf
   push cs
   push desplazamientoIndice//desplaza
   push ax
   push bx
   push cx
   push dx
   push es
   push ds
   push si
   push di
   push bp
   mov auxSPP, sp //restaura el SP//
   mov sp, auxPila
  }//end
  proceso[2].spp = auxSPP;




  //segmento e pila 2
  auxSPP = auxSPP - 1048;
  desplazamientoIndice = proceso[3].offSet;


  //Segmento de pila proceso 3
  asm {
   mov sp,auxSPP//sp
   pushf
   push cs
   push desplazamientoIndice//desplaza
   push ax
   push bx
   push cx
   push dx
   push es
   push ds
   push si
   push di
   push bp
   mov auxSPP, sp //restaura el SP//
   mov sp, auxPila
  }//end



  //segmento e pila 3
  proceso[3].spp = auxSPP;
  auxSPP = auxSPP - 1048;
  desplazamientoIndice = proceso[4].offSet;

//Segmento de pila proceso 4
  asm {
   mov sp,auxSPP//sp
   pushf
   push cs
   push desplazamientoIndice//desplaza
   push ax
   push bx
   push cx
   push dx
   push es
   push ds
   push si
   push di
   push bp
   mov auxSPP, sp //restaura el SP//
   mov sp, auxPila
  }//end

  proceso[4].spp = auxSPP;
  auxSPP = auxSPP - 1048;
  desplazamientoIndice = proceso[5].offSet;



//Segmento de pila proceso 5
  asm {
   mov sp,auxSPP//sp
   pushf
   push cs
   push desplazamientoIndice//desplaza
   push ax
   push bx
   push cx
   push dx
   push es
   push ds
   push si
   push di
   push bp
   mov auxSPP, sp //restaura el SP//
   mov sp, auxPila
  }//end
  proceso[5].spp = auxSPP;

  auxSPP = auxSPP - 1048;




  //comienco en el proceso 0.
  procActualIndex = 0;
  //el actual  tomara el valor del quantum del proceso 0.
  qActual =proceso[procActualIndex].Cquantum;
}//end

//metodo principal de c++
int main()
{




//Limpiar toda la pantalla
  clrscr();

	detect_mouse();
	showmouse_text();



  init_proc();//inicializar los procesos.
  la_interrupcion = getvect(8); //Guardamos la interrupcion
  setvect(8, funcion_interrupcion);//insertamos nuestra interrupcion
  num1_proceso();//ejecutamos el proceso uno



   while(1)//ciclo repetitivo
  {

detect();

  }//end
}//end




