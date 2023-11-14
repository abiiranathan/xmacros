#include <stdio.h>
#include <stdlib.h>

#define DAYS_OF_THE_WEEK                                                                           \
  X(Monday)                                                                                        \
  X(Tuesday)                                                                                       \
  X(Wednesday)                                                                                     \
  X(Thursday)                                                                                      \
  X(Friday)                                                                                        \
  X(Saturday)                                                                                      \
  X(Sunday)

typedef enum Day {

#define X(name) name,
  DAYS_OF_THE_WEEK
#undef X
} Day;

static char* days_list[] = {
#define X(name) [name] = #name,
  DAYS_OF_THE_WEEK
#undef X
};

char* day_tostring(Day day) {
  if (day < Monday || day > Sunday) {
    fprintf(stderr, "Invalid day: %d\n", day);
    exit(1);
  }
  return days_list[day];
}

static int num_days = sizeof(days_list) / sizeof(days_list[0]);

// https://en.wikipedia.org/wiki/X_macro
// X-Macro as an argument
// Pass name of the worker macro into the list macro.
// This both avoids defining an obscurely named macro (X),
// and alleviates the need to undefine it.


int main(void) {
  printf("Number of days: %d\n", num_days);
  printf("Seventh day: %s\n", day_tostring(Sunday));

  for (int i = Monday; i <= Sunday; i++) {
    printf("%d: %s\n", i, day_tostring(i));
  }
}
