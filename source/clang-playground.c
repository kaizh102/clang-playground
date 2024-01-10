#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

int main() {
    struct termios initial_settings, new_settings;

    // Get the current terminal settings
    tcgetattr(STDIN_FILENO, &initial_settings);
    new_settings = initial_settings;

    // Disable canonical mode (line buffering) and echo
    new_settings.c_lflag &= ~(ICANON | ECHO);
    // Set a minimum of characters to read
    new_settings.c_cc[VMIN] = 1;
    // Set a timeout for reading
    new_settings.c_cc[VTIME] = 0;

    // Set the new settings
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);

    printf("Press any key (including non-printable keys)...\n");

    // Enter the loop to capture input
    int key;
    while (1) {
        key = getchar(); // Read a character

        // Display the key pressed (in decimal)
        printf("Key pressed: %X\n", key);

        // Exit loop if a specific key (e.g., 'q') is pressed
        if (key == 'q') {
            break;
        }
    }

    // Restore the initial terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &initial_settings);

    return 0;
}
