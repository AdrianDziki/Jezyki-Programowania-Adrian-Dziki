#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* wyswietlenie w postaci heksadecymalnej - uzywalem do debugowania*/
void print_mem(char *ptr, int len)
{
  int i=0;
  
  for (i=0; i<len; i++)
    printf("%02x ", *(ptr+i));
  printf("\n");    
}

/* wyswietlanie w postaci charow*/
void print_char(char *ptr, int len)
{
  int i=0;
  
  for (i=0; i<len; i++)
    printf("%c ", *(ptr+i));
  printf("\n");    
}



/* sprawdzam ile znakow, ktore mnie nie interesuja: spacja i tabulator*/
int sprawdz_ile_znakow(char *ptr, int len)
{
  int i=0;
  int tmp=0;
  
  for(i=0; i<len; i++)
  {
      switch(*(ptr+i))
      {
        case 0x20: /*spacja*/
          tmp++;
        break;
        case 0x09: /*tabulator*/
          tmp++;
        break;   
      } 
      
  }
return tmp;
}

/* kod automatu*/
void automat(char *out, char *in)
{
  /* sprawdzam dlugosc wejscia*/
  int len = strlen(in); 
  /*moj indeks do wedowania po wejsciowej przestrzeni*/
  int i=0;
  /* moj indeks do wedrowania po wyjsciowej przestrzeni*/
  int j=0;
  
  /*zmienna co bedzie przechowywac stan */
  char state=0x00;;
  
  while(i<len)
  {
               
    state = in[i];
     
     switch(state)
     {
       case 0x20: /*spacja*/
         
       break;
       
       case 0x09: /*tabulator*/
       
       break;
       
       default:/*znaczek*/
        out[j++] = state;
        out[j++] = 0x20;       
               
     }
        
    i++;
  }

}

/*algorytm*/
void zadanie_pierwsze(char *output, char *input)
{

  /*sprawdzam dlugosc ciagu*/
  int len = strlen(input); 

  /*wyswietlam wejscie*/
  print_char(input, len);

  /* sprawdzam ile mam znakow nie bedacych ani spacja ani tabulatorem */
  len = len - sprawdz_ile_znakow(input, len);  
  
  /* obliczam ile bede potrzebowal miejsce wraz ze spacjami pomiedzy znakami*/
  len = 2*len-1;
  
  /* alokuje pamiec na wynik dzialania automatu*/
  output = (char*)malloc(len);
  
  /*czyszcze ta przestrzen*/
  memset(output, 0x00, len);

  /*uruchamiami automat */
  automat(output, input);
  
  /*wyswietl wynik*/  
  print_char(output, len);

  /* zwolnij zaalokowana pamiec*/
  free(output);

}



int main()
{
  char input[] = "1  2\t\t3\t\t 4";
  char *output=NULL;
  
  zadanie_pierwsze(output, input); 
  printf("\n");
  printf("---------------------------------------------------------------------------------");
  printf("\n");
  /* sprawdzam jeszcze dla innego ciagu*/
  char input2[] = "j\ta\ts fd  k \tj     h\t\t\t\tv";
  zadanie_pierwsze(output, input2);  
  
  
return 0;

}
