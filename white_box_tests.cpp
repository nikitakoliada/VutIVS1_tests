//======== Copyright (c) 2022, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - test suite
//
// $NoKeywords: $ivs_project_1 $white_box_tests.cpp
// $Author:     Nikita Koliada <xkolia00@stud.fit.vutbr.cz>
// $Date:       $17.02.2023
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author Nikita Koliada
 * 
 * @brief Implementace testu hasovaci tabulky.
 */

#include <vector>

#include "gtest/gtest.h"

#include "white_box_code.h"



//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy hasovaci tabulky, testujte nasledujici:
// 1. Verejne rozhrani hasovaci tabulky
//     - Vsechny funkce z white_box_code.h
//     - Chovani techto metod testuje pro prazdnou i neprazdnou tabulku.
// 2. Chovani tabulky v hranicnich pripadech
//     - Otestujte chovani pri kolizich ruznych klicu se stejnym hashem 
//     - Otestujte chovani pri kolizich hashu namapovane na stejne misto v 
//       indexu
//============================================================================//
class NonEmptyHashMap : public ::testing::Test {
protected:

    hash_map_t* hashmap;

    void SetUp() override{

        hashmap = hash_map_ctor();
        hash_map_put(hashmap, "test1", 4);
        hash_map_put(hashmap, "orange", 53);
        hash_map_put(hashmap, "snickers", 18);
        hash_map_put(hashmap, "test4", 421);
        hash_map_put(hashmap, "test5", 55124);
        hash_map_put(hashmap, "test6", 1853);
    }

    void TearDown() override{
        hash_map_dtor(hashmap);
    }

};

class EmptyHashMap : public ::testing::Test {
protected:

    hash_map_t* emptyhashmap;

    void SetUp () override{

        emptyhashmap = hash_map_ctor();
        hash_map_reserve(emptyhashmap, 8);

    }

    void TearDown() override{
        hash_map_dtor(emptyhashmap);
    }

};


//TEST(WhiteBoxTest, HashMapCtor)
//{
//    hash_map_t* hashmap = hash_map_ctor();
//    EXPECT_NE(hashmap, nullptr);
//    EXPECT_EQ(hashmap->allocated, HASH_MAP_INIT_SIZE);
//    hash_map_dtor(hashmap);
//}
//TEST(WhiteBoxTest, HashMapDtor)
//{
//    //not empty hash
//    hash_map_t* hashmap = hash_map_ctor();
//    EXPECT_NE(hashmap, nullptr);
//    hash_map_dtor(hashmap);
//    EXPECT_EQ(hashmap, nullptr);
//
//    //empty
//    hash_map_t* hashmap2 = hash_map_ctor();
//    hash_map_put(hashmap2, "24344534", 1);
//    EXPECT_NE(hashmap2, nullptr);
//    hash_map_dtor(hashmap2);
//    EXPECT_EQ(hashmap2, nullptr);
//
//}

TEST_F(NonEmptyHashMap, HashMapPut) {

    hash_map_state_code_t code1 = hash_map_put(hashmap, "puttest1", 223);
    hash_map_state_code_t code2 = hash_map_put(hashmap, "puttest2", 44);
    hash_map_state_code_t code3 = hash_map_put(hashmap, "puttest3", 321);
    bool test1 = hash_map_contains(hashmap, "puttest1");
    EXPECT_EQ(true, test1);
    EXPECT_EQ(OK, code1);
    bool test2 = hash_map_contains(hashmap, "puttest2");
    EXPECT_EQ(true, test2);
    EXPECT_EQ(OK, code2);
    bool test3 = hash_map_contains(hashmap, "puttest3");
    EXPECT_EQ(true, test3);
    EXPECT_EQ(OK, code3);

}

TEST_F(EmptyHashMap, HashMapPut) {

    hash_map_state_code_t code1 = hash_map_put(emptyhashmap, "puttest1", 223);
    hash_map_state_code_t code2 = hash_map_put(emptyhashmap, "puttest2", 44);
    hash_map_state_code_t code3 = hash_map_put(emptyhashmap, "puttest3", 321);
    bool test1 = hash_map_contains(emptyhashmap, "puttest1");
    EXPECT_EQ(true, test1);
    EXPECT_EQ(OK, code1);
    bool test2 = hash_map_contains(emptyhashmap, "puttest2");
    EXPECT_EQ(true, test2);
    EXPECT_EQ(OK, code2);
    bool test3 = hash_map_contains(emptyhashmap, "puttest3");
    EXPECT_EQ(true, test3);
    EXPECT_EQ(OK, code3);

}

TEST_F(NonEmptyHashMap, HashMapContains) {

    EXPECT_EQ(true, hash_map_contains(hashmap, "test1"));
    EXPECT_EQ(true, hash_map_contains(hashmap, "orange"));
    EXPECT_EQ(true, hash_map_contains(hashmap, "snickers"));

    bool test10 = hash_map_contains(hashmap, "test10");
    EXPECT_EQ(false, test10);

}

TEST_F(EmptyHashMap, HashMapContains) {
bool test1 = hash_map_contains(emptyhashmap, "puttest1");
EXPECT_EQ(false, test1);
}



TEST_F(NonEmptyHashMap, HashMapGet) {

int value1, value2;
hash_map_state_code_t code1 = hash_map_get(hashmap, "test1", &value1);
EXPECT_EQ(code1, OK);
EXPECT_EQ(value1, 4);

hash_map_state_code_t code2 = hash_map_get(hashmap, "test10", &value2);
EXPECT_EQ(code2, KEY_ERROR);
}

TEST_F(EmptyHashMap, HashMapGet) {

int value;
hash_map_state_code_t code = hash_map_get(emptyhashmap, "gettest", &value);
EXPECT_EQ(code, KEY_ERROR);

}

TEST_F(NonEmptyHashMap, HashMapRemove) {
EXPECT_EQ(hash_map_contains(hashmap, "test1"), true);
hash_map_state_code_t code1 = hash_map_remove(hashmap, "test1");
EXPECT_EQ(code1, OK);
EXPECT_EQ(hash_map_contains(hashmap, "orange"), true);
hash_map_state_code_t code2 = hash_map_remove(hashmap, "orange");
EXPECT_EQ(code2, OK);

EXPECT_EQ(hash_map_contains(hashmap, "test12"), false);
hash_map_state_code_t code3 = hash_map_remove(hashmap, "test24");
EXPECT_EQ(code3, KEY_ERROR);
}

TEST_F(EmptyHashMap, HashMapRemove) {
hash_map_state_code_t code = hash_map_remove(emptyhashmap, "remtest");
EXPECT_EQ(hash_map_contains(emptyhashmap, "remtest"), false);
EXPECT_EQ(code, KEY_ERROR);
}
TEST_F(NonEmptyHashMap, HashMapPop) {

int value1, value2, value3;
hash_map_state_code_t code1 = hash_map_pop(hashmap, "test1", &value1);
EXPECT_EQ(code1, OK);
EXPECT_EQ(value1, 4);

hash_map_state_code_t code2 = hash_map_pop(hashmap, "snickers", &value2);
EXPECT_EQ(code2, OK);
EXPECT_EQ(value2, 18);

EXPECT_EQ(hash_map_contains(hashmap, "test234"), false);
hash_map_state_code_t code3 = hash_map_pop(hashmap, "test234", &value3);
EXPECT_EQ(code3, KEY_ERROR);
}

TEST_F(EmptyHashMap, HashMapPop) {

int value;
hash_map_state_code_t code = hash_map_pop(emptyhashmap, "poptest", &value);
EXPECT_EQ(code, KEY_ERROR);

}

TEST_F(NonEmptyHashMap, HashMapReserve){
hash_map_state_code_t code = hash_map_reserve(hashmap, 16);
size_t cap = hash_map_capacity(hashmap);
EXPECT_EQ(cap, 16);
EXPECT_EQ(code, OK);
}

TEST_F(EmptyHashMap, HashMapReserve){
hash_map_state_code_t code = hash_map_reserve(emptyhashmap, 16);
size_t cap = hash_map_capacity(emptyhashmap);
EXPECT_EQ(cap, 16);
EXPECT_EQ(code, OK);
}


TEST_F(NonEmptyHashMap, HashMapSize){
size_t size = hash_map_size(hashmap);
EXPECT_EQ(size, 6);
hash_map_state_code_t code = hash_map_reserve(hashmap, 16);
hash_map_put(hashmap, "sizetest1", 23425);
hash_map_put(hashmap, "sizetest2", 33521);

size_t size2 = hash_map_size(hashmap);
EXPECT_EQ(size + 2, size2);

}
TEST_F(EmptyHashMap, HashMapSize){
size_t size = hash_map_size(emptyhashmap);
EXPECT_EQ(size, 0);
}

TEST_F(NonEmptyHashMap, HashMapCapacity) {
size_t cap = hash_map_capacity(hashmap);
EXPECT_EQ(cap, 16);
hash_map_state_code_t code1 = hash_map_reserve(hashmap, 32);
cap = hash_map_capacity(hashmap);
EXPECT_EQ(cap, 32);
}

TEST_F(EmptyHashMap, HashMapCapacity) {
size_t cap = hash_map_capacity(emptyhashmap);
EXPECT_EQ(cap, 8);
hash_map_state_code_t code1 = hash_map_reserve(emptyhashmap, 32);
EXPECT_EQ(OK, code1);
cap = hash_map_capacity(emptyhashmap);
EXPECT_EQ(cap, 32);
}


TEST_F(NonEmptyHashMap, HashMapClear)
{
    hash_map_clear(hashmap);

    //check if hashitems were cleared
    EXPECT_EQ(hashmap->used, 0);
    EXPECT_EQ(hashmap->first, nullptr);
    EXPECT_EQ(hashmap->last, nullptr);

}

TEST_F(EmptyHashMap, HashMapClear)
{
    hash_map_clear(emptyhashmap);

    //check if hashitems were cleared
    EXPECT_EQ(emptyhashmap->used, 0);
    EXPECT_EQ(emptyhashmap->first, nullptr);
    EXPECT_EQ(emptyhashmap->last, nullptr);

}

//TEST(WhiteBoxTest, HashCollision){
//    hash_map_t* hashmap = hash_map_ctor();
//    char* key1 = "CollTest";
//    hash_map_put(hashmap, key1, 1);
//    size_t hash = hash_function(key1);
//    // lets assume key2 has the same hash as key1
//    char* key2 = "CollTest2";
//    size_t index = hash_map_lookup_handle(hashmap, key2, hash, false);
//    EXPECT_EQ(index, 1);
//    hash_map_dtor(hashmap);
//
//}