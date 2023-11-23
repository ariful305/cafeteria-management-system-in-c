# <a name="_jjmbdzow3y55"></a><a name="_svqjtxu2kwoy"></a><a name="_xhyxgzkett17"></a><a name="_41y3xx725x80"></a><a name="_b9rcdwbdf9c2"></a><a name="_4my4fxj5oc68"></a><a name="_wawzm9b1imt8"></a><a name="_w9jbd310xm2g"></a><a name="_mstt4d4i5t1l"></a>**Cafeteria Management System Documentation**


# <a name="_pxju4yt7c3l7"></a>**Overview**

The Cafeteria Management System is a program designed to manage food items, orders, and the overall operation of a cafeteria. It provides functionality for users to view the menu, place orders, and for administrators to manage food items and view order details. The system utilizes various data structures such as linked lists, queues, and stacks for efficient data management.
## <a name="_o342boyc782f"></a>**Table of Contents**
1. Data Structures
1. Global Variables
1. Authentication
1. Food Management
1. Order Management
1. File Operations
1. Stack Operations
1. Queue Operations
1. Freeing Memory
1. Main Function

## <a name="_syjijq697czo"></a>**Data Structures**
### <a name="_l2q9uee9y366"></a>**1. FoodItem**
- Represents a food item in the cafeteria.
- Attributes:
  - name: Name of the food item.
  - price: Price of the food item.
  - quantity: Quantity of the food item in stock.
  - next: Pointer to the next FoodItem in the linked list.
###
### ![](Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.002.png)

### <a name="_jid3hrujsm7x"></a><a name="_46pk1ybkosiq"></a><a name="_tgoo22bvhk6p"></a>**2. OrderItem**
- Represents an item in a customer's order.
- Attributes:
  - name: Name of the ordered item.
  - customerName: Name of the customer placing the order.
  - price: Total price of the ordered item.
  - quantity: Quantity of the ordered item.
  - next: Pointer to the next OrderItem in the linked list.
###
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.003.png)
### <a name="_liwnsedv6pkx"></a>**3. OrderQueueNode**
- Represents a node in the order queue.
- Attributes:
  - data: Pointer to the OrderItem associated with the node.
  - next: Pointer to the next OrderQueueNode in the linked list.
###
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.004.png)

### <a name="_pzm41e1zlyb8"></a><a name="_69mp1joasjel"></a>**4. StackNode**
- Represents a node in the stack for managing table orders.
- Attributes:
  - tableNumber: The table number associated with the order.
  - customerName: Name of the customer associated with the order.
  - orderInfo: Pointer to the OrderItem associated with the order.
  - next: Pointer to the next StackNode in the stack.
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.005.png)
### <a name="_xmd73x79lqh3"></a>**5. User**
- Represents a user with authentication credentials.
- Attributes:
  - username: User's username.
  - password: User's password.
###
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.006.png)
### <a name="_x74o7irx4m1t"></a><a name="_e6bxmva29nck"></a><a name="_rr234dpsczls"></a>**Global Variables**
- admin: An instance of the User struct representing the administrator.
- front and rear: Pointers to the front and rear of the order queue.
- menu: Pointer to the head of the FoodItem linked list.

### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.007.png)
### <a name="_pc6ua7993bt1"></a><a name="_ildc7hh7eqk3"></a>**Authentication**
- The authenticate function compares user-provided credentials with the predefined administrator credentials (admin).
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.008.png)

### <a name="_n2rv6kvfyabd"></a>**Food Management**
- Functions for creating, editing, deleting, and displaying food items in the menu.
- Example functions: createFoodItemNode, addFoodItem, editFoodItem, deleteFoodItem, displayMenu. 
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.009.png)
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.010.png)
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.011.png)
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.012.png)
###
###
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.013.png)
### <a name="_mqwpmce6ebig"></a><a name="_70bmvifd573i"></a><a name="_max5o5h8lq9w"></a><a name="_cu7dyex3iu9l"></a><a name="_nsq2giwrbcdo"></a><a name="_xwwhqukjk4ix"></a>**Order Management**
- Functions for creating, placing, and displaying orders.
- Example functions: createOrderItemNode, placeOrder, displayOrderSummary, showtotal.

### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.014.png)
## ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.016.png)<a name="_p1j9v97tjas9"></a><a name="_c3do1ltrfhq0"></a>**	
## ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.017.png)
###
### <a name="_hr7f7knqyyai"></a><a name="_cx05ik35kksb"></a><a name="_x3ptepkg0ja3"></a>**File Operations**
- Functions for loading and saving the menu from/to a file and deleting a food item from the file.
- Example functions: loadMenuFromFile, saveMenuToFile, deleteItemFromFile.




### ![](Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.018.png)
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.019.png)
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.020.png)
###  <a name="_ioxirejt2d7i"></a><a name="_i9ghj0vxr16f"></a><a name="_zh8cy7kt40l4"></a>**Stack Operations**
- Functions for managing table orders using a stack.
- Example functions: createStackNode, push, pop, displaystack, clearStack.
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.021.png)
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.022.png)
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.023.png)
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.024.png)
##
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.025.png)
### <a name="_ag41dhdx6r2r"></a><a name="_9yj18gv5ntzr"></a><a name="_ioz51rouhtjg"></a><a name="_l1dbvmnyqli4"></a><a name="_s13pfjl14bzt"></a><a name="_wfijlp8b7i0d"></a><a name="_qa5gm5jmor9o"></a>**Queue Operations**
- Functions for managing customer orders using a queue.
- Example functions: createOrderQueueNode, enqueueOrder, dequeueOrder, displayOrderQueue.
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.026.png)
###  ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.027.png)
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.028.png)
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.029.png)
##
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.030.png)
### <a name="_82cfzc6zvula"></a><a name="_41vtz3mmft0t"></a><a name="_1fjz7k9kkqgf"></a><a name="_rqysgvlodzo7"></a><a name="_1z0b8cxkc7kx"></a><a name="_b43jjarp9wzb"></a><a name="_a1hyyymmqin9"></a>**Freeing Memory**
- Function freeMenuAndOrder to release allocated memory for FoodItem and OrderItem linked lists.
### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.031.png)
##
### <a name="_2ibxax1bp3zp"></a><a name="_pbh0ugpw1fsr"></a><a name="_4xkv3ymjbfk3"></a>**Main Function**
The main function initializes global variables, loads the menu, and presents a menu for users and administrators. The program includes various functionalities like displaying the menu, placing orders, managing food items, and processing orders. It also provides an administrative login for additional features.

**For User menu**

### ![](images/Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.032.png)

**For Admin menu![](Aspose.Words.d763cd31-ecbc-449c-a646-937f31083637.033.png)**

**Here's an explanation of why each data structure is used:**

**Linked List (FoodItem and OrderItem):**

**Reason:** Linked lists are used to maintain dynamic lists of food items in the menu (struct FoodItem) and orders (struct OrderItem). Linked lists provide a flexible way to manage and modify the menu and orders, allowing for easy insertion, deletion, and traversal of items.

**Queue (OrderQueue):**

**Reason:** The order queue (struct OrderQueueNode) is implemented as a queue to manage incoming orders in a first-come-first-serve manner. When customers place orders, they are added to the end of the queue, and orders are processed from the front. This ensures that orders are processed in the order they are received, following the queue data structure's behavior.

**Stack (StackNode):**

**Reason:** The stack (struct StackNode) is used to keep track of tables and their associated order information. When a customer places an order, it is pushed onto the stack, and when the order is processed or cleared, it is popped from the stack. This follows the Last In, First Out (LIFO) property of a stack, which is suitable for managing the history of orders at tables.



