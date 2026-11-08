#include "Media.h"

Media::Media(const char* title, int year) : year(year) {
  strncpy(this->title, title, 50);
  (this->title)[50] = '\0';
}
int Media::getYear() {
  return this->year;
}
const char* Media::getTitle() {
  return this->title;
}
Media::~Media() = default;