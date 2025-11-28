add_executable(avl-insertion avl-insertion.c)
target_link_libraries(avl-insertion PUBLIC mostly-trees)
add_test(NAME avl-insertion COMMAND avl-insertion)

add_executable(avl-rotation avl-rotation.c)
target_link_libraries(avl-rotation PUBLIC mostly-trees)
add_test(NAME avl-rotation COMMAND avl-rotation)

add_executable(avl-balance avl-balance.c)
target_link_libraries(avl-balance PUBLIC mostly-trees)
add_test(NAME avl-balance COMMAND avl-balance)
