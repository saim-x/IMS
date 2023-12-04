#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

struct item
{
    char name[20];
    int price;
    int quantity;
    int discount;
};
void add()
{
    printf("\nAdding the itme: ");
    struct item i;
    srand(time(0));
    int id = rand() % 1000;
    printf("\nEnter the name of the item: ");
    scanf("%s", i.name);
    printf("\nEnter the price of the item: ");
    scanf("%d", &i.price);
    printf("\nEnter the quantity of the item: ");
    scanf("%d", &i.quantity);
    printf("\nEnter the discount of the item: ");
    scanf("%d", &i.discount);
    printf("\nItem added successfully");
    printf("\nThe unique id of the item is: %d", id);
    FILE *fp;
    char filepath[20];
    sprintf(filepath, "%d.txt", id);
    fp = fopen(filepath, "w");
    fprintf(fp, "%d %s %d %d %d", id, i.name, i.price, i.quantity, i.discount);
    printf("\n%d Stock of %s has been added to the database", i.quantity, i.name);
    fclose(fp);
}
void del()
{
    printf("\nDelete");
    printf("\n\n");
    printf("\nEnter the id of the item to delete: ");
    int id;
    scanf("%d", &id);
    FILE *fp;
    char filepath[20];
    sprintf(filepath, "%d.txt", id);
    printf("\nFile path: %s\n", filepath);
    fp = fopen(filepath, "r");
    if (fp == NULL)
    {
        printf("\nItem with id %d not found", id);
        return;
    }
    printf("\nDo you want to delete the item with id %d? (Y/N): ", id);
    char ch;
    scanf("%s", &ch);
    if (ch == 'Y' || ch == 'y')
    {
        fclose(fp);
        if (remove(filepath) == 0)
        {
            printf("\nFile deleted successfully");
        }
        else
        {
            printf("\nFile not deleted");
        }
    }
    else
    {
        printf("\nItem with id %d has not been deleted", id);
    }
}
void update()
{
    printf("\nUpdating the item: ");
    printf("\n\n");
    printf("\nEnter the id of the item to update: ");
    int id;
    scanf("%d", &id);
    FILE *fp;
    char filepath[20];
    sprintf(filepath, "%d.txt", id);
    fp = fopen(filepath, "w");
    if (fp == NULL)
    {
        printf("\nItem with id %d not found", id);
        return;
    }
    struct item i;
    printf("\nEnter the name of the item: ");
    scanf("%s", i.name);
    printf("\nEnter the price of the item: ");
    scanf("%d", &i.price);
    printf("\nEnter the quantity of the item: ");
    scanf("%d", &i.quantity);
    printf("\nEnter the discount of the item: ");
    scanf("%d", &i.discount);
    printf("\nItem updated successfully");
    fprintf(fp, "%d %s %d %d %d", id, i.name, i.price, i.quantity, i.discount);
    printf("\n%d Stock of %s has been updated to the database", i.quantity, i.name);
    fclose(fp);
}
void displayallstock()
{
    printf("\nDisplaying all the items stock");
    printf("\n\n");
    FILE *fp;
    fp = fopen("all.txt", "r");
    if (fp == NULL)
    {
        printf("\nNo items found");
        return;
    }
    int id;
    while (fscanf(fp, "%d", &id) != EOF)
    {
        char filepath[20];
        sprintf(filepath, "%d.txt", id);
        FILE *fp1;
        fp1 = fopen(filepath, "r");
        struct item i;
        fscanf(fp1, "%d %s %d %d %d", &id, i.name, &i.price, &i.quantity, &i.discount);
        printf("\n ID: %d\n Name: %s\n Price: %d\n Quantity: %d\n Discount: %d %%", id, i.name, i.price, i.quantity, i.discount);
        fclose(fp1);
    }
}
void display()
{
    printf("\nDisplay item stock");
    printf("\n\n");
    printf("\nEnter the id of the item: ");
    int id;
    scanf("%d", &id);
    FILE *fp;
    char filepath[20];
    sprintf(filepath, "%d.txt", id);
    fp = fopen(filepath, "r");
    if (fp == NULL)
    {
        printf("\nItem with id %d not found", id);
        return;
    }
    struct item i;
    fscanf(fp, "%d %s %d %d %d", &id, i.name, &i.price, &i.quantity, &i.discount);
    printf("\n ID: %d\n Name: %s\n Price: %d\n Quantity: %d\n Discount: %d %%", id, i.name, i.price, i.quantity, i.discount);
    fclose(fp);
}
void bill()
{
    printf("\nBill");
}

void intro()
{
    system("cls");
    printf("\nWelcome to Inventory Management System");
    printf("\n\n");
    for (int i = 0; i < 30; i++)
    {
        printf("*");
        printf(" ");
    }
}
void menu()
{
    printf("\n\n1. Add an item stock");
    printf("\n2. Delete an item stock");
    printf("\n3. Update an item stock");
    printf("\n4. Search an item stock");
    printf("\n5. Display item stock");
    printf("\n6. Bill");
    printf("\n7. Exit");
    printf("\n\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        del();
        break;
    case 3:
        update();
        break;
    case 4:
        displayallstock();
        break;
    case 5:
        display();
        break;
    case 6:
        bill();
        break;
    case 7:
        printf("\nThank you for using IMS");

        exit(0);
        break;
    default:
        printf("\nInvalid choice");
        break;
    }
}

int main()
{
    intro();
    int end = 0;
    while (!end)
    {
        menu();
        printf("\n\nDo you want to Use Program further? (Y/N): ");
        char ch;
        scanf("%s", &ch);
        if (ch == 'N' || ch == 'n')
        {
            end = 1;
        }
    }
}
