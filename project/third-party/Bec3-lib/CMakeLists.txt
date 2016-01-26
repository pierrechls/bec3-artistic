cmake_minimum_required(VERSION 2.8)

project(BeC3)

find_package(CURL REQUIRED)
include_directories(${CURLCPP_SOURCE_DIR}/include include third-party/restclient/include/ third-party/rapidjson/)
set(ALL_LIBRARIES restclient ${CURL_LIBRARY})
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp)

add_subdirectory(third-party)

add_library(Bec3-lib ${SRC_FILES})
