#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

struct Node
{
    char name[16];
    int address;
};

void freeMemory(Node **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(arr[i]);
    }

    free(arr);
}

int main()
{
    Node **arr;
    int currentSize = 6;
    int additionalSize = 2;
    try
    {
        printf("Node struct size = %d\n", sizeof(Node));
        arr = (Node **)malloc(sizeof(Node) * currentSize);

        int index = 0;

        for (int i = 0; i < currentSize; i++)
        {
            arr[i] = (Node *)malloc(sizeof(Node));
            arr[i] = new Node();
            arr[i]->address = i;

            char name[8] = "Node ";
            char num[2];
            itoa(i, num, 10);
            strcat(name, num);
            strcpy(arr[i]->name, name);
        }

        arr = (Node **)realloc(arr, sizeof(Node) * (currentSize + additionalSize));

        for (int i = currentSize; i < currentSize + additionalSize; i++)
        {
            arr[i] = (Node *)malloc(sizeof(Node));
            arr[i] = new Node();
            arr[i]->address = i;

            char name[8] = "Node ";
            char num[2];
            itoa(i, num, 10);
            strcat(name, num);
            strcpy(arr[i]->name, name);
        }

        for (int i = 0; i < currentSize + additionalSize; i++)
        {
            printf("%s - %d\n", arr[i]->name, arr[i]->address);
        }

        freeMemory(arr, currentSize + additionalSize);
    }
    catch (exception ex)
    {
        freeMemory(arr, currentSize + additionalSize);
    }

    return 0;
}