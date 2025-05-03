#include <iostream>
#include <stdexcept>
using namespace std;

class DatabaseException : public exception {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException {};

class QueryTimeoutException : public DatabaseException {};

template <typename T>
class DatabaseConnector {
public:
    void connect(T dbName) {
        cout << "Attempting to connect to " << dbName << "...\n";
        if (dbName == "invalid_db") {
            throw ConnectionFailedException();
        } else if (dbName == "slow_db") {
            throw QueryTimeoutException();
        } else {
            cout << "Connected to " << dbName << " successfully.\n";
        }
    }
};

int main() {
    DatabaseConnector<string> connector;

    try {
        connector.connect("invalid_db");
    } catch (const ConnectionFailedException& e) {
        cout << "Caught ConnectionFailedException - what(): " << e.what() << "\n";
    } catch (const DatabaseException& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << "\n";
    }

    try {
        connector.connect("slow_db");
    } catch (const ConnectionFailedException& e) {
        cout << "Caught ConnectionFailedException - what(): " << e.what() << "\n";
    } catch (const DatabaseException& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << "\n";
    }

    try {
        connector.connect("valid_db");
    } catch (const DatabaseException& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << "\n";
    }

    return 0;
}
