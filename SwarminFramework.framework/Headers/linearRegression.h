#ifndef ML_LINEARREGRESSION_H
#define ML_LINEARREGRESSION_H

class LinearRegression {

public:

    // First feature
    double *x;

    // Target feature
    double *y;

    // Number of training examples
    int m;

    const char *model_dir;

    char model_path[1024];

    // The theta coefficients
    double *theta;

    //Constructor with data.
    LinearRegression(double x[], double y[], int m, const char *model_dir);

    /**
     * Train the model with the supplied parameters.
     *
     * @param alpha         The learning rate, e.g. 0.01.
     * @param iterations    The number of gradient descent steps to do.
     */
    void train(double alpha, int iterations);

    /**
     * Try to predict y, given an x.
     */
    double predict(double x);

    void predictAll();

private:

    /**
     * Compute the cost J.
     */
    static double compute_cost(double x[], double y[], double theta[], int m);

    /**
     * Compute the hypothesis.
     */
    static double h(double x, double theta[]);

    /**
     * Calculate the target feature from the other ones.
     */
    static double *calculate_predictions(double x[], double theta[], int m);

    /**
     * Performs gradient descent to learn theta by taking num_items gradient steps with learning rate alpha.
     */
    static double *gradient_descent(double x[], double y[], double alpha, int iters, double *J, double *theta, int m);

    void save_model(double *theta);
    void init_model();

    static double rmse(double preds[], double targets[], int m);

};


#endif //ML_LINEARREGRESSION_H
