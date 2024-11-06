#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> scores; // 성적을 저장할 벡터
    int score;
    cout << "성적을 입력하시오(종료는 -1) : ";

    // 사용자로부터 성적을 입력받아 벡터에 저장
    while (cin >> score && score != -1)
    {
        scores.push_back(score);
        cout << "성적을 입력하시오(종료는 -1) : ";
    }

    // 성적 합계를 구하고 평균을 계산
    int sum = 0;
    for (int s : scores)
    {
        sum += s;
    }

    double average = (scores.empty()) ? 0 : static_cast<double>(sum) / scores.size();

    cout << "성적 평균=" << average << endl;

    return 0;
}
