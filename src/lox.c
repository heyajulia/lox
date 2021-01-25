#include "chunk.h"
#include "common.h"
#include "debug.h"

int main(__attribute((unused)) int argc,
         __attribute((unused)) const char* argv[]) {
  Chunk chunk;
  chunk_init(&chunk);

  int constant = chunk_add_constant(&chunk, 1.2);
  chunk_write(&chunk, OP_CONSTANT, 123);
  chunk_write(&chunk, constant, 123);

  chunk_write(&chunk, OP_RETURN, 123);

  disassemble_chunk(&chunk, "test chunk");

  chunk_free(&chunk);
}
