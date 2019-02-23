#include <stdio.h>

// add 1
int increment(int num){
    int one = 1;
    while(num & one){
        num = num ^ one;
        one <<= 1;
    }
    num = num ^ one;
    return num;
}

// addition with recursion
//int addittion(int auggend, int addend){
//    int sum = auggend ^ addend;
//    int carry = auggend & addend;
//    carry <<= 1;
//
//    if (carry > 0)
//        return addittion(sum, carry);
//    else
//    return sum;
//}

// addition with itteration
int add(int auggend, int addend){
    int sum = auggend ^ addend;
    int carry = auggend & addend;
    carry <<= 1;

    while (carry != 0){
        int c = carry & sum;
        sum = sum ^ carry;
        carry = c << 1;
    }

    return sum;
}

// twosCompliment
int negate(int num){
    int result = ~num;
    result = increment(result);
    
    return result;
}

// Subtraction
int subtract(int minuend, int subtrahend){
    int difference;
    int mask = 0x8000;
    
    subtrahend = negate(subtrahend);
    //printf("%d %d\n", minuend, subtrahend);
    difference = add(minuend, subtrahend);
    //printf("%d\n", difference);
    
    if(difference & mask){
        return negate(difference);
    }else
    return difference;
}

// division
int division(int divisor, int dividend){
    int quotient = 0;
    int remainder;
    
    remainder = dividend;
    
    while(remainder >= divisor){
        remainder = subtract(remainder, divisor);
        quotient = increment(quotient);
    }
    printf("%d / %d = %d\n", dividend, divisor, quotient);
    return quotient;
}


//int main(){
//    int divisor;
//    int dividend;
//    int quotient;
//
//    printf("Enter divisor: ");
//    scanf("%d", &divisor);
//    printf("Enter divident: ");
//    scanf("%d", &dividend);
//
//    quotient = division(divisor, dividend);
//    printf("Quotient = %d\n", quotient);
//
//
//    return 0;
//}

// int main(){
//     int auggend;
//     int addend;
//     int sum;
    
//     printf("Enter augend: ");
//     scanf("%d", &auggend);
//     printf("Enter addend: ");
//     scanf("%d", &addend);
    
//     sum = subtraction(auggend, addend);
//     printf("Sum = %d\n", sum);
    
    
//     return 0;
// }

//int multiplication(int multiplicand, int multiplier){
//    int product;
//    int i;
//
//    for(i = 1; i <=multiplier; ++i){
//        product = add(multiplicand, multiplicand);
//    }
//
//    return product;
//}

