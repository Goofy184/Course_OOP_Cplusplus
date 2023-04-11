#pragma once
#include <iostream>
#include <vector>
#include "ProductInStore.h"

class Store {
private:
	class Iterator {
	private:
		vector<ProductInStore> it;
		typedef vector<ProductInStore>::iterator iterator;
		typedef vector<ProductInStore>::const_iterator const_iterator;
    public:
        Iterator() {}


        void push_back(const ProductInStore& product) {
            it.push_back(product);
        }

        inline iterator begin() noexcept { return it.begin(); }
        inline const_iterator cbegin() const noexcept { return it.cbegin(); }
        inline iterator end() noexcept { return it.end(); }
        inline const_iterator cend() const noexcept { return it.cend(); }


    };
private:
    Iterator products;

public:
    Store();
    ~Store();

    void addProduct(const ProductInStore& product);

    Iterator getProducts();

    double getTotalProfit();
};