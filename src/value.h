#pragma once

#include "common.h"

typedef double Value;

typedef struct {
  int capacity;
  int count;
  Value* values;
} ValueArray;

void value_array_init(ValueArray* array);
void value_array_write(ValueArray* array, Value byte);
void value_array_free(ValueArray* array);
void value_print(Value value);
