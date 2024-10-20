public class Mergesort {

    public static void printarr(int arr[]) {

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }

        System.out.println();
    }

    // DIVIDE
    public static void sort(int arr[], int si, int ei) {

        // Base condition
        if (si >= ei) {
            return;
        }

        int mid = si + (ei - si) / 2;

        // left side
        sort(arr, si, mid);

        // right side
        sort(arr, mid + 1, ei);

        // merging both the left and right side
        merge(arr, si, ei, mid);
    }

    // CONQUER
    // Function for merging the left and right array
    public static void merge(int arr[], int si, int ei, int mid) {

        // firstly, we will create a temporary array to merge the left and right side of
        // the array
        int temp[] = new int[ei - si + 1]; // size of the new array.

        // Now we will make the iterator for both the parts
        int i = si; // left part
        int j = mid + 1; // right part
        int k = 0; // temp array

        while (i <= mid && j <= ei) {
            if (arr[i] < arr[j]) {
                temp[k] = arr[i];
                i++;
            } else {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }
        while (i <= mid) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        while (j <= ei) {
            temp[k] = arr[j];
            j++;
            k++;
        }

        // copy temporary to my original array
        for (k = 0, i = si; k < temp.length; k++, i++) {
            arr[i] = temp[k];
        }
    }

    public static void main(String args[]) {

        int arr[] = { 2, 5, 8, 4, 9, 3 };

        sort(arr, 0, arr.length - 1); // Remember: ei is arr.length-1

        printarr(arr);
    }
}
// We use Depth first search to implement Merge sort