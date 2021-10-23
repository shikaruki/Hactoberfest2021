import java.lang.*;
import java.util.Scanner;
public class BasicCalculator {

    public static void main(String[] args)
    {
        double num1, num2;

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the numbers");

        num1 = sc.nextDouble();
        num2 = sc.nextDouble();

        System.out.println("Enter the operator (+,-,*,/)");

        char operator = sc.next().charAt(0);

        double output = 0;

        switch (operator) {

            case '+':
                output = num1 + num2;
                break;

            case '-':
                output = num1 - num2;
                break;

            case '*':
                output = num1 * num2;
                break;

            case '/':
                output = num1 / num2;
                break;

            default:
                System.out.println("You enter wrong input");
                break;
        }
        System.out.println("The final result:"+"\n"+num1 + " " + operator + " " + num2 + " = " + output);
    }
}
