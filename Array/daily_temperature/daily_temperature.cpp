#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using temperature_array = std::vector<std::vector<double>>;

void inputDailyTemperature(temperature_array & ta);

void displayDailyTemperature(const temperature_array & ta);

void displayAverageTemperature(const temperature_array & ta);

void showMaxAndMinTemperature(const temperature_array & ta);

void displayWeeklyAverageTemperature(const temperature_array & ta);

int main(void) {
    const int DAYS = 7, ZONE = 5;
    std::freopen("./input.in", "r", stdin);

    // std::random_device               rd;
    // std::mt19937                     gen(rd());
    // std::uniform_real_distribution<> dis(20.0, 40.0);

    // for (int i = 0; i < DAYS; i++)
    // {
    //     for (int j = 0; j < ZONE; j++)
    //         std::cout << std::fixed << std::setprecision(2) << dis(gen) << '
    //         ';
    //     std::cout << '\n';
    // }

    temperature_array daily_temperature(DAYS, std::vector<double>(ZONE));

    inputDailyTemperature(daily_temperature);
    std::cout << '\n';

    displayDailyTemperature(daily_temperature);
    std::cout << '\n';

    displayAverageTemperature(daily_temperature);
    std::cout << '\n';

    showMaxAndMinTemperature(daily_temperature);
    std::cout << '\n';

    displayWeeklyAverageTemperature(daily_temperature);
    std::cout << '\n';

    return 0;
}

void inputDailyTemperature(temperature_array & ta) {
    for (int i = 0; i < ta.size(); i++) {
        std::cout << "Please input for day " << (i + 1) << ":\n";
        for (int j = 0; j < ta[i].size(); j++) {
            std::cout << "Please input for Zone " << char(j + 'A') << ": ";
            std::cin >> ta[i][j];
        }
    }

    return;
}

void displayDailyTemperature(const temperature_array & ta) {
    std::cout << '\t';
    for (int i = 0; i < ta[0].size(); i++)
        std::cout << "Zone " << char(i + 'A') << '\t';
    std::cout << '\n';

    for (int i = 0; i < ta.size(); i++) {
        std::cout << "Day " << (i + 1) << '\t';
        for (int j = 0; j < ta[i].size(); j++)
            std::cout << std::fixed << std::setprecision(2) << ta[i][j] << '\t';
        std::cout << '\n';
    }

    return;
}

void displayAverageTemperature(const temperature_array & ta) {
    for (int i = 0; i < ta.size(); i++)
        std::cout << "Average Temperature of Day " << (i + 1) << ": "
                  << std::fixed << std::setprecision(2)
                  << std::accumulate(ta[i].begin(), ta[i].end(), double(0)) /
                         ta[i].size()
                  << '\n';

    return;
}

void showMaxAndMinTemperature(const temperature_array & ta) {
    std::cout << "\tHottest\tColdest\n";
    for (int i = 0; i < ta.size(); i++)
        std::cout << "Day " << (i + 1) << '\t'
                  << (*std::max_element(ta[i].begin(), ta[i].end())) << '\t'
                  << (*std::min_element(ta[i].begin(), ta[i].end())) << '\n';

    return;
}

void displayWeeklyAverageTemperature(const temperature_array & ta) {
    for (int i = 0; i < ta[0].size(); i++) {
        double sum = static_cast<double>(0);
        for (int j = 0; j < ta.size(); j++)
            sum += ta[j][i];
        std::cout << "Weekly Average Temperature for Zone "
                  << static_cast<char>(i + 'A') << ": " << (sum / ta.size())
                  << '\n';
    }

    return;
}
