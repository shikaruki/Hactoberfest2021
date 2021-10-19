package com.company;

public class fibonacci {
/*
f. Prompt the user for a positive integer n that is less than 75.
Then print the nth fibonacci number.
(The first two fibonacci numbers are 1 and every fibonacci number afterward is the sum of the
previous two.
1,1,2,3,5,8,13,21,34,55,...
1,2,3,4,5,6,,7, 8, 9,10
 */
        public static int fib ( int n)
        {
            if (n <= 1)
                return n;
            return fib(n - 1) + fib(n - 2);
        }
        public static void main (String args[])
        {
            int n = 10;
            System.out.println(fib(n));
        }
}
