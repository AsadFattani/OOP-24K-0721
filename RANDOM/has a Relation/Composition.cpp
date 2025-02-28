#include <iostream>
using namespace std;

class Room {
    private:
        string roomType;

    public:
        Room(string type) : roomType(type) {}

        void displayRoom() {
            cout << "Room Type: " << roomType << endl;
        }
};

class House {
    private:
        string houseName;
        Room livingRoom;
        Room bedRoom;

    public:
        House(string name, string livingRoomType, string bedRoomType) 
        : houseName(name), livingRoom(livingRoomType), bedRoom(bedRoomType) {}

        void displayHouse() {
            cout << "House Name: " << houseName << endl;
            livingRoom.displayRoom();
            bedRoom.displayRoom();
        }
};

int main(){
    House myHouse("My Sweet Home", "Living Room", "Bed Room");
    myHouse.displayHouse();

    return 0;
}




