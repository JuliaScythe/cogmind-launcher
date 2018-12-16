cmake_minimum_required(VERSION 3.13)
project(cogmindLauncher)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0)
pkg_check_modules(G libconfig++)

find_package(Boost COMPONENTS filesystem)

add_subdirectory("src")
