#pragma once
#include <Common.h>
#include <Media.h>

class Movie : public Media {
  protected:
    char director[51];
    int duration;
    long rating;
  public:
    Movie(const char* title, const char* director, int year, int duration, long rating);
    int getDuration();
    long getRating();
    const char* getDirector();
    ~Movie();
};
