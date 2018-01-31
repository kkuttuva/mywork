#include <stdio.h>
#include <string.h>

char decodeStr[10][4] = { { '0', -1, -1, -1 },
                          { '1', -1, -1, -1 },
                          { 'A', 'B', 'C', -1 },
                          { 'D', 'E', 'F', -1 },
                          { 'G', 'H', 'I', -1 },
                          { 'J', 'K', 'L', -1 },
                          { 'M', 'N', 'O', -1 },
                          { 'P', 'Q', 'R', 'S'},
                          { 'T', 'U', 'V', -1 },
                          { 'X', 'Y', 'Z', -1 }};

void genKey(char *nums, int pos, int len, char *res)
{
    int i;

    if (pos == len)
    {
        res[pos] = 0;
        printf("%s\n", res);
        return;
    }

    for (i = 0; i < 4; i++)
    {
        if (decodeStr[nums[pos] - '0'][i] == -1)
            continue;
        res[pos] = decodeStr[nums[pos] - '0'][i];
        genKey(nums, pos + 1, len, res);
    }
}

int main()
{
    char input[256], res[256];
    strcpy(input, "123");
    genKey(input, 0, strlen(input), res);

    strcpy(input, "120");
    genKey(input, 0, strlen(input), res);
    return 0;
}
