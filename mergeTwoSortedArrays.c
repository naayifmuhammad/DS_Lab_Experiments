#include <stdio.h>
void main()
{
    int a1[50], a2[50], a3[100], i, j, k = 0, n, m;
    printf("Enter the size of 1st array");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a1[i]);
    }
    printf("Enter the size of 2nd array");
    scanf("%d", &m);
    for (j = 0; j < m; j++)
    {
        scanf("%d", &a2[j]);
    }
    i = 0;
    j = 0;
    while (i < n && j < m)
    {
        if (a1[i] < a2[j])
        {
            a3[k] = a1[i];
            i++;
        }
        else
        {
            a3[k] = a2[j];
            j++;
        }
        k++;
    }
    if (i >= n)
    {
        while (j < m)
        {
            a3[k] = a2[j];
            j++;
            k++;
        }
    }
    if (j >= m)
    {
        while (i < n)
        {
            a3[k] = a1[i];
            i++;
            k++;
        }
    }
    printf("merged array:\n");
    for (i = 0; i < n + m; i++)
    {
        printf("%d", a3[i]);
    }
}