#include <stdio.h>
#include <string.h>
#include "curses.h"

char libReg[200][25] = {"Kite Runner", "Jungle Book", "Percy Jackson", "Narnia", "Harry Potter", "Alchemist", "Lord of the Rings", "Hunger Games", "Twilight", "Eragon"};
int currentNumOfBooks = (sizeof(libReg)/25);

void mainMenuPrint();
void add(int);
void view(int);
void del(int);
void mod(int);
int loginAdmin();
int loginUser();

int main() {
    
    char id[10],pass[10];
    
    initscr();			/* Start curses mode 		  */
    
    clear();            /* Clear screen for next time  */
    
    printw("Login...\n");
    printw("Login ID : ");
    refresh();
    
    getstr(id);
    
    // ---------Start read password, masking with *
    
    noecho();			/* Don't echo() while we do getch */
    printw("Please Enter your Password:");
    
    int input;
    int i = 0;
    while(( input=getch() ) != '\n'){
        pass[i] = input;
        addch('*');
        i++;
    }
    addch('\n');
    echo(); /*Enable echo again*/
    
    
    pass[i] = '\0'; // make it a string
    
    // --------- End read password, masking with *
    
    
    if (!strcmp(id, "admin") && !strcmp(pass,"1234")) {
        printw("In Admin Mode:\n");
        refresh(); //Refresh is required to show it on screen
        loginAdmin();
    }else if(!strcmp(id, "nikhil") && !strcmp(pass,"1234")){
        printw("In User Mode:\n");
        refresh();
        loginUser();
    }else{
        printw("Invalid Credentials!! Try Again...(Press any Key)\n");
        refresh();
        getch();
        main();
    }
    
    endwin();			/* End curses mode		  */
    
    return 0;
}

int loginAdmin(){
    int op;
    printw("----------------------------------------\n");
    printw("Enter Operation : \n");
    printw("1)Add Book\n");
    printw("2)View Book\n");
    printw("3)Modify Book\n");
    printw("4)Delete Book\n");
    printw("5)Log Out\n");
    printw("----------------------------------------\n");
    scanw("%d", &op);
    switch (op) {
        case 1:
            printw("Selected option: Add Book\n");
            refresh();
            add(0);
            break;
            
        case 2:
            printw("Selected option: View Book\n");
            refresh();
            view(0);
            break;
            
        case 3:
            printw("Selected option: Modify Book\n");
            refresh();
            mod(0);
            refresh();
            break;
            
        case 4:
            printw("Selected option: Delete Book\n");
            refresh();
            del(0);
            break;
        case 5:main();
            break;
        default:
            printw("Invalid Operation!\n");
            refresh();
            break;
    }
    return 0;
}

int loginUser(){
    int op;
    printw("----------------------------------------\n");
    printw("Enter Operation : \n");
    printw("1)View Books\n");
    printw("2)Exit\n");
    printw("----------------------------------------\n");
    scanw("%d", &op);
    
    switch (op) {
        case 1:
            printw("Selected option: View Book\n");
            refresh();
            view(1);
            break;
        case 2:main();
            break;
        default:
            printw("Invalid Operation!\n");
            refresh();
            break;
    }
    return 0;
}

void add(int loginType){
    printw("Adding Book\n");
    printw("Enter Book Title :");
    refresh();
    getstr(libReg[currentNumOfBooks]);
    printw("%s is added to the register\n",libReg[currentNumOfBooks]);
    currentNumOfBooks++;
    if (loginType == 0) {
        loginAdmin();
    }else if (loginType == 1){
        loginUser();
    }
}


void view(int loginType){
    printw("View Book\n");
    int i= 0 ;
    for(i = 0; i <currentNumOfBooks;i++){
        printw("%d) %s\n",i+1,libReg[i]);
    }
    printw("Enter any key to continue...\n");
    refresh();
    getchar();
    clear();
    if (loginType == 0) {
        loginAdmin();
    }else if (loginType == 1){
        loginUser();
    }
}

void mod(int loginType){
    printw("Modify Book\n");
    printw("Enter Book ID : ");
    refresh();
    int id ;
    scanw("%d",&id);
    printw("Modifying %s.\n",libReg[id-1]);
    printw("Enter New Name :\n");
    refresh();
    getstr(libReg[id-1]);
    printw("Entry changed to %s\n", libReg[id-1]);
    printw("Enter any key to continue...\n");
    refresh();
    getchar();
    if (loginType == 0) {
        loginAdmin();
    }else if (loginType == 1){
        loginUser();
    }
}

void del(int loginType){
    printw("Deleting Book\n");
    printw("Enter Book ID : ");
    refresh();
    int id ;
    int c, i;
    scanw("%d",&id);
    printw("Deleting %s.\n",libReg[id-1]);
    for ( c = id - 1 ; c < (sizeof(libReg)/25) ; c++ ){
        for (i = 0; i < 25; i++) {
            libReg[c][i]=libReg[c+1][i];
        }
    }
    currentNumOfBooks--;
    printw("Enter any key to continue...\n");
    refresh();
    getchar();
    
    if (loginType == 0) {
        loginAdmin();
    }else if (loginType == 1){
        loginUser();
    }
}
