#pragma once 

#include "ProductOnStock.h" 

class ProductInStore : public ProductOnStock {
protected:

    double markup; 
    string expirationDate; 

public:
    ProductInStore(string name, string date, string certificate, 
        double cost, double markup, string expirationDate);
    ~ProductInStore(); 

    void setMarkup(double markup); 
    void setExpirationDate(string date); 

    double getMarkup() const; 
    string getExpirationDate(); 

    virtual double getPrice() override; 
};


