import unittest
from module11 import calculate_average, generate_random_numbers, filter_even_numbers

class TestModule11(unittest.TestCase):

    def test_calculate_average(self):
        # Test with normal list.
        self.assertAlmostEqual(calculate_average([10, 20, 30]), 20)
        
        # Test with empty list.
        with self.assertRaises(ZeroDivisionError):
            calculate_average([])

        # Test with single element list.
        self.assertEqual(calculate_average([10]), 10)

    def test_generate_random_numbers(self):
        numbers = generate_random_numbers(1000)
        
        # Check if 1000 numbers were generated.
        self.assertEqual(len(numbers), 1000)
        
        # Check if all numbers are in the range 1 to 100.
        for num in numbers:
            self.assertGreaterEqual(num, 1)
            self.assertLessEqual(num, 100)

    def test_filter_even_numbers(self):
        # Test if only even numbers are returned.
        numbers = [1, 2, 3, 4, 5, 6]
        expected_even_numbers = [2, 4, 6]
        
        # Run the function and check result.
        result = filter_even_numbers(numbers)
        self.assertEqual(result, expected_even_numbers)

if __name__ == "__main__":
    unittest.main()

