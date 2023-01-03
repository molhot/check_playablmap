# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdbool.h>

char **nanka()
{
    char **test;
    char *tester;
    int i;

    i = 0;
    test = (char **)malloc(sizeof(char *) * 5);
    while (i != 4)
    {
        test[i] = (char *)malloc(sizeof(char) * 5);
        test[i][0] = 'h';
        test[i][1] = 'e';
        test[i][2] = 'l';
        test[i][3] = 'u';
        test[i][4] = '\0';
        i++;
    }
    test[i] = NULL;
    return test;
}

int main()
{
    char **tmp;
    int i;

    i = 0;
    tmp = nanka();
    while (tmp[i] != NULL)
    {
        printf("%s\n", tmp[i]);
        i++;
    }
    tmp = NULL;
    system("leaks -q a.out");
    //free(test[i]);
    //free(test);
}