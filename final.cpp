#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
string palabra, adivinar,numero;
int vidas;
void print_dead(){
  cout<< "__\n|   |\n|   0\n|  /|\\\n|  / \\\n|__________________"<<endl<<endl<<endl;
}
void inicio() {
  cout<< "__\n|   |\n|   \n|  \n|  \n|__________________"<<endl<<endl<<endl;
}
void error1() {
  cout<< "__\n|   |\n|   0\n|  \n|  \n|__________________"<<endl<<endl<<endl;
}
void error2() {
  cout<< "__\n|   |\n|   0\n|   |\n|  \n|__________________"<<endl<<endl<<endl;
}
void error3() {
  cout<< "__\n|   |\n|   0\n|  /|\n|  \n|__________________"<<endl<<endl<<endl;
}
void error4() {
  cout<< "__\n|   |\n|   0\n|  /|\\\n|  \n|__________________"<<endl<<endl<<endl;
}
void error5() {
  cout<< "__\n|   |\n|   0\n|  /|\\\n|  /\n|__________________"<<endl<<endl<<endl;
}
void mostrar(){
  cout<<"vidas: "<<vidas<<endl;
  switch (vidas) {
    case 6:
      inicio();
      break;
    case 5:
      error1();
      break;
    case 4:
      error2();
      break;
    case 3:
      error3();
      break;
    case 2:
      error4();
      break;
    case 1:
      error5();
      break;
  }
  cout<<adivinar<<endl;
}
void inicializar(){
  vidas=6;
  srand (time(NULL));
 string palabras[50]={"bateria", "pizza", "peperoni","salsa","cielo","azul","mentira","mama","fabrica","lado","hawaiano","silencio","hola",
   "lata","capa","calabaza","toldo","plantas","arena","creador","establo","actriz","lavatorio","banana","nuevo","periodico","periodista",
   "siesta","ruido","selva","defensa","barrer","escoba","compañia","baile","compañia","uvas","verruga","chico","grande","bocina","laguna",
   "lago","saludar","saludo","disparar","aplastar","superar","tuerca","feliz"
 };
  palabra = palabras[rand() % 50 + 1];

  for(int i=0; i<palabra.size(); i++){
    palabra[i] = tolower(palabra[i]);
  }
  for(int i=0; i<palabra.size(); i++){
      adivinar+='-';
  }
}

void ingresar(char x){
  int condicion=1;
for (int i = 0; i < palabra.size(); i++) {
  if (palabra[i]==x) {
    condicion=0;
    adivinar[i]=x;
  }
}
if (condicion==1) {
  vidas--;
}
}

int main(){
  inicializar();
  mostrar();
while (vidas>0 && palabra!=adivinar) {
  char x;
  cin>>x;
  ingresar(x);
  mostrar();
}
if (vidas>0) {
  cout<<"GANASTE!"<<endl;
}else{
  cout<<"perdiste!, la respuesta era: "<<palabra<<endl;
  print_dead();
}
return 0;
}
