import java.util.Scanner;

public class Operators_Calculator {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter first number");
        int a = in.nextInt();
        System.out.println("Enter second number");
        int b = in.nextInt();
        System.out.println("Enter operator (+,-,*,/) to perform operation");
        String c = in.next();
        int result = 0;
        if (c.equals("+")) {
            result = a+b;
        }
        if (c.equals("-")) {
            result = a-b;
        }
        if (c.equals("*")) {
            result = a*b;
        };
        if (c.equals("/")) {
            result = a/b;
        }
        System.out.println("The result is "+result);
    }
}
