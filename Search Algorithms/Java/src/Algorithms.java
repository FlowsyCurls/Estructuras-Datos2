import java.util.Arrays;


public class Algorithms {
    int[] array = {10, 12, 13, 16, 18, 19, 21, 24, 25, 28, 33, 35, 42, 47};
    int size = 10;

    Algorithms() {}

    public void print() {
        System.out.println(Arrays.toString(array));
    }

    public int sequentialSearch(int key) {
        for (int i = 0; i < array.length; i++)
            if(array[i] == key) {
                return i;
            }
        return -1;
    }

    public int binarySearch(int key) {
        int l = 0, r = array.length - 1;
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

    public int interpolationSearch(int key){
        // Find indexes of two corners
        int low = 0, high = (this.array.length - 1);
        while ((low <= high) && (key >= this.array[low]) && (key <= this.array[high])){
            if (low == high) {
                if (this.array[low] == key)
                    return low;
                return -1;
            }
            int pos = low + (((high-low) /
                    (this.array[high]- this.array[low]))*(key - this.array[low]));
            if (this.array[pos] == key)
                return pos;
            if (this.array[pos] < key)
                low = pos + 1;
            else
                high = pos - 1;
        }
        return -1;
    }
}
