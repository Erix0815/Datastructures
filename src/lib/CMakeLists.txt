add_library(mostly-trees
	greeting/greeting.c
)
target_include_directories(mostly-trees PUBLIC
	./greeting/
)
set(PUBLIC_HEADERS
	greeting/greeting.h
)
set_target_properties(mostly-trees PROPERTIES
	VERSION ${PROJECT_VERSION}
	PUBLIC_HEADER "mostly-trees.h;${PUBLIC_HEADERS}"
)

include(GNUInstallDirs)
install(TARGETS mostly-trees
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/mostly-trees
)
