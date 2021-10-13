package com.company.lab;

import java.util.ArrayList;
import java.util.List;

public class lab {
    static class InterruptingThread extends Thread {
        public void run() {
            try {
                Thread.sleep(1000);
                System.out.println("Task");
            } catch (InterruptedException e) {
                System.out.println("Task interrupted");
            }
            finally {
                System.out.println("Task completed, end of function reached");
            }
        }
    }

    static class ArrayOutOfBounds {
        public void array() {
            String[] arr = {"A", "B", "C", "D" };
            try {
                for (int i = 0; i <= arr.length; i++) {
                    System.out.println(arr[i]);
                }
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Trying to access position out of array index");
            }
            finally {
                System.out.println("Array contents displayed, end of function reached");
            }
        }
    }

    static class IllegalArgument {
        public void setMarks(int marks) {
            try {
                if (marks < 0 || marks > 100)
                    throw new IllegalArgumentException();
                System.out.println(marks);
            } catch (IllegalArgumentException e) {
                System.out.println("Value not satisfied");
            }
            finally {
                System.out.println("Value displayed within range, end of function reached");
            }
        }
    }

    static class IndexOutOfBounds {
        public void string() {
            List<String> l = new ArrayList<>();
            l.add("A");
            l.add("B");
            try {
                for (int i = 0; i <= l.size(); i++) {
                    System.out.println(l.get(i));
                }
            } catch (IndexOutOfBoundsException e) {
                System.out.println("Trying to access position out of list index");
            }
            finally {
                System.out.println("String elements displayed, end of function reached");
            }
        }
    }

    static class NegativeArraySize {
        void createArray(int size) {
            try {
                int[] arr = new int[size];
                for (int i = 0; i < arr.length; i++) {
                    arr[i] = i;
                    System.out.println(arr[i]);
                }
            } catch (NegativeArraySizeException e) {
                System.out.println("Trying to create an array of negative size");
            }
            finally {
                System.out.println("Array elements displayed if size isn't negative, end of function reached");
            }
        }
    }

    static class NullPointer {
        void displayString(String str) {
            try {
                System.out.println("First character of string is " + str.charAt(0));
            } catch (NullPointerException e) {
                System.out.println("Passing null as argument");
            }
            finally {
                System.out.println("First character displayed if argument isn't null, end of function reached");
            }
        }
    }

    public static void main(String[] args) {
        InterruptingThread interruptingThread = new InterruptingThread();
        interruptingThread.start();
        interruptingThread.interrupt();
        ArrayOutOfBounds arrayOutOfBounds = new ArrayOutOfBounds();
        arrayOutOfBounds.array();
        IllegalArgument illegalArgument = new IllegalArgument();
        illegalArgument.setMarks(105);
        IndexOutOfBounds indexOutOfBounds = new IndexOutOfBounds();
        indexOutOfBounds.string();
        NegativeArraySize negativeArraySize = new NegativeArraySize();
        negativeArraySize.createArray(-1);
        NullPointer nullPointer = new NullPointer();
        nullPointer.displayString(null);
    }
}
