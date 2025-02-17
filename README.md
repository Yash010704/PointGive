# Customer Loyalty Program

## Overview
This is a simple C++ program that reads customer data from a CSV file and allows users to check their loyalty points, order history, and bill amount. Users can also redeem their points if they have enough accumulated.

## Features
- Reads customer data from a CSV file.
- Allows users to enter their mobile number to fetch their details.
- Displays customer details including name, number of orders, loyalty points, and total bill amount.
- Provides an option to redeem loyalty points if the user has at least 10 points.
- Calculates the net bill amount after redemption.

## Prerequisites
- A C++ compiler (GCC, MSVC, or Clang)
- A CSV file containing customer data

## CSV Format
The CSV file should have the following structure:
```csv
Name,Contact_No,No_of_Orders,No_of_Points,Bill_Amount
John Doe,1234567890,5,15,500
Jane Smith,0987654321,3,8,300
```

## Usage
1. Run the executable:
   ```bash
   ./customer_loyalty
   ```
2. Enter your mobile number when prompted.
3. View your details and choose whether to redeem your points.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

