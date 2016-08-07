#ifndef _TDDUTEST_H_
#define _TDDUTEST_H_
#include "test.h"
#include "gtest/gtest.h"

class TestThrowScorce : public testing::Test
{
     public:
     int returnvalue;
     virtual void SetUp()
     {
        returnvalue = 0;
     }

     virtual void TearDown()
     {
         tdd_fake_init();
     }

     void tdd_fake_init()
     {
         InitGlobalValue();
     }
};


#endif

