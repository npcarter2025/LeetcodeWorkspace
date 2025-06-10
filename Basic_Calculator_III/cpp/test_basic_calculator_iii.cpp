#include <iostream>
#include <string>
#include <cassert>
#include "basic_calculator_iii.cpp"

void test_examples() {
    std::cout << "Testing examples...\n";
    assert(calculate("1 + 1") == 2);
    assert(calculate(" 6-4 / 2 ") == 4);
    assert(calculate("2*(5+5*2)/3+(6/2+8)") == 21);
    assert(calculate("(2+6* 3+5- (3*14/7+2)*5)+3") == -12);
    std::cout << "✓ All examples passed\n";
}

void test_single_operations() {
    std::cout << "Testing single operations...\n";
    
    // Single numbers
    assert(calculate("42") == 42);
    assert(calculate(" 0 ") == 0);
    assert(calculate("(42)") == 42);
    assert(calculate("( 5 )") == 5);
    
    std::cout << "✓ All single operations passed\n";
}

void test_calculator_ii_without_parentheses() {
    std::cout << "Testing Calculator II functionality...\n";
    
    assert(calculate("3+2*2") == 7);
    assert(calculate("10-2*3") == 4);
    assert(calculate("14/7+2*3") == 8);
    assert(calculate("2*3/2") == 3);
    
    std::cout << "✓ All Calculator II tests passed\n";
}

void test_simple_parentheses() {
    std::cout << "Testing simple parentheses...\n";
    
    assert(calculate("(1+2)*3") == 9);
    assert(calculate("2*(3+4)") == 14);
    assert(calculate("(10-5)/5") == 1);
    assert(calculate("(8+2)/(2+3)") == 2);
    
    std::cout << "✓ All simple parentheses tests passed\n";
}

void test_nested_parentheses() {
    std::cout << "Testing nested parentheses...\n";
    
    assert(calculate("((1+2))") == 3);
    assert(calculate("(1+(2+3))") == 6);
    assert(calculate("((2*3)+4)") == 10);
    assert(calculate("(2*(3+4))") == 14);
    
    std::cout << "✓ All nested parentheses tests passed\n";
}

void test_precedence_with_parentheses() {
    std::cout << "Testing precedence with parentheses...\n";
    
    assert(calculate("(1+2)*3+4") == 13);    // (1+2)*3+4 = 3*3+4 = 9+4 = 13
    assert(calculate("1+(2*3)+4") == 11);    // 1+(2*3)+4 = 1+6+4 = 11
    assert(calculate("(1+2)*(3+4)") == 21);  // (1+2)*(3+4) = 3*7 = 21
    assert(calculate("2*(3+4*5)") == 46);    // 2*(3+4*5) = 2*(3+20) = 2*23 = 46
    
    std::cout << "✓ All precedence tests passed\n";
}

void test_division_truncation() {
    std::cout << "Testing division truncation...\n";
    
    assert(calculate("7/3") == 2);
    assert(calculate("(7)/3") == 2);
    assert(calculate("7/(3)") == 2);
    assert(calculate("(7)/(3)") == 2);
    assert(calculate("1/2") == 0);
    assert(calculate("(8+1)/3") == 3);  // 9/3 = 3
    
    std::cout << "✓ All division truncation tests passed\n";
}

void test_multiple_parentheses_groups() {
    std::cout << "Testing multiple parentheses groups...\n";
    
    assert(calculate("(1+2)+(3+4)") == 10);
    assert(calculate("(2*3)-(1+1)") == 4);        // 6-2 = 4
    assert(calculate("(10/2)+(8/4)") == 7);       // 5+2 = 7
    assert(calculate("(1+2)*(3+4)+(5+6)") == 32); // 3*7+11 = 21+11 = 32
    
    std::cout << "✓ All multiple parentheses tests passed\n";
}

void test_complex_nested() {
    std::cout << "Testing complex nested expressions...\n";
    
    assert(calculate("2*(1+(2*(3+4)))") == 30);  // 2*(1+(2*7)) = 2*(1+14) = 2*15 = 30
    assert(calculate("((2+3)*4)/5") == 4);       // (5*4)/5 = 20/5 = 4
    assert(calculate("(2+(3*(4+5)))") == 29);    // 2+(3*9) = 2+27 = 29
    
    std::cout << "✓ All complex nested tests passed\n";
}

void test_spaces() {
    std::cout << "Testing various spacing...\n";
    
    assert(calculate("  ( 1 + 2 ) * 3  ") == 9);
    assert(calculate(" 2 * ( 3 + 4 ) ") == 14);
    assert(calculate("( 2 + 3 ) * ( 4 + 5 )") == 45);
    assert(calculate("  2  *  (  3  +  4  *  5  )  ") == 46);
    
    std::cout << "✓ All spacing tests passed\n";
}

void test_zero_operations() {
    std::cout << "Testing operations with zero...\n";
    
    assert(calculate("(0+5)*2") == 10);
    assert(calculate("5*(0+2)") == 10);
    assert(calculate("(5-0)*2") == 10);
    assert(calculate("0*(5+2)") == 0);
    assert(calculate("(0/5)+2") == 2);
    
    // Results in zero
    assert(calculate("(1-1)*5") == 0);
    assert(calculate("5*(1-1)") == 0);
    assert(calculate("0*(1+2+3)") == 0);
    
    std::cout << "✓ All zero operations passed\n";
}

void test_precedence_edge_cases() {
    std::cout << "Testing precedence edge cases...\n";
    
    assert(calculate("2+3*4") == 14);     // no parentheses: 2+(3*4) = 2+12 = 14
    assert(calculate("(2+3)*4") == 20);   // with parentheses: (2+3)*4 = 5*4 = 20
    assert(calculate("2*3+4*5") == 26);   // (2*3)+(4*5) = 6+20 = 26
    assert(calculate("(2*3)+(4*5)") == 26); // same as above but explicit
    assert(calculate("2*(3+4)*5") == 70); // 2*7*5 = 70
    
    std::cout << "✓ All precedence edge cases passed\n";
}

void test_deeply_nested() {
    std::cout << "Testing deeply nested parentheses...\n";
    
    assert(calculate("(((1+2)))") == 3);
    assert(calculate("(1+(2+(3+4)))") == 10);  // 1+(2+7) = 1+9 = 10
    assert(calculate("((1+2)*(3+4))") == 21);
    
    std::cout << "✓ All deeply nested tests passed\n";
}

void test_mixed_operations_in_parentheses() {
    std::cout << "Testing mixed operations within parentheses...\n";
    
    assert(calculate("(1+2-3+4)") == 4);
    assert(calculate("(2*3/2*4)") == 12);      // ((2*3)/2)*4 = (6/2)*4 = 3*4 = 12
    assert(calculate("(10-2*3+4/2)") == 6);    // 10-6+2 = 6
    
    std::cout << "✓ All mixed operations tests passed\n";
}

int main() {
    std::cout << "Running Basic Calculator III Tests...\n\n";
    
    try {
        test_examples();
        test_single_operations();
        test_calculator_ii_without_parentheses();
        test_simple_parentheses();
        test_nested_parentheses();
        test_precedence_with_parentheses();
        test_division_truncation();
        test_multiple_parentheses_groups();
        test_complex_nested();
        test_spaces();
        test_zero_operations();
        test_precedence_edge_cases();
        test_deeply_nested();
        test_mixed_operations_in_parentheses();
        
        std::cout << "\n🎉 ALL TESTS PASSED!\n";
        std::cout << "Ready for your implementation!\n";
        return 0;
    } catch (const std::exception& e) {
        std::cout << "\n❌ TEST FAILED: " << e.what() << "\n";
        std::cout << "Note: Tests will fail until you implement the solution.\n";
        return 1;
    }
} 