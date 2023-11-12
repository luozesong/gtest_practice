#include <gtest/gtest.h>

#include "unit_test.h"
#include "mock_unit_test.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// 普通函数测试
TEST(has_test_str, test1) {
    std::string tmp_str = "abscksdfdtest";
    EXPECT_TRUE(has_test_str(tmp_str));
}

// 类公有成员函数
TEST(LzsUnitTest, test_has_funcname) {
   LzsUnitTest one_test;
   one_test.add_func("add_func");
   EXPECT_TRUE(one_test.has_funcname("add_func"));
}

// 类私有成员
TEST(LzsUnitTest, test_add_func_num) {
    LzsUnitTest one_test;
    one_test.add_func_num();
    ASSERT_EQ(one_test.m_to_test_func_num, 1);
}

// mock
//TEST(LzsUnitTest, test_get_cfg) {
//    MockConfigUint* mock_configunit = new MockConfigUint();

//    LzsUnitTest one_test;
//    ConfigUnit* tmp_cfg;
    //EXPECT_CALL(mock_configunit, get_cfg_num(testing::Eq(3)), testing::_)
    //    .WillRepeatedly(testing::DoAll(testing::setArgReferee<5>(5)),
    //                    testing::Return(3));
    //EXPECT_CALL(mock_configunit, get_cfg_num()).WillRepeatedly(testing::DoAll(testing::Return(3)));
    //one_test.get_cfg(3, &tmp_cfg);
    //EXPECT_EQ(one_test.m_to_test_func_num, 3);
//}

