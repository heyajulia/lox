#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "vm.h"

int main(__attribute((unused)) int argc,
         __attribute((unused)) const char* argv[]) {
  vm_init();

  Chunk chunk;
  chunk_init(&chunk);

  int constant = chunk_add_constant(&chunk, 1.2);
  chunk_write(&chunk, OP_CONSTANT, 123);
  chunk_write(&chunk, constant, 123);

  constant = chunk_add_constant(&chunk, 3.4);
  chunk_write(&chunk, OP_CONSTANT, 123);
  chunk_write(&chunk, constant, 123);

  chunk_write(&chunk, OP_ADD, 123);

  constant = chunk_add_constant(&chunk, 5.6);
  chunk_write(&chunk, OP_CONSTANT, 123);
  chunk_write(&chunk, constant, 123);

  chunk_write(&chunk, OP_DIVIDE, 123);

  chunk_write(&chunk, OP_NEGATE, 123);
  chunk_write(&chunk, OP_RETURN, 123);

  disassemble_chunk(&chunk, "test chunk");
  interpret(&chunk);

  chunk_free(&chunk);

  vm_free();
}
