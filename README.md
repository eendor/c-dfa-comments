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

Both demonstrations are hardcoded in `comment.c`:

```c
char accepted[] = "/*aaa*aaa*/";
char rejected[] = "/*aaa*aaa*/a";
```

The rejected string completes the comment and reaches `Q4`, but the extra `a` afterwards moves the DFA from `Q4` to `DEAD`.

Output:

```
Accepted demonstration:
Input: /*aaa*aaa*/
Result: Accepted

Rejected demonstration:
Input: /*aaa*aaa*/a
Result: Rejected
```
