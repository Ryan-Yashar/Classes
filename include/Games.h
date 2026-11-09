#pragma once
#include "Common.h"
#include "Media.h"

class Game : public Media {
  protected:
    char publisher[51];
    float rating;
  public:
    Game(const char* title, int year, const char* publisher, float rating);
    const char* getPublisher();
    float getRating();
    ~Game();
};
