template <class DataType> struct Node
  {
    Node* Front=0;
    Node* Rear_=0;
    DataType Data =0;
  };
template <class NodeType> struct NodeLogger
  {
    NodeType* Begin=0;
    NodeType* End__=0;
  };
template <class DataType,class IndexType> class BasicBilateralLinkList
  {
    struct NodeLogger <struct Node <DataType>> NodeLogger;
    BasicBilateralLinkList();
  };
BasicBilateralLinkList<DataType,IndexType>::BasicBilateralLinkList()
  {
    this->NodeLogger->Begin=0;
    this->NodeLogger->End__=0;
  }