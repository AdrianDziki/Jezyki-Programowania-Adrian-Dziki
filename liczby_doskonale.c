#include<stdio.h>
void czy_liczba_jest_doskonala(int liczba)
{
   int i, suma=0;
   for(i=1;i<=liczba/2; i++)
   {
     if(liczba%i==0)
      {
        suma=suma+i;       
      }                
   }
   
   if(suma==liczba)
    printf("liczba %d jest doskonala\n", suma);
   
}
 
void liczby_doskonale()
{
  int j;
  for(j=1;j<=1000;j++)
  {
    czy_liczba_jest_doskonala(j);
 }
}
  
  
main () 
{
printf("LICZBA DOSKONALA\n");
printf("----------------------------------------\n");
printf("liczby doskonale od 0 do 1000 to:\n");
liczby_doskonale();

}


