#include "ProductOnStock.h" 
ProductOnStock::ProductOnStock(string name, string date, string certificate, double cost)
    : productName(name), 
    manufacturingDate(date), 
    qualityCertificate(certificate), 
    cost(cost) {} 

ProductOnStock::~ProductOnStock() {}

void ProductOnStock::setProductName(string name) {
    productName = name; 
}

void ProductOnStock::setManufacturingDate(string date) {
    manufacturingDate = date;
}

void ProductOnStock::setQualityCertificate(string certificate) {
    qualityCertificate = certificate;
}

void ProductOnStock::setCost(double cost) {
    this->cost = cost; 
}

string ProductOnStock::getProductName() {
    return productName;
}

string ProductOnStock::getManufacturingDate() {
    return manufacturingDate;
}

string ProductOnStock::getQualityCertificate() {
    return qualityCertificate; 
}

double ProductOnStock::getCost() const {
    return cost; 
}

double ProductOnStock::getPrice() {
    return cost; 
}

ProductOnStock& ProductOnStock::operator+=(double value) {
    cost += value; 
    return *this; 
}

ProductOnStock& ProductOnStock::operator-=(double value) {
    cost -= value; 
    return *this; 
}

ProductOnStock& ProductOnStock::operator=(const ProductOnStock& other) {
    if (this == &other) return *this; 
    productName = other.productName;
    manufacturingDate = other.manufacturingDate;
    qualityCertificate = other.qualityCertificate;
    cost = other.cost;
    return *this;
}

istream& operator>>(istream& in, ProductOnStock& product) {
    in >> product.productName >> product.manufacturingDate >> product.qualityCertificate >> product.cost;
    return in;
}

ostream& operator<<(ostream& out, const ProductOnStock& product) {
    out << product.productName << " " << product.manufacturingDate << " " << product.qualityCertificate << " " << product.cost;
    return out;
};