#include "ProductInStore.h" 

ProductInStore::ProductInStore(string name, string date, string certificate, double cost, double markup, string expirationDate)
    : ProductOnStock(name, date, certificate, cost), 
    markup(markup) { 
    setExpirationDate(expirationDate);
    if (boost::gregorian::from_string(expirationDate) < boost::gregorian::from_string(date)) {
        throw exception("Expiration Date can not be before manufacturing date");
    }

} 

ProductInStore::~ProductInStore() {}

void ProductInStore::setMarkup(double markup) {
    this->markup = markup;
}
void ProductInStore::setExpirationDate(string date) {
    validateDate(date);
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

