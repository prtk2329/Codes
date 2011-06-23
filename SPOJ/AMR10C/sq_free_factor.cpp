/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : sq_free_factor.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Wednesday 22 June 2011 07:13:29 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iomanip>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 0
#define MAX_SIZE 1000000

int store_divisors(int *a, int limit){
    int _size = 0, k;
    a[_size++] = 2;
    for(int j = 3; j < limit; j+=2){
      for(k = 0; k < _size; k++){
         if(j%a[k] == 0) break;
         if(a[k] > sqrt(j)) {k = _size; break;}
      }
      if(k == _size){ a[_size++] = j; }
    }
    return _size;   
}

void print_a(int *a, int count_d){
   for(int i = 0; i < count_d; i++){
      std::cout << a[i] << std::endl;
   }
}

int do_the_deed(int num, int *a, int count_d){
    int i = 0, max=0, curr_max=0;
    int final = int(ceil(sqrt(num)));
    if(DEBUG) std::cout << "limit=>" << final << std::endl;
    while(num != 1){
       if(DEBUG) std::cout << "p loop->" << a[i] << " num->"<< num << std::endl;
       if(num%a[i] == 0){
           num = num/a[i]; curr_max++;
       }else{
         if(curr_max>max){ max = curr_max; }
         curr_max = 0;
         i++;
       }
    }
    if(curr_max>max){ max = curr_max; }
    return max;
}

int main(){

    int limit = int(ceil(sqrt(MAX_SIZE)));
    if(DEBUG) std::cout << "limit=>" << limit << std::endl;
    int *ARR  = (int*)malloc(limit*sizeof(int));
    int count_d = store_divisors(ARR, limit);

    int num_test_cases, A, _ret;
    scanf("%d",&num_test_cases);
    if(DEBUG) std::cout << "num=>" << num_test_cases << std::endl;
    for(int i = 0; i < num_test_cases; i++){
       scanf("%d",&A);
       if(DEBUG) std::cout << "input=>" << A << std::endl;
       _ret = do_the_deed(A, ARR, count_d);
       printf("%d\n",_ret);
    }
}
