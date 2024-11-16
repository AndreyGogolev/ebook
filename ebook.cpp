#include <iostream>
#include <vector>
#include <iomanip>

class Libruary{
public:
    Libruary():member_with_his_page_(std::vector<int>(100001,0)),
               page_with_member_count_(std::vector<int>(1001,0)),
               members_count_(0){};
    void AddMember(int member, int page){
        if (member_with_his_page_.at(member)){
            --page_with_member_count_[member_with_his_page_[member]];
        } else{
            ++members_count_;
        }
        member_with_his_page_[member] = page;
        ++page_with_member_count_[page];
    };
    double GetCheerRating(int member){
        double rating = 0.0;
        if (!member_with_his_page_.at(member)){
            return 0.0;
        }
        if (members_count_ == 1){
            return 1.0;
        }
        for (int page = 0; page < member_with_his_page_[member]; ++page){
                rating += (page_with_member_count_[page] * 1.0);
            }
        return rating / (members_count_ - 1);
    };

private:
    std::vector<int> member_with_his_page_;
    std::vector<int> page_with_member_count_;
    int members_count_;
};
int main(void){
    int query_num;
    std::cin >> query_num;
    std::string s;

    Libruary libr;
    for (auto i = 0; i < query_num; ++i){
        std::string a;
        std::cin >> a;
        if (a == "READ"){
            int member, page;
            std::cin >> member >> page;
            libr.AddMember(member, page);
        }else if(a == "CHEER") {
            int member;
            std::cin >> member;
            std::cout << std::setprecision(6) << libr.GetCheerRating(member) << std::endl;
        }
    }
}