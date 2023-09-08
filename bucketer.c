#include <stdio.h>

// Function to calculate SoH (State of Health)
double calculateSoH(double present_capacity, double rated_capacity) {
    return (present_capacity / rated_capacity) * 100.0;
}

// Function to classify a battery based on SoH
char* classifyBattery(double soh) {
    if (soh > 80.0) {
        return "Healthy";
    } else if (soh >= 65.0) {
        return "Replace";
    } else {
        return "Failed";
    }
}

int main() {
    double rated_capacity = 120.0; // Rated capacity of all batteries (in Ah)
    double present_capacities[] = {105.0, 95.0, 60.0, 110.0, 75.0, 100.0};
    int num_batteries = sizeof(present_capacities) / sizeof(present_capacities[0]);

    int healthy_count = 0;
    int replace_count = 0;
    int failed_count = 0;

    // Loop through each battery, calculate SoH, classify, and count
    for (int i = 0; i < num_batteries; i++) {
        double soh = calculateSoH(present_capacities[i], rated_capacity);
        char* classification = classifyBattery(soh);

        if (classification == "Healthy") {
            healthy_count++;
        } else if (classification == "Replace") {
            replace_count++;
        } else {
            failed_count++;
        }
    }

    printf("Classification Counts:\n");
    printf("Healthy: %d\n", healthy_count);
    printf("Replace: %d\n", replace_count);
    printf("Failed: %d\n", failed_count);

    return 0;
}

