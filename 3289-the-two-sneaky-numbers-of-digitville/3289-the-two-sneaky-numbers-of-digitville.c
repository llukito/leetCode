/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int max_ = 0;
    for(int i=0; i<numsSize; i++){
        if(nums[i] > max_){
            max_ = nums[i];
        }
    }
    max_++;
    int arr[max_];for(int i=0; i<max_; i++)arr[i]=0;
    for(int i=0; i<numsSize; i++){
        arr[nums[i]]++;
    }
    int size = 0;
    for(int i=0; i<max_; i++){
        if(arr[i] > 1){
            size++;
        }
    }
    *returnSize = size;
    int* res = malloc(size*sizeof(int));
    int idx = 0;
    for(int i=0; i<max_; i++){
        if(arr[i] > 1){
            res[idx++] = i;
        }
    }
    return res;
}