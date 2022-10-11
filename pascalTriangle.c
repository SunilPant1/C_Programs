int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int** pRetVal = NULL;

    (*returnSize) = numRows;
    (*returnColumnSizes) = (int*)malloc((*returnSize) * sizeof(int));
    if ((*returnColumnSizes) == NULL)
    {
        perror("malloc");
        return pRetVal;
    }
    pRetVal = (int**)malloc((*returnSize) * sizeof(int*));
    if (pRetVal == NULL)
    {
        perror("malloc");
        free((*returnColumnSizes));
        (*returnColumnSizes) = NULL;
        return pRetVal;
    }

    int i;
    int Combination;
    int n, k;
    for (n=1; n<=numRows; ++n)
    {
        (*returnColumnSizes)[n-1] = n;
        pRetVal[n-1] = (int*)malloc(((*returnColumnSizes)[n-1]) * sizeof(int));
        if (pRetVal[n-1] == NULL)
        {
            perror("malloc");
            free((*returnColumnSizes));
            (*returnColumnSizes) = NULL;
            for (i=1; i<n; ++i)
            {
                free(pRetVal[i-1]);
                pRetVal[i-1] = NULL;
            }
            free(pRetVal);
            pRetVal = NULL;
            return pRetVal;
        }
        memset(pRetVal[n-1], 0, ((*returnColumnSizes)[n-1]) * sizeof(int));

        Combination = 1;
        for(k=1; k<=n; ++k)
        {
            pRetVal[n-1][k-1] = Combination;

            
            Combination = Combination * (n - k) / k;
        }
    }

    return pRetVal;
}