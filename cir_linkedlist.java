
import java.util.*;

class CircularLinkedListQueue {
    private static class Node {
        int data;
        Node link;

        Node(int data) {
            this.data = data;
            this.link = null;
        }
    }

    private static class Queue {
        Node front, rear;

        Queue() {
            front = rear = null;
        }
    }

    // Function to create Circular queue
    static void enQueue(Queue q, int value) {
        Node temp = new Node(value);
        if (q.front == null) {
            q.front = temp;
        } else {
            q.rear.link = temp;
        }
        q.rear = temp;
        q.rear.link = q.front; // Link the last node to the front
    }

    // Function to delete element from Circular Queue
    static int deQueue(Queue q) {
        if (q.front == null) {
            System.out.println("Queue is empty");
            return -1; // Indicate that the queue is empty
        }

        int value = q.front.data;
        if (q.front == q.rear) {
            // Only one node in the queue
            q.front = q.rear = null;
        } else {
            // More than one node
            q.front = q.front.link;
            q.rear.link = q.front;
        }

        return value;
    }

    // Function displaying the elements of Circular Queue
    static void displayQueue(Queue q) {
        if (q.front == null) {
            System.out.println("Queue is empty");
            return;
        }

        Node temp = q.front;
        System.out.print("Elements in Circular Queue are: ");
        do {
            System.out.print(temp.data + " ");
            temp = temp.link;
        } while (temp != q.front);
        System.out.println();
    }

    // Driver of the program
    public static void main(String[] args) {
        Queue q = new Queue();

        // Inserting elements in Circular Queue
        enQueue(q, 14);
        enQueue(q, 22);
        enQueue(q, 6);

        // Display elements present in Circular Queue
        displayQueue(q);

        // Deleting elements from Circular Queue
        System.out.printf("Deleted value = %d%n", deQueue(q));
        System.out.printf("Deleted value = %d%n", deQueue(q));

        // Remaining elements in Circular Queue
        displayQueue(q);

        enQueue(q, 9);
        enQueue(q, 20);
        displayQueue(q);
    }
}
