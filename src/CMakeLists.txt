link_directories(${GTKMM_LIBRARY_DIRS} ${G_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS} ${G_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

add_executable(cogmindLauncher main.cpp LauncherWindow.cpp LauncherWindow.h CogmindLauncher.cpp CogmindLauncher.h)

target_link_libraries(cogmindLauncher ${GTKMM_LIBRARIES} ${G_LIBRARIES} ${Boost_LIBRARIES})