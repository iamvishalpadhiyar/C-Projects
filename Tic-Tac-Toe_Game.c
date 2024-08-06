#include <stdio.h>

void intro();
void display(char *game);
int play(char *game);

int main() {
    char game[9] = {'1','2','3','4','5','6','7','8','9'};
    intro();
    display(game);
    play(game);
    return 0;
}

void intro() {
    printf("\n\nTic Tac Toe Game : \n\n");
    printf("How to Play --->\n");
    printf("First player starts with O and then the second plays X.\n");
    printf("Players need to give the number of the place to put O and X.\n\n");
}

void display(char *game) {
    int i, j;
    int x = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c\t",game[x]);
            x++;
        }
        printf("\n\n");
    }
}

int play(char *game) {
    int pos;
    char ch = 'y';
    int cnt;

    while (ch == 'y' || ch == 'Y') {
        for (cnt = 1; cnt <= 9; cnt++) {
            printf("Enter the position: ");
            scanf("%d", &pos);

            if (game[pos - 1] == 'X' || game[pos - 1] == 'O') {
                printf("Position already taken. Try again.\n");
                cnt--;
                continue;
            }

            if (cnt % 2 == 0) {
                game[pos - 1] = 'X';
            } else {
                game[pos - 1] = 'O';
            }

            display(game);

            if( (game[0] == 'X' && game[1] == 'X' && game[2] == 'X') || (game[3] == 'X' && game[4] == 'X' && game[5] == 'X') ||
                (game[6] == 'X' && game[7] == 'X' && game[8] == 'X') || (game[0] == 'X' && game[3] == 'X' && game[6] == 'X') ||
                (game[1] == 'X' && game[4] == 'X' && game[7] == 'X') || (game[2] == 'X' && game[5] == 'X' && game[8] == 'X') || 
                (game[0] == 'X' && game[4] == 'X' && game[8] == 'X') || (game[2] == 'X' && game[4] == 'X' && game[6] == 'X')) 
                {
                    printf("Player 2 ('X') is the Winner\n\n");
                    break;
                } 
            else if(   (game[0] == 'O' && game[1] == 'O' && game[2] == 'O') || (game[3] == 'O' && game[4] == 'O' && game[5] == 'O') ||
                       (game[6] == 'O' && game[7] == 'O' && game[8] == 'O') || (game[0] == 'O' && game[3] == 'O' && game[6] == 'O') ||
                       (game[1] == 'O' && game[4] == 'O' && game[7] == 'O') || (game[2] == 'O' && game[5] == 'O' && game[8] == 'O') || 
                       (game[0] == 'O' && game[4] == 'O' && game[8] == 'O') || (game[2] == 'O' && game[4] == 'O' && game[6] == 'O'))
                        {
                            printf("Player 1 ('O') is the Winner\n\n");
                            break;
                        } 
            else if (cnt == 9) 
            {
                printf("Game Draw\n\n");
                break;
            }
        }
        printf("Do you want to play again (y/n): ");
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y') {
            for (int i = 0; i < 9; i++) {
                game[i] = '1' + i;
            }
            display(game);
        }
    }
    return 0;
}
