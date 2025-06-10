#include <iostream>
#include <string>
#include <cassert>
#include "basic_calculator.cpp"

void test_examples() {
    // Test the examples from the problem
    assert(calculate("1 + 1") == 2);
    assert(calculate(" 2-1 + 2 ") == 3);
    assert(calculate("(1+(4+5+2)-3)+(6+8)") == 23);
    std::cout << "✓ All examples passed\n";
}

void test_edge_cases() {
    // Test edge cases
    assert(calculate("42") == 42);
    assert(calculate("-42") == -42);
    assert(calculate("1+2+3") == 6);
    assert(calculate("10-5-2") == 3);
    assert(calculate("((1+2))") == 3);
    assert(calculate("(-1+2)") == 1);
    assert(calculate("(1+2)+(3+4)") == 10);
    assert(calculate("1-1") == 0);
    std::cout << "✓ All edge cases passed\n";
}

void test_complex_cases() {
    // Test more complex cases
    assert(calculate("1-(2+(3-(4+5)))") == 5);
    assert(calculate("123+456") == 579);
    assert(calculate("  1  +  2  +  3  ") == 6);
    std::cout << "✓ All complex cases passed\n";
}

int main() {
    std::cout << "Running Basic Calculator Tests...\n";
    
    try {
        test_examples();
        test_edge_cases();
        test_complex_cases();
        
        std::cout << "\n🎉 ALL TESTS PASSED!\n";
        return 0;
    } catch (const std::exception& e) {
        std::cout << "\n❌ TEST FAILED: " << e.what() << "\n";
        return 1;
    }
} 