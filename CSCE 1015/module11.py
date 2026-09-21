import random

def calculate_average(numbers):
    # Calculate average, hopefully.
    total_sum = sum(numbers)
    count = len(numbers)
    average = total_sum / count
    return average

def generate_random_numbers(n):
    # Should generate `n` random numbers between 1 and 100.
    numbers = []
    for i in range(n):
        number = random.randint(1, 100)
        numbers.append(number)
    return numbers

def filter_even_numbers(numbers):
    # Filter only even numbers.
    even_numbers = []
    for num in numbers:
        if num % 2 == 0: 
            even_numbers.append(num)
    return even_numbers

def main():
    # Generate 10 random numbers and calculate the average.
    numbers = generate_random_numbers(10)
    print("Generated numbers:", numbers)

    # Calculate average of numbers.
    average = calculate_average(numbers)
    print("Average of numbers:", average)

    # Filter even numbers from the list.
    even_numbers = filter_even_numbers(numbers)
    print("Even numbers:", even_numbers)

if __name__ == "__main__":
    main()

