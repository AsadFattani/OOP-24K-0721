#include <iostream>
using namespace std;

class Ticket {
    protected:
        int ticketID;
        string passengerName;
        int price;
        string date;
        string destination;

    public:
        Ticket(int ticketID, string passengerName, int price, string date, string destination) 
        : ticketID(ticketID), passengerName(passengerName), price(price), date(date), destination(destination) {}

        virtual void reserve() {
            cout << "Ticket reserved successfully!" << endl;
        }
        virtual void cancel() {
            cout << "Ticket cancelled!" << endl;
            cout << "Refund process initiated..." << endl;
            cout << "Refund approved!" << endl;
            cout << "Refund will be issued within 24-48 hours!" << endl;
        }
        virtual void displayTicketInfo() {
            cout << "Ticket ID: " << ticketID << endl;
            cout << "Passenger Name: " << passengerName << endl;
            cout << "Price: $" << price << endl;
            cout << "Date: " << date << endl;
            cout << "Destination: " << destination << endl;
        }
};

class FlightTicket : public Ticket {
    protected:
        string airlineName;
        string flightNumber;
        string seatClass;

    public:
        FlightTicket(int ticketID, string passengerName, int price, string date, string destination, string airlineName, string flightNumber, string seatClass)
        : Ticket(ticketID, passengerName, price, date, destination), airlineName(airlineName), flightNumber(flightNumber), seatClass(seatClass) {}

        void displayTicketInfo() {
            cout << "----- Flight Ticket Info -----" << endl;
            Ticket::displayTicketInfo();
            cout << "Airline Name: " << airlineName << endl;
            cout << "Flight Number: " << flightNumber << endl;
            cout << "Seat Class: " << seatClass << endl;
        }
};

class TrainTicket : public Ticket {
    protected:
        string trainNumber;
        string coachType;
        string departureTime;

    public:
        TrainTicket(int ticketID, string passengerName, int price, string date, string destination, string trainNumber, string coachType, string departureTime) 
        : Ticket(ticketID, passengerName, price, date, destination), trainNumber(trainNumber), coachType(coachType), departureTime(departureTime) {}

        void reserve() {
            cout << "Train ticket reserved successfully! Seat auto-assigned." << endl;
        }
};

class BusTicket : public Ticket {
    protected:
        string busCompany;
        string seatNumber;

    public:
        BusTicket(int ticketID, string passengerName, int price, string date, string destination, string busCompany, string seatNumber) 
        : Ticket(ticketID, passengerName, price, date, destination), busCompany(busCompany), seatNumber(seatNumber) {}

        void cancel() {
            cout << "Bus ticket cancelled!" << endl;
            cout << "Last-minute refund process initiated..." << endl;
            cout << "Refund approved!" << endl;
            cout << "Refund will be issued within 24-48 hours!" << endl;
        }
};

class ConcertTicket : public Ticket {
    protected:
        string artistName;
        string venue;
        string seatType;

    public:
        ConcertTicket(int ticketID, string passengerName, int price, string date, string destination, string artistName, string venue, string seatType)
        : Ticket(ticketID, passengerName, price, date, destination), artistName(artistName), venue(venue), seatType(seatType) {}

        void displayTicketInfo() {
            cout << "----- Concert Ticket Info -----" << endl;
            Ticket::displayTicketInfo();
            cout << "Artist Name: " << artistName << endl;
            cout << "Venue: " << venue << endl;
            cout << "Seat Type: " << seatType << endl;
        }
};

int main () {
    FlightTicket flight(101, "Ali Khan", 75000, "2023-07-21", "Karachi", "PIA", "PK304", "Economy");
    flight.displayTicketInfo();
    cout << endl;

    TrainTicket train(102, "Ayesha Ahmed", 1500, "2023-07-22", "Lahore", "Karakoram Express", "AC Sleeper", "08:00 PM");
    train.reserve();
    cout << endl;

    BusTicket bus(103, "Bilal Hassan", 800, "2023-07-23", "Islamabad", "Daewoo Express", "A12");
    bus.cancel();
    cout << endl;

    ConcertTicket concert(104, "Sara Malik", 5000, "2023-07-24", "Karachi", "Atif Aslam", "Expo Center", "Gold");
    concert.displayTicketInfo();
    cout << endl;

    return 0;
}








