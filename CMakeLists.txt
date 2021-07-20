cmake_minimum_required(VERSION 2.4)

project(CaesarCipher)

add_executable(
  ${PROJECT_NAME}
  main.cpp 
)

add_subdirectory(src)

target_include_directories(${PROJECT_NAME} PUBLIC src)

target_link_libraries(${PROJECT_NAME} cp)
