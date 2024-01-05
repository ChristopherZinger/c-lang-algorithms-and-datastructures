#include <stdio.h>
#include <stdlib.h>

void reassignVariable () {
    int someInt = 10;
    someInt = 11;
    printf("some int: '%d'\n", someInt);
}

void printUnassignedVar() {
    float someEmptyNum;
    printf("unassigned float: '%f' \n", someEmptyNum);
}

void printVariousVariables () {
    int myNum = 10;
    float myFlo = 1.2;
    char myChar = 'h';
    char myString[] = "hello";
    double myDouble = 0.01234567891234;

    printf("digit: %d \n", myNum);
    printf("float: %f  \n", myFlo);
    printf("char: %c \n", myChar);
    printf("string: %s \n", myString);
    printf("double: %.17lf \n", myDouble);
}

void function implicitConversion () {
    int num = 9.99; // becomes 9
    float myFloat = 9; // becomes 9.000000
    float division = 5 / 2; // becomes 2.000000
}

void function explicitConversion () {
    float division = (float) 5 / 2;
}

void constantVariables () {
    const int myConstantInteger = 10;
    // you can not reassign it 
    // myConstantInteger = 10; // this will throw an error
}

int main ()
{
    printVariousVariables();

    return 0;
}
