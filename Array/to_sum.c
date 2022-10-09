typedef struct linkList{
	int data;
	int index_nums;
	struct linkList *ptr;
}linkList;

void hashInsert(int i, int val, int hashSize, linkList *hashT){
        int tmp_val;
	(val < 0) ? (tmp_val = (-1) * val) : (tmp_val = val);
	linkList *tmp_ptr = &hashT[tmp_val % hashSize];
	while(tmp_ptr->ptr) tmp_ptr = tmp_ptr->ptr;
	tmp_ptr->ptr = (linkList *)calloc(1, sizeof(linkList));
	tmp_ptr->ptr->data = val;
	tmp_ptr->ptr->index_nums = i;
}

_Bool hashSearch(int c, int val, int *index, int hashSize, linkList *hashT){
        int tmp_val;
	(val < 0) ? (tmp_val = (-1) * val) : (tmp_val = val);
	linkList *tmp_ptr = &hashT[tmp_val % hashSize];
	tmp_ptr = tmp_ptr->ptr;
	while(tmp_ptr) {
		if((tmp_ptr->data == val) && (tmp_ptr->index_nums != c)){
			*index = tmp_ptr->index_nums;
			return true;
		}
		tmp_ptr = tmp_ptr->ptr;
	}
	return false;
}

int* twoSum(int* nums, int numsSize, int target) {
        linkList *hashT;
	int i, *indexes, tmp, index, hashTSize = 1.3 * numsSize;

	hashT = (linkList *)calloc(hashTSize, sizeof(linkList));
	indexes = (int *)calloc(2, sizeof(int));
	for(i = 0; i < numsSize; i++) hashInsert(i, nums[i], hashTSize, hashT);
	for(i = 0; i < numsSize; i++) {
		tmp = target - nums[i];
		if(hashSearch(i, tmp, &index, hashTSize, hashT)){
			indexes[0] = i;
			indexes[1] = index;
			break;
		}
	}
	return indexes;
}