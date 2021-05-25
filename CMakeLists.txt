cmake_minimum_required(VERSION 3.19)
project(Trie_on_C C)

set(CMAKE_C_STANDARD 99)

add_executable(Trie_on_C src/main.c src/Trie.c include/Trie_H.h src/CuTest.c include/CuTest.h src/test.c src/testsForTrie.c)