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
** ���ȿ��ǵ��ǲ���������ȫ�е����
**/

/*
** G: ��ֻ����һ��Ͷ֣���÷�Ϊ1��2
** W: �����ܷ�
** T: �ֵܷ���3
*/
TEST_F(TestGetTotalScore, ThrowTwoBallNoMark)
{
    ThrowBall(1);
    ThrowBall(2);

    returnvalue = GetTotalScore();

    EXPECT_EQ(3, returnvalue);
}

/*
** G: ����������Ͷ֣���÷�Ϊ1��3��5��4��5��3
** W: �����ܷ�
** T: �ֵܷ���21
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
** ���ǲ��е����
**/

/*
** G: ����������Ͷ֣���÷�Ϊ3��7��3��2
** W: �����ܷ�
** T: �ֵܷ���18
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
** ����ȫ�е����
**/

/*
** G: ����������Ͷ֣���÷�Ϊ10,7,2
** W: �����ܷ�
** T: �ֵܷ���28
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
** G: ����������Ͷ֣������ȫ���벹�У��÷�Ϊ1,2,3,5
** W: �����һ��Ͷ֣�÷���ڶ���Ͷ֣�÷�
** T: ��һ�ֵ÷�Ϊ3���ڶ��ֵ÷�Ϊ11
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
** G: ������һ��Ͷ֣�������е÷�Ϊ3,7,3
** W: �����һ��Ͷ֣�÷�
** T: �÷�Ϊ13
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
** G: ����������Ͷ֣�������е÷�Ϊ3,7,3,2
** W: �����һ��Ͷ֣�÷���ڶ���Ͷ֣�÷�
** T: ��һ�ֵȷ�Ϊ13,�ڶ���Ͷ֣�÷�Ϊ18
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
** G: ����������Ͷ֣����ȫ��,�÷�Ϊ10,7,2
** W: �����һ��Ͷ֣�÷���ڶ���Ͷ֣�÷�
** T: ��һ�ֵȷ�Ϊ19,�ڶ���Ͷ֣�÷�Ϊ28
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
** G: ����������Ͷ֣������ȫ���벹�У��÷�Ϊ1,2,3,5
** W: ���㵱ǰ��
** T: ��ǰ��Ϊ�ڶ���
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
** G: ������һ��Ͷ֣�������е÷�Ϊ3,7,3
** W: ���㵱ǰ��
** T: ��ǰ��Ϊ��һ��

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
** G: ����������Ͷ֣�������е÷�Ϊ3,7,3,2
** W: ���㵱ǰ��
** T: ��ǰ��Ϊ�ڶ���
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
** G: ����������Ͷ֣����ȫ��,�÷�Ϊ10,7,2
** W: ���㵱ǰ��
** T: ��ǰ��Ϊ�ڶ���
*/
TEST_F(TestGetCurrentFrame, ThrowTreeBallWithStrike)
{
    ThrowBall(10);
    ThrowBall(7);
    ThrowBall(2);

    returnvalue = GetCurrentFrame();

    EXPECT_EQ(2, returnvalue);

}


