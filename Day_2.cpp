//#include <fstream>
//#include <iostream>
//#include <vector>
//#include <string>
///*
//
//int score(char hand)
//{
//    if(hand == 'X' || hand == 'A'){
//        return 1;
//    }
//    if(hand == 'Y' || hand == 'B'){
//        return 2;
//    }
//    if(hand == 'Z' || hand == 'C'){
//        return 3;
//    }
//    return 0;
//}
//*/
//
//
//int score(char hand)
//{
//    if(hand == 'X' || hand == 'A'){
//        return 1;
//    }
//    if(hand == 'Y' || hand == 'B'){
//        return 2;
//    }
//    if(hand == 'Z' || hand == 'C'){
//        return 3;
//    }
//    return 0;
//}
//
//int win(int opponent, int player){
//
//    if ( (opponent == 1)) return 0;
//    if ( (opponent == 2)) return 3;
//    if ( (opponent == 2)) return 6;
//
//    if ( (player == 2) && (opponent == 1)) return 6;
//    if ( (player == 3) && (opponent == 2)) return 6;
//    if ( (player == 1) && (opponent == 3)) return 6;
//
//    if ( (player == 1) && (opponent == 2)) return 0;
//    if ( (player == 2) && (opponent == 3)) return 0;
//    if ( (player == 3) && (opponent == 1)) return 0;
//}
///*
//int strategy(char opponent){
//    if(hand == 'X' ){
//        return 1;
//    }
//    if(hand == 'Y' ){
//        return 2;
//    }
//    if(hand == 'Z' ){
//        return 3;
//    }
//    return 0;
//}
//*/
//int win2(int opponent, int player){
//
//    if ( player == opponent) return 3;
//
//    if ( (player == 2) && (opponent == 1)) return 6;
//    if ( (player == 3) && (opponent == 2)) return 6;
//    if ( (player == 1) && (opponent == 3)) return 6;
//
//    if ( (player == 1) && (opponent == 2)) return 0;
//    if ( (player == 2) && (opponent == 3)) return 0;
//    if ( (player == 3) && (opponent == 1)) return 0;
//    return -1;
//}
//
//
//int test2(void){
//
//    std::ifstream File ("input_2");
//    std::string line;
//    int sum = 0;
//    int player = 0;
//    int opponent = 0;
//    int result = 0;
//    int game = 0;
//    while (std::getline(File, line))
//    {
//        opponent = score(line[0]);
//        result = score(line[2]);
//
//        if ( (result == 3))
//        {
//            game = 0;
//            if ( (opponent == 1)) player = 2;
//            if ( (opponent == 2)) player = 3;
//            if ( (opponent == 3)) player = 1;
//        }
//        if ( (result == 2))
//        {
//            player = opponent;
//            game = 3;
//        }
//        if ( (result == 1))
//        {
//            if ( (opponent == 2)) player = 1;
//            if ( (opponent == 3)) player = 2;
//            if ( (opponent == 1)) player = 3;
//            game = 6;
//            //player = (opponent ) % 3 +1;
//        }
//
//        game = win2(opponent, player);
//
//        sum += player + game;
//        std::cout << line <<  ", "<<opponent<< ", "<<player<<   "+ " << game<< ": " << sum <<std::endl;
//    }
//}
