#ifndef LOAD_H
#define LOAD_H
#include "shipping_item.h"
#include <vector>

//Load Class
class Load{
private:
    std::vector<ShippingItem*> shipping_item_;
    int index_;
    int count_;
    double total_weight_;
    double total_volume_;
public:
    Load(){index_ = 0, count_ = 0, total_weight_ = 0, total_volume_ = 0;}
    ~Load();

    //getters
    int get_count() const {return count_;}
    double get_total_volume() const{return total_volume_;}
    double get_total_weight() const{return total_weight_;}

    //other methods
    void FillLoad(std::string filename);
    void DisplayNextDelivery(std::ofstream &out) const;
    void ItemDelivered();
    void NotDeliverable();
    int HowManyDelivered() const;
    int HowManyNotDelivered() const;

};

#endif
