#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // 영화 정보를 저장할 벡터 (이름, 평점)
    vector<pair<string, double>> movies;

    // 영화 정보 입력
    movies.push_back(make_pair("titinic", 9.9));
    movies.push_back(make_pair("gone with the wind", 9.6));
    movies.push_back(make_pair("terminator", 9.7));

    // 영화 정보 출력
    for (const auto &movie : movies)
    {
        cout << movie.first << ": " << movie.second << endl;
    }

    return 0;
}
