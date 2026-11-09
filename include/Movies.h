#pragma once
#include "Common.h"
#include "Media.h"

class Movie : public Media {
  protected:
    char director[51];
    int duration;
    float rating;
  public:
    Movie(const char* title, const char* director, int year, int duration, float rating);
    int getDuration();
    float getRating();
    const char* getDirector();
    ~Movie();
};
