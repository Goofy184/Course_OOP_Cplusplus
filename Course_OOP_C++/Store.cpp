#include "Store.h"

Store::Store() {
	products = Iterator();
}

Store::~Store() {}

void Store::addProduct(const ProductInStore& product) {
	products.push_back(product);
}

Store::Iterator Store::getProducts() {
	return products;
}

double Store::getTotalProfit() {
	double profit = 0;
	for (ProductInStore& product : products) {
		profit += product.getPrice();
	}
	return profit;
}