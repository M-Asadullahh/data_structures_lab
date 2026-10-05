#include <iostream>
#include <string>

using namespace std;

class SongNode {
public:
    string title;
    SongNode* next;

    SongNode(string name) {
        title = name;
        next = nullptr;
    }
};

class MusicPlaylist {
private:
    SongNode* head;
    SongNode* tail;
    int songCount;

public:
    MusicPlaylist() {
        head = nullptr;
        tail = nullptr;
        songCount = 0;
    }

    void addSong(const string& name) {
        SongNode* newSong = new SongNode(name);

        if (head == nullptr) {
            head = newSong;
            tail = newSong;
            newSong->next = head;
        }
        else {
            tail->next = newSong;
            tail = newSong;
            tail->next = head;
        }
        songCount++;
    }

    void displayOnce() const {
        if (head == nullptr) return;

        cout << "--- Playing All Songs (Single Pass) ---\n";
        SongNode* current = head;
        int index = 1;

        do {
            cout << "Track " << index++ << ": " << current->title << "\n";
            current = current->next;
        } while (current != head);

        cout << "\n";
    }

    void playRounds(int totalRounds = 2) const {
        if (head == nullptr) return;

        cout << "--- Playing Playlist for " << totalRounds << " Complete Rounds ---\n";
        SongNode* current = head;
        int totalTrackPlays = songCount * totalRounds;

        for (int i = 1; i <= totalTrackPlays; ++i) {
            int roundNumber = ((i - 1) / songCount) + 1;
            cout << "[Round " << roundNumber << "] Playing: " << current->title << "\n";
            current = current->next;
        }
        cout << "\n";
    }

    ~MusicPlaylist() {
        if (head == nullptr) return;

        SongNode* current = head;
        tail->next = nullptr;

        while (current != nullptr) {
            SongNode* nextSong = current->next;
            delete current;
            current = nextSong;
        }
    }
};

int main() {
    MusicPlaylist playlist;

    playlist.addSong("Bohemian Rhapsody");
    playlist.addSong("Hotel California");
    playlist.addSong("Stairway to Heaven");
    playlist.addSong("Sweet Child O' Mine");
    playlist.addSong("Imagine");

    playlist.displayOnce();
    playlist.playRounds(2);

    return 0;
}