#pragma once 
#include <iostream>
#include <vector>
#include "ProductInStore.h"

class Store {
private:
    //class Iterator {
    //private:
    //    vector<ProductInStore> it; 
    //    typedef vector<ProductInStore>::iterator iterator; 
    //    typedef vector<ProductInStore>::const_iterator const_iterator; 
    //    public:
    //    Iterator() {} 

    //    void push_back(const ProductInStore& product) {
    //        it.push_back(product);
    //    }

    //    inline iterator begin() noexcept { return it.begin(); }
    //    inline const_iterator cbegin() const noexcept { return it.cbegin(); }
    //    inline iterator end() noexcept { return it.end(); }
    //    inline const_iterator cend() const noexcept { return it.cend(); }
    //};
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


