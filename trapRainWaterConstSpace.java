import java.io.*;
import java.util.*;
import java.lang.*;

class Solution{
    // arr: input array
    // n: size of array
    // Function to find the trapped water between the blocks.
    static int trappingWater(int arr[], int n) {

        // Your code here
        int result = 0;

        // maximum element on left and right
        int left_max = 0, right_max = 0;

        // indices to traverse the array
        int lo = 0, hi = n - 1;

        while (lo < hi) {
            if (arr[lo] < arr[hi]) {
                if (arr[lo] > left_max)
                    // update max in left
                    left_max = arr[lo];
                else
                    // water on curr element = max - curr
                    result += left_max - arr[lo];
                lo++;
            }
            else {
                if (arr[hi] > right_max)
                    // update right maximum
                    right_max = arr[hi];
                else
                    result += right_max - arr[hi];
                hi--;
            }
        }

        return result;
    }
}

class trapRainWaterConstSpace {

    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

//        int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
//        while(t-->0){

            //size of array
            System.out.print("Enter size of array : ");
            int n = Integer.parseInt(br.readLine().trim());
            int arr[] = new int[n];
            System.out.print("Enter array elements : ");
            String inputLine[] = br.readLine().trim().split(" ");

            //adding elements to the array
            for(int i=0; i<n; i++){
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            Solution obj = new Solution();

            //calling trappingWater() function
            System.out.println(obj.trappingWater(arr, n));
//        }
    }
}

