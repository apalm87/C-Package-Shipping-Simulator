#include <iostream>
#include <fstream>
#include "load.h"
#include "shipping_item.h"
#include "carton.h"
#include "flat.h"
#include "tube.h"

/**
 *@bried FillLoad - Method that reads from a file and puts contents from the
 * file into a vector. Contents are determined by type C, F, and T.
 * @param filename - String parameter that receives the file name.
 */
void Load::FillLoad(std::string filename) {

    //variables
    Address address_fl;
    Flat flat_fl;
    std::ifstream in (filename);

    //failsafe
    if (in.fail()){
        std::cout << "Unable to open file" << std::endl;
        return;
    }

    //additional variables for reading the file
    std::string type;
    double weight;
    double length;
    double side1; //cartons only
    double side2; //cartons only
    double side3; //cartons only
    double height; //flats only
    double thickness; // flats only
    double circumference; //tubes only
    double volume;

    while (in >> type){
        //for Flats
        if(type == "F"){
            in.ignore();
            std::getline(in,address_fl.name);
            std::getline(in, address_fl.street_address);
            std::getline(in,address_fl.city);
            std::getline(in, address_fl.state);
            std::getline(in, address_fl.zip);
            in >> weight;
            in >> length;
            in >> height;
            in >> thickness;
            in.ignore();

            shipping_item_.push_back(new Flat(address_fl, weight, length, height, thickness));
            volume = shipping_item_[count_]->Volume();
        }
        //for Cartons
        else if(type == "C"){
            in.ignore();
            std::getline(in,address_fl.name);
            std::getline(in, address_fl.street_address);
            std::getline(in,address_fl.city);
            std::getline(in, address_fl.state);
            std::getline(in, address_fl.zip);
            in >> weight;
            in >> side1;
            in >> side2;
            in >> side3;
            in.ignore();
            shipping_item_.push_back(new Carton(address_fl, weight,
                                                side1, side2, side3));
            volume = shipping_item_[count_]->Volume();
        }
        //for Tube
        if(type == "T"){
            in.ignore();
            std::getline(in,address_fl.name);
            std::getline(in, address_fl.street_address);
            std::getline(in,address_fl.city);
            std::getline(in, address_fl.state);
            std::getline(in, address_fl.zip);
            in >> weight;
            in >> length;
            in >> circumference;
            in.ignore();
            shipping_item_.push_back(new Tube(address_fl, weight, length,
                                              circumference));
            volume = shipping_item_[count_]->Volume();
        }
        count_++;
        total_weight_ += weight;
        total_volume_ +=volume;
    }

}

/**
 * Destructor - Destructor that deletes all items in a vector
 */
Load::~Load() {
    for(ShippingItem* &one_ptr: shipping_item_){
        delete one_ptr;
        one_ptr = NULL;
    }
}

/**
 * @bried DisplayNextDelivery - method that displays the address and package
 * type information, and prints to the output file.
 * @param out - parameter that performs output display
 */
void Load::DisplayNextDelivery(std::ofstream &out) const {
        out << shipping_item_[index_]->get_address().name << "\n"
            << shipping_item_[index_]->get_address().street_address << "\n"
            << shipping_item_[index_]->get_address().city << ", "
            << shipping_item_[index_]->get_address().state << " "
            << shipping_item_[index_]->get_address().zip << std::endl;
            shipping_item_[index_]->Display(out);
}

/**
 * @brief ItemDelivered - method that calls set delivered of the index item,
 * and sets it to true.
 */
void Load::ItemDelivered() {
    shipping_item_[index_]->set_delivered(true);
    index_++;
}

/**
 * @brief NotDeliverable - method that calls set delivered of the index item,
 * and sets it to false.
 */
void Load::NotDeliverable() {
    shipping_item_[index_]->set_delivered(false);
    index_++;
}

/**
 * @brief HowManyDelivered - method that loops through shipping_item_, and
 * counts how many items are set to true
 * @return count - the number of items set to true.
 */
int Load::HowManyDelivered() const {
    int count = 0;
    for(ShippingItem* one_ptr: shipping_item_){
        if (one_ptr->get_delivered() == true){
           count++;
        }
    }
    return count;
}

/**
 * @brief HowManyDelivered - method that loops through shipping_item_, and
 * counts how many items are set to true
 * @return count - the number of items set to true.
 */
int Load::HowManyNotDelivered() const {
    int count = 0;
    for(ShippingItem* one_ptr: shipping_item_){
        if (one_ptr->get_delivered() == false){
            count++;
        }
    }
    return count;
}