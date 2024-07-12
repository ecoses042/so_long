#include "../so_long.h"

#include "../so_long.h"
#include <stdlib.h>

static int issep(char a, char b)
{
    return (a == b || a == ' ');
}

static size_t count_words(char const *s, char c)
{
    size_t i = 0;
    size_t count = 0;
    while (s[i])
    {
        while (s[i] && issep(s[i], c))
            i++;
        if (s[i] && !issep(s[i], c))
        {
            count++;
            while (s[i] && !issep(s[i], c))
                i++;
        }
    }
    return count;
}

static char *extract_word(char const *str, char c, size_t *index)
{
    size_t start = *index;
    size_t len = 0;
    while (str[*index] && !issep(str[*index], c))
    {
        len++;
        (*index)++;
    }
    char *word = (char *)malloc(len + 1);
    if (!word)
        return NULL;
    size_t i;
    for (i = 0; i < len; i++)
        word[i] = str[start + i];
    word[i] = '\0';
    return word;
}

static char **free_and_ret_null(char **result, size_t i)
{
    while (i > 0)
    {
        free(result[--i]);
    }
    free(result);
    return NULL;
}

char **ft_split(char const *s, char c)
{
    if (!s)
        return NULL;
    size_t words = count_words(s, c);
    char **result = (char **)malloc(sizeof(char *) * (words + 1));
    if (!result)
        return NULL;
    size_t i = 0;
    size_t index = 0;
    while (i < words)
    {
        while (s[index] && issep(s[index], c))
            index++;
        if (s[index] && !issep(s[index], c))
        {
            result[i] = extract_word(s, c, &index);
            if (!result[i])
                return free_and_ret_null(result, i);
            i++;
        }
    }
    result[i] = NULL;
    return result;
}
