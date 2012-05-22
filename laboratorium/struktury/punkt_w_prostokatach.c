#include <stdarg.h>
#include <stdio.h>

#define ILOSC 10

struct point {
 int x;
 int y;
};

struct rect {
 struct point ll;
 struct point ur;
};

struct point makepoint(int x, int y) {
 struct point tmp;
 tmp.x = x;
 tmp.y = y;
 return tmp;
}

int ptinrect(struct point p, struct rect r)
{
 return p.x >= r.ll.x && p.x < r.ur.x && p.y >= r.ll.y && p.y < r.ur.y;
}


void wypelnianie(struct rect *tmp)
{
 int i=0;
 for(i=0;i<ILOSC;i++)
 {
  tmp[i].ll.x=0;
  tmp[i].ll.y=0;
  tmp[i].ur.x=0;
  tmp[i].ur.y=0;
 }
  
}

int ptinrectangles(char *fmt, ...)
{
 va_list ap;
 struct point p;
 struct rect rr[ILOSC];
 int flag=0;
 int punkty_prostokaty=0;
 int i=0;
 
 wypelnianie(rr);
 
 va_start(ap, fmt);
 while (*fmt!='d')
  switch(*fmt++) {
      case 'p':
        p = va_arg(ap, struct point);
        break;
         
      case 'r':        
        rr[i] = va_arg(ap, struct rect);
        i++;
        break;     
       }
     
     va_end(ap);

 for(i=0;i<ILOSC; i++)
 {
  if (ptinrect(p, rr[i]) )
   punkty_prostokaty=punkty_prostokaty+1;
 } 
 
 
 return punkty_prostokaty;
}

int main() {
 
 /*punkt*/
 struct point p;
 p.x = 1;
 p.y = 1;
 printf("P(%d, %d)\n", p.x, p.y);
 /*pierwszy prostokat*/
 struct rect r;
 r.ll.x=0;
 r.ll.y=0;
 r.ur.x=3;
 r.ur.y=3;
  printf("R: LL(%d, %d), UR:(%d, %d)\n", r.ll.x, r.ll.y, r.ur.x, r.ur.y);
 /*drugi prostokat*/
 struct rect r1;
 r1.ll.x=0;
 r1.ll.y=0;
 r1.ur.x=5;
 r1.ur.y=5;
  printf("R: LL(%d, %d), UR:(%d, %d)\n", r1.ll.x, r1.ll.y, r1.ur.x, r1.ur.y);
 /*trzeci prostokat*/
 struct rect r2;
 r2.ll.x=3;
 r2.ll.y=1;
 r2.ur.x=6;
 r2.ur.y=2;
 printf("R: LL(%d, %d), UR:(%d, %d)\n", r2.ll.x, r2.ll.y, r2.ur.x, r2.ur.y);
 
 
 int ilosc = ptinrectangles("rrprdrrr",  r,  r1,p, r2);
 
 if(ilosc)
  printf("Punkt nalezy do %d z podanych prostokatow\n", ilosc);
 else
  printf("Punkt nie nalezy do zadnego z prostokatow\n");
 
 return 0;
 
}
