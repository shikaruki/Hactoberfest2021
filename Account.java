package com.company;

import java.util.Scanner;

public class Account {
    //variables
    private int id;
    private double balance;
    private static double annualInterestRate;
    private java.util.Date dateCreated;

    //constructor
    public Account(int id) {
            this.id = id;
            balance = 100;
            dateCreated = new java.util.Date();
        }

    //getter
    public double getBalance() {
        return balance;
    }

    public int getID() {
        return id;
    }

    public java.util.Date getDate() {
        return dateCreated;
    }

    public static double getMonthlyInterestRate() {
        return ((annualInterestRate / 12) / 100);
    }

    public double getMonthlyInterest() {
        return (balance * getMonthlyInterestRate());
    }

    //setter
    public void setAnnualInterest(double interest) {
        annualInterestRate = interest;
    }

    public void setBalance(double newBalance) {
        balance = newBalance;
    }

    public void setID(int newID) {
        id = newID;
    }

    //instance
    public double withdraw(double withdrawAmount) {
        return balance = balance - withdrawAmount;
    }

    public double deposit(double depositAmount) {
        return balance = balance + depositAmount;
    }

    public static void main(String[] args) {
        Account[] accounts = new Account[10];
        for (int i = 0; i < accounts.length; i++) {
            accounts[i] = new Account(i);
        }

        Scanner input = new Scanner(System.in);

        System.out.print("Enter an ID: ");
        int enteredID = input.nextInt();
        boolean shouldExit = false;

        while (true) {

            if (enteredID >9) {
                System.out.print("Enter correct id: ");
                enteredID = input.nextInt();
            }

            if (enteredID == accounts[enteredID].getID()) {
                System.out.println("Main Menu: ");
                System.out.println("1: Balance");
                System.out.println("2: Withdraw");
                System.out.println("3: Deposit");
                System.out.println("4: Exit");

                System.out.print("Enter a choice: ");
                int choice = input.nextInt();

                if (choice == 1) {
                    System.out.println("The balance is: " + accounts[enteredID].getBalance());
                    continue;
                }

                else if (choice == 2) {
                    System.out.print("Enter withdraw amount: ");
                    int withdrawAmount = input.nextInt();
                    accounts[enteredID].withdraw(withdrawAmount);
                    continue;
                }

                else if (choice == 3) {
                    System.out.print("Enter deposit amount: ");
                    int depositAmount = input.nextInt();
                    accounts[enteredID].deposit(depositAmount);
                    continue;
                }

                shouldExit = false;
                while (!shouldExit) {
                    if (choice == 4) {
                        System.out.print("Enter an ID: ");
                        enteredID = input.nextInt();
                        shouldExit = true;
                    }
                }
            }
        }
    }
}
