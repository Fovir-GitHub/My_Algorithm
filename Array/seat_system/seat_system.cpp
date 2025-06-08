#include <bitset>
#include <iostream>
#include <vector>

class SeatSystem {
private:
    enum { ROW = 10, COLUMN = 15 };
    enum QUERY_RESULT { AVAILABLE = 0, BOOKED = 1, OUT_OF_RANGE = -1 };

    std::vector<short> seat;

public:
    SeatSystem() : seat(std::vector<short>(ROW)) {}
    ~SeatSystem() {}

    void DisplaySeatingChart() const {
        for (const short & number : seat) {
            for (const char & bit : std::bitset<COLUMN>(number).to_string())
                std::cout << (bit == '1' ? 'B' : 'A') << ' ';
            std::cout << '\n';
        }

        return;
    }

    int GetSeatStatus(int row, int column) const {
        if (row < 0 || row >= ROW || column < 0 || column >= COLUMN)
            return QUERY_RESULT::OUT_OF_RANGE;

        return seat[row] & (1 << (COLUMN - column - 1))
                   ? QUERY_RESULT::BOOKED
                   : QUERY_RESULT::AVAILABLE;
    }

    void BookSeat(int row, int column) {
        int seat_status = GetSeatStatus(row, column);

        if (seat_status == QUERY_RESULT::OUT_OF_RANGE) {
            std::cout << "Out of range!\n";
            return;
        }

        if (seat_status) {
            std::cout << "Already booked!\n";
            return;
        }

        seat[row] |= (1 << (COLUMN - column - 1));

        return;
    }

    void CancelSeat(int row, int column) {
        if (GetSeatStatus(row, column) != QUERY_RESULT::BOOKED) {
            std::cout << "Error!\n";
            return;
        }

        seat[row] &= ~(1 << (COLUMN - column - 1));

        return;
    }

    void CheckAvailablility() const {
        int booked = 0;

        for (const short & number : seat)
            booked += std::bitset<COLUMN>(number).count();

        std::cout << "Booked: " << booked << '\n'
                  << "Available: " << (COLUMN * ROW - booked) << '\n';

        return;
    }

    int SearchConsecutiveSeats(int n) const {
        if (n < 0 || n > COLUMN)
            return QUERY_RESULT::OUT_OF_RANGE;

        short mask = (1 << (n + 1)) - 1;

        for (int i = 0; i < seat.size(); i++)
            for (int j = 0; j < COLUMN - n; j++)
                if (!(seat[i] & (mask << j)))
                    return i;

        return QUERY_RESULT::OUT_OF_RANGE;
    }
};

int main(void) {}