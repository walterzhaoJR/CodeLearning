//https://leetcode-cn.com/problems/reverse-integer/
#include<iostream>
#include<gtest/gtest.h>
#include<limits.h>

using namespace std;

int reverse(int x) {
    
    bool is_negative = false;//负数
    if(x < 0){
        if(x <= INT_MIN){
            return 0;
        }

        is_negative = true;
        x = -x;
    }
    
    int res = 0;

    while(x){
        if(res > INT_MAX/10){//处理溢出的场景
            return 0;
        }

        res *= 10;
        res += (x % 10);
        x /= 10;
    }

    if(true == is_negative){
        res = -res;
    }

    return res;
}

TEST(testCase,test0){
    EXPECT_EQ(reverse(123),321);
}

TEST(testCase,test1){
    EXPECT_EQ(reverse(-123),-321);
}

TEST(testCase,test2){
    EXPECT_EQ(reverse(120),21);
}

TEST(testCase,test3){
    EXPECT_EQ(reverse(0),0);
}

TEST(testCase,test4){
    EXPECT_EQ(reverse(10100),101);
}

TEST(testCase,test5){
    EXPECT_EQ(reverse(1534236469),0);
}

TEST(testCase,test6){
    EXPECT_EQ(reverse(-2147483648),0);
}

int main(int argc,char** argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
    return 0;
}
