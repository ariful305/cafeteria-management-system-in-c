
# Cafeteria Management System

This is a simple Cafeteria Management System implemented in C. The system allows users to manage a menu of food items, place orders, and perform administrative tasks such as adding, editing, and deleting food items. The system also includes features to display order summaries, manage a stack of orders for each table, and process orders from a queue.

## Features

1. **Display Menu:** View the current menu of food items with details such as name, price, and quantity.

2. **Place Order:** Customers can place orders by specifying their name, the item they want to order, and the quantity.

3. **Display Order Queue:** View the current orders in the queue, including customer names, item names, quantities, and prices.

4. **Admin Login:** Authenticate as an admin to access additional features.

5. **Admin Features:**
   - **Add Food Item:** Add a new food item to the menu.
   - **Edit Food Item:** Modify the details of an existing food item.
   - **Delete Food Item:** Remove a food item from the menu.
   - **Place Order:** Admins can also place orders on behalf of customers.
   - **Display Order Summary:** View a summary of all placed orders, including total sales.
   - **Display Stack:** View the current stack of orders for each table.
   - **Display Order Queue:** View the current orders in the queue.
   - **Process One Order:** Process and dequeue one order from the queue.

6. **Save Menu to File:** The system saves the current menu to a file named "menu.txt" to persist data between sessions.

7. **File Operations:**
   - **Load Menu from File:** Load the menu from the "menu.txt" file at the start of the program.
   - **Save Menu to File:** Save the current menu to the "menu.txt" file.

## Usage

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/cafeteria-management-system.git
   ```

2. Compile the program:

   ```bash
   gcc cafeteria_management_system.c -o cafeteria_management_system
   ```

3. Run the executable:

   ```bash
   ./cafeteria_management_system
   ```

4. Follow the on-screen instructions to interact with the Cafeteria Management System.

## Note

- The system uses a simple text file ("menu.txt") to store the menu items. Make sure the file is present in the same directory as the executable.

- Admin credentials are hardcoded as follows:
  - Username: admin
  - Password: 123

- The system includes a basic authentication mechanism. Users need to enter the correct username and password to access admin features.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or create a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

