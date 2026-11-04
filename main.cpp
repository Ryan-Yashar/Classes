#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

class Media {
  protected:
    char title[51];
    int year;
  public:
    Media(const char* title, int year) : year(year) {
      strncpy(this->title, title, 50);
      (this->title)[50] = '\0';
    }
    int getYear() {
      return this->year;
    }
    const char* getTitle() {
      return this->title;
    }
    virtual ~Media() = default;
};
class Game : public Media {
  protected:
    char publisher[51];
    long rating;
  public:
    Game(const char* title, int year, const char* publisher, long rating) : Media(title, year), rating(rating) {
      strncpy(this->publisher, publisher, 50);
      (this->publisher)[50] = '\0';
    }
    ~Game() = default;
};
class Song : public Media {
  protected:
    char artist[51];
    int duration;
    char publisher[51];
  public:
    Song(const char* title, const char* artist, int year, int duration, const char* publisher) : Media(title, year), duration(duration) {
      strncpy(this->artist, artist, 50);
      (this->artist)[50] = '\0';
      strncpy(this->publisher, publisher, 50);
      (this->publisher)[50] = '\0';
    }
    int getDuration() {
      return this->duration;
    }
    const char* getArtist() {
      return this->artist;
    }
    const char* getPublisher() {
      return this->publisher;
    }
    ~Song() = default;
};
class Movie : public Media {
  protected:
    char director[51];
    int duration;
    long rating;
  public:
    Movie(const char* title, const char* director, int year, int duration, long rating) : Media(title, year), duration(duration), rating(rating) {
      strncpy(this->director, director, 50);
      (this->director)[50] = '\0';
    }
    int getDuration() {
      return this->duration;
    }
    long getRating() {
      return this->rating;
    }
    const char* getDirector() {
      return this->director;
    }
    ~Movie() = default;
};
void addCommand() {
  
}
int main() {
  vector<media> media_list;
  char input[8];
  cout << fixed << setprecision(2); //print floats to 2 decimals
  while (true) {
    cout << "Enter one of ADD, SEARCH, DELETE, QUIT to continue. ADD prompts for a new media item, SEARCH lets you search for items via title or year, DELETE deletes one media item from the list, and QUIT ends program execution. Input: ";
    cin.get(input, 8);
    while (cin.get() != '\n') {}
    for (int i=0; input[i] != '\0'; i++) {
      if ('a' <= input[i] && 'z' >= input[i]) {
        input[i] -= 32; //capitalize everything
      }
    }
    if (!strcmp(input, "ADD")) {
      addCommand(media_list);
    } else if (!strcmp(input, "SEARCH")) {
      searchCommand(media_list);
    } else if (!strcmp(input, "DELETE")) {
      deleteCommand(media_list);
    } else if (!strcmp(input, "QUIT")) {
      cout << "Quitting...\n";
      break;
    } else {
      cout << "Command \"" << input << "\" not found. Try again.\n";
    }
  }
  return 0;
}
