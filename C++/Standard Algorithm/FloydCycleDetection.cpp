/*
    Floyd's Cycle detection algorithm to detect loop in a singly
    linked list. And also to determine the length of loop and
    starting point of loop.

    Input:
        A single linked list.

    Output:
        Yes/No based on loop is present or not.
        If yes, then length of loop and starting point of loop.
*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

// Structure defination
struct node
{
    int data;
    node* next;
};

void insertToList(node** head_ref, int data);
void printList(node** head_ref, int length);
void deleteList(node** head_ref, int length);
void FloydCycleAlgo(node** head_ref);

int main(int argc, char const *argv[])
{
    node* head = NULL;
    node* reverseListHead = NULL;
    int inputValue;
    int listLength =0;

    printf("Enter the elements of linked list. Enter -1 to end the list.\n");
    while(true)
    {
        scanf("%d", &inputValue);
        if(inputValue != -1)
        {
            insertToList(&reverseListHead, inputValue);
            listLength++;
        }
        else
            break;
    }

    node* reverseList = reverseListHead;
    while(reverseList != NULL)
    {
        insertToList(&head, reverseList->data);
        reverseList = reverseList->next;
    }

    deleteList(&reverseListHead, listLength);
    printf("Length of linked list:%d\n", listLength);
    printList(&head, listLength);
    
    // create a loop.
    srand(time(NULL));
    int randValue = rand() % listLength;
    node* startLoop = NULL;
    node* listIterator = head;
    int i=0;
   
    while(listIterator->next != NULL)
    {
        i++;
        if(i == randValue)
        {
            startLoop = listIterator;
            printf("Loop starting element:%d\n", startLoop->data);
        }

        listIterator = listIterator->next;
    }

    listIterator->next = startLoop;
    printList(&head, listLength+10);

    FloydCycleAlgo(&head);
    deleteList(&head, listLength);
    return 0;
}

// Insert an element to the linked list
void insertToList(node** head_ref, int data)
{
    node* head = (*head_ref);

    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }

    (*head_ref) = head;
}

// Prints the linked list
void printList(node** head_ref, int length)
{
    node* head = (*head_ref);

    while(length > 0 && head!= NULL)
    {
        printf("%d",head->data);

        if(head->next != NULL && length > 1)
        {
            printf(" -> ");
        }
        else
            printf("\n");

        head = head->next;
        length--;
    }
}

// Delete the entire list.
void deleteList(node** head_ref, int length)
{
    node* head = (*head_ref);
    node* current = head;
    node* prev = NULL;

    while(current != NULL && length != 0)
    {
        prev = current;
        current = current->next;

        free(prev);
        length--;
    }

    (*head_ref) = NULL;
}

// Detect if there is a loop in the linked list. If yes, then also print 
// the length and starting point of loop.
void FloydCycleAlgo(node** head_ref)
{
    node* head = (*head_ref);
    node* slowPtr = head;
    node* fastPtr = head;
    bool found = false;
    int loopLength = 0;

    while(fastPtr != NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if(slowPtr == fastPtr)
        {
            printf("Loop found in the linked list.\n");
            found = true;
            break;
        }
    }

    if(!found)
    {
        printf("No loop found in the linked list.\n");
        return;
    }

    while(true)
    {
        fastPtr = fastPtr->next;
        loopLength++;
        if(fastPtr == slowPtr)
        {
            printf("Loop length:%d\n", loopLength);
            break;
        }
    }

    slowPtr = head;
    while(slowPtr != fastPtr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }

    printf("Loop in the linked list.\n");
    printList(&slowPtr, loopLength);
}