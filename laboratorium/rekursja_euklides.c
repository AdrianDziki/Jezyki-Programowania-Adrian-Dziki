#include<stdio.h>

int  nwd (int n, int k) 
{
  if (n<0||k<0) 
    {
     printf("jedna z liczb lub obie sa ujemne");
    }
  else
    {  
    if (n<k)  
    return nwd(k,n);
    else 
      { 
       if(k==0)  
       return n;
       
       else  
       return nwd(k, n%k);
      }
    }
     
}

main () 
{
  int n, k;
  printf("Podaj pierwsza liczbe naturalna: ");
   scanf("%d", &n);
   while(n<0)
   {
   printf("\nPodles liczbe ujemna albo 0, podaj liczbe naturalna nieuku: ");
   scanf("%d", &n);
   }
   printf("\nPodaj druga liczbe naturalna: ");
   scanf("%d", &k);
   while(k<0)
   {
    printf("\nPodles liczbe ujemna albo 0, podaj liczbe naturalna niekuku: ");
   scanf("%d", &k);
   }
  printf("\n  nwd %d i %d =%d",n,k, nwd(n,k));

}
