#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int isAvailable(int puzzle[][9], int row, int col, int num)
{
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;
    int i, j;

    for(i=0; i<9; ++i)
    {
        if (puzzle[row][i] == num) return 0;
        if (puzzle[i][col] == num) return 0;
        if (puzzle[rowStart + (i%3)][colStart + (i/3)] == num) return 0;
    }
    return 1;
}

int fillSudoku(int puzzle[][9], int row, int col)
{
    int i;
    if(row<9 && col<9)
    {
        if(puzzle[row][col] != 0)
        {
            if((col+1)<9) return fillSudoku(puzzle, row, col+1);
            else if((row+1)<9) return fillSudoku(puzzle, row+1, 0);
            else return 1;
        }
        else
        {
            for(i=0; i<9; ++i)
            {
                if(isAvailable(puzzle, row, col, i+1))
                {
                    puzzle[row][col] = i+1;
                    if((col+1)<9)
                    {
                        if(fillSudoku(puzzle, row, col +1)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else if((row+1)<9)
                    {
                        if(fillSudoku(puzzle, row+1, 0)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

int main()
{
    struct timeval  tv1, tv2;
    clock_t t1,t2;
    int result = 0;
    int i, j;
    int puzzle[9][9]={{0, 0, 0, 0, 6, 0, 0, 8, 0},
                      {0, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 1, 0, 0, 0, 0, 0, 0},
                      {0, 7, 0, 0, 0, 0, 1, 0, 2},
                      {5, 0, 0, 0, 3, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 4, 0, 0},
                      {0, 0, 4, 2, 0, 1, 0, 0, 0},
                      {3, 0, 0, 7, 0, 0, 6, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 5, 0}};
    t1 = clock();
    gettimeofday(&tv1, NULL);
    result = fillSudoku(puzzle, 0, 0);
    t2 = clock();
    gettimeofday(&tv2, NULL);
    double objval = 0.0;
    
    double user_time = (double)(tv2.tv_sec+tv2.tv_usec*1e-6 - (tv1.tv_sec+tv1.tv_usec*1e-6));
    double cpu_time = (double)(t2-t1) / CLOCKS_PER_SEC;

    if(result) {
        printf("\n");
        for(i=1; i<10; ++i) {
            for(j=1; j<10; ++j) 
                printf(" %d", puzzle[i-1][j-1]);
            printf("\n");
        }
        printf("\n");
        printf("user time: %lf \n", user_time);
        printf("cpu  time: %lf \n", cpu_time);
    }
    else printf("\n\nNO SOLUTION\n\n");

    return 0;
}