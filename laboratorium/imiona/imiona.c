#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* sprawdzenie dlugosci pliku*/
int dlugosc_pliku(FILE *f)
{
	
	int pos;
	int end;
	
	pos = ftell (f);
	fseek (f, 0, SEEK_END);
	end = ftell (f);
	fseek (f, pos, SEEK_SET);
	
	return end;
}

/*drukowanie imiona az do znaku nowej linii*/

void drukuj_imie(char *start)
{
	int i=0;
	
	do{
		printf("%c", *(start+i)); /* drukuje wszystkie znaczki od adresu start do znaku nowej linii*/
		i++;
	}while(*(start+i)!='\n');	/* drukuje az do znaku nowej linii- jedno imie - jedna linia*/
	printf("\n");
}

/* to co mi potrzeba to uchwyt do pliku + prefiks ktory bedziemy uzywac do wyszukiwania*/
void przeszukiwanie(FILE *bibl, char *prefiks)
{
	char *b=NULL;
	char c;
	int i=0;
	int prefiks_dlugosc=0;
	

	/* najpierw musze zobaczyc ile ten plik ma wielkosci*/
	int cala_dlugosc = dlugosc_pliku(bibl);
	
	
	b = (char *)malloc(cala_dlugosc); /* alokuje */
	memset(b, 0x00, cala_dlugosc);
	
	if(b!=NULL)
	{	
		
		/* wczytujemy plik i kazde imie konczymy znakiem konca stringu*/
		do {
			c = fgetc (bibl);				
				b[i] = c; 
			i++;
		} while (c != EOF);/* czytam az sie plik skonczy*/
	}	
	
	/* sprawdzamy dlugosc prefiksu*/
	prefiks_dlugosc = strlen(prefiks);

	for(i=0; i<cala_dlugosc; i++)
	{
		/* funkcja memcmp - porownuje dwie zawartosci pamieci - jedna jest pod adresem (b+i) a druga to co kryje prefiks*/
		if (memcmp((b+i), prefiks, prefiks_dlugosc)==0) /* jak zwraca zero - to znaczy ze sie nie roznia*/
		{
			drukuj_imie(b+i); /* jak sie nie roznia to wypisuje imie*/
		}
		
	}	
	
	/* zwalniamy obszar pamieci na koncy*/
	free(b);
	
}

int main(int argc, char* argv[])
{
	FILE *bibl;
	
	/* sprawdzam czy podany byl argument*/
	if(argc == 3)
	{
		/* otwieram plik w trybie czytanie tylko*/
		bibl = fopen(argv[1], "r");
		
		if(bibl==NULL)
		{
			printf("Nie mozna odczytac tego pliku\n");
		}else
		{
			przeszukiwanie(bibl, argv[2]);
		}
		fclose(bibl);
			
	}
	else
	{
		printf("Skladnia: program <biblioteka> <prefiks z duzej litery>\n");
	}	
	
  return 0;
}