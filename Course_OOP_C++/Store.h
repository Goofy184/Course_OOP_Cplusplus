#pragma once 
#include <iostream>
#include <vector>
#include "ProductInStore.h"
class Store {
private:
    vector<ProductInStore> products;
    class StoreIterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = ProductInStore;
        using pointer = ProductInStore*;
        using reference = ProductInStore&;

        StoreIterator(pointer ptr) : m_ptr(ptr) {}

        StoreIterator() : m_ptr(nullptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }

        StoreIterator& operator++() { m_ptr++; return *this; }

        StoreIterator operator++(int) { StoreIterator tmp = *this; ++(*this); return tmp; }

        friend bool operator== (const StoreIterator& a, const StoreIterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const StoreIterator& a, const StoreIterator& b) { return a.m_ptr != b.m_ptr; };

    private:

        pointer m_ptr;

    };
public:
    Store(); 
    ~Store(); 
    StoreIterator begin();
    StoreIterator end();
    void addProduct(const ProductInStore& product); 
    double getTotalProfit(); 
};


