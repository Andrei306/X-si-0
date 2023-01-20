#include <stdio.h>
#include <windows.h>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

/* V1
void print_board()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("\%c ", board[i][j]);
        }
        printf("\n");
    }
}
*/


/* V2
void print_board()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 0 | BACKGROUND_BLUE);
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
*/

void print_board()
{
    printf("\t\t\t\t\t     |     |     \n");
    printf("\t\t\t\t\t  %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2]);

    printf("\t\t\t\t\t_____|_____|_____\n");
    printf("\t\t\t\t\t     |     |     \n");

    printf("\t\t\t\t\t  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);

    printf("\t\t\t\t\t_____|_____|_____\n");
    printf("\t\t\t\t\t     |     |     \n");

    printf("\t\t\t\t\t  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);

    printf("\t\t\t\t\t     |     |     \n\n");
}


void player_turn(char player_symbol)
{
    int location;
    printf("\n\t\t\tJucatorul %c, tasteaza o cifra pentru a plasa simbolul: ", player_symbol);
    scanf("%d", &location);
    printf("\n");

    if (location == 1)
    {
        if (board[0][0] == '1')
        {
            board[0][0] = player_symbol;
        }
        else
        {
            printf("\n\t\t\t\t\tAcel camp este deja ocupat!\n");
            player_turn(player_symbol);
        }
    }
    else if (location == 2)
    {
        if (board[0][1] == '2')
        {
            board[0][1] = player_symbol;
        }
        else
        {
            printf("\n\t\t\t\t\tAcel camp este deja ocupat!\n");
            player_turn(player_symbol);
        }
    }
    if (location == 3)
    {
        if (board[0][2] == '3')
        {
            board[0][2] = player_symbol;
        }
        else
        {
            printf("\n\t\t\t\t\tAcel camp este deja ocupat!\n");
            player_turn(player_symbol);
        }
    }
    if (location == 4)
    {
        if (board[1][0] == '4')
        {
            board[1][0] = player_symbol;
        }
        else
        {
            printf("\n\t\t\t\t\tAcel camp este deja ocupat!\n");
            player_turn(player_symbol);
        }
    }
    if (location == 5)
    {
        if (board[1][1] == '5')
        {
            board[1][1] = player_symbol;
        }
        else
        {
            printf("\n\t\t\t\t\tAcel camp este deja ocupat!\n");
            player_turn(player_symbol);
        }
    }
    if (location == 6)
    {
        if (board[1][2] == '6')
        {
            board[1][2] = player_symbol;
        }
        else
        {
            printf("\n\t\t\t\t\tAcel camp este deja ocupat!\n");
            player_turn(player_symbol);
        }
    }
    if (location == 7)
    {
        if (board[2][0] == '7')
        {
            board[2][0] = player_symbol;
        }
        else
        {
            printf("\n\t\t\t\t\tAcel camp este deja ocupat!\n");
            player_turn(player_symbol);
        }
    }
    if (location == 8)
    {
        if (board[2][1] == '8')
        {
            board[2][1] = player_symbol;
        }
        else
        {
            printf("\n\t\t\t\t\tAcel camp este deja ocupat!\n");
            player_turn(player_symbol);
        }
    }
    if (location == 9)
    {
        if (board[2][2] == '9')
        {
            board[2][2] = player_symbol;
        }
        else
        {
            printf("\n\t\t\t\t\tAcel camp este deja ocupat!\n");
            player_turn(player_symbol);
        }
    }
}

int check_win(char symbol)
{
    // Verific randurile
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
        {
            return 1;
        }
    }

    // Verific coloanele
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
        {
            return 1;
        }
    }

    // Verific diagonalele
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
    {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
    {
        return 1;
    }

    return 0;
}

int check_draw()
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'X' || board[i][j] == '0')
            {
                count++;
            }
        }
    }
    if (count == 9 && check_win('X') == 0 && check_win('0') == 0)
    {
        return 1;
    }
    return 0;
}


int main()
{
    printf("\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb Bun venit la X si 0! \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
    print_board();

    while (1)
    {
        player_turn('X');
        if (check_draw() == 1)
        {
            printf("\n\t\t\t\t\t\tEgalitate!\n");
            return 0;
        }
        print_board();
        if (check_win('X') == 1)
        {
            printf("\n\t\t\t\t\tJucatorul X a castigat!\n");
            return 0;
        }
        if (check_win('0') == 1)
        {
            printf("\n\t\t\t\t\tJucatorul 0 a castigat!\n");
            return 0;
        }
        player_turn('0');
        if (check_draw() == 1)
        {
            printf("\n\t\t\t\t\t\tEgalitate!\n");
            return 0;
        }
        print_board();
        if (check_win('X') == 1)
        {
            printf("\n\t\t\t\t\tJucatorul X a castigat!\n");
            return 0;
        }
        if (check_win('0') == 1)
        {
            printf("\n\t\t\t\t\tJucatorul 0 a castigat!\n");
            return 0;
        }

    }
    return 0;
}
