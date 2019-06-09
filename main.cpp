#include <iostream>
#include "PacManBoard.h"
#include "PacManSFMLmenu.h"
#include "PacManSFMLview.h"

int main()
{
    PacManBoard a(10,10);
    PacManSFMLmenu view;
    PacManSFMLview b(a);
    view.menu();
    b.view();


 return 0;
}
