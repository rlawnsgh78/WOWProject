#include <stdio.h>
#include <windows.h>
#include <conio.h> 

int main(){ 
enum {
BLOCK,   /*  0 : 까망 */ 
DARK_BLUE,  /*  1 : 어두운 파랑 */ 
DARK_GREEN,  /*  2 : 어두운 초록 */ 
DARK_SKY_BLUE, /*  3 : 어두운 하늘 */ 
DARK_RED,  /*  4 : 어두운 빨강 */ 
DARK_VOILET, /*  5 : 어두운 보라 */ 
DARK_YELLOW, /*  6 : 어두운 노랑 */ 
GRAY,   /*  7 : 회색 */ 
DARK_GRAY,  /*  8 : 어두운 회색 */ 
BLUE,   /*  9 : 파랑 */ 
GREEN,   /* 10 : 초록 */ 
SKY_BLUE,  /* 11 : 하늘 */ 
RED,   /* 12 : 빨강 */ 
VOILET,   /* 13 : 보라 */ 
YELLOW,   /* 14 : 노랑 */ 
WHITE,   /* 15 : 하양 */
};     
void SetColor(int color)     
{       
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color );      
} 
SetColor(SKY_BLUE);   
printf("어? 하늘색이다~"); 
getch();
}
