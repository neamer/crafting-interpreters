#include "chunk.h"
#include "debug.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  Chunk chunk;
  initChunk(&chunk);
  writeChunk(&chunk, OP_RETURN);

  disassembleChunk(&chunk, "test chunk");
  freeChunk(&chunk);

  return EXIT_SUCCESS;
}
