#include <stdio.h>                        // SISTEMA DE CONTROL DE PRESTAMOS DE LIBROS
#include <conio.h>
#include <stdlib.h>                       // Copyright @ 2021 Yohan Alek Plazola Arangure
#include <string.h>
#include <ctype.h>
#include <windows.h>

struct Libro
{
	int codigo;
	char nombre[30];
	char autor[13];
	char editorial[13];
	char fechaRegistro[11];
	int cantidad;
}lib;

struct Estudiante
{
	int matricula;
	char nombre[12];
	char apellidoP[12];
	char apellidoM[12];
	char carrera[40];
	int pendiente;
	int codLibro;
	int status;
}est;

struct Empleado
{
	int idEmpleado;
	char nombre[12];
	char apellidoP[12];
	char apellidoM[12];
	int status;
}emp;

struct Prestamo
{
	int idPrestamo;
	int codLibro;
	int matEst;
	int idEmpleado;
	char fechaPrestamo[11];
	char fechaDevolucion[11];
	int seDevolvio;
	int status;
}pre;

FILE * archivo;

//Declaración de funciones
void programa();
void cargar();
void gotoxy(int, int);
int nument(int, int);
int valifec(char *, int);
int valitext(int, char *, int);

//Dibujar los formularios
void frmMenu();
void frmLibros();
void frmEstudiantes();
void frmEmpleados();
void frmPrestamos();
void frmSalir();
void frmBusqueda(int);
void frmEdicion(int);
void frmEliminacion(int);
void mostrarCampos(int);
void mostrarDialogo();

//Limpiar residuos en pantalla
void limpiarArea();

//Controlar Selección de menus
void selectorMenu(int);
void selectorOpciones(int, int);

//LIBROS
int capturaLibro(int *, int *, int *);
int escribirLibro();
int mostrarLibros();
void dibujarLibros(int, int);

//ESTUDIANTES
int capturaEstudiante(int *, int *, int *);
int escribirEstudiante();
int mostrarEstudiantes();
void dibujarEstudiantes(int, int);

//EMPLEADOS
int capturaEmpleado(int *, int *, int *);
int escribirEmpleado();
int mostrarEmpleados();
void dibujarEmpleados(int, int);

//PRESTAMOS
int capturaPrestamo(int *, int *, int *);
int escribirPrestamo();
int mostrarPrestamos();
void dibujarPrestamos(int, int);

//Buscar validar y capturar registros
int buscarRegistro(int, int);
int validarRegistro(int, int);
int capturaRegistro(int *, int *);
int editarRegistro(int *, int *, int *);
int eliminarRegistro(int *, int *);

int main()
{
	programa();
	return 0;
}

//Definición de funciones
void programa()
{
	int op = 1, modo = 0, ent = 1;
	char sel;
	cargar();
	comienzo:
	frmMenu();
	do
	{
		if(ent == 1)
			selectorMenu(op);
		gotoxy(0, 23);
		sel = getch(); //Aquí capturamos el caracter
		regreso:
		switch(toupper(sel)) //Aquí evaluamos el caracter considerandolo como una Mayuscula.
		{
			case 'W':
				if(op >= 2)
					op--;
				break;
			case 'S':
				if(ent == 1)
				{
					if(op <= 4)
					{
						op++;
					}
				}
				else
				{
					if(op <= 5)
					op++;
				}
				break;
			case 13:
				switch(ent)
				{
					case 1:	//MENU			
						switch(op) //Mostramos en pantalla
						{
							case 1:		
								gotoxy(27, 3);
								printf("REGISTRAR");
								gotoxy(27, 5);
								printf("EDITAR");
								gotoxy(27, 7);
								printf("ELIMINAR");
								gotoxy(27, 9);
								printf("MOSTRAR LIBROS");
								gotoxy(27, 11);
								printf("BUSCAR UN LIBRO");
								gotoxy(27, 13);
								printf("REGRESAR AL MENU");
								ent = 2;
								break;
							case 2:
								gotoxy(27, 5);
								printf("REGISTRAR");
								gotoxy(27, 7);
								printf("EDITAR");
								gotoxy(27, 9);
								printf("ELIMINAR");
								gotoxy(27, 11);
								printf("MOSTRAR ESTUDIANTES");
								gotoxy(27, 13);
								printf("BUSCAR UN ESTUDIANTE");
								gotoxy(27, 15);
								printf("REGRESAR AL MENU");		
								op = 1;
								ent = 3;
								break;
							case 3:
								gotoxy(27, 7);
								printf("REGISTRAR");
								gotoxy(27, 9);
								printf("EDITAR");
								gotoxy(27, 11);
								printf("ELIMINAR");
								gotoxy(27, 13);
								printf("MOSTRAR EMPLEADOS");
								gotoxy(27, 15);
								printf("BUSCAR UN EMPLEADO");
								gotoxy(27, 17);
								printf("REGRESAR AL MENU");
								op = 1;
								ent = 4;
								break;
							case 4:
								gotoxy(27, 9);
								printf("REGISTRAR");
								gotoxy(27, 11);
								printf("EDITAR");
								gotoxy(27, 13);
								printf("ELIMINAR");
								gotoxy(27, 15);
								printf("MOSTRAR PRESTAMOS");
								gotoxy(27, 17);
								printf("BUSCAR UN PRESTAMO");
								gotoxy(27, 19);
								printf("REGRESAR AL MENU");
								op = 1;
								ent = 5;
								break;
							case 5:
							{
								int opcion = 1;
								frmSalir();
								gotoxy(27, 7);
								printf("%c------------------------------------------%c", 218, 191);
								gotoxy(27, 8);
								printf("|                                          |");
								gotoxy(27, 9);
								printf("|           %cDeseas Salir del Programa?    |", 168);
								gotoxy(27, 10);
								printf("|                                          |");
								gotoxy(27, 11);
								printf("|                      SI                  |");
								gotoxy(27, 12);
								printf("|                                          |");
								gotoxy(27, 13);
								printf("|                      NO                  |");
								gotoxy(27, 14);
								printf("%c------------------------------------------%c", 192, 217);
								gotoxy(30, 7);
								printf("%c", 24);
								gotoxy(28, 8);
								printf("%c---%c", 218, 191);
								gotoxy(28, 9);
								printf("| W |");
								gotoxy(28, 10);
								printf("%c---%c", 192, 217);
								gotoxy(28, 11);
								printf("%c---%c", 218, 191);
								gotoxy(28, 12);
								printf("| S |");
								gotoxy(28, 13);
								printf("%c---%c", 192, 217);
								gotoxy(30, 14);
								printf("%c", 25);
								gotoxy(47, 11);
								printf("->");
								opcion = 1;
								input:
								switch(toupper(getch()))
								{
									case 'W':
										if(opcion != 1)
											opcion = 1;
										gotoxy(47, 13);
										printf("  ");
										gotoxy(47, 11);
										printf("->");
										goto input;
										break;
									case 'S':
										if(opcion != 0)
											opcion = 0;
										gotoxy(47, 11);
										printf("  ");
										gotoxy(47, 13);
										printf("->");
										goto input;
										break;
									case 13:
										if(opcion == 1)
										{
											op = -1;
										}
										break;
								}
								limpiarArea();
							}
						}
			            break;
					case 2: //LIBROS
						switch(op) //Accedemos al modo (Registro, Edicion, Eliminacion, Muestra)
						{
							case 1:
								modo = 1;
								break;
							case 2:
								modo = 2;
								break;
							case 3:
								modo = 3;
								break;
							case 4:									
								modo = 4;
								break;
							case 5:
								modo = 5;
								break;
							case 6:
								gotoxy(23, 13);
								printf("  ");
								gotoxy(27, 3);
								printf("         ");
								gotoxy(27, 5);
								printf("      ");
								gotoxy(27, 7);
								printf("        ");
								gotoxy(27, 9);
								printf("              ");
								gotoxy(27, 11);
								printf("                ");
								gotoxy(27, 13);
								printf("                ");
								op = 1;
								ent = 1;
								break;
						}
						break;
					case 3: //ESTUDIANTES
						switch(op)
						{
							case 1:						
								modo = 1;
								break;
							case 2:
								modo = 2;
								break;
							case 3:
								modo = 3;
								break;
							case 4:
								modo = 4;
								break;
							case 5:
								modo = 5;
								break;
							case 6:
								gotoxy(23, 15);
								printf("  ");
								gotoxy(27, 5);
								printf("         ");
								gotoxy(27, 7);
								printf("      ");
								gotoxy(27, 9);
								printf("        ");
								gotoxy(27, 11);
								printf("                   ");
								gotoxy(27, 13);
								printf("                    ");
								gotoxy(27, 15);
								printf("                ");
								op = 2;
								ent = 1;
								break;
						}
						break;
					case 4: //EMPLEADOS
						switch(op)
						{
							case 1:		
								modo = 1;
								break;
							case 2:
								modo = 2;
								break;
							case 3:
								modo = 3;
								break;
							case 4:
								modo = 4;
								break;
							case 5:
								modo = 5;
								break;
							case 6:
								gotoxy(23, 17);
								printf("  ");
								gotoxy(27, 7);
								printf("         ");
								gotoxy(27, 9);
								printf("      ");
								gotoxy(27, 11);
								printf("        ");
								gotoxy(27, 13);
								printf("                 ");
								gotoxy(27, 15);
								printf("                  ");
								gotoxy(27, 17);
								printf("                ");
								op = 3;
								ent = 1;
								break;
						}
						break;
					case 5: //PRESTAMOS
						switch(op)
						{
							case 1:						
								modo = 1;
								break;
							case 2:
								modo = 2;
								break;
							case 3:
								modo = 3;
								break;
							case 4:
								modo = 4;
								break;
							case 5:
								modo = 5;
								break;
							case 6:
								gotoxy(23, 19);
								printf("  ");
								gotoxy(27, 9);
								printf("         ");
								gotoxy(27, 11);
								printf("      ");
								gotoxy(27, 13);
								printf("        ");
								gotoxy(27, 15);
								printf("                 ");
								gotoxy(27, 17);
								printf("                  ");
								gotoxy(27, 19);
								printf("                ");
								op = 4;
								ent = 1;
								break;
						}
						break;
				}				
				break;
		}
		switch(modo) //VISUALIZACIÓN DE MENUS
		{
			case 0: //MENU
				switch(ent)
				{
					case 2:
						selectorOpciones(op, 0);
						break;
					case 3:
						selectorOpciones(op, 2);
						break;
					case 4:
						selectorOpciones(op, 4);
						break;
					case 5:
						selectorOpciones(op, 6);
						break;
					case 6:
						break;
				}
				break;	
			case 1: //REGISTRO
				switch(ent)
				{
					case 2:
						if(capturaLibro(&op, &modo, &ent) == -1)
						{
							ent = 1;
							modo = 0;
							op = 1;
							goto regreso;
						}
						break;
					case 3:
						if(capturaEstudiante(&op, &modo, &ent) == -1)
						{
							ent = 1;
							modo = 0;
							op = 2;
							goto regreso;
						}
						break;
					case 4:
						if(capturaEmpleado(&op, &modo, &ent) == -1)
						{
							ent = 1;
							modo = 0;
							op = 3;
							goto regreso;
						}
						break;
					case 5:
						if(capturaPrestamo(&op, &modo, &ent) == -1)
						{
							ent = 1;
							modo = 0;
							op = 4;
							goto regreso;
						}
						break;
					case 6:
						break;
				}
				break;
			case 2: //EDICIÓN
				switch(ent)
				{
					case 2:
						if(editarRegistro(&ent, &op, &modo) == -1)
						{
							ent = 1;
							modo = 0;
							op = 1;
							goto regreso;
						}
						break;
					case 3:
						if(editarRegistro(&ent, &op, &modo) == -1)
						{
							ent = 1;
							modo = 0;
							op = 2;
							goto regreso;
						}
						break;
					case 4:
						if(editarRegistro(&ent, &op, &modo) == -1)
						{
							ent = 1;
							modo = 0;
							op = 3;
							goto regreso;
						}
						break;
					case 5:
						if(editarRegistro(&ent, &op, &modo) == -1)
						{
							ent = 1;
							modo = 0;
							op = 4;
							goto regreso;
						}
						break;
				}
				break;
			case 3: //ELIMINACIÓN
				switch(ent)
				{
					case 2:
						if (eliminarRegistro(&ent, &modo) == -1)
						{
							ent = 1;
							modo = 0;
							op = 1;
							goto regreso;
						}
						break;
					case 3:
						if (eliminarRegistro(&ent, &modo) == -1)
						{
							ent = 1;
							modo = 0;
							op = 2;
							goto regreso;
						}
						break;
					case 4:
						if (eliminarRegistro(&ent, &modo) == -1)
						{
							ent = 1;
							modo = 0;
							op = 3;
							goto regreso;
						}
						break;
					case 5:
						if (eliminarRegistro(&ent, &modo) == -1)
						{
							ent = 1;
							modo = 0;
							op = 4;
							goto regreso;
						}
						break;
				}
				break;
			case 4: //MUESTRA
				switch(ent)
				{
					case 2:
						if(mostrarLibros() == -1)
						{
							gotoxy(25, 23);
							printf("Hubo un problema a la hora de mostrar los libros...");
							getch();						
						}
						limpiarArea();
						gotoxy(25, 23);
						printf("                                                     ");
						ent = 1;
						modo = 0;
						op = 1;
						goto regreso;			
						break;
					case 3:
						if(mostrarEstudiantes() == -1)
						{
							gotoxy(19, 23);
							printf("Parece que no hay estudiantes registrados...");
							getch();			
						}
						limpiarArea();
						gotoxy(19, 23);
						printf("                                                     ");
						ent = 1;                         
						modo = 0;
						op = 2;
						goto regreso;			
						break;
					case 4:
						if(mostrarEmpleados() == -1)
						{
							gotoxy(21, 23);
							printf("Parece que no hay empleados registrados...");
							getch();					
						}
						limpiarArea();
						gotoxy(21, 23);
						printf("                                                 ");
						ent = 1;                         
						modo = 0;
						op = 3;
						goto regreso;	
						break;
					case 5:
						if(mostrarPrestamos() == -1)
						{
							gotoxy(20, 23);
							printf("Parece que no hay prestamos registrados...");
							getch();
							remove("Prestamos.dat");
						}
						limpiarArea();
						gotoxy(20, 23);
						printf("                                                    ");
						ent = 1;                         
						modo = 0;
						op = 4;
						goto regreso;
						break;
					case 6:
						break;
				}
				break;
			case 5: //BUSQUEDA
				switch(ent)
				{
					case 2:
						if(capturaRegistro(&ent, &modo) == -1)
						{
							ent = 1;
							modo = 0;
							op = 1;
							goto regreso;
						}
						break;
					case 3:
						if(capturaRegistro(&ent, &modo) == -1)
						{
							ent = 1;
							modo = 0;
							op = 2;
							goto regreso;
						}
						break;
					case 4:
						if(capturaRegistro(&ent, &modo) == -1)
						{
							ent = 1;
							modo = 0;
							op = 3;
							goto regreso;
						}
						break;
					case 5:
						if(capturaRegistro(&ent, &modo) == -1)
						{
							ent = 1;
							modo = 0;
							op = 4;
							goto regreso;
						}
						break;
				}
				break;
		}
	}while(op > 0 && op <= 6); //Validamos la opción que este en el rango de 1 a 6
	system("cls");
	gotoxy(35, 9);
	printf("%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 187);
	gotoxy(35, 10);
	printf("%c %c--%c %c", 186, 218, 191, 186);
	gotoxy(35, 11);
	printf("%c %c--%c %c", 186, 192, 217, 186);
	gotoxy(35, 12);
	printf("%c ~~~~ %c", 186, 186);
	gotoxy(35, 13);
	printf("%c ~~~~ %c", 186, 186);
	gotoxy(35, 14);
	printf("%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 188);
	gotoxy(25, 17);
	printf("Gracias por usar el programa.\n\n\n\n");
}

void cargar()
{
	int carga = 10;
	gotoxy(10, 13);
	printf("CARGANDO");
	do
	{
		gotoxy(carga, 15);
		printf("%c", 223);
		Sleep(20);
		carga += 2;
	}while(carga <= 68);
}

void gotoxy(int X, int Y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = X;
	dwPos.Y = Y;
	SetConsoleCursorPosition(hcon,dwPos);
}

int nument(int num, int modo)
{
	char tecla, cadena[num + 1];
	int x = 0;
	do
	{
		inicio:
		tecla = getch();
		if ((tecla >= 48 && tecla <= 57) || (tecla == 46))
		{
			printf("%c", tecla);
			cadena[x] = tecla;
			x++;
		}
		if (tecla == 8 && x > 0)
		{
			printf("\b \b");
			cadena[x] = ' ';
			x--;
		}
		if(tecla == 27)
        {
        	return -1;
		}
	}while((tecla != 13 && x < num) || (x < 1 && modo != 2));
	cadena[x] = '\n';
	return atoi(cadena);
}

int valifec(char * pfecha, int modo)
{
	int dia=0, mes=0, anio=0, x=0, c=0, d=0, m=0, a=0, fec=0, bi=0, y = 1;
	char diac[2], mesc[2], anioc[4];
	do
	{
		x=d=m=a=0;
		strcpy(diac,"  ");
		strcpy(mesc,"  ");
		strcpy(anioc,"    ");
		do
		{
			c=getch();
	    	if(c>=48 && c<=57){
				printf("%c",c);
    			if(x<2)
				{
					diac[d]=c;
        			d++;
        		}
				else if (x<5)
				{
					mesc[m]=c;
					m++;
				}
				else
				{
					anioc[a]=c;
					a++;
				}
				*(pfecha+x)=c;
    	    	x++;
	    	}
	    	if(x==2 || x==5)
			{
				printf("/");
    	    	*(pfecha+x)='/';
        		x++;        
        	} 
			if(c==8 && x>0)
			{
				x--;
	    		if(x==2)
				{
					printf("\b\b  \b\b");
	    			*(pfecha+x)=' ';
	    			x--;
	    			*(pfecha+x)=' ';
	    			d--;
	    		}
	    		else if(x<2)
				{
					printf("\b \b");
					*(pfecha+x)=' ';
					d--;
				}
	    		else if(x==5)
				{
					printf("\b\b  \b\b");
	    			*(pfecha+x)=' ';
	    			x--;
					*(pfecha+x)=' ';
					m--;
	    		}
	    		else if(x<5)
				{
					printf("\b \b");
					*(pfecha+x)=' ';
					m--;
				}
	    		else if(x>5)
				{
					printf("\b \b");
	    			*(pfecha+x)=' ';
	    			a--;
	    		}
    		}
			if(c == 27)
	        {
	        	return -1;
			}
			if((x <= 0 && c == 13) && modo == 2)
			{
				*(pfecha+x) = '\n';
				return 1;
			}  
		}while(x<10);
		dia=atoi(diac);
		mes=atoi(mesc);
		anio=atoi(anioc);
		bi=0;
		if(anio%4==0 && (anio%100!=0 || anio%400==0))
			bi++;
		if(dia<=31 && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && anio>=1900 && anio<=2050)
			fec=1;
		else if(dia<=30 && (mes==4 || mes==6 || mes==9 || mes==11) && anio>=1900 && anio<=2050)
			fec=1;
		else if(dia<=28 && mes==2 && anio>=1900 && anio<=2050)
			fec=1;
		else if(dia==29 && mes==2 && anio>=1900 && anio<=2050 && bi==1)
			fec=1;
		else
			for(y=1;y<=10;y++)
				printf("\b \b");
	}while(fec!=1);
	return 0;
}

int valitext(int lon, char * pnom, int modo)
{
	int c=0, x=0;
    do
	{
		c=getch();
        if(c>=65 && c<=90 || c>=97 && c<=122 || c==164 || c==165)
		{
			printf("%c",c);
            *(pnom+x)=c;
            x++;
        }
        if(c == 32 && x > 0)
        {
        	printf("%c",c);
            *(pnom+x)=c;
            x++;
		}
        if(c==8 && x>0)
		{
			x--;
		    printf("\b \b");
	        *(pnom+x)=' ';
        }
        if(c == 27)
        {
        	return -1;
		}
    }while((c != 13 && x < lon) || (x < 1 && modo != 2));
    *(pnom+x)='\n';
    return 0;
}

void frmMenu()
{
	gotoxy(0, 2);
	printf("     %c---------------%c-----------------------------------------------------%c", 218, 194, 191);
	gotoxy(0, 3);
	printf("     |  LIBROS       |                                                     |");
	gotoxy(0, 4);
	printf("     |               |                                                     |");
	gotoxy(0, 5);
	printf("     |  ESTUDIANTES  |                                                     |");
	gotoxy(0, 6);
	printf("     |               |                                                     |");
	gotoxy(0, 7);
	printf("     |  EMPLEADOS    |                                                     |");
	gotoxy(0, 8);
	printf("     |               |                                                     |");
	gotoxy(0, 9);
	printf("     |  PRESTAMOS    |                                                     |");
	gotoxy(0, 10);
	printf("     |               |                                                     |");
	gotoxy(0, 11);
	printf("     |  SALIR   <-   |                                                     |");
	gotoxy(0, 12);
	printf("     |               |                                                     |");
	gotoxy(0, 13);
	printf("     |               |                                                     |");
	gotoxy(0, 14);
	printf("     |               |                                                     |");
	gotoxy(0, 15);
	printf("     |               |                                                     |");
	gotoxy(0, 16);
	printf("     |               |                                                     |");
	gotoxy(0, 17);
	printf("     |               |                                                     |");
	gotoxy(0, 18);
	printf("     |               |                                                     |");
	gotoxy(0, 19);
	printf("     |               |                                                     |");
	gotoxy(0, 20);
	printf("     |               |                                                     |");
	gotoxy(0, 21);
	printf("     |               |                                                     |");
	gotoxy(0, 22);
	printf("     %c---------------%c-----------------------------------------------------%c", 192, 193, 217);
	gotoxy(2, 8);
	printf("%c", 24);
	gotoxy(0, 9);
	printf("%c---%c", 218, 191);
	gotoxy(0, 10);
	printf("| W |");
	gotoxy(0, 11);
	printf("%c---%c", 192, 217);
	gotoxy(0, 12);
	printf("%c---%c", 218, 191);
	gotoxy(0, 13);
	printf("| S |");
	gotoxy(0, 14);
	printf("%c---%c", 192, 217);
	gotoxy(2, 15);
	printf("%c", 25);
}

void frmLibros()
{
	limpiarArea();
	gotoxy(42, 3);
	printf("REGISTRO DE LIBROS");
	gotoxy(21, 4);
	printf("%c-----------------------------------------------------%c", 195, 180);
	gotoxy(27, 2);
	printf("%c", 194);
	gotoxy(22, 3);
	printf("<-ESC");
	gotoxy(27, 3);
	printf("|");
	gotoxy(27, 4);
	printf("%c", 193);
	gotoxy(27, 6);
	printf("C%cdigo:",162);
	gotoxy(26, 7);
	printf("%c-------------%c", 218, 191);
	gotoxy(26, 8);
	printf("|             |");
	gotoxy(26, 9);
	printf("%c-------------%c", 192, 217);
	gotoxy(43, 6);
	printf("Nombre del libro:");
	gotoxy(42, 7);
	printf("%c------------------------------%c", 218, 191);
	gotoxy(42, 8);
	printf("|                              |");
	gotoxy(42, 9);
	printf("%c------------------------------%c", 192, 217);
	gotoxy(44, 11);
	printf("Autor:");
	gotoxy(43, 12);
	printf("%c-------------%c", 218, 191);
	gotoxy(43, 13);
	printf("|             |");
	gotoxy(43, 14);
	printf("%c-------------%c", 192, 217);
	gotoxy(60, 11);
	printf("Editorial:");
	gotoxy(59, 12);
	printf("%c-------------%c", 218, 191);
	gotoxy(59, 13);
	printf("|             |");
	gotoxy(59, 14);
	printf("%c-------------%c", 192, 217);
	gotoxy(35, 17);
	printf("Fecha de registro:");
	gotoxy(53, 16);
	printf("%c----------%c", 218, 191);
	gotoxy(53, 17);
	printf("|          |");
	gotoxy(53, 18);
	printf("%c----------%c", 192, 217);
	gotoxy(53, 19);
	printf("%c---%c", 218, 191);
	gotoxy(53, 20);
	printf("|   |");
	gotoxy(53, 21);
	printf("%c---%c", 192, 217);
	gotoxy(44, 20);
	printf("Cantidad:");
}

void frmEstudiantes()
{
	limpiarArea();
	gotoxy(40, 3);
	printf("REGISTRO DE ESTUDIANTES");
	gotoxy(21, 4);
	printf("%c-----------------------------------------------------%c", 195, 180);
	gotoxy(27, 2);
	printf("%c", 194);
	gotoxy(22, 3);
	printf("<-ESC");
	gotoxy(27, 3);
	printf("|");
	gotoxy(27, 4);
	printf("%c", 193);
	gotoxy(35, 6);
	printf("Matricula:");
	gotoxy(34, 7);
	printf("%c-----------%c", 218, 191);
	gotoxy(34, 8);
	printf("|           |");
	gotoxy(34, 9);
	printf("%c-----------%c", 192, 217);
	gotoxy(50, 6);
	printf("Nombre:");
	gotoxy(49, 7);
	printf("%c-------------%c", 218, 191);
	gotoxy(49, 8);
	printf("|             |");
	gotoxy(49, 9);
	printf("%c-------------%c", 192, 217);
	gotoxy(24, 12);
	printf("Apellido Paterno:");
	gotoxy(42, 11);
	printf("%c-------------%c", 218, 191);
	gotoxy(42, 12);
	printf("|             |");
	gotoxy(42, 13);
	printf("%c-------------%c", 192, 217);
	gotoxy(24, 16);
	printf("Apellido Materno:");
	gotoxy(42, 15);
	printf("%c-------------%c", 218, 191);
	gotoxy(42, 16);
	printf("|             |");
	gotoxy(42, 17);
	printf("%c-------------%c", 192, 217);
	gotoxy(24, 20);
	printf("Carrera:");
	gotoxy(33, 19);
	printf("%c---------------------------------------%c", 218, 191);
	gotoxy(33, 20);
	printf("|                                       |");
	gotoxy(33, 21);
	printf("%c---------------------------------------%c", 192, 217);
}

void frmEmpleados()
{
	limpiarArea();
	gotoxy(41, 3);
	printf("REGISTRO DE EMPLEADOS");
	gotoxy(21, 4);
	printf("%c-----------------------------------------------------%c", 195, 180);
	gotoxy(27, 2);
	printf("%c", 194);
	gotoxy(22, 3);
	printf("<-ESC");
	gotoxy(27, 3);
	printf("|");
	gotoxy(27, 4);
	printf("%c", 193);
	gotoxy(35, 6);
	printf("ID Empleado:");
	gotoxy(34, 7);
	printf("%c-----------%c", 218, 191);
	gotoxy(34, 8);
	printf("|           |");
	gotoxy(34, 9);
	printf("%c-----------%c", 192, 217);
	gotoxy(50, 6);
	printf("Nombre:");
	gotoxy(49, 7);
	printf("%c-------------%c", 218, 191);
	gotoxy(49, 8);
	printf("|             |");
	gotoxy(49, 9);
	printf("%c-------------%c", 192, 217);
	gotoxy(24, 12);
	printf("Apellido Paterno:");
	gotoxy(42, 11);
	printf("%c-------------%c", 218, 191);
	gotoxy(42, 12);
	printf("|             |");
	gotoxy(42, 13);
	printf("%c-------------%c", 192, 217);
	gotoxy(24, 16);
	printf("Apellido Materno:");
	gotoxy(42, 15);
	printf("%c-------------%c", 218, 191);
	gotoxy(42, 16);
	printf("|             |");
	gotoxy(42, 17);
	printf("%c-------------%c", 192, 217);
	
}

void frmPrestamos()
{
	limpiarArea();
	gotoxy(43, 3);
	printf("REALIZAR PRESTAMO");
	gotoxy(21, 4);
	printf("%c-----------------------------------------------------%c", 195, 180);
	gotoxy(27, 2);
	printf("%c", 194);
	gotoxy(22, 3);
	printf("<-ESC");
	gotoxy(27, 3);
	printf("|");
	gotoxy(27, 4);
	printf("%c", 193);
	gotoxy(23, 6);
	printf("ID:");
	gotoxy(26, 5);
	printf("%c-----------%c", 218, 191);
	gotoxy(26, 6);
	printf("|           |");
	gotoxy(26, 7);
	printf("%c-----------%c", 192, 217);
	gotoxy(43, 6);
	printf("C%cdigo de libro:", 162);
	gotoxy(60, 5);
	printf("%c-----------%c", 218, 191);
	gotoxy(60, 6);
	printf("|           |");
	gotoxy(60, 7);
	printf("%c-----------%c", 192, 217);
	gotoxy(34, 9);
	printf("Matricula del Estudiante:");
	gotoxy(60, 8);
	printf("%c-----------%c", 218, 191);
	gotoxy(60, 9);
	printf("|           |");
	gotoxy(60, 10);
	printf("%c-----------%c", 192, 217);
	gotoxy(43, 12);
	printf("ID del Empleado:");
	gotoxy(60, 11);
	printf("%c-----------%c", 218, 191);
	gotoxy(60, 12);
	printf("|           |");
	gotoxy(60, 13);
	printf("%c-----------%c", 192, 217);
	gotoxy(41, 17);
	printf("Fecha de prestamo:");
	gotoxy(60, 16);
	printf("%c-----------%c", 218, 191);
	gotoxy(60, 17);
	printf("|           |");
	gotoxy(60, 18);
	printf("%c-----------%c", 192, 217);
	gotoxy(42, 20);
	printf("Fecha de entrega:");
	gotoxy(60, 19);
	printf("%c-----------%c", 218, 191);
	gotoxy(60, 20);
	printf("|           |");
	gotoxy(60, 21);
	printf("%c-----------%c", 192, 217);
}

void frmSalir()
{
	limpiarArea();
	gotoxy(42, 3);
	printf("SALIR DEL PROGRAMA");
	gotoxy(21, 4);
	printf("%c-----------------------------------------------------%c", 195, 180);
	gotoxy(27, 2);
	printf("%c", 194);
	gotoxy(22, 3);
	printf("<-ESC");
	gotoxy(27, 3);
	printf("|");
	gotoxy(27, 4);
	printf("%c", 193);
}

void frmBusqueda(int ent)
{
	switch(ent)
	{
		case 2:
			gotoxy(44, 3);
			printf("BUSCAR UN LIBRO");
			gotoxy(23, 6);
			printf("C%cdigo:", 162);
			gotoxy(30, 5);
			printf("%c-----------%c", 218, 191);
			gotoxy(30, 6);
			printf("|           |");
			gotoxy(30, 7);
			printf("%c-----------%c", 192, 217);
			break;
		case 3:
			gotoxy(41, 3);
			printf("BUSCAR UN ESTUDIANTE");
			gotoxy(23, 6);
			printf("Matricula:", 162);
			gotoxy(33, 5);
			printf("%c-----------%c", 218, 191);
			gotoxy(33, 6);
			printf("|           |");
			gotoxy(33, 7);
			printf("%c-----------%c", 192, 217);
			break;
		case 4:
			gotoxy(42, 3);
			printf("BUSCAR UN EMPLEADO");
			gotoxy(23, 6);
			printf("ID EMPLEADO:", 162);
			gotoxy(35, 5);
			printf("%c-----------%c", 218, 191);
			gotoxy(35, 6);
			printf("|           |");
			gotoxy(35, 7);
			printf("%c-----------%c", 192, 217);
			break;
		case 5:
			gotoxy(42, 3);
			printf("BUSCAR UN PRESTAMO");
			gotoxy(23, 6);
			printf("ID PRESTAMO:", 162);
			gotoxy(35, 5);
			printf("%c-----------%c", 218, 191);
			gotoxy(35, 6);
			printf("|           |");
			gotoxy(35, 7);
			printf("%c-----------%c", 192, 217);
			break;
	}
	gotoxy(21, 4);
	printf("%c-----------------------------------------------------%c", 195, 180);
	gotoxy(27, 2);
	printf("%c", 194);
	gotoxy(22, 3);
	printf("<-ESC");
	gotoxy(27, 3);
	printf("|");
	gotoxy(27, 4);
	printf("%c", 193);
}

void frmEdicion(int ent)
{
	switch(ent)
	{
		case 2:
			gotoxy(44, 3);
			printf("EDITAR UN LIBRO");
			gotoxy(27, 6);
			printf("C%cdigo:", 162);
			gotoxy(26, 7);
			printf("%c-----------%c", 218, 191);
			gotoxy(26, 8);
			printf("|           |");
			gotoxy(26, 9);
			printf("%c-----------%c", 192, 217);
			break;
		case 3:
			gotoxy(41, 3);
			printf("EDITAR UN ESTUDIANTE");
			gotoxy(35, 6);
			printf("Matricula:");
			gotoxy(34, 7);
			printf("%c-----------%c", 218, 191);
			gotoxy(34, 8);
			printf("|           |");
			gotoxy(34, 9);
			printf("%c-----------%c", 192, 217);
			break;
		case 4:
			gotoxy(42, 3);
			printf("EDITAR UN EMPLEADO");
			gotoxy(35, 6);
			printf("ID Empleado:");
			gotoxy(34, 7);
			printf("%c-----------%c", 218, 191);
			gotoxy(34, 8);
			printf("|           |");
			gotoxy(34, 9);
			printf("%c-----------%c", 192, 217);
			break;
		case 5:
			gotoxy(42, 3);
			printf("EDITAR UN PRESTAMO");
			gotoxy(23, 6);
			printf("ID PRESTAMO:", 162);
			gotoxy(35, 5);
			printf("%c------%c", 218, 191);
			gotoxy(35, 6);
			printf("|      |");
			gotoxy(35, 7);
			printf("%c------%c", 192, 217);
			break;
	}
	gotoxy(21, 4);
	printf("%c-----------------------------------------------------%c", 195, 180);
	gotoxy(27, 2);
	printf("%c", 194);
	gotoxy(22, 3);
	printf("<-ESC");
	gotoxy(27, 3);
	printf("|");
	gotoxy(27, 4);
	printf("%c", 193);
}

void frmEliminacion(int ent)
{
	switch(ent)
	{
		case 2:
			gotoxy(42, 3);
			printf("ELIMINAR UN LIBRO");
			gotoxy(23, 6);
			printf("C%cdigo:", 162);
			gotoxy(30, 5);
			printf("%c-----------%c", 218, 191);
			gotoxy(30, 6);
			printf("|           |");
			gotoxy(30, 7);
			printf("%c-----------%c", 192, 217);
			break;
		case 3:
			gotoxy(39, 3);
			printf("ELIMINAR UN ESTUDIANTE");
			gotoxy(23, 6);
			printf("Matricula:", 162);
			gotoxy(33, 5);
			printf("%c-----------%c", 218, 191);
			gotoxy(33, 6);
			printf("|           |");
			gotoxy(33, 7);
			printf("%c-----------%c", 192, 217);
			break;
		case 4:
			gotoxy(39, 3);
			printf("ELIMINAR UN EMPLEADO");
			gotoxy(23, 6);
			printf("ID EMPLEADO:", 162);
			gotoxy(35, 5);
			printf("%c-----------%c", 218, 191);
			gotoxy(35, 6);
			printf("|           |");
			gotoxy(35, 7);
			printf("%c-----------%c", 192, 217);
			break;
		case 5:
			gotoxy(40, 3);
			printf("ELIMINAR UN PRESTAMO");
			gotoxy(23, 6);
			printf("ID PRESTAMO:", 162);
			gotoxy(35, 5);
			printf("%c-----------%c", 218, 191);
			gotoxy(35, 6);
			printf("|           |");
			gotoxy(35, 7);
			printf("%c-----------%c", 192, 217);
			break;
	}
	gotoxy(21, 4);
	printf("%c-----------------------------------------------------%c", 195, 180);
	gotoxy(27, 2);
	printf("%c", 194);
	gotoxy(22, 3);
	printf("<-ESC");
	gotoxy(27, 3);
	printf("|");
	gotoxy(27, 4);
	printf("%c", 193);
}

void mostrarCampos(int ent)
{
	switch(ent)
	{
		case 2:
			gotoxy(43, 6);
			printf("Nombre del libro:");
			gotoxy(42, 7);
			printf("%c------------------------------%c", 218, 191);
			gotoxy(42, 8);
			printf("|                              |");
			gotoxy(42, 9);
			printf("%c------------------------------%c", 192, 217);
			gotoxy(44, 11);
			printf("Autor:");
			gotoxy(43, 12);
			printf("%c-------------%c", 218, 191);
			gotoxy(43, 13);
			printf("|             |");
			gotoxy(43, 14);
			printf("%c-------------%c", 192, 217);
			gotoxy(60, 11);
			printf("Editorial:");
			gotoxy(59, 12);
			printf("%c-------------%c", 218, 191);
			gotoxy(59, 13);
			printf("|             |");
			gotoxy(59, 14);
			printf("%c-------------%c", 192, 217);
			gotoxy(35, 17);
			printf("Fecha de registro:");
			gotoxy(53, 16);
			printf("%c----------%c", 218, 191);
			gotoxy(53, 17);
			printf("|          |");
			gotoxy(53, 18);
			printf("%c----------%c", 192, 217);
			gotoxy(53, 19);
			printf("%c---%c", 218, 191);
			gotoxy(53, 20);
			printf("|   |");
			gotoxy(53, 21);
			printf("%c---%c", 192, 217);
			gotoxy(44, 20);
			printf("Cantidad:");
			break;
		case 3:
			gotoxy(50, 6);
			printf("Nombre:");
			gotoxy(49, 7);
			printf("%c-------------%c", 218, 191);
			gotoxy(49, 8);
			printf("|             |");
			gotoxy(49, 9);
			printf("%c-------------%c", 192, 217);
			gotoxy(24, 12);
			printf("Apellido Paterno:");
			gotoxy(42, 11);
			printf("%c-------------%c", 218, 191);
			gotoxy(42, 12);
			printf("|             |");
			gotoxy(42, 13);
			printf("%c-------------%c", 192, 217);
			gotoxy(24, 16);
			printf("Apellido Materno:");
			gotoxy(42, 15);
			printf("%c-------------%c", 218, 191);
			gotoxy(42, 16);
			printf("|             |");
			gotoxy(42, 17);
			printf("%c-------------%c", 192, 217);
			gotoxy(24, 20);
			printf("Carrera:");
			gotoxy(33, 19);
			printf("%c---------------------------------------%c", 218, 191);
			gotoxy(33, 20);
			printf("|                                       |");
			gotoxy(33, 21);
			printf("%c---------------------------------------%c", 192, 217);
			break;
		case 4:
			gotoxy(50, 6);
			printf("Nombre:");
			gotoxy(49, 7);
			printf("%c-------------%c", 218, 191);
			gotoxy(49, 8);
			printf("|             |");
			gotoxy(49, 9);
			printf("%c-------------%c", 192, 217);
			gotoxy(24, 12);
			printf("Apellido Paterno:");
			gotoxy(42, 11);
			printf("%c-------------%c", 218, 191);
			gotoxy(42, 12);
			printf("|             |");
			gotoxy(42, 13);
			printf("%c-------------%c", 192, 217);
			gotoxy(24, 16);
			printf("Apellido Materno:");
			gotoxy(42, 15);
			printf("%c-------------%c", 218, 191);
			gotoxy(42, 16);
			printf("|             |");
			gotoxy(42, 17);
			printf("%c-------------%c", 192, 217);
			break;
		case 5:
			gotoxy(43, 6);
			printf("C%cdigo de libro:", 162);
			gotoxy(60, 5);
			printf("%c-----------%c", 218, 191);
			gotoxy(60, 6);
			printf("|           |");
			gotoxy(60, 7);
			printf("%c-----------%c", 192, 217);
			gotoxy(34, 9);
			printf("Matricula del Estudiante:");
			gotoxy(60, 8);
			printf("%c-----------%c", 218, 191);
			gotoxy(60, 9);
			printf("|           |");
			gotoxy(60, 10);
			printf("%c-----------%c", 192, 217);
			gotoxy(43, 12);
			printf("ID del Empleado:");
			gotoxy(60, 11);
			printf("%c-----------%c", 218, 191);
			gotoxy(60, 12);
			printf("|           |");
			gotoxy(60, 13);
			printf("%c-----------%c", 192, 217);
			gotoxy(41, 17);
			printf("Fecha de prestamo:");
			gotoxy(60, 16);
			printf("%c-----------%c", 218, 191);
			gotoxy(60, 17);
			printf("|           |");
			gotoxy(60, 18);
			printf("%c-----------%c", 192, 217);
			gotoxy(42, 20);
			printf("Fecha de entrega:");
			gotoxy(60, 19);
			printf("%c-----------%c", 218, 191);
			gotoxy(60, 20);
			printf("|           |");
			gotoxy(60, 21);
			printf("%c-----------%c", 192, 217);
			break;
	}
}

void mostrarDialogo()
{
	gotoxy(27, 16);
	printf("%c------------------------------------------%c", 218, 191);
	gotoxy(27, 17);
	printf("|                                          |");
	gotoxy(27, 18);
	printf("|        %cDeseas Eliminar este registro?   |", 168);
	gotoxy(27, 19);
	printf("|                                          |");
	gotoxy(27, 20);
	printf("|                      SI                  |");
	gotoxy(27, 21);
	printf("|                                          |");
	gotoxy(27, 22);
	printf("|                      NO                  |");
	gotoxy(27, 23);
	printf("%c------------------------------------------%c", 192, 217);
	gotoxy(30, 16);
	printf("%c", 24);
	gotoxy(28, 17);
	printf("%c---%c", 218, 191);
	gotoxy(28, 18);
	printf("| W |");
	gotoxy(28, 19);
	printf("%c---%c", 192, 217);
	gotoxy(28, 20);
	printf("%c---%c", 218, 191);
	gotoxy(28, 21);
	printf("| S |");
	gotoxy(28, 22);
	printf("%c---%c", 192, 217);
	gotoxy(30, 23);
	printf("%c", 25);
}

void limpiarArea()
{
	system("cls");
	frmMenu();
	gotoxy(0, 0);
	gotoxy(0, 23);
}

void selectorMenu(int op)
{
	switch(op)
	{
		case 1:
			gotoxy(5, 3);
			printf("%c  LIBROS       %c", 219, 219);
			gotoxy(5, 4);
			printf("%c-             -%c", 195, 180);
			gotoxy(5, 5);
			printf("|  ESTUDIANTES  |");
			gotoxy(5, 6);
			printf("|               |");
			break;
		case 2:
			gotoxy(5, 3);
			printf("|  LIBROS       |");
			gotoxy(5, 4);
			printf("%c-             -%c", 195, 180);
			gotoxy(5, 5);
			printf("%c  ESTUDIANTES  %c", 219, 219);
			gotoxy(5, 6);
			printf("%c-             -%c", 195, 180);
			gotoxy(5, 7);
			printf("|  EMPLEADOS    |");
			gotoxy(5, 8);
			printf("|               |");
			break;
		case 3:
			gotoxy(5, 4);
			printf("|               |");
			gotoxy(5, 5);
			printf("|  ESTUDIANTES  |");
			gotoxy(5, 6);
			printf("%c-             -%c", 195, 180);
			gotoxy(5, 7);
			printf("%c  EMPLEADOS    %c", 219, 219);
			gotoxy(5, 8);
			printf("%c-             -%c", 195, 180);
			gotoxy(5, 9);
			printf("|  PRESTAMOS    |", 219, 219);
			gotoxy(5, 10);
			printf("|               |");
			break;
		case 4:
			gotoxy(5, 6);
			printf("|               |");
			gotoxy(5, 7);
			printf("|  EMPLEADOS    |");
			gotoxy(5, 8);
			printf("%c-             -%c", 195, 180);
			gotoxy(5, 9);
			printf("%c  PRESTAMOS    %c", 219, 219);
			gotoxy(5, 10);
			printf("%c-             -%c", 195, 180);
			gotoxy(5, 11);
			printf("|  SALIR   <-   |");
			gotoxy(5, 12);
			printf("|               |");
			break;
		case 5:
			gotoxy(5, 8);
			printf("|               |");
			gotoxy(5, 9);
			printf("|  PRESTAMOS    |");
			gotoxy(5, 10);
			printf("%c-             -%c", 195, 180);
			gotoxy(5, 11);
			printf("%c  SALIR  <-    %c", 219, 219);
			gotoxy(5, 12);
			printf("%c-             -%c", 195, 180);
			break;
	}
}

void selectorOpciones(int op, int ind)
{
	switch(op)
	{
		case 1:
			gotoxy(23, 3 + ind);
			printf("->");
			gotoxy(23, 5 + ind);
			printf("  ");
			break;
		case 2:
			gotoxy(23, 3 + ind);
			printf("  ");
			gotoxy(23, 5 + ind);
			printf("->");
			gotoxy(23, 7 + ind);
			printf("  ");
			break;
		case 3:
			gotoxy(23, 5 + ind);
			printf("  ");
			gotoxy(23, 7 + ind);
			printf("->");
			gotoxy(23, 9 + ind);
			printf("  ");
			break;
		case 4:
			gotoxy(23, 7 + ind);
			printf("  ");
			gotoxy(23, 9 + ind);
			printf("->");
			gotoxy(23, 11 + ind);
			printf("  ");
			break;
		case 5:
			gotoxy(23, 9 + ind);
			printf("  ");
			gotoxy(23, 11 + ind);
			printf("->");
			gotoxy(23, 13 + ind);
			printf("  ");
			break;
		case 6:
			gotoxy(23, 11 + ind);
			printf("  ");
			gotoxy(23, 13 + ind);
			printf("->");
			break;
	}
}

int capturaLibro(int * op, int * modo, int * ent)
{
	limpiarArea(); //Limpia pantalla o area de trabajo
	do
	{
		lib.codigo = NULL;
		memset(lib.nombre, '\0', 30);
		memset(lib.autor, '\0', 13);
		memset(lib.editorial, '\0', 13);
		memset(lib.fechaRegistro, '\0', 11);
		lib.cantidad = NULL; //Limpiar la variable de estructura
		frmLibros(); //Formulario de los Libros
		cod: //Es una etiqueta
		gotoxy(27, 8);
		printf("            ");
		gotoxy(27, 8);
		//Empezamos a capturar
		lib.codigo = nument(10, 1);
		//Validamos que exista el código
		if(validarRegistro(2, lib.codigo) == 0 || validarRegistro(2, lib.codigo) == 1)
		{
			gotoxy(18, 23);
			printf("Ya existe un registro asociado a este c%cdigo...", 162);
			getch();
			gotoxy(18, 23);
			printf("                                               ");
			goto cod;
		}
		if(lib.codigo == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		gotoxy(43, 8);
		if(valitext(29, &lib.nombre, 1) == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		gotoxy(44, 13);
		if(valitext(12, &lib.autor, 1) == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		gotoxy(60, 13);
		if(valitext(12, &lib.editorial, 1) == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		gotoxy(54, 17);
		if(valifec(&lib.fechaRegistro, 1) == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		gotoxy(54, 20);
		lib.cantidad = nument(2, 1);
		if(lib.cantidad == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		//Aquí escribimos o guardamos el nuevo registro ingresado.
		if(escribirLibro() == -1)
		{
			gotoxy(25, 20);
			printf("Hubo un error al intentar escribir el libro...");
		}
		getch();
		gotoxy(25, 23);
		printf("                                                   ");
		limpiarArea();
	}while(1);
}

int escribirLibro()
{
	archivo = fopen("Libros.dat", "ab");
	if(archivo == NULL)
		return -1;
	fwrite(&lib, sizeof(struct Libro), 1, archivo); //Aquí escribimos el registro en el archivo abierto
	fclose(archivo); //Aqui lo cerramos
	gotoxy(30, 23);
	printf("Se ha registrado el libro con exito...");
	return 0;
}

int mostrarLibros()
{
	limpiarArea();
	int numregistros = 0;
	archivo = fopen("Libros.dat", "rb");
	if (archivo == NULL)
		return -1;
	gotoxy(27, 2);
	printf("%c", 194);
	gotoxy(22, 3);
	printf("<-ESC");
	gotoxy(27, 3);
	printf("|");
	gotoxy(41, 3);
	rewind(archivo); //Nos posicionamos en el principio del archivo
	fread(&lib, sizeof(struct Libro), 1, archivo);
	while(!feof(archivo))
	{
		numregistros += lib.cantidad;
		fread(&lib, sizeof(struct Libro), 1, archivo);
	}
	fclose(archivo);
	printf("%i LIBROS REGISTRADOS", numregistros);
	gotoxy(21, 4);
	printf("%c-----------------------------------------------------%c", 195, 180);
	gotoxy(27, 4);
	printf("%c", 193);
	gotoxy(23, 9);
	printf("  ");
	archivo = fopen("Libros.dat", "rb");
	if (archivo == NULL)
		return -1;
	fread(&lib, sizeof(struct Libro), 1, archivo);
	numregistros = -7;
	while(!feof(archivo))
	{		
		if(lib.cantidad > 0)
		{
			numregistros += 7;
			dibujarLibros(0, numregistros);
			gotoxy(32, 5 + numregistros);
			printf("Codigo: %i", lib.codigo);
			gotoxy(32, 6 + numregistros);
			printf("Nombre: %s", lib.nombre);
			gotoxy(32, 7 + numregistros);
			printf("Autor: %s", lib.autor);
			gotoxy(32, 8 + numregistros);
			printf("Editorial: %s", lib.editorial);
			gotoxy(32, 9 + numregistros);
			printf("Fecha: %s", lib.fechaRegistro);
			gotoxy(32, 10 + numregistros);
			printf("Cantidad: %i", lib.cantidad);
		}
		fread(&lib, sizeof(struct Libro), 1, archivo);
	}
	fclose(archivo);
	gotoxy(0, 0);
	gotoxy(0, 23);
	getch();
	return 0;
}

void dibujarLibros(int x, int y)
{
	gotoxy(23 + x, 5 + y);
	printf("%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 187);
	gotoxy(23 + x, 6 + y);
	printf("%c %c--%c %c", 186, 218, 191, 186);
	gotoxy(23 + x, 7 + y);
	printf("%c %c--%c %c", 186, 192, 217, 186);
	gotoxy(23 + x, 8 + y);
	printf("%c ~~~~ %c", 186, 186);
	gotoxy(23 + x, 9 + y);
	printf("%c ~~~~ %c", 186, 186);
	gotoxy(23 + x, 10 + y);
	printf("%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 188);
}

int capturaEstudiante(int * op, int * modo, int * ent)
{
	limpiarArea();
	do
	{
		est.matricula = NULL;
		memset(est.nombre, '\0', 12);
		memset(est.apellidoP, '\0', 12);
		memset(est.apellidoM, '\0', 12);
		memset(est.carrera, '\0', 40);
		est.pendiente = NULL;
		est.codLibro = NULL;
		est.status = NULL;
		frmEstudiantes();
		mat:
		gotoxy(35, 8);
		printf("          ");
		gotoxy(35, 8);
		est.matricula = nument(10, 1);
		if(validarRegistro(3, est.matricula) == 0 || validarRegistro(3, est.matricula) == 1)
		{
			gotoxy(15, 23);
			printf("Ya existe un registro asociado a esta matricula...", 162);
			getch();
			gotoxy(15, 23);
			printf("                                                  ");
			goto mat;
		}
		if(est.matricula == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		gotoxy(50, 8);
		if(valitext(11, &est.nombre, 1) == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		gotoxy(43, 12);
		if(valitext(11, &est.apellidoP, 1) == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		gotoxy(43, 16);
		if(valitext(11, &est.apellidoM, 1) == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		gotoxy(34, 20);
		if(valitext(39, &est.carrera, 1) == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		est.pendiente = 0;
		est.codLibro = 0;
		est.status = 1;
		//Guardar registro
		if(escribirEstudiante() == -1)
		{
			gotoxy(25, 20);
			printf("Hubo un error al intentar escribir el estudiante...");
		}
		getch();
		gotoxy(25, 23);
		printf("                                                   ");
		limpiarArea();
	}while(1);
}

int escribirEstudiante()
{
	archivo = fopen("Estudiantes.dat","ab");
	if(archivo == NULL)
		return -1;
	fwrite(&est, sizeof(struct Estudiante), 1, archivo);
	fclose(archivo);
	gotoxy(24, 23);
	printf("Se ha registrado el estudiante con exito...");
	return 0;
}

int mostrarEstudiantes()
{
	int numregistros = 0;
	archivo = fopen("Estudiantes.dat", "rb");
	if (archivo == NULL)
		return -1;
	rewind(archivo);
	fread(&est, sizeof(struct Estudiante), 1, archivo);
	while(!feof(archivo))
	{
		if(est.status > 0)
			numregistros++;
		fread(&est, sizeof(struct Estudiante), 1, archivo);
	}
	if(numregistros == 0)
	{
		fclose(archivo);
		return -1;
	}
	else
	{
		limpiarArea();
		gotoxy(27, 2);
		printf("%c", 194);
		gotoxy(22, 3);
		printf("<-ESC");
		gotoxy(27, 3);
		printf("|");
		gotoxy(38, 3);
	}
	fclose(archivo);
	printf("%i ESTUDIANTES REGISTRADOS", numregistros);
	gotoxy(21, 4);
	printf("%c-----------------------------------------------------%c", 195, 180);
	gotoxy(27, 4);
	printf("%c", 193);
	gotoxy(23, 9);
	printf("  ");
	archivo = fopen("Estudiantes.dat", "rb");
	if (archivo == NULL)
		return -1;
	fread(&est, sizeof(struct Estudiante), 1, archivo);
	numregistros = -7;
	while(!feof(archivo))
	{
		if(est.status > 0)
		{
			numregistros += 7;
			dibujarEstudiantes(0, numregistros); //Dibujas Estudiante
			gotoxy(32, 5 + numregistros);
			printf("Matricula: %i", est.matricula);
			gotoxy(32, 6 + numregistros);
			printf("Nombre: %s", est.nombre);
			gotoxy(32, 7 + numregistros);
			printf("Apellido Paterno: %s", est.apellidoP);
			gotoxy(32, 8 + numregistros);
			printf("Apellido Materno: %s", est.apellidoM);
			gotoxy(32, 9 + numregistros);
			printf("Carrera: %s", est.carrera);
			gotoxy(32, 10 + numregistros);
			printf("Prestamo pendiente: ");
			if(est.pendiente <= 0)
				printf("NO");
			else
				printf("SI");
		}
		fread(&est, sizeof(struct Estudiante), 1, archivo);
	}
	fclose(archivo);
	gotoxy(0, 0);
	gotoxy(0, 23);
	getch();
	return 0;
}

void dibujarEstudiantes(int x, int y)
{
	gotoxy(26 + x, 5 + y);
	printf("%c-%c", 218, 191);
	gotoxy(25 + x, 6 + y);
	printf("%c%c-%c%c", 218, 193, 193, 191);
	gotoxy(25 + x, 7 + y);
	printf("|   |");
	gotoxy(25 + x, 8 + y);
	printf("|   |");
	gotoxy(25 + x, 9 + y);
	printf("%c---%c", 192, 217);
}

int capturaEmpleado(int * op, int * modo, int * ent)
{
	do
	{
		emp.idEmpleado = NULL;
		memset(emp.nombre, '\0', 12);
		memset(emp.apellidoP, '\0', 12);
		memset(emp.apellidoM, '\0', 12);
		emp.status = NULL;
		frmEmpleados();
		int var = 1;
		ids:
		if (validarRegistro(4, var) == 1)
		{
			emp.idEmpleado = 1;
			gotoxy(35, 8);
			printf("%i", emp.idEmpleado);
		}
		else if (validarRegistro(4, var) == 0)
		{
			var++;
			goto ids;
		}
		else
		{
			emp.idEmpleado = var;
			gotoxy(35, 8);
			printf("%i", emp.idEmpleado);
		}
		gotoxy(50, 8);
		if(valitext(11, &emp.nombre, 1) == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		gotoxy(43, 12);
		if(valitext(11, &emp.apellidoP, 1) == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		gotoxy(43, 16);
		if(valitext(11, &emp.apellidoM, 1) == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		emp.status = 1;
		gotoxy(34, 20);
		if(escribirEmpleado() == -1)
		{
			gotoxy(25, 20);
			printf("Hubo un error al intentar escribir el empleado...");
		}
		getch();
		gotoxy(25, 23);
		printf("                                                   ");
		limpiarArea();
	}while(1);
}

int escribirEmpleado()
{
	archivo = fopen("Empleados.dat","ab");
	if(archivo == NULL)
		return -1;
	fwrite(&emp, sizeof(struct Empleado), 1, archivo);
	fclose(archivo);
	gotoxy(24, 23);
	printf("Se ha registrado el empleado con exito...");
	return 0;
}

int mostrarEmpleados()
{
	int numregistros = 0;
	archivo = fopen("Empleados.dat", "rb");
	if (archivo == NULL)
		return -1;
	rewind(archivo);
	fread(&emp, sizeof(struct Empleado), 1, archivo);
	while(!feof(archivo))
	{
		if(emp.status > 0)
			numregistros++;
		fread(&emp, sizeof(struct Empleado), 1, archivo);
	}
	if(numregistros == 0)
	{
		fclose(archivo);
		return -1;
	}
	else
	{
		limpiarArea();
		gotoxy(27, 2);
		printf("%c", 194);
		gotoxy(22, 3);
		printf("<-ESC");
		gotoxy(27, 3);
		printf("|");
		gotoxy(38, 3);
	}
	fclose(archivo);
	printf("%i EMPLEADOS REGISTRADOS", numregistros);
	gotoxy(21, 4);
	printf("%c-----------------------------------------------------%c", 195, 180);
	gotoxy(27, 4);
	printf("%c", 193);
	gotoxy(23, 9);
	printf("  ");
	archivo = fopen("Empleados.dat", "rb");
	if (archivo == NULL)
		return -1;
	fread(&emp, sizeof(struct Empleado), 1, archivo);
	numregistros = -7;
	while(!feof(archivo))
	{
		if(emp.status > 0)
		{
			numregistros += 7;
			dibujarEmpleados(0, numregistros);
			gotoxy(32, 5 + numregistros);
			printf("ID Empleado: %i", emp.idEmpleado);
			gotoxy(32, 6 + numregistros);
			printf("Nombre: %s", emp.nombre);
			gotoxy(32, 7 + numregistros);
			printf("Apellido Paterno: %s", emp.apellidoP);
			gotoxy(32, 8 + numregistros);
			printf("Apellido Materno: %s", emp.apellidoM);
		}
		fread(&emp, sizeof(struct Empleado), 1, archivo);
	}
	fclose(archivo);
	gotoxy(0, 0);
	gotoxy(0, 23);
	getch();
	return 0;
}

void dibujarEmpleados(int x, int y)
{
	gotoxy(26 + x, 5 + y);
	printf("%c-%c", 218, 191);
	gotoxy(25 + x, 6 + y);
	printf("%c%c%c%c%c", 218, 193, 220, 193, 191);
	gotoxy(25 + x, 7 + y);
	printf("| %c |", 186);
	gotoxy(25 + x, 8 + y);
	printf("|   |");
	gotoxy(25 + x, 9 + y);
	printf("%c---%c", 192, 217);
}

int capturaPrestamo(int * op, int * modo, int * ent)
{
	do
	{
		pre.idPrestamo = NULL;
		pre.codLibro = NULL;
		pre.matEst = NULL;
		pre.idEmpleado = NULL;
		memset(pre.fechaPrestamo, '\0', 11);
		memset(pre.fechaDevolucion, '\0', 11);
		pre.seDevolvio = NULL;
		pre.status = NULL;
		frmPrestamos();
		int var = 1;
		idp:
		gotoxy(27, 6);
		printf("           ");
		gotoxy(27, 6);
		if (validarRegistro(5, var) == 1)
		{
			pre.idPrestamo = 1;
			gotoxy(27, 6);
			printf("%i", pre.idPrestamo);
		}
		else if (validarRegistro(5, var) == 0)
		{
			var++;
			goto idp;
		}
		else
		{
			pre.idPrestamo = var;
			gotoxy(27, 6);
			printf("%i", pre.idPrestamo);
		}
		cod:
		gotoxy(61, 6);
		printf("           ");
		gotoxy(61, 6);
		pre.codLibro = nument(10, 1);
		if(pre.codLibro == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		if(validarRegistro(2, pre.codLibro) == -1)
		{
			gotoxy(20, 23);
			printf("No existe el codigo de libro ingresado...");
			getch();
			gotoxy(20, 23);
			printf("                                         ");
			goto cod;
		}
		else if (validarRegistro(2, pre.codLibro) == 1)
		{
			gotoxy(12, 23);
			printf("Solo queda 1 Libro de este tipo, no se puede prestar...");
			getch();
			gotoxy(12, 23);
			printf("                                                       ");
			goto cod;
		}
		mat:
		gotoxy(61, 9);
		printf("           ");
		gotoxy(61, 9);
		pre.matEst = nument(10, 1);
		if(pre.matEst == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		if(validarRegistro(3, pre.matEst) == -1)
		{
			gotoxy(15, 23);
			printf("No existe un estudiante asociado a esta matricula...");
			getch();
			gotoxy(15, 23);
			printf("                                                    ");
			goto mat;
		}
		else if (validarRegistro(3, pre.matEst) == 1)
		{
			gotoxy(20, 23);
			printf("Este estudiante a%cn debe un prestamo...", 163);
			getch();
			gotoxy(20, 23);
			printf("                                         ");
			goto mat;
		}
		ide:
		gotoxy(61, 12);
		printf("           ");
		gotoxy(61, 12);
		pre.idEmpleado = nument(10, 1);
		if(pre.idEmpleado == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		if(validarRegistro(4, pre.idEmpleado) == -1 || validarRegistro(4, pre.idEmpleado) == 1)
		{
			gotoxy(20, 23);
			printf("No existe un empleado asociado con este ID...");
			getch();
			gotoxy(20, 23);
			printf("                                             ");
			goto ide;
		}
		gotoxy(61, 17);
		if(valifec(&pre.fechaPrestamo, 1) == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		gotoxy(61, 20);
		if(valifec(&pre.fechaDevolucion, 1) == -1)
		{
			*op = 1;
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		pre.seDevolvio = 0;
		pre.status = 1;
		if(escribirPrestamo() == -1)
		{
			gotoxy(25, 20);
			printf("Hubo un error al intentar registrar el prestamo...");
		}
		getch();
		gotoxy(25, 23);
		printf("                                                   ");
		limpiarArea();
	}while(1);
}

int escribirPrestamo()
{
	archivo = fopen("Prestamos.dat","ab");
	if(archivo == NULL)
		return -1;
	fwrite(&pre, sizeof(struct Prestamo), 1, archivo);
	fclose(archivo);
	archivo = fopen("Libros.dat", "r+b");
	if(archivo == NULL)
		return -1;
	fread(&lib, sizeof(struct Libro), 1, archivo);
	while(!feof(archivo))
	{
		if (pre.codLibro == lib.codigo)
		{
			if(lib.cantidad > 1)
			{
				lib.cantidad--;
				int pos = ftell(archivo) - sizeof(struct Libro);
	            fseek(archivo, pos, SEEK_SET);
	            fwrite(&lib, sizeof(struct Libro), 1, archivo);
	            break;
			}
			else
				break;
		}
		fread(&lib, sizeof(struct Libro), 1, archivo);
	}
	fclose(archivo);
	archivo = fopen("Estudiantes.dat", "r+b");
	if(archivo == NULL)
		return -1;
	fread(&est, sizeof(struct Estudiante), 1, archivo);
    while(!feof(archivo))
    {
        if (pre.matEst == est.matricula)
        {
         	if(est.pendiente != 1)
        		est.pendiente = 1;
        	est.codLibro = pre.codLibro;
            int pos = ftell(archivo) - sizeof(struct Estudiante);
            fseek(archivo, pos, SEEK_SET);
            fwrite(&est, sizeof(struct Estudiante), 1, archivo);
            break;
        }
        fread(&est, sizeof(struct Estudiante), 1, archivo);
    }
    fclose(archivo);
	gotoxy(24, 23);
	printf("Se ha registrado el prestamo con exito...");
	return 0;
}

int mostrarPrestamos()
{
	int numregistros = 0, cont = -33, regs = 0, lineas = 0, x;
	//Cargar Prestamo
	archivo = fopen("Prestamos.dat", "rb");
	if (archivo == NULL)
		return -1;
	rewind(archivo);
	fread(&pre, sizeof(struct Prestamo), 1, archivo);
	while(!feof(archivo))
	{
		if(pre.status > 0)
			numregistros++;
		fread(&pre, sizeof(struct Prestamo), 1, archivo);
	}
	if(numregistros == 0)
	{
		fclose(archivo);
		return -1;
	}
	else
	{
		limpiarArea();
		gotoxy(27, 2);
		printf("%c", 194);
		gotoxy(22, 3);
		printf("<-ESC");
		gotoxy(27, 3);
		printf("|");
		gotoxy(40, 3);
	}
	lineas = numregistros;
	fclose(archivo);
	printf("%i PRESTAMOS REALIZADOS", numregistros);
	gotoxy(21, 4);
	printf("%c-----------------------------------------------------%c", 195, 180);
	gotoxy(27, 4);
	printf("%c", 193);
	gotoxy(23, 9);
	printf("  ");
	//Inicio de bucle
	bucle:
	x = 1;
	regs++;
	cont += 33;
	archivo = fopen("Prestamos.dat", "rb");
	if (archivo == NULL)
		return -1;
	while(x <= regs)
	{
		x++;
		fread(&pre, sizeof(struct Prestamo), 1, archivo);
	}
	fclose(archivo);
	//Cargar Libro
	archivo = fopen("Libros.dat", "rb");
	if(archivo == NULL)
		return -1;
	fread(&lib, sizeof(struct Libro), 1, archivo);
	while(!feof(archivo))
	{
		if(pre.codLibro == lib.codigo)
		{
			break;
		}
		fread(&lib, sizeof(struct Libro), 1, archivo);
	}
	fclose(archivo);
	//Cargar Estudiante
	archivo = fopen("Estudiantes.dat", "rb");
	if(archivo == NULL)
		return -1;
	fread(&est, sizeof(struct Estudiante), 1, archivo);
	while(!feof(archivo))
	{
		if(pre.matEst == est.matricula)
		{
			break;
		}
		fread(&est, sizeof(struct Estudiante), 1, archivo);
	}
	fclose(archivo);
	//Cargar Empleado
	archivo = fopen("Empleados.dat", "rb");
	if(archivo == NULL)
		return -1;
	fread(&emp, sizeof(struct Empleado), 1, archivo);
	while(!feof(archivo))
	{
		if(pre.idEmpleado == emp.idEmpleado)
		{
			break;
		}
		fread(&emp, sizeof(struct Empleado), 1, archivo);
	}
	fclose(archivo);
	if(pre.status > 0 && lib.cantidad > 0 && est.status > 0 && emp.status > 0)
	{
		numregistros = -7;
		dibujarPrestamos(0, cont);
		numregistros += 7;
		gotoxy(25, 5 + cont + numregistros);
		printf("PRESTAMO #%i", pre.idPrestamo);
		gotoxy(25, 7 + cont);
		printf("LIBRO PRESTADO: ");
		dibujarLibros(2, cont + (numregistros + 4));
		gotoxy(34, 10 + cont + numregistros);
		printf("Codigo: %i", lib.codigo);
		gotoxy(34, 11 + cont + numregistros);
		printf("Nombre: %s", lib.nombre);
		gotoxy(34, 12 + cont + numregistros);
		printf("Autor: %s", lib.autor);
		gotoxy(34, 13 + cont + numregistros);
		printf("Editorial: %s", lib.editorial);
		gotoxy(25, 16 + cont);
		printf("ESTUDIANTE QUE SOLICIT%c EL LIBRO: ", 224);
		dibujarEstudiantes(2, cont + (numregistros + 13));
		gotoxy(34, 18 + cont + numregistros);
		printf("Matricula: %i", est.matricula);
		gotoxy(34, 19 + cont + numregistros);
		printf("Nombre: %s", est.nombre);
		gotoxy(34, 20 + cont + numregistros);
		printf("Apellido Paterno: %s", est.apellidoP);
		gotoxy(34, 21 + cont + numregistros);
		printf("Apellido Materno: %s", est.apellidoM);
		gotoxy(34, 22 + cont + numregistros);
		printf("Carrera: %s", est.carrera);
		gotoxy(25, 24 + cont);
		printf("EMPLEADO QUE ATENDI%c AL ESTUDIANTE: ", 224);
		dibujarEmpleados(2, cont + (numregistros + 21));
		gotoxy(34, 26 + cont + numregistros);
		printf("ID Empleado: %i", emp.idEmpleado);
		gotoxy(34, 27 + cont + numregistros);
		printf("Nombre: %s", emp.nombre);
		gotoxy(34, 28 + cont + numregistros);
		printf("Apellido Paterno: %s", emp.apellidoP);
		gotoxy(34, 29 + cont + numregistros);
		printf("Apellido Materno: %s", emp.apellidoM);
		gotoxy(25, 32 + cont + numregistros);
		printf("Fecha de Prestamo: %s", pre.fechaPrestamo);
		gotoxy(25, 33 + cont + numregistros);
		printf("Fecha de Entrega: %s", pre.fechaDevolucion);
		gotoxy(25, 35 + cont);
		printf("ESTADO ACTUAL: ");
		if(pre.seDevolvio == 0)
			printf("No se ha devuelto.");
		else
			printf("Ya se devolvi%c el prestamo.", 162);
	}
	if(lineas > 1)
	{
		lineas--;
		goto bucle;
	}
	fclose(archivo);
	gotoxy(0, 0);
	gotoxy(0, 23);
	getch();
	return 0;
}

void dibujarPrestamos(int x, int y) //Dibuja el marco de los prestamos
{
	gotoxy(23, 6 + y);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	gotoxy(23, 7 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 8 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 9 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 10 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 11 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 12 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 13 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 14 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 15 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 16 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 17 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 18 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 19 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 20 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 21 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 22 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 23 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 24 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 25 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 26 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 27 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 28 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 29 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 30 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 31 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 32 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 33 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 34 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 35 + y);
	printf("%c                                                 %c", 186, 186);
	gotoxy(23, 36 + y);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
}

int buscarRegistro(int ent, int reg) //Busca y muestra registros
{
	struct Libro regLi;
	struct Estudiante regEs;
	struct Empleado regEm;
	struct Prestamo regPr;
	switch(ent)
	{
		case 2:
			archivo = fopen("Libros.dat","rb");
			if (archivo == NULL)
				break;
			fread(&regLi, sizeof(struct Libro), 1, archivo);
			while(!feof(archivo))
			{
				if (reg != regLi.codigo)
				{
					fread(&regLi, sizeof(struct Libro), 1, archivo);
					continue;
				}
				else
				{
					if(regLi.cantidad > 0)
					{
						dibujarLibros(0, 4);
						gotoxy(32, 9);
						printf("Codigo: %i", regLi.codigo);
						gotoxy(32, 10);
						printf("Nombre: %s", regLi.nombre);
						gotoxy(32, 11);
						printf("Autor: %s", regLi.autor);
						gotoxy(32, 12);
						printf("Editorial: %s", regLi.editorial);
						gotoxy(32, 13);
						printf("Fecha: %s", regLi.fechaRegistro);
						gotoxy(32, 14);
						printf("Cantidad: %i", regLi.cantidad);
					}
					else
						break;
					return 0;
				}
			}
			fclose(archivo);
			break;
		case 3:
			archivo = fopen("Estudiantes.dat","rb");
			if (archivo == NULL)
				break;
			fread(&regEs, sizeof(struct Estudiante), 1, archivo);
			while(!feof(archivo))
			{
				if (reg != regEs.matricula)
				{
					fread(&regEs, sizeof(struct Estudiante), 1, archivo);
					continue;
				}
				else
				{
					if(regEs.status > 0)
					{
						dibujarEstudiantes(0, 4);
						gotoxy(32, 9);
						printf("Matricula: %i", regEs.matricula);
						gotoxy(32, 10);
						printf("Nombre: %s", regEs.nombre);
						gotoxy(32, 11);
						printf("Apellido Paterno: %s", regEs.apellidoP);
						gotoxy(32, 12);
						printf("Apellido Materno: %s", regEs.apellidoM);
						gotoxy(32, 13);
						printf("Carrera: %s", regEs.carrera);
						gotoxy(32, 14);
						if(regEs.pendiente == 1)
							printf("Prestamo pendiente: SI");
						else
							printf("Prestamo pendiente: NO");
					}
					else
						break;
					return 0;
				}
			}
			fclose(archivo);
			break;
		case 4:
			archivo = fopen("Empleados.dat","rb");
			if (archivo == NULL)
				break;
			fread(&regEm, sizeof(struct Empleado), 1, archivo);
			while(!feof(archivo))
			{
				if (reg != regEm.idEmpleado)
				{
					fread(&regEm, sizeof(struct Empleado), 1, archivo);
					continue;
				}
				else
				{
					if(regEm.status > 0)
					{
						dibujarEmpleados(0, 4);
						gotoxy(32, 9);
						printf("ID Empleado: %i", regEm.idEmpleado);
						gotoxy(32, 10);
						printf("Nombre: %s", regEm.nombre);
						gotoxy(32, 11);
						printf("Apellido Paterno: %s", regEm.apellidoP);
						gotoxy(32, 12);
						printf("Apellido Materno: %s", regEm.apellidoM);
					}
					else
						break;
					return 0;
				}
			}
			fclose(archivo);
			break;
		case 5:
			archivo = fopen("Prestamos.dat","rb");
			if (archivo == NULL)
				break;
			fread(&regPr, sizeof(struct Prestamo), 1, archivo);
			while(!feof(archivo))
			{
				if (reg != regPr.idPrestamo)
				{
					fread(&regPr, sizeof(struct Prestamo), 1, archivo);
					continue;
				}
				else if (reg == regPr.idPrestamo && regPr.status == 1)
				{
					fclose(archivo);
					archivo = fopen("Libros.dat","rb");
					if (archivo == NULL)
						break;
					fread(&regLi, sizeof(struct Libro), 1, archivo);
					while(!feof(archivo))
					{
						if (regPr.codLibro == regLi.codigo)
						{
							break;
						}
						fread(&regLi, sizeof(struct Libro), 1, archivo);
					}
					fclose(archivo);
					archivo = fopen("Estudiantes.dat","rb");
					if (archivo == NULL)
						break;
					fread(&regEs, sizeof(struct Estudiante), 1, archivo);
					while(!feof(archivo))
					{
						if (regPr.matEst == regEs.matricula)
						{
							break;
						}
						fread(&regEs, sizeof(struct Estudiante), 1, archivo);
					}
					fclose(archivo);
					archivo = fopen("Empleados.dat","rb");
					if (archivo == NULL)
						break;
					fread(&regEm, sizeof(struct Empleado), 1, archivo);
					while(!feof(archivo))
					{
						if (regPr.idEmpleado == regEm.idEmpleado)
						{
							break;
						}
						fread(&regEm, sizeof(struct Empleado), 1, archivo);
					}
					fclose(archivo);
					if(regPr.status > 0 && regLi.cantidad > 0 && regEs.status > 0 && regEm.status > 0)
					{
						gotoxy(36, 5);
						printf("            ");
						dibujarPrestamos(0, 0);
						gotoxy(25, 5);
						printf("PRESTAMO #%i", regPr.idPrestamo);
						gotoxy(25, 7);
						printf("LIBRO PRESTADO: ");
						dibujarLibros(2, 4);
						gotoxy(34, 10);
						printf("Codigo: %i", regLi.codigo);
						gotoxy(34, 11);
						printf("Nombre: %s", regLi.nombre);
						gotoxy(34, 12);
						printf("Autor: %s", regLi.autor);
						gotoxy(34, 13);
						printf("Editorial: %s", regLi.editorial);
						gotoxy(25, 16);
						printf("ESTUDIANTE QUE SOLICIT%c EL LIBRO: ", 224);
						dibujarEstudiantes(2, 13);
						gotoxy(34, 18);
						printf("Matricula: %i", regEs.matricula);
						gotoxy(34, 19);
						printf("Nombre: %s", regEs.nombre);
						gotoxy(34, 20);
						printf("Apellido Paterno: %s", regEs.apellidoP);
						gotoxy(34, 21);
						printf("Apellido Materno: %s", regEs.apellidoM);
						gotoxy(34, 22);
						printf("Carrera: %s", regEs.carrera);
						gotoxy(25, 24);
						printf("EMPLEADO QUE ATENDI%c AL ESTUDIANTE: ", 224);
						dibujarEmpleados(2, 21);
						gotoxy(34, 26);
						printf("ID Empleado: %i", regEm.idEmpleado);
						gotoxy(34, 27);
						printf("Nombre: %s", regEm.nombre);
						gotoxy(34, 28);
						printf("Apellido Paterno: %s", regEm.apellidoP);
						gotoxy(34, 29);
						printf("Apellido Materno: %s", regEm.apellidoM);
						gotoxy(25, 32);
						printf("Fecha de Prestamo: %s", regPr.fechaPrestamo);
						gotoxy(25, 33);
						printf("Fecha de Entrega: %s", regPr.fechaDevolucion);
						gotoxy(25, 35);
						printf("ESTADO ACTUAL: ");
						if(regPr.seDevolvio == 0)
							printf("No se ha devuelto.");
						else
							printf("Ya se devolvi%c el prestamo.", 162);
					}
					else
					{
						regPr.status = 0;
						break;
					}
					return 0;
				}
			}
			fclose(archivo);
			break;
	}
	gotoxy(24, 23);
	printf("No se encontr%c el registro...", 162);
	return -1;
}

int validarRegistro(int ent, int reg) //Valida la existencia de un registro
{
	struct Libro regLi;
	struct Estudiante regEs;
	struct Empleado regEm;
	struct Prestamo regPr;
	switch(ent)
	{
		case 2:
			archivo = fopen("Libros.dat","rb");
			if(archivo == NULL)
				return -1;
			fread(&regLi, sizeof(struct Libro), 1, archivo);
			while(!feof(archivo))
			{
				if (reg != regLi.codigo)
				{
					fread(&regLi, sizeof(struct Libro), 1, archivo);
					continue;
				}
				else
				{
					if (regLi.cantidad > 1)
						return 0;
					else if (regLi.cantidad <= 0)
						return -1;
					else
						return 1;
				}
			}
			fclose(archivo);
			break;
		case 3:
			archivo = fopen("Estudiantes.dat","rb");
			if(archivo == NULL)
				return -1;
			fread(&regEs, sizeof(struct Estudiante), 1, archivo);
			while(!feof(archivo))
			{
				if (reg != regEs.matricula)
				{
					fread(&regEs, sizeof(struct Estudiante), 1, archivo);
					continue;
				}
				else
				{
					if(regEs.status <= 0)
						return -1;
					if(regEs.pendiente == 1)
						return 1;
					else
						return 0;
				}
			}
			fclose(archivo);
			break;
		case 4:
			archivo = fopen("Empleados.dat","rb");
			if(archivo == NULL)
				return 1;
			fread(&regEm, sizeof(struct Empleado), 1, archivo);
			while(!feof(archivo))
			{
				if (reg != regEm.idEmpleado)
				{
					fread(&regEm, sizeof(struct Empleado), 1, archivo);
					continue;
				}
				else
				{
					if(regEm.status <= 0)
						return -1;
					return 0;
				}
			}
			fclose(archivo);
			break;
		case 5:
			archivo = fopen("Prestamos.dat","rb");
			if(archivo == NULL)
				return 1;
			fread(&regPr, sizeof(struct Prestamo), 1, archivo);
			while(!feof(archivo))
			{
				if (reg != regPr.idPrestamo)
				{
					fread(&regPr, sizeof(struct Prestamo), 1, archivo);
					continue;
				}
				else
				{
					fclose(archivo);
					archivo = fopen("Libros.dat","rb");
					if (archivo == NULL)
						break;
					fread(&regLi, sizeof(struct Libro), 1, archivo);
					while(!feof(archivo))
					{
						if (regPr.codLibro == regLi.codigo)
						{
							break;
						}
						fread(&regLi, sizeof(struct Libro), 1, archivo);
					}
					fclose(archivo);
					archivo = fopen("Estudiantes.dat","rb");
					if (archivo == NULL)
						break;
					fread(&regEs, sizeof(struct Estudiante), 1, archivo);
					while(!feof(archivo))
					{
						if (regPr.matEst == regEs.matricula)
						{
							break;
						}
						fread(&regEs, sizeof(struct Estudiante), 1, archivo);
					}
					fclose(archivo);
					archivo = fopen("Empleados.dat","rb");
					if (archivo == NULL)
						break;
					fread(&regEm, sizeof(struct Empleado), 1, archivo);
					while(!feof(archivo))
					{
						if (regPr.idEmpleado == regEm.idEmpleado)
						{
							break;
						}
						fread(&regEm, sizeof(struct Empleado), 1, archivo);
					}
					fclose(archivo);
					if(regPr.status <= 0 || regLi.cantidad <= 0 || regEs.status <= 0 || regEm.status <= 0)
						return -1;
					return 0;
				}
			}
			fclose(archivo);
			break;
	}
	return -1;
}

int capturaRegistro(int * ent, int * modo) //Se utiliza para capturar las busquedas
{
	int reg;
	inicio:
	limpiarArea();
	do
	{
		frmBusqueda(*ent);
		switch(*ent)
		{
			case 2:
				gotoxy(31, 6);
				break;
			case 3:
				gotoxy(34, 6);
				break;
			case 4:
				gotoxy(36, 6);
				break;
			case 5:
				gotoxy(36, 6);
				break;
		}
		reg = nument(10, 5);
		if (reg == -1)
		{
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		if (buscarRegistro(*ent, reg) == -1)
		{
			getch();
			goto inicio;
		}
		getch();
		limpiarArea();
	}while(1);
}

int editarRegistro(int * ent, int * op, int * modo) //Edita un registro existente
{
	//Estas se usan para guardar la información consultada
	struct Libro LE;
	struct Estudiante EsE;
	struct Empleado EmE;
	struct Prestamo PE;
	do
	{
		limpiarArea();
		frmEdicion(*ent); //Dibuja el formulario
		switch(*ent)
		{
			case 2:
				cod:
				lib.codigo = NULL;
				memset(lib.nombre, '\0', 30);
				memset(lib.autor, '\0', 13);
				memset(lib.editorial, '\0', 13);
				memset(lib.fechaRegistro, '\0', 11);
				lib.cantidad = NULL;
				gotoxy(27, 8);
				printf("           ");
				gotoxy(27, 8);
				lib.codigo = nument(10, 2);
				if(lib.codigo == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if(validarRegistro(*ent, lib.codigo) == 0 || validarRegistro(*ent, lib.codigo) == 1)
				{
					mostrarCampos(*ent); //Esta función dibuja en pantalla, los campos del respectivo registro
					gotoxy(18, 23);
					printf("Deja vacio el campo que no desees editar.");
					archivo = fopen("Libros.dat","rb");
					if(archivo == NULL)
						return -1;
					fread(&LE, sizeof(struct Libro), 1, archivo);
					while(!feof(archivo))
					{
						if (lib.codigo != LE.codigo)
						{
							fread(&LE, sizeof(struct Libro), 1, archivo);
							continue;
						}
						else
						{
							break;
						}
					}
					fclose(archivo);
				}
				else
				{
					gotoxy(17, 23);
					printf("No existe un libro asociado con este c%cdigo...", 162);
					getch();
					gotoxy(17, 23);
					printf("                                               ");
					goto cod;
				}
				gotoxy(43, 8);
				if(valitext(29, &lib.nombre, 2) == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if (lib.nombre[0] == '\n')
				{
					gotoxy(43, 8);
					printf("%s", LE.nombre);
					strcpy(lib.nombre, LE.nombre);
				}
				gotoxy(44, 13);
				if(valitext(12, &lib.autor, 2) == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if (lib.autor[0] == '\n')
				{
					gotoxy(44, 13);
					printf("%s", LE.autor);
					strcpy(lib.autor, LE.autor);
				}
				gotoxy(60, 13);
				if(valitext(12, &lib.editorial, 2) == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if (lib.editorial[0] == '\n')
				{
					gotoxy(60, 13);
					printf("%s", LE.editorial);
					strcpy(lib.editorial, LE.editorial);
				}
				gotoxy(54, 17);
				if(valifec(&lib.fechaRegistro, 2) == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if(lib.fechaRegistro[0] == '\n')
				{
					gotoxy(54, 17);
					printf("%s", LE.fechaRegistro);
					strcpy(lib.fechaRegistro, LE.fechaRegistro);
				}
				gotoxy(54, 20);
				lib.cantidad = nument(2, 2);
				if(lib.cantidad == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if (lib.cantidad == NULL)
				{
					gotoxy(54, 20);
					printf("%i", LE.cantidad);
					lib.cantidad = LE.cantidad;
				}
				archivo = fopen("Libros.dat", "r+b"); //R + B significa lectura y escritura binaria (Ambas)
				fread(&LE, sizeof(struct Libro), 1, archivo);
			    while(!feof(archivo))
			    {
			        if (lib.codigo == LE.codigo)
			        {
			            int pos = ftell(archivo) - sizeof(struct Libro);
			            fseek(archivo, pos, SEEK_SET);
			            fwrite(&lib, sizeof(struct Libro), 1, archivo);
			            break;
			        }
			        fread(&LE, sizeof(struct Libro), 1, archivo);
			    }
			    fclose(archivo);
			    gotoxy(10, 23);
			    printf("             Se ha editado el libro con exito...         \b\b\b\b\b\b\b\b\b");
			    getch();
				break;
			case 3:				
				mat:
				est.matricula = NULL;
				memset(est.nombre, '\0', 12);
				memset(est.apellidoP, '\0', 12);
				memset(est.apellidoM, '\0', 12);
				memset(est.carrera, '\0', 40);
				est.pendiente = NULL;
				est.codLibro = NULL;
				est.status = NULL;
				gotoxy(35, 8);
				printf("          ");
				gotoxy(35, 8);
				est.matricula = nument(10, 2);
				if(est.matricula == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if(validarRegistro(*ent, est.matricula) == 0 || validarRegistro(*ent, est.matricula) == 1)
				{
					mostrarCampos(*ent);
					gotoxy(20, 23);
					printf("Deja vacio el campo que no desees editar.");
					archivo = fopen("Estudiantes.dat","rb");
					if(archivo == NULL)
						return -1;
					fread(&EsE, sizeof(struct Estudiante), 1, archivo);
					while(!feof(archivo))
					{
						if (est.matricula != EsE.matricula)
						{
							fread(&EsE, sizeof(struct Estudiante), 1, archivo);
							continue;
						}
						else
						{
							break;
						}
					}
					fclose(archivo);
				}
				else
				{
					gotoxy(13, 23);
					printf("No existe un estudiante asociado con esta matricula...");
					getch();
					gotoxy(13, 23);
					printf("                                                      ");
					goto mat;
				}
				gotoxy(50, 8);
				if(valitext(11, &est.nombre, 2) == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if (est.nombre[0] == '\n')
				{
					gotoxy(50, 8);
					printf("%s", EsE.nombre);
					strcpy(est.nombre, EsE.nombre);
				}
				gotoxy(43, 12);
				if(valitext(11, &est.apellidoP, 2) == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if (est.apellidoP[0] == '\n')
				{
					gotoxy(43, 12);
					printf("%s", EsE.apellidoP);
					strcpy(est.apellidoP, EsE.apellidoP);
				}
				gotoxy(43, 16);
				if(valitext(11, &est.apellidoM, 2) == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if (est.apellidoM[0] == '\n')
				{
					gotoxy(43, 16);
					printf("%s", EsE.apellidoM);
					strcpy(est.apellidoM, EsE.apellidoM);
				}
				gotoxy(34, 20);
				if(valitext(39, &est.carrera, 2) == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if (est.carrera[0] == '\n')
				{
					gotoxy(34, 20);
					printf("%s", EsE.carrera);
					strcpy(est.carrera, EsE.carrera);
				}
				archivo = fopen("Estudiantes.dat", "r+b");
				fread(&EsE, sizeof(struct Estudiante), 1, archivo);
			    while(!feof(archivo))
			    {
			        if (est.matricula == EsE.matricula)
			        {
			            int pos = ftell(archivo) - sizeof(struct Estudiante);
			            fseek(archivo, pos, SEEK_SET);
			            fwrite(&est, sizeof(struct Estudiante), 1, archivo);
			            break;
			        }
			        fread(&EsE, sizeof(struct Estudiante), 1, archivo);
			    }
			    fclose(archivo);
			    gotoxy(8, 23);
			    printf("             Se ha editado el estudiante con exito...         \b\b\b\b\b\b\b\b\b");
			    getch();
				break;
			case 4:
				ide:
				emp.idEmpleado = NULL;
				memset(emp.nombre, '\0', 12);
				memset(emp.apellidoP, '\0', 12);
				memset(emp.apellidoM, '\0', 12);
				emp.status = NULL;
				gotoxy(35, 8);
				printf("          ");
				gotoxy(35, 8);
				emp.idEmpleado = nument(10, 2);
				if(emp.idEmpleado == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if(validarRegistro(*ent, emp.idEmpleado) == 0)
				{
					mostrarCampos(*ent);
					gotoxy(20, 23);
					printf("Deja vacio el campo que no desees editar.");
					archivo = fopen("Empleados.dat","rb");
					if(archivo == NULL)
						return -1;
					fread(&EmE, sizeof(struct Empleado), 1, archivo);
					while(!feof(archivo))
					{
						if (emp.idEmpleado != EmE.idEmpleado)
						{
							fread(&EmE, sizeof(struct Empleado), 1, archivo);
							continue;
						}
						else
						{
							break;
						}
					}
					fclose(archivo);
				}
				else
				{
					gotoxy(17, 23);
					printf("No existe un empleado asociado con este ID...");
					getch();
					gotoxy(17, 23);
					printf("                                             ");
					goto ide;
				}
				gotoxy(50, 8);
				if(valitext(11, &emp.nombre, 2) == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if (emp.nombre[0] == '\n')
				{
					gotoxy(50, 8);
					printf("%s", EmE.nombre);
					strcpy(emp.nombre, EmE.nombre);
				}
				gotoxy(43, 12);
				if(valitext(11, &emp.apellidoP, 2) == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if (emp.apellidoP[0] == '\n')
				{
					gotoxy(43, 12);
					printf("%s", EmE.apellidoP);
					strcpy(emp.apellidoP, EmE.apellidoP);
				}
				gotoxy(43, 16);
				if(valitext(11, &emp.apellidoM, 2) == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if (emp.apellidoM[0] == '\n')
				{
					gotoxy(43, 16);
					printf("%s", EmE.apellidoM);
					strcpy(emp.apellidoM, EmE.apellidoM);
				}
				archivo = fopen("Empleados.dat", "r+b");
				fread(&EmE, sizeof(struct Empleado), 1, archivo);
			    while(!feof(archivo))
			    {
			        if (emp.idEmpleado == EmE.idEmpleado)
			        {
			            int pos = ftell(archivo) - sizeof(struct Empleado);
			            fseek(archivo, pos, SEEK_SET);
			            fwrite(&emp, sizeof(struct Empleado), 1, archivo);
			            break;
			        }
			        fread(&EmE, sizeof(struct Empleado), 1, archivo);
			    }
			    fclose(archivo);
			    gotoxy(8, 23);
			    printf("             Se ha editado el empleado con exito...         \b\b\b\b\b\b\b\b\b");
			    getch();
				break;
			case 5:
				idp:
				pre.idPrestamo = NULL;
				pre.codLibro = NULL;
				pre.matEst = NULL;
				pre.idEmpleado = NULL;
				memset(pre.fechaPrestamo, '\0', 11);
				memset(pre.fechaDevolucion, '\0', 11);
				pre.seDevolvio = NULL;
				pre.status = 1;
				gotoxy(36, 6);
				printf("      ");
				gotoxy(36, 6);
				pre.idPrestamo = nument(5, 2);
				if(pre.idPrestamo == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if(validarRegistro(*ent, pre.idPrestamo) == 0)
				{
					mostrarCampos(*ent);
					gotoxy(20, 23);
					printf("Deja vacio el campo que no desees editar.");
					archivo = fopen("Prestamos.dat","rb");
					if(archivo == NULL)
						return -1;
					fread(&PE, sizeof(struct Prestamo), 1, archivo);
					while(!feof(archivo))
					{
						if (pre.idPrestamo != PE.idPrestamo)
						{
							fread(&PE, sizeof(struct Prestamo), 1, archivo);
							continue;
						}
						else
						{
							break;
						}
					}
					fclose(archivo);
				}
				else
				{
					gotoxy(14, 23);
					printf("No existe un prestamo registrado con este ID...");
					getch();
					gotoxy(14, 23);
					printf("                                               ");
					goto idp;
				}
				codp:
				gotoxy(61, 6);
				printf("           ");
				gotoxy(61, 6);
				pre.codLibro = nument(10, 2);
				if(pre.codLibro == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if (pre.codLibro == NULL)
				{
					gotoxy(61, 6);
					printf("%i", PE.codLibro);
					pre.codLibro = PE.codLibro;
				}
				else
				{
					if(validarRegistro(2, pre.codLibro) == -1)
					{
						gotoxy(20, 23);
						printf("No existe el codigo de libro ingresado...");
						getch();
						gotoxy(20, 23);
						printf("                                         ");
						goto codp;
					}
					else if (validarRegistro(2, pre.codLibro) == 1)
					{
						gotoxy(12, 23);
						printf("Solo queda 1 Libro de este tipo, no se puede prestar...");
						getch();
						gotoxy(12, 23);
						printf("                                                       ");
						goto codp;
					}
				}
				matp:
				gotoxy(61, 9);
				printf("           ");
				gotoxy(61, 9);
				pre.matEst = nument(10, 2);
				if(pre.matEst == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if (pre.matEst == NULL)
				{
					gotoxy(61, 9);
					printf("%i", PE.matEst);
					pre.matEst = PE.matEst;
				}
				else
				{
					if(validarRegistro(3, pre.matEst) == -1)
					{
						gotoxy(15, 23);
						printf("No existe un estudiante asociado a esta matricula...");
						getch();
						gotoxy(15, 23);
						printf("                                                    ");
						goto matp;
					}
					else if (validarRegistro(3, pre.matEst) == 1)
					{
						gotoxy(20, 23);
						printf("Este estudiante a%cn debe un prestamo...", 163);
						getch();
						gotoxy(20, 23);
						printf("                                         ");
						goto matp;
					}
				}
				idep:
				gotoxy(61, 12);
				printf("           ");
				gotoxy(61, 12);
				pre.idEmpleado = nument(10, 2);
				if(pre.idEmpleado == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if (pre.idEmpleado == NULL)
				{
					gotoxy(61, 12);
					printf("%i", PE.idEmpleado);
					pre.idEmpleado = PE.idEmpleado;
				}
				else
				{
					if(validarRegistro(4, pre.idEmpleado) == -1 || validarRegistro(4, pre.idEmpleado) == 1)
					{
						gotoxy(20, 23);
						printf("No existe un empleado asociado con este ID...");
						getch();
						gotoxy(20, 23);
						printf("                                             ");
						goto idep;
					}
				}
				gotoxy(61, 17);
				if(valifec(&pre.fechaPrestamo, 2) == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if (pre.fechaPrestamo[0] == '\n')
				{
					gotoxy(61, 17);
					printf("%s", PE.fechaPrestamo);
					strcpy(pre.fechaPrestamo, PE.fechaPrestamo);
				}
				gotoxy(61, 20);
				if(valifec(&pre.fechaDevolucion, 2) == -1)
				{
					*op = 1;
					*modo = 0;
					*ent = 1;
					limpiarArea();
					return -1;
				}
				if(pre.fechaDevolucion[0] == '\n')
				{
					gotoxy(61, 20);
					printf("%s", PE.fechaDevolucion);
					strcpy(pre.fechaDevolucion, PE.fechaDevolucion);
				}
				pre.seDevolvio = 0;
				archivo = fopen("Prestamos.dat", "r+b");
				fread(&PE, sizeof(struct Prestamo), 1, archivo);
			    while(!feof(archivo))
			    {
			        if (pre.idPrestamo == PE.idPrestamo)
			        {
			            int pos = ftell(archivo) - sizeof(struct Prestamo);
			            fseek(archivo, pos, SEEK_SET);
			            fwrite(&pre, sizeof(struct Prestamo), 1, archivo);
			            break;
			        }
			        fread(&PE, sizeof(struct Prestamo), 1, archivo);
			    }
			    fclose(archivo);
			    //Acomodar Libros
			    if(pre.codLibro != PE.codLibro)
			    {
			    	archivo = fopen("Libros.dat", "r+b");
					fread(&LE, sizeof(struct Libro), 1, archivo);
				    while(!feof(archivo))
				    {
				        if (LE.codigo == PE.codLibro)
				        {
							LE.cantidad++;	        	
				            int pos = ftell(archivo) - sizeof(struct Libro);
				            fseek(archivo, pos, SEEK_SET);
				            fwrite(&LE, sizeof(struct Libro), 1, archivo);
				            break;
				        }
				        fread(&LE, sizeof(struct Libro), 1, archivo);
				    }
			    	fclose(archivo);
			    	archivo = fopen("Libros.dat", "r+b");
			    	rewind(archivo);
					fread(&LE, sizeof(struct Libro), 1, archivo);
				    while(!feof(archivo))
				    {
				        if(LE.codigo == pre.codLibro)
				        {
				        	LE.cantidad--;	        	
				            int pos = ftell(archivo) - sizeof(struct Libro);
				            fseek(archivo, pos, SEEK_SET);
				            fwrite(&LE, sizeof(struct Libro), 1, archivo);
				            break;
						}
						fread(&LE, sizeof(struct Libro), 1, archivo);
				    }
				    fclose(archivo);
				}
				//Restablecer Estudiantes
				if(pre.matEst != PE.matEst)
			    {
			    	archivo = fopen("Estudiantes.dat", "r+b");
					fread(&EsE, sizeof(struct Estudiante), 1, archivo);
				    while(!feof(archivo))
				    {
				        if (EsE.matricula == PE.matEst)
				        {
							EsE.pendiente = 0;	        	
				            int pos = ftell(archivo) - sizeof(struct Estudiante);
				            fseek(archivo, pos, SEEK_SET);
				            fwrite(&EsE, sizeof(struct Estudiante), 1, archivo);
				            break;
				        }
				        fread(&EsE, sizeof(struct Estudiante), 1, archivo);
				    }
			    	fclose(archivo);
			    	archivo = fopen("Estudiantes.dat", "r+b");
					fread(&EsE, sizeof(struct Estudiante), 1, archivo);
				    while(!feof(archivo))
				    {
				        if (EsE.matricula == pre.matEst)
				        {
							EsE.pendiente = 1;
				            int pos = ftell(archivo) - sizeof(struct Estudiante);
				            fseek(archivo, pos, SEEK_SET);
				            fwrite(&EsE, sizeof(struct Estudiante), 1, archivo);
				            break;
				        }
				        fread(&EsE, sizeof(struct Estudiante), 1, archivo);
				    }
				    fclose(archivo);
				}
				gotoxy(8, 23);
			    printf("             Se ha editado el prestamo con exito...         \b\b\b\b\b\b\b\b\b");
			    getch();
				break;
		}
	}while(1);
}

int eliminarRegistro(int * ent, int * modo) //Elimina un registro existente
{
	struct Libro LE;
	struct Estudiante EsE;
	struct Empleado EmE;
	struct Prestamo PE;
	int reg, opcion = 0, x;
	do
	{
		inicio: //Etiqueta
		limpiarArea();
		frmEliminacion(*ent);
		switch(*ent)
		{
			case 2:
				gotoxy(31, 6);
				break;
			case 3:
				gotoxy(34, 6);
				break;
			case 4:
				gotoxy(36, 6);
				break;
			case 5:
				gotoxy(36, 6);
				break;
		}
		reg = nument(10, 3);
		if (reg == -1)
		{
			*modo = 0;
			*ent = 1;
			limpiarArea();
			return -1;
		}
		if (buscarRegistro(*ent, reg) == -1)
		{
			getch();
			goto inicio;
		}
		mostrarDialogo();
		gotoxy(47, 20);
		printf("->");
		opcion = 1;
		input:
		switch(toupper(getch()))
		{
			case 'W':
				if(opcion != 1)
					opcion = 1;
				gotoxy(47, 22);
				printf("  ");
				gotoxy(47, 20);
				printf("->");
				goto input;
				break;
			case 'S':
				if(opcion != 0)
					opcion = 0;
				gotoxy(47, 20);
				printf("  ");
				gotoxy(47, 22);
				printf("->");
				goto input;
				break;
			case 13:
				if (opcion == 1)
				{
					switch(*ent)
					{
						case 2:
							archivo = fopen("Libros.dat", "r+b");
							rewind(archivo);
							fread(&LE, sizeof(struct Libro), 1, archivo);
							while(!feof(archivo))
							{
								if(LE.codigo == reg)
								{
									LE.cantidad = 0;
									int pos = ftell(archivo) - sizeof(struct Libro);
						            fseek(archivo, pos, SEEK_SET);
						            fwrite(&LE, sizeof(struct Libro), 1, archivo);
						            break;
								}
								fread(&LE, sizeof(struct Libro), 1, archivo);
							}
							fclose(archivo);
							break;
						case 3:
							archivo = fopen("Estudiantes.dat", "r+b");
							rewind(archivo);
							fread(&EsE, sizeof(struct Estudiante), 1, archivo);
							while(!feof(archivo))
							{
								if(EsE.matricula == reg)
								{
									EsE.status = 0;
									int pos = ftell(archivo) - sizeof(struct Estudiante);
						            fseek(archivo, pos, SEEK_SET);
						            fwrite(&EsE, sizeof(struct Estudiante), 1, archivo);
						            break;
								}
								fread(&EsE, sizeof(struct Estudiante), 1, archivo);
							}
							fclose(archivo);
							//Acomodar Libro
							archivo = fopen("Libros.dat", "r+b");
							rewind(archivo);
							fread(&LE, sizeof(struct Libro), 1, archivo);
							while(!feof(archivo))
							{
								if(EsE.codLibro == LE.codigo)
								{
									LE.cantidad++;
									int pos = ftell(archivo) - sizeof(struct Libro);
						            fseek(archivo, pos, SEEK_SET);
						            fwrite(&LE, sizeof(struct Libro), 1, archivo);
						            break;
								}
								fread(&LE, sizeof(struct Libro), 1, archivo);
							}
							fclose(archivo);
							break;
						case 4:
						{
							x = 0;
							archivo = fopen("Empleados.dat", "r+b");
							rewind(archivo);
							fread(&EmE, sizeof(struct Empleado), 1, archivo);
							while(!feof(archivo))
							{
								if(EmE.idEmpleado == reg)
								{
									EmE.status = 0;
									EmE.idEmpleado = 0;
									int pos = ftell(archivo) - sizeof(struct Empleado);
						            fseek(archivo, pos, SEEK_SET);
						            fwrite(&EmE, sizeof(struct Empleado), 1, archivo);
						            break;
								}
								fread(&EmE, sizeof(struct Empleado), 1, archivo);
							}
							//Acomodar IDs
							rewind(archivo);
							fread(&EmE, sizeof(struct Empleado), 1, archivo);
							while(!feof(archivo))
							{
								if(EmE.status > 0)
									x++;
								fread(&EmE, sizeof(struct Empleado), 1, archivo);
							}
							if(x > 0)
							{
								int vueltas = x;
								struct Empleado emps[vueltas];
								x = 0;
								rewind(archivo);
								do
								{
									fread(&EmE, sizeof(struct Empleado), 1, archivo);
									if(EmE.status > 0)
									{
										emps[x].idEmpleado = x + 1;
										strcpy(emps[x].nombre, EmE.nombre);
										strcpy(emps[x].apellidoP, EmE.apellidoP);
										strcpy(emps[x].apellidoM, EmE.apellidoM);
										emps[x].status = 1;
										x++;
									}
								}while(x < vueltas);
								fclose(archivo);
								archivo = fopen("Empleados.dat", "wb");
								fwrite(&emps, sizeof(struct Empleado), vueltas, archivo);
								fclose(archivo);
							}
						}break;
						case 5:
						{
							x = 0;
							archivo = fopen("Prestamos.dat", "r+b");
							rewind(archivo);
							fread(&PE, sizeof(struct Prestamo), 1, archivo);
							while(!feof(archivo))
							{
								if(PE.idPrestamo == reg)
								{
									PE.idPrestamo = 0;
									PE.status = 0;
									int pos = ftell(archivo) - sizeof(struct Prestamo);
						            fseek(archivo, pos, SEEK_SET);
						            fwrite(&PE, sizeof(struct Prestamo), 1, archivo);
						            break;
								}
								fread(&PE, sizeof(struct Prestamo), 1, archivo);
							}
							fclose(archivo);
							//Restablecer Estudiante
							archivo = fopen("Estudiantes.dat", "r+b");
							rewind(archivo);
							fread(&EsE, sizeof(struct Estudiante), 1, archivo);
							while(!feof(archivo))
							{
								if(EsE.matricula == PE.matEst)
								{
									EsE.pendiente = 0;
									EsE.codLibro = NULL;
									int pos = ftell(archivo) - sizeof(struct Estudiante);
						            fseek(archivo, pos, SEEK_SET);
						            fwrite(&EsE, sizeof(struct Estudiante), 1, archivo);
						            break;
								}
								fread(&EsE, sizeof(struct Estudiante), 1, archivo);
							}
							fclose(archivo);
							//Acomodar Libro
							archivo = fopen("Libros.dat", "r+b");
							rewind(archivo);
							fread(&LE, sizeof(struct Libro), 1, archivo);
							while(!feof(archivo))
							{
								if(LE.codigo == PE.codLibro)
								{
									LE.cantidad++;
									int pos = ftell(archivo) - sizeof(struct Libro);
						            fseek(archivo, pos, SEEK_SET);
						            fwrite(&LE, sizeof(struct Libro), 1, archivo);
						            break;
								}
								fread(&LE, sizeof(struct Libro), 1, archivo);
							}
							fclose(archivo);
							//Acomodar IDs
							archivo = fopen("Prestamos.dat", "r+b");
							rewind(archivo);
							fread(&PE, sizeof(struct Prestamo), 1, archivo);
							while(!feof(archivo))
							{
								if(PE.status > 0)
									x++;
								fread(&PE, sizeof(struct Prestamo), 1, archivo);
							}
							if(x > 0)
							{
								int vueltas = x;
								struct Prestamo pres[vueltas];
								x = 0;
								rewind(archivo);
								do
								{
									fread(&PE, sizeof(struct Prestamo), 1, archivo);
									if(PE.status > 0)
									{
										pres[x].idPrestamo = x + 1;
										pres[x].codLibro = PE.codLibro;
										pres[x].matEst = PE.matEst;
										pres[x].idEmpleado = PE.idEmpleado;
										strcpy(pres[x].fechaPrestamo, PE.fechaPrestamo);
										strcpy(pres[x].fechaDevolucion, PE.fechaDevolucion);
										pres[x].seDevolvio = PE.seDevolvio;
										pres[x].status = 1;
										x++;
									}
								}while(x < vueltas);
								fclose(archivo);
								archivo = fopen("Prestamos.dat", "wb");
								fwrite(&pres, sizeof(struct Prestamo), vueltas, archivo);
								fclose(archivo);
							}
						}break;
					}
					gotoxy(27, 16);
					printf("%c------------------------------------------%c", 218, 191);
					gotoxy(27, 17);
					printf("|                                          |");
					gotoxy(27, 18);
					printf("|                                          |");
					gotoxy(27, 19);
				    printf("|  Se ha eliminado el registro con exito.  |");
					gotoxy(27, 20);
					printf("|                                          |");
					gotoxy(27, 21);
					printf("|                                          |");
					gotoxy(27, 22);
					printf("|                                          |");
					gotoxy(27, 23);
					printf("%c------------------------------------------%c", 192, 217);
					getch();
				}
				break;
		}
	}while(1);
}
