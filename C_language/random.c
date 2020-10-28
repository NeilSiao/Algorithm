#include <stdio.h>

/* function to generate and return random numbers */
int *getRandom(int max, int total)
{

    int r[total];
    int i;

    /* set the seed */
    srand((unsigned)time(NULL));

    for (i = 0; i < total; ++i)
    {
        r[i] = rand() % max + 1;
        printf("r[%d] = %d\n", i, r[i]);
    }

    return r;
}

/* main function to call above defined function */
int main()
{

    /* a pointer to an int */
    int *p;
    int i;

    printf("--- Section.1 : Six Numbers ---\n");

    p = getRandom(39, 6);

    printf("--- Section.2  One Numbers ---\n");

    p = getRandom(8, 1);

    return 0;
}