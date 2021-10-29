
// Java Program to find maximum in arr[] 
class Test
{
     static int arr[] = {10, 324, 45, 90, 9808};
       
     // Method to find maximum in arr[]
     static int largest()
     {
         int i;
           
         // Initialize maximum element
         int max = arr[0];
        
         // Traverse array elements from second and
         // compare every element with current max  
         for (i = 1; i < arr.length; i++)
             if (arr[i] > max)
                 max = arr[i];
        
         return max;
     }
       
     // Driver method
     public static void main(String[] args) 
     {
         System.out.println("Largest in given array is " + largest());
        }
 }
