#include <stdio.h>

// System parameters
#define M1 2.0
#define M2 3.0
#define K1 0.5
#define K2 1.0
#define K3 15.0
#define C1 0.25
#define C2 0.33
#define C3 0.5

// Function to calculate the derivative of the state
void calculate_derivative(double t, double state[4], double derivative[4]) {
    derivative[0] = state[2];  // dx1/dt = v1
    derivative[1] = state[3];  // dx2/dt = v2

    double delta_x = state[0] - state[1];

    // dv1/dt
    derivative[2] = -(K1 * state[0] + K2 * delta_x) / M1;

    // dv2/dt
    derivative[3] = -(K3 * state[1] - K2 * delta_x) / M2;
}

// Euler's Method for solving the system
void euler_method(double t_initial, double t_final, double dt, double initial_conditions[4]) {
    FILE *output_file;
    output_file = fopen("trajectory_data.txt", "w");

    double t = t_initial;
    double state[4];
    for (int i = 0; i < 4; ++i) {
        state[i] = initial_conditions[i];
    }

    while (t <= t_final) {
        fprintf(output_file, "%f %f %f %f %f\n", t, state[0], state[1], state[2], state[3]);

        double derivative[4];
        calculate_derivative(t, state, derivative);

        for (int i = 0; i < 4; ++i) {
            state[i] += derivative[i] * dt;
        }

        t += dt;
    }

    fclose(output_file);
}

int main() {
    // Define the initial conditions
    double initial_conditions[4] = {1.0, -0.5, 0.0, 0.0};  // x1, x2, v1, v2

    // Time parameters
    double t_initial = 0.0;
    double t_final = 10.0;
    double dt = 0.01;

    // Solve the system using Euler's Method
    euler_method(t_initial, t_final, dt, initial_conditions);

    return 0;
}