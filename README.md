# DFA for C-Style Comments

**Rodnee Glen A. Martin**  
**3 BSCS-A**  
**CS 13a — Automata Theory and Formal Language**

A C implementation of a Deterministic Finite Automaton (DFA) that recognizes C-style comments. The DFA uses the abstract alphabet `{a, *, /}`, where `a` represents any character other than `*` or `/`.

## DFA Visualization

![DFA Transition Visualization](dfa_transitions.gif)

## States

| State | Meaning |
| --- | --- |
| `Q0` | start state |
| `Q1` | opening `/` has been read |
| `Q2` | inside the comment |
| `Q3` | `*` has been encountered inside the comment |
| `Q4` | accepting state after the closing delimiter |
| `DEAD` | trap / reject state |

## Compile

```bash
gcc -Wall -Wextra -std=c11 comment.c -o comment
```

## Run

Windows:

```bash
.\comment.exe
```

Linux / macOS:

```bash
./comment
```

## Example

Hardcoded input in `comment.c`:

```c
char input[] = "/*aaa*aaa*/";
```

Output:

```
Accepted
```
