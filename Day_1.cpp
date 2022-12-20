//#include <fstream>
//#include <iostream>
//#include <vector>
//#include <string>
//int test(void){
//
//    std::ifstream File ("input_1");
//    std::vector<std::vector<int>> elves;
//    std::string line;
//    long max_cal_1=0,max_cal_2=0,max_cal_3 = 0;
//    long curr_cal = 0;
//
//    while (std::getline(File, line))
//    {
//        if(line.empty()){
//            if (curr_cal > max_cal_1)
//            {
//                max_cal_3 = max_cal_2 ;
//                max_cal_2 = max_cal_1 ;
//                max_cal_1 = curr_cal;
//            }
//            else if (curr_cal > max_cal_2)
//            {
//                max_cal_3 = max_cal_2 ;
//                max_cal_2 = curr_cal ;
//            }
//            else if (curr_cal > max_cal_3)
//            {
//                max_cal_3 = curr_cal ;
//            }
//            curr_cal = 0;
//        }
//        else {
//
//            curr_cal += std::stoul(line);
//            std::cout << curr_cal  << " " << max_cal_1<< " " << max_cal_2 << " " << max_cal_3<< "\n";
//
//        }
//
//    }
//    if (curr_cal > max_cal_1)
//    {
//        max_cal_3 = max_cal_2 ;
//        max_cal_2 = max_cal_1 ;
//        max_cal_1 = curr_cal;
//    }
//    else if (curr_cal > max_cal_2)
//    {
//        max_cal_3 = max_cal_2 ;
//        max_cal_2 = curr_cal ;
//    }
//    else if (curr_cal > max_cal_3)
//    {
//        max_cal_3 = curr_cal ;
//    }
//
//    std::cout <<"\n" << curr_cal << ", "<< max_cal_1<< ", " << max_cal_2 << ", " << max_cal_3;
//    std::cout <<"\n" << max_cal_1 + max_cal_2 +max_cal_3;
//    return 0;
//}
