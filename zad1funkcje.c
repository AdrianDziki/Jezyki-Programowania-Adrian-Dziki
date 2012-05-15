#include<stdio.h>
#include<math.h>
double przeciwprostokatna(double a, double b)
{
 double c;
 c=sqrt(a*a+b*b);  
 return c;
}

main()
{
      
double c,d,e;
c=przeciwprostokatna(3,4);  
d=przeciwprostokatna(5,5);
e=przeciwprostokatna(1,6);
printf("Dlugosc przeciwprostokatnej wynosi = %5.5lf\n", c); 
printf("Dlugosc przeciwprostokatnej wynosi = %5.5lf\n", d); 
printf("Dlugosc przeciwprostokatnej wynosi = %5.5lf", e); 

}
