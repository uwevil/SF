#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**********RUN*********
 
 % gcc -o sat sat.c
 % ./sat <nx> <ny> <fileName> <step>
 
 avec:
 nx = nombre de grenouilles à gauche
 ny = nombre de grenouilles à droite
 fileName = nom du fichier sortie
 step = nombre de pas
 
 */

//*****************************QUESTION 1************************************//
void init(int nx, int ny, int *x, int *y){
    int i = 0;
    for (i = 0; i < nx + ny + 1; i++){
        if (i < nx){
            x[i] = 1;
        }else{
            x[i] = 0;
        }
    }
    for (i = nx + ny; i >= 0; i--){
        if (i > nx){
            y[i] = 1;
        }else{
            y[i] = 0;
        }
    }
}

//*****************************QUESTION 2************************************//
void final(int nx, int ny, int *xf, int *yf){
    int i = 0;
    for (i = nx + ny; i >= 0; i--){
        if (i > ny){
            xf[i] = 1;
        }else{
            xf[i] = 0;
        }
    }
    
    for (i = 0; i < nx + ny + 1; i++){
        if (i < ny){
            yf[i] = 1;
        }else{
            yf[i] = 0;
        }
    }
}

void writeFile(int n, int *xx, int *yy, char *fileName){
    FILE *file_out = fopen(fileName, "a+");
    int j = 0;
    fprintf(file_out, "(");
    for (j = 0; j < n; j++){
        if (xx[j] == 0){
            fprintf(file_out, "!x%d", j);
        }else{
            fprintf(file_out, "x%d", j);
        }
        
        fprintf(file_out, " & ");
        
        if (yy[j] == 0){
            fprintf(file_out, "!y%d", j);
        }else{
            fprintf(file_out, "y%d", j);
        }
        
        if (j + 1 < n){
            fprintf(file_out, " & ");
        }
    }
    
    fprintf(file_out, ") | \n");
    fclose(file_out);
}

void generator2(int n, int *x, int *y, char *fileName){
    
    int i = 0;
    
    //*********************************//
    for (i = 0; i < n; i++){
        if (i + 1 < n){
            if (x[i] == 1 && x[i + 1] == 0 && y[i + 1] == 0){
                int *xx = malloc(sizeof(int)*n);
                int *yy = malloc(sizeof(int)*n);
                
                int j = 0;
                for (j = 0; j < n; j++){
                    if (j == i){
                        xx[j] = 0;
                        xx[j + 1] = 1;
                    }else if (j != i + 1){
                        xx[j] = x[j];
                    }
                    
                    yy[j] = y[j];
                }
                
                writeFile(n, xx, yy, fileName);
                
                generator2(n, xx, yy, fileName);
            }
        }
    }
    
    //*****************************************//
    for (i = n -1; i >= 0; i--){
        if (i - 1 >= 0){
            if (y[i] == 1 && y[i - 1] == 0 && x[i - 1] == 0){
                int *xx = malloc(sizeof(int)*n);
                int *yy = malloc(sizeof(int)*n);
                
                int j = 0;
                for (j = 0; j < n; j++){
                    if (j == i){
                        yy[j] = 0;
                        yy[j - 1] = 1;
                    }else if (j != i - 1){
                        yy[j] = y[j];
                    }
                    
                    xx[j] = x[j];
                }
                
                writeFile(n, xx, yy, fileName);
                
                generator2(n, xx, yy, fileName);
            }
        }
    }
    
    //********************************************//
    for (i = 0; i < n; i++){
        if (i + 2 < n){
            if (x[i] == 1 && x[i + 1] == 0 && x[i + 2] == 0 && y[i + 1] == 1 && y[i + 2] == 0){
                int *xx = malloc(sizeof(int)*n);
                int *yy = malloc(sizeof(int)*n);
                
                int j = 0;
                for (j = 0; j < n; j++){
                    if (j == i){
                        xx[j] = 0;
                        xx[j + 2] = 1;
                    }else if (j != i + 2){
                        xx[j] = x[j];
                    }
                    
                    yy[j] = y[j];
                }
                
                writeFile(n, xx, yy, fileName);
                
                generator2(n, xx, yy, fileName);
            }
        }
    }
    
    //*****************************************//
    for (i = n -1; i >= 0; i--){
        if (i - 2 >= 0){
            if (y[i] == 1 && y[i - 1] == 0 && y[i - 2] == 0 && x[i - 1] == 1 && x[i - 2] == 0){
                int *xx = malloc(sizeof(int)*n);
                int *yy = malloc(sizeof(int)*n);
                
                int j = 0;
                for (j = 0; j < n; j++){
                    if (j == i){
                        yy[j] = 0;
                        yy[j - 2] = 1;
                    }else if (j != i - 2){
                        yy[j] = y[j];
                    }
                    
                    xx[j] = x[j];
                }
                
                writeFile(n, xx, yy, fileName);
                
                generator2(n, xx, yy, fileName);
            }
        }
    }
    
}


void writeInit(int n,int *x, int *y, char * fileName){
    FILE *file_out = fopen(fileName, "a+");
    
    fprintf(file_out, "(");
    int j;
    for (j = 0; j < n; j++){
        if (x[j] == 0){
            fprintf(file_out, "!x%d", j);
        }else{
            fprintf(file_out, "x%d", j);
        }
        
        fprintf(file_out, " & ");
        
        if (y[j] == 0){
            fprintf(file_out, "!y%d", j);
        }else{
            fprintf(file_out, "y%d", j);
        }
        
        if (j + 1 < n){
            fprintf(file_out, " & ");
        }
    }
    
    fprintf(file_out, ") | \n");
    fclose(file_out);
    
}

void writeFinal(int n, int *x, int *y, char *fileName){
    FILE *file_out = fopen(fileName, "a+");
    
    fprintf(file_out, "(");
    int j;
    for (j = 0; j < n; j++){
        if (x[j] == 0){
            fprintf(file_out, "!x%d", j);
        }else{
            fprintf(file_out, "x%d", j);
        }
        
        fprintf(file_out, " & ");
        
        if (y[j] == 0){
            fprintf(file_out, "!y%d", j);
        }else{
            fprintf(file_out, "y%d", j);
        }
        
        if (j + 1 < n){
            fprintf(file_out, " & ");
        }
    }
    fprintf(file_out, ")\n");
    fclose(file_out);
}

/*
 générer tous les cas possibles( tous les chemin à partir de la configuration initiale)
 */

void generator3(int n, int *initx, int *inity, int *finalx, int *finaly, char *fileName){
    FILE *file_out = fopen(fileName, "w");
    fclose(file_out);
    
    writeInit(n, initx, inity, fileName);
    generator2(n, initx, inity, fileName);
    writeFinal(n, finalx, finaly, fileName);
}

int compare2Tab(int n, int *x, int *y, int *xx, int *yy){
    int i = 0;
    for (i = 0; i < n; i++){
        if (x[i] != xx[i] || y[i] != yy[i])
            return 1;
    }
    
    return 0;
}

int generator4(int n, int *initx, int *inity, int *finalx, int *finaly, int currentStep, int step, char *fileName){
    int i = 0;
    
    if (currentStep == step)
        return 1;
    
    int *x = initx;
    int *y = inity;
    
    //*********************************//
    for (i = 0; i < n; i++){
        if (i + 1 < n){
            if (x[i] == 1 && x[i + 1] == 0 && y[i + 1] == 0){
                int *xx = malloc(sizeof(int)*n);
                int *yy = malloc(sizeof(int)*n);
                
                int j = 0;
                for (j = 0; j < n; j++){
                    if (j == i){
                        xx[j] = 0;
                        xx[j + 1] = 1;
                    }else if (j != i + 1){
                        xx[j] = x[j];
                    }
                    
                    yy[j] = y[j];
                }
                
                writeFile(n, xx, yy, fileName);
                
                if (compare2Tab(n, finalx, finaly, xx, yy) == 0)
                    return 0;
                
                int test = generator4(n, xx, yy, finalx, finaly, currentStep + 1, step, fileName);
                
                if (test == 0)
                    return 0;
            }
        }
    }
    
    //*****************************************//
    for (i = n -1; i >= 0; i--){
        if (i - 1 >= 0){
            if (y[i] == 1 && y[i - 1] == 0 && x[i - 1] == 0){
                int *xx = malloc(sizeof(int)*n);
                int *yy = malloc(sizeof(int)*n);
                
                int j = 0;
                for (j = 0; j < n; j++){
                    if (j == i){
                        yy[j] = 0;
                        yy[j - 1] = 1;
                    }else if (j != i - 1){
                        yy[j] = y[j];
                    }
                    
                    xx[j] = x[j];
                }
                
                writeFile(n, xx, yy, fileName);
                
                if (compare2Tab(n, xx, yy, finalx, finaly) == 0)
                    return 0;
                
                int test = generator4(n, xx, yy, finalx, finaly, currentStep + 1, step, fileName);
                
                if (test == 0)
                    return 0;
            }
        }
    }
    
    //********************************************//
    for (i = 0; i < n; i++){
        if (i + 2 < n){
            if (x[i] == 1 && x[i + 1] == 0 && x[i + 2] == 0 && y[i + 1] == 1 && y[i + 2] == 0){
                int *xx = malloc(sizeof(int)*n);
                int *yy = malloc(sizeof(int)*n);
                
                int j = 0;
                for (j = 0; j < n; j++){
                    if (j == i){
                        xx[j] = 0;
                        xx[j + 2] = 1;
                    }else if (j != i + 2){
                        xx[j] = x[j];
                    }
                    
                    yy[j] = y[j];
                }
                
                writeFile(n, xx, yy, fileName);
                
                if (compare2Tab(n, xx, yy, finalx, finaly) == 0)
                    return 0;
                
                int test = generator4(n, xx, yy, finalx, finaly, currentStep + 1, step, fileName);
                
                if (test == 0)
                    return 0;
            }
        }
    }
    
    //*****************************************//
    for (i = n -1; i >= 0; i--){
        if (i - 2 >= 0){
            if (y[i] == 1 && y[i - 1] == 0 && y[i - 2] == 0 && x[i - 1] == 1 && x[i - 2] == 0){
                int *xx = malloc(sizeof(int)*n);
                int *yy = malloc(sizeof(int)*n);
                
                int j = 0;
                for (j = 0; j < n; j++){
                    if (j == i){
                        yy[j] = 0;
                        yy[j - 2] = 1;
                    }else if (j != i - 2){
                        yy[j] = y[j];
                    }
                    
                    xx[j] = x[j];
                }
                
                writeFile(n, xx, yy, fileName);
                
                if (compare2Tab(n, xx, yy, finalx, finaly) == 0)
                    return 0;
                
                int test = generator4(n, xx, yy, finalx, finaly, currentStep + 1, step, fileName);
                
                if (test == 0)
                    return 0;
            }
        }
    }
    
    return 1;
}

//*****************************QUESTION 3 et 4************************************//

int generator4Bis(int n, int *initx, int *inity, int *finalx, int *finaly, int step, char *fileName){
    FILE *file_out = fopen(fileName, "w");
    fclose(file_out);
    
    writeInit(n, initx, inity, fileName);
    int res = generator4(n, initx, inity, finalx, finaly, 0, step, fileName);
    writeFinal(n, finalx, finaly, fileName);
    return res;
}


int generator5(int n, int *initx, int *inity, int *finalx, int *finaly,int currentStep, char *fileName){
    int i = 0;
    
    int *x = initx;
    int *y = inity;
    
    //*********************************//
    for (i = 0; i < n; i++){
        if (i + 1 < n){
            if (x[i] == 1 && x[i + 1] == 0 && y[i + 1] == 0){
                int *xx = malloc(sizeof(int)*n);
                int *yy = malloc(sizeof(int)*n);
                
                int j = 0;
                for (j = 0; j < n; j++){
                    if (j == i){
                        xx[j] = 0;
                        xx[j + 1] = 1;
                    }else if (j != i + 1){
                        xx[j] = x[j];
                    }
                    
                    yy[j] = y[j];
                }
                
                writeFile(n, xx, yy, fileName);
                
                if (compare2Tab(n, finalx, finaly, xx, yy) == 0)
                    return currentStep + 1;
                
                int test = generator5(n, xx, yy, finalx, finaly, currentStep + 1, fileName);
                
                if (test != 0)
                    return test;
            }
        }
    }
    
    //*****************************************//
    for (i = n -1; i >= 0; i--){
        if (i - 1 >= 0){
            if (y[i] == 1 && y[i - 1] == 0 && x[i - 1] == 0){
                int *xx = malloc(sizeof(int)*n);
                int *yy = malloc(sizeof(int)*n);
                
                int j = 0;
                for (j = 0; j < n; j++){
                    if (j == i){
                        yy[j] = 0;
                        yy[j - 1] = 1;
                    }else if (j != i - 1){
                        yy[j] = y[j];
                    }
                    
                    xx[j] = x[j];
                }
                
                writeFile(n, xx, yy, fileName);
                
                if (compare2Tab(n, xx, yy, finalx, finaly) == 0)
                    return currentStep + 1;
                
                int test = generator5(n, xx, yy, finalx, finaly, currentStep + 1, fileName);
                
                if (test != 0)
                    return test;
            }
        }
    }
    
    //********************************************//
    for (i = 0; i < n; i++){
        if (i + 2 < n){
            if (x[i] == 1 && x[i + 1] == 0 && x[i + 2] == 0 && y[i + 1] == 1 && y[i + 2] == 0){
                int *xx = malloc(sizeof(int)*n);
                int *yy = malloc(sizeof(int)*n);
                
                int j = 0;
                for (j = 0; j < n; j++){
                    if (j == i){
                        xx[j] = 0;
                        xx[j + 2] = 1;
                    }else if (j != i + 2){
                        xx[j] = x[j];
                    }
                    
                    yy[j] = y[j];
                }
                
                writeFile(n, xx, yy, fileName);
                
                if (compare2Tab(n, xx, yy, finalx, finaly) == 0)
                    return currentStep + 1;
                
                int test = generator5(n, xx, yy, finalx, finaly, currentStep + 1, fileName);
                
                if (test != 0)
                    return test;
            }
        }
    }
    
    //*****************************************//
    for (i = n -1; i >= 0; i--){
        if (i - 2 >= 0){
            if (y[i] == 1 && y[i - 1] == 0 && y[i - 2] == 0 && x[i - 1] == 1 && x[i - 2] == 0){
                int *xx = malloc(sizeof(int)*n);
                int *yy = malloc(sizeof(int)*n);
                
                int j = 0;
                for (j = 0; j < n; j++){
                    if (j == i){
                        yy[j] = 0;
                        yy[j - 2] = 1;
                    }else if (j != i - 2){
                        yy[j] = y[j];
                    }
                    
                    xx[j] = x[j];
                }
                
                writeFile(n, xx, yy, fileName);
                
                if (compare2Tab(n, xx, yy, finalx, finaly) == 0)
                    return currentStep + 1;
                
                int test = generator5(n, xx, yy, finalx, finaly, currentStep + 1, fileName);
                
                if (test != 0)
                    return test;
            }
        }
    }
    
    return 0;
}
//*****************************QUESTION 5************************************//
/*
 chaque configuration est unique car les grenouilles à gauche ne peut qu'avancer vers la droite (resp. pour les grenouilles à droite vers la gauche).
 */


//*****************************QUESTION 6 et 7************************************//

int generator5Bis(int n, int *initx, int *inity, int *finalx, int *finaly, char *fileName){
    FILE *file_out = fopen(fileName, "w");
    fclose(file_out);
    
    writeInit(n, initx, inity, fileName);
    int res = generator5(n, initx, inity, finalx, finaly, 0, fileName);
    writeFinal(n, finalx, finaly, fileName);
    return res;
}

int main(int argc, char ** argv){
    int nx = atoi(argv[1]);
    int ny = atoi(argv[2]);
    char *fileName = argv[3];
    int step = atoi(argv[4]);
    
    int *x = malloc(sizeof(int)*(nx + ny + 1));
    int *y = malloc(sizeof(int)*(nx + ny + 1));
    int *xf = malloc(sizeof(int)*(nx + ny + 1));
    int *yf = malloc(sizeof(int)*(nx + ny + 1));
    
    init(nx, ny, x, y);
    final(nx, ny, xf, yf);
    /*
     int i = 0;
     for (i = 0; i < nx + ny + 1; i++){
     printf(" %d ", x[i]);
     }
     
     printf("\n");
     for (i = 0; i < nx + ny + 1; i++){
     printf(" %d ", y[i]);
     }
     
     printf("\n");
     for (i = 0; i < (nx + ny + 1); i++){
     printf(" %d ", xf[i]);
     }
     
     printf("\n");
     for (i = 0; i < (nx + ny + 1); i++){
     printf(" %d ", yf[i]);
     }
     
     printf("\n");
     */
    
    generator3((nx + ny + 1), x, y, xf, yf, fileName);
    
    strcat(fileName, "_1");
    
    if (generator4Bis((nx + ny + 1), x, y, xf, yf, step, fileName) == 0){
        printf("%d steps => OK\n", step);
    }else{
        printf("%d steps => KO\n", step);
    }
    
    strcat(fileName, "_2");
    
    int res = generator5Bis((nx + ny + 1), x, y, xf, yf, fileName);
    printf("%d steps to success\n", res);
    
    return 0;
}
