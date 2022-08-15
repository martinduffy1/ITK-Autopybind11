###############################################################################
# Swig and PCRE do not support blank spaces in install directory namespaces
# This means that ITK cannot be built in a path that contains spaces
# See https://www.swig.org/Doc1.3/Windows.html
message("autopybind 111")
if("${CMAKE_BINARY_DIR}" MATCHES "^.* .*$")
  message(FATAL_ERROR "Swig and PCRE do not support paths with space characters. Please change build directory name.")
endif()

# install autopybind11
if(NOT DEFINED AutoPybind11)
  include(FetchContent)
  FetchContent_Declare(
    AutoPybind11
    GIT_REPOSITORY https://gitlab.kitware.com/john.parent/autopybind11
    GIT_TAG        "b3c15faca272817d68b2180f1922d0e4862975df"
    )
  set(FETCHCONTENT_QUIET OFF)
  FetchContent_MakeAvailable(AutoPyBind11)
endif()

find_package(Python3 COMPONENTS Development REQUIRED)
set(PYTHON_EXECUTABLE /usr/bin/python3.8)
set(PYGCCXML_DIR ${ITK_CMAKE_DIR}/../Modules/ThirdParty/pygccxml/src CACHE INTERNAL "pygccxml path")

###############################################################################
# store the current dir, so it can be reused later
set(ITK_WRAP_SWIGINTERFACE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" CACHE INTERNAL "swig interface source dir")
set(ITK_WRAP_SWIGINTERFACE_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}" CACHE INTERNAL "swig interface binary dir")

set(WRAPPER_MASTER_INDEX_OUTPUT_DIR "${ITK_DIR}/Wrapping/Typedefs" CACHE INTERNAL "typedefs dir")
set(IGENERATOR  "${CMAKE_CURRENT_SOURCE_DIR}/generator.py" CACHE INTERNAL "generator.py path" FORCE)

message("Autopybind loaded")
# wrap macro
macro(itk_wrap_simple_type_swig_interface wrap_class swig_name)
  string(APPEND SWIG_INTERFACE_TYPEDEFS "using ${swig_name} = ${wrap_class};\n")
endmacro()

include_directories("${WRAPPER_MASTER_INDEX_OUTPUT_DIR}")
