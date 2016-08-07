#include "tdd_fake.h"

class TestGetTotalScore : public TestThrowScorce
{
     virtual void SetUp()
     {
        TestThrowScorce::SetUp();
     }

     virtual void TearDown()
     {
        TestThrowScorce::TearDown();
     }

};

/**
** 首先考虑的是不含补中与全中的情况
**/

/*
** G: 当只进行一轮投郑，得分为1，2
** W: 计算总分
** T: 总分等于3
*/
TEST_F(TestGetTotalScore, ThrowTwoBallNoMark)
{
    ThrowBall(1);
    ThrowBall(2);

    returnvalue = GetTotalScore();

    EXPECT_EQ(3, returnvalue);
}

/*
** G: 当进行三轮投郑，得分为1，3，5，4，5，3
** W: 计算总分
** T: 总分等于21
*/

TEST_F(TestGetTotalScore, ThrowManyBallNoMark)
{
    ThrowBall(1);
    ThrowBall(3);
    ThrowBall(5);
    ThrowBall(4);
    ThrowBall(5);
    ThrowBall(3);

    returnvalue = GetTotalScore();

    EXPECT_EQ(21, returnvalue);
}

/**
** 考虑补中的情况
**/

/*
** G: 当进行两轮投郑，得分为3，7，3，2
** W: 计算总分
** T: 总分等于18
*/

TEST_F(TestGetTotalScore, ThrowFourBallWithSpare)
{
    ThrowBall(3);
    ThrowBall(7);
    ThrowBall(3);
    ThrowBall(2);

    returnvalue = GetTotalScore();

    EXPECT_EQ(18, returnvalue);

}

/**
** 考虑全中的情况
**/

/*
** G: 当进行两轮投郑，得分为10,7,2
** W: 计算总分
** T: 总分等于28
*/
TEST_F(TestGetTotalScore, ThrowTreeBallWithStrike)
{
    ThrowBall(10);
    ThrowBall(7);
    ThrowBall(2);

    returnvalue = GetTotalScore();

    EXPECT_EQ(28, returnvalue);


}

class TestGetFrameScore : public TestThrowScorce
{
     virtual void SetUp()
     {
         TestThrowScorce::SetUp();
     }

     virtual void TearDown()
     {
         TestThrowScorce::TearDown();
     }

};

/*
** G: 当进行两轮投郑，不含全中与补中，得分为1,2,3,5
** W: 计算第一轮投郑得分与第二轮投郑得分
** T: 第一轮得分为3，第二轮得分为11
*/
TEST_F(TestGetFrameScore, TheFirstFrame)
{
    ThrowBall(1);
    ThrowBall(2);
    ThrowBall(3);
    ThrowBall(5);

    returnvalue = GetFramScore(1);

    EXPECT_EQ(3, returnvalue);

    returnvalue = GetFramScore(2);

    EXPECT_EQ(11, returnvalue);

}

/*
** G: 当进行一轮投郑，含补中得分为3,7,3
** W: 计算第一轮投郑得分
** T: 得分为13
*/
TEST_F(TestGetFrameScore, ThrowThreeBallWithSpare)
{
    ThrowBall(3);
    ThrowBall(7);
    ThrowBall(3);

    returnvalue = GetFramScore(1);

    EXPECT_EQ(13, returnvalue);

}

/*
** G: 当进行两轮投郑，含补中得分为3,7,3,2
** W: 计算第一轮投郑得分与第二轮投郑得分
** T: 第一轮等分为13,第二轮投郑得分为18
*/
TEST_F(TestGetFrameScore, ThrowFourBallWithSpare)
{
    ThrowBall(3);
    ThrowBall(7);
    ThrowBall(3);
    ThrowBall(2);

    returnvalue = GetFramScore(1);

    EXPECT_EQ(13, returnvalue);

    returnvalue = GetFramScore(2);

    EXPECT_EQ(18, returnvalue);

}

/*
** G: 当进行两轮投郑，含全中,得分为10,7,2
** W: 计算第一轮投郑得分与第二轮投郑得分
** T: 第一轮等分为19,第二轮投郑得分为28
*/
TEST_F(TestGetFrameScore, ThrowTreeBallWithStrike)
{
    ThrowBall(10);
    ThrowBall(7);
    ThrowBall(2);

    returnvalue = GetFramScore(1);

    EXPECT_EQ(19, returnvalue);

    returnvalue = GetFramScore(2);

    EXPECT_EQ(28, returnvalue);

}


class TestGetCurrentFrame: public TestThrowScorce
{
     virtual void SetUp()
     {
         TestThrowScorce::SetUp();
     }

     virtual void TearDown()
     {
         TestThrowScorce::TearDown();
     }

};

/*
** G: 当进行两轮投郑，不含全中与补中，得分为1,2,3,5
** W: 计算当前轮
** T: 当前轮为第二轮
*/
TEST_F(TestGetCurrentFrame, TheFirstFrame)
{
    ThrowBall(1);
    ThrowBall(2);
    ThrowBall(3);
    ThrowBall(5);

    returnvalue = GetCurrentFrame();

    EXPECT_EQ(2, returnvalue);
}

/*
** G: 当进行一轮投郑，含补中得分为3,7,3
** W: 计算当前轮
** T: 当前轮为第一轮

*/
TEST_F(TestGetCurrentFrame, ThrowThreeBallWithSpare)
{
    ThrowBall(3);
    ThrowBall(7);
    ThrowBall(3);

    returnvalue = GetCurrentFrame();

    EXPECT_EQ(2, returnvalue);

}

/*
** G: 当进行两轮投郑，含补中得分为3,7,3,2
** W: 计算当前轮
** T: 当前轮为第二轮
*/
TEST_F(TestGetCurrentFrame, ThrowFourBallWithSpare)
{
    ThrowBall(3);
    ThrowBall(7);
    ThrowBall(3);
    ThrowBall(2);

    returnvalue = GetCurrentFrame();

    EXPECT_EQ(2, returnvalue);

}

/*
** G: 当进行两轮投郑，含全中,得分为10,7,2
** W: 计算当前轮
** T: 当前轮为第二轮
*/
TEST_F(TestGetCurrentFrame, ThrowTreeBallWithStrike)
{
    ThrowBall(10);
    ThrowBall(7);
    ThrowBall(2);

    returnvalue = GetCurrentFrame();

    EXPECT_EQ(2, returnvalue);

}


