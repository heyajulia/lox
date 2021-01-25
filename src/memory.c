#include <stdlib.h>
#include <sysexits.h>

#include "memory.h"

void* reallocate(void* pointer,
                 __attribute((unused)) size_t old_size,
                 size_t new_size) {
  if (new_size == 0) {
    free(pointer);

    return NULL;
  }

  void* result = realloc(pointer, new_size);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }

  return result;
}
