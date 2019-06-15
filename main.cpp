#include <iostream>
#include "PacManBoard.h"
#include "PacManSFMLmenu.h"
#include "PacManSFMLview.h"
#include "PacManSFMLgameresult.h"

int main()
{
    PacManBoard a(10,10);
    PacManSFMLmenu view;
    PacManSFMLview b(a);
    view.menu();
    b.view();
    PacManSFMLgameresult gameresult(a);
    gameresult.gameresult();


 return 0;
}
