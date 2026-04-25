 def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)

        # If list is empty
        if self.head is None:
            self.head = new_node
            return

      
        temp = self.head
        while temp.next:
            temp = temp.next

        #
        temp.next = new_node
        new_node.prev = temp

 
    def traverse(self):
        temp = self.head
        while temp:
            print(temp.data, end=" ")
            temp = temp.next


n = int(input())
elements = list(map(int, input().split()))

dll = DoublyLinkedList()

for i in elements:
    dll.insert(i)


dll.traverse()
