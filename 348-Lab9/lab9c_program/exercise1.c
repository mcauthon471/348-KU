#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define NUM_MONTHS 12

void generateSalesReport(double sales[], char *months[]) {
    printf("Monthly sales report for 2022:\n");
    printf("Month      Sales\n");


    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%-10s $%.2f\n", months[i], sales[i]);
    }
}

void generateSalesSummary(double sales[]) {
    double minSales = sales[0];
    double maxSales = sales[0];
    double totalSales = sales[0];

    for (int i = 1; i < NUM_MONTHS; i++) {
        if (sales[i] < minSales) {
            minSales = sales[i];
        }
        if (sales[i] > maxSales) {
            maxSales = sales[i];
        }
        totalSales += sales[i];
    }

    double avgSales = totalSales / NUM_MONTHS;

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (January)\n", minSales);
    printf("Maximum sales: $%.2f (December)\n", maxSales);
    printf("Average sales: $%.2f\n", avgSales);
}

void calculateMovingAverages(double sales[], char *months[]) {
    printf("\nSix-Month Moving Average Report:\n");

    for (int i = 0; i < NUM_MONTHS - 5; i++) {
        double sum = 0;
        for (int j = 0; j < 6; j++) {
            sum += sales[i + j];
        }

        // Use a fixed width for month and range columns
        printf("%-10s - %-10s $%.2f\n", months[i], months[i + 5], sum / 6);
    }
}

void generateSalesReportDescending(double sales[], char *months[]) {
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month        Sales\n");
    // Create a copy of the sales array and its corresponding months for sorting
    double sortedSales[NUM_MONTHS];
    char *sortedMonths[NUM_MONTHS];

    for (int i = 0; i < NUM_MONTHS; i++) {
        sortedSales[i] = sales[i];
        sortedMonths[i] = months[i];
    }

    // Sort the sales data and corresponding months in descending order
    for (int i = 0; i < NUM_MONTHS - 1; i++) {
        for (int j = i + 1; j < NUM_MONTHS; j++) {
            if (sortedSales[i] < sortedSales[j]) {
                // Swap sales
                double tempSales = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = tempSales;

                // Swap months
                char *tempMonth = sortedMonths[i];
                sortedMonths[i] = sortedMonths[j];
                sortedMonths[j] = tempMonth;
            }
        }
    }

    // Print the sorted sales report
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%-12s $%.2f\n", sortedMonths[i], sortedSales[i]);
    }
}

int main() {
    char *months[] = {"January", "February", "March", "April", "May", "June", "July",
                      "August", "September", "October", "November", "December"};
    double sales[] = {
        23458.01,
        40112.00,
        56011.85,
        37820.88,
        37904.67,
        60200.22,
        72400.31,
        56210.89,
        67230.84,
        68233.12,
        80950.34,
        95225.22
    };

    generateSalesReport(sales, months);
    generateSalesSummary(sales);
    calculateMovingAverages(sales, months);
    generateSalesReportDescending(sales, months);


    return 0;
}
