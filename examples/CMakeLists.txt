cmake_minimum_required( VERSION 3.5)
project(myThread) 
# set(SOURCES testCondition.cc tesMmutexLock.cc testMutexLockGuard.cc testThread.cc testTaskQueue.cc testThreadpool.cc)

add_executable( example_bin_con  testCondition.cc)
add_executable( example_bin_mutex  testMutexLock.cc)
add_executable( example_bin_mutexGuard  testMutexLockGuard.cc)
add_executable( example_bin_thread testThread.cc)
add_executable( example_bin_taskqueue testTaskQueue.cc)
add_executable( example_bin_threadpool testthreadpool.cc)


# find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)

# Include the boost headers
# target_include_directories( ${PROJECT_NAME}
    # PRIVATE 
        # ${Boost_INCLUDE_DIRS}
# )

# link against the boost libraries
target_link_libraries(${PROJECT_NAME}
    PUBLIC
        sub::myThread
    # ${Boost_SYSTEM_LIBRARY}
    # ${Boost_FILESYSTEM_LIBRARY}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)


if( CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT )
  message(STATUS "Setting default CMAKE_INSTALL_PREFIX path to ${CMAKE_BINARY_DIR}/install")
  set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE STRING "The path to use for make install" FORCE)
endif()

# install(TARGETS example_bin DESTINATION bin) 
# how to install sub library, install(TARGETS ${} DESTINATION bin) 
# install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib) 
# install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION include) 
# install(FILES ${PROJECT_SOURCE_DIR}/config/conf.dat DESTINATION etc) 
####Install