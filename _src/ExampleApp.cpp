#include "Multiply.hpp"
#include "Addition.hpp"

#include <stdio.h>

int main(void)
{
        int x = 4;
        int y = 5;

        int z1 = Addition::twoValues(x,y);
        printf("Addition result: %d\n",z1);

        int z2 = Multiply::twoValues(x,y);
        printf("Multiply result: %d\n",z2);

        //delete corporation;
        return 0;
}
