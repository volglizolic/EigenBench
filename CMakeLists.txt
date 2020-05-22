cmake_minimum_required(VERSION 3.15)
project(EigenBench C)

set(CMAKE_C_STANDARD 11)

add_executable(eigen_bench main.c creators.c creators.h helper.c helper.h utils.c utils.h)
target_link_libraries(eigen_bench /home/volglizolic/Desktop/TL2/libtl2.a)
target_include_directories(eigen_bench PRIVATE /home/volglizolic/Desktop/TL2/)
target_include_directories(eigen_bench PRIVATE /home/volglizolic/Desktop/Counters/hpc_utils_lib/include/)

add_executable(main.c creators.c creators.h helper.c helper.h utils.c utils.h)
target_link_libraries(pipino_eigen_bench /home/volglizolic/Desktop/PipinoSTM/cmake-build-debug/libPipinoSTM.a)
target_include_directories(pipino_eigen_bench PRIVATE /home/volglizolic/Desktop/PipinoSTM/)

add_executable(main.c creators.c creators.h helper.c helper.h utils.c utils.h)
target_link_libraries(pipino_eigen_bench_v2 /home/volglizolic/Desktop/PipinoSTMv2/cmake-build-debug/libPipinoSTMv2.a)
target_include_directories(pipino_eigen_bench_v2 PRIVATE /home/volglizolic/Desktop/PipinoSTMv2/)

add_executable(main.c creators.c creators.h helper.c helper.h utils.c utils.h)
target_link_libraries(pipino_eigen_bench_v3 /home/volglizolic/Desktop/PipinoSTMv3/cmake-build-debug/libPipinoSTMv3.a)
target_include_directories(pipino_eigen_bench_v3 PRIVATE /home/volglizolic/Desktop/PipinoSTMv3/)


find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
    set_property(PROPERTY COMPILE_OPTIONS "-pthread")
    set_property(PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
    target_link_libraries(pipino_eigen_bench "${CMAKE_THREAD_LIBS_INIT}")
    target_link_libraries(pipino_eigen_bench_v2 "${CMAKE_THREAD_LIBS_INIT}")
    target_link_libraries(pipino_eigen_bench_v3 "${CMAKE_THREAD_LIBS_INIT}")
    target_link_libraries(eigen_bench "${CMAKE_THREAD_LIBS_INIT}")
endif()