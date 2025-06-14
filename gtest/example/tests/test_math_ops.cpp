#include <gtest/gtest.h>
#include "../include/math_ops.h"

// Test fixture (optional, can be used for setup/teardown)
class MathOpsTest : public ::testing::Test {
protected:
    void SetUp() override 
    {
        std::cout << "Setting up for test\n";
    }

    void TearDown() override 
    {
        std::cout << "Cleaning up after test\n";
    }
};  // Use TEST_F instead of TEST to use the fixture

// Basic test case
TEST(MathOpsTest, AddTwoNumbers) {
    EXPECT_EQ(add(2, 3) , 5);
    EXPECT_EQ(add(-1, 1), 0);
    EXPECT_EQ(add(0, 0) , 0);
}

// Another test case
TEST(MathOpsTest, AddLargeNumbers) {
    EXPECT_EQ(add(1000, 2000), 3000);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}