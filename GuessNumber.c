#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("\n\nThis is a number guessing game : ");
    printf("\n\nThere are three levels and 7 chance to guess number\n");
    printf("game give the hints that number is more or less.\n");
    printf("First level number between 1 to 10\n");
    printf("second level number between 1 to 100\n");
    printf("Third level number between -100 to 100\n");
    int ch,val,temp,i;
    char n='y';
    while(n=='y' || n=='Y')
    {
        printf("Enter the level : ");
        scanf("%d",&ch);
        if(ch==1)
        {
            srand(time(NULL));
            int val = rand() % 10 + 1;
            for(i=1;i<=7;i++)
            {
                printf("tell the number : ");
                scanf("%d",&temp);
                if(temp==val)
                {
                    printf("Congratulations !\n");
                    printf("You win the game");
                    break;
                }
                else if(temp > val)
                {
                    printf("number less than %d\n",temp);
                }
                else if(temp < val)
                {
                    printf("number greater than %d\n",temp);
                }
            }
            printf("You lost\n");
            printf("Number is %d",val);
        }
        else if(ch==2)
        {
            srand(time(NULL));
            int val = rand() % 100 + 1;
            for(i=1;i<=7;i++)
            {
                printf("tell the number : ");
                scanf("%d",&temp);
                if(temp==val)
                {
                    printf("Congratulations !\n");
                    printf("You win the game");
                    break;
                }
                else if(temp > val)
                {
                    printf("number less than %d\n",temp);
                }
                else if(temp < val)
                {
                    printf("number greater than %d\n",temp);
                }
            }
            printf("You lost\n");
            printf("Number is %d",val);
        }
        else if(ch==3)
        {
            srand(time(NULL));
            int val = rand() % 201 - 100;
            for(i=1;i<=7;i++)
            {
                printf("tell the number : ");
                scanf("%d",&temp);
                if(temp==val)
                {
                    printf("Congratulations !\n");
                    printf("You win the game");
                    break;
                }
                else if(temp > val)
                {
                    printf("number less than %d\n",temp);
                }
                else if(temp < val)
                {
                    printf("number greater than %d\n",temp);
                }
            }
            printf("You lost\n");
            printf("Number is %d",val);
        }
        else
        {
            printf("Enter valid level");
        }
        printf("\nDo you want to play (y/n) : ");
        scanf(" %c",&n);
    }
}