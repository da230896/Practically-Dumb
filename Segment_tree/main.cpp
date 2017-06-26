#include <iostream>
#include "SegmentTreeLazy.h"
using namespace std;

int main()
{
    SegmentTree root;
    int arr[] = {10,11,9,1,2,0,12};
    root.build(arr,0,6);

    cout << root.query(4,6) << '\n';

    root.update(5,11);

    cout << root.query(0,6) << '\n';    

    return 0;
}