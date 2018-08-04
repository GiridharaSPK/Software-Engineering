#include <stdio.h>
#include <math.h>

int checkArmstrong(int n );
int numOfDigits(int n);

int main(int argc, const char * argv[]) {
    //Inisialising Variables
    int num;
    //Getting in input
    printf("Enter number n : ");
    scanf("%d",&num);
    //Loop to check if Armstrong
    while (num != -1) {
        if(checkArmstrong(num) == 1){
            printf("The number entered is an Armstrong Number.\n");
        }else if (checkArmstrong(num) == 0){
            printf("The number entered is not an Armstrong Number.\n");
        }
        printf("Enter number n : ");
        scanf("%d",&num);
    }
    printf("Program Ended.\n");
    return 0;
}

//Check if input is prime and reuturns 1 is prime and 0 if it is not
int checkArmstrong(int n){
    int noOfDigits, tempN, calc = 0;
    tempN = n;
    noOfDigits = numOfDigits(n);
    while (tempN > 0) {
        calc += pow(tempN%10, noOfDigits);
        tempN /= 10;
    }
    if (calc == n) {
        return 1;
    }else{C
        return 0;
    }
}

int numOfDigits(int n){
    int numOfDigits=1;
    while (n >= 10) {
        numOfDigits++;
        n /= 10;
    }
    return numOfDigits;
}
