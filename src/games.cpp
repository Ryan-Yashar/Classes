#include "Games.h"

Game::Game(const char* title, int year, const char* publisher, float rating) : Media(title, year), rating(rating) {
  strncpy(this->publisher, publisher, 50);
  (this->publisher)[50] = '\0';
}
const char* Game::getPublisher() {
  return this->publisher;
}
float Game::getRating() {
  return this->rating;
}
Game::~Game() = default;