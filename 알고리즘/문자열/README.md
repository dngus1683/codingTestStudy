# 문자열
+ [문자열 입력](#문자열-입력)
+ [문자열 분리](#문자열-분리)
+ [문자열 자료형 변환](#문자열-자료형-변환)
+ [KMP 알고리즘](#KMP-알고리즘)
+ [LCP 알고리즘](#LCP-알고리즘)
  
## 문자열 입력
C++에서 문자열을 입력받는 방법으로 cin.getline()과 getline() 함수가 있다. 이 두 함수는 문자열을 입력 받는 방식이 다르며, 사용하는 상황에 따라 선택할 수 있다.
  + **cin.getline()**
  
    cin.getline() 함수는 C 스타일 문자열을 입력 받을 때 사용된다. 이 함수는 istream 클래스의 멤버 함수로서, istream 객체에서 문자열을 읽어온다.

    이 함수는 입력 버퍼에서 개행 문자('\n')를 만날 때까지 문자를 읽어오며, 개행 문자가 입력된 후에는 읽기를 중단하고, 개행 문자를 버퍼에 남겨둔다.

    함수의 마지막 인자를 통해 입력 중단의 기준을 정할 수 있다. 하지만 입력을 마무리 할 때, enter키를 누르기 때문에 마지막 enter키 입력을 제거하기 위해 cin.ignore()를 사용한다.
    ```c++
    char buffer[SIZE];
    cin.getline(buffer, SIZE); // cin.getline()에는 string을 인자로 받을 수 없다.

    cin.getline(buffer, SIZE, 'z'); // 문자 z를 입력 받으면 그 전까지의 입력만 받는다.
    cin.ignore();  // 'z' 뒤에 따라오는 enter 키 제거
    ```    

  + **getline()**
    
      getline() 함수는 string 객체를 입력 받을 때 사용된다. 이 함수는 <string> 헤더 파일에 정의되어 있다.
  
      getline() 함수는 istream 객체와 string 객체를 인자로 받아, 입력 스트림에서 한 줄을 읽어와 string 객체에 저장한다. 이 함수는 개행 문자를 읽어와 버퍼에서 제거한다.

      함수의 마지막 인자를 통해 입력 중단의 기준을 정할 수 있다. 하지만 입력을 마무리 할 때, enter키를 누르기 때문에 마지막 enter키 입력을 제거하기 위해 cin.ignore()를 사용한다.
      ```c++
      string str; // 문자열 객체
      ifstream file("sample.txt"); // 파일 객체
      
      getline(cin, str);  // 키보드 입력으로부터 문자열 받기
      getline(file, str); // 파일로부터 문자열 받기

      getline(cin, str, '$'); // '$'를 입력 받으면 그 전까지의 입력만 받는다.
      cin.ignore();  // '$' 뒤에 따라 오는 enter 키 제거
      ```

## 문자열 분리
C++에서 문자열을 공백을 기준으로 분리하는 방법에는 여러 가지가 있다. 가장 일반적인 방법은 std::istringstream, std::stringstream, std::string::find()와 std::string::substr() 함수를 사용하는 것이다. 이러한 방법들은 문자열을 특정 구분자(여기서는 공백)로 나누어서 각각의 부분 문자열을 추출할 수 있다.

  + **std::stringstream 사용하기**
    
    <sstream> 해더에 포함된 std::stringstream 클래스를 사용하여 문자열을 공백을 기준으로 분리할 수 있다. 이 클래스는 문자열 스트림을 생성하여 문자열에서 값을 추출할 수 있다.
    ```c++
    #include <iostream>
    #include <sstream>
    #include <string>
    #include <vector>

    using namespace std;
    
    int main() {
        string line = "Hello world, how are you?";
        stringstream ss(line); // 또는 ss를 선언한 후, ss << line; 을 통해 line의 문자열을 ss 문자열 스트림에 넣을 수 있다.
        string word;
        vector<std::string> words;
    
        while (ss >> word) {
            words.push_back(word);
        }
    
        for (const auto& w : words) {
            std::cout << w << std::endl;
        }
    
        string a, b, c, d, e;

        ss >> a >> b >> c >> d >> e; 
    
        return 0;
    }
    ```
  + **std::string::find()와 std::string::substr() 사용하기**

    <string> 해더에 포함된 std::string::find() 함수를 사용하여 공백을 찾고, std::string::substr() 함수를 사용하여 부분 문자열을 추출할 수 있다.
    ```c++
    #include <iostream>
    #include <string>
    #include <vector>
  
    usine namespace std;
    
    int main() {
        string line = "Hello world, how are you?";
        vector<std::string> words;
    
        size_t start = 0, end;
        while ((end = line.find(' ', start)) != string::npos) {
            words.push_back(line.substr(start, end - start));
            start = end + 1;
        }
        words.push_back(line.substr(start));
    
        for (const auto& w : words) {
            std::cout << w << std::endl;
        }
    
        return 0;
    }
    ```
  + **한 문자씩 합치기**

      std::string::substr()의 시간 복잡도는 O(N)이며 반복문의 깊이가 깊다면 시간이 오래걸릴 수 있다. 때문에 반복문을 통해 문자 단위로 문자열을 순회하면서 ' '가 나올 때까지 앞 전의 문자들을 더해간다.
      이 후, ' '이 나타난다면 그때까지 합했던 단어를 처리한 후 다시 새로 문자를 더해간다.
      
      ```c++
      #include <iostream>
      #include <string>
      #include <vector>
    
      usine namespace std;
      
      int main() {
          string line = "Hello world, how are you?";
          vector<std::string> words;

          string word;
          for(char ch : line)
          {
              if(ch != ' ')
              {
                  word += ch;
              }
              else
              {
                  words.push_back(word);
                  word.clear();
              }
          }
          if(!word.empty())
          {
              words.push_back(word);
          }
      
          return 0;
      }
      ```
 + **cin.peek() 활용**

      std::cin.peek() 함수는 스트림에 존재하는 문자를 반환하는 함수다. 이를 활용하여, 일반적인 cin >> 을 통해 문자 단위로 입력받다가 cin.peek()를 통해 '\n'이 스트림에 남아있다면 입력 받기를 종료하는 방식이다.
      이때, std::cin.peek()는 스트림에서 문자를 제거하지는 않기 때문에 std::cin.ignore()로 추가적으로 제거해줘야 한다.

      하지만 이 방식은 다른 방식들보다 입력을 많이 받기 때문에, 입력받을 단어가 많을 경우 시간이 가장 오래걸릴 수 있다.
      
      ```c++
      #include <iostream>
      #include <string>
      #include <vector>
    
      usine namespace std;
      
      int main() {
          vector<std::string> words;
      
          string word;
          while(true)
          {
              cin >> word;
              words.push_back(word);
              if(cin.peek() == '\n')
              {
                  cin.ignore();
                  break;
              }
          }
      
          return 0;
      }
      ```

## 문자열 자료형 변환

C++에서는 std::stoi() 함수를 사용하여 문자열을 정수로 변환할 수 있으며, 문자열을 스트림을 취급하게 하는 stringstream을 활용하여 정수 이외에도 다양한 자료형으로 변환할 수 있다.

  + **std::stoi()**
    
    std::stoi() 함수는 문자열을 정수로 변환하는데 사용되며, 변환 중에 예외가 발생하면 std::invalid_argument 또는 std::out_of_range 예외가 발생한다.
    해당 방법은 C++11부터 도입되었기 때문에, 사용하기 전 C++ 버전을 확인하고 사용해야 한다.
    ```c++
    #include <iostream>
    #include <string>

    using namespace std;
    
    int main() {
        string str = "12345";
        int num = stoi(str);
        cout << "String to int: " << num << endl;
        return 0;
    }
    ```

  + **std::stringstream**
    
    std::stringstream 클래스를 사용하면 문자열을 다른 데이터 타입으로 변환할 수 있다.
    std::stringstream은 문자열을 스트림으로 취급하여 입출력 연산을 수행할 수 있는 클래스이며, 이를 활용하여 문자열을 정수, 실수, 불리언 등 다른 데이터 타입으로 변환할 수 있다.
    ```c++
    #include <iostream>
    #include <string>
    #include <sstream>

    using namespace std;
    
    int main() {
        string str = "12345";
        int num;
        
        // std::stringstream 객체 생성
        stringstream ss(str);
    
        // ss를 이용하여 문자열을 정수로 변환
        ss >> num;
    
        cout << "String to int: " << num << endl;
    
        return 0;
    }
    ```

---
## KMP 알고리즘

KMP(Knuth-Morris-Pratt)는 문자열 검색 알고리즘으로, 패턴 내에서 중복되는 접두사와 접미사를 활용해 검색 시간을 줄이는 데 사용된다. 텍스트에서 특정 패턴을 효율적으로 찾기 위해 설계되었으며, **O(n + m)** 시간 복잡도를 갖는다.

### Algorithm
KMP 알고리즘은 두 단계로 이루어진다:
1. **부분 일치 테이블(PI 배열) 생성**  
   패턴 문자열 내에서 접두사와 접미사가 얼마나 일치하는지를 계산한 테이블이다.
2. **패턴 검색**  
   PI 배열을 참조하여 텍스트와 패턴을 비교하고, 불일치가 발생하면 불필요한 비교를 건너뛴다.

- 부분 일치 테이블 생성
  - 패턴의 접두사와 접미사 정보를 기반으로 테이블을 생성한다.
  - PI 배열의 값은 각 위치에서 가장 긴 접두사와 접미사의 일치 길이를 나타낸다.

### 검색 과정
1. 텍스트와 패턴의 문자를 처음부터 비교한다.
2. 불일치가 발생하면 PI 배열을 참조하여 이동할 위치를 결정한다.
3. 이동 후 다시 비교를 진행하며, 패턴이 텍스트 내에서 발견되면 위치를 반환한다.

### Pseudocode
```
function computePI(pattern):
    pi = [0] * length(pattern)
    j = 0
    for i from 1 to length(pattern) - 1:
        while (j > 0 and pattern[i] != pattern[j]):
            j = pi[j - 1]
        if pattern[i] == pattern[j]:
            j += 1
            pi[i] = j
    return pi

function KMP(text, pattern):
    pi = computePI(pattern)
    j = 0
    for i from 0 to length(text) - 1:
        while (j > 0 and text[i] != pattern[j]):
            j = pi[j - 1]
        if text[i] == pattern[j]:
            if j == length(pattern) - 1:
                print("Pattern found at", i - j)
                j = pi[j]
            else:
                j += 1
```

### Complexity
- 시간 복잡도: O(n + m) (n: 텍스트 길이, m: 패턴 길이)
- 공간 복잡도: O(m) (패턴 길이를 저장하는 PI 배열의 크기)

### Implementation
+ C++
    ```c++
    #include <iostream>
    #include <vector>
    #include <string>

    using namespace std;

    vector<int> computePI(const string& pattern) {
        vector<int> pi(pattern.size(), 0);
        int j = 0;
        for (int i = 1; i < pattern.size(); ++i) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = pi[j - 1];
            }
            if (pattern[i] == pattern[j]) {
                pi[i] = ++j;
            }
        }
        return pi;
    }

    void KMP(const string& text, const string& pattern) {
        vector<int> pi = computePI(pattern);
        int j = 0;
        for (int i = 0; i < text.size(); ++i) {
            while (j > 0 && text[i] != pattern[j]) {
                j = pi[j - 1];
            }
            if (text[i] == pattern[j]) {
                if (j == pattern.size() - 1) {
                    cout << "Pattern found at index " << i - j << endl;
                    j = pi[j];
                } else {
                    ++j;
                }
            }
        }
    }
    ```

---

## LCP 알고리즘

LCP 배열은 서픽스 배열(Suffix Array)과 함께 사용되며, 문자열에서 인접한 서픽스 간의 공통 접두사의 최대 길이를 나타낸다. LCP 배열은 문자열 내 중복된 부분 문자열이나 문자열 비교와 같은 문제를 해결하는 데 사용된다.

### Algorithm
1. **서픽스 배열 생성**  
   문자열의 모든 접미사를 사전순으로 정렬한다.
2. **LCP 배열 계산**  
   서픽스 배열의 인접한 항목 간의 공통 접두사 길이를 계산하여 LCP 배열을 생성한다.

- **동작 과정**
  1. 주어진 문자열의 서픽스 배열을 구한다.
  2. 서픽스 배열의 순서를 기준으로 인접한 두 서픽스 간의 공통 접두사 길이를 계산한다.
  3. 계산된 값을 LCP 배열에 저장한다.

### Pseudocode
```
function computeLCP(suffixArray, text):
    n = length(text)
    lcp = [0] * n
    rank = [0] * n

    for i from 0 to n - 1:
        rank[suffixArray[i]] = i

    k = 0
    for i from 0 to n - 1:
        if rank[i] == n - 1:
            k = 0
            continue
        j = suffixArray[rank[i] + 1]
        while (i + k < n and j + k < n and text[i + k] == text[j + k]):
            k += 1
        lcp[rank[i]] = k
        if k > 0:
            k -= 1
    return lcp
```

### Complexity
- 시간 복잡도: O(n) (n: 문자열 길이)
- 공간 복잡도: O(n) (서픽스 배열과 LCP 배열의 크기)

### Implementation
+ C++
    ```c++
    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>

    using namespace std;

    vector<int> buildSuffixArray(const string& s) {
        int n = s.size();
        vector<int> suffixArray(n), rank(n), temp(n);
        for (int i = 0; i < n; ++i) {
            suffixArray[i] = i;
            rank[i] = s[i];
        }
        for (int k = 1; k < n; k *= 2) {
            auto cmp = [&](int a, int b) {
                if (rank[a] != rank[b]) return rank[a] < rank[b];
                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;
                return ra < rb;
            };
            sort(suffixArray.begin(), suffixArray.end(), cmp);
            temp[suffixArray[0]] = 0;
            for (int i = 1; i < n; ++i) {
                temp[suffixArray[i]] = temp[suffixArray[i - 1]] + (cmp(suffixArray[i - 1], suffixArray[i]) ? 1 : 0);
            }
            rank = temp;
        }
        return suffixArray;
    }

    vector<int> computeLCP(const string& s, const vector<int>& suffixArray) {
        int n = s.size();
        vector<int> lcp(n), rank(n);
        for (int i = 0; i < n; ++i) rank[suffixArray[i]] = i;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (rank[i] == n - 1) {
                k = 0;
                continue;
            }
            int j = suffixArray[rank[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) ++k;
            lcp[rank[i]] = k;
            if (k > 0) --k;
        }
        return lcp;
    }
    ```
