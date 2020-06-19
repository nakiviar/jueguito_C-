# include <conio.h> 
# include <iostream>
#include <windows.h> 

using namespace std;

#define  ESPACIOS_H 75
#define  ESPACIOS_V 23
#define  ARRIBA 72
#define  ABAJO 80 
#define  IZQUIERDA 75
#define  DERECHA 77   
void pintarAvion_H(int x,int y );
void pintarAvion_V(int x,int y );
void pintarInstruccion(void);    
void gotoxy(int x,int y);
void cursor();
 void pintarLimite();
 void pintarBalita(int x,int y );
 void moverBalita(int x,int y );

char avion_l1[]={' ',' ',' ', '"' ,' ',' ',' ','\0'};
char avion_l2[]={' ','|',' ', ' ', ' ','|',' ','\0'};
char avion_l3[]={'*',' ',' ', '*' ,' ',' ','*','\0'};



char MoverseX[ESPACIOS_H];   //ESPACIOS 75
char CampoDeMovimientoX[]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
				 ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
				 ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                 ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',0}; // son 75 espacios

char MoverseY[ESPACIOS_V]; ///ESPACIOS 23
char CampoDeMovimientoY[]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                           ' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};//son 25
//char CampoDeMovimientoY[]={'\n',0};

int main(void)
{
           
      char tecla;
	  //int i, j, k;
	  
	  
	  int horizontal=35; // posición punto de partida horizontal
      int vertical= 13;  // posición de punto de partida de `posición vertical

    do{ 
      cursor();  // Caracteriza el curso desapareciendolo de pantalla.
   // pintarLimite();
     
     		
             //_setcursortype( 0 );
             pintarAvion_H(horizontal,vertical);     //Pinta el avión a partir del valor de 
             		                      //horizontal
             pintarAvion_V(horizontal,vertical);                               
           tecla=getch();						//Espera a que presionemos una tecla (conio)
             
             //tecla=cin.get();
             if(tecla== IZQUIERDA && horizontal>1)horizontal-=1;		//Avanza a la izquierda
		else if(tecla== DERECHA & horizontal<71)horizontal+=1;	//Avanza hacia la derecha
             if(tecla== ARRIBA && vertical>1)vertical-=1;       //Avanza hacia arriba
        else if(tecla== ABAJO && vertical<22)vertical+=1;	//Avanza hacia abajo    
		       int balver=vertical;
		  if(tecla== 'a')
		  {
		  
		  for(int i =0 ;i<vertical-1;i++){
		  	
		  	 moverBalita(horizontal+3,balver-2);
		  	 balver--;
		  	 Sleep(30);
		 if(i==vertical-2){

			 cout <<"hola"<<endl;
		 		Sleep(2000);
		 }
		  
		  }
		  
	
			}	
		  /*balita(horizontal,wardv);
		  wardv++;*/
	
		
		
		// if(kbhit()){
		 

		 	
		// }
		 
        system("cls");
            
     }while(1 == 1);     //| 38 | (Arriba) | 40 | (Abajo) || 37 | (Izqierda) |
                            //| 39 | (Derecha) |
      
      return 0; 
}
void pintarBalita(int x,int y ){
	
	gotoxy(x,y+1); //+3 -2  
printf("%c", 184);
}


void moverBalita(int x,int y){
	gotoxy(x, y); printf(" ");

		pintarBalita(x,y);


}

void pintarAvion_H(int x,int y ){

	gotoxy(x,y); puts(avion_l1); // imprimimos los respectivos espacios y las distintas partes
    gotoxy(x,y+1); puts(avion_l2); // del avion
	gotoxy(x,y+2); puts(avion_l3);
}

void pintarAvion_V(int x, int y ){

	gotoxy(x,y);printf(MoverseX); puts(avion_l1); // imprimimos los respectivos espacios y las distintas partes
    gotoxy(x,y+1);printf(MoverseX); puts(avion_l2); // del avion
	gotoxy(x,y+2);printf(MoverseX); puts(avion_l3);
}
void gotoxy(int x, int y) // Función para posicionar el cursor en la pantalla
 { 
 COORD coord; 
 coord.X = x; 
 coord.Y = y; 
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 
 } 
 
 void pintarLimite()
	{
	for (int i = 2; i < 78;i++)
	{
		gotoxy(i, 3); printf("%c", 205);
		gotoxy(i, 33); printf("%c", 205);
	}
	for (int i = 4; i < 33; i++)
	{
		gotoxy(2, i); printf("%c", 186);
		gotoxy(77, i); printf("%c", 186);
	}
	gotoxy(2, 3); printf("%c", 201);
	gotoxy(2, 33); printf("%c", 200);
	gotoxy(77, 3); printf("%c", 187);
	gotoxy(77, 33); printf("%c", 188);
	}
 
 void cursor()          //Función para caracterizar el cursor
 {
      HANDLE hCon;
      hCon= GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_CURSOR_INFO cci; 
      cci.dwSize=50;      // tamaño del cursor en porcentaje (%)
      cci.bVisible=FALSE; // FALSE para que no se haga visible
                         // TRUE para que se haga visible
      
      SetConsoleCursorInfo(hCon,&cci);
     
}
