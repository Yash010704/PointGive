#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Customer {
    string name;
    string contact_no;
    int no_of_orders;
    int no_of_points;
    int bill_amount;
};

vector<Customer> readCSV(const string &filename) {
    vector<Customer> customers;
    ifstream file(filename);
    string line, word;
    
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return customers;
    }
    
    getline(file, line); // Skip header
    while (getline(file, line)) {
        stringstream ss(line);
        Customer cust;
        
        getline(ss, cust.name, ',');
        getline(ss, cust.contact_no, ',');
        ss >> cust.no_of_orders;
        ss.ignore();
        ss >> cust.no_of_points;
        ss.ignore();
        ss >> cust.bill_amount;
        
        customers.push_back(cust);
    }
    
    file.close();
    return customers;
}

int main() {
    string filename = "C:\\Users\\hp pc\\OneDrive\\Documents\\MyCode\\GIVE_AWAY_POINT\\Book2.csv";
    vector<Customer> customers = readCSV(filename);
    
    string phone_number;
    cout << "Enter your mobile number: ";
    cin >> phone_number;
    
    if (phone_number.length() != 10) {
        cout << "Enter a valid number." << endl;
        return 0;
    }
    
    bool found = false;
    for (const auto &cust : customers) {
        if (cust.contact_no == phone_number) {
            found = true;
            cout << "Fetching your details..." << endl;
            cout << "Name: " << cust.name << endl;
            cout << "Number of orders: " << cust.no_of_orders << endl;
            cout << "Number of points: " << cust.no_of_points << endl;
            cout << "Bill Amount: " << cust.bill_amount << endl;
            
            string question;
            cout << "Do you want to redeem your points? (yes/no): ";
            cin >> question;
            
            if (question == "yes") {
                if (cust.no_of_points >= 10) {
                    int net_bill_amount = cust.bill_amount - cust.no_of_points;
                    cout << "YOU HAVE TO PAY: " << net_bill_amount << endl;
                } else {
                    cout << "Since you have " << cust.no_of_points << " points, you are not eligible for redemption." << endl;
                }
            } else {
                cout << "Thank you!" << endl;
            }
            break;
        }
    }
    
    if (!found) {
        cout << "No entry found." << endl;
    }
    
    return 0;
}
