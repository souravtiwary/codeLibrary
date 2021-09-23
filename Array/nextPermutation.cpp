#include <bits/stdc++.h>
using namespace std;

// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

// The replacement must be in place and use only constant extra memory.



// 1. Start from its last element, traverse backward to find the first one with index i that 
// satisfy num[i-1] < num[i]. So, elements from num[i] to num[n-1] is reversely sorted.
// 2. To find the next permutation, we have to swap some numbers at different positions, 
// to minimize the increased amount, we have to make the highest changed position as high as possible. 
// Notice that index larger than or equal to i is not possible as num[i,n-1] is reversely sorted. 
// So, we want to increase the number at index i-1, clearly, swap it with the smallest number between num[i,n-1] 
// that is larger than num[i-1]. For example, original number is 121543321, we want to swap the '1' at position 2 
// with '2' at position 7.
// 3. The last step is to make the remaining higher position part as small as possible, 
// we just have to reversely sort the num[i,n-1]

class Solution {
public:
    
    void swap(int i, int j, vector<int> &nums){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void reverseVector(vector<int> &nums, int start){
        int i = start;
        int j= nums.size()-1;
        while(i < j){
            swap(i, j, nums);
            i++;;
            j--;
        }
        
    }
    
    void nextPermutation(vector<int>& num) {
       int n=num.size();
        if(n<2)
            return;
        int index=n-1;        
        while(index>0){
            if(num[index-1]<num[index])
                break;
            index--;
        }
        if(index==0){
            reverseVector(num,0);
            return;
        }
        else{
            int val=num[index-1];
            int j=n-1;
            while(j>=index){
                if(num[j]>val)
                    break;
                j--;
            }
            swap(j,index-1, num);
            reverseVector(num,index);
            return;
        }
    }
};