/*
Author: LilWons
Date: 2024-01-11
Version: 1

Description: Gets inputs N and M from the user and returns the series of squares that can be made out of a piece of paper with NxM dimensions. 
No fractional squares are allowed and no square can be less than 1 in length and width.  
*/

#include <stdlib.h>
#include <stdio.h>

//Global variable to flag the first square.
int firstSquare;

/*
BadInput: Notifies user of invalid input.
Clears input buffer. 
*/
void BadInput(){
    fprintf(stderr, "Invalid input\n");
    while (getchar() != '\n');
}
/*
GetDimN: Gets and returns N input from the user.
Check each input is a positive integer. 
*/
int GetDimN(void){
    int N; 
    printf("Enter Size of N: ");
    fflush(stdout);
    if(scanf("%d", &N) != 1 || N < 1) {
        BadInput();
        return 0;
    }

    return N;
}
/*
GetDimM: Gets and returns M input from the user.
Check each input is a positive integer. 
*/
int GetDimM(void){
    int M; 
    printf("Enter Size of M: ");
    fflush(stdout);
    if(scanf("%d", &M) != 1 || M < 1) {
        BadInput();
        return 0;
    }
    return M;
}
/*
printSquare: Prints the square dimensions in the format of LxW. 
*/
void PrintSquare(int square){
    if(!firstSquare){
        printf(", ");
    }
    printf("%dx%d", square, square);
    firstSquare = 0;
}
/*
GetSquares: Finds and prints the largest square able to be made with available dimensions. 
*/
void GetSquares(int *dimN, int *dimM){
    if(*dimN > *dimM){
        PrintSquare(*dimM);
        *dimN = *dimN - *dimM;
    }
    else{
        PrintSquare(*dimN);
        *dimM = *dimM - *dimN;
   }
}
/*
main: Check to ensure squares can be made with the provided dimensions.
Continues making squares until no more squares can be made with available dimensions.
*/
int main(){
    int M, N;
    firstSquare = 1;
    N = GetDimN();
    if (N == 0) return EXIT_FAILURE; 
    M = GetDimM();
    if (M == 0) return EXIT_FAILURE;  
    while(N > 0 && M > 0){
        GetSquares(&N, &M);
    }
    return 0;
}


