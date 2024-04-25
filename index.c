#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct
{
    char name[MAX_NAME_LENGTH];
    float price;
} MenuItem;

MenuItem menu[MAX_ITEMS];
int menuCount = 0;

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int quantity;
} OrderItem;

OrderItem orders[MAX_ITEMS];
int orderCount = 0;

void addItemToMenu(const char *name, float price)
{
    if (menuCount < MAX_ITEMS)
    {
        strcpy(menu[menuCount].name, name);
        menu[menuCount].price = price;
        menuCount++;
        printf("Item added to the menu. \n");
    }
    else
    {
        printf("Menu is full. Connot add more items.\n");
    }
}

// Display Menu
void displayMenu()
{
    printf("Menu: \n");
    for (int i = 0; i < menuCount; i++)
    {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Remove Item From Menu
void removeItemFromMenu(int index)
{
    if (index >= 0 && index < menuCount)
    {
        for (int i = index; i < menuCount - 1; i++)
        {
            strcpy(menu[i].name, menu[i + 1].name);
            menu[i].price = menu[i + 1].price;
        }
        menuCount--;
        printf("Item removed from the menu. \n");
    }
    else
    {
        printf("Invalid index. Cannot remove item. \n");
    }
}

// Modify Order
void modifyOrder(int index, int newQuantity)
{
    if (index >= 0 && index < orderCount)
    {
        orders[index].quantity = newQuantity;
        printf("Order modified.\n");
    }
    else
    {
        printf("Invalid index. Cannot Modify Order.\n");
    }
}
// Total Price
float calculateTotalPrice()
{
    float total = 0.0;
    for (int i = 0; i < orderCount; i++)
    {
        for (int j = 0; j < menuCount; j++)
        {
            if (strcmp(orders[i].name, menu[j].name) == 0)
            {
                total += orders[i].quantity * menu[j].price;
                break;
            }
        }
    }
    return total;
}

// Display Orders
void displayOrders()
{
    printf("Orders: \n");
    for (int i = 0; i < orderCount; i++)
    {
        printf("%d. %s - Quantity: %d\n", i + 1, orders[i].name, orders[i].quantity);
    }
    printf("Total Price: $%.2f\n", calculateTotalPrice());
}

int main()
{
    int choice;
    char itemName[MAX_NAME_LENGTH];
    float itemPrice;
    int quantity;
    int index;
    int newQuantity;

    do
    {
        printf("\nFood Order Management System\n");
        printf("1. Add Item to Menu\n");
        printf("2. Display Menu\n");
        printf("3. Remove Item from Menu\n");
        printf("4. Take Order\n");
        printf("5. Modify Order\n");
        printf("6. Display Orders\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter name of the item: ");
            scanf("%s", itemName);
            printf("Enter price of the item: ");
            scanf("%f", &itemPrice);
            addItemToMenu(itemName, itemPrice);
            break;
        case 2:
            displayMenu();
            break;
        case 3:
            printf("Enter index of the item to remove: ");
            scanf("%d", &index);
            removeItemFromMenu(index - 1);
            break;
        case 4:
            printf("Enter name of the item to order: ");
            scanf("%s", itemName);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            takeOrder(itemName, quantity);
            break;
        case 5:
            printf("Enter index of the order to modify: ");
            scanf("%d", &index);
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            modifyOrder(index - 1, newQuantity);
            break;
        case 6:
            displayOrders();
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}