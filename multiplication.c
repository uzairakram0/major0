/*
Jared Carpenter
*/

#include <stdio.h>

int multiplication(unsigned int multiplicand,unsigned int multiplier) {
	unsigned int holder = 0;
	unsigned int holderAddition;
	unsigned int multiplicandHold;
	unsigned int multiplicandHoldFinal;
	multiplicandHoldFinal = multiplicand;

	int number = 0;
	while (number != 8) { //Goes through all binary numbers.
		if (multiplier & (1 << number)){ //If there is a 1 in the binary position in multiplier.
			multiplicandHold = multiplicand; 
			//ADDITION
			while (multiplicand != 0) {
				holderAddition = holder & multiplicand; //Both have ones
				holder = holder ^ multiplicand; //Has ones in either.
				holderAddition = holderAddition << 1; //Shift
				multiplicand = holderAddition; //Multiplicand hold for while loop.
			}
			multiplicand = multiplicandHold;
		}
		multiplicand = multiplicand << 1; //Shift left.
		number++;
	}

	printf("%d x %d = %d\n", multiplicandHoldFinal, multiplier, holder);
}

