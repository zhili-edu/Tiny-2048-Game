enable_testing()
# moveBoard TEST
add_executable(test_moveBoard test_main.cpp test_moveBoard.cpp)
target_link_libraries(test_moveBoard 2048_lib)
add_test(NAME moveBoard COMMAND test_moveBoard)
# MergeBoard TEST
add_executable(test_mergeBoard test_main.cpp test_mergeBoard.cpp)
target_link_libraries(test_mergeBoard 2048_lib)
add_test(NAME mergeBoard COMMAND test_mergeBoard)