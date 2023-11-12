#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <set>

#include <gtest/gtest.h>

bool has_test_str(const std::string& my_string);

class ConfigUnit {
public:
    ConfigUnit();
    ~ConfigUnit();

    bool read_config_file();
    int get_cfg_num();

private:
    int _cfg_num;
};

class LzsUnitTest {
public:
    LzsUnitTest();
    ~LzsUnitTest();
    int init(ConfigUnit* cfg_unit);
    virtual bool has_funcname(const std::string& funcname);
    size_t add_func(const std::string& funcname);
    size_t add_user(const std::string& username);
    bool get_cfg(int key, ConfigUnit** cfg);

private:
    void add_func_num();
    FRIEND_TEST(LzsUnitTest, test_add_func_num);
    
private:
    std::set<std::string> m_usernames;
    std::set<std::string> m_funcnames;
    int m_to_test_func_num;
    ConfigUnit* m_cfg_unit;
};