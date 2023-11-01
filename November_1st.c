#define _CRT_SECURE_NO_WARNINGS 1

// void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
//         int det=0;
//         int src=0;
//         int arr[m+n];
//         int k=0;
//         if(m==0)
//         {
//             for(int a=0;a<n;a++){
//             nums1[a]=nums2[a];
//         }
//         }
//         while(det<m||src<n)
//         {
//             if(det==m)
//             {
//                 for(;k<m+n;k++)
//                 {
//                     arr[k]=nums2[src++];
//                 }
//             }
//             else if(src==n)
//             {
//                 for( ;k<m+n;k++)
//                 {
//                     arr[k]=nums1[det++];
//                 }
//             }
//             else if(nums1[det]<nums2[src])
//             {
//                 arr[k++]=nums1[det++];
//             }
//             else
//             {
//                 arr[k++]=nums2[src++];
//             }
//         }
//         for(int i=0;i<m+n;i++)
//         {
//             nums1[i]=arr[i];
//         }
// }


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i1 = m - 1; int i2 = n - 1;
    int t = n + m - 1;

    while (i1 >= 0 && i2 >= 0)
    {
        if (nums1[i1] <= nums2[i2])
        {
            nums1[t--] = nums2[i2--];
        }
        else
        {
            nums1[t--] = nums1[i1--];
        }
    }
    while (i2 >= 0)
    {
        nums1[t--] = nums2[i2--];
    }

}