class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
 int i = 0, j = 0, result = -1;
    
    // Loop to find the k-th element
    while (k > 0 && i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            result = arr1[i];
            i++;
        } else {
            result = arr2[j];
            j++;
        }
        k--;
    }
    
    // If arr1 still has elements left
    while (i < n && k > 0) {
        result = arr1[i];
        i++;
        k--;
    }
    
    // If arr2 still has elements left
    while (j < m && k > 0) {
        result = arr2[j];
        j++;
        k--;
    }
    
    return result;

    }
};
