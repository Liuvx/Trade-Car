#include "blue.h"

extern int MEI_Num;
extern int NAN_Num;
extern int JIU_Num;

void BLUE_print(void)
{
    printf("M%d", MEI_Num);
    printf("N%d", NAN_Num);
    printf("J%d", JIU_Num);
}
