
#include "Medicine.h"
#include <stdexcept>
#include <utility>


Medicine::Medicine(std::string _name, std::string _origin, Date _expDate, int _quantity, float _price) {
    name = std::move(_name);
    origin = std::move(_origin);
    expDate = _expDate;
    quantity = _quantity;
    price = _price;
}


string Medicine::getName() const { return name; }


string Medicine::getOrigin() const { return origin; }


Date Medicine::getExpDate() const { return expDate; }


float Medicine::getPrice() const { return price; }


int Medicine::getQuantity() const { return quantity; }


void Medicine::setPrice(float newPrice) {
    if (newPrice < 0)
        throw std::invalid_argument("Negative prices are not valid.");
    price = newPrice;
}


void Medicine::setQuantity(int newQuantity) {
    if (newQuantity < 0)
        throw std::invalid_argument("Negative quantities are not valid.");
    quantity = newQuantity;
}