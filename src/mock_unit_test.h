#include "unit_test.h"
#include "gmock/gmock.h"

class MockConfigUint : public ConfigUnit {
public:
    MOCK_METHOD2(get_cfg_num, int());
};