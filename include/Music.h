#pragma once
#include "Common.h"
#include "Media.h"

class Song : public Media {
  protected:
    char artist[51];
    int duration;
    char publisher[51];
  public:
    Song(const char* title, const char* artist, int year, int duration, const char* publisher);
    int getDuration();
    const char* getArtist();
    const char* getPublisher();
    ~Song();
};
