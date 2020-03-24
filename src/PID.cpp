#include "PID.h"

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * Initialize PID coefficients and errors
   */
  Kp = Kp_;
  Kd = Kd_;
  Ki = Ki_;
  p_error = 0;
  d_error = 0;
  i_error = 0;
}

void PID::UpdateError(double cte) {
  /**
   * Update PID errors based on cte.
   */
  p_error = cte;
  d_error = cte - prev_cte;
  prev_cte = cte;
  i_error += cte;
}

double PID::TotalError() {
  /**
   * Calculate and return the total error
   */
  return -Kp*p_error - Kd*d_error - Ki*i_error;
}