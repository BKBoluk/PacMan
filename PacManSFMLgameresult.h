#ifndef PacManSFMLgameresult_H_
#define PacManSFMLgameresult_H_
#include "PacManBoard.h"

using namespace std;

class PacManSFMLgameresult
{
    PacManBoard& board;

public:
    PacManSFMLgameresult(PacManBoard&);
    void gameresult();

};

#endif
