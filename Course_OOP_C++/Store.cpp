#include "Store.h" 
Store::Store() {}

Store::~Store() {}
void Store::addProduct(const ProductInStore& product) {
	products.push_back(product); 
}

Store::StoreIterator Store::begin()
{
	if (products.empty()) {
		return StoreIterator();
	}
	return StoreIterator(&products[0]);
}

Store::StoreIterator Store::end()
{
	if (products.empty()) {
		return StoreIterator();
	}
	return StoreIterator(&products[0] + products.size());
}


double Store::getTotalProfit() {
	double profit = 0; 
	for (ProductInStore& product : products) { 
		profit += product.getPrice(); 
	}
	return profit; 
}


