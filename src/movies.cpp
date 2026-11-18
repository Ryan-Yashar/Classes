#include "Movies.h"

Movie::Movie(const char* title, const char* director, int year, int duration, float rating) : Media(title, year), duration(duration), rating(rating) {
  strncpy(this->director, director, 50);
  (this->director)[50] = '\0';
}
int Movie::getDuration() {
  return this->duration;
}
float Movie::getRating() {
  return this->rating;
}
const char* Movie::getDirector() {
  return this->director;
}
void Movie::printSelf() {
  cout << "\"" << this->getTitle() << "\". Year: " << this->getYear() << ". Duration: " << this->getDuration() << " seconds. Director: " << this->getDirector() << ". Rating: " << this->getRating() << ".\n";
}
Movie::~Movie() = default;