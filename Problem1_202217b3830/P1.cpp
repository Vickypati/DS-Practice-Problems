#include<stdio.h>
#include<conio.h>
#define MAX 10
/* Define the required functions to create a list, insert into the list,
delete an element from the list, search and display the list */
void create();
void insert();
void deletion();
void search();
void display();
int a,b[20], n, p, e, f, i, pos;
int main()
{
//clrscr();
int ch;
char g='y';
do
{
printf("\nMain Menu");
printf("\n1.Create \n2.Delete \n3.Search \n4.Insert \n5.Display\n6.Exit\n");
printf("\nEnter your Choice:");
scanf("%d", &ch);
/* The following switch will call the appropriate choice provided
by the user */
switch(ch)
{
case 1:
create();
break;
case 2:
deletion();
break;
case 3:
search();
break;
case 4:
insert();
break;
case 5:
display();
break;
case 6:
//Exit
return 0;
break;
default:
printf("\nEnter the correct choice:");
}
printf("\nDo u want to continue:::");
scanf("\n%c", &g);
}
/* The program is intended to run till we provide inputs other that ‘y’
or ‘Y’ */
while(g=='y'||g=='Y');
getch();
}
void create()
{
printf("\nEnter the number of nodes:");
scanf("%d", &n);
/* The loop should run till we get the ‘n’ inputs */
for(i=0;i<n;i++)
{
printf("\nEnter the Element:",i+1);
scanf("%d", &b[i]);
}
}
void deletion()
{
printf("\nEnter the position u want to delete::");
scanf("%d", &pos);
if(pos>=n)
{
printf("\nInvalid Location::");
}
else
{
for(i=pos+1;i<n;i++)
{
b[i-1]=b[i];
}n--;
}
printf("\nThe Elements after deletion:");
for(i=0;i<n;i++)
{
printf("\t%d", b[i]);
}
}
void search()
{
printf("\nEnter element to search: ");
    scanf("%d", &e);

    /* Assume that element does not exists in array */
    int found = 0;
    
    for(i=0; i<n; i++)
    {
        /*
         * If element is found in array then raise found flag
         * and terminate from loop.
         */
        if(b[i] ==e)
        {
            found = 1;
            break;
        }
    }

    /*
     * If element is not found in array
     */
    if(found == 1)
    {
        printf("\n%d is found at position %d",e, i);
    }
    else
    {
        printf("\n%d is not found in the array", e);
    }
}
void insert()
{
printf("\nEnter the position u need to insert::");
scanf("%d", &pos);
if(pos>=n)
{
printf("\nInvalid Location::");
}
else
{
for(i=MAX-1;i>=pos-1;i--)
{
b[i+1]=b[i];
}
printf("\nEnter the element to insert::\n");
scanf("%d",&p);
b[pos]=p;
n++;
}
printf("\nThe list after insertion::\n");
display();
}
void display()
{
printf("\nThe Elements of The list ADT are:");
for(i=0;i<n;i++)
{
printf("\n\n%d", b[i]);
}
}