Overview
The Arbitrary Precision Calculator is a C-based project that performs mathematical operations on extremely large numbers that exceed the limits of standard data types like int, long, or double. This is achieved by manually representing each digit of the number using data structures such as linked lists or arrays, and implementing arithmetic logic using DSA techniques.

Features
Supports very large numbers (hundreds or thousands of digits)

Addition, subtraction, multiplication (and optionally division)

Negative number handling

Input/output as strings for easy user interaction

Digit-by-digit computation using custom logic (no built-in math functions for big numbers)

How It Works
Number Representation
Each number is read as a string and stored:

As a linked list or array, where each node or element represents a single digit.

In reverse order for easier computation (optional, based on implementation).

Arithmetic Operations
Addition: Performed digit by digit from least to most significant, storing the carry manually.

Subtraction: Digit-by-digit with borrow handling, works for both positive and negative values.

Multiplication: Simulated manually using elementary school method—each digit multiplied and aligned.

Division (optional): Performed by repeated subtraction or long division logic.

Data Structures Used
Singly Linked List or Dynamic Arrays: For storing digits

Stacks: For managing carry/borrow if needed

Custom structs: To hold numbers and operation results
