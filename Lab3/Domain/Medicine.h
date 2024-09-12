#pragma once
#include <string>
using std::string;

struct Date {
    int day, month, year;
};


class Medicine {
private:
    string name{}, origin{};
    int quantity{};
    float price{};
    Date expDate{};

public:
    Medicine(string _name, string _origin, Date _expDate, int _quantity, float _price);

    string getName() const;

    string getOrigin() const;

    Date getExpDate() const;

    float getPrice() const;

    int getQuantity() const;

    void setPrice(float newPrice);

    void setQuantity(int newQuantity);
};

