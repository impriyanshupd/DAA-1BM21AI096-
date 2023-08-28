#include <iostream>
#include <cstring>

int main()
{
    int table[126];
    char t[100], p[25];
    int n, i, k, j, m, flag = 0;
    std::cout << "Enter the Text" << std::endl;
    std::cin.getline(t, 100);
    n = strlen(t);
    std::cout << "Enter the Pattern" << std::endl;
    std::cin.getline(p, 25);
    m = strlen(p);
    for (i = 0; i < 126; i++)
        table[i] = m;
    for (j = 0; j <= m - 2; j++)
        table[p[j]] = m - 1 - j;
    i = m - 1;
    while (i <= n - 1)
    {
        k = 0;
        while (k <= m - 1 && p[m - 1 - k] == t[i - k])
            k++;
        if (k == m)
        {
            std::cout << "The position of the pattern is " << i - m + 2 << std::endl;
            flag = 1;
            break;
        }
        else
            i = i + table[t[i]];
    }
    if (!flag)
        std::cout << "Pattern is not found in the given text" << std::endl;
    return 0;
}
