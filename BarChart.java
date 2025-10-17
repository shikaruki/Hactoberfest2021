import java.util.Scanner;
import java.util.Arrays;

public class BarChart {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int n = sc.nextInt();
            int[] heights = new int[n];
            for (int i = 0; i < n; i++) heights[i] = sc.nextInt();

            int max = Arrays.stream(heights).max().orElse(0);
            for (int level = max; level >= 1; level--) {
                for (int h : heights)
                    System.out.print(h >= level ? "* " : "  ");
                System.out.println();
            }
        }
    }
}
