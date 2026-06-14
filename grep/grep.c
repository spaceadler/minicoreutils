#include <string.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
        if (argc < 3)
        {
                printf("Usage: ./grep <search_term> <file> <...>\n");
                return 1;
        }

        char *search_term = argv[1];
        char line_buffer[2048];

        for (int i = 2; i < argc; i++)
        {
                FILE *file_ptr = fopen(argv[i], "r");

                if (file_ptr == NULL)
                {
                        printf("grep: %s: No such file or directory\n", argv[i]);
                        continue;
                }

                while (fgets(line_buffer, sizeof(line_buffer), file_ptr) != NULL)
                {
                        if (strstr(line_buffer, search_term) != NULL)
                        {
                                printf("%s", line_buffer);
                        }
                }
                fclose(file_ptr);
        }
        return 0;
}
