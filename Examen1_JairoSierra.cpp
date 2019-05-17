#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>//Input
using std:: string;
using std:: to_string;
#include <stdio.h>
//Provisionar la matriz de chars para el juego
char** provisionarMatriz(int);
//liberar memoria de la matriz
void liberarMatriz(char**&,int);
//imprimir la matriz
void printMatrix(char**,int);
//Llenado de la matrix
void llenado(char**);
int menu();
void Ejercicio1(char**);
//metodo para imprimir la matrix
void imprimeMatriz(char**,int,int);
//metodo para verificar las piezas
bool piezas(char**,int,int,int);
//metodo de los atacantes
bool atacantes(char**);
//metodo de los defensores
bool defensores(char**);
//metodo de comer las piezas
char** comer(char**);
int main(){
int opcion = 0;
        do{
           char** matrix=NULL;
        switch(opcion=menu()){
                case 1:
                   //inicializar matriz n x n
                   matrix=provisionarMatriz(11);
		   //LLamada del metodo que realiza todas las funciones del juego
		   Ejercicio1(matrix);
		   //Libera la matriz
		   liberarMatriz(matrix,11);
                break;

                      case 2:
                           cout<<"El programa se cerrara"<<endl;
                       break;
        }
}while(opcion!=2);
}
int menu(){
        while(true){
        //cout<<"MENU"<<endl;
        //mostrar tres opciones
        //1.- Ejercicio 1
        //2.- salir
        cout<<"MENU"<<endl
        <<"1.- Ejercico 1"<<endl
        <<"2.- Salir"<<endl;
        //pedir al usuario una opcion
        cout<<"Ingrese una opcion: ";
        int opcion =0;
        //leer la opcion
        cin>>opcion;
        //validar la opcion
        if(opcion>=1 && opcion<= 2){
                //si es valido retornar
                return opcion;
          }
          else{

        //else mostrar mensaje de error al usuario
        cout<<"La opcion elegida no es valida, ingrese un valor entre 1 y 4"<<endl;
  }
  }//end del while
        return 0;
  }
char** provisionarMatriz(int size){
   char** matrix = NULL;
   matrix = new char*[size];
   for(int i=0;i<size;i++){
      matrix[i]=new char[size];
   }
   return matrix;
}
void liberarMatriz(char**& matrix,int size){
   for(int i=0;i<size;i++){
    if(matrix[i] != NULL){
     delete[] matrix[i];
     matrix[i]=NULL;
    }
  }
  if(matrix != NULL){
    delete[] matrix;
    matrix = NULL;
  }

}
void printMatrix(char** matrix,int size){
    for(int i=0;i<size;i++){
     for(int j=0;j<size;j++){
        cout<<"["<<matrix[i][j]<<"]  ";
     }
     cout<<endl;
  }

}
void llenado(char** matrix){
for (int i = 3; i < 8; i++) {
            matrix[0][i] = '#';
            matrix[10][i] = '#';
            matrix[i][0] = '#';
            matrix[i][10] = '#';
        }
        matrix[1][5] = '#';
        matrix[9][5] = '#';
        matrix[5][1] = '#';
        matrix[5][9] = '#';
        matrix[0][0] = '@';
        matrix[10][0] = '@';
        matrix[0][10] = '@';
        matrix[10][10] = '@';
        for (int i = 2; i < 9; i++) {
            matrix[i][5] = '0';
            matrix[5][i] = '0';
        }
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                if (matrix[i][j] != '0' && matrix[i][j] != '#') {
                    matrix[i][j] = ' ';
                }
            }
        }
	matrix[0][7]=' ';
	matrix[0][3]=' ';
	matrix[1][5]=' ';
	matrix[1][4]='#';
	matrix[1][6]='#';
	matrix[3][0]=' ';
	matrix[7][0]=' ';
	matrix[5][1]=' ';
	matrix[4][1]='#';
	matrix[6][1]='#';
	matrix[10][3]=' ';
	matrix[10][7]=' ';
	matrix[9][5]=' ';
	matrix[9][4]='#';
	matrix[9][6]='#';
	matrix[3][10]=' ';
	matrix[6][10]=' ';
	matrix[5][9]=' ';
	matrix[4][9]='#';
	matrix[6][9]='#';
        matrix[5][5] = 'W';
        matrix[0][0] = 'X';
        matrix[10][0] = 'X';
        matrix[0][10] = 'X';
        matrix[10][10] = 'X';
        matrix[2][5] = ' ';
        matrix[5][2] = ' ';
        matrix[8][5] = ' ';
        matrix[5][8] = ' ';
        matrix[4][4] = '0';
        matrix[4][6] = '0';
        matrix[6][4] = '0';
        matrix[6][6] = '0';
	matrix[2][5]='#';
	matrix[5][2]='#';
	matrix[5][8]='#';
	matrix[8][5]='#';
}
void Ejercicio1(char** matrix)
{ 
     //Se llena la matriz
     llenado(matrix);
     //Se imprime la matriz
     printMatrix(matrix,11);
     //Trunos
     for (int i = 0; i < 999999999; i++){ //turnos probables
            if (i % 2 == 0) {//Menciona a quien le toca mover en el turno
               cout<<"Jugador 1= Mascovitas"<<endl;
            } else {
                cout<<"Jugador 2= Suecos"<<endl;
            }//fin del if de los turnos
            cout<<"Escoja la pieza que va a mover."<<endl;//Se obtienen x y y para saber que pieza se movera
            cout<<"Ingrese la coordenada x: "<<endl;
	    string cadena=" ";
	    cin>>cadena;
	    string cadena1=" "; 
	    cadena1 = cadena.substr(0,1);
	    string  cadena2 = " ";
	    cadena2 = cadena.substr(2,3);
	    int x=0,y=0;
	    //Se valida el valor del x
	   if(cadena1=="A"||cadena1=="a"){
	     x=0;
	   }
	   if(cadena1=="B"|| cadena1=="b"){
	     x=1;
	   }
	   if(cadena1=="C"||cadena1=="c"){
	     x=2; 
	   }
	   if(cadena1=="D"||cadena1=="d"){
	     x=3;
	   }
	   if(cadena1=="E"||cadena1=="e"){
	     x=4;
	   }
	   if(cadena1=="F"||cadena1=="f"){
	     x=5;
	   }
	   if(cadena1=="G"||cadena1=="g"){
	     x=6;
	   }
	   if(cadena1=="H"||cadena1=="h"){
	     x=7;
	   }
           if(cadena1=="I"||cadena1=="i"){
	     x=8;
	   }
	   if(cadena1=="J"||cadena1=="j"){
	     x=9;
	   }
	   if(cadena1=="K"||cadena1=="k"){
	     x=10;
	   }
	   //Se calcula el valor de y
	   y=0;
	   y=(int)cadena2[0]-48;
	   //While que valida de x y y esten en el tamaño de la matriz
	   while (x >= 11 || x < 0 || y>=11 || y<0) {
		cout<<"Escoja la pieza que va a mover."<<endl;//Se obtienen x y y para saber que pieza se movera
            	cout<<"Ingrese la coordenada x: "<<endl;
            	string cadena=" ";
            	cin>>cadena;
                string cadena1=" ";
            	cadena1 = cadena.substr(0,1);
            	string  cadena2 = " ";
            	cadena2 = cadena.substr(2,3);
            	int x=0,y=0;
           	if(cadena1=="A"||cadena1=="a"){
             		x=0;
           	}	
           	if(cadena1=="B"|| cadena1=="b"){
             		x=1;
           	}
           	if(cadena1=="C"||cadena1=="c"){
             		x=2;
           	}
           	if(cadena1=="D"||cadena1=="d"){
             		x=3;
           	}
           	if(cadena1=="E"||cadena1=="e"){
             		x=4;
           	}
           	if(cadena1=="F"||cadena1=="f"){
             		x=5;
           	}
	   	if(cadena1=="G"||cadena1=="g"){
             		x=6;
           	}
           	if(cadena1=="H"||cadena1=="h"){
             		x=7;
           	}
           	if(cadena1=="I"||cadena1=="i"){
             		x=8;
           	}
           	if(cadena1=="J"||cadena1=="j"){
             		x=9;
           	}
           	if(cadena1=="K"||cadena1=="k"){
             		x=10;
           	}
           	y=0;
           	y=(int)cadena2[0]-48;
	   }//fin del while de comprobrar las primeras coordenadas
	   if (piezas(matrix, x, y, i)) {//verifica si la pieza seleccionada es correcta al turno del jugador
                	bool flag = true;
                while (flag) {
                   cout<<"Ingrese las coordenadas a las que desea mover la ficha. "<<endl;//Se obtienen las nuevas coordenadas a las que se movera la pieza
		   string cadena3= " ";
		   int movx=0,movy=0;
                   cout<<"Ingrese la coordenada: "<<endl;
                   cin>>cadena3;
		   string cadena4=" ";
                   cadena4 = cadena3.substr(0,1);
                   string  cadena5 = " ";
                   cadena5 = cadena3.substr(2,3);
         	 if(cadena4=="A"||cadena4=="a"){
             		movx=0;
           	}
           	if(cadena4=="B"||cadena4=="b"){
             		movx=1;
           	}
           	if(cadena4=="C"||cadena4=="c"){
             		movx=2;
          	 }	
           	if(cadena4=="D"||cadena4=="d"){
             		movx=3;
           	}
           	if(cadena4=="E"||cadena4=="e"){
             		movx=4;
           	}
           	if(cadena4=="F"||cadena4=="f"){
             		movx=5;
           	}
           	if(cadena4=="G"||cadena4=="g"){
             		movx=6;
           	}
           	if(cadena4=="H"||cadena4=="h"){
             		movx=7;
           	}
           	if(cadena4=="I"||cadena4=="i"){
            		movx=8;
           	}
           	if(cadena4=="J"||cadena4=="j"){
             		movx=9;
           	}
           	if(cadena4=="K"||cadena4=="k"){
             		movx=10;
           	}
	   	movy = (int)cadena5[0]-48;
                    while (movx >= 11 || movx < 0 || movy>=11 || movy<0) {
			 	cout<<"Valores incorrecto"<<endl;
                       	 	cout<<"Ingrese las coordenadas a las que desea mover la ficha. "<<endl;//Se obtienen las nuevas coordenadas a las que se movera la pieza
                   		string cadena3= " ";
                   		int movx=0,movy=0;
                    		cout<<"Ingrese la coordenada: "<<endl;
                    		cin>>cadena3;
                    		string cadena1=" ";
                    		cadena1 = cadena3.substr(0,1);
                     		string  cadena2 = " ";
                    		cadena2 = cadena3.substr(2,3);
          		if(cadena1=="A"||cadena1=="a"){
             			movx=0;
           		}
           		if(cadena1=="B"||cadena1=="b"){
            			 movx=1;
           		}
           		if(cadena1=="C"||cadena1=="c"){
             			movx=2;
           		}
           		if(cadena1=="D"||cadena1=="d"){
             			movx=3;
           		}
           		if(cadena1=="E"||cadena1=="e"){
             			movx=4;
           		}
           		if(cadena1=="F"||cadena1=="f"){
             			movx=5;
           		}
           		if(cadena1=="G"||cadena1=="g"){
             			movx=6;
           		}
	   		if(cadena1=="H"||cadena1=="h"){
             			movx=7;
           		}
           		if(cadena1=="I"||cadena1=="i"){
            			movx=8;
           		}
           		if(cadena1=="J"||cadena1=="j"){
             			movx=9;
           		}
           		if(cadena1=="K"||cadena1=="k"){
             			movx=10;
           		}
           		movy = (int)cadena2[0];
                    }//fin del movimiento en la coordenada x
                    if (matrix[movx][movy] == ' ' && (movx == x || movy == y)) {//coloca la pieza en las coordenadas que indica el usuario
                        if (i % 2 == 0) {
                            matrix[movx][movy] = '#';
                        } else {
                            if (matrix[x][y] == 'W') {
                                matrix[movx][movy] = 'W';
                            } else {
                                matrix[movx][movy] = '0';
                            }
                        }
                        matrix[x][y] = ' ';
                        matrix = comer(matrix);//revisa la matriz para verificar si se pueden eliminar piezas
                        imprimeMatriz(matrix, 0, 0);
                        cout<<endl;
                        flag = false;
                    }//fin del if que coloca las piezas en las coordenadas ingresadas
                    else {
                        flag = true;
                    }
                }
            }//fin del if que verifica si se puede mover la pieza
            else {
                i = i - 1;
            }
            if (defensores(matrix) || atacantes(matrix)) {//Verifica si hay un ganador
                if (i % 2 == 0) {//Menciona que jugador gano
                    cout<<"Gana el juego los Moscovitas! Felicidades!!!"<<endl;
                } else {
                    cout<<"Gana el juego los Suecos! Felicidades!!!"<<endl;
                }
                break;
            }//fin del if que menciona al ganador
        }//fin del for de los movimientos
}
void imprimeMatriz(char** matriz, int filas, int cols) {//Imprime la matriz de manera recursiva
        if (filas == 10 && cols == 10) {
            cout<<"["<< matriz[filas][cols]<< "]   ";
        } else {
            if (cols == 10) {
                cout<<"["<< matriz[filas][cols]<< "]"<<endl;
                imprimeMatriz(matriz, filas + 1, 0);
            } else {
                 cout<<"["<< matriz[filas][cols]<<"]   ";
                imprimeMatriz(matriz, filas, cols + 1);
            }
        }
    }//fin del metodo que imprime la matriz recursivamente
bool piezas(char** t, int x, int y, int turno) {//verifica si se puede usar la pieza a mover 
        if (turno % 2 == 0) {
            if (t[x][y] == '#') {
                return true;
            } else {
                return false;
            }
        } else {
            if (t[x][y] == '0' || t[x][y] == 'W') {
                return true;
            } else {
                return false;
            }
        }
    }
bool atacantes(char** t) {//valida si gana atacante al eliminar a el rey
        int cont = 0;
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                if (t[i][j] == 'W') {
                    cont++;
                }
            }
        }
        if (cont != 0) {
            return false;
        } else {
            return true;
        }
    }//fin del metodo cuando ganan los atacantes al comerse al rey
bool defensores(char** t) {//verifica si gana defensores si el rey llega a algun borde
        for (int i = 0; i < 11; i++) {
            if (t[i][10] == 'W') {
                return true;
            }
            if (t[i][0] == 'W') {
                return true;
            }
            if (t[0][i] == 'W') {
                return true;
            }
            if (t[10][i] == 'W') {
                return true;
            }
        }
        return false;
    }//Fin del metodo que verifica si los defensores ganan
char** comer(char** t) {//elimina las piezas que esten entre dos fichas contrarias
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 11; j++) {
               if (t[i - 1][j] == t[i + 1][j] && t[i][j] != t[i - 1][j] && t[i][j] != ' ' && t[i - 1][j] != ' ' && t[i][j] != 'W') {
                    t[i][j] = ' ';
                }
            }
        }
        for (int i = 0; i < 11; i++) {
            for (int j = 1; j < 10; j++) {
                if (t[i][j - 1] == t[i][j + 1] && t[i][j] != t[i][j - 1] && t[i][j] != ' ' && t[i][j + 1] != ' ' && t[i][j] != 'W') {
                    t[i][j] = ' ';
                }
            }
        }
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 11; j++) {
                if (t[i - 1][j] == t[i + 1][j] && t[i - 1][j] == '#' && t[i][j] == 'W') {
                    t[i][j] = ' ';
                }
            }
        }
        for (int i = 0; i < 11; i++) {
            for (int j = 1; j <10; j++) {
                if (t[i][j - 1] == t[i][j + 1] && t[i][j - 1] == '#' && t[i][j] == 'W') {
                    t[i][j] = ' ';
                }
            }
        }
        return t;
    }//fin del metodo que elimina las piezas que esten en medio de los atacantes
