#include <16f1937.h>            //pic a utilizar          
//#include <time.h>
#include <stdlib.h>
#include <tones.c>
#use standard_io (D)
#use standard_io (B)
#fuses XT, NOPROTECT, NOWRT, NOPUT, NOWDT, NOLVP, NOCPD       //ordenes para el programador 
#use delay (clock=4000000)         //Fosc=4Mhz
#define lcd_rs_pin PIN_D4
#define lcd_rw_pin PIN_D5
#define lcd_enable_pin PIN_D6
#define lcd_data4 PIN_D0
#define lcd_data5 PIN_D1
#define lcd_data6 PIN_D2
#define lcd_data7 PIN_D3
#include <lcd.c>               //libreria manejo de la lcd
#define TONE_PIN  PIN_B3


int
character1[8] = {7,23,22,31,14,10,15,0},//dino completo
character2[8] = {7,23,22,31,14,2,3,0},// dino sin pata izquierda
character3[8] = {7,23,22,31,14,8,12,0},// dino sin pata derecha
character4[8] = {6,22,22,30,30,6,6,31}, //cactus grande
character5[8] = {0,0,12,13,15,12,12,31}, //cactus chico
character6[8] = {29,28,25,2,20,0,0,0}, //sol 1
character7[8] = {28,29,24,2,8,0,0,0};  // sol 2

/////////////////// variables para el juego
int randon; 
int16 puntuacion=0;
int16 final=0;
int16  record=0;
int16 record1=0;
signed int16 cac;
signed int16 gua;
int guar=0;
   
           int delay=0, delay1=0, delay2=0; //declaramos las variables para 
	///despues poder modificar la velocidad
           
//////////////////////////////////////////////////////////////////////////////



void principal (){   ///programa principal que contiene la mayoria de 
///las funciones del codigo


 for (cac=16; cac>0; cac--){ //for para que los cactus se recorran
     
     
     
   if(cac==2){           ///////sonidos de perder
        output_high (PIN_B3);   ///encender la bocina conectada al pin B3
     delay_ms(5);               //mantener 5 ms
        output_low (PIN_B3);	///apagar la bocina conectada al pin B3
         delay_ms(5); 		 //mantener 5 ms
        
         output_high (PIN_B3);	 ///encender la bocina conectada al pin B3
     delay_ms(5);  		//mantener 5 ms
        output_low (PIN_B3);	///apagar la bocina conectada al pin B3
         delay_ms(5); 		//mantener 5 ms
         
         
         output_high (PIN_B3);	 ///encender la bocina conectada al pin B3
     delay_ms(5);  		//mantener 5 ms
        output_low (PIN_B3);	///apagar la bocina conectada al pin B3
         delay_ms(5); 		//mantener 5 ms
         
         
         output_high (PIN_B3);	 ///encender la bocina conectada al pin B3
     delay_ms(5);  		//mantener 5 ms
        output_low (PIN_B3);	///apagar la bocina conectada al pin B3
        
        
       cac=2;  			//mantenemos la variable cac en un valor de 2 
      
    lcd_putc("\f" ) ; 		//limpiar la pantalla 
          lcd_gotoxy(5,1);	//apuntar a la posición x=5 y y=1
       lcd_putc("Perdiste" ) ;	//imprimir  mensaje
     
 
          if ((record<puntuacion)&& (record1<final)){ //comparar si la puntución anterior 
							// es más pequeña que la puntuación actual
              while (input(PIN_B0)==1){    //entrar a un ciclo donde se debe de oprimir el boton en B0
					   // para salir e iniciar un nuevo juego
              lcd_gotoxy(1,2);		   //apunta a la posición  
      printf(lcd_putc,"New Record!:%3Lu%Lu",final,  puntuacion);  //imprimir mensaje junto con dos variables
        record=puntuacion ;  //almacenamos la puntuación más alta en la variable record
        record1=final;  //lamacenamos la variable final más alta en record1
        
        delay_ms(500); //mantenemos este ciclo durante 500ms
         
              } //Fin de while


               lcd_putc("\f" ) ; //limpiamos pantalla
               puntuacion=0;  //limpiamos la varible puntuación
          	final=0; //limpiar final
	} //fin de If
            
              
              
              if((record>=puntuacion)&& (record1>=final)){ //checar sipuntuación y final son
								//más pequeñas que el record
               while (input(PIN_B0)==1){   //salir del ciclo cuando se precione B0    
              lcd_gotoxy(1,2);		//apunta ala posición x=1 y=2 de la pantalla LCD
      printf(lcd_putc,"Puntuacion:%3Lu%Lu",final,  puntuacion); //Imprime mensajecon dos variables
       delay_ms(500);  //mantener  500ms
  
         
              } //Fin while
                       lcd_putc("\f" ) ; //limpiar pantalla
                puntuacion=0; //limpar puntuación 
                final=0; //limpiar final
              } //Fin if
      
           
           
      
      
     
          
}
   //velocidad
   if(final<2) //si se tiene menos de 20 puntos 
   {
       delay=40;
       delay1=20; //velocidad baja
       delay2=10;
       
   }

   if((final<5)&&(final>2)) //si se tiene menos de 50 puntos y más de 20 
   {
       delay=30;
       delay1=15; //velocidad media 
       delay2=8; 
   }

   if((final<7)&&(final>5)) //si se tiene menos de 70 puntos y más de 50 
   {
       delay=20;
       delay1=10; //velocidad alta
       delay2=5;
       
   }

   if((final<10)&&(final>7))  //si se tiene menos de 100 puntos y más de 70 
   {
       delay=10;
       delay1=5; //velocidad más alta
       delay2=3;
       
   }
   if(final>10)  //si se tiene mas de 100 puntos 
   {
       delay=6;
       delay1=3; //velocidad final
       delay2=2;
       
   }
   

//GENERAR ESCENARIO RANDOM
  
 
   if (cac==16){ //solo se generan cuando inicia el ciclo de recorrer los cactus
    randon=(rand()%7); //elegir un número entre 0 y 6
   }

     if (randon==0){  //si el número es 0
     lcd_gotoxy(cac,2);
                     printf(lcd_putc, "%c",4);////cactus
delay_ms(delay2);
                        lcd_gotoxy(cac+1,2);///////borrar
                     printf(lcd_putc, " ");
}


if (randon==1){ //si el número es 1
     lcd_gotoxy(cac,2);
                     printf(lcd_putc, "%c",3);////cactus
                       delay_ms(delay2);
                        lcd_gotoxy(cac+1,2);///////borrar
                     printf(lcd_putc, " ");
}

if (randon==2){  //si el número es 2
     lcd_gotoxy(cac,2);
                     printf(lcd_putc, "%c%c",4,3);////cactus
                     delay_ms(delay2);
                        lcd_gotoxy(cac+2,2);///////borrar
                     printf(lcd_putc, " ");
}

if (randon==3){   //si el número es 3
     lcd_gotoxy(cac,2);
                     printf(lcd_putc, "%c%c",3,4);////cactus
                     delay_ms(delay2);
                        lcd_gotoxy(cac+2,2);///////borrar
                     printf(lcd_putc, " ");
}
if (randon==4){    //si el número es 4
     lcd_gotoxy(cac,2); 
                     printf(lcd_putc, "%c%c%c",4,3,4);////cactus
                     delay_ms(delay2);
                        lcd_gotoxy(cac+3,2);///////borrar
                     printf(lcd_putc, " "); //limpiar
                 
}

if (randon==5){   //si el número es 5
     lcd_gotoxy(cac,2);
                     printf(lcd_putc, "%c%c%c",3,4,3);////cactus
                     delay_ms(delay2);
                        lcd_gotoxy(cac+3,2);///////borrar
                     printf(lcd_putc, " ");
}
if (randon==6){   //si el número es 6
     lcd_gotoxy(cac,2);
                     printf(lcd_putc, "%c%c",4,4);////cactus
delay_ms(delay2);
                        lcd_gotoxy(cac+2,2);///////borrar
                     printf(lcd_putc, " ");
}   
  
    
     
     lcd_gotoxy(5,1); //apunta a la posición x=5 y=1 de la LCD
     printf(lcd_putc," P=%3Lu%Lu",final, puntuacion);  //imprime los puntos en la partida
    
     lcd_gotoxy(2,2);
     printf(lcd_putc, "%c",1); //imprime dino sin pata izquierda
      lcd_gotoxy(1,1);
     printf(lcd_putc, "%c",5); //imprime sol 1 
         
     delay_ms(delay1);
  
      lcd_gotoxy(2,2);
     printf(lcd_putc, "%c",2); //imprime dino sin pata derecha
      lcd_gotoxy(1,1);
     printf(lcd_putc, "%c",6); //imprime sol 2
 
     delay_ms(delay1);
    
     gua=cac; //antes de entrar al if cuando se preciona el botón, guardamos la variable cac 
     
     ////////////////////
       if (input(PIN_B0)==0){  //if cuando se preciona el botón
         
           lcd_putc("\f" ) ; // limpiar pantalla
           
       lcd_gotoxy(5,1);  
     printf(lcd_putc," P=%3Lu%Lu",final, puntuacion);   //imprimir variables final y puntuación
    
     lcd_gotoxy(2,1);
     printf(lcd_putc, "%c",0);  //imprime dino completo (saltando)
      lcd_gotoxy(1,1);
     printf(lcd_putc, "%c",5);  //imprime sol 1
     delay_ms(5);
  
      lcd_gotoxy(2,1);
     printf(lcd_putc, "%c",0); //imprime dino completo (saltando)
      lcd_gotoxy(1,1);
     printf(lcd_putc, "%c",6); //imprime sol 2
     delay_ms(5);    
     int lo;
   lo= cac-4;  //
   output_high (PIN_B3); //sonar cuando saltan
     delay_ms(5);  
        output_low (PIN_B3); //apagar bocina
        
   

        
 for (cac=gua-1; gua>lo; gua--){///ciclo para mover cactus y dino saltando 
   
                puntuacion=guar; 
              guar++;
              lcd_gotoxy(5,1);
             
                printf(lcd_putc," P=%3Lu%Lu",final, puntuacion); 

  if (randon==0){
     lcd_gotoxy(gua,2);
                     printf(lcd_putc, "%c",4);////cactus
   //delay_ms(delay2);
                        lcd_gotoxy(gua+1,2);///////borrar
                     printf(lcd_putc, " ");
                    delay_ms(delay);
}


if (randon==1){
     lcd_gotoxy(gua,2);
                     printf(lcd_putc, "%c",3);////cactus
  //delay_ms(delay2);
                        lcd_gotoxy(gua+1,2);///////borrar
                     printf(lcd_putc, " ");
                     delay_ms(delay);
}

if (randon==2){
     lcd_gotoxy(gua,2);
                     printf(lcd_putc, "%c%c",4,3);////cactus
 // delay_ms(delay2);
                        lcd_gotoxy(gua+2,2);///////borrar
                     printf(lcd_putc, " ");
                    delay_ms(delay);
}

if (randon==3){
     lcd_gotoxy(gua,2);
                     printf(lcd_putc, "%c%c",3,4);////cactus
  //delay_ms(delay2);
                        lcd_gotoxy(gua+2,2);///////borrar
                     printf(lcd_putc, " ");
                     delay_ms(delay);
}
if (randon==4){
     lcd_gotoxy(gua,2);
                     printf(lcd_putc, "%c%c%c",4,3,4);////cactus
//  delay_ms(delay2);
                        lcd_gotoxy(gua+3,2);///////borrar
                     printf(lcd_putc, " ");
                   delay_ms(delay);
}

if (randon==5){
     lcd_gotoxy(gua,2);
                     printf(lcd_putc, "%c%c%c",3,4,3);////cactus
  //delay_ms(delay2);
                        lcd_gotoxy(gua+3,2);///////borrar
                     printf(lcd_putc, " ");
                    delay_ms(delay);
}
if (randon==6){
     lcd_gotoxy(gua,2);
                     printf(lcd_putc, "%c%c",4,4);////cactus

                        lcd_gotoxy(gua+2,2);///////borrar
                     printf(lcd_putc, " ");
                     delay_ms(delay);
}  

          
                                         if(guar>=9) //solo va del 0 al 9
                                            {
                                     final++; //cuando las unidades son 9, sumamos a las decenas
                                         guar=0; //regresamos a 0
                                        }
                                        else{
                                    guar++;
        
                                        }
          ///&&&&
           }
 
         lcd_putc("\f" ) ;
          
 }
     cac=gua;
     
 
   
    
    if(puntuacion>=9)
    {
     final++;
     puntuacion=0;
    }
    else{
        puntuacion++;
        
    }
      guar=puntuacion;
}
}

////////////////////////





void main(){   //main
    output_high (PIN_D7); //alimentamos LCD
    lcd_init(); //iniciamos LCD
lcd_set_cgram_char(0, character1); //guardamos caracteres personalizados en cgram
lcd_set_cgram_char(1, character2);
lcd_set_cgram_char(2, character3);
lcd_set_cgram_char(3, character4);
lcd_set_cgram_char(4, character5);
lcd_set_cgram_char(5, character6);
lcd_set_cgram_char(6, character7);

   set_tris_b(0x00);//configura puerto b
   output_b(0x00);

  
   
  while (input(PIN_B0)==1){   ////mensaje de bienvenida mientras no se precione B0 
     
        lcd_gotoxy(1,1);
      printf(lcd_putc,"Presiona A");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Para comenzar");
  }


   delay_ms(100); 
  
   lcd_putc("\f" ) ; //limpia la pantalla
   
       lcd_gotoxy(1,1);
      printf(lcd_putc,"Presentado por:");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Jesus Fer Hiram");
      delay_ms(500);
         lcd_putc("\f" ) ;
      
     
      lcd_gotoxy(4,1);
    printf(lcd_putc,"¡ LISTO !");
      delay_ms(100);
    lcd_putc("\f" ) ;
     
    
    
        output_high (PIN_B3);
     delay_ms(5);  
        output_low (PIN_B3);
         delay_ms(5); 
      lcd_gotoxy(8,1);
      printf(lcd_putc," 3 ");
        delay_ms(100); 
    lcd_putc("\f" ) ;

     
        output_high (PIN_B3);
     delay_ms(5);  
        output_low (PIN_B3);
         delay_ms(5); 
         lcd_gotoxy(8,1);
         printf(lcd_putc," 2 ");
          delay_ms(100); 
    lcd_putc("\f" ) ;
      
   
    
    
        output_high (PIN_B3);
     delay_ms(5);  
        output_low (PIN_B3);
         delay_ms(5); 
    lcd_gotoxy(8,1);
         printf(lcd_putc," 1 ");
          delay_ms(100); 
    lcd_putc("\f" ) ;
    
   output_high (PIN_B3);
     delay_ms(50);  
        output_low (PIN_B3);
         delay_ms(50);
      

while(TRUE){//ciclo infinito
    
principal (); //llamamos a la función principal


        
}   
    
    
    
    
    
   delay_ms(100);   
   lcd_putc("\f" ) ; //limpia la pantalla
      
}
/*
 Final del proyecto Final
  */
