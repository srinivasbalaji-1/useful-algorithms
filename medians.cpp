#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int qselect(vector<int> a,int low, int len);
int findMedian(vector<int> a,int low, int len) {
    int i = 2;
    vector<int> temp;
    if (a.size() <= 5 || len-low<=5) {
        return a[(len+low)/ 2];
    }
    for (i = low+2; i < len; i += 5) {
        temp.push_back(a[i]);
    }
    if(i<len+5){
        temp.push_back(a[(len-1+i-2)/2]);
    }
    int val = qselect(temp,0, temp.size());
    return val;
}

int qselect(vector<int> a, int low,int len) {
    for (int i = low; i < len; i+=5) {
        if (i + 4 < len)
            sort(a.begin()+i, a.begin() +i+5);
        else
            sort(a.begin() + i, a.end());
    }
    int median = findMedian(a,low, len);
    return median;
}

int qs(vector<int> a, int rank, int low, int high) {
    int mid = -1;
    int pivot;
    while (mid != rank) {
        
        int i = low;
        int j = high;
        mid = i==j?i:mid;
        pivot = qselect(a,low,high+1);
        while (i < j) {
            while (a[i] < pivot && i < j) {
                i++;
            }
            while (a[j] > pivot && j > i) {
                j--;
            }
            if(i<j) swap(a[i], a[j]);
            if(i==j) mid = i;
        }
        if(mid>rank)
                high = mid-1;
        else if(mid<rank)
            low = mid+1;
    }
    return pivot;
}

int main() {
    int a[] = {3, 1, 6, 4, 8, 23, 98, 47, 56, 22, 81, 12, 99, 81, 25, 11, 15, 26, 51, 41, 37, 83, 93, 53, 61, 42};
    vector<int> b(a, a + 26);
    cout<<qs(b, 13, 0, 25);
    //qsort(a, 0, 4);

}
