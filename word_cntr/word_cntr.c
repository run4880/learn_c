#include <windows.h>
#include <stdio.h>

#define IN 1  /* внутри слова */
#define OUT 0 /* снаружи слова */

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int c, state, nc, nw, nl;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;

        if (c == '\n')
            ++nl;

        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("Кол-во: символов %d, слов %d, строк %d", nc, nw, nl);
}