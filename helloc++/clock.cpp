// #include <iostream>
// #include <thread>
// #include <chrono>
// using namespace std;

// class Clock 
// {
// private:
//     int hour, min, sec;
        
// public:
//     void getdata()
//     {
//         int h, m, s;
//         cout << "Enter hours, minutes and seconds respectively:" << endl;
//         cin >> h >> m >> s;

//         if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60))
//         {
//             settime(h, m, s);
//         }
//         else
//         {
//             cout << "Invalid Input!" << endl;
//         }
//     }

//     void settime(int h, int m, int s)
//     {
//         hour = h;
//         min = m;
//         sec = s;
//     }

//     void display()
//     {
//         // Display with leading zeros
//         cout << (hour < 10 ? "0" : "") << hour << ":"
//              << (min < 10 ? "0" : "") << min << ":"
//              << (sec < 10 ? "0" : "") << sec << endl;
//     }

//     void tick()
//     {
//         sec++;
//         if (sec == 60)
//         {
//             sec = 0;
//             min++;
//             if (min == 60)
//             {
//                 min = 0;
//                 hour++;
//                 if (hour == 24)
//                 {
//                     hour = 0;
//                 }
//             }
//         }
//     }
// };

// int main()
// {
//     Clock tt;
//     tt.getdata();

//     while (true)
//     {
//         system("cls"); // Clears screen on Windows (optional)
//         tt.display();
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//         tt.tick();
//     }

//     return 0;
// }




//compiler le support garena
    