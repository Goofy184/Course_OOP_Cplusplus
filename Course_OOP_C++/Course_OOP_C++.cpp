// include necessary libraries and header files
#include <iostream>
#include <string>
#include "Store.h"
#include "ProductOnStock.h"
#include "ProductInStore.h"
#include <fstream>

int main() {
    Store store; 
    string filename = "Course_OOP.txt"; 
    ofstream outputFile(filename); 

    if (!outputFile.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    int productCount; 
    cout << "Enter the number of products: ";
    cin >> productCount;

    for (int i = 0; i < productCount; i++) {
        string name, date, certificate, expirationDate;
        double cost, markup;

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

        try {
            ProductInStore product(name, date, certificate, cost, markup, expirationDate);
            store.addProduct(product); 
        }
        catch (const exception& ex) {
            cout << "Error: " << ex.what() << endl;
        }

    }
    for (auto& product : store) {
        outputFile << product << endl;
    }
    outputFile.close();

    double totalProfit = store.getTotalProfit(); 
    cout << "Total profit: " << totalProfit << endl; 

    return 0; 
}
