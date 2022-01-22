#include <stdio.h>

int gcd(int g, int l)

{
    if (l > 0)
    {
        return gcd(l, (g % l));
    }
    else
    {
        return g;
    }
}

int main()
{
    int result = gcd(450, 40);
    printf("res is: %i\n", result);
}