#include <iostream>
#include <vector>

template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1, InIter2 first2, InIter2 last2, OutIter out){
    auto curr1 = first1;
    auto curr2 = first2;
    if(first1 == last1){
        return out;    
    }
    auto temp = *curr1;
    bool flag = false;
    while(curr1 != last1 || curr2 != last2){
        if(curr1 == last1){
            break;
        } else if (curr2 == last2){
            *out = *curr1;
            curr1++;
            out++;
        } else {
            if(*curr1 > *curr2){
                //std::cout << "curr1: " << *curr1 << ", curr2: " << *curr2 << " *curr1 > *curr2 -> step forward on curr2" << '\n';
                curr2++;
            } else if(*curr1 < *curr2){
                //std::cout << "curr1: " << *curr1 << ", curr2: " << *curr2 << " *curr1 < *curr2 -> step forward on curr1 anyway and then:" << '\n';
                if(flag){
                    //std::cout << "flag is true" << '\n';
                    if(*curr1 == temp){
                        //std::cout << "next item on *curr1 is equal to prev -> adding it to out" << '\n';
                        *out = temp;
                        out++;
                        std::cout << temp << '\n';
                    }
                    else{
                        //std::cout << "next item on *curr1 is not equal to prev -> flag = false" << '\n';
                        flag = false;
                        curr1--;
                    }
                } else {
                    //std::cout << "flag is false -> adding curr item to out and step forward on curr1" << '\n';
                    *out = *curr1;
                    out++;
                }
                curr1++;
            } else if (*curr1 == *curr2){
                //std::cout << "*curr1 == *curr2-> flag = true, step forward on both" << '\n';
                temp = *curr1;
                flag = true;
                curr1++;
                curr2++;
            }
            //std::cout << "---------------------------------\n";
        }


        
    }
    return out;
}


int main(){
    std::vector<int> v1;
    std::vector<int> v2 = {1,1,2,3,5,5,6,10,11,12};
    std::vector<int> v3(v1.size());
    auto out = SetDifference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for(auto& item: v3){
        std::cout << item << ' ';
    }
    std::cout << '\n';
    for(;out != v3.end(); ++out){
        std::cout << *out << ' ';
    }
    std::cout << '\n';

}