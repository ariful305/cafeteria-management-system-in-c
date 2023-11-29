#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************************
*                                Data Structures                              *
******************************************************************************/

struct FoodItem
{
    char name[100];
    float price;
    int quantity;
    struct FoodItem* next;
};

struct OrderItem
{
    char name[100];
    char customerName[100];
    float price;
    int quantity;
    struct OrderItem* next;
};

struct OrderQueueNode
{
    struct OrderItem* data;
    struct OrderQueueNode* next;
};

struct StackNode
{
    int tableNumber;
    char customerName[100];
    struct OrderItem* orderInfo;
    struct StackNode* next;
};

struct User
{
    char username[20];
    char password[20];
};

/******************************************************************************
*                             Global Variables                                *
******************************************************************************/


struct User admin = {"admin", "123"};
struct OrderQueueNode *front = NULL;
struct OrderQueueNode *rear= NULL;

/******************************************************************************
*                            Authentication check                             *
******************************************************************************/

/**
 * @brief Authenticates a user based on the provided username and password.
 *
 * @param currentUser Pointer to a User struct containing the current user's credentials.
 * @return 1 if authentication is successful, 0 otherwise.
 */

int authenticate(struct User* currentUser)
{
    char username[20];
    char password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    if (strcmp(currentUser->username, username) == 0 && strcmp(currentUser->password, password) == 0)
    {
        return 1;
    }
    else
    {
        printf("Authentication failed. Invalid username or password.\n");
        return 0;
    }
}

/******************************************************************************
*                    Food Create,Edit,Delete,Display                          *
******************************************************************************/

/**
 * @brief Creates a new FoodItem node with the given parameters.
 *
 * @param name Name of the food item.
 * @param price Price of the food item.
 * @param quantity Quantity of the food item in stock.
 * @return Pointer to the newly created FoodItem node.
 */

struct FoodItem* createFoodItemNode(char name[], float price, int quantity)
{



    struct FoodItem* newItem = (struct FoodItem*)malloc(sizeof(struct FoodItem));
    if (newItem != NULL)
    {
        strcpy(newItem->name, name);
        newItem->price = price;
        newItem->quantity = quantity;
        newItem->next = NULL;
    }
    return newItem;
}

/**
 * @brief Adds a new food item to the menu.
 *
 * @param head Pointer to the head of the FoodItem linked list.
 * @param name Name of the food item.
 * @param price Price of the food item.
 * @param quantity Quantity of the food item in stock.
 */

void addFoodItem(struct FoodItem** head, char name[], float price, int quantity)
{
    struct FoodItem* newItem = createFoodItemNode(name, price, quantity);
    newItem->next = *head;
    *head = newItem;
    printf("Food item added successfully!\n");
}

/**
 * @brief Edits the details of a food item in the menu.
 *
 * @param head Pointer to the head of the FoodItem linked list.
 * @param oldName Name of the food item to be edited.
 */
void editFoodItem(struct FoodItem** head, char oldName[])
{
    struct FoodItem* current = *head;
    while (current != NULL)
    {
        if (strcmp(current->name, oldName) == 0)
        {
            printf("Enter the new name for %s: ", oldName);
            scanf("%s", current->name);
            printf("Enter the new quantity for %s: ", current->name);
            scanf("%d", &current->quantity);
            printf("Food item edited successfully!\n");
            return;
        }
        current = current->next;
    }
    printf("Food item not found!\n");
}
/**
* @brief Deletes a food item from the menu based on its name.
*
* @param head Pointer to the head of the FoodItem linked list.
* @param name Name of the food item to be deleted.
*/

void deleteFoodItem(struct FoodItem** head, char name[])
{
    struct FoodItem* current = *head;
    struct FoodItem* prev = NULL;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (prev == NULL)
            {
                *head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            printf("Food item deleted successfully!\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Food item not found!\n");
}

/**
 * @brief Displays the current menu with item details.
 *
 * @param head Pointer to the head of the FoodItem linked list.
 */
void displayMenu(struct FoodItem* head)
{
    struct FoodItem* current = head;

    if (current != NULL)
    {
        printf("|--------|----------------------|------------|-----------|\n");
        printf("| %-6s | %-20s | %-10s | %-9s |\n", "No.", "Name", "Price ($)", "Quantity");
        printf("|--------|----------------------|------------|-----------|\n");
    }
    else
    {
        printf("No item available\n\n");
        return;
    }

    int itemNumber = 1;
    while (current != NULL)
    {
        printf("| %-6d | %-20s | %-10.2f | %-9d |\n", itemNumber, current->name, current->price, current->quantity);
        current = current->next;
        itemNumber++;
    }
    printf("|--------|----------------------|------------|-----------|\n");
}

/******************************************************************************
*                           Order Create,summary                              *
******************************************************************************/


/**
 * @brief Creates a new OrderItem node with the given parameters.
 *
 * @param name Name of the ordered item.
 * @param price Price of the ordered item.
 * @param quantity Quantity of the ordered item.
 * @param customerName Name of the customer placing the order.
 * @return Pointer to the newly created OrderItem node.
 */
struct OrderItem* createOrderItemNode(char name[], float pricePerUnit, int quantity, char customerName[])
{
    struct OrderItem* newItem = (struct OrderItem*)malloc(sizeof(struct OrderItem));
    if (newItem != NULL)
    {
        strcpy(newItem->name, name);
        strcpy(newItem->customerName, customerName);
        newItem->price = pricePerUnit * quantity; // Use price * quantity
        newItem->quantity = quantity;
        newItem->next = NULL;
    }
    return newItem;
}
/**
 * @brief Places an order for a specified quantity of a food item.
 *
 * @param menu Pointer to the head of the FoodItem linked list representing the menu.
 * @param order Pointer to the head of the OrderItem linked list representing orders.
 * @param name Name of the food item to be ordered.
 * @param quantity Quantity of the food item to be ordered.
 * @param customerName Name of the customer placing the order.
 * @return 1 if the order is successfully placed, 0 otherwise.
 */
int placeOrder(struct FoodItem** menu, struct OrderItem** order, const char name[], int quantity, char customerName[])
{
    struct FoodItem* current = *menu;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (current->quantity >= quantity)
            {
                // Add the item to the order list
                struct OrderItem* orderItem = createOrderItemNode(name, current->price, quantity, customerName);
                orderItem->next = *order;
                *order = orderItem;

                // Update the quantity in the menu
                current->quantity -= quantity;

                printf("Order placed successfully for %s!\n", customerName);
                return 1;
            }
            else
            {
                printf("Insufficient quantity in stock!\n");
                return 0;
            }
        }
        current = current->next;
    }
    printf("Food item not found!\n");
    return 0;
}
/**
 * @brief Displays a summary of the orders, including customer names, item names, prices, and quantities.
 *
 * @param order Pointer to the head of the OrderItem linked list representing orders.
 */
void displayOrderSummary(struct OrderItem* order)
{
    printf("======================================================================================\n");
    printf("|                      O r d e r   S u m m a r y                     |\n");
    printf("======================================================================================\n");

    if (order == NULL)
    {
        printf("|                      No Order items found!                        |\n");
    }
    else
    {
        printf("| %-23s | %-32s | %-10s | %-8s |\n", "Customer Name", "Item Name", "Price ($)", "Quantity");
        printf("------------------------------------------------------------------------------------\n");

        struct OrderItem* current = order;
        while (current != NULL)
        {
            printf("| %-23s | %-32s | $%-9.2f | %-8d |\n", current->customerName, current->name, current->price, current->quantity);
            current = current->next;
        }
    }

    printf("======================================================================================\n");

}


void showtotal(struct OrderItem* order)
{
    printf("Total Sale: ");
    struct OrderItem* current = order;
    double total = 0; // Change to double
    while (current != NULL)
    {
        total += current->price;
        current = current->next;
    }

    printf("$%.2f\n", total); // Change to %f for double
}

float getPriceByName(struct FoodItem* menu,char name[])
{
    struct FoodItem* current = menu;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            return current->price;
        }
        current = current->next;
    }
    return 0.0; // Return 0 if the item is not found (you may choose a different value)
}
/******************************************************************************
*                          File Operation                                     *
******************************************************************************/
/**
 * @brief Loads the menu from the "menu.txt" file into a linked list.
 *
 * @return Pointer to the head of the loaded FoodItem linked list.
 */
struct FoodItem* loadMenuFromFile()
{
    struct FoodItem* head = NULL;
    FILE* file = fopen("menu.txt", "r");
    if (file != NULL)
    {
        char name[50];
        float price;
        int quantity;
        char customerName[100];
        while (fscanf(file, "%s %f %d\n", name, &price, &quantity) == 3)
        {
            struct FoodItem* newItem = createFoodItemNode(name, price, quantity);
            if (newItem != NULL)
            {
                newItem->next = head;
                head = newItem;
            }
        }
        fclose(file);

    }
    else
    {
        printf("Menu file not found. Starting with an empty menu.\n");
    }
    return head;
}
/**
 * @brief Saves the current menu to the "menu.txt" file.
 *
 * @param head Pointer to the head of the FoodItem linked list.
 */
void saveMenuToFile(struct FoodItem* head)
{
    FILE* file = fopen("menu.txt", "w");
    if (file != NULL)
    {
        struct FoodItem* current = head;
        while (current != NULL)
        {
            fprintf(file, "%s %.2f %d\n", current->name, current->price, current->quantity);
            current = current->next;
        }
        fclose(file);

    }
    else
    {
        printf("Error: Unable to save menu items.\n");
    }
}
/**
 * @brief Deletes a food item from the menu file.
 *
 * @param itemName Name of the food item to be deleted.
 */
void deleteItemFromFile(const char* itemName)
{
    FILE* file = fopen("menu.txt", "r");
    if (file == NULL)
    {
        printf("Menu file not found.\n");
        return;
    }

    FILE* tempFile = fopen("temp_menu.txt", "w");
    if (tempFile == NULL)
    {
        printf("Error: Unable to create temporary file.\n");
        fclose(file);
        return;
    }

    char name[50];
    float price;
    int quantity;
    int itemFound = 0;

    // Read items from the original file, exclude the item to be deleted
    while (fscanf(file, "%s %f %d\n", name, &price, &quantity) == 3)
    {
        if (strcmp(name, itemName) == 0)
        {
            itemFound = 1;
            continue; // Skip the item to be deleted
        }
        fprintf(tempFile, "%s %.2f %d\n", name, price, quantity);
    }

    fclose(file);
    fclose(tempFile);

    // Remove the original file and rename the temporary file to the original filename
    remove("menu.txt");
    rename("temp_menu.txt", "menu.txt");

    if (itemFound)
    {
        printf("Item \"%s\" deleted from the menu.\n", itemName);
    }
    else
    {
        printf("Item \"%s\" not found in the menu.\n", itemName);
    }
}
/******************************************************************************
*                          Stack Operation                                    *
******************************************************************************/

/**
 * @brief Creates a new StackNode with the given parameters.
 *
 * @param tableNumber The table number.
 * @param orderInfo Pointer to the OrderItem associated with the table.
 * @return Pointer to the newly created StackNode.
 */
struct StackNode* createStackNode(char customerName[],struct OrderItem* orderInfo)
{
    int tableNumber =  rand() % 10 + 1;

    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (newNode != NULL)
    {
        newNode->tableNumber = tableNumber;
        strcpy(newNode->customerName, customerName);
        newNode->orderInfo = orderInfo;
        newNode->next = NULL;
    }
    return newNode;
}

/**
 * @brief Pushes a table number and order information onto the stack.
 *
 * @param stack Pointer to the Stack.
 * @param tableNumber The table number to be pushed.
 * @param orderInfo Pointer to the OrderItem associated with the table.
 */

void push(struct StackNode **top,char customerName[], struct OrderItem* orderInfo)
{
    struct StackNode* newNode = createStackNode(customerName, orderInfo);
    if (newNode != NULL)
    {
        newNode->next = *top;
        *top = newNode;
    }

}
/**
 * @brief Pops a table number and order information from the stack.
 *
 * @param stack Pointer to the Stack.
 * @return Pointer to the popped StackNode.
 */
struct StackNode* pop(struct StackNode **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty.\n");
        return NULL;
    }

    struct StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);

    return temp;
}
void displaystack(struct StackNode* top)
{
    if(top != NULL)
    {
        printf("\n=================================================\n");
        printf("| %-15s | %-15s |\n", "Table Number", "Customer Name\n");
        printf("==================================================\n");

        while (top != NULL)
        {
            printf("| %-15d | %-15s |\n", top->tableNumber, top->customerName); // Update "Details" based on your order information
            top = top->next;
        }

        printf("==================================================\n");
    }
    else
    {
        printf("=================================================\n");
        printf("                        No Data In stack           \n");
        printf("=================================================\n");
    }
}

void clearStack(struct StackNode **top)
{
    while (*top != NULL)
    {
        struct StackNode *temp = *top;
        *top = (*top)->next;
        free(temp);
    }

    printf("Stack cleared successfully.\n");
}
/******************************************************************************
*                          Queue Operation                                    *
******************************************************************************/
/**
 * @brief Loads the menu from the "menu.txt" file into a linked list.
 *
 * @return Pointer to the head of the loaded FoodItem linked list.
 */
struct OrderQueueNode* createOrderQueueNode(struct FoodItem* data)
{
    struct OrderQueueNode* newNode = (struct OrderQueueNode*)malloc(sizeof(struct OrderQueueNode));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

/**
 * @brief Checks if the order queue is empty.
 *
 * @param orderQueue Pointer to the OrderQueue structure.
 * @return 1 if the order queue is empty, 0 otherwise.
 */
int isOrderQueueEmpty(struct OrderQueue* orderQueue)
{
    return front == NULL;
}

/**
 * @brief Enqueues a food item into the order queue.
 *
 * @param front Pointer to the front of the OrderQueue.
 * @param rear Pointer to the rear of the OrderQueue.
 * @param data Pointer to the OrderItem data to be enqueued.
 */
void enqueueOrder(struct OrderQueueNode** front, struct OrderQueueNode** rear, struct OrderItem* data)
{
    struct OrderQueueNode* newNode = createOrderQueueNode(data);
    if (newNode != NULL)
    {
        if (*front == NULL)
        {
            *front = *rear = newNode;
        }
        else
        {
            (*rear)->next = newNode;
            *rear = newNode;
        }
    }
}
/**
 * @brief Enqueues a food item into the order queue.
 *
 * @param front Pointer to the front of the OrderQueue.
 * @param rear Pointer to the rear of the OrderQueue.
 * @param data Pointer to the OrderItem data to be enqueued.
 */
struct OrderQueueNode* dequeueOrder(struct OrderQueueNode** front)
{
    if (*front == NULL)
    {
        printf("Order Queue is empty.\n");
        return NULL;
    }

    struct OrderQueueNode* temp = *front;
    *front = (*front)->next;

    printf("\n=============================================================\n");
    printf("Processing order: %s - Quantity: %d - Customer: %s\n", temp->data->name, temp->data->quantity, temp->data->customerName);
    fflush(stdout); // Flush the output buffer to display the loading animation immediately


    for (int i = 0; i < 25; ++i)
    {
        printf(".");
        fflush(stdout);
        usleep(50000); // Introduce a delay of 500,000 microseconds (0.5 seconds) between dots
    }

    printf("\n");

    printf("Order processed: %s - Quantity: %d - Customer: %s\n", temp->data->name, temp->data->quantity, temp->data->customerName);

    free(temp->data); // Assuming that data is dynamically allocated
    free(temp);

    return temp; // Return the dequeued node
}

/**
 * @brief Displays the current order queue with order details.
 *
 * @param front Pointer to the front of the OrderQueue.
 */
void displayOrderQueue(struct OrderQueueNode** front)
{
    if (*front != NULL)
    {
        printf("=========================================================================================================\n");
        printf("| %-5s | %-20s | %-30s | %-10s | %-20s |\n", "S.No.", "Customer Name", "Item Name", "Quantity", "Price");
        printf("=========================================================================================================\n");

        struct OrderQueueNode* current = *front;
        int serialNumber = 1;
        while (current != NULL)
        {
            printf("| %-5d | %-20s | %-30s | %-10d | $%-20.2f |\n", serialNumber, current->data->customerName, current->data->name, current->data->quantity, current->data->price);
            current = current->next;
            serialNumber++;
        }

        printf("=========================================================================================================\n");
    }
    else
    {
        printf("=========================================================================================================\n");
        printf(" No Order queue\n");
        printf("=========================================================================================================\n");
    }
}

/******************************************************************************
*                          Free Memory                                        *
******************************************************************************/
/**
 * @brief Frees the memory allocated for the FoodItem and OrderItem linked lists.
 *
 * @param menu Pointer to the head of the FoodItem linked list.
 * @param order Pointer to the head of the OrderItem linked list.
 */
void freeMenuAndOrder(struct FoodItem* menu, struct OrderItem* order)
{
    while (menu != NULL)
    {
        struct FoodItem* tempMenu = menu;
        menu = menu->next;
        free(tempMenu);
    }

    while (order != NULL)
    {
        struct OrderItem* tempOrder = order;
        order = order->next;
        free(tempOrder);
    }
}

int main()
{
    struct FoodItem* menu = NULL;
    struct OrderItem* order = NULL;
    struct OrderQueueNode* orderQueue = NULL;
    struct StackNode* top = NULL;

a:
    menu = loadMenuFromFile();
    printf("Welcome to Cafeteria Management System\n");
    int choice;
    char itemName[50];
    float itemPrice;
    int itemQuantity;
    char customerName[100];
    char editItemName[50];
    int isAuthenticated = 0;

    do
    {
        printf("\n1. Display Menu\n");
        printf("2. Place Order\n");
        printf("3. Display Order Queue\n");
        printf("4. Admin Login\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayMenu(menu);
            break;
        case 2:
            printf("Enter your name: ");
            scanf("%s", customerName);
            printf("Enter item name to order: ");
            scanf("%s", itemName);
            printf("Enter quantity to order: ");
            scanf("%d", &itemQuantity);
            if(placeOrder(&menu, &order, itemName, itemQuantity, customerName) == 1)
            {
                itemPrice = getPriceByName(menu, itemName);

                struct FoodItem* orderedItem = createFoodItemNode(itemName, itemPrice, itemQuantity);
                enqueueOrder(&front, &rear, createOrderItemNode(itemName, itemPrice, itemQuantity, customerName));
                push(&top,customerName,createOrderItemNode(itemName, itemPrice, itemQuantity, customerName));

            }

            break;
        case 3:
            displayOrderQueue(&front);
            break;
        case 4:
            isAuthenticated = authenticate(&admin);
            break;
        case 5:
            goto b;
            break;
        default:
            printf("Invalid choice.\n");

        }

        if (isAuthenticated)


        {
            do
            {
                printf("\nCafeteria Management System\n");
                printf("Enter your choice: \n");
                printf("1. Add Food Item\n");
                printf("2. Edit Food Item\n");
                printf("3. Delete Food Item\n");
                printf("4. Place Order\n");
                printf("5. Display Menu\n");
                printf("6. Display Order Summary\n");
                printf("7. Display stack\n");
                printf("8. Display Order queue\n");
                printf("9. Process one Order \n");
                printf("10. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    printf("Enter item name: ");
                    scanf("%s", itemName);
                    printf("Enter item price: ");
                    scanf("%f", &itemPrice);
                    printf("Enter item quantity: ");
                    scanf("%d", &itemQuantity);
                    addFoodItem(&menu, itemName, itemPrice, itemQuantity);
                    break;
                case 2:
                    // New case to edit a food item
                    printf("Enter the name of the item to edit: ");
                    scanf("%s", editItemName);
                    editFoodItem(&menu, editItemName);
                    break;
                case 3:
                    printf("Enter item name to delete: ");
                    scanf("%s", itemName);
                    deleteItemFromFile(itemName);
                    deleteFoodItem(&menu, itemName);
                    break;
                case 4:
                    printf("Enter customer's name: ");
                    scanf("%s", customerName);
                    printf("Enter item name to order: ");
                    scanf("%s", itemName);
                    printf("Enter quantity to order: ");
                    scanf("%d", &itemQuantity);
                    if(placeOrder(&menu, &order, itemName, itemQuantity, customerName) == 1)
                    {
                        itemPrice = getPriceByName(menu, itemName);

                        struct FoodItem* orderedItem = createFoodItemNode(itemName, itemPrice, itemQuantity);
                        enqueueOrder(&front, &rear, createOrderItemNode(itemName, itemPrice, itemQuantity, customerName));
                        push(&top,customerName,createOrderItemNode(itemName, itemPrice, itemQuantity, customerName));

                    }

                    break;
                case 5:
                    displayMenu(menu);
                    break;
                case 6:
                    displayOrderSummary(order);
                    showtotal(order);
                    break;

                case 7:
                    displaystack(top);
                    break;
                case 8:
                    displayOrderQueue(&front);
                    break;
                case 9:
                    if (!isOrderQueueEmpty(&front))
                    {
//
                        dequeueOrder(&front);

                    }
                    else
                    {
                        printf("Order Queue is empty. No orders to process.\n");
                    }
                    break;
                case 10:
                    saveMenuToFile(menu);
                    goto a;
                    break;



                default:
                    printf("Invalid choice! Please enter a valid option.\n");
                }
            }
            while (choice != 11);
        }
    }
    while (choice != 5);
b:
    freeMenuAndOrder(menu, order);
    menu = NULL;
    order = NULL;

    while (front != NULL)
    {
        struct OrderQueueNode* temp = front;
        front = (front)->next;
        free(temp->data);
        free(temp);
    }

    while (top != NULL)
    {
        struct StackNode* temp = top;
        top = top->next;
        free(temp->orderInfo);
        free(temp);
    }

    printf("\nThank you for using Cafeteria Management System!\n");
    return 0;
}



