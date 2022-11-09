/* TODO
 *
 * FINISH THE MESSAGE BOX WHEN REACHING THE END OF FILE WHILE REPLACEING TEXT [solved]
 *
 * FINISH THE HELP PART IN ABOUT, GIVING A BRIEF INSTRUCTION OF THE TEXT EDITOR
 *
 * FINISH THE FIND/REPLACE FEATURE IN TWO SEPERATE NEW WINDOWS (CLASS REPLACE EXTENDS CLASS FIND)
 *
 * FINISH THE ADVANCED FEATURES [solved]
 *
 * rework KMP string match, replace the parameters as (substring a, pattern b)
 * a might be the substring of [pos, EOF] or [start of file, pos]
 * the func:
 * void partialMatch(string const& subString, string const& pattern)
 *
 * ------------------------------------
 *
 * encoding area wont flush [solved]
 *
 * throw message box when the encoding text only consists of one character
 *
 * clear the decoding area
 *
 * ------------------------------------
 *
 * maybe adding support to '\n'?? [solved]
 *
 * ------------------------------------
 *
 * add 2 ways of comparing the similarity between files:
 * Levenshtein distance and vector distance
 *
 * VECTOR DISTANCE
 * given string s1 s2
 * split s1 and s2, pushing all their slices into its respective vector<string>
 * removing all the duplicates
 *
 * traverse s1, getting freqs for all substrings in s1
 * traverse s2, kmp all substrings of s1, getting freqs for all public substrings of s2
 *
 * append all unique strings in s1 to s2
 * append all unique strings in s2 to s1
 *
 * determine the similarity
 *
 * ------------------------------------
 *
 *
 *
 *
 *
 */
