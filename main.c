/*----------------------------

Collection of states {s_i}. Sequence of inputs (say characters) {c_j}. State transition function T: (s_i, c_j) |-> s_k
. For pattern matching we would say one such state corresponds to a ‘match’. For string matching allowed state transitions
are increments until match found or ‘back to the beginning’ aka start over.

-----------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define MAXTERMLENGTH 100

int next(int state, const char *s, int c) {
    int nextstate = state;
    if (c == s[state + 1]) {
        nextstate += 1;
    } else {
         nextstate = -1;
    }
    return nextstate;
}

int noncontiguousnext(int state, const char *s, int c) {
    int nextstate = state;
    if (c == s[state + 1]) {
        nextstate += 1;
    }
    return nextstate;
}

int automaton(int (*next)(int, const char *, int), const char *s) {
    int c;
    int state = -1;
    while ((c = getchar()) != '\n' && c != EOF) {
        state = next(state, s, c);
        if ((state + 1) == strlen(s)) {
            return 0;
        }
    }
    return -1;
}

void automatonbuilder(char *s, int choice) {
    fseek(stdin,0,SEEK_END);
    printf("matching against the term '%s'. Please enter in text to match:\n", s);
    int result;
    if (choice == 1) {
        result = automaton(next, s);
    } else {
        result = automaton(noncontiguousnext, s);
    }
    if (result == 0) {
        printf("matched '%s' in text.\n", s);
    } else {
        printf("no match found in text.\n");
    }
}

void matchprompt(int choice) {
    fseek(stdin,0,SEEK_END);
    printf("enter in term to match against:\n");
    char buf[MAXTERMLENGTH];
    int c;
    char *p = buf;
    while ((c = getchar()) != '\n' && c != EOF) {
        *p++ = c;
    }
    *p = '\0';
    automatonbuilder(buf, choice);
}

int main() {
    int c;
    printf("('q': quit) please select an automaton type: '1' for contiguous or '2' non-contiguous\n");
    c = getchar();
    while (c != 'q' && c != '1' && c != '2') {
        c = getchar();
    }
    if (c == 'q') {
        printf("exiting ...\n");
        exit(0);
    } else if (c == '1') {
        printf("contiguous automaton selected\n");
        matchprompt(1);
    } else {
        printf("non-contiguous automaton selected\n");
        matchprompt(2);
    }
}


