#pragma once
#include "Common.h"

class Media {
  protected:
    char title[51];
    int year;
  public:
    Media(const char* title, int year);
    int getYear();
    const char* getTitle();
    virtual ~Media();
};
