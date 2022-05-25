// #include <iostream>

// using namespace std;

// int main()
// {
//     int input  =- 1;

//     while(input != 1 && input != 2){
// 		cout << "Кто ходит первый?" << endl;
// 		cout << "1 - Ферзь" << endl;
// 		cout << "2 - Конь" << endl;
// 		cin >> input;
//     }
    
// 	int a, b, c, d, e, f;
    
// 	string firstFigure = input == 1 ? "Ферзь" : "Конь";
//     string secondFigure = input != 1 ? "Конь" : "Ферзь";

//     cout << "Введите координаты " << firstFigure << endl;
//     cin >> a >> b;
//     cout << "Введите координаты, куда пойдёт" << firstFigure << endl;
//     cin >> e >> f;

//     if(input == 1) {
//         if(!(a == e || b == f || abs(a - e) == abs(b - f))){
//             cout << "Ферзь не может так ходить" << endl;
//             return -1;

//         }
//     }
    
// 	if(input == 2) {
//         if(!((a + 2 == e && b + 1 == f) ||
//          (a + 2 == e && b - 1 == f) ||
//          (a - 2 == e && b + 1 == f) ||
//          (a - 2 == e && b - 1 == f) ||

//          (a + 1 == e && b + 2 == f) ||
//          (a + 1 == e && b - 2 == f) ||
//          (a - 1 == e && b + 2 == f) ||
//          (a - 1 == e && b - 2 == f))) {
//             cout << "Ферзь не может так двигаться" << endl;
//             return -1;
//          }

//     }
//     cout << "Введите координаты" << secondFigure << endl;
//     cin >> c >> d;

//     // Конь
//     if (input == 1){
//             if((c + 2 == e && d + 1 == f) ||
//          (c + 2 == e && d - 1 == f) ||
//          (c - 2 == e && d + 1 == f) ||
//          (c - 2 == e && d - 1 == f) ||

//          (c + 1 == e && d + 2 == f) ||
//          (c + 1 == e && d - 2 == f) ||
//          (c - 1 == e && d + 2 == f) ||
//          (c - 1 == e && d - 2 == f)){
//              cout << "Конь побил ферзя" << endl;
//          }
//          else{
//              cout << "Конь не побил ферзя" << endl;

//          }
//         }

//     // Ферзь
//     else{

//             if(c == e || d == f || abs(c - e) == abs(d - f)){
//                 cout << "Ферзь не побил коня" << endl;
//             }
//             else{

//                 cout << "Ферьз не побил коня" << endl;
//             }
//     }

// }