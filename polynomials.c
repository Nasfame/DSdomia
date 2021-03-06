#include <stdio.h>
#include <stdlib.h>
#include "string.c"

typedef struct node node;
typedef struct poly poly;

struct node {
    int exp;
    int coef;
    node *next;
} chead;

struct poly {
    node *head;
    node *cur;
    node *temp;
} A, B, C;

void append(poly *p, int exp, int cf) {
    node *new = (node *) malloc(sizeof(node));
    new->coef = cf;
    new->exp = exp;
    new->next = NULL;
    p->cur->next = new;
    p->cur = p->cur->next;
}

void *inialize(poly *p) {
    node *head = (node *) malloc(sizeof(node));
    head->next = NULL;
    p->head = head;
    p->cur = head;
    puts("COEF EXP");
    char *in = input();
    while (strlen(in) > 0) {
        char **li = split(in, " ");
        append(p, toInt(li[1]), toInt(li[0]));
        puts("COEF EXP");
        in = input();
    }
}

void display(poly *p) {
    p->temp = p->head->next;
    while (p->temp != NULL) {
        printf("%dx^%d", p->temp->coef, p->temp->exp);
        p->temp = p->temp->next;
        if (p->temp != NULL)
            printf("+");
    }
    puts("");
}

void *add() {
    A.temp = A.head->next;
    B.temp = B.head->next;
    chead.next = NULL;
    C.head = &chead;
    C.cur = C.head;
    while (A.temp != NULL && B.temp != NULL) {
        if (A.temp->exp == B.temp->exp) {
            append(&C, A.temp->exp, A.temp->coef + B.temp->coef);
            A.temp = A.temp->next;
            B.temp = B.temp->next;
        } else if (A.temp->exp < B.temp->exp) {
            append(&C, B.temp->exp, B.temp->coef);
            B.temp = B.temp->next;
        } else {
            append(&C, A.temp->exp, A.temp->coef);
            A.temp = A.temp->next;
        }
    }
    while (A.temp != NULL) {
        append(&C, A.temp->exp, A.temp->coef);
        A.temp = A.temp->next;
    }
    while (B.temp != NULL) {
        append(&C, B.temp->exp, B.temp->coef);
        B.temp = B.temp->next;
    }
    display(&C);
}

void *mul() {
    A.temp = A.head->next;
    B.temp = B.head->next;
    chead.next = NULL;
    C.head = &chead;
    C.cur = C.head;
    w1:
    while (A.temp != NULL) {
        while (B.temp != NULL)   {
            append(&C, A.temp->exp + B.temp->exp, A.temp->coef * B.temp->coef);
            B.temp = B.temp->next;
            goto w1; //break not working
        }
        B.temp = B.head->next;
        A.temp = A.temp->next;
    }
    display(&C);
};

int main() {
    puts("Polynomial A");
    inialize(&A);
    puts("Polynomial B");
    inialize(&B);
    int x;
    while (1) {
        puts("1. Add 2.Multiply ");
        scanf("%d", &x);
        void *choice = (x == 1) ? add() : mul();
    }
    return 0;
}