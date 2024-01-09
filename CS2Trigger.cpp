#include <iostream>
#include <windows.h>

// Function to check if the trigger key is pressed
bool isTriggerKeyPressed()
{
    // Replace VK_F1 with the desired trigger key (F1 key in this case)
    return (GetAsyncKeyState(VK_F1) & 0x8000);
}

// Function to simulate mouse click
void triggerMouseClick()
{
    INPUT input;
    ZeroMemory(&input, sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input, sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
}

int main()
{
    std::cout << "Triggerbot is running!" << std::endl;

    while (true)
    {
        // Check if the trigger key is pressed
        if (isTriggerKeyPressed())
        {
            // Trigger the mouse click
            triggerMouseClick();
        }
    }

    return 0;
}
