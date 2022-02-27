#include <iostream>
#include <iomanip>
#include "tube.h"

//static data member
double const Tube::kPi = 3.14159;

/**
 * @brief set_circumference - Method that sets circumference. if circumference
 * is less than min size or greater than length + circumference is greater than
 * max size, throw excewption.
 * @param circumference
 */
void Tube::set_circumference(double circumference) {
    if (circumference < kMinSize || (length_ + circumference) > kMaxSize){
        throw std::out_of_range("Invalid circumference");
    }
    circumference_ = circumference;
}

/**
 * @brief - default Tube constructor. Uses a try catch block for
 * invalid information.
 * @param address - sent parameter for address
 * @param weight  - sent parameter for weight
 * @param length  - sent parameter for length
 * @param circumference - sent parameter for circumference
 */
Tube::Tube(Address address, double weight, double length,
           double circumference) : ShippingItem(address, weight, length){
    try {
        set_circumference(circumference);
        set_delivered(false);
    } catch (std::out_of_range e) {
        throw;
    }
}

/**
 * @brief Volume - method that calculates Tube volume.
 * @return volume - returns the total volume of the tube.
 */
double Tube::Volume() const {
    double volume = kPi * (circumference_ / (2.0 * kPi)) *
            (circumference_ / (2.0 * kPi)) * length_;
    return volume;
}

/**
 * @brief Display - Method that display Tube information
 * @param out - displays the output
 */
void Tube::Display(std::ostream &out) const {
    out << std::fixed << std::setprecision(1) <<  "Tube: " << weight_ << " lbs. "
        << length_ << " x " << circumference_ << std::endl;
}


