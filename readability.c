#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int letter_count(string x);
int word_count(string x);
int sentence_count(string x);

int main(void)
{
    string text = get_string("Enter text:\n");

    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            count++;
        }
    }

    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
    }

    int words = 0;
    char *separated = strtok(text, " ");
    while (separated != NULL)
	{
	    words++;
		separated = strtok(NULL, " ");
	}


    printf("There are %i sentences\n", count);
    printf("There are %i letters\n", letters);
    printf("There are %i words\n", words);

    float L = 100 * letters / words;
    float S = 100 * count / words;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}