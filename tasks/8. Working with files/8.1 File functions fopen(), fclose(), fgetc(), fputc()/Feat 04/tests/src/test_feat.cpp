#include "gtest/gtest.h"

extern "C" {
#include "../../config.h"
#include "../../utils.h"
}

TEST(exit_successfully, task_8_1_feat_4) { ASSERT_EQ(main_task(), 0); }
