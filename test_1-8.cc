 #include <iostream>
 
 using namespace std;

 int main() {
     // todo
     return 0; 
 }

 const char* msg_to_usr(int num_tries) {
     const int rsp_cnt = 5;
     static const char* usr_msgs[rsp_cnt] = {
         "go on, make a guess.",
         "oops! nice guess but not quite it.",
         "hmm, sorry. wrong a second time.",
         "this is harder than it looks, no?",
         "it's must be getting pretty frustrating by now!"
     };
     if (num_tries < 0) {
         num_tries = 0;
     } else if (num_tries >= rsp_cnt) {
         num_tries = rsp_cnt - 1;
     }
     return usr_msgs[num_tries];
 }