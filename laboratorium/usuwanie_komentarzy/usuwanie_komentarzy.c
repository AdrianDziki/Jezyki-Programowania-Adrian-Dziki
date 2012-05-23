#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *plik1;


/* sprawdzanie dlugosci pliku ktory otworzony ma wskaznik f*/
int dlugosc_pliku(FILE *f)
{
	int pos;	
	int end;
	
	pos = ftell (f); /* aktualna pozycja jest ustawiona na poczatek */
	fseek (f, 0, SEEK_END); /* przewijam plik na koniec*/
	end = ftell (f); /* sprawdzam jak daleko w pamieci jest ten koniec od poczatku - i wiem jaka jest dlugosc*/
	fseek (f, pos, SEEK_SET);/* ustawiam wskaznik na miejsce na poczatku*/
	
	return end; /* zwracam dlugosc*/
}

int zastap(FILE *fp) 
{
	char c;
	int n=0;
	int dlugosc=0;
	char *b;
	int i=0;
	int osc=0, obc=0;
	
	/* sprawdzam czy wskaznik wskazuje na cos*/
	if (fp==NULL) perror ("Plik sie nie otwiera");
	else
	{
		
		dlugosc = dlugosc_pliku(fp); /* sprawdzam dlugosc pliku*/

		b = (char *)malloc(dlugosc); /* alokuje pamiec na plik*/
		memset(b, 0x00, dlugosc); /* czyszcze zaalokowana przestrzen w pamieci*/
		
		if(b !=NULL)	/* jezeli stworzylo sie miejsce to moge na nim pracowac*/
		{	
			do {
				c = fgetc (fp);	/* czytam znaczek z pliku i wstawiam go do zmiennej c, fgetc - po przeczytaniu znaczka - przeskakuje na nastepny w piku*/			
				
				b[i] = c; 	
				i++; /* przechodze do nastepnej lokalizacji */
			} while (c != EOF); /* czytam az sie skonczy plik*/
		}	
	
		for(i=0;i<dlugosc;i++)
		{
			if(*(b+i)=='/' && *(b+i+1)=='*')      /* warunek na wykrycie poczatka duzego komentarza  */
			{	
				obc=1;	/* flaga obc jest ustawiona na 1 - znaczy jestesmy w duzym komentarzu i bedziemy ignorowac jego zawartosc */
			}
			
			if(*(b+i)=='*' && *(b+i+1)=='/') /* warunek na zamkniecie duzego komentarza */
			{	
				obc=0; /* flaga obc ustawiona na zero - juz nie ignorujemy zawartosci */
				*(b+i) = 0x20; /* jeszcze trzeba wyczyscic gwiazdke zamykajaca komentarz*/
				*(b+i+1) = 0x20; /* i wyczyscic slash zamykajacy komentarz */
				
			}	
				
			if(*(b+i)=='/' && *(b+i+1)=='/') /* warunek na wykrycie malego, linijkowego komentarza */
			{	
				osc = 1; /* flga ustawiona na 1 wiec ignorujemy wszystko od tej pory*/
			}	
			
			if(osc==1 && *(b+i)=='\n') /* warunek na zaminiecie malego komentarza - jedziemy do konca lnijki*/
			{
				osc=0; /* flaga osc = 0 wiec juz koniec malego, linijkowego komentarza */
			}	
			
			if( osc==1 || obc==1) /* warunek na to, ze jestesmy albo w malym albo w duzym komentarzu*/
			{ 
				*(b+i) = 0x20; /* jezeli jestesmy w malym albo duzym komentarzu - to zamiast oryginalnego komentarza wstawiamy znaczek spacji */
				
			}	
			
		}	
	
		
		FILE *fnew=fopen("bez_komentarza.c", "w"); /* po wyczysczeniu komentarzy bedziemy wrzucac wynik naszej pracy do pliku bez_komentarza.c - ktory jest otwarty w trybie pisania*/
		
		if (fnew==NULL) /* sprawdzamy czy udalo sie go stworzyc - brak miejsca na dysku moglby spowodowac trudnosc*/
			printf("Nie mozna stworzyc pliku\n");		
		
		for(i=0;i<dlugosc;i++) /* wpisujemy tyle znaczkow ile bylo w pierwszym pliku*/
		{
			fprintf(fnew, "%c", *(b+i)); /* zrzucamy zawartosc pamieci do pliku uzywajac fprintd*/
		}	
		
		fclose(fnew); /* zamykamy plik*/
		
		free(b); /* zwlniamy zaalokowana pamiec */
	
	}
	
}

/* z linii polen bedziemy przesylac nazwe pliku ktory bedzie podlegal czyszczeniu z komentarzy*/
int main(int argc, char* argv[])
{
	
/* musza byc dwa argumenty - pierwszy jest defaultowa nazwa programu a grugi zawiera nazwe argumentu - naszego pliku do czyszczenia */	
if (argc == 2)
{	
			
	plik1=fopen(argv[1], "r"); /* otwieramy plik ktorego nazwa zostala przeslana w argv[1] i jego uchwyt  zapisujemy do plik1*/
	if (plik1==NULL) 
        printf("Nie mozna otworzyc pliku\n");

	zastap(plik1); /* wywolujemy nasza funkcje czyszczaca plik z komentarzy i zapisujaca wynik naszego dzialania w nowym pliku*/
	
	
	fprintf(plik1, ""); 
	fclose(plik1); /* zamykamy uchwyt do pliku*/
}	
	else /* inna ilosc argumentow przywywolaniu programu nie powinna sie zdarzyc */
	{
		printf("podaj nazwe pliku *.c\n");	
	}	

	return 0;
}

