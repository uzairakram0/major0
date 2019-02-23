#include <stdio.h>
#include "major0.h"
 
int main(){
    
    char choice;
    char buffer;
    int input1;
    int input2;
    int result;
    
    do{
        printf("Chose one of the following or press 'q' to quit:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("Select: ");
        scanf("%c", &choice);
        
        switch(choice){
            
            case '1':
            printf("Enter operands between 1 and 100, inclusively.\n");
            printf("Enter Auggend: ");  scanf("%d", &input1);
            printf("Enter Addend: ");   scanf("%d", &input2);
            result = addition(input1,input2);
            printf("%d\n", result);
            break;

            case '2':
            printf("Enter operands between 1 and 100, inclusively.\n");
            printf("Enter Minuend: ");  scanf("%d", &input1);
            printf("Enter Subtrahend: ");   scanf("%d", &input2);
            result = subtraction(input1, input2);
            printf("%d\n", result);
            break;
            
            case '3':
            printf("Enter operands between 1 and 100, inclusively.\n");
            printf("Enter Multiplicand: ");   scanf("%d", &input1);
            printf("Enter Multiplier: ");   scanf("%d", &input2);
            result = multiplication(input1,input2);
            printf("%d\n", result);
            break;
            
            case '4':
            printf("Enter operands between 1 and 100, inclusively.\n");
            printf("Enter Dividend: "); scanf("%d", &input1);
            printf("Enter Divisor: ");  scanf("%d", &input2);
            result = division(input2,input1);
            printf("%d\n", result);
            break;
        }
	if(choice != 'q') 
        scanf("%c", &choice);   
        
    }while(choice != 'q');
    return 0;
}


