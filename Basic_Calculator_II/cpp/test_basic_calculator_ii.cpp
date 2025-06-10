#include <iostream>
#include <string>
#include <cassert>
#include "basic_calculator_ii.cpp"

void test_examples() {
    // Test the examples from the problem
    std::cout << "Testing examples...\n";
    assert(calculate("3+2*2") == 7);
    assert(calculate(" 3/2 ") == 1);
    assert(calculate(" 3+5 / 2 ") == 5);
    std::cout << "✓ All examples passed\n";
}

void test_single_operations() {
    std::cout << "Testing single operations...\n";
    
    // Single numbers
    assert(calculate("42") == 42);
    assert(calculate(" 0 ") == 0);
    
    // Simple addition
    assert(calculate("1+2") == 3);
    assert(calculate("1+2+3") == 6);
    
    // Simple subtraction
    assert(calculate("5-2") == 3);
    assert(calculate("10-3-2") == 5);
    
    // Simple multiplication
    assert(calculate("2*3") == 6);
    assert(calculate("2*3*4") == 24);
    
    // Simple division
    assert(calculate("6/2") == 3);
    assert(calculate("7/3") == 2);  // truncate toward zero
    assert(calculate("8/2/2") == 2);
    
    std::cout << "✓ All single operations passed\n";
}

void test_precedence() {
    std::cout << "Testing operator precedence...\n";
    
    // Multiplication precedence
    assert(calculate("1+2*3") == 7);    // 1 + (2*3) = 7
    assert(calculate("2*3+1") == 7);    // (2*3) + 1 = 7
    assert(calculate("1+2*3+4") == 11); // 1 + (2*3) + 4 = 11
    
    // Division precedence
    assert(calculate("6/2+1") == 4);    // (6/2) + 1 = 4
    assert(calculate("1+6/2") == 4);    // 1 + (6/2) = 4
    assert(calculate("8/2-1") == 3);    // (8/2) - 1 = 3
    
    // Mixed precedence
    assert(calculate("2+3*4-1") == 13); // 2 + (3*4) - 1 = 13
    assert(calculate("10-2*3") == 4);   // 10 - (2*3) = 4
    assert(calculate("14/2-3") == 4);   // (14/2) - 3 = 4
    
    std::cout << "✓ All precedence tests passed\n";
}

void test_consecutive_operations() {
    std::cout << "Testing consecutive high-precedence operations...\n";
    
    assert(calculate("2*3/2") == 3);    // (2*3)/2 = 6/2 = 3
    assert(calculate("12/3*2") == 8);   // (12/3)*2 = 4*2 = 8
    assert(calculate("2*3*4/6") == 4);  // ((2*3)*4)/6 = 24/6 = 4
    
    std::cout << "✓ All consecutive operations passed\n";
}

void test_division_truncation() {
    std::cout << "Testing division truncation...\n";
    
    assert(calculate("7/3") == 2);
    assert(calculate("1/2") == 0);
    assert(calculate("11/3") == 3);
    
    std::cout << "✓ All division truncation tests passed\n";
}

void test_spaces() {
    std::cout << "Testing various spacing...\n";
    
    assert(calculate("  2  +  3  *  4  ") == 14);
    assert(calculate(" 10 / 2 - 1 ") == 4);
    assert(calculate("1+ 2*3 +4") == 11);
    
    std::cout << "✓ All spacing tests passed\n";
}

void test_zero_operations() {
    std::cout << "Testing operations with zero...\n";
    
    assert(calculate("0+5") == 5);
    assert(calculate("5-0") == 5);
    assert(calculate("0*5") == 0);
    assert(calculate("5*0") == 0);
    assert(calculate("0/5") == 0);
    
    // Results in zero
    assert(calculate("1-1") == 0);
    assert(calculate("5*0") == 0);
    assert(calculate("2-2*1") == 0);
    
    std::cout << "✓ All zero operations passed\n";
}

void test_complex_expressions() {
    std::cout << "Testing complex expressions...\n";
    
    assert(calculate("1+2*3+4*5-6/2") == 24);   // 1 + 6 + 20 - 3 = 24
    assert(calculate("100-90+10*2/5") == 14);   // 100 - 90 + 4 = 14
    
    std::cout << "✓ All complex expressions passed\n";
}

int main() {
    std::cout << "Running Basic Calculator II Tests...\n\n";
    
    try {
        test_examples();
        test_single_operations();
        test_precedence();
        test_consecutive_operations();
        test_division_truncation();
        test_spaces();
        test_zero_operations();
        test_complex_expressions();
        
        std::cout << "\n🎉 ALL TESTS PASSED!\n";
        std::cout << "Ready for your implementation!\n";
        return 0;
    } catch (const std::exception& e) {
        std::cout << "\n❌ TEST FAILED: " << e.what() << "\n";
        std::cout << "Note: Tests will fail until you implement the solution.\n";
        return 1;
    }
} 