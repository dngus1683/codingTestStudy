# 게임 닉네임
# 닉네임들이 주어질 때 별칭을 만들자. baekjoon -> b, bakejoon -> bak (앞에 baekjoon이 있으므로 두 이름의 차이 중 최소), baekjoon -> baekjoon2


# 내 답안1
import sys

input = sys.stdin.readline

n = int(input())
li = [input().rstrip() for _ in range(n)]

class Node(object):
    def __init__(self, key, state=0, cnt=0, data=None):
        self.key = key
        self.data = data
        self.state = state
        self.cnt = cnt
        self.children = {}

class Trie(object):
    def __init__(self):
        self.head = Node(None)
  # 문자열 삽입
    def insert(self, string):
        curr_node = self.head
        # 삽입할 string 각각의 문자에 대해 자식 Node를 만들며 내려간다.
        for char in string:
            # 자식 Node들 중 같은 문자가 없으면 Node 새로 생성
            if char not in curr_node.children:
                curr_node.children[char] = Node(char)
            # 같은 문자가 있으면 노드를 따로 생성하지 않고, 해당 노드로 이동
            curr_node = curr_node.children[char]
        # 문자열이 끝난 지점의 노드의 data값에 해당 문자열을 입력
        curr_node.data = string

    # 문자열이 존재하는지 search
    def search(self, string):
        #가장 아래에 있는 노드에서 부터 탐색 시작
        flag = 0
        output = str()
        curr_node = self.head
        for i in range(len(string)):
            if string[i] in curr_node.children:
                curr_node = curr_node.children[string[i]]
                if curr_node.state == 0 and flag == 0:
                    output = string[0:i+1]
                    flag = 1
                curr_node.state += 1
            else:
                return output
        curr_node.cnt += 1
        #탐색이 끝난 후 해당 노드의 data값이 존재한다면
        #문자가 포함되어있다는 뜻이다.
        if curr_node.state == 1 and curr_node.cnt == 1:
            return output
        elif curr_node.cnt == 1:
            return curr_node.data
        else:
            return curr_node.data + str(curr_node.cnt)

trie = Trie()
for l in li:
    trie.insert(l)
    print(trie.search(l))
