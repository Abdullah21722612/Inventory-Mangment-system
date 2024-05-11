#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

struct Product
{
    char name[50];
    int quantity;
    float price;
    int restock;
};

void addProduct(struct Product products[], int *numProducts);
void total_value(struct Product p1[], int numProducts);
void restocks(struct Product p1[], int numProducts);
void report(struct Product p1[], int numProducts);

int main()
{
    struct Product p1[MAX_ITEMS];
    int numProducts = 0;
    int choice;

    printf("Welcome to the Inventory Management System!\n");

    do
    {
        printf("\n1. Add product\n");
        printf("2. Calculate total value\n");
        printf("3. Restock\n");
        printf("4. Generate report\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addProduct(p1, &numProducts);
            break;
        case 2:
            total_value(p1, numProducts);
            break;
        case 3:
            restocks(p1, numProducts);
            break;
        case 4:
            report(p1, numProducts);
            break;
        case 5:
        system("clear");
            printf("Exiting...\nThank you! Come again.\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}

void addProduct(struct Product p1[], int *numProducts)
{
    char addMore = 'y';
    int Flag = 0;

    while (addMore == 'y')
    {
        system("clear");
        printf("Enter product name (or 'n' to quit): ");
        scanf("%s", p1[*numProducts].name);

        if (strcmp(p1[*numProducts].name, "n") == 0)
        {
            break;
        }

        do
        {
            printf("Enter product quantity: ");
            if (scanf("%d", &p1[*numProducts].quantity) == 1)
            {
                Flag = 1;
            }
            else
            {
                printf("Invalid input. Please enter numbers only.\n");
                scanf("%*[^\n]");
            }
        } while (!Flag);

        Flag = 0;

        do
        {
            printf("Enter product price: ");
            if (scanf("%f", &p1[*numProducts].price) == 1)
            {
                Flag = 1;
            }
            else
            {
                printf("Invalid input. Please enter numbers only.\n");
                scanf("%*[^\n]");
            }
        } while (!Flag);

        (*numProducts)++;
        printf("Product added successfully.\n");
        printf("Do you want to add another product (y/n)? ");
        scanf(" %c", &addMore);
    }
}

void total_value(struct Product p1[], int numProducts)
{
    system("clear");
    float totalValue = 0.0;
    printf("Product Details:\n");
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < numProducts; i++)
    {
        printf("%-20s %-10d $%-10.2f\n\n", p1[i].name, p1[i].quantity, p1[i].price);
        totalValue += p1[i].quantity * p1[i].price;
    }
    printf("-----------------------------------------------------------\n");
    printf("\nTotal Inventory Value:          $%.2f\n\n\n", totalValue);
}

void report(struct Product p1[], int numProducts)
{
    system("clear");
    printf("=== Inventory Report ===\n");
    printf("%-20s %-10s %-10s %-15s\n", "Name", "Quantity", "Price", "Restocking");
    for (int i = 0; i < numProducts; i++)
    {
        printf("%-20s %-10d $%-9.2f ", p1[i].name, p1[i].quantity, p1[i].price);
        if (p1[i].restock == 1)
        {
            printf("Yes\n\n");
        }
        else
        {
            printf("No\n\n");
        }
    }
}

void restocks(struct Product p1[], int numProducts)
{
    system("clear");
    int threshold = 10;
    printf("     Restocking Needed:\n\n");
    for (int i = 0; i < numProducts; i++)
    {
        if (p1[i].quantity < threshold)
        {
            p1[i].restock = 1;
            printf("         %s needs restocking. Current quantity: %d\n\n\n\n", p1[i].name, p1[i].quantity);
        }
        else
        {
            p1[i].restock = 0;
        }
    }
}