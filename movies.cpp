#include <Movies.h>

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
