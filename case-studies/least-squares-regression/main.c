#include <math.h>
#include <stdio.h>
#define LENGTH 10

double inputs [LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
double outputs [LENGTH] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
/* double outputs [LENGTH] = {1, 4, 9, 16, 25, 36, 49, 64, 81}; */

struct model {
  double a;
  double b;
};

double sum_of_squared_residuals( int length
                               , double * inputs
                               , double * outputs
                               , struct model parameters
                               , double (*f)(double, struct model)
                               );
double sum_of_squared_derivative( int length
                                , double * inputs
                                , double * outputs
                                , struct model parameters
                                , double (*f)(double, struct model)
                                , double (*derivative)(double, struct model)
                                );
double linear_model( double input
                   , struct model parameters
                   );
double linear_model_derivative_a( double input
                                , struct model parameters
                                );
double linear_model_derivative_b( double input
                                , struct model parameters
                                );
void print_parameters(struct model parameters);


int main(int argc, char ** argv) {
  double epsilon = 10;
  struct model parameters = {0,11};

  print_parameters(parameters);

  while (epsilon < fabs(sum_of_squared_residuals(LENGTH, inputs, outputs, parameters, linear_model))) {
    double da = sum_of_squared_derivative(LENGTH, inputs, outputs, parameters, linear_model, linear_model_derivative_a);
    double db = sum_of_squared_derivative(LENGTH, inputs, outputs, parameters, linear_model, linear_model_derivative_b);
    double mag = sum_of_squared_residuals(LENGTH, inputs, outputs, parameters, linear_model);
    double modifier = 1;
    modifier = mag;
    print_parameters(parameters);
    printf("derivative_a = %f\n", da);
    printf("derivative_b = %f\n", db);
    printf("mag = %f\n", mag);
    parameters.a = parameters.a - (da / modifier);
    parameters.b = parameters.b - (db / modifier);
    printf("\n");
  }
  printf("Solution found: %f + x * %f\n", parameters.a, parameters.b);
}

void print_parameters(struct model parameters) {
  printf("(struct model {%f, %f})\n", parameters.a, parameters.b);
}

double sum_of_squared_residuals( int length
                               , double * inputs
                               , double * outputs
                               , struct model parameters
                               , double (*f)(double, struct model)
                               ) {
  double sum = 0;
  for (int i = 0 ; i < length ; ++i) {
    double r = outputs[i] - f(inputs[i], parameters);
    sum += r * r;
  }
  return sum;
}

double sum_of_squared_derivative( int length
                                , double * inputs
                                , double * outputs
                                , struct model parameters
                                , double (*f)(double, struct model)
                                , double (*derivative)(double, struct model)) {
  double sum = 0;
  for (int i = 0 ; i < length ; ++i) {
    double r = outputs[i] - f(inputs[i], parameters);
    sum += r * derivative(inputs[i], parameters);
  }
  return -2 * sum;
}

double linear_model( double input
                   , struct model parameters
                   ) {
  return parameters.a + input * parameters.b;
}

double linear_model_derivative_a( double input
                                , struct model parameters
                              ) {
  return 1;
}

double linear_model_derivative_b( double input
                                , struct model parameters
                              ) {
  return input;
}

