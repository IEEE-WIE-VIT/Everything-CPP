#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node
{
	int coeff;
	int pow;
	struct Node *next;
}*result;

void readPolynomial(struct Node** poly)
{
	int coeff, exp, cont;
	struct Node *temp ;
	temp = (struct Node*)malloc(sizeof(struct Node));
	*poly = temp;
	do{
		printf("\nCoeffecient: ");
		scanf("%d", &coeff);
		printf("Exponent: ");
		scanf("%d", &exp);
		temp->coeff = coeff;
		temp->pow = exp;
		temp-> next = NULL;
		printf("\nHave more terms? 1 for y and 0 for no: ");
		scanf("%d", &cont);
		if(cont)
		{
			temp->next = (struct Node*)malloc(sizeof(struct Node));
			temp = temp->next;
			temp->next = NULL;
		}
	}while(cont);
}

void displayPolynomial(struct Node* poly)
{
	printf("\nPolynomial expression is: ");
	while(poly != NULL)
	{
		printf("%dX^%d", poly->coeff, poly->pow);
		poly = poly->next;
		if(poly != NULL)
			printf("+");
	}
}

void addPolynomials(struct Node** result, struct Node* first, struct Node* second)
{
 	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 	temp->next = NULL;
 	*result = temp;
 	while(first && second)
 	{
 		if(first->pow > second->pow)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}
 		else if(first->pow < second->pow)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 		else
 		{
 			temp->coeff = first->coeff + second->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 			second = second->next;
 		}

 		if(first && second)
 		{
 			temp->next = (struct Node*)malloc(sizeof(struct Node));
 			temp = temp->next;
 			temp->next = NULL;
 		}
 	}
 	while(first || second)
 	{
 		temp->next = (struct Node*)malloc(sizeof(struct Node));
 		temp = temp->next;
 		temp->next = NULL;

 		if(first)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}

 		else if(second)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 	}
}

int main()
{   clrscr();
    int ch;
    while(1)
    {
    printf("\n1.Enter 2 polynomials\n2.Exit\n");
	printf("Enter your choice: ");
	scanf("%d",&ch);
	if(ch==1)
    {
        struct Node* first = NULL;
        struct Node* second = NULL;
        struct Node* result = NULL;
        printf("\nFirst polynomial:\n");
        readPolynomial(&first);
        displayPolynomial(first);
        printf("\nSecond polynomial:\n");
        readPolynomial(&second);
        displayPolynomial(second);
        addPolynomials(&result, first, second);
        printf("\nRESULT\n");
        displayPolynomial(result);
    }
    else if(ch==2)
    {
        exit(0);
    }
    else
        printf("\nInvalid choice\n");
    }
}
