#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

/**
* @author Maycon de Queiroz
* Adianta TEMPO a legenda - Tempo negativo atrasa a legenda
* Chamada: Legenda [Arquivo de entrada] [Tempo (positivo adianta e negativo atrasa)]
*/

FILE *On;
FILE *Off;
char L[200],K[200],J[200];
int M1=0,S1=0,H1=0,O1=0,M2=0,S2=0,H2=0,O2=0, N=0, TEMPO=0;

int T19 (){
  if (S1>=TEMPO){
    S1=S1-TEMPO;
  } else {
    M1=M1-1;
    S1=S1+(60-TEMPO);
  }
  if (S2>=TEMPO){
    S2=S2-TEMPO;
  } else {
    M2=M2-1;
    S2=S2+(60-TEMPO);
  }
  return 0;
}

int T20(){
  TEMPO=TEMPO*-1;
  S1=S1+TEMPO;
  if (S1>=60){
    M1=M1+1;
    S1=S1-60;
  }
  if (M1>=60){
    H1=H1+1;
    M1=M1-60;
  }
  S2=S2+TEMPO;
  if (S2>=60){
    M2=M2+1;
    S2=S2-60;
  }
  if (M2>=60){
    H2=H2+1;
    M2=M2-60;
  }
  TEMPO=TEMPO*-1;
}

int Dois(int A){
  int B=0;
  if (K[A]=='1'){
    B=B+10;
  }
  if (K[A]=='2'){
    B=B+20;
  }
  if (K[A]=='3'){
    B=B+30;
  }
  if (K[A]=='4'){
    B=B+40;
  }
  if (K[A]=='5'){
    B=B+50;
  }
  if (K[A]=='6'){
    B=B+60;
  }
  if (K[A]=='7'){
    B=B+70;
  }
  if (K[A]=='8'){
    B=B+80;
  }
  if (K[A]=='9'){
    B=B+90;
  }
  if (K[A+1]=='1'){
    B=B+1;
  }
  if (K[A+1]=='2'){
    B=B+2;
  }
  if (K[A+1]=='3'){
    B=B+3;
  }
  if (K[A+1]=='4'){
    B=B+4;
  }
  if (K[A+1]=='5'){
    B=B+5;
  }
  if (K[A+1]=='6'){
    B=B+6;
  }
  if (K[A+1]=='7'){
    B=B+7;
  }
  if (K[A+1]=='8'){
    B=B+8;
  }
  if (K[A+1]=='9'){
    B=B+9;
  }
  return B;
}

int Tres(int A){
  int B=0;
  //Centena
  if (K[A]=='1'){
    B=B+100;
  }
  if (K[A]=='2'){
    B=B+200;
  }
  if (K[A]=='3'){
    B=B+300;
  }
  if (K[A]=='4'){
    B=B+400;
  }
  if (K[A]=='5'){
    B=B+500;
  }
  if (K[A]=='6'){
    B=B+600;
  }
  if (K[A]=='7'){
    B=B+700;
  }
  if (K[A]=='8'){
    B=B+800;
  }
  if (K[A]=='9'){
    B=B+900;
  }
  //Dezena
  if (K[A+1]=='1'){
    B=B+10;
  }
  if (K[A+1]=='2'){
    B=B+20;
  }
  if (K[A+1]=='3'){
    B=B+30;
  }
  if (K[A+1]=='4'){
    B=B+40;
  }
  if (K[A+1]=='5'){
    B=B+50;
  }
  if (K[A+1]=='6'){
    B=B+60;
  }
  if (K[A+1]=='7'){
    B=B+70;
  }
  if (K[A+1]=='8'){
    B=B+80;
  }
  if (K[A+1]=='9'){
    B=B+90;
  }
  //Unidade
  if (K[A+2]=='1'){
    B=B+1;
  }
  if (K[A+2]=='2'){
    B=B+2;
  }
  if (K[A+2]=='3'){
    B=B+3;
  }
  if (K[A+2]=='4'){
    B=B+4;
  }
  if (K[A+2]=='5'){
    B=B+5;
  }
  if (K[A+2]=='6'){
    B=B+6;
  }
  if (K[A+2]=='7'){
    B=B+7;
  }
  if (K[A+2]=='8'){
    B=B+8;
  }
  if (K[A+2]=='9'){
    B=B+9;
  }
  return B;
}

int Atempo(){
  H1 = Dois(0);
  M1 = Dois(3);
  S1 = Dois(6);
  O1 = Tres(9);
  H2 = Dois(17);
  M2 = Dois(20);
  S2 = Dois(23);
  O2 = Tres(26);
}

int main (int argc, char *argv[]){
  if (argc != 3){
    printf ("Quantidade de argumentos insuficiente, espera-se:\n\tLegenda.exe [Arquivo de entrada] [Tempo (positivo adianta e negativo atrasa)]");
    return -1;
  }
  Off=fopen("OUT.srt","w");
  if (Off == NULL){
    printf ("Erro ao abrir o arquivo de saida\n");
    return -1;
  }
  On=fopen(argv[1],"r");
  if (On == NULL){
    printf ("Erro ao abrir o arquivo de saida\n");
    return -1;
  }
  TEMPO = atoi(argv[2]);
  while (!feof(On)){
    fscanf (On, "%i\n", &N);
    fprintf(Off, "%i\n", N);
    fgets (K, 70, On);
    Atempo();
    if (TEMPO>0){
      T19();
    } else {
      T20();
    }
    fprintf(Off, "%i:%i:%i,%i --> %i:%i:%i,%i\n", H1, M1, S1, O1, H2, M2, S2, O2);
    fgets(L, 70, On);
    fgets(J, 70, On);
    fprintf(Off, "%s", L);
    if (strcmp(J, "\n")==0){
      fprintf(Off, "\n", J);
    } else {
      fprintf(Off, "%s\n", J);
    }
  }
}
