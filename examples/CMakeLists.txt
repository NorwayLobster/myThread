cmake_minimum_required( VERSION 3.5)
project(example) 
# set(SOURCES testCondition.cc tesMmutexLock.cc testMutexLockGuard.cc testThread.cc testTaskQueue.cc testThreadpool.cc)

add_executable( example_bin_con  testCondition.cc)
target_link_libraries(example_bin_con  PUBLIC sub::threadpool)

add_executable( example_bin_mutex  testMutexLock.cc)
target_link_libraries(example_bin_mutex   PUBLIC sub::threadpool)

add_executable( example_bin_mutexGuard  testMutexLockGuard.cc)
target_link_libraries(example_bin_mutexGuard   PUBLIC sub::threadpool)

add_executable( example_bin_thread testThread.cc)
target_link_libraries(example_bin_thread  PUBLIC sub::threadpool)

add_executable( example_bin_taskqueue testTaskQueue.cc)
target_link_libraries(example_bin_taskqueue  PUBLIC sub::threadpool)

add_executable( example_bin_threadpool testthreadpool.cc)
target_link_libraries(example_bin_threadpool  PUBLIC sub::threadpool)


# find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)

# Include the boost headers
# target_include_directories( ${PROJECT_NAME}
    # PRIVATE 
        # ${Boost_INCLUDE_DIRS}
# )

#target_link_libraries(${PROJECT_NAME}
#    PUBLIC
#    # ${Boost_SYSTEM_LIBRARY}
#    # ${Boost_FILESYSTEM_LIBRARY}
#}
# link against the boost libraries

#target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)


if( CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT )
  message(STATUS "Setting default CMAKE_INSTALL_PREFIX path to ${CMAKE_BINARY_DIR}/install")
  set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE STRING "The path to use for make install" FORCE)
endif()

install(TARGETS example_bin_con DESTINATION bin) 
install(TARGETS example_bin_mutex DESTINATION bin) 
install(TARGETS example_bin_mutexGuard DESTINATION bin) 
install(TARGETS example_bin_thread DESTINATION bin) 
install(TARGETS example_bin_taskqueue DESTINATION bin) 
install(TARGETS example_bin_threadpool DESTINATION bin) 
# how to install sub library, install(TARGETS ${} DESTINATION bin) 
# install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib) 
# install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION include) 
# install(FILES ${PROJECT_SOURCE_DIR}/config/conf.dat DESTINATION etc) 
####Install
