#include <stdio.h>
void main()
{
    int a1[50], a2[50], a3[100], i, j, k = 0, n, m;
    printf("Enter the size of 1st array: ");
    scanf("%d", &m);
    printf("Enter elements for the first array:\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &a1[i]);
    }
    printf("Enter the size of 2nd array: ");
    scanf("%d", &n);
    printf("Enter elements for the second array:\n");
    for (j = 0; j < n; j++)
    {
        scanf("%d", &a2[j]);
    }
    i = 0;
    j = 0;
    while (i < m && j < n)
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
    if (i >= m)
    {
        while (j < n)
        {
            a3[k] = a2[j];
            j++;
            k++;
        }
    }
    if (j >= n)
    {
        while (i < m)
        {
            a3[k] = a1[i];
            i++;
            k++;
        }
    }

    printf("merged array:\n");
    for (i = 0; i < (m + n); i++)
    {
        printf("%d  ", a3[i]);
    }
}