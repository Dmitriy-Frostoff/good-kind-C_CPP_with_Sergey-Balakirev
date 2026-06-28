#enable testing
enable_testing()

# create binary @link{current_feat} that contains test_feat and GTest
add_executable(test_feat src/test_feat.cpp)
target_link_libraries(test_feat PRIVATE task_logic GTest::gtest GTest::gtest_main)
target_include_directories(test_feat PRIVATE ../)

include(CTest)
add_test(NAME test_feat COMMAND test_feat)
