/*
	Universidad Autonoma de Aguascalientes
	ciencias de la computacion
	Ingenieria en Computacion Inteligentes Semestre 5
	Optimizacion Inteligente 
	Alumnos: 
		Omar Villalobos Rodriguez ID: 315374
	Profesor:
		LUIS FERNANDO GUTIERREZ MARFILEÑO
	Este programa utiliza el Recocido simulado para el problema del agente viajero
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

//Struct para ciudades
struct Ciudades {
	//Posiciones X, Y
	int x;
	int y;
};

//Funcion que calcula la distancia entre las cuidades 
double calcularDistancia(struct Ciudades  ciudad1, struct Ciudades  ciudad2) {
	//Funcion para Calcular las Distancias por pitagoras
	double Distancia = sqrt(pow(ciudad1.x - ciudad2.x, 2) + pow(ciudad1.y - ciudad2.y, 2));
	//Regresa la Hipotenusa 
    return Distancia;
}

//Funcion que calcula el recorrido final 
double calcularRecorrido(struct Ciudades  ciudades[], int recorrido[],int Num_ciudades) {
	//Calcula la distancia total de todo el recorrido 
    double distanciaTotal = 0;
    //Calculas de la primera a la ultima
    for (int i = 0; i < Num_ciudades-1; i++) {
        distanciaTotal += calcularDistancia(ciudades[recorrido[i]], ciudades[recorrido[i + 1]]);
    }
    //Calcula de la ultima a la primera (Regreso)
    distanciaTotal += calcularDistancia(ciudades[recorrido[Num_ciudades - 1]], ciudades[recorrido[0]]);
    return distanciaTotal;
}

//Funcion Main()
int main(){
	
	//Varibales Gobales de Control
	double Temp_Ini = 0, Temp_Final = 0, Fact_Enfriamiento = 0, Max_Iteraciones = 0, op;
	int Num_ciudades, ejemplo;
	
	do{
		system("cls");
		cout<<"Este programa utiliza el Metodo Recocido Simulado para resolver el Problema del Agente Viajero empezando en la primera ciudad y terminando en la primera"<<endl<<endl;
		cout<<"Quieres agregar Un Numero de Ciudades y sus posiciones: "<<endl;
		cout<<"1)Si"<<endl;
		cout<<"2)No Usar el Ejemplo"<<endl;
		cout<<"Elige una opcion: ";
		cin>>ejemplo;
		
		if(ejemplo == 2){
			Num_ciudades = 25;
		}
		else{
			cout<<endl<<"Dame el numero de cuidades: ";
			cin>>Num_ciudades;
		}
		
		//Crear el Struct de Cuidades
		struct Ciudades Ciudad[Num_ciudades];
		
		if(ejemplo == 2){
			//Coordenadas de ejemplo
			//Ciudad 0
			Ciudad[0].x = 5;
			Ciudad[0].y = 4;
			//Ciudad 1
			Ciudad[1].x = 7;
			Ciudad[1].y = 4;
			//Ciudad 2
			Ciudad[2].x = 5;
			Ciudad[2].y = 6;
			//Ciudad 3
			Ciudad[3].x = 4;
			Ciudad[3].y = 3;
			//Ciudad 4
			Ciudad[4].x = 3;
			Ciudad[4].y = 6;
			//Ciudad 5
			Ciudad[5].x = 4;
			Ciudad[5].y = 5;
			//Ciudad 6
			Ciudad[6].x = 2;
			Ciudad[6].y = 4;
			//Ciudad 7
			Ciudad[7].x = 1;
			Ciudad[7].y = 3;
			//Ciudad 8
			Ciudad[8].x = 1;
			Ciudad[8].y = 5;
			//Ciudad 9
			Ciudad[9].x = 3;
			Ciudad[9].y = 2;
			//Ciudad 10
			Ciudad[10].x = 6;
			Ciudad[10].y = 3;
			//Ciudad 11
			Ciudad[11].x = 7;
			Ciudad[11].y = 7;
			//Ciudad 12
			Ciudad[12].x = 6;
			Ciudad[12].y = 1;
			//Ciudad 13
			Ciudad[13].x = 4;
			Ciudad[13].y = 1;
			//Ciudad 14
			Ciudad[14].x = 1;
			Ciudad[14].y = 1;
			//Ciudad 15
			Ciudad[15].x = 1;
			Ciudad[15].y = 7;
			//Ciudad 16
			Ciudad[16].x = 4;
			Ciudad[16].y = 7;
			//Ciudad 17
			Ciudad[17].x = 7;
			Ciudad[17].y = 2;
			//Ciudad 18
			Ciudad[18].x = 9;
			Ciudad[18].y = 2;
			//Ciudad 19
			Ciudad[19].x = 8;
			Ciudad[19].y = 5;
			//Ciudad 20
			Ciudad[20].x = 10;
			Ciudad[20].y = 4;
			//Ciudad 21
			Ciudad[21].x = 11;
			Ciudad[21].y = 1;
			//Ciudad 22
			Ciudad[22].x = 10;
			Ciudad[22].y = 7;
			//Ciudad 23
			Ciudad[23].x = 13;
			Ciudad[23].y = 6;
			//Ciudad 24
			Ciudad[24].x = 12;
			Ciudad[24].y = 8;
		}
		else{
			//Pedir posiciones de las cuidades
			for(int i=0; i<Num_ciudades; i++){
				cout<<"Dame la posicion x de la cuidad "<<i<<": ";
				cin>>Ciudad[i].x;
				cout<<"Dame la posicion y de la cuidad "<<i<<": ";
				cin>>Ciudad[i].y;
				cout<<endl;
			}
		}
	
		//Pedida de datos
    	system("cls");
    	cout<<"Dame el numero de iteraciones maximas: ";
		cin>> Max_Iteraciones;
		cout<<"Dame la Temperatura Inicial: ";
		cin>> Temp_Ini;
		cout<<"Dame la Temperatura final: ";
		cin>> Temp_Final;
		cout<<"Dame el Factor de Enfriamiento: ";
		cin>>Fact_Enfriamiento;
    	
		//Variables
		int recorridoActual[Num_ciudades];
	    int recorridoMejor[Num_ciudades];
	    double temperatura = Temp_Ini;
	    double distanciaActual, distanciaMejor;
	    int iteraciones = 0;
    
	    //Randoms
	    srand(time(NULL));
	    
	     // Generar una solucion inicial 
	    for (int i = 0; i < Num_ciudades; i++) {
	        recorridoActual[i] = i;
	    }
	    //Ordenarlo de forma Aleatoria sin modificar el inicio en la cuidad 0
	    for (int i = 1; i < Num_ciudades; i++) {
	    	int j;
			do{
	        	j = rand() % Num_ciudades;
			}while(j==0);
	        int temp = recorridoActual[i];
	        recorridoActual[i] = recorridoActual[j];
	        recorridoActual[j] = temp;
	    }
	    
	    //Guardar la distancia del aleatorio como mejor y guardamos el recorido
	    distanciaActual = calcularRecorrido(Ciudad, recorridoActual, Num_ciudades);
	    distanciaMejor = distanciaActual;
		//De momento es la solucion mejor
	    for (int i = 0; i < Num_ciudades; i++) {
	        recorridoMejor[i] = recorridoActual[i];
	    }
	
		//Bucle Para soluciones hasta acabar las iteraciones o llegar a la temperatura
	    while (temperatura > Temp_Final && iteraciones < Max_Iteraciones) {
			//Buscar Randoms sin modificar la cuidad 0
			int i;
	        int j;
			do{
				i = rand() % Num_ciudades;
	        	j = rand() % Num_ciudades;
			}while(i==0||j==0);
			
			//Intercambio 
	        int temp = recorridoActual[i];
	        recorridoActual[i] = recorridoActual[j];
	        recorridoActual[j] = temp;
			
			//Calculas la distancia del recorrido 
	        double nuevaDistancia = calcularRecorrido(Ciudad, recorridoActual,Num_ciudades);
	        double deltaDistancia = nuevaDistancia - distanciaActual;
		
			//Probabilidad para aceptar malas soluciones para salir de optimos locales 
	        if (deltaDistancia < 0 || ((double)rand() / RAND_MAX) < exp(-deltaDistancia / temperatura)) {
	            distanciaActual = nuevaDistancia;
	            //Mejor Solucion Actual
	            if (distanciaActual < distanciaMejor) {
	                distanciaMejor = distanciaActual;
	                for (int i = 0; i < Num_ciudades; i++) {
	                    recorridoMejor[i] = recorridoActual[i];
	                }
					cout<<"Mejor solucion Actual en la iteracion: "<<iteraciones<<" Distancia Recorrida: "<<distanciaMejor<<endl;
	            }
	    	//Si no funciona el cambio como mejor lo regreso a como estaba para buscar otro
	        } else {
	            // Deshacer el intercambio
	            temp = recorridoActual[i];
	            recorridoActual[i] = recorridoActual[j];
	            recorridoActual[j] = temp;
	        }
	        //Calcular la temperatura 
	        temperatura = Fact_Enfriamiento*(Temp_Ini/(1+iteraciones));
	        iteraciones++;
		}
		cout<<"Iteracion Maxima: "<<iteraciones<<endl;
		//Resultados
		cout<<"El Mejor recorrido encontrado es: "<<endl;
		for (int i=0;i<Num_ciudades;i++) {
		    cout<<recorridoMejor[i]<<" -> ";
		}
		cout<<"0 "<<endl;
		cout<<endl<<"Distancia Total: "<<distanciaMejor<<endl;
		//Menu de Regreso o salida
		cout<<"Regresar al Inicio:"<<endl;
		cout<<"1)Si"<<endl;
		cout<<"2)No"<<endl;
		cin>>op;
	}while(op!=2);

	return 0;
}
