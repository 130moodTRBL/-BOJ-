using namespace std;

int uclid(int a, int b)
{
    if(b == 0) {
        return a;
    }
    return uclid(b, a % b);
}

long long solution(int w,int h) {
    int n;
    long long ans;
    
    if(w > h) {
        n = uclid(w, h);
    }
    else {
        n = uclid(h, w);
    }
    
    ans = ((long long)w * h) - n * (w / n + h / n - 1);
    return ans;
}
