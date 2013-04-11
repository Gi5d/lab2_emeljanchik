#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1						//student number
#define M 1						//sem1 exam number
#define B 1						//sem2 exam number
#define SE 10
#define NE 8
#define FE 12
char read_argument(int argc, char **argv)
{
	if(argc>=2)
	{
		if(!(strcmp(argv[1], "-sem1")))
			return '1';
		if(!(strcmp(argv[1], "-sem2")))
			return '2';
		if(!(strcmp(argv[1], "-sem3")))
			return '3';
	}
	return '0';
}
struct student
{
	char surname[SE];
	char name[NE];
	char father_name[FE];
};
union results
{
	int sem1[M];
	int sem2[B];
};
struct info
{
	student info_s;
	results info_r;
	int sem_number;
};
void flist_1 (int b, info z)
{
	int q;
	for (q=0; q<SE && z.info_s.surname[q]!='\n' && z.info_s.surname[q]!='\0'; q++)
		printf ("%c", z.info_s.surname[q]);
	if (q<SE)
		for ( ; q<SE; q++)
			printf (" ");
	printf (" %c.", z.info_s.name[0]);
	printf (" %c.", z.info_s.father_name[0]);
	printf ("\nocenki za ekzameni po porjadky: ");
	if (b==1)
		for (q=0; q<M; q++)
			printf (" %d", z.info_r.sem1[q]);
	if (b==2)
		for (q=0; q<B; q++)
			printf (" %d", z.info_r.sem2[q]);
}
int main (int argc, char **argv)
{
	int i, j, k[N];
	info p[N];					//p - pointer
	for (i=0; i<N; i++)			//ввод данных
	{
		fflush (stdin);
		printf ("vvedite familijy %d studenta: ", i+1);
		fgets (p[i].info_s.surname, SE, stdin);
		fflush (stdin);
		printf ("vvedite imja %d studenta: ", i+1);
		fgets (p[i].info_s.name, NE, stdin);
		fflush (stdin);
		printf ("vvedite otchestvo %d studenta: ", i+1);
		fgets (p[i].info_s.father_name, FE, stdin);
		for (j=0; j<1; )
		{
			printf ("za 1 ili 2 semestr ocenki? ");
			if (!scanf ("%d", &k[i]) || (k[i]!=1 && k[i]!=2))
				fflush (stdin);
			else j++;
		}
		for (j=0; ; )
		{
			printf ("vvedite ocenky za %d ekzamen %d studenta: ", j+1, i+1);
			if (!scanf ("%d", &(p[i].info_r.sem1[j])) || p[i].info_r.sem1[j]<0 || p[i].info_r.sem1[j]>10)
				fflush (stdin);
			else j++;
			if (k[i]==1 && j>=M) break;
			if (k[i]==2 && j>=B) break;
		}
	}
	switch (read_argument(argc, argv))
	{
		case '1': 
			j=1;
			break;
		case '2': 
			j=2;
			break;
		case '3':
			j=3;
			break;
		default:
			printf("\niz komandnoi stroki ne polycheni vernii zapros.");
			return 0;
	}
	for (i=0; i<N; i++)
		if (j==k[i])
			flist_1(k[i], p[i]);
}