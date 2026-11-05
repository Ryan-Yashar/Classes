#include <Games.h>

class Game : public Media {
  protected:
    char publisher[51];
    long rating;
  public:
    Game(const char* title, int year, const char* publisher, long rating) : Media(title, year), rating(rating) {
      strncpy(this->publisher, publisher, 50);
      (this->publisher)[50] = '\0';
    }
    const char* getPublisher() {
      return this->publisher;
    }
    long getRating() {
      return this->rating;
    }
    ~Game() = default;
};
