import unittest
from basic_calculator import calculate


class TestBasicCalculator(unittest.TestCase):
    
    def test_example_1(self):
        """Test Example 1: Simple addition"""
        self.assertEqual(calculate("1 + 1"), 2)
    
    def test_example_2(self):
        """Test Example 2: Addition and subtraction with spaces"""
        self.assertEqual(calculate(" 2-1 + 2 "), 3)
    
    def test_example_3(self):
        """Test Example 3: Complex expression with parentheses"""
        self.assertEqual(calculate("(1+(4+5+2)-3)+(6+8)"), 23)
    
    def test_single_number(self):
        """Test single positive number"""
        self.assertEqual(calculate("42"), 42)
    
    def test_single_negative_number(self):
        """Test single negative number"""
        self.assertEqual(calculate("-42"), -42)
    
    def test_simple_addition(self):
        """Test simple addition without spaces"""
        self.assertEqual(calculate("1+2+3"), 6)
    
    def test_simple_subtraction(self):
        """Test simple subtraction"""
        self.assertEqual(calculate("10-5-2"), 3)
    
    def test_mixed_operations(self):
        """Test mixed addition and subtraction"""
        self.assertEqual(calculate("1-2+3-4+5"), 3)
    
    def test_nested_parentheses(self):
        """Test nested parentheses"""
        self.assertEqual(calculate("((1+2))"), 3)
        self.assertEqual(calculate("(1+(2+3))"), 6)
    
    def test_negative_in_parentheses(self):
        """Test negative numbers in parentheses"""
        self.assertEqual(calculate("(-1+2)"), 1)
        self.assertEqual(calculate("(1+(-2))"), -1)
    
    def test_multiple_parentheses_groups(self):
        """Test multiple groups of parentheses"""
        self.assertEqual(calculate("(1+2)+(3+4)"), 10)
        self.assertEqual(calculate("(1-2)+(3-4)"), -2)
    
    def test_zero_result(self):
        """Test expressions that result in zero"""
        self.assertEqual(calculate("1-1"), 0)
        self.assertEqual(calculate("(1+2)-(2+1)"), 0)
    
    def test_large_numbers(self):
        """Test with larger numbers"""
        self.assertEqual(calculate("123+456"), 579)
        self.assertEqual(calculate("1000-500"), 500)
    
    def test_spaces_everywhere(self):
        """Test with many spaces"""
        self.assertEqual(calculate("  1  +  2  +  3  "), 6)
        self.assertEqual(calculate(" ( 1 + 2 ) "), 3)
    
    def test_complex_nested_expression(self):
        """Test complex nested expression"""
        self.assertEqual(calculate("1-(2+(3-(4+5)))"), 5)
    
    def test_unary_minus_at_start(self):
        """Test unary minus at the beginning"""
        self.assertEqual(calculate("-1"), -1)
        self.assertEqual(calculate("-1+2"), 1)
    
    def test_unary_minus_after_parentheses(self):
        """Test unary minus after opening parentheses"""
        self.assertEqual(calculate("(-1)"), -1)
        self.assertEqual(calculate("(-(1+2))"), -3)


if __name__ == '__main__':
    unittest.main() 