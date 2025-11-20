add_executable(unittest1 unittest.c)
target_link_libraries(unittest1 PUBLIC mostly-trees)
add_test(NAME Unittest_1 COMMAND unittest1)
