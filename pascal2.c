long double binom(int n, int k){
    long double fact = 1;
    if (k)
    {
        for (int i = n - k + 1; i <= n; i++) fact *= i;
        for (int i = k; i > 1; i--) fact /= i;
    }
    return fact;
}

int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;
    int end = ceil((*returnSize / 2.));
    
    int* row = (int*) malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < end; i++) 
    {
        row[i] = binom(rowIndex, i);
        row[(*returnSize) - (i + 1)] = row[i];
    }
    
    return row;
}