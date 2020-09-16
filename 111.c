#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, k, l, len, count = 0;
    char s[] = "this is level 16";

    // gets(s);
    len = strlen(s);

    for (i = 0; i < len; i++)
    {
        if (s[i] != ' ' || s[i] != '\n')
        {
            for (j = i; j < len; j++)
            {
                if (s[j] == ' ' || s[j] == '\n')
                    break;
            }
        }

        for (k = i, l = j - 1;;)
        {
            if (s[k] != s[l])
                break;
            else if (k >= l)
            {
                count = count + 1;
                break;
            }
            else
            {
                k = k + 1;
                l = l - 1;
                continue;
            }
        }

        i = j;
    }

    printf("\n%d", count);
    return 0;
}