#include "packing_tests.h"


int main(void) {
    test_packing_2_4();
    test_packing_3_4();
    test_packing_2_5();
    test_packing_2_10();
    test_packing_3_8();
    test_packing_4_16();
    printf("Passed all tests.\n");
}


void test_packing_2_4(void) {
    uint16_t features[2] = { 0x1, 0x2 };
    uint8_t bitWidth = 4;
    uint16_t numValues = 2;
    uint8_t output[1];
    
    uint16_t numBytes = pack(output, features, bitWidth, numValues);
    assert(numBytes == 1);
    assert(output[0] == 0x21);
}


void test_packing_3_4(void) {
    uint16_t features[3] = { 0x1, 0x2, 0x3 };
    uint8_t bitWidth = 4;
    uint16_t numValues = 3;
    uint8_t output[2];
    
    uint16_t numBytes = pack(output, features, bitWidth, numValues);
    assert(numBytes == 2);
    assert(output[0] == 0x21);
    assert(output[1] == 0x3);
}


void test_packing_2_5(void) {
    uint16_t features[2] = { 0x13, 0x09 };
    uint8_t bitWidth = 5;
    uint16_t numValues = 2;
    uint8_t output[2];
    
    uint16_t numBytes = pack(output, features, bitWidth, numValues);
    assert(numBytes == 2);
    assert(output[0] == 0x33);
    assert(output[1] == 0x1);
}


void test_packing_2_10(void) {
    uint16_t features[2] = { 0x145, 0x2FB };
    uint8_t bitWidth = 10;
    uint16_t numValues = 2;
    uint8_t output[3];

    uint16_t numBytes = pack(output, features, bitWidth, numValues);
    assert(numBytes == 3);
    assert(output[0] == 0x45);
    assert(output[1] == 0xED);
    assert(output[2] == 0xB);
}


void test_packing_3_8(void) {
    uint16_t features[3] = { 0x72, 0x89, 0xEF };
    uint8_t bitWidth = 8;
    uint16_t numValues = 3;
    uint8_t output[3];

    uint16_t numBytes = pack(output, features, bitWidth, numValues);
    assert(numBytes == 3);
    assert(output[0] == 0x72);
    assert(output[1] == 0x89);
    assert(output[2] == 0xEF);
}


void test_packing_4_16(void) {
    uint16_t features[4] = { 0xDEAD, 0xBEEF, 0x1234, 0x5678 };
    uint8_t bitWidth = 16;
    uint16_t numValues = 4;
    uint8_t output[8];

    uint16_t numBytes = pack(output, features, bitWidth, numValues);
    assert(numBytes == 8);
    assert(output[0] == 0xAD);
    assert(output[1] == 0xDE);
    assert(output[2] == 0xEF);
    assert(output[3] == 0xBE);
    assert(output[4] == 0x34);
    assert(output[5] == 0x12);
    assert(output[6] == 0x78);
    assert(output[7] == 0x56);
}
