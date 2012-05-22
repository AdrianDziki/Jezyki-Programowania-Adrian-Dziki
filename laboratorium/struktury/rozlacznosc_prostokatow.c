#include<stdio.h>

struct point {
	int x;
	int y;
};

struct rect {
	struct point ll;
	struct point ur;
};


int ptinrect(struct point p, struct rect r) {
	return p.x >= r.ll.x && p.x <= r.ur.x
	&& p.y >= r.ll.y && p.y <= r.ur.y;
}

int disjointrect(struct rect r1, struct rect r2)
{	
	/* wyznaczam gorny  lewy punkt dla r1*/
	struct point ul1, lr1;

	ul1.x = r1.ll.x;
	ul1.y = r1.ur.y;
	
	/* wyznaczam dolny prawy punkt dla r1*/
	
	lr1.x = r1.ur.x;
	lr1.y = r1.ll.y;
	
	/* wyznaczam gorny  lewy punkt dla r2*/
	struct point ul2, lr2;
	
	ul2.x = r2.ll.x;
	ul2.y = r2.ur.y;
	
	/* wyznaczam dolny prawy punkt dla r2*/
	
	lr2.x = r2.ur.x;
	lr2.y = r2.ll.y;

	return (ptinrect(r1.ll, r2) || ptinrect(r1.ur, r2) || ptinrect(ul1, r2) || ptinrect(lr1, r2) || ptinrect(r2.ll, r1) || ptinrect(r2.ur, r1) || ptinrect(ul2, r1) || ptinrect(lr2, r1));
	
}

int main () 
{
	int r;
	
	struct rect r1;
	struct rect r2;
	printf("SPRAWDZENIE CZY PIERWSZY PROSTOKAT JEST ROZLACZNY WZGLEDEM DRUGIEGO\n\n");
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
	scanf("%d", &r2.ur.y);

	
	
	 if(r1.ll.x < r1.ur.x && r1.ll.y < r1.ur.y && r2.ll.x < r2.ur.x && r2.ll.y < r2.ur.y)
		{
			r = disjointrect(r1, r2);

			printf("Jesli rozlaczny to 0, jesli nie jest rozlaczny to 1: %d\n", r );
		}
	
	else
		printf("Wspolrzedne jednego z prostokatow sa zle (wspolrzedne prawego\ngornego rogu nie moga byc mniejsze od wspolrzednych lewego gornego rogu)");
		
}
