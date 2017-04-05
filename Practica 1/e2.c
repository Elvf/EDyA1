#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int string_len (char *str) {
  int i = 0;
  
  while (str[i] != '\0') {
    i++;
  }
  
  return i;
}

void string_reverse (char *str) {
  char temp;
  size_t len = string_len(str);
  size_t i, k = len - 1;
  
  for (i = 0; i < len; i++) {
    temp = str[k];
    str[k] = str[i];
    str[i] = temp;
    k--;
    
    /* 2 characters are changing place for each cycle of the loop, so
     * we need only traverse half the array */
    if (k == (len / 2)) {
      break;
    }
  }
}

size_t string_concat (char *str1, char *str2, size_t max) {
  size_t len1 = string_len(str1);
  size_t i, counter = 0;
  
  /* If the max amount of bytes of memory is already occupied, we can't
   * do a concat, so we return 0 because 0 characters were changed */
  if (max == len1) {
    return 0;
  }
  
  /* Now if the above doesn't apply, we go through and start adding the
   * characters from str2 to the end of str1, replacing the \0 char that
   * previously was at the len1 - 1 positon */
  for (i = 0; i < max - len1; i++) {
    str1[len1 + i] = str2[i];
    counter++;
  }
  
  /* Since we want str1 to remain a string, the loop only goes up to
   * max - 1, so we can add the \0 character manually at the end */
  str1[max - 1] = '\0';
  
  return counter + 1;
}

int string_compare (char *str1, char *str2) {
  size_t len1 = string_len(str1);
  size_t len2 = string_len(str2);
  int i;
  
  /* Compare lengths first */
  if (len1 > len2) {
    return 1;
  } else if (len1 < len2) {
    return -1;
  }
  
  /* If both strings are equal in length, then we compare character
   * by character, returning respective outputs per case */
  for (i = 0; i < len1; i++) {
    if (str1[i] != str2[i]) {
      if (str1[i] < str2[i]) {
        return -1;
      } else {
        return 1;
      }
    }
  }
  
  /* If the loop doesn't break, that means the strings are equal */
  return 0;
}

int string_substring (char *str1, char *str2) {
  size_t len1 = string_len(str1);
  size_t len2 = string_len(str2);
  int i, comparatorIndex = 0;
  
  /* We iterate through str1, to find if str2 is a substring */
  for (i = 0; i < len1; i++) {
    /* If comparatorIndex is less than the length of string2, then we
     * can compare char by char after our first find. */
    if (comparatorIndex < len2) {
      if (str1[i] == str2[comparatorIndex]) {
        /* If the characters are equal, we add 1 to the comparator index
         * so we can keep comparing the next char of str1 with the 2nd
         * char of str2, and so on */
        comparatorIndex++;
      } else {
        /* If the characters don't match after the comparison, we reset
         * comparator Index to keep looking for matches */
        comparatorIndex = 0;
      }
    } else {
      /* After comparing, if we find a match, the index where str2 first
       * occurs in str1 is our current position minus the length of
       * str2. */
      return i - len2;
    }
  }
  
  /* If the loop doesn't break, we can safely assume there are no
   * instances of str2 in str1 */
  return -1;
}

void string_join (char* stringArray[], size_t capacity, char *separator, char *res, size_t maxRes) {
  int i, k, l, pos = 0;
  size_t currentStrLength, totalCharLength = 0;
  
  /* We calculate the total number of bytes we're going to need to
   * allocate for res */
  for (i = 0; i < capacity; i++) {
    totalCharLength = totalCharLength + string_len(stringArray[i]);
  }
  
  /* We add the total capacity of the array to the total char length
   * since we also need space for the separators and the last \0 end
   * of string character */
  totalCharLength = totalCharLength + ((capacity - 1) * string_len(separator)) + 1;

  assert(maxRes >= totalCharLength);
  
  /* We can finally begin copying the strings together */
  for (i = 0; i < capacity; i++) {
    /* We calculate the length of the current string */
    currentStrLength = string_len(stringArray[i]);
    
    /* Copy character by character from the array to our new string */
    for (k = 0; k < currentStrLength; k++) {
      res[pos] = stringArray[i][k];
      pos++;
    }
    
    /* We add 1 to the position, so we can place our separator 
     * character(s) there */
    //pos++;
    
    /* We only need capacity - 1 separators since the last character
     * has to be an end of string */
    if (i < capacity - 1) {
      /* We copy, char by char, the separator to the string, adding to
       * the overall position as we go */
      for (l = 0; l < string_len(separator); l++) {
        res[pos] = separator[l];
        pos++;
      }
    } else {
      /* If we're on the last iteration, the final character of the new
       * string is going to be an end of string character */
      res[pos] = '\0';
    }
  }
}

/**
 * Main
 */
int main (void) {
  char testStr1[] = "Hello World!";
  char testStr2[50] = {'I', ' ', 'a', 'm', ' ', 'a', ' ', 'c', 'o', 'm', 'p', 'u', 't', 'e', 'r', '\0'};
  char testStr3[] = "I do multiple things better than you.";
  char testStr4[] = "This string is reversed";
  char testStr5[] = "orl";
  char separator[] = " . ";
  char joinResult[100];
  char *arr[3];
  int len1, len2, len3, copiedChars, comparison, substring;
  
  /* string_len test */
  len1 = string_len(testStr1);
  len2 = string_len(testStr2);
  len3 = string_len(testStr3);
  
  printf("Length of the strings:\n [1]. %d\n [2]. %d\n [3]. %d\n\n", len1, len2, len3);
  
  /* string_reverse test */
  printf("String to reverse: %s", testStr4);
  string_reverse(testStr4);
  printf("\nString after reversal: %s\n\n", testStr4);
  
  /* string_concat test */
  copiedChars = string_concat(testStr2, testStr1, 50);
  printf("The cat'd string from testStr2 and testStr1 is: %s\nCharacters copied: %d\n\n", testStr2, copiedChars);
  
  /* string_compare test */
  comparison = string_compare(testStr1, testStr1);
  printf("Comparison variable: %d\n\n", comparison);
  
  /* string_substring test */
  substring = string_substring(testStr1, testStr5);
  printf("Substring variable: %d\n\n", substring);
  
  /* string_join test */
  arr[0] = testStr1;
  arr[1] = testStr2;
  arr[2] = testStr3;
  
  string_join(arr, 3, separator, joinResult, 100);
  
  printf("Joined string result:\n%s\n\n", joinResult);
  
  return 0;
}
