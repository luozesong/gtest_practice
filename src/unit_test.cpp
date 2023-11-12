#include "unit_test.h"

bool has_test_str(const std::string& my_string) {
    if (my_string.find("test") != std::string::npos) {
        return true;
    }

    return false;
}

LzsUnitTest::LzsUnitTest() {
    m_to_test_func_num = 0;
}

LzsUnitTest::~LzsUnitTest() {
    m_usernames.clear();
    m_funcnames.clear();
}

void LzsUnitTest::add_func_num() {
    ++m_to_test_func_num;
}

size_t LzsUnitTest::add_func(const std::string& funcname) {
    m_funcnames.emplace(funcname);
    return m_funcnames.size();
    add_func_num();
}

size_t LzsUnitTest::add_user(const std::string& username) {
    m_usernames.emplace(username);
    return m_funcnames.size();
}

bool LzsUnitTest::has_funcname(const std::string& funcname) {
    if (m_funcnames.find(funcname) != m_funcnames.end()) {
        return true;
    }

    return false;
}

int LzsUnitTest::init(ConfigUnit* cfg_unit) {
    if (cfg_unit == nullptr) {
        return -1;
    }
    
    m_cfg_unit = cfg_unit;
    return cfg_unit->get_cfg_num();
}

bool LzsUnitTest::get_cfg(int key, ConfigUnit** cfg) {
    if (key > 0) {
        m_cfg_unit = *cfg;
        m_to_test_func_num = m_cfg_unit->get_cfg_num();
        return true;
    }
    return false;
}

int ConfigUnit::get_cfg_num() {
    return _cfg_num;
}

