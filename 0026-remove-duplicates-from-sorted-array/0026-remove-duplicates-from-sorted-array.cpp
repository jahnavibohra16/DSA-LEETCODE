class Solution {
public:
    int removeDuplicates(vector<int>& a) {
    int i = 0;
    int n = a.size();
	for(int j =1; j < n; j++){
		if(a[i]!=a[j]){
			a[i+1]=a[j];
			i++;
		}
	}
	return i+1;
    }
};