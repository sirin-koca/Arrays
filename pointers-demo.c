#include <stdio.h>

#define ARRAY_LENGTH 5
#define STRING_LENGTH 10

// Function prototypes
void print_basic_pointer(int *basic_pointer);
void print_fancy_same_array(char **fancy_same_array);
void print_ptr_array(char *ptr_array[]);

int main(void) {
    // Basic pointers and basic addresses
    int basic_value = 'A';
    int *basic_pointer = &basic_value;

    printf("Pointer is at address %p\n", (void *) &basic_pointer);
    print_basic_pointer(basic_pointer);

    // More advanced use of pointers
    char array[ARRAY_LENGTH] = {'a', 'A', 'b', 'z', 'M'};
    char *same_array = array;
    char **fancy_same_array = &same_array;

    printf("array[3] = %c, addr = %p\n", array[3], (void *) &array[3]);
    printf("same_array[3] = %c, addr = %p\n", same_array[3], (void *) &same_array[3]);
    print_fancy_same_array(fancy_same_array);

    // Char arrays are also just a "string" of characters
    char array_string[STRING_LENGTH] = "hello";
    char *same_array_string = array_string;
    char **fancy_same_array_string = &same_array_string;

    printf("array string %s, addr = %p\n", array_string, (void *) &array_string);
    printf("same array string %s, addr = %p\n", same_array_string, (void *) &same_array_string);
    print_fancy_same_array(fancy_same_array_string);

    // Arrays of pointers
    char *ptr_array[2];
    char *ptr1 = NULL;
    char *ptr2 = NULL;
    char char_elements[2] = {'H', 'i'};

    ptr1 = &char_elements[1];
    ptr2 = char_elements;

    ptr_array[0] = ptr2;
    ptr_array[1] = ptr1;

    print_ptr_array(ptr_array);

    return 0;
}

void print_basic_pointer(int *basic_pointer) {
    printf("Value at address of pointer is %c\n\n", *basic_pointer);
}

void print_fancy_same_array(char **fancy_same_array) {
    printf("**fancy_same_array[3] = %c, addr = %p\n", (*fancy_same_array)[3], (void *) &(*fancy_same_array)[3]);
    printf("Fancy array string %s, addr = %p\n\n", (*fancy_same_array), (void *) &(*fancy_same_array));
}

void print_ptr_array(char *ptr_array[]) {
    printf("**ptr_array = %c\n", **ptr_array);
    printf("Addr at **ptr_array = %p\n", (void *) &(**ptr_array));
    printf("Addr at **ptr_array[0] = %p\n\n", (void *) &(*ptr_array[0]));

    printf("*ptr_array[1] = %c\n", *ptr_array[1]);
    printf("Addr at *ptr_array[0] = %p\n", (void *) &(**ptr_array));
    printf("Addr at *ptr_array[0] = %p\n", (void *) &(**ptr_array));
    printf("Addr at *ptr_array[1] = %p\n", (void *) &(*ptr_array[1]));
}
