#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _stack {
    char c;
    struct _stack *top;
    struct _stack *next;

    void (*push)(struct _stack *, char);

    struct _stack *(*pop)(struct _stack *);

    struct _stack *(*peek)(struct _stack *);

    int (*isEmpty)(struct _stack *);
} stack;

void push(stack *s, char c) {
    stack *node;
    if (!(node = malloc(sizeof(stack)))) return;
    node->c = c;
    node->next = s->top;
    s->top = node;
}

stack *peek(stack *this) {
    return this->top;
}

stack *pop(stack *this) {
    stack *node;
    if (this->top == NULL) return NULL;
    node = this->top;
    this->top = this->top->next;
    return node;
}

int isEmpty(stack *this) {
    return this->top == NULL;
}

stack *NewStack() {
    stack *s;
    if (!(s = malloc(sizeof(stack)))) return NULL;
    s->top = s->next = NULL;
    s->push = push;
    s->peek = peek;
    s->pop = pop;
    s->isEmpty = isEmpty;
    return s;
}

int isPairParentheses(char left, char right) {
    return left == '(' && right == ')'
           || left == '{' && right == '}'
           || left == '[' && right == ']';
}

int isValid(char *s) {
    stack *stk = NewStack();
    if (stk == NULL) return 0;
    int i;
    size_t n;
    stack *node;
    for (i = 0, n = strlen(s); i < n; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stk->push(stk, s[i]);
        } else {
            if (!stk->isEmpty(stk) && isPairParentheses(stk->peek(stk)->c, s[i])) {
                if (!(node = stk->pop(stk))) free(node);
            } else {
                return 0;
            }
        }
    }
    return stk->isEmpty(stk);
}

int main(int argc, const char *argv[]) {
    char *s = "]";
    int result = isValid(s);
    printf("is valid = %s", result == 1 ? "true" : "false");
}