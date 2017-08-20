/*
    Mainly two implementation
        while(start <= end)
            where start = mid+1,or end = mid-1          ----> used for searching the element
        OR
        while(start < end)
            where start =mid,or end = mid

    very general type of ques on binary search:
        1.Segment tree based 
        2.Rotated array
*/



/*
    binary search with duplicate is not possible 13 15 15 15 17 2 2 9 ---> will produce 15 as min element 
        if completely relying on binary search
    

    15 16 19 19 19 20 21 21 23 1 1 2 2 2 3 4 5
    left = 0,right = 16

*/  

