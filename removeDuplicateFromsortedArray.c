

int removeDuplicates(int* nums, int numsSize){
     int k = 0;
    for (int j = 0; j < numsSize; j++)
    {
        if (nums[j] == nums[j + 1])
        {
            nums[j] = 1000;
            k++;
        }
    }
    // sorting the array 
    int temp;
    for (int i = 0; i < numsSize; ++i)
    {
        for (int j = i + 1; j < numsSize; ++j)
        {
            if (nums[i] > nums[j])
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    return k;
}