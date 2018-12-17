cmake_minimum_required(VERSION 3.13)
project(cogmindLauncher)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0)
pkg_check_modules(G libconfig++)
pkg_check_modules(CURLPP curlpp)

find_package(Boost COMPONENTS filesystem regex)

add_subdirectory("src")
