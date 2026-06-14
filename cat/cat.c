#include <stdio.h>

int main (int argc, char *argv[])
{
        for (int i = 1; i < argc; i++)
        {
                FILE *file_ptr = fopen(argv[i], "r");

                if (file_ptr == NULL)
                {
                        printf("cat: %s: No such file or directory\n", argv[i]);
                        continue;
                }

                int current;

                while ((current = fgetc(file_ptr)) != EOF)
                {
                        printf("%c", current);
                }

                fclose(file_ptr);
        }
        return 0;
}
