#include <math.h>
#include <stdio.h>
#define LENGTH 10

double inputs [LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
double linear_outputs [LENGTH] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
double quadratic_outputs [LENGTH] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

struct linear_model_parameters {
  double a;
  double b;
};

struct quadratic_model_parameters {
  double a;
  double b;
  double c;
};

void print_linear_parameters(struct linear_model_parameters parameters);
void print_quadratic_parameters(struct quadratic_model_parameters parameters);

typedef struct quadratic_model_parameters current_model;
#define print_parameters(x) print_quadratic_parameters(x);

double sum_of_squared_residuals( int length
                               , double * inputs
                               , double * outputs
                               , current_model parameters
                               , double (*f)(double, current_model)
                               );
double sum_of_squared_derivative( int length
                                , double * inputs
                                , double * outputs
                                , current_model parameters
                                , double (*f)(double, current_model)
                                , double (*derivative)(double, current_model)
                                );
double linear_model( double input
                   , struct linear_model_parameters parameters
                   );
double linear_model_derivative_a( double input
                                , struct linear_model_parameters parameters
                                );
double linear_model_derivative_b( double input
                                , struct linear_model_parameters parameters
                                );
double quadratic_model( double input
                      , struct quadratic_model_parameters parameters
                      );
double quadratic_model_derivative_a( double input
                                   , struct quadratic_model_parameters parameters
                                   );
double quadratic_model_derivative_b( double input
                                   , struct quadratic_model_parameters parameters
                                   );
double quadratic_model_derivative_c( double input
                                   , struct quadratic_model_parameters parameters
                                   );


double max(double a, double b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int main(int argc, char ** argv) {
  double epsilon = 10;
  /* struct linear_model_parameters parameters = {0,11}; */
  /* double * outputs = linear_outputs; */
  struct quadratic_model_parameters parameters = {100,11,1};
  double * outputs = quadratic_outputs;

  print_parameters(parameters);


  /* while (epsilon < fabs(sum_of_squared_residuals(LENGTH, inputs, outputs, parameters, linear_model))) { */
  /*   double da = sum_of_squared_derivative(LENGTH, inputs, outputs, parameters, linear_model, linear_model_derivative_a); */
  /*   double db = sum_of_squared_derivative(LENGTH, inputs, outputs, parameters, linear_model, linear_model_derivative_b); */
  /*   double mag = sum_of_squared_residuals(LENGTH, inputs, outputs, parameters, linear_model); */
  /*   double modifier = 1; */
  /*   modifier = mag; */
  /*   print_parameters(parameters); */
  /*   printf("derivative_a = %f\n", da); */
  /*   printf("derivative_b = %f\n", db); */
  /*   printf("mag = %f\n", mag); */
  /*   parameters.a = parameters.a - (da / modifier); */
  /*   parameters.b = parameters.b - (db / modifier); */
  /*   printf("\n"); */
  /* } */
  while (epsilon < fabs(sum_of_squared_residuals(LENGTH, inputs, outputs, parameters, quadratic_model))) {
    double da = sum_of_squared_derivative(LENGTH, inputs, outputs, parameters, quadratic_model, quadratic_model_derivative_a);
    double db = sum_of_squared_derivative(LENGTH, inputs, outputs, parameters, quadratic_model, quadratic_model_derivative_b);
    double dc = sum_of_squared_derivative(LENGTH, inputs, outputs, parameters, quadratic_model, quadratic_model_derivative_c);
    double mag = sum_of_squared_residuals(LENGTH, inputs, outputs, parameters, quadratic_model);
    print_parameters(parameters);
    printf("derivative_a = %f\n", da);
    printf("derivative_b = %f\n", db);
    printf("derivative_c = %f\n", dc);
    printf("mag = %f\n", mag);
    parameters.a = parameters.a - (da) / mag;
    parameters.b = parameters.b - (db) / mag;
    parameters.c = parameters.c - (dc) / mag;
    printf("\n");
  }

  printf("Solution found:\n");
  print_parameters(parameters);
  printf("Magnitude of sum of squared residuals is: %f\n", sum_of_squared_residuals(LENGTH, inputs, outputs, parameters, quadratic_model));
}

void print_linear_parameters(struct linear_model_parameters parameters) {
  printf("(linear_model {%f, %f})\n", parameters.a, parameters.b);
}
void print_quadratic_parameters(struct quadratic_model_parameters parameters) {
  printf("(quadratic_model {%f, %f, %f})\n", parameters.a, parameters.b, parameters.c);
}

double sum_of_squared_residuals( int length
                               , double * inputs
                               , double * outputs
                               , current_model parameters
                               , double (*f)(double, current_model)
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
                                , current_model parameters
                                , double (*f)(double, current_model)
                                , double (*derivative)(double, current_model)) {
  double sum = 0;
  for (int i = 0 ; i < length ; ++i) {
    double r = outputs[i] - f(inputs[i], parameters);
    sum += r * derivative(inputs[i], parameters);
  }
  return -2 * sum;
}

double linear_model( double input
                   , struct linear_model_parameters parameters
                   ) {
  return parameters.a + input * parameters.b;
}

double linear_model_derivative_a( double input
                                , struct linear_model_parameters parameters
                              ) {
  return 1;
}

double linear_model_derivative_b( double input
                                , struct linear_model_parameters parameters
                              ) {
  return input;
}

double quadratic_model( double input
                      , struct quadratic_model_parameters parameters
                      ) {
  return parameters.a + input * parameters.b + input * input * parameters.c;
}
double quadratic_model_derivative_a( double input
                                   , struct quadratic_model_parameters parameters
                                   ) {
  return 1;
}
double quadratic_model_derivative_b( double input
                                   , struct quadratic_model_parameters parameters
                                   ) {
  return input;
}
double quadratic_model_derivative_c( double input
                                   , struct quadratic_model_parameters parameters
                                   ) {
  return input * input;
}
