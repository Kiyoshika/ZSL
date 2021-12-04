add_library(zsl 
    dataset/constructors/Constructors.cpp
    dataset/operators/Operators.cpp
    dataset/encapsulators/Encapsulators.cpp
    dataset/resize/Resize.cpp
    dataset/io/DataIO.cpp
    dataset/casting/Casting.cpp
    dataset/select/Select.cpp
    dataset/filter/Filter.cpp
    dataset/drop/Drop.cpp
    dataset/replace/Replace.cpp
    dataset/sample/Sample.cpp
    dataset/append/Append.cpp
    dataset/transpose/Transpose.cpp
    dataset/aggregates/CountNA.cpp
    dataset/split/SplitData.cpp
)
target_compile_options(zsl PRIVATE -O2)
target_include_directories(zsl PRIVATE include)

add_executable(main main.cpp)
target_compile_options(main PRIVATE -O2)
target_link_libraries(main zsl)
