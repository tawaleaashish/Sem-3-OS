#include <stdio.h>
void main()
{
    int i, j, k, n, r;
    printf("Number of Process = ");
    scanf("%d", &n);
    printf("Number of types of Resources = ");
    scanf("%d", &r);
    int Resource_allocated[n][r], Resource_Max[n][r], Resource_available[r], allocated_total[r];
    int total_resources[r], Resource_needed[n][r], f[n], flag, completed = n;
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Resource allocation value of P%d\n", i + 1);
        for (j = 0; j < r; j++)
        {
            printf("Resource allocation value of Type %c : ", j + 65);
            scanf("%d", &Resource_allocated[i][j]);
        }
        printf("\nEnter Max Resource value of P%d\n", i + 1);
        for (j = 0; j < r; j++)
        {
            printf("Maximun Resource required of Type %c: ", j + 65);
            scanf("%d", &Resource_Max[i][j]);
        }
    }
    for (j = 0; j < r; j++)
    {
        printf("\nTotal Resources of Type %c: ", j + 65);
        scanf("%d", &total_resources[j]);
    }
    for (i = 0; i < n; i++)
    {
        f[i] = 0;
        for (j = 0; j < r; j++)
        {
            Resource_needed[i][j] = Resource_Max[i][j] - Resource_allocated[i][j];
            allocated_total[j] += Resource_allocated[i][j];
        }
    }
    for (j = 0; j < r; j++)
    {
        Resource_available[j] = total_resources[j] - allocated_total[j];
    }
    for (i = 0; i < n; i++)
    {
        flag = 0;
        if (f[i] == 0)
        {
            for (j = 0; j < r; j++)
            {
                if (Resource_needed[i][j] > Resource_available[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                for (j = 0; j < r; j++)
                {
                    Resource_available[j] += Resource_allocated[i][j];
                }
                f[i] = 1;
                completed--;
                if (completed > 0)
                    printf("P%d -> ", i+1);
                else
                    printf("P%d", i+1);
            }
        }
        if (completed > 0 && i == n - 1)
            i = -1;
    }
}