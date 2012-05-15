#include <stdarg.h>
#include <stdio.h>

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

int  ptinrectangles(char *fmt, ...)
{
 va_list ap;
 struct point p, *pp;
 struct rect rr, *prr;
 int punkty_prostokaty=0;
 
 va_start(ap, fmt);
 while (*fmt)
  switch(*fmt++) {
   case 'p':
    p = va_arg(ap, struct point);
    printf("P(%d, %d)\n", p.x, p.y);
    break;

   case 'r':
    rr = va_arg(ap, struct rect);
    printf("R: LL(%d, %d), UR:(%d, %d)\n", rr.ll.x, rr.ll.y, rr.ur.x, rr.ur.y);
    
    if (ptinrect(p, rr) )
     punkty_prostokaty=punkty_prostokaty+1;
    else
     punkty_prostokaty; 
    break;
  }
 va_end(ap);
 
 return punkty_prostokaty;
}

int main() {
 
/*punkt*/
 struct point p;
 p.x = 1;
 p.y = 1;
 
/*pierwszy prostokat*/
 struct rect r;
 r.ll.x=0;
 r.ll.y=0;
 r.ur.x=3;
 r.ur.y=3;
/*drugi prostokat*/ 
 struct rect r1;
 r1.ll.x=0;
 r1.ll.y=0;
 r1.ur.x=5;
 r1.ur.y=5;
/*trzeci prostokat*/
 struct rect r2;
 r2.ll.x=3;
 r2.ll.y=1;
 r2.ur.x=6;
 r2.ur.y=2;
 
 printf("prostokat \n");
 int ilosc = ptinrectangles("prrr", p, r, r1, r2);
 
 if(ilosc)
  printf("Punkt nalezy do %d z podanych prostokatow\n", ilosc);
 else 
  printf("Punkt nie nalezy do zadnego z prostokatow\n");
 
 return 0;
 
}
