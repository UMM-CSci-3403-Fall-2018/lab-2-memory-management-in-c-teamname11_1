#include <gtest/gtest.h>
#include "disemvowel.h"

// Each test has a placeholder variable that calls disemvowel()
// so that whatever is returned from disemvowel() can be freed. 

TEST(Disemvowel, HandleEmptyString) {
  char *str = disemvowel((char*) "");  
  ASSERT_STREQ("", str);
  free(str);
}

TEST(Disemvowel, HandleNoVowels) {
  char *str = disemvowel((char*) "pqrst");	
  ASSERT_STREQ("pqrst", str);
  free(str);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char *str = disemvowel((char*) "aeiouAEIOUOIEAuoiea");	
  ASSERT_STREQ("", str);
  free(str);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char *str = disemvowel((char*) "Morris, Minnesota");	
  ASSERT_STREQ("Mrrs, Mnnst", str);
  free(str);	     
}

TEST(Disemvowel, HandlePunctuation) {
  char *str = disemvowel((char*) "An (Unexplained) Elephant!");	
  ASSERT_STREQ("n (nxplnd) lphnt!", str);
  free(str);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  char *disemvoweled_str = disemvowel(str);  
  ASSERT_STREQ("xyz", disemvoweled_str);

  free(disemvoweled_str);
  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
