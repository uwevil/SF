#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void init(int n, int *x, int *y){
  int i = 0;
  for (i = 0; i < n; i++){
    if (i < n/2){
      x[i] = 1;
    }else{
       x[i] = 0;
    }
     if (i > n/2){
      y[i] = 1;
    }else{
       y[i] = 0;
    }
  }
}

void final(int n, int *xf, int *yf){
  int i = 0;
  for (i = 0; i < n; i++){
    if (i < n/2){
      yf[i] = 1;
    }else{
       yf[i] = 0;
    }
     if (i > n/2){
      xf[i] = 1;
    }else{
       xf[i] = 0;
    }
  }
}

void generator2(int n, int *x, int *y){

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
	FILE *file_out = fopen("./boolTmp", "a+");

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
	generator2(n, xx, yy);
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
	FILE *file_out = fopen("./boolTmp", "a+");

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
	generator2(n, xx, yy);
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
                FILE *file_out = fopen("./boolTmp", "a+");
                
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
                generator2(n, xx, yy);
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
                FILE *file_out = fopen("./boolTmp", "a+");
                
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
                generator2(n, xx, yy);
            }
        }
    }

}

void writeInit(int n,int *x, int *y){
    FILE *file_out = fopen("./boolTmp", "a+");
    
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

void writeFinal(int n, int *x, int *y){
    FILE *file_out = fopen("./boolTmp", "a+");
    
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

int main(int argc, char ** argv){
    int n = 7;
    
    int *x = malloc(sizeof(int)*n);
    int *y = malloc(sizeof(int)*n);
    int *xf = malloc(sizeof(int)*n);
    int *yf = malloc(sizeof(int)*n);
    
  init(n, x, y);
  final(n, xf, yf);
    
    /*
  int i = 0;
  for (i = 0; i < n; i++){
    printf(" %d ", x[i]);
  } 

  printf("\n");
   for (i = 0; i < n; i++){
    printf(" %d ", y[i]);
  }

   printf("\n");
 for (i = 0; i < n; i++){
    printf(" %d ", xf[i]);
  } 

  printf("\n");
   for (i = 0; i < n; i++){
    printf(" %d ", yf[i]);
  }

   printf("\n");
*/
    FILE *file_out = fopen("./boolTmp", "w");
    fclose(file_out);
    writeInit(n, x, y);
   generator2(n, x, y);
    writeFinal(n, xf, yf);

  return 0;
}
