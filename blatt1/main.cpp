# include <iostream>
# include <vector>
# include <string>
using namespace std;

int main () {
    cout << "Hello , World !" << endl ;


    vector<string> team = { "Paddy", "Linda" }; // Vektor mit Startwerten
    team.__emplace_back ("Steve"); // weiteren Wert zum Vektor hinzufügen
    team.__emplace_back ("Flo"); // ...
    int teamSize = team.size ();
    cout << "Wir sind : " << team[0] << "..." << team[teamSize-1] << endl ;
    return 0;
}