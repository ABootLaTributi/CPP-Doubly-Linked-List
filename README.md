# CPP-Doubly-Linked-List
C++ implementation of a doubly linked list featuring bidirectional traversal, dynamic node management, front/back insertion and deletion, reverse output, and O(1) endpoint operations.

The IntNode contains both prev and next pointers, creating the bidirectional structure of a doubly linked list. The IntList interface provides push_front, pop_front, push_back, pop_back, emptiness checking, forward stream output, and reverse traversal.

The project also explicitly targets O(1) back insertion and removal, using a tail pointer rather than traversing the entire list. Your reverse-output routine demonstrates the main advantage of a doubly linked structure by starting at the tail and following prev pointers toward the head. 
