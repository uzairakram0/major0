#include <stdio.h>

/*
 Author: Clint Wyatt 
 
 */

int twosCompliment(int subbtractand){
    
    subbtractand =~subbtractand;
    unsigned int one = 1;

	// flip all set bits until find a 0
	while (subbtractand & one)
	{
		subbtractand ^= one;
		one <<= 1;
	}

	subbtractand ^= one;	// flip rightmost 0 bit

	return subbtractand;
}
int subtraction(int input1, int input2) {

    while(input1 > 100 || input1 <0){
    printf("Enter Minuend: ");
    scanf("%d", &input1);
    }
    
    while(input2 >100 || input2 <0){
    printf("Enter Subtrahend: ");
    scanf("%d", &input2);
    }
    
    printf("%d - %d = ", input1, input2);
    char carry = 0x0;
   
    //now doing 2's compliment.
    input2 = twosCompliment(input2);
    
    int x =1;
    int i =0;
    for(i; i <=7; i++, x++){
       
        //if both input1 and input2's read location are the same
        if((input1 &(1<<i)) & (input2 &(1<<i))){
            carry = carry|(1<<x);
        }
        //input1 and input2 are different, XOR.
        else if((input1 &(1<<i))^(input2 &(1<<i))){
           //if the current carry index is one
            if((carry &(1<<i)) >0){
                //setting carry's next index to 1.
                carry = carry|(1<<x);
            }
            else{
                //setting the carry's next index to 0. 
                carry = carry|(0<<x);
            }
        }
        //case being both the input2 and input1 are 0
        else{
            carry = carry|(0<<x);
        }
       
    }
    input1 = input1 ^ input2;
    //Xoring the input(which is the total so far) with the carry.
    input1 = input1 ^ carry;
    
    return input1;

}
