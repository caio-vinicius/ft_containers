#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"

#include <vector>

bool vector_size(unsigned int size) {
  std::vector<int> v;
  std::vector<int> ft_v;

  for (unsigned int i = 0; i < size; i++) v.push_back(i);
  for (unsigned int i = 0; i < size; i++) ft_v.push_back(i);

  if (v.size() == ft_v.size())
    return (true);
  else
    return (false);
}

TEST_CASE( "The size of the vector matches", "[vector]" ) {
    REQUIRE( vector_size(5) );
}
