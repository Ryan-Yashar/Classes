#pragma once
#include "Common.h"

void get(char* buffer, size_t size);
bool verifyCorrect(char* valuetoprint);
int numType(char* input);
void prompt(char* input, const char* type, const char* attribute, int allowedTypes);