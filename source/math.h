
// A math library for GEMS. work in progress, made by Oklomsy!
// The math library is a essential part of an OS, and although the languages themselves have math functions. they might not have a function to check if a number is even or odd and it may require some libraries but the math library allows you to save time.

int evenorodd(int n){
  if (n % 2 == 0){
    return 2; // 2 = true/even
  } else {
    return 1; // 1 = false/odd
  }
  return 0;
}

// Example: "What is 10% out of 150?"
float findpercentageofnum(float per, float num){
  return per / 100 * num;
}

long int factorial(int n){
  if (n == 0){
    return 1;
  } else{
    return n * factorial(n-1);
  }
}
