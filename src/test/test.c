#include <stdio.h>
#include <stdlib.h>

int ERRORS = 0;

void end_if_errors() {
  if (ERRORS) {
    printf("[INF] there were %d errors", ERRORS);
    exit(ERRORS);
  }
}

void defer_throw(char* err) {
  printf("[ERR] %s\n", err);
  ERRORS++;
}
void throw(char* err) {
  defer_throw(err);
  end_if_errors();
}

void defer_assert(bool assertion, char* err) {
  if (!assertion) defer_throw(err);
}
void assert(bool assertion, char* err) {
  if (!assertion) throw(err);
}
