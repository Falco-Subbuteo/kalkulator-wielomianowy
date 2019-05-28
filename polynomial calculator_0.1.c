#include <stdio.h>
#include <stdlib.h>

int p, reg1[21]={0}, reg2[21]={0}, reg3[21]={0};

void quit(){
	printf("Kalkulator wielomianowy\nBartlomiej Sokolowski\n2019\nbartlomiej_sokolowski@poczta.pl\n");
}

int add(){
	int poly1[21]={0}, poly2[21]={0}, ifreg, num, i, s;
	
	//Pierwszy wielomian.
	do{
		printf("Czy wykorzystasz rejestr (1 - tak, 0 - nie)?\n");
		scanf("%i", &ifreg);
	} while (ifreg != 1 || ifreg != 0);
	if (ifreg=1) {
		do {
			printf("Który rejestr?\n");
			scanf("%i", &num)
			if (num = 1){
				for (i=0; i<21; i++){
					poly1[i] = reg1[i];
				}
			} else if (num = 2){
				for (i=0; i<21; i++){
					poly1[i] = reg2[i];
				}
			} else if (num = 3){
				for (i=0; i<21; i++){
					poly1[i] = reg3[i];
				} 
			} else {
				printf("Nieprawidlowy numer rejestru!\n");
			}
		} while (num != 1 || num != 2 || num != 3);
	} else {
		do {	
			printf("Wprowadz stopien wielomianu.\n");
			scanf("%i", &s);
		} while (s<20);
		printf("Podaj wspolczynniki wielomianu.\n");
		for (i=s; i>=0; i--){
			scanf("%i", &poly1[i]);
		}
	}
	
	//Drugi wielomian
	do{
		printf("Czy wykorzystasz rejestr (1 - tak, 0 - nie)?\n");
		scanf("%i", &ifreg);
	} while (ifreg != 1 || ifreg != 0);
	if (ifreg=1) {
		do {
			printf("Który rejestr?\n");
			scanf("%i", &num)
			if (num = 1){
				for (i=0; i<21; i++){
					poly2[i] = reg1[i];
				}
			} else if (num = 2){
				for (i=0; i<21; i++){
					poly2[i] = reg2[i];
				}
			} else if (num = 3){
				for (i=0; i<21; i++){
					poly2[i] = reg3[i];
				} 
			} else {
				printf("Nieprawidlowy numer rejestru!\n");
			}
		} while (num != 1 || num != 2 || num != 3);
	} else {
		do {	
			printf("Wprowadz stopien wielomianu.\n");
			scanf("%i", &s);
		} while (s<21);
		printf("Podaj wspolczynniki wielomianu.\n");
		for (i=s; i>=0; i--){
			scanf("%i", &poly2[i]);
		}
	}
	
	int poly3[21]={0};
	for (i=0; i<21; i++){
		poly3[i] = poly1[i]+poly2[i];
	}
	
	return poly3;
}

int subtract(){
	int poly1[21]={0}, poly2[21]={0}, poly3[21]={0}, s1, s2, i;
	
	printf("Podaj stopien pierwszego wielomianu.\n");
	scanf("%i", &s1);
	printf("Podaj wspolczynniki pierwszego wielomianu.\n");
	for (i=s1; i>=0; i--){
		scanf("%i", &poly1[i]);
	}
	for (i=20; i>0; i--){
		if (poly1[i] != 0){
			printf("%ix^%i + ", poly1[i], i );
		}
	}
	printf("%i\n\n", poly1[0]);
	
	printf("Podaj stopien drugiego wielomianu.\n");
	scanf("%i", &s2);
	printf("Podaj wspolczynniki drugiego wielomianu.\n");
	for (i=s2; i>=0; i--){
		scanf("%i", &poly2[i]);
	}
	for (i=20; i>0; i--){
		if (poly2[i] != 0){
			printf("%ix^%i + ", poly2[i], i );
		}
	}
	printf("%i\n\n", poly2[0]);
	
	
	for (i=0; i<21; i++){
		poly3[i]=poly1[i]-poly2[i];
	}
	
	printf("Wynik: ");
	for (i=20; i>0; i--){
		if (poly3[i] != 0){
			printf("%ix^%i + ", poly3[i], i );
		}
	}
	printf("%i\n\n", poly3[0]);
	
	return poly3;
}

int multiply(){
	int poly1[21]={0}, poly2[21]={0}, poly3[21]={0}, s1, s2, s3, i, j;
	
	printf("Podaj stopien pierwszego wielomianu.\n");
	scanf("%i", &s1);
	printf("Podaj wspolczynniki pierwszego wielomianu.\n");
	for (i=s1; i>=0; i--){
		scanf("%i", &poly1[i]);
	}
	
	if (p != 0){
		for (i=0; i<21; i++){
			poly1[i]=poly1[i]%p;
		}
	}
	
	for (i=20; i>0; i--){
		if (poly1[i] != 0){
			printf("%ix^%i + ", poly1[i], i );
		}
	}
	printf("%i\n\n", poly1[0]);
	
	printf("Podaj stopien drugiego wielomianu.\n");
	scanf("%i", &s2);
	printf("Podaj wspolczynniki drugiego wielomianu.\n");
	for (i=s2; i>=0; i--){
		scanf("%i", &poly2[i]);
	}
	for (i=20; i>0; i--){
		if (poly2[i] != 0){
			printf("%ix^%i + ", poly2[i], i );
		}
	}
	printf("%i\n\n", poly2[0]);
	
	
	for (i=0; i<=s1; i++){
		for (j=0; j<=s2; j++){
			poly3[i+j]=poly3[i+j]+poly1[i]*poly2[j];
		}
	}
	
	printf("Wynik: ");
	for (i=20; i>0; i--){
		if (poly3[i] != 0){
			printf("%ix^%i + ", poly3[i], i );
		}
	}
	printf("%i\n\n", poly3[0]);
	
	return poly3;
}

int divide(){
	//todo
}

int modulo(){
	//todo
}
	
	
	

int main(){
	
	printf("S O K O L O W S K I ' S   P O L Y N O M I A L   C A L C U L A T O R\n\n\n");
	
	printf("UWAGA! Program obsluguje wielomiany max. 20 stopnia!\n");
	printf("Podaj podstawe modularna do obliczen (0 dla liczb rzeczywistych).\n");
	do {
		scanf("%i", &p);
		if (p<0){
			printf("Podstawa modularna musi byc nieujemna!\n");
		}
	} while (p>0);
	
	int choice, s1, s2, i, reg1, reg2;
	int poly1[21]={0}
	int poly2[21]={0};
	int poly3[21]={0};
	
	printf("Podaj stopien pierwszego wielomianu.\n");
	scanf("%i", &s1);
	printf("Podaj wspolczynniki wielomianu.\n");
	for (i=s1; i>=0; i--){
		scanf("%i", &poly1[i]);
	}
	
	printf("Podaj stopien drugiego wielomianu.\n");
	scanf("%i", &s2);
	printf("Podaj wspolczynniki wielomianu.\n");
	for (i=s2; i>=0; i--){
		scanf("%i", &poly2[i]);
	}
	
	do{
		printf("Co moge dla Ciebie zrobic?\n");
		printf("0) zerowanie rejestru\n1) dodawanie\n2) odejmowanie\n 3) mnozenie\n\
4) dzielenie\n5) dzielenie modulo\n6) zapisz do rejestru\n7) pokaz rejestr\n8) wyjdz\n\n");
		
		switch (choice){
			case 0:
				
				break;
			case 1:
				add();
				break;
			case 2:
				subtract();
				break;
			case 3:
				multiply();
				break;
			case 4:
				divide();
				break;
			case 5:
				modulo();
				break;
			case 6:
				
				break;
			case 7:
				
				break;
			case 8:
				quit();
				break;
			default:
				printf("Nieprawid³owy numer operacji!\n\n");
				break;
		} 
	} while (choice != 8);
		
	
	return 0;
}
