#include "Music.h"

Song::Song(const char* title, const char* artist, int year, int duration, const char* publisher) : Media(title, year), duration(duration) {
  strncpy(this->artist, artist, 50);
  (this->artist)[50] = '\0';
  strncpy(this->publisher, publisher, 50);
  (this->publisher)[50] = '\0';
}
int Song::getDuration() {
  return this->duration;
}
const char* Song::getArtist() {
  return this->artist;
}
const char* Song::getPublisher() {
  return this->publisher;
}
Song::~Song() = default;