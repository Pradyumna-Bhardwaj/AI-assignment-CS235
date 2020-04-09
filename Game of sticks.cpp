#include <bits/stdc++.h>
#include <memory>
using namespace std;

unique_ptr<int[]> minMax(int N, int player, int alpha, int beta)
{
    auto tempArr = make_unique<int[]>(4);
    if (N == 1 && player == 1){
        tempArr[0] = 1; tempArr[1] = 1; tempArr[2] = -1; tempArr[3] = beta;
        return tempArr;
    }
    else if (N == 1 && player == 2){
        tempArr[0] = 1; tempArr[1] = 2; tempArr[2] = alpha; tempArr[3] = 1;
        return tempArr;
    }
    else{
        int i; //sticks
        for (int j = 1; j <= 3; j++){
            i = 4 - j;
            if (N > i){
                if (player == 1){
                    auto arr = minMax(N - i, 2, alpha, beta);
                    if (arr[2] < arr[3]) alpha = arr[3];
                    if (alpha == 1 || alpha > beta) break;
                }
                else{
                    auto arr = minMax(N - i, 1, alpha, beta);
                    if (arr[2] < arr[3]) beta = arr[2];
                    if (beta == -1 || alpha > beta) break;
                }
            }
        }
        tempArr[0] = i; tempArr[1] = player; tempArr[2] = alpha; tempArr[3] = beta;
        return tempArr;
    }
}

void HUMANvsAI(int N){
    cout << "NOTE: You should pick  1 to 3 sticks\n\n";
    cout << "\nChoosing randomly who will get first turn\n";
    int pick, winner = (rand() % 2) + 1;
    if (winner == 1) cout << "Winner is AI!\n";
    else cout << "You won the toss!\n";
    
    while (1){
        if (winner == 1){
            auto arr = minMax(N, 1, INT_MIN, INT_MAX);
            cout << "AI picks " << arr[0] << " sticks.\n";
            N -= arr[0];
            if (N == 0){
                cout << "\nYou Won the game.\nAI Lost the game.\n";
                break;
            }
            cout << "->Remaining Sticks - " << N << "<-\n";
            cout << "How many stick you want to pick? ";
            do{
                cin >> pick;
                if (pick < 1 || pick > 3)
                    cout << "Enter valid value again : ";
            } while (pick <= N && (pick < 1 || pick > 3));
            N -= pick;
            if (N == 0){
                cout << "\nYou lost the game.\nAI won the game.\n";
                break;
            }
            cout << "->Remaining Sticks - " << N << "<-\n";
        }
        else{
            cout << "How many stick you want to pick? ";
            do{
                cin >> pick;
                if (pick < 1 || pick > 3)
                    cout << "Enter valid value again : ";
            } while (pick <= N && (pick < 1 || pick > 3));
            N -= pick;
            if (N == 0){
                cout << "\nYou lost the game.\nAI won the game.\n";
                break;
            }
            cout << "->Remaining Sticks - " << N << "<-\n";
            auto arr = minMax(N, 1, INT_MIN, INT_MAX);
            cout << "AI picks: " << arr[0] << " sticks.\n";
            N -= arr[0];
            if (N == 0){
                cout << "\nYou Won the game.\nAI Lost the game.\n";
                break;
            }
            cout << "->Remaining Sticks - " << N << "<-\n";
        }
    }
}

void AIvsAI(int N)
{
    cout << "\nChoosing randomly who will get first turn\n";
    int pick, loser, winner = (rand() % 2) + 1;
    if (winner == 1){
        cout << "AI 1 won the toss!\n";
        loser = 2;
    }
    else{
        cout << "AI 2 won the toss!\n";
        loser = 1;
    }
    while (1)
    {
        auto arr = minMax(N, 1, INT_MIN, INT_MAX);
        cout << "AI " << winner << " picks: " << arr[0] << " sticks.\n";
        N -= arr[0];
        if (N == 0){
            cout << "\nAI " << loser << " Won the game.\nAI " << winner << " Lost the game.\n";
            break;
        }
        cout << "->Remaining Sticks - " << N << "<-\n";
        arr = minMax(N, 1, INT_MIN, INT_MAX);
        cout << "AI " << loser << " picks: " << arr[0] << " sticks.\n";
        N -= arr[0];
        if (N == 0){
            cout << "\nAI " << loser << " Won the game.\nAI " << winner << " Lost the game.\n";
            break;
        }
        cout << "->Remaining Sticks - " << N << "<-\n";
    }
}

int main()
{
    int N, choice;
    srand(time(NULL));
    cout << "1.)Human v/s AI\n";
    cout << "2.)AI v/s AI\n";
    cout << "Enter the choice : ";
    cin >> choice;
    cout << "Enter the number of sticks in game : ";
    cin >> N;
    if(choice == 1) HUMANvsAI(N);
    else if(choice ==2) AIvsAI(N);
    return 0;
}

