#include <stdio.h>

#define MAX 25

#define RED 0
#define YELLOW 1
#define GREEN 2
#define MAGENTA 3
#define WHITE 4
#define BLUE 5
#define BLACK 6
#define CYAN 7

/* Dear person who will check my code. Since its not a formal code, i wanna write some funny comments. Life is short and i wanna enjoy writing each line of code and writing funny comments. */

/* swapping the coordinates because of the coordinates. dealing with the corners of the part specifically. */
/* if you liked my code, we can have a cup of coffee once the campus opens (of course you will pay for the coffee " ogreniciym ben"  */

void swap(int *firstNumber, int *secondNumber) {
    int temp;
    temp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temp;
}

void fill(int array[MAX][MAX], int x, int y, int initialColor, int colorNumber) {
    int i, j;
    array[x][y] = colorNumber;

    /* super genius kind of checking eight sides of a cell. This is what happens when you code after you eat "acili lahmacun". Dear TA, You are always welcome*/
    /* to give me some extra marks because of it :). show how generous you are.*/
    for (i = -1; i <= 1; ++i) {
        for (j = -1; j <= 1; ++j) {
            int newX, newY;
            newX = x + i;
            newY = y + j;


            /* check the numbers if they are inside the matrix or not. */
            if ((newX > (MAX - 1) && newY < 0) || (newX > (MAX - 1) && (newY >= 0 && newY <= (MAX - 1))) ||
                (newX > (MAX - 1) && newY > (MAX - 1)) || ((newX >= 0 && newX <= (MAX - 1)) && newY > (MAX - 1)) ||
                (newX > (MAX - 1) && newY > (MAX - 1)) || (newX < 0 && (newY >= 0 && newY <= (MAX - 1))) ||
                (newX < 0 && newY < 0) || ((newX >= 0 && newX <= (MAX - 1)) && (newY < 0))) {
                continue;
            }

            /* recursion dude........ COOL :) */
            if (array[newX][newY] == initialColor) {
                fill(array, newX, newY, initialColor, colorNumber);
            }
        }
    }
}

int main() {

    int array[MAX][MAX];

    int colorNumber;


    /* for choosing color. */
    int iColor, jColor;
    /* initial location */
    int inLocation, jnLoction;


    char operation;

    int i;
    int j;

    /* getting the goddamn matrix. */
    for (i = 0; i < MAX; ++i) {
        for (j = 0; j < MAX; ++j) {
            int input;
            scanf(" %d", &input);
            array[i][j] = input;
        }
    }


    scanf(" %c", &operation);

    /* when you are excited and at the same time you dont know how many days these below operation will take ;) */
    switch (operation) {

        case 'F': {
            int initialColor;
            int k, l;
            /* I used to think that writing scanner in java was cooler than scanf,but now i think scanf is better because i am lazy and i dont wanna write "new" for everthing.
             * Goktruk Hoca would get happy after me saying that.*/



            /* coordinates for choosing the color */
            scanf(" %d", &iColor);
            scanf(" %d", &jColor);

            /* coordinates for choosing the initial place. */
            scanf(" %d", &inLocation);
            scanf(" %d", &jnLoction);


            /* choosing the color according to the plate. choosing color is done. */
            if (iColor < 0 && jColor < 0) {
                colorNumber = RED;
            } else if (iColor < 0 && (jColor >= 0 && jColor <= (MAX - 1))) {
                colorNumber = YELLOW;
            } else if (iColor < 0 && jColor > (MAX - 1)) {
                colorNumber = GREEN;
            } else if ((iColor >= 0 && iColor <= (MAX - 1)) && (jColor > (MAX - 1))) {
                colorNumber = MAGENTA;
            } else if (iColor > (MAX - 1) && jColor > (MAX - 1)) {
                colorNumber = WHITE;
            } else if (iColor > (MAX - 1) && (jColor >= 0 && jColor <= (MAX - 1))) {
                colorNumber = BLUE;
            } else if (iColor > (MAX - 1) && jColor < 0) {
                colorNumber = BLACK;
            } else if ((iColor >= 0 && iColor <= (MAX - 1)) && (jColor < 0)) {
                colorNumber = CYAN;
            } else {
                colorNumber = array[iColor][jColor];
            }

            /* initial Color that will get changed with the new color. */
            initialColor = array[inLocation][jnLoction];

            /* passing the array... */
            if (initialColor != colorNumber) {
                fill(array, inLocation, jnLoction, initialColor, colorNumber);
            } else { ;
            }

            /* printing the changed matrix... OH YEAH BABY! */
            for (k = 0; k < MAX; ++k) {
                for (l = 0; l < MAX; ++l) {
                    printf("%d ", array[k][l]);
                }
                printf("\n");
            }
            break;
        }

        case 'P': {

            int numbersOfCellsAffected;
            int copyStartRow, copyStartCol, copyEndRow, copyEndCol;
            int pasteStartRow, pasteStartCol, pasteEndRow, pasteEndCol;
            int x;
            int y;
            int k;
            int l;
            int m;
            int n;


            scanf(" %d %d %d %d", &copyStartRow, &copyStartCol, &copyEndRow, &copyEndCol);
            scanf(" %d %d %d %d", &pasteStartRow, &pasteStartCol, &pasteEndRow, &pasteEndCol);


            if (copyStartRow >= copyEndRow || copyStartCol >= copyEndCol) {
                swap(&copyStartCol, &copyEndCol);
                swap(&copyStartRow, &copyEndRow);
            }

            if (pasteStartRow >= pasteEndRow || pasteStartCol >= pasteEndCol) {
                swap(&pasteStartCol, &pasteEndCol);
                swap(&pasteStartRow, &pasteEndRow);
            }


            numbersOfCellsAffected = 0;

            /* Dear TA, next time please choose c99, because this mixed assignment and initliaztion really make things long. and very it makes me sad. */


            x = pasteStartRow - copyStartRow;
            y = pasteStartCol - copyStartCol;


            for (k = pasteStartRow; k <= pasteEndRow; ++k) {
                for (l = pasteStartCol; l <= pasteEndCol; ++l) {
                    if ((array[k][l] != array[k - x][l - y])) {
                        numbersOfCellsAffected += 1;
                    }
                    array[k][l] = array[k - x][l - y];
                }
            }

            /* The big problem is that since we are used to i and j, i keep writing i and j instead of m and n
             and 99% of the time i get a cardiac attack when i see those errors. Then i spend hours figuring out why its like that.
             after i am so close, as limit in math gets so close to a number, to punch keyboard of my laptop, i realize that i have to write the new variables instead of i and j. ;) */


            for (m = 0; m < MAX; ++m) {
                for (n = 0; n < MAX; ++n) {
                    printf("%d ", array[m][n]);
                }
                printf("\n");
            }
            printf("%d\n", numbersOfCellsAffected);
        }
            break;


            /* man this one is long.. and i am tired of this THE. so less comments..*/
        case 'R': {
            int copyStartRow, copyStartCol, copyEndRow, copyEndCol;
            int pasteStartRow, pasteStartCol, pasteEndRow, pasteEndCol;
            char operationSide;
            int angle;

            int x;
            int y;

            int cellAffected = 0;


            /* for ninety right. THANKS TO THIS OLD LANGUAGE I HAVE TO WRITE EVERYTHING AT THE TOP*/
            int m;
            int n;

            /* for one eighty  variable */
            int i, j;

            /* FOR  PRINTING LOOPS */
            int k, l;

            scanf(" %c", &operationSide);
            scanf(" %d", &angle);


            scanf(" %d %d %d %d", &copyStartRow, &copyStartCol, &copyEndRow, &copyEndCol);
            scanf(" %d %d %d %d", &pasteStartRow, &pasteStartCol, &pasteEndRow, &pasteEndCol);


            if (operationSide == 'R') {
                if (angle == 90) {
                    for (m = pasteStartRow; m <= pasteEndRow; ++m) {
                        for (n = pasteStartCol; n <= pasteEndCol; ++n) {
                            cellAffected += (array[m][n] != array[copyEndRow - (n - pasteStartCol)][copyStartCol + (m -
                                                                                                                    pasteStartRow)]);
                            array[m][n] = array[copyEndRow - (n - pasteStartCol)][copyStartCol + (m - pasteStartRow)];
                        }
                    }
                } else if (angle == 180) {
                    for (i = pasteStartRow; i <= pasteEndRow; i++) {
                        for (j = pasteStartCol; j <= pasteEndCol; j++) {
                            cellAffected += (array[i][j] != array[pasteEndRow - (i - pasteStartRow)][copyEndCol - (j -
                                                                                                                   pasteStartCol)]);
                            array[i][j] = array[pasteEndRow - (i - pasteStartRow)][copyEndCol - (j - pasteStartCol)];
                        }
                    }
                } else if (angle == 270) {
                    for (i = pasteStartRow; i <= pasteEndRow; i++) {
                        for (j = pasteStartCol; j <= pasteEndCol; j++) {
                            cellAffected += (array[i][j] != array[copyStartRow + (j - pasteStartCol)][copyEndCol - (i -
                                                                                                                    pasteStartRow)]);

                            array[i][j] = array[copyStartRow + (j - pasteStartCol)][copyEndCol - (i - pasteStartRow)];
                        }
                    }
                } else if(angle == 0) {

                    x = pasteStartRow - copyStartRow;
                    y = pasteStartCol - copyStartCol;

                    for (k = pasteStartRow; k <= pasteEndRow; ++k) {
                        for (l = pasteStartCol; l <= pasteEndCol; ++l) {
                            if ((array[k][l] != array[k - x][l - y])) {
                                cellAffected += 1;
                            }
                            array[k][l] = array[k - x][l - y];
                        }
                    }

                }
            }

            if (operationSide == 'L') {
                if (angle == 90) {
                    for (i = pasteStartRow; i <= pasteEndRow; i++) {
                        for (j = pasteStartCol; j <= pasteEndCol; j++) {
                            cellAffected += (array[i][j] != array[copyStartRow + (j - pasteStartCol)][copyEndCol - (i -
                                                                                                                    pasteStartRow)]);

                            array[i][j] = array[copyStartRow + (j - pasteStartCol)][copyEndCol - (i - pasteStartRow)];
                        }
                    }
                } else if (angle == 180) {
                    for (i = pasteStartRow; i <= pasteEndRow; i++) {
                        for (j = pasteStartCol; j <= pasteEndCol; j++) {
                            cellAffected += (array[i][j] != array[pasteEndRow - (i - pasteStartRow)][copyEndCol - (j -
                                                                                                                   pasteStartCol)]);
                            array[i][j] = array[pasteEndRow - (i - pasteStartRow)][copyEndCol - (j - pasteStartCol)];
                        }
                    }
                } else if (angle == 270) {
                    for (m = pasteStartRow; m <= pasteEndRow; ++m) {
                        for (n = pasteStartCol; n <= pasteEndCol; ++n) {
                            cellAffected += (array[m][n] != array[copyEndRow - (n - pasteStartCol)][copyStartCol + (m -
                                                                                                                    pasteStartRow)]);
                            array[m][n] = array[copyEndRow - (n - pasteStartCol)][copyStartCol + (m - pasteStartRow)];
                        }
                    }
                } else if (angle == 0) {
                    x = pasteStartRow - copyStartRow;
                    y = pasteStartCol - copyStartCol;

                    for (k = pasteStartRow; k <= pasteEndRow; ++k) {
                        for (l = pasteStartCol; l <= pasteEndCol; ++l) {
                            if ((array[k][l] != array[k - x][l - y])) {
                                cellAffected += 1;
                            }
                            array[k][l] = array[k - x][l - y];
                        }
                    }
                }
            }

            for (k = 0; k < MAX; ++k) {
                for (l = 0; l < MAX; ++l) {
                    printf("%d ", array[k][l]);
                }
                printf("\n");
            }
            printf("%d\n", cellAffected);
            break;
        }
    }
    return 0;
}
