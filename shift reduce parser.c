#include <stdio.h>
#include <string.h>
int k = 0, z = 0, i = 0, j = 0, c = 0;
char a[50], ac[50], stk[50], act[50];
void check();
int main()
{
    clrscr();
    printf("GRAMMAR is E->E+E \n\t E->E*E \n\t E->(E) \n\t E->id");
    printf("\n\nEnter input string:  ");
    scanf("%s",&a);
    c = strlen(a);
    strcpy(act, "SHIFT->");
    printf("stack \t input \t action");
    for (k = 0, i = 0; j < c; k++, i++, j++)
    {
	if (a[j] == 'i' && a[j + 1] == 'd')
	{
	    stk[i] = a[j];
	    stk[i + 1] = a[j + 1];
	    stk[i + 2] = '\0';
	    a[j] = ' ';
	    a[j + 1] = ' ';
	    printf("\n$%s\t%s$\t%sid", stk, a, act);
	    check();
	}
	else
	{   
	    stk[i] = a[j];
	    stk[i + 1] = '\0';
	    a[j] = ' ';
	    printf("\n$%s\t%s$\t%s%c", stk, a, act, stk[i]);
	    check();
	}
    }
    if(stk[0]=='E'&&stk[1]=='\0')
	printf("\n$%s\t%s$\t ACCEPT",stk,a);
    else
	printf("\n$%s\t%s$\t REJECT",stk,a);
    getch();
    return 0;

}
void check()
{
    strcpy(ac, "REDUCE TO E");
    for (z = 0; z < c; z++)
	if (stk[z] == 'i' && stk[z + 1] == 'd')
	{
	    stk[z] = 'E';
	    stk[z + 1] = '\0';

	    printf("\n$%s\t%s$\t%s->ID", stk, a, ac);
	    j++;
	}
    for (z = 0; z < c; z++)
	if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E')
	{
	    stk[z] = 'E';
	    stk[z + 1] = '\0';
	    stk[z + 2] = '\0';
	    printf("\n$%s\t%s$\t%s->E+E", stk, a, ac);
	    i = i - 2;
	}
    for (z = 0; z < c; z++)
	if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E')
	{
	    stk[z] = 'E';
	    stk[z + 1] = '\0';
	    stk[z + 1] = '\0';
	    printf("\n$%s\t%s$\t%s->E*E", stk, a, ac);
	    i = i - 2;
	}
    for (z = 0; z < c; z++)
	if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')')
	{
	    stk[z] = 'E';
	    stk[z + 1] = '\0';
	    stk[z + 1] = '\0';
	    printf("\n$%s\t%s$\t%s->(E)", stk, a, ac);
	    i = i - 2;
	    check();
	}

}
