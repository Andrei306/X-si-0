#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Funcția de mai jos afiseaza o matrice de i pe j si in umple fiecare camp cu o linie orizontala si un spatiu.
 * 
 * @param size reprezinta marimea matricii
 * @param board este un vector bidimensional, care reprezinta o matrice cu size randuri si size coloane
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
 * @brief Functia de mai jos face trecerea de la randul unui jucator la al celuilalt.
Se initializeaza 2 variabile row si col, si bucla cu randul jucatorilor se repeta pana la o conditie data. Se afiseaza randul cui jucator e, in functie
de simbol. Scaneaza randul si coloana pentru a determina pozitia unde se doreste a fi plasat simbolul, si in caz ca acel camp este invalid (minim un numar
din cele 2 inserate depaseste valoarea lui size) sau in caz ca este ocupat deja (este diferit de un spatiu gol), functia returneaza 2 mesaje sugestive.
Altfel, functia plaseaza simbolul jucatorului al carui rand este pe pozitia respectiva in matrice si este folosit break pentru a iesi din aceasta functie
 * 
 * @param size reprezinta marimea matricii
 * @param board este un vector bidimensional, care reprezinta o matrice cu size randuri si size coloane
 * @param symbol reprezinta unul dintre cele 2 simboluri folosite in joc: X sau 0. Asa se face diferenta si intre jucatori, fiecare va avea propriul simbol
 */

void player_turn(int size, char board[size][size], char symbol)
{
    int row, col;
    while (1) {
        printf("\nRandul jucatorului %c. Tasteaza randul si coloana unde vrei sa inserezi simbolul (exemplu: 2 3): \n", symbol);
        scanf("%d %d", &row, &col);
        row--;
        col--;
        if(row<0||row>=size||col<0||col>=size)
        {
            printf("\nPozitie invalida!\n");
        }
        else if(board[row][col]!=' ')
        {
            printf("\nCamp deja ocupat!\n");
        }
        else {
            board[row][col] = symbol;
            break;
        }
    }
}

/**
 * @brief Functia de mai jos ne arata daca exista vreaun castigator, adica daca un simbol apare de 3 sau 4 ori pe rand, coloana sau diagonala. Prima oara se verifica
randurile. Este incrementata o variabila count initializata cu 0 de fiecare data cand apare un simbol pe rand/coloana/diagonala
 * 
 * @param size reprezinta marimea matricii
 * @param symbol reprezinta unul dintre cele 2 simboluri folosite in joc: X sau 0. Asa se face diferenta si intre jucatori, fiecare va avea propriul simbol
 * @param board este un vector bidimensional, care reprezinta o matrice cu size randuri si size coloane
 * @return int cand indeplineste conditiile, adica variabila count devine 3 sau 4, in functie de caz, functia returneaza valoarea 1, adica exista un jucator care
a castigat, cel care este la rand, altfel returneaza valoarea 0, adica jocul merge mai departe, nu exista niciun castigator momentan
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
 * @brief Daca nu mai sunt campuri libere si nu exista niciun castigator, atunci jocul va decide ca este egalitate
 * 
 * @param size reprezinta marimea matricii
 * @param board este un vector bidimensional, care reprezinta o matrice cu size randuri si size coloane
 * @return int daca inca sunt spatii libere, functia returneaza 0, adica nimic; Daca nu mai este niciun spatiu liber si anterior nu a returnat functia care
determina castigatorul nimic, atunci functia de egalitate va returna ea 1, adica declara jocul incheiat la egalitate
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
 * @brief Aceasta functie va citi marimea tablei de joc introdusa de jucatori, dupa propriile preferinte, si va construi o matrice patratica de dimensiunea
respectiva. Va initializa simbolul cu X, acela fiind jucatorul care incepe si va intra intr-o bucla unde va apela functiile de afisare a tablei de joc,
cat si cea pentru randul fiecarui jucator. Verifica dupa daca unul dintre jucatori a castigat, iar in caz afirmativ, afiseaza tabla de joc si un mesaj
aferent. Ultima oara verifica daca este egalitate. Altfel, schimba simbolul curent (din X in 0 sau invers) si repeta bucla: afisare tabla, rand jucator,
verificare castigator/egalitate si asa mai departe
 * 
 * @return int in bucla functiei main, dupa apelarea functiilor in ordinea lor logica, dupa fiecare verificare de castigator sau egalitate, daca este afirmativa,
este afisata din nou tabla de joc cu ajutorul functiei, si un mesaj aferent; dupa aceea functia main returneaza 0, adica iese din bucla, iar la final
este scris inca un return 0 pentru a opri programul din a mai rula, deoarece jocul este incheiat
 */
int main()
{
    int size;
    printf("Alege marimea tablei de joc (exemplu: 3): ");
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
            printf("Jucatorul X a castigat!");
            return 0;
        }
        if(check_win(size, 'O', board))
        {
            print_board(size, board);
            printf("Jucatorul O a castigat!");
            return 0;
        }
        if(check_draw(size, board))
        {
            print_board(size, board);
            printf("Egalitate!");
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
