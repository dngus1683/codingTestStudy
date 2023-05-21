# 레드 블랙 트리의 노드 삽입 및 검색을 파이썬으로 구현
import random
from timeit import default_timer as timer

# node class
class Node(object):
    def __init__(self, key, parent, color):
        self.key = key
        self.left = None
        self.right = None
        self.color = color
        self.parent = parent



# 이진 탐색 트리 삽입
def bst_insert(node_p, node_c, parent):
    if node_p is None:
        node_p = Node(node_c.key, parent, 'red')
    elif node_c.key < node_p.key:
        node_p.left = bst_insert(node_p.left, node_c, node_p)
    else:
        node_p.right = bst_insert(node_p.right, node_c, node_p)
    return node_p

# node 시계 방향으로 회전
def right_rotate(x):
    global root
    y = x.left
    x.left = y.right
    if y.right is not None:
        y.right.parent = x
    y.parent = x.parent
    if x.parent is None:
        root = y
    elif x == x.parent.right:
        x.parent.right = y
    else:
        x.parent.left = y
    y.right = x
    x.parent = y

# node 반시계 방향으로 회전
def left_rotate(x):
    global root
    y = x.right
    x.right = y.left
    if y.left is not None:
        y.left.parent = x
    y.parent = x.parent
    if x.parent is None:
        root = y
    elif x == x.parent.left:
        x.parent.left = y
    else:
        x.parent.right = y
    y.left = x
    x.parent = y

#####                           과제03                           ######
#####                    레드 블랙 트리 삽입 코드                     ######
# 레드 블랙 트리 삽입
def rb_insert(n):
    global root
    root = bst_insert(root, n, None)
    while n.parent.color == 'red':
        if n.parent == n.parent.parent.right:
            u = n.parent.parent.left
            if u.color == 'red':
                u.color = 'black'
                n.parent.color = 'black'
                n.parent.parent.color = 'red'
                n = n.parent.parent
            elif n == n.parent.left:
                n = n.parent
                right_rotate(n)
            n.parent.color = 'black'
            n.parent.parent.color = 'red'
            left_rotate(n.parent.parent)

        else:
            u = n.parent.parent.right
            if u.color == 'red':
                u.color = 'black'
                n.parent.color = 'black'
                n.parent.parent.color = 'red'
                n = n.parent.parent
            elif n == n.parent.right:
                n = n.parent
                left_rotate(n)
            n.parent.color = 'black'
            n.parent.parent.color = 'red'
            right_rotate(n.parent.parent)
    root.color = 'black'

#####                    레드 블랙 트리 삽입 코드                     ######



#####                    레드 블랙 트리 검색 코드                     ######
def search(node, key):
    if node is None or node.key == key:
        return node
    if key < node.key: return search(node.left, key)
    return search(node.right, key)

#####                    레드 블랙 트리 검색 코드                     ######
#####                           과제03                           ######


x = random.sample(range(5000),1000)
value = x[800]

root = None
for i in x:
    n = Node(i, Node(None, None, None), "red")
    rb_insert(n)

start = timer()
found = search(root, value)
print(timer()-start)

if found is not None:
    print('value', value, 'found', found.key)
    print(True if found.key == value else False)