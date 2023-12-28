#include <stdio.h>
#include <string.h>

int main() {
    // Open the user file for reading
    FILE* user_file = fopen("2b_user_list.txt", "r");
    if (user_file == NULL) {
        perror("Error opening user file");
        return 1;
    }

    char line[100]; // Assuming a maximum line length of 100 characters

    char valid_users[100][20]; // Assuming a maximum of 100 valid users with a length of 20 characters each
    int valid_user_count = 0;

    // Read and store the student numbers from the user file
    while (fgets(line, sizeof(line), user_file)) {
        line[strcspn(line, "\n")] = '\0'; // Remove the newline character
        strcpy(valid_users[valid_user_count], line);
        valid_user_count++;
    }

    // Close the user file
    fclose(user_file);

    // Open the CAD file for reading
    FILE* cad_file = fopen("cad2023_2b_w8.txt", "r");
    if (cad_file == NULL) {
        perror("Error opening CAD file");
        return 1;
    }

    char unique_users[100][20]; // Assuming a maximum of 100 unique users with a length of 20 characters each
    int unique_user_count = 0;

    // Read the CAD file line by line
    while (fgets(line, sizeof(line), cad_file)) {
        char* token = strtok(line, " "); // Split the line by space
        if (token != NULL && strstr(token, "cad") == token) {
            // Extract the student number (skip "cad")
            char student_number[20]; // Assuming a maximum length of 20 characters for a student number
            strcpy(student_number, token + 3); // Skip "cad"

            // Check if the student number is in the list of valid users and not a duplicate
            int is_valid = 0;
            for (int i = 0; i < valid_user_count; i++) {
                if (strcmp(valid_users[i], student_number) == 0) {
                    is_valid = 1;
                    break;
                }
            }

            // Add the student number to the unique_users list if it's valid and not a duplicate
            if (is_valid) {
                int is_duplicate = 0;
                for (int i = 0; i < unique_user_count; i++) {
                    if (strcmp(unique_users[i], student_number) == 0) {
                        is_duplicate = 1;
                        break;
                    }
                }

                if (!is_duplicate) {
                    strcpy(unique_users[unique_user_count], student_number);
                    unique_user_count++;
                }
            }
        }
    }

    // Reverse the order of the unique student numbers
    for (int i = 0; i < unique_user_count / 2; i++) {
        char temp[20];
        strcpy(temp, unique_users[i]);
        strcpy(unique_users[i], unique_users[unique_user_count - 1 - i]);
        strcpy(unique_users[unique_user_count - 1 - i], temp);
    }

    // Print the unique student numbers in reverse order
    for (int i = 0; i < unique_user_count; i++) {
        printf("%s\n", unique_users[i]);
    }

    // Close the CAD file
    fclose(cad_file);

    return 0;
}