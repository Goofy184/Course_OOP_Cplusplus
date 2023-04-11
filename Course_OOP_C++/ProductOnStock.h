#pragma once
#include <iostream>
using namespace std;
class ProductOnStock {
protected:
    string productName;
    string manufacturingDate;
    string qualityCertificate;
    double cost;

public:
    ProductOnStock(string name, string date, string certificate, double cost);
    ~ProductOnStock();

    void setProductName(string name);
    void setManufacturingDate(string date);
    void setQualityCertificate(string certificate);
    void setCost(double cost);

    string getProductName();
    string getManufacturingDate();
    string getQualityCertificate();
    double getCost() const;

    virtual double getPrice();

    ProductOnStock& operator+=(double value);
    ProductOnStock& operator-=(double value);
    ProductOnStock& operator=(const ProductOnStock& other);

    friend istream& operator>>(istream& in, ProductOnStock& product);
    friend ostream& operator<<(ostream& out, const ProductOnStock& product);
};
