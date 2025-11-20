add_library(mostly-trees
	universal/universal.c
	trees/avl.c
)
target_include_directories(mostly-trees PUBLIC
	./universal/
	./trees/
)
set(PUBLIC_HEADERS
	universal/universal.h
	trees/avl.h
)
set_target_properties(mostly-trees PROPERTIES
	VERSION ${PROJECT_VERSION}
	PUBLIC_HEADER "mostly-trees.h;${PUBLIC_HEADERS}"
)

include(GNUInstallDirs)
install(TARGETS mostly-trees
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/mostly-trees
)
