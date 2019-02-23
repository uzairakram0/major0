//Addition
#include <stdio.h>

int addition(first, second) {

unsigned int carry = 0;

while (second != 0)
{
//Find the carry and shift it left by comparing the numbers with a bitwise and (&)
carry = first & second;
carry = carry << 1;

//Perform bitwise XOR on operands and set the result to the first operand
first = first ^ second;

//Set the result of the carry to the second operand so it can be used on the next
//pass in the loop.
second = carry;

}//End while loop

return first;

}


