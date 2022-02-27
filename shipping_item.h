#ifndef SHIPPING_ITEM_H
#define SHIPPING_ITEM_H

//struct for Address
struct Address{
    std::string name;
    std::string street_address;
    std::string city;
    std::string state;
    std::string zip;
};

//ShippingItem Base Class
class ShippingItem{
protected:
    Address address_;
    double weight_;
    double length_;
    bool delivered_;

public:
    //static constant
    static double kMaxWeight;
    static double kMaxSize;
    static double kMinSize;

    //constructors and destructor
    ShippingItem(){address_.name = "unknown", weight_ = 2; length_ = 12,
                   delivered_ = false;}
    ShippingItem(Address address, double weight, double length);
    ~ShippingItem(){};

    //getters
    Address get_address() const {return address_;}
    double get_weight() const {return weight_;}
    double get_length() const {return length_;}
    bool get_delivered() const {return delivered_;}

    //setters
    void set_address(Address address);
    void set_weight(double weight);
    virtual void set_length(double length);
    void set_delivered(bool delivered);

    //other methods
    void MarkDelivered();
    virtual double Volume() const = 0;
    virtual void Display(std::ostream &out) const = 0;
};

#endif