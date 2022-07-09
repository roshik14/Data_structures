#include <gtest/gtest.h>
#include <array>
#include "array.h"
TEST(array_test_suit, simple_test) {
    std::array<int, 3> orig_array {234, 21, 11};
    s21::array<int, 3>copy_array {234, 21, 11};
    for (int i {}; i < 3; i++)
        ASSERT_EQ(orig_array.at(i), copy_array.at(i));
    ASSERT_EQ(orig_array.size(), copy_array.size());
    ASSERT_EQ(orig_array.max_size(), copy_array.max_size());
    std::array<char, 0> orig_ar1;
    s21::array<char, 0> copy_ar1;
    ASSERT_EQ(orig_ar1.empty(), copy_ar1.empty());
}

TEST(array_test_suit, swap_test) {
    std::array<double, 5> orig_array1 {2.5, 3.4, 255.3, 1.2, 0.5};
    std::array<double, 5> orig_array2 {-5.3, 1.18, -4.3, 255.34, 1.23};
    s21::array<double, 5> copy_array1 {2.5, 3.4, 255.3, 1.2, 0.5};
    s21::array<double, 5> copy_array2 {-5.3, 1.18, -4.3, 255.34, 1.23};
    orig_array1.swap(orig_array2);
    copy_array1.swap(copy_array2);
    for (int i {}; i < 5; i++) {
        ASSERT_DOUBLE_EQ(orig_array1[i], copy_array1[i]);
        ASSERT_DOUBLE_EQ(orig_array2[i], copy_array2[i]);
    }
    ASSERT_EQ(orig_array1.size(), copy_array1.size());
    ASSERT_EQ(orig_array2.max_size(), copy_array2.max_size());
    ASSERT_EQ(orig_array1.front(), copy_array1.front());
    ASSERT_EQ(orig_array2.front(), copy_array2.front());
    ASSERT_EQ(orig_array1.back(), copy_array1.back());
    ASSERT_EQ(orig_array2.back(), copy_array2.back());
}

TEST(array_test_suit, copy_constructor_test) {
    std::array<int, 3> orig_array1 {234, 21, 11};
    s21::array<int, 3>copy_array1 {234, 21, 11};
    std::array<int, 3>orig_array2(orig_array1);
    s21::array<int, 3>copy_array2(copy_array1);
    for (int i {}; i < 3; i++) {
        ASSERT_EQ(orig_array1.at(i), copy_array1.at(i));
        ASSERT_EQ(orig_array2.at(i), copy_array2.at(i));
    }
    ASSERT_EQ(orig_array1.size(), copy_array1.size());
    ASSERT_EQ(orig_array1.max_size(), copy_array1.max_size());
    ASSERT_EQ(orig_array2.size(), copy_array2.size());
    ASSERT_EQ(orig_array2.max_size(), copy_array2.max_size());
    std::array<char, 0> orig_ar1;
    s21::array<char, 0> copy_ar1;
    std::array<char, 0> orig_ar2(orig_ar1);
    s21::array<char, 0> copy_ar2(copy_ar1);
    ASSERT_EQ(orig_ar1.empty(), copy_ar1.empty());
    ASSERT_EQ(orig_ar2.empty(), copy_ar2.empty());
}

TEST(array_test_suit, move_constructor_test) {
    std::array<int, 5> orig_array1 {234, 21, 11, 34, 999};
    s21::array<int, 5>copy_array1 {234, 21, 11, 34, 999};
    std::array<int, 5>orig_array2(std::move(orig_array1));
    s21::array<int, 5>copy_array2(std::move(copy_array1));
    for (size_t i {}; i < copy_array2.size(); i++) {
        ASSERT_EQ(orig_array2.at(i), copy_array2.at(i));
    }
    ASSERT_EQ(orig_array1.size(), copy_array1.size());
    ASSERT_EQ(orig_array1.max_size(), copy_array1.max_size());
    ASSERT_EQ(orig_array2.size(), copy_array2.size());
    ASSERT_EQ(orig_array2.max_size(), copy_array2.max_size());
    std::array<char, 0> orig_ar1;
    s21::array<char, 0> copy_ar1;
    ASSERT_EQ(orig_ar1.empty(), copy_ar1.empty());
}

TEST(array_test_suit, move_operator_test) {
    std::array<int, 5> orig_array1 {234, 21, 11, 34, 999};
    s21::array<int, 5>copy_array1 {234, 21, 11, 34, 999};
    std::array<int, 5>orig_array2 {25};
    s21::array<int, 5>copy_array2 {25};
    orig_array2 = std::move(orig_array1);
    copy_array2 = std::move(copy_array1);
    for (size_t i {}; i < copy_array2.size(); i++) {
        ASSERT_EQ(orig_array2.at(i), copy_array2.at(i));
    }
    ASSERT_EQ(orig_array1.size(), copy_array1.size());
    ASSERT_EQ(orig_array1.max_size(), copy_array1.max_size());
    ASSERT_EQ(orig_array2.size(), copy_array2.size());
    ASSERT_EQ(orig_array2.max_size(), copy_array2.max_size());
    std::array<char, 0> orig_ar1;
    s21::array<char, 0> copy_ar1;
    ASSERT_EQ(orig_ar1.empty(), copy_ar1.empty());
}

TEST(array_test_suit, iterator_test) {
    std::array<int, 5> orig_array1 {234, 21, 11, 34, 999};
    s21::array<int, 5>copy_array1 {234, 21, 11, 34, 999};
    int *orig_beg = orig_array1.begin();
    int *copy_beg = copy_array1.begin();
    int *orig_end = orig_array1.end();
    int *copy_end = copy_array1.end();
    while (orig_beg < orig_end && copy_beg < copy_end) {
        ASSERT_EQ(*orig_beg++, *copy_beg++);
    }
    ASSERT_EQ(orig_array1.size(), copy_array1.size());
    ASSERT_EQ(orig_array1.max_size(), copy_array1.max_size());
    s21::array<char, 0> copy_ar1;
    ASSERT_TRUE(copy_ar1.begin() == copy_ar1.end());
    s21::array<double, 3> my_arr {2.3, 4.5555, 6.1234};
    double *d = my_arr.data();
    ASSERT_DOUBLE_EQ(my_arr[0], *d);
}

TEST(array_test_suit, fill_test) {
    std::array<size_t, 10> orig_array;
    s21::array<size_t, 10>my_arr;
    orig_array.fill(555);
    my_arr.fill(555);
    for (size_t i = 0; i < orig_array.size(); i++)
        ASSERT_EQ(orig_array[i], my_arr[i]);
    ASSERT_EQ(orig_array.size(), my_arr.size());;
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
