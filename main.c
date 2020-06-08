/*Assignment 1 for Data Structures and Algorithm Development c
 * Author: Manpreet Kaur
 * Date: 07, June, 2020
 * Description: This is Sodoku Grid that takes first two rows of the grid from user
 * and random generator is used to generate rest of the values
 * Also, It checks if the grid is valid or not
 * Submitted to: Muhammad Mohiuddin
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define SIZE 63
#define RANGE 9
#define OFFSET 1
#define SIZE1 80
#define SIZE2 80

/*This function is used to print the Sudoku Grid
 * 1- Validate the each row for distinct values from 1-9, no duplicates
 * 2- Validate the each column for distinct values from 1-9, no duplicates
 * 3- Validate each submatix for distinct values
 */
void printGrid(int grid[9][9]) {
    int i, j;
    printf("--------------Sudoku Grid------------\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%3d ", grid[i][j]);
            if (j == 8) {
                printf("\n");
            }
        }
    }
}

//This function is used to validate the grid
void validateGrid(int grid[9][9]) {
    int record[9];
    //declaring all the variables required for this validation
    int i, j, q, w, x, y, z, sumOfRows, sumOfColumns;


    //this validates the row for distinct numbers
    for (i = 0; i < 9; i++) {
        sumOfRows = 0;
        for (j = 0; j < 9; j++)
            sumOfRows = sumOfRows + grid[i][j];
        //if there are only distinct values starting from 1 to 9, no duplicates , the total will be 45
        //if the sum is not equal to 45 then break the loop
        if (sumOfRows != 45)
            break;
    }

    //if the sum for each row is 45 then validate the sum of columns
    if (sumOfRows == 45) {

        //this validates the columns
        for (i = 0; i < 9; i++) {
            sumOfColumns = 0;
            for (j = 0; j < 9; j++)
                sumOfColumns = sumOfColumns + grid[j][i];

            //if the sum is not equal to 45 then break the loop
            if (sumOfColumns != 45)
                break;
        }
        //if the total for the columns is also 45 then we validate the 3*3 submatrixs
        if (sumOfColumns == 45) {
            //sub matrix validator
            for (q = 0; q < 3; q += 3) {
                for (w = 0; w < 3; w += 3) {
                    z = 0;
                    int record[9];

                    // getting a 3*3 matrix
                    for (x = q; x < q + 3; x++) {
                        for (y = w; y < w + 3; y++) {
                            record[z++] = grid[j][i];
                        }
                    }
                }
            }
//if sub matrix are unique, then the grid is valid
            printf("\nGiven Soduku Grid is Valid\n\n");
        }
            //unless the grid is not valid
        else
            printf("This is invalid Grid\n");
    } else
        printf("This is invalid Grid\n");

}

int main() {

    //Declaration of the variables, and arrays
    int userGrid[9][9];
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n = 0;
    int m1, m2, m3, m4, m5, m6, m7, m8, m9, m = 0;
    char temp1[SIZE1];
    char temp2[SIZE2];

    //defining the grid
    int validGrid[9][9] = {
            {5, 3, 4, 6, 7, 8, 9, 1, 2},
            {6, 7, 2, 1, 9, 5, 3, 4, 8},
            {1, 9, 8, 3, 4, 2, 5, 6, 7},
            {8, 5, 9, 7, 6, 1, 4, 2, 3},
            {4, 2, 6, 8, 5, 3, 7, 9, 1},
            {7, 1, 3, 9, 2, 4, 8, 5, 6},
            {9, 6, 1, 5, 3, 7, 2, 8, 4},
            {2, 8, 7, 4, 1, 9, 6, 3, 5},
            {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };

    //calling the function to print the validGrid array 9*9
    printGrid(validGrid);

    //calling the function to validate the grid
    validateGrid(validGrid);

    printf("Enter row 1 of your Sudoku grid\n");

    //if user does not enter 9 values repeat the loop
    while (n != 9) {
        printf("Use Space\\Tab key to enter the values and press 'Return' after entering nine"
               " integers.\nRemember, to make a valid row of Sudoku grid,  all integers should be distinct and range from 1 to 9\n");

        //this gets the user input and store then in temp1 variable
        fgets(temp1, sizeof(temp1), stdin);
        n = sscanf(temp1, "%d %d %d %d %d %d %d %d %d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9);


//if user enters any values less than 0(negative), then break the loop and start over
        if (n1 < 0 || n2 < 0 || n3 < 0 || n4 < 0 || n5 < 0 || n6 < 0 || n7 < 0 || n8 < 0 || n9 < 0) {
            printf("One or more entries are outside the range of 1 t 9!\n");
            continue;
        }

        //if user enters any value greater than 9  then break the loop and start over
        if (n1 > 9 || n2 > 9 || n3 > 9 || n4 > 9 || n5 > 9 || n6 > 9 || n7 > 9 || n8 > 9 || n9 > 9) {
            printf("One or more entries are outside the range of 1 t 9!\n");
            continue;
        }
        //if user enters the exact 9 values then break the loop
        if (n == 9)
            break;

        printf("Enter exactly nine INTEGERS separated by space//Tab followed by Enter to end/nUse "
               "Space\\Tab key to enter the values and press 'Return' after entering nine integers.  Remember, "
               "to make a valid row of Sudoku grid,  all integers should be distinct and range from 1 to 9\n");

    }

    /*Inserting the values from user input to the array,
     * Defining the indexes where to insert the values
     */
    userGrid[9][9] = sscanf(temp1, "%d%d%d%d%d%d%d%d%d",
                            &userGrid[0][0],
                            &userGrid[0][1],
                            &userGrid[0][2],
                            &userGrid[0][3],
                            &userGrid[0][4],
                            &userGrid[0][5],
                            &userGrid[0][6],
                            &userGrid[0][7],
                            &userGrid[0][8]);


    printf("\n\nEnter row 2 of your Sudoku grid\n");

    //if user does not enter 9 values repeat the loop
    while (m != 9) {
        printf("Use Space\\Tab key to enter the values and press 'Return' after entering nine"
               " integers.\nRemember, to make a valid row of Sudoku grid,  all integers should be distinct and range from 1 to 9\n");

        //this gets the user input and store then in temp2 variable
        fgets(temp2, sizeof(temp2), stdin);
        m = sscanf(temp2, "%d%d%d%d%d%d%d%d%d", &m1, &m2, &m3, &m4, &m5, &m6, &m7, &m8, &m9);

        //if user enters any values less than 0(negative), then break the loop and start over
        if (m1 < 0 || m2 < 0 || m3 < 0 || m4 < 0 || m5 < 0 || m6 < 0 || m7 < 0 || m8 < 0 || m9 < 0) {
            printf("One or more entries are outside the range of 1 t 9!\n");
            continue;
        }

        //if user enters any value greater than 9  then break the loop and start over
        if (m1 > 9 || m2 > 9 || m3 > 9 || m4 > 9 || m5 > 9 || m6 > 9 || m7 > 9 || m8 > 9 || m9 > 9) {
            printf("One or more entries are outside the range of 1 t 9!\n");
            continue;
        }

        //if user enters the exact 9 values then break the loop
        if (m == 9)
            break;

        printf("Enter exactly nine INTEGERS separated by space//Tab followed by Enter to end/nUse "
               "Space\\Tab key to enter the values and press 'Return' after entering nine integers.\nRemember, "
               "to make a valid row of Sudoku grid,  all integers should be distinct and range from 1 to 9\n");
    }

    /*Inserting the values from user input to the array,
     * Defining the indexes where to insert the values
     */
    userGrid[9][9] = sscanf(temp2, "%d%d%d%d%d%d%d%d%d",
                            &userGrid[1][0],
                            &userGrid[1][1],
                            &userGrid[1][2],
                            &userGrid[1][3],
                            &userGrid[1][4],
                            &userGrid[1][5],
                            &userGrid[1][6],
                            &userGrid[1][7],
                            &userGrid[1][8]);

    /*generate the Random Numbers using random number generator
     * SIZE is the 63 because we want to generate 63 values
     * RANGE is 9
     * Generating the random values and inserting them in userGrid Array
     */
    srand(time(NULL));
    for (int dex = 1; dex <= SIZE; dex++) {
        for (int i = 2; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                userGrid[i][j] = rand() % RANGE + OFFSET;
            }
        }
    }
//Printing the User Grid
    printGrid(userGrid);

//Validate the user Grid
    validateGrid(userGrid);

    return 0;
}//main method ending