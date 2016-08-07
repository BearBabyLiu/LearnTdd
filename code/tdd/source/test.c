#include "test.h"

int g_Score;
int acBall[21];
int CurrentThrow;
int CurrentFrame;
int flag = true;

void InitGlobalValue()
{
    g_Score = 0;
    CurrentThrow = 0;
    CurrentFrame = 0;
    flag = true;
    memset(acBall, 0, sizeof(int) * 21);
}

int ThrowBall(int pin)
{
    acBall[CurrentThrow++] = pin;
    g_Score += pin;

    if(true == flag)
    {
        if(10 == pin)
        {
            CurrentFrame++;
        }
        else
        {
            CurrentFrame++;
            flag = false;
        }

    }
    else
    {
        flag = true;
    }
    return 0;
}

int GetTotalScore()
{
    return GetFramScore(GetCurrentFrame());
}

int GetCurrentFrame()
{
    return CurrentFrame;
}

int GetFramScore(int framenum)
{
    int score = 0;
    int iloop = 0;
    int ball = 0;
    for(iloop = 0; iloop < framenum; iloop++)
    {
        int firstthrow  = acBall[ball++];
        if(10 == firstthrow)
        {
            score += 10 + acBall[ball] + acBall[ball+1];
        }
        else
        {

            int secondthrow = acBall[ball++];
            int framescore = firstthrow + secondthrow;
            if(10 == framescore)
            {
                score += framescore + acBall[ball];
            }
            else
            {
                score += framescore;
            }

        }
    }
    return score;
}
