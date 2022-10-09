int num,i;
int arr[10000];

void inorder(struct TreeNode* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        arr[i++]=root->val;
        //printf("%d-",root->val);
        inorder(root->right);
    }
}



bool find(int k){
    int l=0, r = num-1;
    while(l<r){
        if(arr[l] + arr[r] == k){
            return true;
        } else if(arr[l] + arr[r] > k){
            r--;
        } else {
            l++;
        }
    }
    return false;
}