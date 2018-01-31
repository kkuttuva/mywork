#include <string.h>
#include <malloc.h>
#include <stdio.h>

int isVowel(char c)
{
    return (c == 'a') ||
           (c == 'e') ||
           (c == 'i') ||
           (c == 'o') ||
           (c == 'u');
}

void swap (char *s, int l, int r)
{
   char t = s[l];
   s[l] = s[r];
   s[r] = t;
}

char * reverse(const char *s)
{
    int len = strlen(s);
    int l = 0, r = len - 1;

    char * rev = (char *)malloc(len + 1);
    strcpy(rev, s);

    while (l < r)
    {
       while (!isVowel(rev[l]) && (l < r))
          l++;
       while (!isVowel(rev[r]) && (l < r))
          r--;
       if (l < r)
          swap(rev, l, r);
       l++;
       r--;
    }

    return rev;
}

int main()
{
    printf("%s\n", reverse("bc"));
    printf("%s\n", reverse("bcd"));
    printf("%s\n", reverse("aaa"));
    printf("%s\n", reverse("eooe"));
    printf("%s\n", reverse("aei"));
    printf("%s\n", reverse("aeea"));
    printf("%s\n", reverse("ada"));
    printf("%s\n", reverse("adfe"));
    return 0;
}
