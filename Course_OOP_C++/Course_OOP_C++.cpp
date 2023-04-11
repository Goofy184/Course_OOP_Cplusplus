#include <iostream>
#include <string>
#include "Store.h"
#include "ProductOnStock.h"
#include "ProductInStore.h"

int main() {
    Store store;
    ProductInStore product1("Product1", "01.01.2022", "Cert1", 100, 0.2, "01.01.2023");
    ProductInStore product2("Product2", "02.01.2022", "Cert2", 200, 0.3, "02.01.2023");
    store.addProduct(product1);
    store.addProduct(product2);
    double totalProfit = store.getTotalProfit();
    cout << "Total profit: " << totalProfit << endl;

    for (ProductInStore& product : store.getProducts()) {
        cout << product << endl;
    }

    return 0;
}