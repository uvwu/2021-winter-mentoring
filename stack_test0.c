#include "stack.h"
#include <string.h>
#include <assert.h>

int main() {
    stack *stack1 = stack_alloc(1);

    assert(stack1->top == -1); // top은 -1로 초기화 되어야한다.

    element e1 = (element) {
        .number = 1,
        .name = "element one",
    };

    bool res = stack_pop(stack1);
    assert(res == false);
    assert(stack1->top == -1);

    stack_push(stack1, e1);
    assert(stack1->top == 0);
    res = stack_pop(stack1);
    assert(res == true);
    assert(stack1->top == -1);

    puts("test0: stack push, pop test pass");
}
