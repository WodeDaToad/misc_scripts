// this is a script I wrote to make my statistics homework easier.
// there are some things I'd like to improve\
// such as command line input\
// or txt file input

#include <fstream>
#include <cmath>
using namespace std;

// return mean of a number set
double mean(double* data, int siz){
	double val;
	for(int i = 0; i < siz; ++i){
		val += *(data + i);
	}
	val /= siz;
	return val;
}

// return variance of a number set
double variance(double* data, int siz, bool samp = true){
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
double stddev(double* data, int siz, bool samp = true){
	double var = variance(data, siz, samp);
	return pow(var, 0.5);
}

// return smallest in a number set
double smallest(double* data, int siz){
	double val = 999999;
	for(int i = 0; i < siz; ++i){
		if(val > *(data + i)){
			val = *(data + i);
		}
	}
	return val;
}

// return largest in a number set
double largest(double* data, int siz){
	double val = 0;
	for(int i = 0; i < siz; ++i){
		if(val < *(data + i)){
			val = *(data + i);
		}
	}
	return val;
}

// return range of a number set
double range(double* data, int siz){
	return largest(data, siz) - smallest(data, siz);
}

// return median of a number set
double median(double* data, int siz){
	double val;
	if(siz % 2 == 0){
		val = (*(data + (siz / 2)) + *(data + (siz / 2) - 1)) / 2;
	}else{
		val = *(data + (siz / 2));
	}
	return val;
}

// return first quartile of a number set
double firstquart(double* data, int siz){
	double val;
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
double thirdquart(double* data, int siz){
	double val;
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
	int siz = 26;
	//double data[] = {81.2, 26.1, 95.0, 41.1, 28.6, 21.7, 11.5, 68.5, 345.5, 321.2, 1202.6, 1.0, 4.9, 163.0, 372.4, 244.3, 47.3, 87.0, 26.3, 24.4, 830.1, 4.9, 36.6, 147.8, 17.3, 29.0};
	double data[] = {274.7, 302.8, 242.5, 255.0, 17.5, 115.3, 31.4, 703.4, 334.1, 1697.8, 118.3, 198.6, 129.6, 274.7, 119.0, 1656.0, 7.7, 430.0, 40.6, 92.4, 200.7, 32.7, 4.1, 978.0, 489.1, 2745.6};
	//double data[] = {81.2, 26.1, 95.0, 41.1, 28.6, 21.7, 11.5, 68.5, 345.5, 321.2, 1202.6, 1.0, 4.9, 163.0, 372.4, 244.3, 47.3, 87.0, 26.3, 24.4, 830.1, 4.9, 36.6, 147.8, 17.3, 29.0, 274.7, 302.8, 242.5, 255.0, 17.5, 115.3, 31.4, 703.4, 334.1, 1697.8, 118.3, 198.6, 129.6, 274.7, 119.0, 1656.0, 7.7, 430.0, 40.6, 92.4, 200.7, 32.7, 4.1, 978.0, 489.1, 2745.6};
	bool samp = true;
	ofstream go;
	go.open("outdouble.txt");
	go << "Size: " << siz;
	if(samp){
		go << "\nSample";
	}else{
		go << "\nPopulation";
	}
	go << "\nMean: " << mean(data, siz) << "\nVariance: " << variance(data, siz, samp) << "\nStdDev: " << stddev(data, siz, samp) << "\nRange: " << smallest(data, siz) << " to " << largest(data, siz);
	go.close();
	return 0;
}