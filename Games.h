#pragma once;
#include <Common.h>
#include <Media.h>

class Game : public Media {
  protected:
    char publisher[51];
    long rating;
  public:
    Game(const char* title, int year, const char* publisher, long rating);
    const char* getPublisher();
    long getRating();
    ~Game();
}
