#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int winner_check(char arr[][3])
{

    for (int i = 0; i < 3; i++)
    {
        // For vertical
        if (arr[0][i] == 'X' && arr[1][i] == 'X' && arr[2][i] == 'X')
        {
            return 2;
        }
        // For Horizontal
        else if (arr[i][0] == 'X' && arr[i][1] == 'X' && arr[i][2] == 'X')
        {
            return 2;
        }

        // For vertical
        if (arr[0][i] == 'O' && arr[1][i] == 'O' && arr[2][i] == 'O')
        {
            return 1;
        }
        // For Horizontal
        else if (arr[i][0] == 'O' && arr[i][1] == 'O' && arr[i][2] == 'O')
        {
            return 1;
        }
    }
    // For Diagonal
    if ((arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X') || (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X'))
    {
        return 2;
    }

    if ((arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O') || (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O'))
    {
        return 1;
    }

    return 3;
}

int scan_arr(char arr[][3], int index[][2])
{

    int m = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == ' ')
            {
                index[m][0] = i;
                index[m][1] = j;
                m = m + 1;
            }
        }
    }
    return m;
}
void display_arr(char arr[][3])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("  %c  |", arr[i][j]);
        }
        printf("\n------------------\n");
    }
    printf("\n\n");
}

void get_player_move(char arr[][3])
{
    int i, j;
    printf("Your turn hehe\n");
    printf("Enter your move: ");
    scanf("%d, %d", &i, &j);
    if (arr[i - 1][j - 1] == ' ') {
    arr[i - 1][j - 1] = 'O';
    }
    else {
        printf("\nWrong move , dont waste my time play again\n\n");
        get_player_move(arr);
    }
}

int get_computer_smarter_move(char arr[][3])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = j + 1; k < 3; k++)
            {   if ((i == 0) && (arr[j][j] == arr[k][k]) &&(arr[j][j] =='X') && (arr[3-(k + j)][3-(k + j)] == ' '))
                {
                    arr[3-(k + j)][3-(k + j)] = 'X';
                    return 1;
                }
                else if ((i == 0) && (arr[j][2-j] == arr[k][2-k]) &&(arr[j][2-j] =='X') && (arr[3-(k + j)][k+j-1] == ' '))
                {
                    arr[3-(k + j)][k+j-1] = 'X';
                    return 1;
                }
                else if ((arr[j][i] == arr[k][i]) &&(arr[j][i] =='X') && (arr[3-(k + j)][i] == ' '))
                {
                    arr[3-(k + j)][i] = 'X';
                    return 1;
                }
                else if ((arr[i][j] == arr[i][k]) &&(arr[i][j] =='X') && (arr[i][3-(k + j)] == ' '))
                {
                    arr[i][3-(k + j)] = 'X';
                    return 1;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = j + 1; k < 3; k++)
            {   if ((i == 0) && (arr[j][j] == arr[k][k]) &&(arr[j][j] =='O') && (arr[3-(k + j)][3-(k + j)] == ' '))
                {
                    arr[3-(k + j)][3-(k + j)] = 'X';
                    return 1;
                }
                else if ((i == 0) && (arr[j][2-j] == arr[k][2-k]) &&(arr[j][2-j] =='O') && (arr[3-(k + j)][k+j-1] == ' '))
                {
                    arr[3-(k + j)][k+j-1] = 'X';
                    return 1;
                }
                else if ((arr[j][i] == arr[k][i]) &&(arr[j][i] =='O') && (arr[3-(k + j)][i] == ' '))
                {
                    arr[3-(k + j)][i] = 'X';
                    return 1;
                }
                else if ((arr[i][j] == arr[i][k]) &&(arr[i][j] =='O') && (arr[i][3-(k + j)] == ' '))
                {
                    arr[i][3-(k + j)] = 'X';
                    return 1;
                }
            }
        }
    }
    return 0;
}

int get_computer_move(char arr[][3], const int index[][2], const int m)
{

    // if (arr[1][1] == 'X')
    // {
    //     for (int i = 0; i < 3; i++)
    //     {
    //         for (int j = 0; j < 3; j++)
    //         {
    //             if (arr[i][j] == 'X' && arr[])
    //             {
    //                 /* code */
    //             }

    //         }

    //     }

    // }

    int random = rand() % (m);
    arr[index[random][0]][index[random][1]] = 'X';
    return random;
}

// void check_draw(char arr[][3])
// {

//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             if (arr[i][j] == ' ')
//             {
//                 ;
//             }
//         }
//     }
//     return 0;
// }
int main()
{
    srand(time(0));

    int index_count, first, winner_check_count, consent = 0;
    char arr[][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int index[9][2];

    display_arr(arr);
    printf("Enter 0 if you want computer to play first otherwise enter 1: ");
    scanf("%d", &first);

    while (consent == 0)
    {
        winner_check_count = winner_check(arr);
        index_count = scan_arr(arr, index);
        if (winner_check_count == 3 && index_count != 0 && first == 0)
        {
            if (get_computer_smarter_move(arr) == 1)
            {
                printf("\nComputer plays smartly hehe\n");
                display_arr(arr);
                first = 1;
            }
            else
            {
                int m;
                m = get_computer_move(arr, index, index_count);
                printf("\nComputer Turn hehe\n");
                printf("\nComputer playsss [%d, %d]\n\n", index[m][0] + 1, index[m][1] + 1);
                first = 1;
                display_arr(arr);
            }
        }

        else if (winner_check_count == 3 && index_count != 0 && first == 1)
        {
            get_player_move(arr);
            first = 0;
            display_arr(arr);
        }

        else if (winner_check_count == 1)
        {
            printf("\nPlayer wins yeeeee\n\n");
            display_arr(arr);
            consent = 1;
        }

        else if (winner_check_count == 2)
        {
            printf("\nComputer wins yeeeee\n\n");
            display_arr(arr);
            consent = 1;
        }

        else if (index_count == 0)
        {
            printf("\nDrawww yeeeee\n\n");
            display_arr(arr);
            consent = 1;
        }
    }
    return 0;
}