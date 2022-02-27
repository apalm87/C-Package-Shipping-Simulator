/**
 * @file - load_class
 * @author - Arthur Palmer
 * @brief - main for the load_class program. This program simulates shipping
 * different types of packages for a shipping company. Package types includes
 * cartons, flats, and tubes.
 * @return 0 - return 0 when program runs successfully.
 */
#include <iostream>
#include <fstream>
#include "shipping_item.h"
#include "carton.h"
#include "flat.h"
#include "tube.h"
#include "load.h"

using namespace  std;

int main() {
  cout << "Part 2.2: Use the Carton Class in Main.cpp\n";
  Address address;
  address.name = "Steven Rodgers";
  address.street_address = "123 American Way.";

  // Create a Carton object using the new constructor.
  // When using this constructor, use try/catch blocks to handle
  // the exceptions.
  // Use the Carton object to call the getter and setter methods.
  // Print out the results to see that the methods are doing what is expected.
  // When calling the setters, use try/catch blocks to handle the exceptions.
  // Use the Carton object to call the Display method to print to cout.

  try{
      Carton carton1(address, 41.4, 31.2, 8.6, 8.6);

      cout << "Name:" << address.name << endl;
      cout << "Street Address: " << address.street_address << endl;
      cout << "Weight: " << carton1.get_weight() << endl;
      cout << "Height: " << carton1.get_height() << endl;
      cout << "Width: " << carton1.get_width() << endl;
      cout << "Length: " << carton1.get_length() << endl;
      cout << "Volume: " << carton1.Volume() << endl;

      carton1.Display(cout);
      carton1.set_weight(55);
      carton1.set_height(20);
      carton1.set_width(14);
      carton1.set_length(22);

      cout << "Name:" << address.name << endl;
      cout << "Street Address: " << address.street_address << endl;
      cout << "Weight: " << carton1.get_weight() << endl;
      cout << "Height: " << carton1.get_height() << endl;
      cout << "Width: " << carton1.get_width() << endl;
      cout << "Length: " << carton1.get_length() << endl;
      cout << "Volume: " << carton1.Volume() << endl;

      carton1.Display(cout);

  } catch(exception e){}

  cout << "\nPart 3.3: Use the Flat Class in Main.cpp\n";
  // Create Flat objects using the default and non-default constructors.
  // When using the non-constructor, use try/catch blocks to handle the
  // exceptions.
  // Use the Flat objects to call the getter and setter methods.
  // Print out the results to see how these getters and setters are working.
  // When calling the setters, use try/catch blocks to handle the exceptions.
  // Use the Flat objects to call the Volume and Display methods.
  // Print out the results to cout.

  Flat flat1;
  try{
      Flat flat2(address, 1, 14, 11, .5);

      flat1.set_weight(1.5);
      flat1.set_length(10);
      flat1.set_height(5);
      flat1.set_thickness(.25);

      cout << "Name:" << address.name << endl;
      cout << "Street Address: " << address.street_address << endl;
      cout << "Weight: " << flat1.get_weight() << endl;
      cout << "Length: " << flat1.get_length() << endl;
      cout << "Height: " << flat1.get_height() << endl;
      cout << "Thickness: " << flat1.get_thickness() << endl;
      cout << "Volume:" << flat1.Volume() << endl;

      flat1.Display(cout);

      cout << "Name:" << address.name << endl;
      cout << "Street Address: " << address.street_address << endl;
      cout << "Weight: " << flat2.get_weight() << endl;
      cout << "Length: " << flat2.get_length() << endl;
      cout << "Height: " << flat2.get_height() << endl;
      cout << "Thickness: " << flat2.get_thickness() << endl;
      cout << "Volume:" << flat2.Volume() << endl;

      flat2.Display(cout);

  } catch(exception e){}


  cout << "\nPart 4.3: Use the Tube Class in Main.cpp";

  // 1. Create Tube objects using the default and non-default constructors.
  // When using the non-constructor, use try/catch blocks to handle the
  // exceptions.

  // Use the Tube objects to call the getter and setter methods.
  // Print out the results to see how these getters and setters are working.
  // When calling the setters, use try/catch blocks to handle the exceptions.

  // Use the Tube objects to call the Volume, Girth and Display methods.
  // Print out the results to cout.

  Tube tube1;
  try{
      Tube tube2 (address, 4, 7, 5);
      cout << "Circumference: " << tube2.get_circumference() << endl;
      tube1.set_circumference(2.5);
      cout << "Circumference: " << tube1.get_circumference() << endl;

      cout << "Volume: " << tube1.Volume() << endl;
      cout << "Girth: " << tube1.Girth() << endl;

      tube1.Display(cout);

  } catch(exception e){}

  cout << "\nPart 5.3: Use the Load Class in Main.cpp\n";

  // 1. Create a Load object.
  Load* load1 = new Load;
  std::string filename = "../../load_1.txt";
  std::ofstream out ("../../output.txt");

  // 2. Use the Load object to call the getter methods.
  // Print out the results to see how these getters are working.
  // Do this right after the Load object is created and after it
  // is filled from the file.
  cout << "\nBefore: \n";
  cout << "Count: " << load1->get_count() << endl;
  cout << "Total Volume: " << load1->get_total_volume() << endl;
  cout << "Total Weight: " << load1->get_total_weight() << endl;

  //3. Use the Load object to call the FillLoad method.
  // Then call the DisplayNextDelivery, ItemDelivered, NotDeliverable,
  // HowManyDelivered, and HowManyNotDelivered methods multiple times
  // to see how these work when making deliveries.

  load1->FillLoad(filename);
  cout << "\nAfter: \n";
  cout << "Count: " << load1->get_count() << endl;
  cout << "Total Volume: " << load1->get_total_volume() << endl;
  cout << "Total Weight: " << load1->get_total_weight() << endl;

  cout << "Item Delivered" << endl;
  load1->DisplayNextDelivery(out);
  cout << "How many delivered: "<< load1->HowManyDelivered() << endl;
  cout << "How many not delivered: " << load1->HowManyNotDelivered() << endl;
  load1->ItemDelivered();
  cout << "How many delivered: "<< load1->HowManyDelivered() << endl;
  cout << "How many not delivered: " << load1->HowManyNotDelivered() << endl;
  load1->DisplayNextDelivery(out);
  load1->NotDeliverable();
  cout << "How many delivered: "<< load1->HowManyDelivered() << endl;
  cout << "How many not delivered: " << load1->HowManyNotDelivered() << endl;
  load1->DisplayNextDelivery(out);
  load1->ItemDelivered();
  cout << "How many delivered: "<< load1->HowManyDelivered() << endl;
  cout << "How many not delivered: " << load1->HowManyNotDelivered() << endl;
  load1->DisplayNextDelivery(out);
  load1->ItemDelivered();
  cout << "How many delivered: "<< load1->HowManyDelivered() << endl;
  cout << "How many not delivered: " << load1->HowManyNotDelivered() << endl;
  load1->DisplayNextDelivery(out);
  load1->ItemDelivered();
  cout << "How many delivered: "<< load1->HowManyDelivered() << endl;
  cout << "How many not delivered: " << load1->HowManyNotDelivered() << endl;
  load1->DisplayNextDelivery(out);
  load1->ItemDelivered();
  cout << "How many delivered: "<< load1->HowManyDelivered() << endl;
  cout << "How many not delivered: " << load1->HowManyNotDelivered() << endl;
  load1->DisplayNextDelivery(out);
  load1->ItemDelivered();
  cout << "How many delivered: "<< load1->HowManyDelivered() << endl;
  cout << "How many not delivered: " << load1->HowManyNotDelivered() << endl;

  return 0; 
}