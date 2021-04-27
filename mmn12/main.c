#include <stdio.h>
#include "data.h"
int path(adjmat matrix,int father,int son);
int main();
typedef int adjmat[N][N];
int path(adjmat matrix,int father,int son)
{
    int flag;
    int step;
    flag = FALSE;
    while(!flag){
       if(son == father)
           return TRUE;
       flag = TRUE;
       for(step = 0; step<N; step++){
           if(matrix[step][son] == 1){
               son = step;
               flag = FALSE;
               break;
           }

       }
    }
    return FALSE;
}
    int main() {
        adjmat mat;
        int Start;
        int End;
        int i;
        int j;
        int result;
        printf("Hello user! please insert %d values for the matrix in the size of %d*%d, the values can be 0 or 1\n",
               N * N,
               N, N);
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                scanf("%d", &mat[i][j]);
                if (j == N - 1)
                    printf("\n");
            }
        }
        printf("Hey again, here is your new matrix\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                printf("%d", mat[i][j]);
                if (j == N - 1)
                    printf("\n");
            }
        }
        while (TRUE) {
            printf("Now, in order to find a path between to nodes in the tree, please enter start node and end node.\n");
            printf("start node is:\n");
            scanf("%d", &Start);
            printf("end node is:\n");
            scanf("%d", &End);
            if (Start == -1 && End == -1)
                break;
            result = path(mat, Start, End);
            if (result == TRUE) {
                printf("Congratulation! there is a path from %d to %d\n", Start, End);
            }
            if (result == FALSE) {
                printf("Oh no, there is no path between %d to %d\n", Start, End);
            }
        }
        return 0;
    }
