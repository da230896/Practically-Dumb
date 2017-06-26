/*
    range update is lazy
    point update is okay
*/

using namespace std;

class SegmentTree{
    int sum,l,r,lazyVal;
    SegmentTree *left,*right;
public:
    SegmentTree()
    {
        lazyVal = sum = 0,l = -1,r = -1;
        left = right = 0x0;
    }
    bool getLazyMarker()
    {
        return lazyVal;
    }
    void setLazyMarker(int Val)
    {
        lazyVal += Val;
    }
    int getSum()
    {
        return sum;
    }
    void build(int *arr,int l = 0,int r = 0)
    {
        this->l = l,this->r = r;
        if(l == r)
        {
            sum = arr[l];
            return;
        }
        int mid = (l+r)/2;
        if(left == 0x0)left = new SegmentTree();
        if(right == 0x0)right = new SegmentTree();

        left->build(arr,l,mid);
        right->build(arr,mid+1,r);

        sum = left->getSum() + right->getSum();
        return;
    }
    int query(int L,int R)
    {
        if(L > r || R < l)
            return 0;
        if(L <= l && R >= r)
            return sum;
        return left->query(L,R) + right->query(L,R);
    }
    int update(int i,int val)
    {
        if(l == r && r == i)
        {
            sum = val;
            return val;
        }
        int mid = (l+r)/2;
        if(i > mid)
        {
            int x = right->update(i,val);
            return sum = left->getSum() + x;
        }else{
            int x = left->update(i,val);
            return sum = right->getSum() + x;
        }
    }
    int updateLazyManner(int L,int R,int incr)
    {   
        if(lazyVal)
        {
            sum += (r-l+1)*lazyVal;
            if(left != 0x0)
                left->setLazyMarker(lazyVal);
            if(right != 0x0)
                right->setLazyMarker(lazyVal);
            lazyVal = 0;
        }
        if(L > r || R < l || L > R)
            return sum;
        if(l >= L && r <= R)
        {
            sum += (r-l+1)*incr;
            if(left != 0x0)
                left->setLazyMarker(incr);
            if(right != 0x0)
                right->setLazyMarker(incr);
            return sum;
        }
        return sum = left->updateLazyManner(L,R,incr) + right->updateLazyManner(L,R,incr);
    }
    int queryLazyManner(int L,int R)
    {
        if(lazyVal)
        {
            sum += (r-l+1)*lazyVal;
            if(left != 0x0)
                left->setLazyMarker(lazyVal);
            if(right != 0x0)
                right->setLazyMarker(lazyVal);
            lazyVal = 0;
        }
        if(L > r || R < l || L > R)
            return 0;
        if(l >= L && r <= R)
        {
            return sum;
        }
        return left->queryLazyManner(L,R) + right->queryLazyManner(L,R);
    }
};