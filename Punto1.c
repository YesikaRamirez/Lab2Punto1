/* Integrantes: Ashley Paola Romero Restrepo, Yesika Biviana Ramirez Duran*/
/* Alse grupo 5*/
/* Profesor: MARCO ANDRES ORTIZ NIÑO*/
/* Laboratorio 2 parte 1*/

/*Dados dos puntos ingresados por el usuario,encuentre la ecuación de la recta.
 El programa debe mostrar el siguiente menú(o similar)para que el usuario
 seleccione la opción deseaday muestre el resultado correspondiente.*/
 
 
 
# include <stdio.h>

typedef struct punto{
	float x ;
	float y ;
	
}punto;



void Ingresar(punto *p1, punto *p2);
void Pendiente1();
void Cruce();
void EcuacionR();

int main(void) //menu principal
{
	int opc;
	punto p1, p2, result;
	result.x = 0;
	result.y = 0;
	p1.x = 0;
	p1.y = 0;
	p2.x = 0;
	p2.y = 0;
	
	
	
	do
	{	
	
		printf(" \n Menu Principal\n");
		printf(" 1- Ingresar puntos \n");
		printf(" 2- Mostrar pendiente \n");
		printf(" 3- Mostrar cruce con el eje Y \n");
		printf(" 4- Mostrar ecuación de la recta \n");
		printf(" 5- salir \n");
		
		do
			{
			printf(" ¿Que opcion deseas escoger?\n");
			scanf("%d",&opc);
			
			} 
			
		while (opc< 1 || opc> 5);  /* || es o , solo puede ser entre 1 y 5*/
	
		switch(opc)
		{
			case 1 :
					Ingresar(&p1, &p2);
					break;
					 
			case 2 : 
					Pendiente1(&p1, &p2, &result);
					break;
					 
					   
			case 3 :
					Cruce(&p1, &p2, &result);
					break;
					 
			case 4 :
					EcuacionR(&p1, &p2, &result);
					break;
		
		}
	
		}while (opc != 5); // no sea igual a 5
	
	
	return 0;
}

// DEFINICION DE PUNTOS//

// INGRESAR PUNTOS//

void Ingresar(punto *p1, punto *p2)
{		
	printf("\nIngresar Puntos \n");
	printf("\nIngresa los valores del punto 1\n");   
	printf("valor de x1\n");
	scanf("%f",&(p1->x));
	printf("valor de y1\n");
	scanf("%f",&(p1->y));
	printf("\nIngresa los valores del punto 2\n");
	printf("valor de x2\n");
	scanf("%f",&(p2->x));
	printf("valor de y2\n");
	scanf("%f",&(p2->y));	
	
	printf ("primer punto(%.2f,%.2f)\n",p1->x,p1->y);
	printf ("primer punto(%.2f,%.2f)\n",p2->x,p2->y);
}

//PendienteR//

void Pendiente1(punto *p1, punto *p2, punto *res)

{
	float m = 0;

	(*res).x = p2->x - p1->x;
	(*res).y = p2->y - p1->y;
	
	m = res-> y/ res-> x; 

	printf(" Mostrar pendiente \n\n");
							 
	if (res-> x == 0)
		{printf("\nLa pendiente no existe , por que la recta es vertical.\n\n");}
		else 
			if (res-> y == 0 )
				{printf("\nLa pendiente es 0 , por que la recta es Horizontal.\n\n");}					
				else
					if (m < 0)
					{printf("\nLa pendiente es %.2f y es decreciente.\n\n",m);}
					if (m > 0)
					{printf("\nLa pendiente es %.2f y es creciente.\n\n",m);}
						
}
// INTERSECCION DE LA RECTA CON EL EJE Y//

void Cruce(punto *p1, punto *p2, punto *res)
{
	float m;
	float cruce;
	
	(*res).x = p2->x - p1->x;
	(*res).y = p2->y - p1->y;
	m = res-> y/ res-> x; 
	cruce = ((((m*p1->x) - p1->y)/m));
	if (res-> x == 0)
		{printf("\nEl punto de corte no existe , por que la recta es vertical.\n");}
		else 
			if (res-> y ==0)
				{printf("\nEl punto de corte es %.2f , y la recta es Horizontal.\n",p2->y);}
		else
		{printf("\nEl punto de interseccion con el eje Y es (%.2f,0)\n\n",cruce);}
}


//Mostrar ecuacion//

void EcuacionR(punto *p1, punto *p2, punto *res)
{
	float inter;
	float m;
	
	(*res).x = p2->x - p1->x;
	(*res).y = p2->y - p1->y;
	m = res-> y/ res-> x;
	inter = -1*(p1->x * m) + p1->y;
	
	if (res-> x == 0)
		{printf("\nLa ecuacion de la recta es X=%.2f\n",p1->x);}
		else 
			if (res-> y ==0)
				{printf("\nLa ecuacion de la recta es y=%.2f\n",p1->y);}
		else
		{printf("La ecuación de la recta es Y= %.2fX  %.2f\n\n",m, inter);
		}
}
