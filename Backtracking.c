#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#define mSize 8 // maximum size of the matrix
#define MAX_STRING_SIZE 20 // maximum size of the string

bool backtracking(int matrix[mSize][mSize], int i, int j, int size); // boolean return true if backtracking is over
bool isOk(int matrix[mSize][mSize], int i, int j, int num, int size); // boolean return true if there is no simillar color in both of rows and columns otherwise return flase
bool UsedInRow(int matrix[mSize][mSize], int i, int j, int num, int size); // boolean return true if there is another same color in the row
bool UsedInCol(int matrix[mSize][mSize], int i, int j, int num, int size); // boolean return true if there is another same color in the column
void rightRotatebyOne(int arr[], int n); // function to rotate a line of colors (right rotation)
int printMatrix(int matrix[mSize][mSize], int size); // function to print the matrix of colors


// backtracking function
bool backtracking(int matrix[mSize][mSize], int i, int j, int size){ // takes the matrix, i for row, j for col, and size of the matrix
	int num, k;
	for(k=0; k< size; k++){ // start from 1 to size of matrix 
		num = matrix[i][j]; // take the number in the matrix
		if(isOk(matrix,i,j,num,size)){ // check if the number is not in the same row or col
			i++; // move to the next row
			j++; // move to the next col
			if(backtracking(matrix, i, j, size)){ // backtrack for new row and col
				return true;
			}
		}
		else{ // if the number is in the same row or col
			if(i<size){ // we need only the rows in the matrix
				printf("Rotate line %d\n", i);
				rightRotatebyOne(matrix[i], size); // right rotate
			}
			else{ // if we reached the last row then we finished with true
				return true;
			}
		}
		
	}
	return false; // if nothing was true return false to declare that there's no solution
}


// rotate function
void rightRotatebyOne(int arr[], int n) { // takes the row and size of row
    int temp = arr[n-1], i; // assign the last cell to temprorary 
    for (i = n-1; i > 0; i--){ // start from the last element
        arr[i] = arr[i - 1]; // rotate
        printf("%d\t", arr[i]); // print the rotated cell
	}
    arr[i] = temp; // the temprorary cell is assigned to the first cell
    printf("%d\n\n", arr[i]); // print it
} 

// checks if there's same number in each of rows and cols
bool isOk(int matrix[mSize][mSize], int i, int j, int num, int size){
	if(!UsedInRow(matrix, i, j, num, size) && !UsedInCol(matrix, i, j, num, size)) // if the number is not in same row and col
		return true; // return true
	return false; // else return false
}

// function to check if the number is in the same row
bool UsedInRow(int matrix[mSize][mSize], int i, int j, int num, int size){
	int k;
    for (k = 0; k < size; k++) // loop for cols
        if (matrix[i][k] == num && k != j) // if the number is found but not the same that we already have
            return true; // return true
    return false; // else return false
}

// function to check if the number is in the same col
bool UsedInCol(int matrix[mSize][mSize], int i, int j, int num, int size){
	int k;
    for (k = 0; k < size; k++) // loop for rows
        if (matrix[k][j] == num && k!=i) // if the number is found but not the same that we already have
            return true; // return true
    return false; // else return false
}

// function to print the matrix as colors not numbers
int printMatrix(int matrix[mSize][mSize], int size){
	int k, p, color;
	char arr[mSize+1][MAX_STRING_SIZE]= {"zero","white", "black", "blue", "yellow", "red", "orange", "purple", "green"}; // colors array of strings
	for(k = 0; k<size; k++){ // loop
		for(p=0; p<size; p++){ // loop
			color = matrix[k][p]; // assign the value to color variable
			printf("%s\t", arr[color]); // print the color from array of colors
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	// variables of colors will be used in switch case
	int white = 1, black = 2, blue = 3, yellow = 4, red = 5, orange = 6, purple = 7, green = 8;
	int i, j, k, p, size;
	int choose;
	int matrix[mSize][mSize];
	
	printf("Please choose size of matrix to be between 3 and 8:\n");
	while(scanf("%d",&size) != 1){ // check if the user enters numbers only
		printf("please enter only numbers\n");
		getchar();
	}
	while(size<3 || size>8){ // check if the user enters number between 3 and 8
		printf("Please enter a number between 3 and 8\n");
		scanf("%d",&size);
	}
	
	// start filling the matrix bu user
	printf("Pease choose %d colors from bellow: \n",size);
	for(i=0;i<size;i++){
		printf("Start row number %d\n\n",i+1); // start with rows
		for(j=0;j<size;j++){
			printf("Col number %d\n\n",j+1); // fill the cols
			printf("Please choose color: \n(1: white, 2: black, 3: blue, 4: yellow, 5: red, 6: orange, 7: purple, 8: green)\n\n");
			scanf("%d",&choose); // take a number from a user
			switch(choose){ // put the right color in the matrix
				case 1:
					matrix[i][j] = white;
					break;
				case 2:
					matrix[i][j] = black;
					break;
				case 3:
					matrix[i][j] = blue;
					break;
				case 4:
					matrix[i][j] = yellow;
					break;
				case 5:
					matrix[i][j] = red;
					break;
				case 6:
					matrix[i][j] = orange;
					break;
				case 7:
					matrix[i][j] = purple;
					break;
				case 8:
					matrix[i][j] = green;
					break;
				default: // if the user entered a wrong number notify him/her!
					printf("You entered wrong color\n");
					break;
			}
		}
	}
//	system("cls"); // you can clear screen by uncomment this line
//	 if you want to print the matrix before starting please uncomment the following 3 lines
//	printf("\nMatrix before backtracking:\n");
//	printMatrix(matrix,size);
//	printf("\n");

	i = 0; // to start from the beginning make rows starts from 0
	j = 0; // to start from the beginning make cols starts from 0
	printf("\n");
	// start backtracking and check if the result is true or false
	if(backtracking(matrix, i, j, size)){
		printf("The result Matrrix is:\n\n"); // if result is true 
		printMatrix(matrix, size); // print the color matrix
	}
	else{ // else print that there's no solution
		printf("\nThere is no solution\n");
	}
	
	return 0;
}
