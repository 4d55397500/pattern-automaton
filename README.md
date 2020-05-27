# pattern-automaton
A string matching pattern automaton in c.

### Background

A finite automaton consists of a set of states {s_i}, a sequence of inputs {c_j},  and a state transition function T: (s_i, c_j) |-> s_k
. For pattern matching we would say one such state corresponds to a ‘match’. For string matching allowed state transitions
are increments until a match is found, or it's ‘back to the beginning’ aka one starts over.

### Run

Run the main program. There are 'contiguous' and 'non-contiguous' automatons implemented. A sample run:
```
('q': quit) please select an automaton type: '1' for contiguous or '2' non-contiguous
2
non-contiguous automaton selected
enter in term to match against:
a ow e
matching against the term 'a ow e'. Please enter in text to match:
its a long way from Kansas rieght here.
matched 'a ow e' in text.

```
