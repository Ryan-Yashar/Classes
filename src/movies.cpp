#include "Movies.h"

Movie::Movie(const char* title, const char* director, int year, int duration, long rating) : Media(title, year), duration(duration), rating(rating) {
  strncpy(this->director, director, 50);
  (this->director)[50] = '\0';
}
int Movie::getDuration() {
  return this->duration;
}
long Movie::getRating() {
  return this->rating;
}
const char* Movie::getDirector() {
  return this->director;
}
Movie::~Movie() = default;