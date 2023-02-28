#include <stdio.h>
#include <stdlib.h>

/**
 * @brief The function below displays an i by j array and fills each field with a horizontal line and a space.
 *
 * @param size - the size of the game board
 * @param board - the game board with all the moves done until now
 */

void print_board(int size, char board[size][size])
{
    int i, j;
    printf("\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if(board[i][j] == ' ') printf("- ");
            else printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief The function below switches from one player's turn to another.
 *
 * @param size - the size of the game board
 * @param board - the game board with all the moves done until now
 * @param symbol - symbol (x or 0) of the current player
 */

void player_turn(int size, char board[size][size], char symbol)
{
    int row, col;
    while (1) {
        printf("\nPlayer %c's turn. Type the row and column where you want to insert the symbol (eg: 2 3): \n", symbol);
        scanf("%d %d", &row, &col);
        row--;
        col--;
        if(row<0||row>=size||col<0||col>=size)
        {
            printf("\nInvalid position!\n");
        }
        else if(board[row][col]!=' ')
        {
            printf("\nAlready filled position!\n");
        }
        else {
            board[row][col] = symbol;
            break;
        }
    }
}

/**
 * @brief The function below shows us if there is a winning player, that is, if a symbol appears 3 or 4 times in a row, column or diagonal.
 *
 * @param size - the size of the game board
 * @param board - the game board with all the moves done until now
 * @param symbol - symbol (x or 0) of the current player
 * @return int - when it meets the conditions, i.e. the count variable becomes 3 or 4, depending on the case, the function returns the value 1, meaning there
 is a player who won, the one who is in turn, otherwise it returns the value 0, which means the game goes on, there is no winner at the moment
 */

int check_win(int size, char symbol, char board[size][size])
{
    // Check rows
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == symbol)
                count++;
            if(count==size && size==3)
                return 1;
            if(size>3 && count==4)
                return 1;
        }
    }

    // Check columns
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (board[j][i] == symbol)
                count++;
            if(count==size && size==3)
                return 1;
            if(size>3 && count==4)
                return 1;
        }
    }

    // Check diagonals
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (board[i][i] == symbol)
            count++;
    }
    if(count==size && size==3)
        return 1;
    if(size>3 && count==4)
        return 1;

    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (board[i][size-i-1] == symbol)
            count++;
    }
    if(count==size && size==3)
        return 1;
    if(size>3 && count==4)
        return 1;

    return 0;
}

/**
 * @brief If there are no more free fields and there is no winner, then the game will decide that it is a tie
 *
 * @param size - the size of the game board
 * @param board - the game board with all the moves done until now
 * @return int - if there are still free spaces, the function returns 0, meaning nothing; If there is no more free space and previously the function that
determines the winner did not return anything, then the tie function will return 1, that is, declare the game ended in a tie.
 */

int check_draw(int size, char board[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

/**
 * @brief This function will read the size of the game board entered by the players, according to their own preferences, and construct a square matrix of
that size. It will initialize the symbol with X, that is the starting player and will display the game board, as well as each player's turn. It checks then
if one of the players has won, and if so, displays the game board and a message related. For the last time it checks if there is a tie.
 *
 * @return int - in the loop of the main function, after calling the functions in their logical order, after each winner or tie check, if it is affirmative,
the game board is displayed again with the help of the function, and a related message; after that, the main function returns 0 (it exits the loop), and at
the end another 'return 0' is written to stop the program from running, because the game is finished
 */
int main()
{
    int size;
    printf("Choose the size of the game board (eg: 3): ");
    scanf("%d", &size);
    char board[size][size];
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            board[i][j] = ' ';
        }
    }
    char symbol = 'X';
    int row, col;
    while (1)
    {
        print_board(size, board);
        player_turn(size, board, symbol);
        if(check_win(size, 'X', board))
        {
            print_board(size, board);
            printf("Player X wins!");
            return 0;
        }
        if(check_win(size, 'O', board))
        {
            print_board(size, board);
            printf("Player O wins!");
            return 0;
        }
        if(check_draw(size, board))
        {
            print_board(size, board);
            printf("Draw!");
            return 0;
        }

        if (symbol == 'X')
        {
            symbol = 'O';
        }
        else
        {
            symbol = 'X';
        }
    }
    return 0;
}
