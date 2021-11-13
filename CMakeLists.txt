cmake_minimum_required(VERSION 3.0.0)
project(ewallet VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()

if (APPLE)
    set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl@1.1")
    set(OPENSSL_INCLUDE_DIR "/usr/local/opt/openssl@1.1/include")
    set(OPENSSL_LIBRARIES "/usr/local/opt/openssl@1.1/lib")
endif (APPLE)

find_package(OpenSSL REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)

include_directories(include)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "src/*.cpp")
add_executable(ewallet ${sources})

if (WIN32)
    target_link_libraries(ewallet nlohmann_json::nlohmann_json OpenSSL::SSL wsock32 ws2_32 crypt32 -static)
endif (WIN32)
if (APPLE)
    target_link_libraries(ewallet OpenSSL::SSL nlohmann_json::nlohmann_json)
endif(APPLE)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
