#ifndef ML_UTILS_H
#define ML_UTILS_H

#include <vector>

class lrUtils {

public:
    static double array_sum(double arr[], int len);

    static double *array_pow(double arr[], int len, int power);

    static double *array_multiplication(double arr1[], double arr2[], int len);

    static double *array_diff(double arr1[], double arr2[], int len);

    static bool fileExists(const char *path);
    
    static std::vector<std::pair<std::string, std::vector<double>>> read_csv(std::string filename);

    static void modelTrainAndPredict(bool train, const char *inputDir, const char *dataFile);

};

#endif //ML_UTILS_H
