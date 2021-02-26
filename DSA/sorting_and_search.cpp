#include<bits/stdc++.h>
#include<limits.h>

int inf = std::numeric_limits<int>::max();

using namespace std;

void swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}


void display(int array[], int size)
{
    for(int i=0; i<size; i++)
        cout<<array[i]<<" ";
}


//sorting functions
// O(n^2) sort time
void insertion_sort(int array[], int size)
{
    for(int i=1; i<size; i++)
    {
        if (array[i] < array[i-1])
        {
            int tmp = array[i];
            int j = i-1;
            while(j>=0 and array[j] > tmp)
            {
                swap(&array[j+1], &array[j]);
                j--;
            }
            array[j+1] = tmp;
        }
    }
}


// O(n^2) sort time
void bubble_sort(int array[], int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=i+1;j<size; j++)
        {
            if (array[j] < array[i])
                swap(&array[i], &array[j]);
        }
    }
}

void merge(int array[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int p1[n1 + 1], p2[n2 + 1];
    //setting temp arrays with elements of two halves
    for(int i=1; i<=n1; i++)
        p1[i] = array[p + i - 1];
    for(int j=1; j<=n2; j++)
        p2[j] = array[q + j];

    int i = 1, j = 1;
    p1[n1+1] = inf;
    p2[n2+1] = inf;
    for(int k=p; k<=r; k++)
    {
        if (p1[i]<=p2[j])
        {
            array[k] = p1[i];
            i++;
        }
        else
        {
            array[k] = p2[j];
            j++;
        }
    }
}


// O(nlogn) sort time
void merge_sort(int array[], int p, int r)
{
    if(p < r)
    {
        int q = (p+r)/2;
        merge_sort(array, p, q);
        merge_sort(array, q+1, r);
        merge(array, p, q, r);
    }
}

//searchin algos
// O(n) search time
bool linear_search(int array[], int size, int val)
{
    for(int i=0; i<size;i++)
        if (array[i] == val)
            return true;
    return false;
}

// O(logn) for sorted array
int binary_search(int array[],int l, int r, int val)
{
    // merge_sort(array, 0, r-1);
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (array[mid] == val) 
            return mid; 
  
        if (array[mid] > val) 
            return binary_search(array, l, mid - 1, val); 
  
        return binary_search(array, mid + 1, r, val); 
    } 
    return -1; 
}

int main()
{
    int array[] = {6,8,4,3,2,112,31,52,1};
    int size = sizeof(array)/ sizeof(array[0]);
    cout<<"\nUnsorted Array: ";
    display(array, size);
    cout<<"\n";
    insertion_sort(array, size);
    merge_sort(array, 0, size-1);
    cout<<"\nSorted Array: ";
    display(array, size);
    // cout<<"\n"<<linear_search(array, size, 1);
    cout<<"\n"<<binary_search(array, 0, size-1, 112);
    return 1;
}
