#include <iostream>
#include <vector>
using namespace std;

vector<int> array = {10, 12, 13, 16, 18, 19, 21, 24, 25, 28, 33, 35, 42, 47};

int SequentialSearch (int key){
    int index = 0;
    while((index < array.size()) && (key != array[index])){
        if (array[index] != key)
            index++;
    }
    return (index);
}

int BinarySearch (int key){
    int l = 0, r = array.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (array[m] == key) // Check if key is at mid
            return m;
        if (array[m] < key) // If key greater, ignore left half
            l = m + 1;
        else // If key is smaller, ignore right half
            r = m - 1;
    }
    return -1;
}

int InterpolationSearch (int key){
    // Find indexes of two corners
    int low = 0, high = array.size() - 1;
    while ((low <= high) && (key >= array[low]) && (key <= array[high])){
        if (low == high) {
            if (array[low] == key)
                return low;
            return -1;
        }
        int pos = low + (((high-low) /
                          (array[high]- array[low]))*(key - array[low]));
        if (array[pos] == key)
            return pos;
        if (array[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}



int main() {
    int a = SequentialSearch(33);
    int b = BinarySearch(33);
    int c = InterpolationSearch(33);

    if (a==b && b==c)
        cout <<"Element is found at index: " << a << endl;
    else cout << "Element is not found!" << endl;
    return 0;
}
