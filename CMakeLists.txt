cmake_minimum_required(VERSION 3.20)

project(algorithms)

# ====================================================================================
#                               base targets - modules
# ====================================================================================

# ====================================================================================
#                                  patterns target
# ====================================================================================

add_library(${PROJECT_NAME}-patterns MODULE)
target_compile_features(${PROJECT_NAME}-patterns PRIVATE cxx_std_17)

target_sources(${PROJECT_NAME}-patterns PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/creational/abstract-factory.cpp
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
  ${CMAKE_CURRENT_SOURCE_DIR}/src/patterns/behavioral/visitor.cpp

)
target_include_directories(${PROJECT_NAME}-patterns PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ====================================================================================
#
# ====================================================================================



# ====================================================================================
#                                     tests target
# ====================================================================================

# ====================================================================================
#                                    patterns tests
# ====================================================================================

add_subdirectory(extern/Catch2)

add_executable(tests-patterns EXCLUDE_FROM_ALL)
target_compile_features(tests-patterns PRIVATE cxx_std_17)

add_dependencies(tests-patterns ${PROJECT_NAME}-patterns)

target_sources(tests-patterns PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/tests/patterns/tests_creational.cpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/tests/patterns/tests_structural.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/patterns/tests_behavioral.cpp
)
target_include_directories(tests-patterns PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(tests-patterns PRIVATE
  Catch2::Catch2

  $<TARGET_OBJECTS:${PROJECT_NAME}-patterns>
)

add_custom_target(run-tests-patterns COMMAND $<TARGET_FILE:tests-patterns> "-s patterns::*")
add_dependencies(run-tests-patterns tests-patterns)

# ====================================================================================
#
# ====================================================================================
