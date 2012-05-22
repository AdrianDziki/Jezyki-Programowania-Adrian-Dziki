#include<stdio.h>
/*ten program jest do testowania usuwania komentarzy*/
struct point 
{
  int x;
  int y;
};
//usuwam komentarze
struct rect {
  struct point ll;
  struct point ur;
};
//to jest plik z komentarzami
struct point makepoint(int x, int y) {
  struct point tmp;
  tmp.x = x;
  tmp.y = y;
  return tmp;
}
//plik z komentarzami
int rectinrect(struct rect r1, struct rect r2)
{
        if (r1.ll.x >= r2.ll.x && r2.ur.x >= r1.ur.x && r1.ll.y >= r2.ll.y && r2.ur.y >= r1.ur.y)
           return 1;
        else
           return 0;       
}
/* komentarz komentarz komentarz*/
int main () 
{
  int r;
  
 // struct rect r1;
 // struct rect r2;
 /* printf("SPRAWDZENIE CZY PIERWSZY PROSTOKAT JEST ZAWARTY W DRUGIM\n\n");
  printf("Podaj wspolrzedne lewego dolnego rogu pierwszego prostokata: \n");
  scanf("%d", &r1.ll.x);
  scanf("%d", &r1.ll.y);
  printf("Podaj wspolrzedne prawego gornego rogu pierwszego prostokata: \n");
  scanf("%d", &r1.ur.x);
  scanf("%d", &r1.ur.y);
  printf("Podaj wspolrzedne lewego dolnego rogu drugiego prostokata: \n");
  scanf("%d", &r2.ll.x);
  scanf("%d", &r2.ll.y);
  printf("Podaj wspolrzedne prawego gornego rogu drugiego prostokata: \n");
  scanf("%d", &r2.ur.x);
  scanf("%d", &r2.ur.y);*/
  
  
  /*komentarz komentarzkomentazr*/
  if(r1.ll.x < r1.ur.x && r1.ll.y < r1.ur.y && r2.ll.x < r2.ur.x && r2.ll.y < r2.ur.y)
  {
    r = rectinrect(r1, r2);
    printf("Jesli zawiera to 1, jesli nie zawiera to 0 : %d\n", r ); //komentarz
  }
  else
    printf("Wspolrzedne jednego z prostokatow sa zle (wspolrzedne prawego\ngornego rogu nie moga byc mniejsze od wspolrzednych lewego gornego rogu)");  //komentarz
    
}
