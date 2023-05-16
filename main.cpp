#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Team {
    string team;
    int wins, ties, loses, goals, lost;
public:
    Team(string n, int w, int r, int l, int g, int l1) : name(n), wins(w), ties(r), loses(l), goals(g), lost(l1) {}
    int points() const { return wins*3 + ties; }
    string toString() const {
        string wynik = name + "\t";
        wynik += "\033[32m" + to_string(wins) + "\033[0m\t";
        wynik += to_string(ties) + "\t";
        wynik += "\033[31m" + to_string(loses) + "\033[0m\t";
        wynik += "\033[32m" + to_string(goals) + "\033[0m\t";
        wynik += "\033[31m" + to_string(lost) + "\033[0m\n";
        return wynik;
    }
    friend bool operator<(const Team& d1, const Team& d2) {
        if (d1.points() != d2.points()){
            return d1.points() > d2.points();
        }
        if (d1.wins != d2.wins){
            return d1.wins > d2.wins;
        }
        if (d1.loses != d2.loses){
            return d1.loses < d2.loses;
        }
        if (d1.goals != d2.goals){
            return d1.goals > d2.goals;
        }
        return d1.lost < d2.lost;
    }
    friend ostream& operator<<(ostream& os, const Team& d) {
        os << d.toString();
        return os;
    }
};

int main() {
    vector<Team> league = {
        Team("Real Madryt", 20, 6, 4, 65, 25),
        Team("Barcelona", 18, 8, 4, 60, 30),
        Team("Chelsea", 18, 6, 6, 55, 25),
        Team("PSG", 16, 8, 6, 45, 30),
        Team("Pogon Szczecin", 14, 10, 6, 50, 35),
        Team("Legia Warszawa", 12, 10, 8, 40, 35),
        Team("Juventus", 12, 9, 9, 45, 40),
        Team("Lech Poznan", 11, 12, 7, 40, 30),
        Team("Menchester City", 10, 10, 10, 35, 35),
        Team("Liverpool", 10, 8, 12, 35, 40)
    };

    sort(league.begin(), league.end());

    for (auto team : league) {
        cout << team;
    }

    return 0;

};