void travel(struct TreeNode *root,int arr,int size){
        if(root==NULL)
        return;
        arr[(size)++]=root->val;
        travel(root->left,arr,size);
        travel(root->right,arr,size);
        }
        int preorderTraversal(struct TreeNode root, int returnSize){
        *returnSize=0;
        int *arr=(int )malloc(100sizeof(int));
        travel(root,arr,returnSize);
        return arr;
}