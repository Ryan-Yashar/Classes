#include <Music.h>

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
