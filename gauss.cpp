#include <iostream>
#define SIZE 3


/* Algorytm wyznaczania wyznacznika macierzy
metoda eliminacji Gaussa

 Kod jest dosc brzydki ale byl zrobiony 
czysto w celach wyprobowania swoich sil. */



int main(){

    double matrix[SIZE][SIZE];
    double temp1, temp2;
    double det = 1;
    int i, j;

    for(i =0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            std::cin >> matrix[i][j];
        }
    }
    

    if(matrix[0][0]==0){
        std::cout << "dupa" << std::endl;
        for(i = 0; i < SIZE; i++){
        if(matrix[i][0]!=0){
            det *= -1;
            for(j = 0; j < SIZE; j++){
                temp1 = matrix[i][j];
                temp2 = matrix[0][j];
                matrix[0][j] = temp1;
                matrix[i][j] = temp2;
            }
        }
    }
    }
    
    


    for(i=j=0; i < SIZE-1 && j < SIZE-1; i++, j++){
           for(int m = i+1; m < SIZE; m++){
                for(int n = SIZE-1; n >=j; n--){
                        matrix[m][n] -= (matrix[m][j]/matrix[i][j]*matrix[i][n]); 
                        // std::cout << matrix[m][n] << std::endl;
                }
        }
    }

    for(i =0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    
    
    for(i=j=0; i < SIZE && j < SIZE; i++, j++){
        det *= matrix[i][j];
    }
    std::cout << det << std::endl;
}
