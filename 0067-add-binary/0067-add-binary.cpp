class Solution {
public:
  static std::string addBinary(std::string a, std::string b) {
    if (a.length() < b.length()) {
      std::swap(a, b);
    }

    auto fill = [&](std::string& s, size_t k) {
      std::reverse(s.begin(), s.end());

      for (size_t i = 0; i < k; ++ i) {
        s.push_back('0');
      }

      std::reverse(s.begin(), s.end());
    };

    fill(b, a.length() - b.length());

    std::string result;
    bool carry_bit = false;

    for (int i = static_cast<int>(a.length()) - 1; i >= 0; -- i) {
      if (a[i] == '0' && b[i] == '0') {
        if (carry_bit) {
          result.push_back('1');
          carry_bit = false;
        } else {
          result.push_back('0');
        }
      } 
      else if (a[i] == '0' || b[i] == '0') {
        if (carry_bit) {
          result.push_back('0');
          carry_bit = true;
        } else {
          result.push_back('1');
        }
      } 
      else {
        if (carry_bit) {
          result.push_back('1');
        } else {
          result.push_back('0');
        }
        carry_bit = true;
      }
    }

    if (carry_bit) {
      result.push_back('1');
    }

    std::reverse(result.begin(), result.end());
    return result;
  }
};