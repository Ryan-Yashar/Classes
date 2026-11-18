#pragma once
#include "Common.h"

void capitalizeInput(char* input);
void get(char* buffer, size_t size);
bool verifyCorrect(char* valuetoprint, bool isAdding=true);
int numType(char* input);
void prompt(char* input, const char* type, const char* attribute, int allowedTypes);