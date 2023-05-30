#include "ProductInStore.h" 

ProductInStore::ProductInStore(string name, string date, string certificate, double cost, double markup, string expirationDate)
    : ProductOnStock(name, date, certificate, cost), 
    markup(markup), 
    expirationDate(expirationDate) {} 

ProductInStore::~ProductInStore() {}

void ProductInStore::setMarkup(double markup) {
    this->markup = markup;
}
void ProductInStore::setExpirationDate(string date) {
    expirationDate = date; 
}

double ProductInStore::getMarkup() const {
    return markup;
}

string ProductInStore::getExpirationDate() {
    return expirationDate; 
}

double ProductInStore::getPrice() {
    return cost * (1 + markup); 
}

