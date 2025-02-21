#include <gtest/gtest.h>
#include "sllist.h"
#include "stack.h"
TEST(SinglyLinkedListTest, PushFront) {
    SinglyLinkedList<int, std::string> list;
    list.push_front(10, "ten");
    ASSERT_EQ(list.size(), 1);
    list.push_front(10, "ten");
    list.push_front(20, "twenty");
    list.push_front(1, "one");
    ASSERT_EQ(list.size(), 4);
    ASSERT_EQ(list.get_first()->key, 1);
    ASSERT_EQ(list.get_first()->info, "one");

}
TEST(SinglyLinkedListTest, Copy){
    SinglyLinkedList<int, std::string> list;
    list.push_front(10, "ten");
    list.push_front(20, "twenty");
    list.push_front(1, "one");
    SinglyLinkedList<int, std::string> second;
    second.testCopy(list);
    ASSERT_TRUE(list==second);

}

TEST(SinglyLinkedListTest, PopFront) {
    SinglyLinkedList<int, std::string> list;
    list.push_front(10, "ten");

    // std::string info;
    ASSERT_TRUE(list.pop_front());
    ASSERT_EQ(list.size(), 0);
    list.push_front(1,"one");
    list.push_front(5,"five");
    list.push_front(7,"seven");
    ASSERT_TRUE(list.pop_front());
    ASSERT_TRUE(list.pop_front());
    ASSERT_TRUE(list.pop_front());
    ASSERT_FALSE(list.pop_front());



}
// TEST(SinglyLinkedListTest, PopBack){
//     SinglyLinkedList<int, std::string> list;
//     list.push_front(10, "ten");
//     ASSERT_TRUE(list.pop_back());
//     list.push_front(10, "ten");
//     list.push_front(20, "twenty");
//     list.push_front(1, "one");
//     ASSERT_TRUE(list.pop_back());
//     ASSERT_FALSE(list.exists_node(10, "ten"));

// }
TEST(SinglyLinkedListTest, IsEmpty){
    SinglyLinkedList<int, std::string> list;
    ASSERT_TRUE(list.is_Empty());
    list.push_front(10, "ten");
    ASSERT_FALSE(list.is_Empty());



}
TEST(SinglyLinkedListTest, Reverse){
    SinglyLinkedList<int, int> list;
    SinglyLinkedList<int, int> check;
    list.push_back(1,1);
    list.push_back(2,1);
    list.push_back(7,2);
    list.push_back(9,1);
    check.push_back(9,1);
    check.push_back(7,2);
    check.push_back(2,1);
    check.push_back(1,1);
    list.reverse_list();
    ASSERT_TRUE(list==check);

    SinglyLinkedList<int, int> second;
    second.reverse_list();
    ASSERT_TRUE(second.is_Empty());


}
TEST(SinglyLinkedListTest, CountKeys){
    SinglyLinkedList<int, int> list;
    list.push_back(1,1);
    list.push_back(2,1);
    list.push_back(1,1);
    list.push_back(9,1);
    int count=list.count_key(1);
    ASSERT_EQ(count,2);
    count=list.count_key(5);
    ASSERT_EQ(count,0);
   

    
}
TEST(SinglyLinkedListTest, CountInfo){
    SinglyLinkedList<int, int> list;
    list.push_back(1,1);
    list.push_back(2,1);
    list.push_back(1,1);
    list.push_back(9,2);
    int count=list.count_info(1);
    ASSERT_EQ(count,3);
    count=list.count_info(2);
    ASSERT_EQ(count,1);
    count=list.count_info(4);
    ASSERT_EQ(count,0);

    
}

TEST(SinglyLinkedListTest, Find){
    SinglyLinkedList<int, std::string> list;
    list.push_front(10, "ten");
    list.push_front(20, "twenty");
    list.push_front(1, "one");
    ASSERT_TRUE(list.find_info("twenty")!=nullptr);
    ASSERT_TRUE(list.find_info("three")==nullptr);
    ASSERT_TRUE(list.find_key(10)!=nullptr);
    ASSERT_TRUE(list.find_key(11)==nullptr);

}

TEST(SinglyLinkedListTest, PopEmpty) {
    SinglyLinkedList<int, std::string> list;
   
    ASSERT_FALSE(list.pop_front());
}

TEST(SinglyLinkedListTest, Clear) {
    SinglyLinkedList<int, std::string> list;
    list.push_back(1, "one");
    list.push_back(2, "two");
    list.push_back(3, "three");

    list.clear();

    EXPECT_TRUE(list.is_Empty());
    EXPECT_EQ(list.size(), 0);
    ASSERT_FALSE(list.get_last());

}

TEST(SinglyLinkedListTest, InsertAfter) {
    SinglyLinkedList<int, std::string> list;
    bool inserted = list.insert_After(1, 2, "two");
    EXPECT_FALSE(inserted);
    list.push_back(1, "one");
    list.push_back(2, "two");

    inserted = list.insert_After(2, 3, "three");
    EXPECT_TRUE(inserted);
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.get(3), "three");
    EXPECT_EQ(list.get_last()->key, 3);

    inserted = list.insert_After(17, 4, "four");  
    EXPECT_FALSE(inserted);
    EXPECT_EQ(list.size(), 3); 
}


TEST(SinglyLinkedListTest, Get) {
    SinglyLinkedList<int, std::string> list;
    list.push_back(1, "one");
    list.push_back(2, "two");
    list.push_back(3, "three");
    list.push_back(2, "two");

    EXPECT_EQ(list.get(1), "one");
    EXPECT_EQ(list.get(2, 1), "two");
    EXPECT_EQ(list.get(2, 2), "two");
    EXPECT_EQ(list.get(3), "three");

    EXPECT_THROW(list.get(4), std::out_of_range); 
}

TEST(SinglyLinkedListTest, Front) {
    SinglyLinkedList<int, std::string> list;
    list.push_back(1, "one");
    list.front(1, "one");
    ASSERT_TRUE(list.front(1,"one"));
    ASSERT_FALSE(list.front(2,"two"));

    
}
TEST(SinglyLinkedListTest,RemoveAll){
    SinglyLinkedList<int, std::string> list;
    list.push_back(1, "one");
    list.push_back(2, "two");
    list.push_back(3, "three");
    list.push_back(2, "two_two");
    list.remove_all_key(2);
    ASSERT_FALSE(list.info_exists("two_two"));
    EXPECT_EQ(list.size(),2);
    ASSERT_FALSE(list.key_exists(2));
    

}
TEST(SinglyLinkedListTest, Exists){
    SinglyLinkedList<int, std::string> list;
    ASSERT_FALSE(list.info_exists("three"));
    list.push_back(1, "one");
    list.push_back(2, "two");
    ASSERT_TRUE(list.info_exists("one"));
    ASSERT_TRUE(list.key_exists(1));
    ASSERT_TRUE(list.key_exists(1));
    ASSERT_FALSE(list.info_exists("three"));
    ASSERT_FALSE(list.key_exists(3));


}
TEST(SinglyLinkedListTest, ExistsNode){
    SinglyLinkedList<int, std::string> list;
    ASSERT_FALSE( list.exists_node(1,"one")); 
    list.push_back(1, "one");
    list.push_back(2, "two");
    ASSERT_TRUE( list.exists_node(1,"one"));
    ASSERT_FALSE( list.exists_node(1,"two"));



}
TEST(SinglyLinkedListTest, OperatorEqual){
    SinglyLinkedList<int, int> seq1;
    SinglyLinkedList<int, int> seq2;
    SinglyLinkedList<int, int> seq;
    for (int i = 0; i <= 5; ++i) {
        seq1.push_back(i, i);
        seq2.push_back(i, i);}
    ASSERT_TRUE(seq1==seq2);
   
}
TEST(SinglyLinkedListTest, OperatorNotEqual){
    SinglyLinkedList<int, int> seq1;
    SinglyLinkedList<int, int> seq2;
    SinglyLinkedList<int, int> seq;
    for (int i = 0; i <= 5; ++i) {
        seq1.push_back(i, i);
        seq2.push_back(i, i);}
    ASSERT_FALSE(seq1!=seq2);}

TEST(ConcatenateTest, VersionOne){
    SinglyLinkedList<int, int> seq1;
    SinglyLinkedList<int, int> seq2;
    SinglyLinkedList<int, int> seq;
    SinglyLinkedList<int, int> result;

    for (int i = 0; i <= 5; ++i) {
        seq1.push_back(i, i);
        seq2.push_back(i+20,i+20);
    }
    concatenate(seq1, seq2, 2, 3, result);
    // int  correct[]={0,1,20,21,22,2,3,23,24,25,4,5};
    
    seq.push_back(0, 0);
    seq.push_back(1, 1);

    seq.push_back(20, 20);
    seq.push_back(21, 21);
    seq.push_back(22, 22);
    seq.push_back(2, 2);
    seq.push_back(3, 3);
    seq.push_back(23, 23);
    seq.push_back(24, 24);
    seq.push_back(25, 25);

    seq.push_back(4, 4);
    seq.push_back(5, 5);

    ASSERT_TRUE(seq==result);
}

TEST(ConcatenateTest, VersionTwo){
    SinglyLinkedList<int, int> seq1;
    SinglyLinkedList<int, int> seq2;
    SinglyLinkedList<int, int> seq;
    SinglyLinkedList<int, int> res;



    for (int i = 0; i <= 2; ++i) {
        seq1.push_back(i, i);}
    for (int i = 5; i <= 10; ++i) {
        seq2.push_back(i, i);}
    concatenate(seq1, seq2, 2, 3, seq); //{0,1,2} {5,6,7,8,9,10}
    // int  correct[]={0,1,5,6,7,2,8,9,10};

    res.push_back(0, 0);
    res.push_back(1, 1);
    res.push_back(5, 5);
    res.push_back(6, 6);
    res.push_back(7, 7);
    res.push_back(2, 2);
    res.push_back(8, 8);
    res.push_back(9, 9);
    res.push_back(10, 10);

    ASSERT_TRUE(res==seq);
}

// }
TEST(ConcatenateTest, VersionThree){
    SinglyLinkedList<int, int> seq1;
    SinglyLinkedList<int, int> seq2;
    SinglyLinkedList<int, int> seq;
    
    for (int i = 0; i <= 2; ++i) {
        seq1.push_back(i, i);}
    for (int i = 5; i <= 10; ++i) {
        seq2.push_back(i, i);}
    concatenate(seq1, seq2, 0, 0, seq);

    ASSERT_TRUE(seq.is_Empty());
    ASSERT_TRUE(seq1.is_Empty());
    ASSERT_TRUE(seq2.is_Empty());
}





TEST(STACK,PUSH){
    Stack<int, std::string> stack;
    stack.push(1, "one");
    stack.push(2,"two");
    EXPECT_EQ(stack.size(), 2);
    stack.push(3, "three");
    EXPECT_EQ(stack.size(), 3);


}
TEST(STACK,POP){
    Stack<int, std::string> stack;
    ASSERT_FALSE(stack.pop());
    stack.push(1, "one");
    stack.push(2,"two");
    ASSERT_TRUE(stack.pop());
    ASSERT_TRUE(stack.pop());
    ASSERT_FALSE(stack.pop());
    Stack<int, std::string> stack_second;
    ASSERT_FALSE(stack.pop());
    ASSERT_TRUE(stack.empty()); 



}
TEST(STACK,FIRST){
    Stack<int, std::string> stack;
    stack.push(1, "one");
    stack.push(2,"two");
    ASSERT_EQ(stack.first(),"one");
    stack.pop();
    ASSERT_EQ(stack.first(),"two");

}
TEST(STACK,SIZE){
     Stack<int, std::string> stack;
     ASSERT_EQ(stack.size(),0);
    stack.push(1, "one");
    stack.push(2,"two");
    stack.push(3, "three");
    stack.push(2,"two");
    ASSERT_EQ(stack.size(),4);


}
TEST(STACK,EMPTY){
    Stack<int, std::string> stack;
    EXPECT_TRUE(stack.empty());
    stack.push(1, "one");
    EXPECT_FALSE(stack.empty());
}