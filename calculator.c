#include<stdio.h>

int main()
{
    int num1,num2;
    
    printf("\n    :: This is your Calculator ::\n\n");
    printf("Enter number 1 - ");
    scanf("%d",&num1);
    
    printf("Enter number 2 - ");
    scanf("%d",&num2);
    
    int operation;
    printf("\nPlease provide the operation you need to perform :\n");
    printf("\nEnter 1 for Additon ");
    printf("\nEnter 2 for substraction (num1-num2) ");
    printf("\nEnter 3 for Multiplication ");
    printf("\nEnter 4 for Division (num1/num2) ");
    printf("\n\n");
    scanf("%d",&operation);
    printf("\nYour answer is : ");

    if(operation==1)
    {
        printf("%d\n",num1+num2);
    }
    
    if(operation==2)
    {
        printf("%d\n",num1-num2);
    }
    
    if(operation==3)
    {
        printf("%d\n",num1*num2);
    }

    if(operation==4)
    {
        printf("%d\n",num1/num2);
    }
    
    return 0;
}