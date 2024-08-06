#include <stdio.h>

int main() {
    float num1,num2;
    char ch = 'y',s = 'n';
    while(ch=='y' || ch=='Y')
    {
        char op;
        if(s=='n')
        {
            printf("\nEnter the first number : ");
            scanf("%f",&num1);
            printf("Enter the second number : ");
            scanf("%f",&num2);
        }
        printf("Which opearion do you want to perform (+,-,*,/) : ");
        scanf(" %c",&op);
        switch(op)
        {
            case '+':
                printf("Addition of %0.2f and %0.2f is %0.2f ",num1,num2,(num1+num2));
                break;
            case '-':
                printf("Substration of %0.2f and %0.2f is %0.2f ",num1,num2,(num1-num2));
                break;
            case '*':
                printf("Multiplication of %0.2f and %0.2f is %0.2f ",num1,num2,(num1*num2));
                break;
            case '/':
                if(num2==0)
                {
                    printf("There is a error : Division by zero");
                    break;
                }
                else
                {
                    printf("Division of %0.2f and %0.2f is %0.2f ",num1,num2,(num1/num2));
                    break;
                }
            default:
                printf("Enter valid operator");
                break;
        }
        printf("\n\nDo you want to continue (y/n) : ");
        scanf(" %c",&ch);
        if(ch=='y')
        {
            printf("do you perform operation on same number (y/n) : ");
            scanf(" %c",&s);
        }
    }
}