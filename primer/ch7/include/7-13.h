//
// Created by baul on 4/6/20.
//

#ifndef CH6_7_2_H
#define CH6_7_2_H

#include <iostream>
#include <string>

struct Sales_data{
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s){}
    Sales_data(const std::string &s, unsigned n, double p) :
               bookNo(s), units_sold(n), revenue(n*p){}
    Sales_data(std::istream &is){
        double price = 0.0;
        is >> bookNo >> units_sold >> price;
        revenue = units_sold * price;
    }

    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

#endif //CH6_7_2_H
