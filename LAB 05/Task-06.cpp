#include <iostream>
using namespace std;

class level {
    private:
        string name;
        string difficulty;

    public:
        level() {}

        level(string name, string difficulty) : name(name), difficulty(difficulty) {}

        void display() {
            cout << "Level Name: " << name << endl;
            cout << "Difficulty: " << difficulty << endl;
        }
};

class VideoGame {
    private:
        string title;
        string genre;
        level levels[5]; // for 5 level game
        int levelCount;

    public:
        VideoGame(string title, string genre) : title(title), genre(genre), levelCount(0) {}

        void addLevel(level level) {
            if (levelCount < 5) {
                levels[levelCount++] = level;
            } else {
                cout << "Game has reached maximum levels, cannot add more levels." << endl;
            }
        }

        void display() {
            cout << "Title: " << title << endl;
            cout << "Genre: " << genre << endl;
            cout << "Game has " << levelCount << " levels:" << endl << endl;
            for (int i = 0; i < levelCount; i++) {
                cout << "Level " << i + 1 << ":" << endl;
                levels[i].display();
            }
        }
};

int main() {
    level level1("World 1-1", "Easy");
    level level2("World 1-2", "Medium");
    level level3("World 1-3", "Hard");
    level level4("World 1-4", "Very Hard");
    level level5("World 2-1", "Insane");
    level level6("World 2-2", "Extreme");
    
    VideoGame game("Super Mario Bros.", "Platformer");
    game.addLevel(level1);
    game.addLevel(level2);
    game.addLevel(level3);
    game.addLevel(level4);
    game.addLevel(level5);
    
    game.display();

    game.addLevel(level6);

    return 0;
}




