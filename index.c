#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct{
    char name[MAX_NAME_LENGTH];
    float price;
} MenuItem;

MenuItem menu[MAX_ITEMS];
int menuCount = 0;

typedef struct{
    char name[MAX_NAME_LENGTH];
    int quantity;
} OrderItem;

OrderItem orders[MAX_ITEMS];
int orderCount = 0;

int main()
{

    return 0;
}