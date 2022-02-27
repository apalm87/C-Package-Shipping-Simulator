#ifndef TUBE_H
#define TUBE_H
#include "shipping_item.h"

// Tube subclass for ShippingItem
class Tube : public ShippingItem{
private:
    double circumference_;
public:
    static const double kPi;

    //constructors and destructor
    Tube(){address_.name = "unknown", weight_ = 2, length_ = 12,
           delivered_ = false, circumference_ = 12;}
    Tube(Address address, double weight, double length, double circumference);
    ~Tube(){};

    //getter
    double get_circumference() const {return circumference_;}
    //setter
    void set_circumference(double circumference);

    //other methods
    double Volume() const;
    double Girth() const {return circumference_;}
    void Display(std::ostream &out) const;

};

#endif