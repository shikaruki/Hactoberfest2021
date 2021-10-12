import java.util.Arrays;

public class SelectionSort {

    void selectionSort(int array[]) {
        int size = array.length;
        for (int step = 0; step < size - 1; step++) {
            int min_idx = step;
            for (int i = step + 1; i < size; i++) {
                if (array[i] < array[min_idx]) {
                    min_idx = i;
                }
            }

            int temp = array[step];
            array[step] = array[min_idx];
            array[min_idx] = temp;
        }
    }
    public static void main(String args[]) {
        int[] arr = {45,25,89,65,24,2, 4,55,656, 3, 5, 1, 8, 6, 7};
        SelectionSort temp = new SelectionSort();
        temp.selectionSort(arr);
        System.out.println("Sorted Array in Ascending Order: ");
        System.out.println(Arrays.toString(arr));
    }
}
