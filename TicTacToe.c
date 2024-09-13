// Final project, Tic Tac Toe.
#include <stdio.h>

int print_board(char board[3][3]);  // prints the board.
int check_cells(char board[3][3]);  // checks if the board is full.
int check_win(char board[3][3], char player1[15], char player2[15]);    // checks win conditions.

int main(void)
{
// Large title of the game.
    printf("TTTTTTTT    IIIIIIII      CCC      TTTTTTTT      A       CCC      TTTTTTTT      OOO      EEEEEEEE\n   TT          II       C             TT       A  A    C             TT       O     O    E\n   TT          II       C             TT      A __ A   C             TT       O     O    EEEE\n   TT          II       C             TT     A      A  C             TT       O     O    E\n   TT       IIIIIIII      CCC         TT    A        A   CCC         TT         OOO      EEEEEEEE\n");
    printf("__________________________________________________________________________________________________\n\n");
    char board[3][3] = {' '}, player1[15]={' '}, player2[15]={' '};
    int i = 0, j = 0, rep = 0, x = 0, y = 0, check = 0, flag = 0;
// Rules text.
    printf("______________________________________________RULES______________________________________________\n");
    printf(" - Enter the names of the 2 players at the start of the game; player 1 is X and player 2 is O.\n - Players will take turns, as indicated by their names.\n - The player must enter the coordinate of the cell separated by a space, first column then row, e.g., 1 2.\n - A player wins by aligning 3 of their symbols horizontally, vertically, or diagonally.\n - The game ends when the board is full.\n");

// Scan player names.
    printf("PLAYER 1 NAME: ");
    fgets(player1, 15, stdin);
    printf("PLAYER 2 NAME: ");
    fgets(player2, 15, stdin);
    do  // loop that allows playing again.
    {
        flag = 0;
        for (i = 0; i < 3; i++)    // clear the board and reset flag.
        {
            for (j = 0; j < 3; j++)
            {
                board[i][j] = ' ';
            }
        }
        do  // Loop to start the game.
        {
            // instructions for player 1.
            print_board(board);
            printf("TURN OF 'X' %s", player1);
            scanf("%d %d", &x, &y);
            do  // loop that checks if the values entered are within the board and not occupied.
            {
                if ((x > 3 || y > 3 || x < 1 || y < 1) || (board[y-1][x-1] == 'X' || board[y-1][x-1] == 'O'))
                {
                    do  // checks if the values are within the board.
                    {
                        if (x > 3 || y > 3 || x < 1 || y < 1)
                        {
                            printf("ERROR: VALUE OUT OF RANGE\n");
                            printf("TURN OF %s", player1);
                        }
                        else
                        {
                            break;
                        }
                        scanf("%d %d", &x, &y);
                    } while (rep != 3);
                
                    do  // checks if the chosen cell is not occupied.
                    {
                        if (board[y-1][x-1] == 'X' || board[y-1][x-1] == 'O')
                        {
                            printf("CHOOSE A FREE CELL\n");
                        }
                        else
                        {
                            break;
                        }
                        scanf("%d %d", &x, &y);
                    } while (rep != 3);
                }
                else
                {
                    break;
                }
            } while (rep != 3);
            board[y-1][x-1] = 'X';
            
            flag = check_win(board, player1, player2);
            if (flag == 1)
            {
                print_board(board);
                printf("\nCONGRATULATIONS %s\n", player1);
                printf("██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗██╗███╗   ██╗\n╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██║████╗  ██║\n ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║\n  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║██║╚██╗██║\n   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║\n   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝\n");
                break;
            }
            if (flag == 2)
            {
                print_board(board);
                printf("\nCONGRATULATIONS %s\n", player2);
                printf("██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗██╗███╗   ██╗\n╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██║████╗  ██║\n ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║\n  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║██║╚██╗██║\n   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║\n   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝\n");
                break;
            }
            
            flag = check_cells(board);
            if (flag == 3)
            {
                print_board(board);
                printf("THE BOARD IS FULL.");
                printf("██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗ \n██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗\n██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝\n██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗\n╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║\n ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝\n");
                break;
            }
            
    // instructions for player 2.
            print_board(board);
            printf("TURN OF 'O' %s", player2);
            scanf("%d %d", &x, &y);
            do  // loop that checks if the values entered are within the board and not occupied.
            {
                if ((x > 3 || y > 3 || x < 1 || y < 1) || (board[y-1][x-1] == 'X' || board[y-1][x-1] == 'O'))
                {
                    do  // checks if the values are within the board.
                    {
                        if (x > 3 || y > 3 || x < 1 || y < 1)
                        {
                            printf("ERROR: VALUE OUT OF RANGE\n");
                            printf("TURN OF %s", player2);
                        }
                        else
                        {
                            break;
                        }
                        scanf("%d %d", &x, &y);
                    } while (rep != 3);
                
                    do  // checks if the chosen cell is not occupied.
                    {
                        if (board[y-1][x-1] == 'X' || board[y-1][x-1] == 'O')
                        {
                            printf("CHOOSE A FREE CELL\n");
                        }
                        else
                        {
                            break;
                        }
                        scanf("%d %d", &x, &y);
                    } while (rep != 3);
                }
                else
                {
                    break;
                }
            } while (rep != 3);
            board[y-1][x-1] = 'O';
            
            flag = check_win(board, player1, player2);
            if (flag == 1)
            {
                print_board(board);
                printf("\nCONGRATULATIONS %s\n", player1);
                printf("██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗██╗███╗   ██╗\n╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██║████╗  ██║\n ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║\n  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║██║╚██╗██║\n   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║\n   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝\n");
                break;
            }

            if (flag == 2)
            {
                print_board(board);
                printf("\nCONGRATULATIONS %s\n", player2);
                printf("██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗██╗███╗   ██╗\n╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██║████╗  ██║\n ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║\n  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║██║╚██╗██║\n   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║\n   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝\n");
                break;
            }
    
            flag = check_cells(board);
            if (flag == 3)
            {
                print_board(board);
                printf("THE BOARD IS FULL.\n");
                printf("██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗ \n██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗\n██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝\n██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗\n╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║\n ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝\n");

                break;
            }
            
        } while (rep != 3);
        
        printf("WOULD YOU LIKE TO PLAY AGAIN? Yes (1) No (0)\n");
        scanf("%d", &rep);
        
        if (rep == 0)
        {
            printf("\nTHANK YOU FOR PLAYING!\n");
            break;
        }
    } while (rep == 1);

    return 0;
}

int print_board(char board[3][3])  // prints the board.
{
    printf("\t\t\t _______1_______________2_______________3________\n");
    for (int i = 0; i < 3; i++)
    {
        printf("\t\t\t%d|", i+1);

        for (int j = 0; j < 3; j++)
        {
            printf("\t%c\t|", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int check_cells(char board[3][3])  // checks if the board is full.
{
    // checks if cells are filled.
    int count = 0, flag = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'X' || board[i][j] == 'O') // If cells are filled, count increases.
            {
                count++;
            }
        }
    }
    if (count == 9)       // if the board is full, flag is 3 and the game ends.
    {
        flag = 3;
    }
    return flag;
}

int check_win(char board[3][3], char player1[15], char player2[15]) // checks win conditions.
{
    // All win conditions are checked; the value of flag is returned.
    // if flag is 1, player 1 won; if 2, player 2 won.
    int flag = 0;
    
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')      // diagonal1 player1
    {
        flag = 1;
        return flag;
    }
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')      // diagonal1 player2
    {
        flag = 2;
        return flag;
    }
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')      // diagonal2 player1
    {
        flag = 1;
        return flag;
    }
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')      // diagonal2 player2
    {
        flag = 2;
        return flag;
    }
    
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')      // row player1
        {
            flag = 1;
            return flag;
        }
        if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')      // row player2
        {
            flag = 2;
            return flag;
        }
        if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')      // column player1
        {
            flag = 1;
            return flag;
        }
        if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')      // column player2
        {
            flag = 2;
            return flag;
        }
    }
    return flag;
}