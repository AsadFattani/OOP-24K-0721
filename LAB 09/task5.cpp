#include <iostream>
using namespace std;

class Shipment {
    private:
        string trackingNumber;
        double weight;

    public:
        virtual void estimateDeliveryTime  () = 0; // Pure virtual function
        virtual void showDetails () = 0; 
};

class AirFreight : public Shipment {
    public:
        void estimateDeliveryTime () {
            cout << "Estimated delivery time for Air Freight: 2-3 days" << endl;
        }
        void showDetails () {
            cout << "Air Freight Shipment in progress" << endl;
        }
};

class GroundShipment : public Shipment {
    public:
        void estimateDeliveryTime () {
            cout << "Estimated delivery time for Ground Shipment: 5-7 days" << endl;
        }
        void showDetails () {
            cout << "Ground Shipment in progress" << endl;
        }
};

int main (){
    Shipment* shipment1 = new AirFreight();
    Shipment* shipment2 = new GroundShipment();

    shipment1->estimateDeliveryTime();
    shipment1->showDetails();

    cout << endl;

    shipment2->estimateDeliveryTime();
    shipment2->showDetails();

    delete shipment1;
    delete shipment2;

    return 0;
}



