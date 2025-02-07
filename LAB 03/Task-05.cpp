#include <iostream>
using namespace std;

class MusicPlayer {
    private:
        string playList[100];
        string currentPlayingSong;
        int songCount = 0;
    public:
        void addSong(const string& song) {
            if (songCount < 100) {
                playList[songCount] = song;
                songCount++;
                cout << "Song added to playlist: " << song << endl;
            } else {
                cout << "Playlist is full!" << endl;
            }
        }

        void playSong(const string& song) {
            bool found = false;
            for (int i = 0; i < songCount; ++i) {
                if (playList[i] == song) {
                    currentPlayingSong = song;
                    cout << "Playing song: " << song << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Song not found in playlist!" << endl;
            }
        }

        void pauseSong() {
            if (!currentPlayingSong.empty()) {
                cout << "Song paused: " << currentPlayingSong << endl;
            } else {
                cout << "No song is currently playing!" << endl;
            }
        }

        void stopSong() {
            if (!currentPlayingSong.empty()) {
                cout << "Song stopped: " << currentPlayingSong << endl;
                currentPlayingSong.clear();
            } else {
                cout << "No song is currently playing!" << endl;
            }
        }

        void displayPlayList() const {
            cout << endl << "--- Playlist ---" << endl;
            for (int i = 0; i < songCount; ++i) {
                cout << i + 1 << ". " << playList[i] << endl;
            }
            cout << endl;
        }
};

int main (){
    MusicPlayer myPlayer;
    
    while (true) {
        cout << "1. Add Song" << endl;
        cout << "2. Play Song" << endl;
        cout << "3. Pause Song" << endl;
        cout << "4. Stop Song" << endl;
        cout << "5. Display Playlist" << endl;
        cout << "0. Exit" << endl;
        
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        getchar();
        
        switch (choice) {
            case 1: {
                string song;
                cout << "Enter song name: ";
                getline(cin, song);
                myPlayer.addSong(song);
                break;
            }
            case 2: {
                string song;
                cout << "Enter song name: ";
                getline(cin, song);
                myPlayer.playSong(song);
                break;
            }
            case 3:
                myPlayer.pauseSong();
                break;
            case 4:
                myPlayer.stopSong();
                break;
            case 5:
                myPlayer.displayPlayList();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return 0;
}



