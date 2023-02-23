CMAKE_MINIMUM_REQUIRED( VERSION 3.1 )
PROJECT(rootjna)

find_package(ROOT REQUIRED)

file(GLOB SRC_FILES CONFIGURE_DEPENDS 
  #${PROJECT_SOURCE_DIR}/src/[a-zA-z]*.cxx
  ./src/[a-zA-z]*.cxx
  )

add_library(rootjna SHARED ${SRC_FILES})
target_include_directories(rootjna
  INTERFACE ./include ${ROOT_INCLUDE_DIRS})
target_link_libraries(rootjna PUBLIC ROOT::Core ROOT::RIO)

#add_library(SHARED ${PROJECT_NAME} ${library_sources})
#install(TARGETS ${PROJECT_NAME} DESTINATION lib)
#target_link_libraries(${PROJECT_NAME} ${ROOT_LIBS})
