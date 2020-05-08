cmake_minimum_required(VERSION 3.15)
project(EigenBench C)

set(CMAKE_C_STANDARD 11)


add_executable(EigenBench main.c creators.c creators.h helper.c helper.h utils.c utils.h)
find_library(/home/Volglizolic/Desktop/TL2 ltl2)
target_link_libraries(EigenBench /home/Volglizolic/Desktop/TL2/libtl2.a)
target_include_directories(EigenBench PRIVATE /home/Volglizolic/Desktop/TL2/)
target_include_directories(EigenBench PRIVATE /home/Volglizolic/Desktop/Counters/hpc_utils_lib/include/)

add_executable(PipinoEigenBench main.c creators.c creators.h helper.c helper.h utils.c utils.h)
target_link_libraries(PipinoEigenBench /home/Volglizolic/Desktop/PipinoSTM/cmake-build-debug/libPipinoSTM.a)
target_include_directories(PipinoEigenBench PRIVATE /home/Volglizolic/Desktop/PipinoSTM/)

add_executable(PipinoEigenBenchv2 main.c creators.c creators.h helper.c helper.h utils.c utils.h)
target_link_libraries(PipinoEigenBenchv2 /home/Volglizolic/Desktop/PipinoSTMv2/libPipinoSTMv2.a)
target_include_directories(PipinoEigenBenchv2 PRIVATE /home/Volglizolic/Desktop/PipinoSTMv2/)

find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
    set_property(TARGET PipinoEigenBench PROPERTY COMPILE_OPTIONS "-pthread")
    set_property(TARGET PipinoEigenBench PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
    set_property(TARGET PipinoEigenBenchv2 PROPERTY COMPILE_OPTIONS "-pthread")
    set_property(TARGET PipinoEigenBenchv2 PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
    set_property(TARGET EigenBench PROPERTY COMPILE_OPTIONS "-pthread")
    set_property(TARGET EigenBench PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
    target_link_libraries(PipinoEigenBench "${CMAKE_THREAD_LIBS_INIT}")
    target_link_libraries(PipinoEigenBenchv2 "${CMAKE_THREAD_LIBS_INIT}")
    target_link_libraries(EigenBench "${CMAKE_THREAD_LIBS_INIT}")
endif()