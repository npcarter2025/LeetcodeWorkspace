import unittest
from basic_calculator_ii import calculate


class TestBasicCalculatorII(unittest.TestCase):
    
    def test_example_1(self):
        """Test Example 1: Multiplication precedence"""
        self.assertEqual(calculate("3+2*2"), 7)
    
    def test_example_2(self):
        """Test Example 2: Division with spaces"""
        self.assertEqual(calculate(" 3/2 "), 1)
    
    def test_example_3(self):
        """Test Example 3: Mixed operations with spaces"""
        self.assertEqual(calculate(" 3+5 / 2 "), 5)
    
    def test_single_number(self):
        """Test single number"""
        self.assertEqual(calculate("42"), 42)
        self.assertEqual(calculate(" 0 "), 0)
    
    def test_simple_addition(self):
        """Test simple addition"""
        self.assertEqual(calculate("1+2"), 3)
        self.assertEqual(calculate("1+2+3"), 6)
    
    def test_simple_subtraction(self):
        """Test simple subtraction"""
        self.assertEqual(calculate("5-2"), 3)
        self.assertEqual(calculate("10-3-2"), 5)
    
    def test_simple_multiplication(self):
        """Test simple multiplication"""
        self.assertEqual(calculate("2*3"), 6)
        self.assertEqual(calculate("2*3*4"), 24)
    
    def test_simple_division(self):
        """Test simple division"""
        self.assertEqual(calculate("6/2"), 3)
        self.assertEqual(calculate("7/3"), 2)  # truncate toward zero
        self.assertEqual(calculate("8/2/2"), 2)
    
    def test_division_truncation(self):
        """Test division truncation toward zero"""
        self.assertEqual(calculate("7/3"), 2)
        self.assertEqual(calculate("1/2"), 0)
        self.assertEqual(calculate("11/3"), 3)
    
    def test_multiplication_precedence(self):
        """Test multiplication precedence over addition/subtraction"""
        self.assertEqual(calculate("1+2*3"), 7)  # 1 + (2*3) = 1 + 6 = 7
        self.assertEqual(calculate("2*3+1"), 7)  # (2*3) + 1 = 6 + 1 = 7
        self.assertEqual(calculate("1+2*3+4"), 11)  # 1 + (2*3) + 4 = 1 + 6 + 4 = 11
    
    def test_division_precedence(self):
        """Test division precedence over addition/subtraction"""
        self.assertEqual(calculate("6/2+1"), 4)  # (6/2) + 1 = 3 + 1 = 4
        self.assertEqual(calculate("1+6/2"), 4)  # 1 + (6/2) = 1 + 3 = 4
        self.assertEqual(calculate("8/2-1"), 3)  # (8/2) - 1 = 4 - 1 = 3
    
    def test_mixed_precedence(self):
        """Test mixed operations with precedence"""
        self.assertEqual(calculate("2+3*4-1"), 13)  # 2 + (3*4) - 1 = 2 + 12 - 1 = 13
        self.assertEqual(calculate("10-2*3"), 4)  # 10 - (2*3) = 10 - 6 = 4
        self.assertEqual(calculate("14/2-3"), 4)  # (14/2) - 3 = 7 - 3 = 4
    
    def test_consecutive_high_precedence(self):
        """Test consecutive multiplication/division"""
        self.assertEqual(calculate("2*3/2"), 3)  # (2*3)/2 = 6/2 = 3
        self.assertEqual(calculate("12/3*2"), 8)  # (12/3)*2 = 4*2 = 8
        self.assertEqual(calculate("2*3*4/6"), 4)  # ((2*3)*4)/6 = (6*4)/6 = 24/6 = 4
    
    def test_spaces_everywhere(self):
        """Test with various spacing"""
        self.assertEqual(calculate("  2  +  3  *  4  "), 14)
        self.assertEqual(calculate(" 10 / 2 - 1 "), 4)
        self.assertEqual(calculate("1+ 2*3 +4"), 11)
    
    def test_large_numbers(self):
        """Test with larger numbers"""
        self.assertEqual(calculate("100+200"), 300)
        self.assertEqual(calculate("1000/10"), 100)
        self.assertEqual(calculate("123*2"), 246)
    
    def test_zero_operations(self):
        """Test operations involving zero"""
        self.assertEqual(calculate("0+5"), 5)
        self.assertEqual(calculate("5-0"), 5)
        self.assertEqual(calculate("0*5"), 0)
        self.assertEqual(calculate("5*0"), 0)
        self.assertEqual(calculate("0/5"), 0)
    
    def test_result_zero(self):
        """Test expressions that result in zero"""
        self.assertEqual(calculate("1-1"), 0)
        self.assertEqual(calculate("5*0"), 0)
        self.assertEqual(calculate("0/1"), 0)
        self.assertEqual(calculate("2-2*1"), 0)
    
    def test_complex_expressions(self):
        """Test more complex expressions"""
        self.assertEqual(calculate("1+2*3+4*5-6/2"), 24)  # 1 + 6 + 20 - 3 = 24
        self.assertEqual(calculate("100-90+10*2/5"), 14)  # 100 - 90 + (20/5) = 100 - 90 + 4 = 14
    
    def test_edge_case_single_digit(self):
        """Test edge cases with single digits"""
        self.assertEqual(calculate("9"), 9)
        self.assertEqual(calculate("1*9"), 9)
        self.assertEqual(calculate("9/1"), 9)


if __name__ == '__main__':
    unittest.main() 