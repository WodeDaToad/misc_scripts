// this is a script I wrote to make my statistics homework easier.
// there are some things I'd like to improve\
// such as adding better sort methods\
// and command line input\
// or txt file input

#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;

// return mean of a number set
double mean(int* data, int siz){
	double val;
	for(int i = 0; i < siz; ++i){
		val += *(data + i);
	}
	val /= siz;
	return val;
}

// return variance of a number set
double variance(int* data, int siz, bool samp = true){
	double val;
	double meani = mean(data, siz);
	for(int i = 0; i < siz; ++i){
		val += pow((*(data + i) - meani), 2);
	}
	if(samp){
		return val / (siz - 1);
	}else{
		return val / siz;
	}
}

// return standard of deviation of a number set
double stddev(int* data, int siz, bool samp = true){
	double var = variance(data, siz, samp);
	return pow(var, 0.5);
}

// return smallest in a number set
int smallest(int* data, int siz, bool sorted = false){
	int val;
	if(sorted == false){
		val = 999999;
		for(int i = 0; i < siz; ++i){
			if(val > *(data + i)){
				val = *(data + i);
			}
		}
	}else{
		val = *data;
	}
	return val;
}

// return largest in a number set
int largest(int* data, int siz, bool sorted = false){
	int val;
	if(sorted == false){
		for(int i = 0; i < siz; ++i){
			if(val < *(data + i)){
				val = *(data + i);
			}
		}
	}else{
		val = *(data + siz - 1);
	}
	return val;
}

// return range of a number set
int range(int* data, int siz, bool sorted = false){
	return largest(data, siz) - smallest(data, siz);
}

void bubblesort(int* data, int siz){
	for(int i = 0; i < siz - 1; ++i){
		for (int j = 0; j < siz - 1; ++j){
			if(*(data + j) > *(data + j + 1)){
				int temp = *(data + j);
				*(data + j) = *(data + j + 1);
				*(data + j + 1) = temp;
			}
		}
	}
}

// return median of a number set
int median(int* data, int siz){
	int val;
	if(siz % 2 == 0){
		val = (*(data + (siz / 2)) + *(data + (siz / 2) - 1)) / 2;
	}else{
		val = *(data + (siz / 2));
	}
	return val;
}

// return first quartile of a number set
int firstquart(int* data, int siz){
	int val;
	if(siz % 4 == 0){
		val = (*(data + (siz / 4)) + *(data + (siz / 4) - 1)) / 2;
	}else{
		int newsiz = siz / 2;
		if(newsiz % 2 == 0){
			val = (*(data + (newsiz / 2)) + *(data + (newsiz / 2) - 1)) / 2;
		}else{
			val = *(data + (newsiz / 2));
		}
	}
	return val;
}

// return third quartile of a number set
int thirdquart(int* data, int siz){
	int val;
	if(siz % 4 == 0){
		val = (*(data + (3 * siz / 4)) + *(data + (3 * siz / 4) - 1)) / 2;
	}else{
		int newsiz = siz / 2;
		if(newsiz % 2 == 0){
			val = (*(data + (3 * newsiz / 2)) + *(data + (3 * newsiz / 2) + 1)) / 2;
		}else{
			val = *(data + (3 * newsiz / 2));
		}
	}
	return val;
}

int main(){
	int siz = 9;
	int data[] = {953, 950, 948, 955, 951, 949, 957, 954, 955};
	bubblesort(data, siz);
	bool samp = true;
	ofstream go;
	go.open("outint.txt");
	go << "Size: " << siz << "\nMean: " << mean(data, siz) << "\nVariance: " << variance(data, siz, samp) << "\nStdDev: " << stddev(data, siz, samp);
	go << "\nRange: " << smallest(data, siz, true) << " to " << largest(data, siz, true);
	go << "\nFirst Quartile: " << firstquart(data, siz) << "\nMedian: " << median(data, siz) << "\nThird Quartile: " << thirdquart(data, siz);
	go.close();
	return 0;
}