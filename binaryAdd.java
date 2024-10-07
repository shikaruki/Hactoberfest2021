import java.util.Scanner;

public class binaryAdd {

    // Method to add two binary numbers
    public static String addBinary(String a, String b) {
        StringBuilder result = new StringBuilder(); // To store the result
        int i = a.length() - 1, j = b.length() - 1, carry = 0; // Index pointers and carry initialization
        
        // Loop through both strings from right to left
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;  // Start with carry from the last addition
            
            if (i >= 0) sum += a.charAt(i--) - '0'; // Convert char to int and add
            if (j >= 0) sum += b.charAt(j--) - '0';
            
            result.append(sum % 2);  // Append the result of sum modulo 2 (binary addition)
            carry = sum / 2;  // Update the carry for the next position
        }
        
        return result.reverse().toString();  // Reverse and return the result
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input two binary numbers
        System.out.print("Enter first binary number: ");
        String binary1 = scanner.nextLine();
        
        System.out.print("Enter second binary number: ");
        String binary2 = scanner.nextLine();
        
        // Output the result of binary addition
        String result = addBinary(binary1, binary2);
        System.out.println("Sum of binary numbers: " + result);
        
        scanner.close();
    }
}
