#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

class FileException : public runtime_error {
    public:
        FileException(const string& message) : runtime_error(message) {}
};

class SearchException : public runtime_error {
    public:
        SearchException(const string& message) : runtime_error(message) {}
};

class DataFileHandler {
    private:
        string filename;

    public:
        DataFileHandler(const string& file) : filename(file) {}

        void saveLine(const string& record) {
            ofstream file(filename, ios::app);
            if (!file) {
                throw FileException("Failed to open file for writing.");
            }
            file << record << endl;
            file.close();
        }

        void readAll() {
            ifstream file(filename);
            if (!file) {
                throw FileException("Failed to open file for reading.");
            }
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        }

        void searchInFile(const string& keyword) {
            if (keyword.empty()) {
                throw SearchException("Keyword cannot be empty.");
            }
            ifstream file(filename);
            if (!file) {
                throw SearchException("Failed to open file for reading.");
            }
            string line;
            bool found = false;
            while (getline(file, line)) {
                if (line.find(keyword) != string::npos) {
                    cout << line << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "No matching lines found." << endl;
            }
            file.close();
        }
};

class InvalidTicketException : public runtime_error {
    public:
        InvalidTicketException(const string& message) : runtime_error(message) {}
};

class TicketCountTransaction {
    private:
        int ticketSold;
        string timeStamp;

    public:
        TicketCountTransaction(int tickets, const string& time) {
            if (tickets < 0) {
                throw InvalidTicketException("Ticket count cannot be negative.");
            }
            ticketSold = tickets;
            timeStamp = time;
        }

        string getFormattedData() const {
            return timeStamp + ", " + to_string(ticketSold);
        }

        int getTicketSold() const {
            return ticketSold;
        }
};

class InvalidRevenueException : public runtime_error {
    public:
        InvalidRevenueException(const string& message) : runtime_error(message) {}
};

class TicketRevenueTransaction {
    private:
        double revenue;
        string timeStamp;

    public:
        TicketRevenueTransaction(double rev, const string& time) {
            if (rev < 0) {
                throw InvalidRevenueException("Revenue cannot be negative.");
            }
            revenue = rev;
            timeStamp = time;
        }

        string getFormattedData() const {
            return timeStamp + ", " + to_string(revenue);
        }

        double getRevenue() const {
            return revenue;
        }
};

class AlertSystem {
    private:
        DataFileHandler& dataFileHandler;
        int seatLimit;
        double revenueLimit;

    public:
        AlertSystem(DataFileHandler& handler, int seatLim, double revLim)
            : dataFileHandler(handler), seatLimit(seatLim), revenueLimit(revLim) {}

        void checkThreshold(int ticketsSold, double revenue) {
            if (ticketsSold > seatLimit) {
                string alert = "[ALERT] Overbooked: Tickets sold (" + to_string(ticketsSold) + 
                               ") exceeded seat limit (" + to_string(seatLimit) + ").";
                cout << alert << endl;
                dataFileHandler.saveLine(alert);
            }
            if (revenue > revenueLimit) {
                string alert = "[ALERT] Revenue spike: Revenue (" + to_string(revenue) + 
                               ") exceeded limit (" + to_string(revenueLimit) + ").";
                cout << alert << endl;
                dataFileHandler.saveLine(alert);
            }
        }
};

// Main function for testing
int main() {
    try {
        DataFileHandler handler("alerts.txt");

        TicketCountTransaction ticketTransaction(120, "2023-10-01 10:00");
        TicketRevenueTransaction revenueTransaction(15000.50, "2023-10-01 10:00");

        handler.saveLine(ticketTransaction.getFormattedData());
        handler.saveLine(revenueTransaction.getFormattedData());

        AlertSystem alertSystem(handler, 100, 10000.0);
        alertSystem.checkThreshold(ticketTransaction.getTicketSold(), revenueTransaction.getRevenue());

        cout << "Reading all alerts:" << endl;
        handler.readAll();

        cout << "Searching for 'Overbooked':" << endl;
        handler.searchInFile("Overbooked");
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}




