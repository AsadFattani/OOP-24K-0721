#include <iostream>
using namespace std;

class Car{
    private:
        string brand;
        string model;
        double rentalPrice;
        bool availability;
        int days;
        double discount;
        double revenue;
        string registrationNumber;

    public:
        Car(string regNum) : registrationNumber(regNum) {
            brand = "Unknown";
            model = "Generic";
            rentalPrice = 0.0;
            availability = true;
            days = 0;
            discount = 0.0;
            revenue = 0.0;
        }

        Car(string brandp, string modelp, double rentalPricep, bool availabilityp, string regNum) 
            : brand(brandp), model(modelp), rentalPrice(rentalPricep), availability(availabilityp), registrationNumber(regNum) {
            days = 0;
            discount = 0.0;
            revenue = 0.0;
        }

        Car (Car &car) : registrationNumber(car.registrationNumber) {
            brand = car.brand;
            model = car.model;
            rentalPrice = car.rentalPrice;
            availability = car.availability;
            days = car.days;
            discount = car.discount;
            revenue = car.revenue;
        }

        void updateDetails(string brandp, string modelp, double rentalPricep, bool availabilityp){
            brand = brandp;
            model = modelp;
            rentalPrice = rentalPricep;
            availability = availabilityp;
        }

        void checkAvailabilty(){
            cout << endl << "Checking availability for " << brand << " " << model << "..." << endl;
            if (availability){
                cout << "Car is available for rent" << endl;
            }else {
                cout << "Car is not available for rent" << endl;
            }
        }

        void applyDiscount(string customerName){
            if (days > 10){
                discount = 0.1;
                cout << "Dear " << customerName << ", a discount of 10% has been applied for renting the car for " << days << " days." << endl;
            } else if (days > 5){
                discount = 0.05;
                cout << "Dear " << customerName << ", a discount of 5% has been applied for renting the car for " << days << " days." << endl;
            } else {
                discount = 0.0;
                cout << "Dear " << customerName << ", no discount is available for renting the car for " << days << " days." << endl;
            }
        }

        void updateRevenue(){
            if (!availability){
                double rentalRevenue = rentalPrice * days * (1 - discount);
                this->revenue += rentalRevenue;
                cout << "Revenue generated: $" << rentalRevenue << endl;
                availability = true;
            } else {
                cout << "Car is not rented, no revenue generated." << endl;
            }
        }

        void rentalRequest(){
            cout << endl << "Processing rental request for " << brand << " " << model << "..." << endl;
            if (availability){
                cout << "Car is available for rent" << endl;
                availability = false;
            }else {
                cout << "Car is not available for rent" << endl;
            }
        }

        void displayDetails(){
            cout << endl << "----- Car Details -----" << endl;
            cout << "Car Registration Number: " << registrationNumber << endl;
            cout << "Brand: " << brand << endl;
            cout << "Model: " << model << endl;
            cout << "Rental Price: $" << rentalPrice << endl;
            cout << "Availability: " << (availability ? "Available" : "Not Available") << endl;
            cout << "Total Revenue: $" << revenue << endl;
        }

        void setRentalDays(int daysp) {
            days = daysp;
        }
};

int main(){
    Car car1("REG123");
    car1.updateDetails("Toyota", "Corolla", 1000.0, true);
    car1.checkAvailabilty();
    car1.rentalRequest();
    car1.checkAvailabilty();
    car1.setRentalDays(6);
    car1.applyDiscount("John Doe");
    car1.updateRevenue();
    car1.displayDetails();

    Car car2("Honda", "Civic", 1200.0, true, "REG456");
    car2.checkAvailabilty();
    car2.rentalRequest();
    car2.checkAvailabilty();
    car2.setRentalDays(11);
    car2.applyDiscount("Jane Smith");
    car2.updateRevenue();
    car2.displayDetails();

    Car car3(car2);
    car3.updateDetails("Ford", "Focus", 900.0, true);
    car3.checkAvailabilty();
    car3.rentalRequest();
    car3.checkAvailabilty();
    car3.setRentalDays(3);
    car3.applyDiscount("Alice Johnson");
    car3.updateRevenue();
    car3.displayDetails();

    return 0;
}

