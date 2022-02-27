#include <iostream>
#include "shipping_item.h"

//static data members
double ShippingItem::kMaxWeight = 70;
double ShippingItem::kMaxSize = 108;
double ShippingItem::kMinSize = .007;

/**
 * @brief set_address method - sets address_ value to the sent address
 * @param address - sent parameter value of address
 */
void ShippingItem::set_address(Address address){
    address_ = address;
}

/**
 * @brief set_weight method - sets weight_ value to the sent weight. If sent
 * weight is less than 0 or greater than kMaxWeight, throw exception
 * @param weight - sent parameter value of weight
 */
void ShippingItem::set_weight(double weight){
    if (weight < 0 || weight > kMaxWeight) {
        throw std::out_of_range("Invalid Weight.");
    }
    weight_ = weight;
}

/**
 * @brief set_length method - sets length_ value to the sent length. If sent
 * length is less than kMinSize or greater than kMaxSize, throw exception
 * @param length
 */
void ShippingItem::set_length(double length){
    if(length < kMinSize || length > kMaxSize){
        throw std::out_of_range("Invalid Length");
    }
    length_ = length;
}

/**
 * @brief set_delivered - method sets delivered_ value to the sent delivered.
 * @param delivered - parameter value of sent delivered
 */
void ShippingItem::set_delivered(bool delivered){
    delivered_ = delivered;
}

/**
 * @brief ShippingItem non-default constructor
 * @param address - sent parameter of address
 * @param weight - sent parameter of weight
 * @param length - sent parameter of length
 */
ShippingItem::ShippingItem(Address address, double weight, double length)
{
    set_address(address);
    set_weight(weight);
    set_length(length);
    set_delivered(false);
}

/**
 * @brief MarkDelivered - sets delivered_ data member to true;
 */
void ShippingItem::MarkDelivered() {
    delivered_ = true;
}
