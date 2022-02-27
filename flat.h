#ifndef FLAT_H
#define FLAT_H
#include "shipping_item.h"

//Flat subclass for ShippingItem
class Flat : public ShippingItem{
private:
    double height_;
    double thickness_;

public:
    Flat(){address_.name = "unknown", weight_ = 2, length_ = 12,
           delivered_ = false, height_ = 8, thickness_ = .4;}
    Flat(Address address, double weight, double length, double height,
         double thickness);
    ~Flat(){};

    //getter
    double get_height() const {return height_;}
    double get_thickness() const {return thickness_;}

    //setter
    void set_length(double length);
    void set_height(double height);
    void set_thickness(double thickness);

    //other methods
    double Volume() const;
    void Display(std::ostream &out) const;
};

#endif