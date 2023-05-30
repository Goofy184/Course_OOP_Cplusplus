// include necessary libraries and header files
#include <iostream>
#include <string>
#include "Store.h"
#include "ProductOnStock.h"
#include "ProductInStore.h"
#include <fstream>
#include <boost/date_time/gregorian/gregorian.hpp>

void validateDate(string date){

}

int main() {
    Store store; // create a store object
    string filename = "Course_OOP.txt"; // specify the filename
    ofstream outputFile(filename); // create an output file stream

    // check if the file is open
    if (!outputFile.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    int productCount; // variable to store the number of products
    cout << "Enter the number of products: ";
    cin >> productCount;

    // loop through the number of products
    for (int i = 0; i < productCount; i++) {
        string name, date, certificate, expirationDate;
        double cost, markup;

        // get user input for product details
        cout << "Enter product name: ";
        cin >> name;
        cout << "Enter manufacturing date: ";
        cin >> date;
        cout << "Enter quality certificate: ";
        cin >> certificate;
        cout << "Enter cost: ";
        cin >> cost;
        cout << "Enter markup: ";
        cin >> markup;
        cout << "Enter expiration date: ";
        cin >> expirationDate;
        cout << endl;


        ProductInStore product(name, date, certificate, cost, markup, expirationDate);
        store.addProduct(product); // add the product to the store

    }
    for (auto& product : store) {
        outputFile << product << endl;
    }
    outputFile.close(); // close the output file

    double totalProfit = store.getTotalProfit(); // calculate the total profit
    cout << "Total profit: " << totalProfit << endl; // display the total profit

    return 0; // exit the program
}
