#include "stack.h"
#include <string.h>
#include <assert.h>

int main() {
    stack *stack1 = stack_alloc(1);
    element e1 = (element) {
        .number = 1,
        .name = "element one",
    };
    element e2 = (element) {
        .number = 2,
        .name = "element two",
    };
    element e3 = (element) {
        .number = 3,
        .name = "element three",
    };
    element e4 = (element) {
        .number = 4,
        .name = "element four",
    };

    assert(stack1->capacity == 1);
    stack_push(stack1, e1);
    assert(stack1->capacity == 1);
    stack_push(stack1, e2);
    assert(stack1->capacity == 2);
    stack_push(stack1, e3);
    assert(stack1->capacity == 4);

    element *r1 = stack_top(stack1);
    assert(strcmp(r1->name, "element three") == 0);
    // printf("%s\n", r1->name);

    stack_pop(stack1);
    assert(strcmp(r1->name, "deleted") == 0);
    // printf("%s\n", r1->name);
    
    element *r2 = stack_top(stack1);
    assert(strcmp(r2->name, "element two") == 0);
    // printf("%s\n", r2->name);

    puts("test2: stack 확장 테스트 pass");
}
