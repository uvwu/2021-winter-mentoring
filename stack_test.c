#include "stack.h"
#include <string.h>
#include <assert.h>

int main() {
    stack *stack1 = stack_alloc(128);
    element e1 = (element) {
        .number = 1,
        .name = "element one",
    };
    element e2 = (element) {
        .number = 2,
        .name = "element two",
    };

    stack_push(stack1, e1);
    stack_push(stack1, e2);

    element *r1 = stack_top(stack1);
    assert(strcmp(r1->name, "element two") == 0);
    printf("%s\n", r1->name);

    stack_pop(stack1);
    assert(strcmp(r1->name, "deleted") == 0);
    printf("%s\n", r1->name);
    
    element *r2 = stack_top(stack1);
    assert(strcmp(r2->name, "element one") == 0);
    printf("%s\n", r2->name);

    printf("test1 pass");
}
