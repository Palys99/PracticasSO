#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>

int id;

int main(){

    int i;
    int j;
    int row;
    int col;
    int order;

    long T1;
    long T2;
    float delta;

    pid_t process_1;
    pid_t process_2;
    pid_t process_3;
    pid_t process_4;

    printf("Ingrese el orden de las matrices cuadradas A y B: ");
    scanf("%d", &order);

    T1 = clock();

    printf("\nLas matrices cuadradas A y B, son matrices de orden %d",order);

    order = order - 1;

    row = order;
    col = order;

    float A[row+1][col+1];
    float B[row+1][col+1];

    for(i = 0; i <= row; i++){

        for(j = 0; j <= col; j++){

            printf("\n\nIngrese el valor de la matriz A[%d][%d]: ",i+1,j+1);
            scanf("%f", &A[i][j]);

            printf("\nIngrese el valor de la matriz B[%d][%d]: ",i+1,j+1);
            scanf("%f", &B[i][j]);
        }
    }

    printf("\nLa multiplicación de matrices A y B:\n\n");

    id = shmget(IPC_PRIVATE, 100, 0600);

    pid_t pid = fork();
    process_1 = fork();
    process_2 = fork();
    process_3 = fork();
    process_4 = fork();
    
    int *a;
    a = shmat(id,0,0);

    printf("\n\nprocess 1:\n\n");

    if(process_1 == 0){
        int P1 = 0;

        if(P1 <= 249){

            for(i = 0; i <= row; i++) {

                    for(j = 0; j <= col; j++) {

                        float C[row+1][col+1];

                            for(int AUX = 0; AUX <= order; AUX++) {

                                    C[i][j] += A[i][AUX] * B[AUX][j];

                                }
                                printf("%.2f ",C[i][j]);
                    }
                    printf("\n");
            }
        }
        exit(0);
    }

    printf("\n\nprocess 2:\n\n");

    if(process_2 == 0){
        int P2 = 250;

        if(P2 >=250 && P2 <= 499){

            for(i = 0; i <= row; i++) {

                    for(j = 0; j <= col; j++) {

                        float C[row+1][col+1];

                            for(int AUX = 0; AUX <= order; AUX++) {

                                    C[i][j] += A[i][AUX] * B[AUX][j];

                                }
                                printf("%.2f ",C[i][j]);
                    }
                    printf("\n");
            }
        }
        exit(0);
    }

    printf("\n\nprocess 3:\n\n");

    if(process_3 == 0){
        int P3 = 0;

        if(P3 >=500 && P3 <= 749){

            for(i = 0; i <= row; i++) {

                    for(j = 0; j <= col; j++) {

                        float C[row+1][col+1];

                            for(int AUX = 0; AUX <= order; AUX++) {

                                    C[i][j] += A[i][AUX] * B[AUX][j];

                                }
                                printf("%.2f ",C[i][j]);
                    }
                    printf("\n");
            }
        }
        exit(0);
    }

    printf("\n\nprocess 4:\n\n");

    if(process_4 == 0){
        int P4 = 0;

        if(P4 >=750 && P4 <= 999){

            for(i = 0; i <= row; i++) {

                    for(j = 0; j <= col; j++) {

                        float C[row+1][col+1];

                            for(int AUX = 0; AUX <= order; AUX++) {

                                    C[i][j] += A[i][AUX] * B[AUX][j];

                                }
                                printf("%.2f ",C[i][j]);
                    }
                    printf("\n");
            }
        }
        exit(0);
    }

    waitpid(process_1, NULL, 0);
    waitpid(process_2, NULL, 0);
    waitpid(process_3, NULL, 0);
    waitpid(process_4, NULL, 0);

    T2 = clock();
        delta = (float)(T2-T1)/CLOCKS_PER_SEC;

        printf("\n\Time %.5f seconds\n\n",delta);

    return 0;
}
