#ifndef PacManSFMLview_H_
#define PacManSFMLview_H_
#include "PacManBoard.h"

using namespace std;

class PacManSFMLview
{
    PacManBoard& board;

public:
    PacManSFMLview(PacManBoard&);
    void view();

};

#endif
