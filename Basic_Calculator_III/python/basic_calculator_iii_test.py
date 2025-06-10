import unittest
from basic_calculator_iii import calculate


class TestBasicCalculatorIII(unittest.TestCase):
    
    def test_example_1(self):
        """Test Example 1: Simple addition"""
        self.assertEqual(calculate("1 + 1"), 2)
    
    def test_example_2(self):
        """Test Example 2: Division with subtraction"""
        self.assertEqual(calculate(" 6-4 / 2 "), 4)
    
    def test_example_3(self):
        """Test Example 3: Complex expression with parentheses and precedence"""
        self.assertEqual(calculate("2*(5+5*2)/3+(6/2+8)"), 21)
    
    def test_example_4(self):
        """Test Example 4: Very complex nested expression"""
        self.assertEqual(calculate("(2+6* 3+5- (3*14/7+2)*5)+3"), -12)
    
    def test_single_number(self):
        """Test single number"""
        self.assertEqual(calculate("42"), 42)
        self.assertEqual(calculate(" 0 "), 0)
        self.assertEqual(calculate("123"), 123)
    
    def test_single_parentheses(self):
        """Test single number in parentheses"""
        self.assertEqual(calculate("(42)"), 42)
        self.assertEqual(calculate("( 5 )"), 5)
    
    def test_simple_operations_without_parentheses(self):
        """Test basic operations from Calculator II"""
        self.assertEqual(calculate("3+2*2"), 7)  # precedence test
        self.assertEqual(calculate("10-2*3"), 4)
        self.assertEqual(calculate("14/7+2*3"), 8)
        self.assertEqual(calculate("2*3/2"), 3)
    
    def test_simple_parentheses_operations(self):
        """Test basic parentheses from Calculator I"""
        self.assertEqual(calculate("(1+2)*3"), 9)
        self.assertEqual(calculate("2*(3+4)"), 14)
        self.assertEqual(calculate("(10-5)/5"), 1)
        self.assertEqual(calculate("(8+2)/(2+3)"), 2)
    
    def test_nested_parentheses(self):
        """Test nested parentheses"""
        self.assertEqual(calculate("((1+2))"), 3)
        self.assertEqual(calculate("(1+(2+3))"), 6)
        self.assertEqual(calculate("((2*3)+4)"), 10)
        self.assertEqual(calculate("(2*(3+4))"), 14)
    
    def test_precedence_with_parentheses(self):
        """Test operator precedence combined with parentheses"""
        self.assertEqual(calculate("(1+2)*3+4"), 13)  # (1+2)*3+4 = 3*3+4 = 9+4 = 13
        self.assertEqual(calculate("1+(2*3)+4"), 11)  # 1+(2*3)+4 = 1+6+4 = 11
        self.assertEqual(calculate("(1+2)*(3+4)"), 21)  # (1+2)*(3+4) = 3*7 = 21
        self.assertEqual(calculate("2*(3+4*5)"), 46)  # 2*(3+4*5) = 2*(3+20) = 2*23 = 46
    
    def test_division_truncation(self):
        """Test division truncation toward zero"""
        self.assertEqual(calculate("7/3"), 2)
        self.assertEqual(calculate("(7)/3"), 2)
        self.assertEqual(calculate("7/(3)"), 2)
        self.assertEqual(calculate("(7)/(3)"), 2)
        self.assertEqual(calculate("1/2"), 0)
        self.assertEqual(calculate("(8+1)/3"), 3)  # 9/3 = 3
        self.assertEqual(calculate("3/(2/1-4)"), -1)  # 3/(-2) = -1.5 -> -1 (truncate toward zero)
    
    def test_multiple_parentheses_groups(self):
        """Test multiple separate parentheses groups"""
        self.assertEqual(calculate("(1+2)+(3+4)"), 10)
        self.assertEqual(calculate("(2*3)-(1+1)"), 4)  # 6-2 = 4
        self.assertEqual(calculate("(10/2)+(8/4)"), 7)  # 5+2 = 7
        self.assertEqual(calculate("(1+2)*(3+4)+(5+6)"), 32)  # 3*7+11 = 21+11 = 32
    
    def test_complex_nested_expressions(self):
        """Test complex nested expressions"""
        self.assertEqual(calculate("2*(1+(2*(3+4)))"), 30)  # 2*(1+(2*7)) = 2*(1+14) = 2*15 = 30
        self.assertEqual(calculate("((2+3)*4)/5"), 4)  # (5*4)/5 = 20/5 = 4
        self.assertEqual(calculate("(2+(3*(4+5)))"), 29)  # 2+(3*9) = 2+27 = 29
    
    def test_spaces_everywhere(self):
        """Test with various spacing patterns"""
        self.assertEqual(calculate("  ( 1 + 2 ) * 3  "), 9)
        self.assertEqual(calculate(" 2 * ( 3 + 4 ) "), 14)
        self.assertEqual(calculate("( 2 + 3 ) * ( 4 + 5 )"), 45)
        self.assertEqual(calculate("  2  *  (  3  +  4  *  5  )  "), 46)
    
    def test_large_numbers(self):
        """Test with larger numbers"""
        self.assertEqual(calculate("(100+200)*3"), 900)
        self.assertEqual(calculate("1000/(10*2)"), 50)
        self.assertEqual(calculate("(123+456)*2"), 1158)
    
    def test_zero_operations(self):
        """Test operations involving zero"""
        self.assertEqual(calculate("(0+5)*2"), 10)
        self.assertEqual(calculate("5*(0+2)"), 10)
        self.assertEqual(calculate("(5-0)*2"), 10)
        self.assertEqual(calculate("0*(5+2)"), 0)
        self.assertEqual(calculate("(0/5)+2"), 2)
    
    def test_result_zero(self):
        """Test expressions that result in zero"""
        self.assertEqual(calculate("(1-1)*5"), 0)
        self.assertEqual(calculate("5*(1-1)"), 0)
        self.assertEqual(calculate("(2-2)/(1+1)"), 0)
        self.assertEqual(calculate("0*(1+2+3)"), 0)
    
    def test_precedence_edge_cases(self):
        """Test tricky precedence cases with parentheses"""
        self.assertEqual(calculate("2+3*4"), 14)  # no parentheses: 2+(3*4) = 2+12 = 14
        self.assertEqual(calculate("(2+3)*4"), 20)  # with parentheses: (2+3)*4 = 5*4 = 20
        self.assertEqual(calculate("2*3+4*5"), 26)  # (2*3)+(4*5) = 6+20 = 26
        self.assertEqual(calculate("(2*3)+(4*5)"), 26)  # same as above but explicit
        self.assertEqual(calculate("2*(3+4)*5"), 70)  # 2*7*5 = 70
    
    def test_complex_real_world_expressions(self):
        """Test complex expressions that might appear in real calculations"""
        self.assertEqual(calculate("(1+2+3)*(4+5)"), 54)  # 6*9 = 54
        self.assertEqual(calculate("((1+2)*3+(4+5)*6)/7"), 9)  # (3*3 + 9*6)/7 = (9+54)/7 = 63/7 = 9
        self.assertEqual(calculate("(10-5)*(20/4)+(3*2)"), 31)  # 5*5+6 = 25+6 = 31
        
    def test_deeply_nested(self):
        """Test deeply nested parentheses"""
        self.assertEqual(calculate("(((1+2)))"), 3)
        self.assertEqual(calculate("(1+(2+(3+4)))"), 10)  # 1+(2+7) = 1+9 = 10
        self.assertEqual(calculate("((1+2)*(3+4))"), 21)
    
    def test_mixed_operations_in_parentheses(self):
        """Test all four operations within parentheses"""
        self.assertEqual(calculate("(1+2-3+4)"), 4)
        self.assertEqual(calculate("(2*3/2*4)"), 12)  # ((2*3)/2)*4 = (6/2)*4 = 3*4 = 12
        self.assertEqual(calculate("(10-2*3+4/2)"), 6)  # 10-6+2 = 6
    
    def test_calculator_ii_cases_with_parentheses(self):
        """Test Calculator II type expressions but with parentheses added"""
        self.assertEqual(calculate("(3+2*2)"), 7)  # same as 3+2*2
        self.assertEqual(calculate("(14/7+2*3)"), 8)  # same as 14/7+2*3
        self.assertEqual(calculate("((2*3)/2)"), 3)  # same as 2*3/2


if __name__ == '__main__':
    unittest.main() 