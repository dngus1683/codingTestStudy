# 문자열

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

## 문자열 공백
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


## string을 int로 변환

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

