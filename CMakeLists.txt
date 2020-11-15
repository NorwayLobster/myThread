cmake_minimum_required( VERSION 3.5)
project(myThread)
# add_subdirectory(examples)//cmake .. still error
set(SOURCES 
      src/condition.cpp
      src/mutex.cpp
      src/mutexLockGuard.cpp
      src/thread.cpp
      src/taskQueue.cpp
      src/threadpool.cpp
)

add_library( ${PROJECT_NAME}  SHARED ${SOURCES})
add_library( sub::myThread ALIAS ${PROJECT_NAME} )
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)

# Include the boost headers
target_include_directories( ${PROJECT_NAME}
    PRIVATE ${Boost_INCLUDE_DIRS}
)

# link against the boost libraries
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
)



if( CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT )
  message(STATUS "Setting default CMAKE_INSTALL_PREFIX path to ${CMAKE_BINARY_DIR}/install")
  set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE STRING "The path to use for make install" FORCE)
endif()

# install(TARGETS ${PROJECT_NAME} DESTINATION bin) 
# how to install sub library, install(TARGETS ${} DESTINATION bin) 
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib) 
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION include) 
# install(FILES ${PROJECT_SOURCE_DIR}/config/conf.dat DESTINATION etc) 
####Install