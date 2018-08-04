#include <stdio.h>
#include <string.h>

int printBill(char*, int, int);
int spacePrintStr(char *input, int num);
int spacePrintInt(int input, int num);

int main(int argc, const char * argv[]) {
    //Inisialising variables
    int rate = 0;
    int quantity = 0;
    float finalCost = 0;
    char product[20];
    //Getting Bill Entries
    printf("Enter Product Name :");
    gets(product);
    printf("Enter Product Rate :");
    scanf("%d", &rate);
    printf("Enter Quantity :");
    scanf("%d", &quantity);
    finalCost += quantity* rate;
    printBill(product, quantity, rate);

    return 0;
}

//Prints Bill
int printBill(char *product, int quantity, int rate){
    printf("**************** B I L L ***************\n");
    printf("Item               Quantity Price Amount\n");
    printf("________________________________________\n");
//    printf("%20s %8d %5.2f %6.2f", product, quantity, rate, quantity*rate);
    spacePrintStr(product, 20);
    spacePrintInt(quantity, 8);
    spacePrintInt(rate, 6);
    printf("%d",quantity*rate);
    printf(" ");
    printf("________________________________________\n");
    printf("Total Amount to be paid = %d\n", rate*quantity);
    printf("________________________________________\n");
    return 0;
}

//Formats Str inputs so that alignment is right
int spacePrintStr(char *input, int num){
    int i;
    int count;
    for(i = 0 ; i < num ; i++){
        if(input[i] == '\0')
            break;
        count++;
    }
    printf("%s",input);
    for (i = 0; i < num - count; i++) {
      printf(" ");
    }
    return 0;
}

//Formats Int inputs so that alignment is right
int spacePrintInt(int input, int num){
    int inputCopy = input;
    int count= 0;
    int i;
    while (inputCopy > 0) {
        inputCopy = inputCopy/10;
        count++;
    }
    printf("%d",input);
    for (i = 0; i < num - count; i++) {
        printf(" ");
    }
    //printf("%d",count);
    return 0;
}
