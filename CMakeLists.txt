cmake_minimum_required(VERSION 3.15)
project(StudentuProjektas)

# Executable failas
add_executable(Program
    src/main.cpp
    src/vector_testavimas.cpp
)

# Include path
target_include_directories(Program PRIVATE include)

# Nurodom install info
install(TARGETS Program DESTINATION bin)

# CPack setup
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_NAME "OOP")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_GENERATOR "NSIS") 
set(CPACK_PACKAGE_EXECUTABLES "Program" "Vector")
include(CPack)