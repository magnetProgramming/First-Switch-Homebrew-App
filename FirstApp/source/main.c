#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <switch.h>

int main(int argc, char* argv[]) 
{
    consoleInit(NULL);

    padConfigureInput(1, HidNpadStyleSet_NpadStandard);
    PadState pad;
    padInitializeDefault(&pad);

    printf("First Switch Homebrew Application\n");

    printf("Made with love <3 by magnetProgramming\n");

    while (appletMainLoop()) 
    {
        padUpdate(&pad);
        u64 kdown = padGetButtonsDown(&pad);

        if (kdown & HidNpadButton_Plus) 
        {
            break;
        } else if (kdown & HidDebugPadButton_X) 
        {
            printf("You found the secret button! Good job.\n");
        }

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}

