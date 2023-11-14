#include <stdio.h>

// Define the X macro for the list of variables
#define FOR_LIST_OF_VARIABLES(DO)                                                                  \
  DO(1, age)                                                                                       \
  DO(2, height)                                                                                    \
  DO(3, weight)

// Macro to declare variables
#define DEFINE_NAME_VAR(id, name, ...) int name;

// Macro to define an enumeration
#define DEFINE_ENUMERATION(id, name, ...) name = id,

// Macro to print variables and their values
#define PRINT_NAME_AND_VALUE(id, name, ...) printf(#name " = %d\n", name);

// Function to use the declared variables
void use_variables(void) {
  // Execute the list to declare variables
  FOR_LIST_OF_VARIABLES(DEFINE_NAME_VAR)

  // Use the declared variables
  age    = 25;
  height = 180;
  weight = 75;
}

// Declare an enumeration
enum my_id_list_type { FOR_LIST_OF_VARIABLES(DEFINE_ENUMERATION) };

// Function to print variables and their values
void print_variables(void) {
  // Execute the list to print variables and their values
  FOR_LIST_OF_VARIABLES(PRINT_NAME_AND_VALUE)
}

int main(void) {
  // Use the variables
  use_variables();

  // Print the variables and their values
  print_variables();

  return 0;
}
