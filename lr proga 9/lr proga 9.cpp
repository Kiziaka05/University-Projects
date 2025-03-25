#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const int BASE = 15554;

//порівняння
int Compare(const vector<int>& num1, const vector<int>& num2) {
    if (num1.size() != num2.size())
        return num1.size() < num2.size() ? -1 : 1;

    for (int i = num1.size() - 1; i >= 0; --i) {
        if (num1[i] != num2[i])
            return num1[i] < num2[i] ? -1 : 1;
    }

    return 0;  // якщо вони рівні
}


//множення на коефіцієнт
vector<int> MultiplyByCoefficient(const vector<int>& num, int coefficient) {
    int n = num.size();
    int carry = 0;
    long long product = 0;
    vector<int> result(n, 0);

    for (int i = 0; i < n; ++i) {
        product = num[i] * coefficient + carry;
        carry = product / BASE;
        result[i] = product % BASE;
    }

    while (carry) {
        result.push_back(carry % BASE);
        carry /= BASE;
    }

    return result;
}


//Пошук найбільшого коефіцієнту для ділення
unsigned FindDiv(const vector<int>& dividend, const vector<int>& divisor) {

    unsigned first = 0;
    unsigned last = BASE;
    unsigned it;
    int count, step;
    count = last - first;
    while (count > 0) {
        it = first;
        step = count / 2;
        it += step;
        if (Compare(dividend, MultiplyByCoefficient(divisor, it)) >= 0) {
            first = ++it;
            count -= step + 1;
        }
        else {
            count = step;
        }
    }
    return first - 1;

}


//додавання
vector<int> Add(const vector<int>& num1, const vector<int>& num2) {
    int carry = 0;
    int sum = 0;
    vector<int> result;
    size_t max_len = max(num1.size(), num2.size());

    for (size_t i = 0; i < max_len || carry; ++i) {
         sum = carry;
        if (i < num1.size()) sum += num1[i];
        if (i < num2.size()) sum += num2[i];
        carry = sum / BASE;
        result.push_back(sum % BASE);
    }

    return result;
}


//Віднімання
vector<int> Subtract(const vector<int>& num1, const vector<int>& num2) {
    int carry = 0;
    int diff = 0;
    vector<int> result;
    size_t max_length = max(num1.size(), num2.size());

    
    if (Compare(num1, num2) == -1) {
        cerr << "First number should be greater than or equal to the second number for subtraction!" << endl;
        return result;
    }

    for (size_t i = 0; i < max_length || carry; ++i) {
        diff = num1[i] - carry;
        if (i < num2.size()) diff -= num2[i];
        if (diff < 0) {
            diff += BASE;
            carry = 1;
        }
        else {
            carry = 0;
        }
        result.push_back(diff);
    }

    // Видалення ведучих нулів
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    return result;
}


//Множення
vector<int> Multiply(const vector<int>& num1, const vector<int>& num2) {
    int n = num1.size(), m = num2.size();
    int carry = 0;
    long long product = 0;
    vector<int> result(n + m, 0);

    for (int i = 0; i < n; ++i) {
        carry = 0;
        for (int j = 0; j < m || carry; ++j) {
            product = result[i + j] + carry + (long long)num1[i] * (j < m ? num2[j] : 0);
            carry = product / BASE;
            result[i + j] = product % BASE;
        }
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    return result;
}


//Ділення
pair<vector<int>, vector<int>> Divide(const vector<int>& num1, const vector<int>& num2) {
    vector<int> quotient;
    vector<int> temp = num1;
    vector<int> currentDividend;
    if (num2.size() == 1 && num2[0] == 0) {
        cerr << "Error: Division by zero!" << endl;
        return make_pair(vector<int>{0}, vector<int>{0});
    }

    if (Compare(num1, num2) == -1) {
        quotient.push_back(0);
        temp = num1;
        return make_pair(quotient, temp);
    }

    if (Compare(num1, num2) == 0) {
        quotient.push_back(1);
        temp.push_back(0);
        return make_pair(quotient, temp);
    }

    for (int i = temp.size() - num2.size(); i >= 0; --i) {
        currentDividend.clear();
        currentDividend.insert(currentDividend.begin(), temp.begin() + i, temp.end());

        int div = FindDiv(currentDividend, num2);

        quotient.insert(quotient.begin(), div);

        temp = Subtract(currentDividend, MultiplyByCoefficient(num2, div));
    }

    
    while (temp.size() > 1 && temp.back() == 0) {
        temp.pop_back();
    }

    return make_pair(quotient, temp);
}



//Виведення
void printNumber(const vector<int>& number) {
    for (auto it = number.rbegin(); it != number.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}






int main() {
    char choice;
    string input1, input2;
    cout << "Please enter the number, separating each digit with spaces!" << endl;
    cout << "Enter the first number: ";
    getline(cin, input1);
    cout << "Enter the second number: ";
    getline(cin, input2);

    vector<int> num1, num2;

    stringstream ss1(input1);
    int digit;
    while (ss1 >> digit) {
        if (digit >= BASE) {
            cerr << "Invalid input!" << endl;
            return 1;
        }
        num1.insert(num1.begin(), digit);
    }

    stringstream ss2(input2);
    while (ss2 >> digit) {
        if (digit >= BASE) {
            cerr << "Invalid input!" << endl;
            return 1;
        }
        num2.insert(num2.begin(), digit);
    }

    cout << "Enter operation (+, -, *, /): ";
    cin >> choice;
    switch (choice) {
    case '+': {
        vector<int> add_res = Add(num1, num2);
        cout << "Addition result: ";
        printNumber(add_res);
        break;
    }
    case '-': {
        vector<int> subtr_res = Subtract(num1, num2);
        cout << "Subtraction result: ";
        printNumber(subtr_res);
        break;
    }
    case '*': {
        vector<int> mult_res = Multiply(num1, num2);
        cout << "Multiplication result: ";
        printNumber(mult_res);
        break;
    }
    case '/': {
        auto div_res = Divide(num1, num2);
        cout << "Division result: " << endl;
        cout << "Quotient: ";
        printNumber(div_res.first);
        cout << "Remainder: ";
        printNumber(div_res.second);
        break;
    }
    default:
        cout << "Invalid operation" << endl;
        break;
    }
    return 0;
}

