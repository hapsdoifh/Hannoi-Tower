// Hannover Tower.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#define LENGTH 10

typedef struct _Stack {
    char Storage[LENGTH];
    int top;
    char label;
}Stack;

int Pop(Stack* myStack,char* store) {
    if (myStack->top < 0) { //the stack is empty
        return -1;
    }
    *store = myStack->Storage[myStack->top];
    myStack->Storage[myStack->top] = 0;
    myStack->top -= 1;
    return 0;
}

int Push(Stack* myStack, char* store) {
    if ((int)(myStack->top) >= (int)(sizeof(myStack->Storage) / sizeof(char))) { //stack too big
        return -1;
    }
    myStack->top++;
    myStack->Storage[myStack->top] = *store;
    return 0;
}

int MoveTower(Stack* Start, Stack* Dest, Stack* Middle, int level, Stack* list[3]) {
    char temp;
    if (level == level) {
    }
    if (level == 1) { //Only top one
        if (Pop(Start, &temp) != -1) {
            Push(Dest, &temp);
            for (int k = 0; k < LENGTH; k++) {
                printf("%d\t%d\t%d", list[0]->Storage[LENGTH - 1 - k], list[1]->Storage[LENGTH - 1 - k], list[2]->Storage[LENGTH - 1 - k]);
                printf("\n");
            }
            printf("\n\n");
        }
        Sleep(3000);
    }
    else {
        MoveTower(Start, Middle, Dest, level - 1, list);
        Pop(Start, &temp);
        Push(Dest, &temp);
        for (int k = 0; k < LENGTH; k++) {
            printf("%d\t%d\t%d", list[0]->Storage[LENGTH - 1 - k], list[1]->Storage[LENGTH - 1 - k], list[2]->Storage[LENGTH - 1 - k]);
            printf("\n");
        }
        Sleep(3000);
        printf("\n\n");
        MoveTower(Middle, Dest, Start, level - 1, list);
    }
    return 0;
}

int main()
{
    Stack Start; //start of array is the top
    Stack Dest;
    Stack Middle;
    Start.top = -1;
    Start.label = 'S';
    Dest.top = -1;
    Dest.label = 'D';
    Middle.top = -1;
    Middle.label = 'M';
    memset(Dest.Storage, 0, sizeof(Dest.Storage));
    memset(Middle.Storage, 0, sizeof(Middle.Storage));
    for (int i = 0; i < sizeof(Start.Storage); i++) {
        Start.Storage[i] = LENGTH - i;
        Start.top++;
    }
    Stack* Towerlist[3] = { &Start, &Middle, &Dest };
    MoveTower(&Start, &Dest, &Middle,sizeof(Start.Storage)/sizeof(char), Towerlist);
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
