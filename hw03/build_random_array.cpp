#include<random>
#include<functional>

std::random_device rd;  
std::mt19937 rng(rd()); // Mersenne twister MT19937
std::uniform_real_distribution<double> distribution(0, 1);

void seed_random_number(long seed) {
  rng = std::mt19937(seed);
}

double random_number()
{
  double res = distribution(rng);
  return res;
}

double *build_random_array(int N) {
  // seed_random_number(0);
  double *A = new double[N];
  for (int i = 0; i < N; ++i) {
    A[i] = random_number();
  }
  return A;
}
