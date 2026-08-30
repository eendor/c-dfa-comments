/* DFA for a single C-style comment over the alphabet { a, *, / } */

#include <stdio.h>

/* DFA states */
enum State {
    Q0,    /* start, expecting '/' */
    Q1,    /* read '/', expecting '*' */
    Q2,    /* inside comment body */
    Q3,    /* inside comment, last symbol was '*' */
    Q4,    /* accepting: read closing '*' then '/' */
    DEAD   /* trap state */
};

/* alphabet symbols; SYM_A = any character that is not '*' or '/' */
enum Symbol { SYM_A, SYM_STAR, SYM_SLASH };

static enum Symbol classify(char c)
{
    if (c == '*') return SYM_STAR;
    if (c == '/') return SYM_SLASH;
    return SYM_A;
}

static enum State step(enum State s, enum Symbol x)
{
    switch (s) {
    case Q0:
        return (x == SYM_SLASH) ? Q1 : DEAD;
    case Q1:
        return (x == SYM_STAR) ? Q2 : DEAD;
    case Q2:
        return (x == SYM_STAR) ? Q3 : Q2;
    case Q3:
        if (x == SYM_SLASH) return Q4;
        if (x == SYM_STAR)  return Q3;
        return Q2;
    case Q4:
        return DEAD;   /* nothing may follow the closing delimiter */
    default:
        return DEAD;
    }
}

/* run the DFA over the whole comment; 1 only if it halts in Q4 */
static int accepts(const char comment[])
{
    enum State s = Q0;
    int i;

    for (i = 0; comment[i] != '\0'; i++)
        s = step(s, classify(comment[i]));

    return s == Q4;
}

static void demo(const char *title, const char comment[])
{
    printf("%s\n", title);
    printf("%s\n", comment);
    printf("%s\n", accepts(comment) ? "Accepted" : "Rejected");
}

int main(void)
{
    char accepted[] = "/*aaa*aaa*/";
    char rejected[] = "/*aaa*aaa*/a";

    demo("Accepted demonstration:", accepted);
    printf("\n");
    demo("Rejected demonstration:", rejected);

    return 0;
}
