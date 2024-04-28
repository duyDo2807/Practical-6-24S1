#include "BigNumCalc.h"

#include <algorithm>

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
  std::list<int> result;
  for (char digit : numString) {
    result.push_back(digit - '0');
  }
  return result;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
  std::list<int> sum;
  int carry = 0;
  while (!num1.empty() || !num2.empty() || carry) {
    int d1 = num1.empty() ? 0 : num1.back();
    int d2 = num2.empty() ? 0 : num2.back();
    int total = d1 + d2 + carry;
    sum.push_front(total % 10);
    carry = total / 10;
    if (!num1.empty()) num1.pop_back();
    if (!num2.empty()) num2.pop_back();
  }
  return sum;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
  std::list<int> diff;
  int borrow = 0;
  while (!num1.empty() || !num2.empty()) {
    int d1 = num1.empty() ? 0 : num1.back();
    int d2 = num2.empty() ? 0 : num2.back();
    int result = d1 - d2 - borrow;
    if (result < 0) {
      result += 10;
      borrow = 1;
    } else {
      borrow = 0;
    }
    diff.push_front(result);
    if (!num1.empty()) num1.pop_back();
    if (!num2.empty()) num2.pop_back();
  }
  diff.erase(diff.begin(), std::find_if(diff.begin(), diff.end(),
                                        [](int digit) { return digit != 0; }));
  if (diff.empty()) diff.push_back(0);
  return diff;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
  std::list<int> product;
  int carry = 0;
  for (auto it = num1.rbegin(); it != num1.rend(); ++it) {
    int digit = *it;
    int result = digit * num2.front() + carry;
    product.push_front(result % 10);
    carry = result / 10;
  }
  if (carry > 0) {
    product.push_front(carry);
  }
  return product;
}