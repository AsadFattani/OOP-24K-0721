#include <iostream>
using namespace std;

class Character {
    protected:
        int characterID;
        string name;
        string level;
        int healthPoints;
        string weaponType;

    public:
        Character(int characterID, string name, string level, int healthPoints, string weaponType) 
        : characterID(characterID), name(name), level(level), healthPoints(healthPoints), weaponType(weaponType) {}

        virtual void attack() {
            cout << "Character attacked!" << endl;
        }
        virtual void defend() {
            cout << "Character defended!" << endl;
        }
        virtual void displayStats () {
            cout << "Character ID: " << characterID << endl;
            cout << "Name: " << name << endl;
            cout << "Level: " << level << endl;
            cout << "Health Points: " << healthPoints << endl;
            cout << "Weapon Type: " << weaponType << endl;
        }
};

class Warrior : public Character {
    protected:
        string armorSrength;
        int meleeDamage;

    public:
        Warrior(int characterID, string name, string level, int healthPoints, string weaponType, string armorSrength, int meleeDamage)
        : Character(characterID, name, level, healthPoints, weaponType), armorSrength(armorSrength), meleeDamage(meleeDamage) {}

        void attack() {
            cout << "Warrior attacked with melee weapon!" << endl;
        }
};

class Mage : public Character {
    protected:
        int manaPoints;
        string spellPower;
    
    public:
        Mage(int characterID, string name, string level, int healthPoints, string weaponType, int manaPoints, string spellPower)
        : Character(characterID, name, level, healthPoints, weaponType), manaPoints(manaPoints), spellPower(spellPower) {}

        void defend() {
            cout << "Mage defended with magic shield!" << endl;
        }
};

class Archer : public Character {
    protected:
        int arrowCount;
        string rangedAccuracy;

    public:
        Archer(int characterID, string name, string level, int healthPoints, string weaponType, int arrowCount, string rangedAccuracy)
        : Character(characterID, name, level, healthPoints, weaponType), arrowCount(arrowCount), rangedAccuracy(rangedAccuracy) {}

        void attack() {
            cout << "Archer attacked with bow and arrow!" << endl;
        }
};

class Rogue : public Character {
    protected:
        string stealthLevel;
        string agility;
    
    public:
        Rogue(int characterID, string name, string level, int healthPoints, string weaponType, string stealthLevel, string agility)
        : Character(characterID, name, level, healthPoints, weaponType), stealthLevel(stealthLevel), agility(agility) {}

        void displayStats() {
            cout << "----- Rogue Stats -----" << endl;
            Character::displayStats();
            cout << "Stealth Level: " << stealthLevel << endl;
            cout << "Agility: " << agility << endl;
        }
};

int main () {
    Warrior warrior(101, "Warrior", "Level 10", 100, "Sword", "Heavy", 50);
    warrior.displayStats();
    cout << endl;

    Mage mage(102, "Mage", "Level 10", 80, "Staff", 100, "High");
    mage.defend();
    cout << endl;

    Archer archer(103, "Archer", "Level 10", 70, "Bow", 20, "High");
    archer.attack();
    cout << endl;

    Rogue rogue(104, "Rogue", "Level 10", 60, "Dagger", "High", "High");
    rogue.displayStats();
    cout << endl;

    return 0;
}



