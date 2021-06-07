/**
 * Demo file for the exercise on binary tree
 *
 * @author Erel Segal-Halevi
 * @since 2021-04
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "BinaryTree.hpp"
using namespace ariel;

int main() {
  BinaryTree<int> tree_of_ints;
   tree_of_ints.add_root(6)
   .add_left(6, 2).add_left(2, 1);//.add_right(2,4).add_left(4,3).add_right(4,5).add_right(6,7).add_right(7,9).add_left(9,8);     // Now 9 is the left child of 1
  //.add_left(9, 4)     // Now 4 is the left child of 9
   // .add_left(4, 5) 
   //.add_left(1, 2).add_right(2, 32)   // Now 5 is the right child of 9
   //.add_right(1, 3)  
   //.add_right(3, 23)     // Now 3 is the right child of 1
  
  //.add_right(32, 121);     // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)

   //cout << tree_of_ints << endl;  /* Prints the tree in a reasonable format. For example:
  //       1
  //       |--------|
  //       2        3
  //       |---|
  //       4   5
  // */
//  cout << "\n pre_order is: "<< endl;
//   for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
//     cout << (*it) << " " ;
//   }  // prints: 1 2 4 5 3
//   cout << "\n in_order is: "<< endl;
//   for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
//     cout << (*it) << " " ;
//   }  // prints: 4 2 5 1 3 
//    cout << "\n post_order is: "<< endl;

//   for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
//     cout << (*it) << " " ;
//   }  // prints: 4 5 2 3 1
//   cout << "\n in_order_normal is: "<< endl;

//   for (int element: tree_of_ints) {  // this should work like inorder
//     cout << element << " " ;
//   }  // prints: 4 2 5 1 3 


  // The same should work with other types, e.g. with strings:
  
  BinaryTree<string> tree_of_strings;
  tree_of_strings.add_root("1")     
  .add_left("1", "9")      // Now 9 is the left child of 1
  .add_left("9", "4")      // Now 4 is the left child of 9
  .add_right("9", "5")     // Now 5 is the right child of 9
  .add_right("1", "3")     // Now 3 is the right child of 1
  .add_left("1", "2");     // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
   cout << tree_of_strings << endl; 
// cout << "\n preorder is: "<< endl;
  // for (auto it=tree_of_strings.begin_preorder(); it!=tree_of_strings.end_preorder(); ++it) {
  //   cout << (*it) << " " ;
  // }  // prints: 1 2 4 5 3
  // cout << "\n inorder is: "<< endl;
//   for (auto it=tree_of_strings.begin_inorder(); it!=tree_of_strings.end_inorder(); ++it) {
//     cout << (*it) << " " ;
//   }  // prints: 4 2 5 1 3 
//   cout << "\n postorder is: "<< endl;
//   for (auto it=tree_of_strings.begin_postorder(); it!=tree_of_strings.end_postorder(); ++it) {
//     cout << (*it) << " " ;
//   }  // prints: 4 5 2 3 1

//   cout << "\n inorder_normal is: "<< endl;
//   for (const string& element: tree_of_strings) {  // this should work like inorder
//     cout << element << " " ;
//   }   // prints: 4 2 5 1 3 

// BinaryTree<int> tree_of_ints1;
//   tree_of_ints1.add_root(9)
//   .add_left(9, 8).add_left(8, 7);




// cout << "\ntree_of_ints1: " <<endl;
// for (auto it=tree_of_ints1.begin_inorder(); it!=tree_of_ints1.end_inorder(); ++it) {
//      cout << (*it) << " " ;
//    } 
// cout << "\ntree_of_ints: " <<endl;
//    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
//      cout << (*it) << " " ;
//    } 

//  cout << " \n after = is :=====================================:     "<< endl;


//  tree_of_ints1 =  tree_of_ints;



// cout << "\ntree_of_ints1: " <<endl;
// for (auto it=tree_of_ints1.begin_inorder(); it!=tree_of_ints1.end_inorder(); ++it) {
//      cout << (*it) << " " ;
//    } 
// cout << "\ntree_of_ints: " <<endl;
//    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
//      cout << (*it) << " " ;
//    } 

 }