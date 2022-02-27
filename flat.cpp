#include <iostream>
#include <iomanip>
#include "flat.h"

/**
 * @brief set_length - Method that sets length. if its less than kMinSize or
 * greater than 15, throw out_of_range exception.
 * @param length - Parameter of sent length.
 */
void Flat::set_length(double length) {
    if(length < kMinSize || length > 15){
        throw std::out_of_range("Invalid Length");
    }
    length_ = length;
}

/**
 * @brief set_height - Method that sets height. if its less than kMinSize or
 * greater than 12, throw out_of_range exception.
 * @param height - Parameter of sent height.
 */
void Flat::set_height(double height) {
    if(height < kMinSize || height > 12){
        throw std::out_of_range("Invalid Height");
    }
    height_ = height;
}

/**
 * @brief set_thickness - Method that sets thickness. if its less than kMinSize
 * or greater than .75, throw out_of_range exception.
 * @param thickness - Parameter of sent thickness.
 */
void Flat::set_thickness(double thickness) {
    if(thickness < kMinSize || thickness > .75){
        throw std::out_of_range("Invalid Thickness");
    }
    thickness_ = thickness;
}

/**
 * @brief Address - non_default constructor for Flat
 * @param address - sent parameter for flat address
 * @param weight - sent parameter for flat weight
 * @param length - sent parameter for flat length
 * @param height - sent parameter for flat height
 * @param thickness - sent parameter for flat thickness
 */
Flat::Flat(Address address, double weight, double length, double height,
           double thickness) : ShippingItem(address, weight, length){
    try {
        set_length(length);
        set_height(height);
        set_thickness(thickness);
        set_delivered(false);
    } catch (std::out_of_range e) {
        throw;
    }
}

/**
 * @brief Volume - Method that calculates the Flat Volume
 * @return Volume - Returns the total calculated Volume
 */
double Flat::Volume() const {
    double Volume = length_ * height_ * thickness_;
    return Volume;
}

/**
 * @brief Display - Method that display Carton information
 * @param out - displays the output
 */
void Flat::Display(std::ostream &out) const {
    out << std::fixed << std::setprecision(1) <<  "Flat: " << weight_ << " lbs. "
        << length_ << " x " << height_ << " x " << thickness_ << std::endl;
}