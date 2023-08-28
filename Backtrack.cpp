#include <iostream>
#include <vector>

int count, d;
std::vector<int> w(10), x(10);

void subset(int cs, int k, int r)
{
    int i;
    x[k] = 1;
    if (cs + w[k] == d)
    {
        std::cout << "\nSubset solution = " << ++count << "\n";
        for (i = 0; i <= k; i++)
        {
            if (x[i] == 1)
                std::cout << w[i];
        }
    }
    else if (cs + w[k] + w[k + 1] <= d)
        subset(cs + w[k], k + 1, r - w[k]);
    if ((cs + r - w[k] >= d) && (cs + w[k + 1]) <= d)
    {
        x[k] = 0;
        subset(cs, k + 1, r - w[k]);
    }
}

int main()
{
    int sum = 0, i, n;
    std::cout << "Enter the number of elements\n";
    std::cin >> n;
    std::cout << "Enter the elements in ascending order\n";
    for (i = 0; i < n; i++)
        std::cin >> w[i];
    std::cout << "Enter the required sum\n";
    std::cin >> d;
    for (i = 0; i < n; i++)
        sum += w[i];
    if (sum < d)
    {
        std::cout << "No solution exists\n";
        return 0;
    }
    std::cout << "The solution is\n";
    count = 0;
    subset(0, 0, sum);
    return 0;
}
