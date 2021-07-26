cmake_minimum_required(VERSION 3.20)

project(algorithms)

# ====================================================================================
#                               base targets - modules
# ====================================================================================

add_library(${PROJECT_NAME}_patterns_objs MODULE) # EXCLUDE_FROM_ALL
target_compile_features(${PROJECT_NAME}_patterns_objs PRIVATE cxx_std_17)

target_sources(${PROJECT_NAME}_patterns_objs PRIVATE
  # ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/creational/abstract-factory.cpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/creational/builder.cpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/creational/factory-method.cpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/creational/prototype.cpp

  # ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/structural/adapter.cpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/structural/bridge.cpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/structural/composite.cpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/structural/decorator.cpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/structural/facade.cpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/structural/flyweight.cpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/structural/proxy.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/command.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/cor.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/mediator.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/memento.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/observer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/state.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/strategy.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/template-method.cpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/visitor.cpp

)
target_include_directories(${PROJECT_NAME}_patterns_objs PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)



# ====================================================================================
#                                     tests target
# ====================================================================================

add_subdirectory(extern/Catch2)

add_executable(tests EXCLUDE_FROM_ALL)
target_compile_features(tests PRIVATE cxx_std_17)

add_dependencies(tests ${PROJECT_NAME}_patterns_objs)

target_sources(tests PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.cpp

  # ${CMAKE_CURRENT_SOURCE_DIR}/tests/patterns/tests_creational.cpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/tests/patterns/tests_structural.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/patterns/tests_behavioral.cpp
)
target_include_directories(tests PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(tests PRIVATE
  Catch2::Catch2

  $<TARGET_OBJECTS:${PROJECT_NAME}_patterns_objs>
)

add_custom_target(run-tests COMMAND $<TARGET_FILE:tests> -s)
add_dependencies(run-tests tests)
