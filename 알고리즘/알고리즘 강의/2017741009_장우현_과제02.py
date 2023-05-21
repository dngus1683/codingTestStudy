import random
from timeit import default_timer as timer

class Node(object):
    def __init__(self, key, parent):
        self.key = key
        self.left = None
        self.right = None
        self.parent = parent


def insert(node, key, parent):
    if node is None:
        node = Node(key, parent)
    elif key < node.key:
        node.left = insert(node.left, key, node)
    else:
        node.right = insert(node.right, key, node)
    return node

def search(node, key):
    if node is None or node.key == key:
        return node
    if key < node.key: return search(node.left, key)
    return search(node.right, key)

#####                           과제02                           ######
#####                    이진 검색 트리 삭제 코드                     ######
def delete(node):
    global root
    if node == root:
        root = delete_node(node)
    elif node == node.parent.left:
        node.parent.left = delete_node(node)
    else:
        node.parent.right = delete_node(node)

def delete_node(node):
    if node.left is None and node.right is None:
        return None
    elif node.left is not None and node.right is None:
        return node.left
    elif node.left is None and node.right is not None:
        return node.right
    else:
        s = node.right
        while s.left is not None:
            sparent = s
            s = s.left
            node.key = s.key
        if s == node.right:
            node.right = s.right
        else:
            sparent.left = s.right
        return node

#####                    이진 검색 트리 삭제 코드                     ######
#####                           과제02                           ######

x = random.sample(range(5000),1000)
value = x[800]

root = None
for i in x:
    root = insert(root, i, None)
start = timer()
found1 = search(root, value)
print(timer()-start)

if found1 is not None:
    print('value', value, 'found', found1.key)
    print(True if found1.key == value else False)

start = timer()
delete(found1)
print(timer()-start)

found2 = search(root, value)

if found2 is None:
    print('value was deleted')
    print('found is ', found2)