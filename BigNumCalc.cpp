#include "BigNumCalc.h"

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
  std::list<int> bigNum;
  for (char digit : numString) {
    bigNum.push_back(digit - '0');
  }
  return bigNum;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
  std::list<int> result;
  int carry = 0;
  auto it1 = num1.rbegin();
  auto it2 = num2.rbegin();
  while (it1 != num1.rend() || it2 != num2.rend() || carry) {
    int sum = carry;
    if (it1 != num1.rend()) {
      sum += *it1;
      ++it1;
    }
    if (it2 != num2.rend()) {
      sum += *it2;
      ++it2;
    }
    result.push_front(sum % 10);
    carry = sum / 10;
  }
  return result;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
  std::list<int> result;
  int borrow = 0;
  auto it1 = num1.rbegin();
  auto it2 = num2.rbegin();
  while (it1 != num1.rend() || it2 != num2.rend()) {
    int diff = borrow;
    if (it1 != num1.rend()) {
      diff += *it1;
      ++it1;
    }
    if (it2 != num2.rend()) {
      diff -= *it2;
      ++it2;
    }
    if (diff < 0) {
      diff += 10;
      borrow = -1;
    } else {
      borrow = 0;
    }
    result.push_front(diff);
  }
  while (!result.empty() && result.front() == 0) {
    result.pop_front();
  }
  return result;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
  std::list<int> result;
  if (num2.size() != 1) {
    return result;
  }
  int multiplier = num2.front();
  int carry = 0;
  for (auto it = num1.rbegin(); it != num1.rend(); ++it) {
    int product = (*it) * multiplier + carry;
    result.push_front(product % 10);
    carry = product / 10;
  }
  if (carry > 0) {
    result.push_front(carry);
  }
  return result;
}