// 912. Sort an Array

#include <bits/stdc++.h> 

using namespace std;

// heap sort 
class Solution {
public:
    vector<int> min_heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (2 * i + 1);
    }

    int right(int i) {
        return (2 * i + 2);
    }

    void heapify(int i) {
        if (left(i) > min_heap.size() - 1)
            return;
        
        int j = left(i);
        if (right(i) < min_heap.size() && min_heap[left(i)] > min_heap[right(i)])
            j = right(i);
        if (min_heap[i] > min_heap[j]) {
            swap(min_heap[i], min_heap[j]);
            heapify(j);
        }
    }

    int extract_min() {
        int min = min_heap[0];
        swap(min_heap[0], min_heap[min_heap.size() - 1]);
        min_heap.pop_back();
        if (min_heap.size() > 0) 
            heapify(0);
        return min;
    }

    void sift_up(int i) {
        while (i > 0 && min_heap[parent(i)] > min_heap[i]) {
            swap(min_heap[parent(i)], min_heap[i]);
            i = parent(i);
        }
    }

    void insert(int x) {
        min_heap.push_back(x);
        int i = min_heap.size() - 1;

        sift_up(i);
    }

    void print(){
        for(auto i: min_heap) cout << i << " ";
    }


    vector<int> sortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            insert(nums[i]);    
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = extract_min();
        }

        return nums;
    }
};


// heap sort with built-in priority_queue
class Solution2 {
public:
    priority_queue<int, vector<int>, greater<int> > pq;

    vector<int> heap_sort(vector<int>& a) {
        for (int i = 0; i < a.size(); i++) {
            pq.push(a[i]);
        }
        int j = 0;
        while (pq.size() != 0) {
            a[j] = pq.top();
            pq.pop();
            j++;
        }
        return a;
    }
    vector<int> sortArray(vector<int>& nums) {
        heap_sort(nums);
        return nums ;
    }
};


// quick sort
class Solution3 {
public:
    void quick_sort(vector<int>& a, int left, int right) {
        if (left >= right) {
            return;
        }

        int mid = (left + right) / 2;
        int pivot = a[mid];

        int i = left, j = right;
        
        while (i <= j) {
            while (a[i] < pivot) {
                i++;
            }
            while (pivot < a[j]) {
                j--;
            }
            if (i <= j) {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }        

        quick_sort(a, left, j);
        quick_sort(a, i, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1); 
        return nums;     
    }
};


// merge sort
class Solution4 {
public:
    void merge_arrays(vector<int>&a, int left, int mid, int right) {
        int left_size = mid - left + 1;
        int right_size = right - mid;
        
        int L_arr[left_size];
        int R_arr[right_size];

        for (int i = 0; i < left_size; i++) {
            L_arr[i] = a[left + i];
        }

        for (int i = 0; i < right_size; i++) {
            R_arr[i] = a[mid + i + 1];
        }


        int L_i = 0;
        int R_i = 0;
        int k = left;

        while (L_i < left_size && R_i < right_size) {
            if (L_arr[L_i] <= R_arr[R_i]) {
                a[k] = L_arr[L_i];
                L_i++;
            }
            else {
                a[k] = R_arr[R_i];
                R_i++;
            }
            k++;
        }

        while (L_i < left_size) {
            a[k] = L_arr[L_i];
            L_i++;
            k++;
        }

        while (R_i < right_size) {
            a[k] = R_arr[R_i];
            R_i++;
            k++;
        }
    }

    void merge_sort(vector<int>& a, int left, int right) {
        if (left >= right) {
            return;
        }
        
        int mid = (left + right) / 2;

        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);

        merge_arrays(a, left, mid, right);

    }

    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};


int main() {
    Solution s;
    int n = 10;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> aa = s.sortArray(v);

    for (auto a: aa) cout << a << " ";

    return 0;
}