Java program to print the following pattern on the console
12344321
123**321
12****21
1******1

Algorithm:
STEP 1: START
STEP 2: SET lines=4
STEP 3: DEFINE i, j.
STEP 4: SET space=0
STEP 5: SET i=0
STEP 6: REPEAT STEP 7 TO 20 UNTIL i
STEP 7: SET j=1
STEP 8: REPEAT STEP 9 UNTIL j <= space.
STEP 9: PRINT " " and SET J=J+1
STEP 10: SET j=1
STEP 11: REPEAT STEP 12 and 13 UNTIL j<=lines
STEP 12: IF j <=(lines-i). PRINT j ELSE PRINT *
STEP 13: SET j=j+1
STEP 14: DECREMENT j by 1
STEP 15: REPEAT STEP 16 and 17 UNTIL j>0
STEP 16: IF j>( lines-i ) then PRINT * ELSE PRINT j
STEP 17: SET j=j-1
STEP 18: IF (lines-i) >9 INCREMENT space by 1
STEP 19: PRINT new line
STEP 20: SET i=i+1
STEP 21: END
Program:
public class pattern  
{  
    public static void main(String[] args) {  
    int lines=4;  
    int i,j;  
    int space=0;  
    for(i=0;i<lines;i++){// this loop is used to print lines  
        for(j=1;j<=space;j++){// this loop is used to print space in a line  
            System.out.print(" ");  
        }  
        for(j=1;j<=lines;j++){// this loop is used to print numbers in a line  
            if(j<=(lines-i))  
            System.out.print(j);  
            else  
            System.out.print("*");  
        }  
        j--;  
        while(j>0){// this loop is used to print numbers in a line  
            if(j>lines-i)  
            System.out.print("*");  
            else  
            System.out.print(j);  
            j--;  
        }  
        if((lines-i)>9)// this loop is used to increment space  
        space=space+1;  
    System.out.println("");  
    }  
}  
Output:

12344321
123**321
12****21
1******1
