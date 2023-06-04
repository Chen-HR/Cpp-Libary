#include <stdlib.h>
#include <iostream>
#include <iomanip>

struct Node
  {
    Node* Front=0;
    Node* Rear_=0;
    int   Data =0;
  };
struct List
  {
    struct Node* Begin=0;
    struct Node* End__=0;
  };

int GetData(struct List* MainList,int Index)
  {
    struct Node* Current_ = 0;
    // Focus
    if (0<=Index)
      {
        for (int i=0;i<=Index;i++)
          if (Current_==MainList->End__)
            break;
          else if (i==0)
            Current_ = MainList->Begin;
          else // if (i!=0)
            Current_ = Current_->Rear_;
      }
    else // if (Index<0)
      {
        for (int i=-1;i>=Index;i--)
          if (Current_==MainList->Begin)
            break;
          else if (i==-1)
            Current_ = MainList->End__;
          else // if (i!=-1)
            Current_ = Current_->Front;
      }
    // Process
    return Current_->Data;
  }
void SetData(struct List* MainList,int Index,int Data)
  {
    struct Node* Current_ = 0;
    // Focus
    if (0<=Index)
      {
        for (int i=0;i<=Index;i++)
          if (Current_==MainList->End__)
            break;
          else if (i==0)
            Current_ = MainList->Begin;
          else // if (i!=0)
            Current_ = Current_->Rear_;
      }
    else // if (Index<0)
      {
        for (int i=-1;i>=Index;i--)
          if (Current_==MainList->Begin)
            break;
          else if (i==-1)
            Current_ = MainList->End__;
          else // if (i!=-1)
            Current_ = Current_->Front;
      }
    // Process
    Current_->Data = Data;
  }
struct Node* GetNode(struct List* MainList,int Index)
  {
    struct Node* Current_ = 0;
    // Focus
    if (0<=Index)
      {
        for (int i=0;i<=Index;i++)
          if (Current_==MainList->End__)
            break;
          else if (i==0)
            Current_ = MainList->Begin;
          else // if (i!=0)
            Current_ = Current_->Rear_;
      }
    else // if (Index<0)
      {
        for (int i=-1;i>=Index;i--)
          if (Current_==MainList->Begin)
            break;
          else if (i==-1)
            Current_ = MainList->End__;
          else // if (i!=-1)
            Current_ = Current_->Front;
      }
    // Process
    return Current_;
  }
int GetIndex(struct List* MainList,struct Node* MainNode)
  {
    struct Node* Current_ = 0;
    int Index = 0;
    for (Index=0;MainNode!=Current_;Index++)
      if (Current_==MainList->End__)
        break;
      else if (Index==0)
        Current_ = MainList->Begin;
      else // if (Index!=0)
        Current_ = Current_->Rear_;
    return Index-1;
  }

void Creat_FromEmpty(struct List* MainList,int Data)
  {
    struct Node* Creator_= ((Node*)(calloc(1,sizeof(Node))));
    Creator_->Data  = Data ;
    Creator_->Front = 0 ;
    Creator_->Rear_ = 0 ;
    MainList->Begin = Creator_ ;
    MainList->End__ = Creator_ ;
  }
void AddInBegin (struct List* MainList,int Data)
  {
    if (MainList->Begin!=0)
      {
        struct Node* Creator_ = ((Node*)(calloc(1,sizeof(Node))));
        Creator_->Data         = Data ;
        Creator_->Rear_        = MainList->Begin ;
        MainList->Begin->Front = Creator_ ;
        MainList->Begin        = Creator_ ;
      }
    else // if (MainList->Begin==0)
      Creat_FromEmpty(MainList,Data);
  }
void AddInEnd   (struct List* MainList,int Data)
  {
    if (MainList->End__!=0)
      {
        struct Node* Creator_ = ((Node*)(calloc(1,sizeof(Node))));
        Creator_->Data         = Data ;
        Creator_->Front        = MainList->End__ ;
        MainList->End__->Rear_ = Creator_ ;
        MainList->End__        = Creator_ ;
      }
    else // if (MainList->End__==0)
      Creat_FromEmpty(MainList,Data);
  }
// Insert a Node.
// After Insert, the Node Index is Index.
void Insert     (struct List* MainList,int Index,int Data)
  {
    struct Node* Creator_ = ((Node*)(calloc(1,sizeof(Node))));
    struct Node* Front = 0;
    struct Node* Rear_ = 0;
    Creator_->Data  = Data ;
    // Focus
    if (0<=Index)
      {
        Rear_ = GetNode(MainList,Index);
        Front = Rear_->Front;
      }
    else // if (Index<0)
      {
        Front = GetNode(MainList,Index);
        Rear_ = Front->Rear_;
      }
    // Process
    if ((Front!=MainList->End__)&&(Rear_!=MainList->Begin))
      {
        Creator_->Front = Front ;
        Creator_->Rear_ = Rear_ ;
        Front->Rear_ = Creator_ ;
        Rear_->Front = Creator_ ;
      }
    else if (Rear_==MainList->Begin)
      AddInBegin(MainList,Data);
    else if (Front==MainList->End__)
      AddInEnd  (MainList,Data);
  }

void Remove_ToClear(struct List* MainList)
  {
    //if ((MainList->Begin==MainList->End__)&&(MainList->Begin!=0)&&(MainList->End__!=0))
      {
        free(MainList->Begin);
        MainList->Begin = 0;
        MainList->End__ = 0;
      }
  }
void RemoveBegin(struct List* MainList)
  {
    //if ((MainList->Begin!=0)&&(MainList->End__!=0))
      {
        if (MainList->Begin!=MainList->End__)
          {
            MainList->Begin = MainList->Begin->Rear_;
            free(MainList->Begin->Front);
            MainList->Begin->Front = 0;
          }
        else
          Remove_ToClear(MainList);
      }
  }
void RemoveEnd  (struct List* MainList)
  {
    //if ((MainList->Begin!=0)&&(MainList->End__!=0))
      {
        if (MainList->Begin!=MainList->End__)
          {
            MainList->End__ = MainList->End__->Front;
            free(MainList->End__->Rear_);
            MainList->End__->Rear_ = 0;
          }
        else
          Remove_ToClear(MainList);
      }
  }
void Remove     (struct List* MainList,int Index)
  {
    struct Node* Damager_ = 0;
    // Focus
    Damager_ = GetNode(MainList,Index);
    // Process
    if ((Damager_!=MainList->Begin)&&(Damager_!=MainList->End__))
      {
        Damager_->Rear_->Front = Damager_->Front;
        Damager_->Front->Rear_ = Damager_->Rear_;
        free(Damager_);
      }
    else if (Damager_==MainList->Begin)
      RemoveBegin(MainList);
    else if (Damager_==MainList->End__)
      RemoveEnd  (MainList);
  }

void Exchange(struct List* MainList,int Index_1,int Index_2)
  {
    struct Node* Node_1 = 0;
    struct Node* Node_2 = 0;
    // Focus Node_1
    Node_1 = GetNode(MainList,Index_1);
    // Focus Node_2
    Node_2 = GetNode(MainList,Index_2);
    // Process
    bool TempBegin = false;
    bool TempEnd__ = false;
    if ((Node_1==MainList->Begin)||(Node_2==MainList->Begin))
      {
        TempBegin = true;
        AddInBegin(MainList,MainList->Begin->Data);
      }
    if ((Node_1==MainList->End__)||(Node_2==MainList->End__))
      {
        TempEnd__ = true;
        AddInEnd  (MainList,MainList->End__->Data);
      }
    struct Node* Node_1_Front = Node_1->Front;
    struct Node* Node_1_Rear_ = Node_1->Rear_;
    struct Node* Node_2_Front = Node_2->Front;
    struct Node* Node_2_Rear_ = Node_2->Rear_;
    if ((((Node_1_Rear_!=Node_2)&&(Node_1!=Node_2_Front))&&(Node_2_Rear_!=Node_1)&&(Node_2!=Node_1_Front))) // Node_1 and Node_2 are not Neighbors.
      {
        Node_1->Front = Node_2_Front;
        Node_1->Rear_ = Node_2_Rear_;
        Node_2->Front = Node_1_Front;
        Node_2->Rear_ = Node_1_Rear_;
        Node_1_Front->Rear_ = Node_2;
        Node_1_Rear_->Front = Node_2;
        Node_2_Front->Rear_ = Node_1;
        Node_2_Rear_->Front = Node_1;
      }
    else if ((Node_1_Rear_==Node_2)&&(Node_1==Node_2_Front)) // Node_1 and Node_2 are Neighbors, Node_1 is Front at Node_2, Node_2 is Rear at Node_1.
      {
        Node_1_Front->Rear_ = Node_2;
        Node_2_Rear_->Front = Node_1;
        Node_1->Front = Node_1->Rear_;
        Node_2->Rear_ = Node_2->Front;
        Node_1->Rear_ = Node_2_Rear_;
        Node_2->Front = Node_1_Front;
      }
    else if ((Node_2_Rear_==Node_1)&&(Node_2==Node_1_Front)) // Node_2 and Node_1 are Neighbors, Node_2 is Front at Node_1, Node_1 is Rear at Node_2.
      {
        Node_2_Front->Rear_ = Node_1;
        Node_1_Rear_->Front = Node_2;
        Node_2->Front = Node_2->Rear_;
        Node_1->Rear_ = Node_1->Front;
        Node_2->Rear_ = Node_1_Rear_;
        Node_1->Front = Node_2_Front;
      }
    if (TempBegin)
      RemoveBegin(MainList);
    if (TempEnd__)
      RemoveEnd  (MainList);
  }
void Clear(struct List* MainList,int Index_Begin=0,int Index_End__=-1)
  {
    struct Node* Node_Begin = 0;
    struct Node* Node_End__ = 0;
    // Focus Node_Begin
    Node_Begin = GetNode(MainList,Index_Begin);
    // Focus Node_End__
    Node_End__ = GetNode(MainList,Index_End__);
    // Process
    while (Node_Begin->Rear_!=Node_End__)
      {
        Remove(MainList,Index_Begin+1);
      }
    Remove(MainList,Index_Begin+1);
    Remove(MainList,Index_Begin);
  }
void Copy (struct List* MainList,struct List* SubList,int Index_Begin=0,int Index_End__=-1) // Add : MainList Index
  {
    struct Node* Node_Begin = 0;
    struct Node* Node_End__ = 0;
    // Focus Node_Begin
    Node_Begin = GetNode(MainList,Index_Begin);
    // Focus Node_End__
    Node_End__ = GetNode(MainList,Index_End__);
    // Process
    struct Node* Current_ = 0;
    while (Current_!=Node_End__)
      {
        if (Current_==0)
          Current_ = Node_Begin;
        else // if (i!=-1)
          Current_ = Current_->Rear_;
        AddInEnd(MainList,Current_->Data);
      }
  }

void PrintNodeData(struct Node* Node)
  {
    //std::cout << std::setw(30) << Node->Data << std::endl ;
    std::cout << std::setw(10) << Node << "->Data  : " << std::setw(10) << Node->Data << std::endl ;
  }
void Read_FromBeginToEnd_Simple(struct List* MainList)
  {
    struct Node* Current_ = MainList->Begin;
    while (Current_!=0)
      {
        std::cout << std::setw(10) << Current_        << " : " ;
        std::cout << std::setw(10) << Current_->Front << " , " ;
        std::cout << std::setw( 5) << Current_->Data  << " , " ;
        std::cout << std::setw(10) << Current_->Rear_ << " \n" ;
        if (Current_ == MainList->End__) break;
        if (Current_ == Current_->Rear_) break;
        Current_ = Current_->Rear_;
      }
  }
void Read_FromEndToBegin_Simple(struct List* MainList)
  {
    struct Node* Current_ = MainList->End__;
    while (Current_!=0)
      {
        std::cout << std::setw(10) << Current_        << " : " ;
        std::cout << std::setw(10) << Current_->Front << " , " ;
        std::cout << std::setw( 5) << Current_->Data  << " , " ;
        std::cout << std::setw(10) << Current_->Rear_ << " \n" ;
        if (Current_ == MainList->Begin) break;
        if (Current_ == Current_->Front) break;
        Current_ = Current_->Front;
      }
  }
void Read_FromBeginToEnd_Basic(struct List* MainList)
  {
    struct Node* Current_ = MainList->Begin;
    while (Current_!=0)
      {
        std::cout << std::setw(10) << Current_ << "->Front : " << std::setw(10) << Current_->Front << std::endl ;
        PrintNodeData(Current_);
        std::cout << std::setw(10) << Current_ << "->Rear_ : " << std::setw(10) << Current_->Rear_ << std::endl ;
        if (Current_ == MainList->End__) break;
        if (Current_ == Current_->Rear_) break;
        Current_ = Current_->Rear_;
      }
  }
void Read_FromEndToBegin_Basic(struct List* MainList)
  {
    struct Node* Current_ = MainList->End__;
    while (Current_!=0)
      {
        std::cout << std::setw(10) << Current_ << "->Front : " << std::setw(10) << Current_->Front << std::endl ;
        PrintNodeData(Current_);
        std::cout << std::setw(10) << Current_ << "->Rear_ : " << std::setw(10) << Current_->Rear_ << std::endl ;
        if (Current_ == MainList->Begin) break;
        if (Current_ == Current_->Front) break;
        Current_ = Current_->Front;
      }
  }

//01_DecommissionTime=202102182300
//01  void Insert     (struct List* MainList,int Index,int Data)
//01    {
//01      struct Node* Creator_ = ((Node*)(calloc(1,sizeof(Node))));
//01      struct Node* Front = 0;
//01      struct Node* Rear_ = 0;
//01      Creator_->Data  = Data ;
//01      // Focus
//01      if (0<=Index)
//01        {
//01          for (int i=0;i<=Index;i++)
//01            if (Rear_==MainList->End__)
//01              break;
//01            else if (i==0)
//01              Rear_ = MainList->Begin;
//01            else // if (i!=0)
//01              Rear_ = Rear_->Rear_;
//01          Front = Rear_->Front;
//01        }
//01      else // if (Index<0)
//01        {
//01          for (int i=-1;i>=Index;i--)
//01            if (Front==MainList->Begin)
//01              break;
//01            else if (i==-1)
//01              Front = MainList->End__;
//01            else // if (i< -1)
//01              Front = Front->Front;
//01          Rear_ = Front->Rear_;
//01        }
//01      // Process
//01      if ((Front!=MainList->End__)&&(Rear_!=MainList->Begin))
//01        {
//01          Creator_->Front = Front ;
//01          Creator_->Rear_ = Rear_ ;
//01          Front->Rear_ = Creator_ ;
//01          Rear_->Front = Creator_ ;
//01        }
//01      else if (Rear_==MainList->Begin)
//01        AddInBegin(MainList,Data);
//01      else if (Front==MainList->End__)
//01        AddInEnd  (MainList,Data);
//01    }

//01_DecommissionTime=202102180030
//01  void RemoveBegin(struct List* MainList)
//01    {
//01      struct Node* Damager_ = MainList->Begin;
//01      struct Node* Rear_ = Damager_->Rear_;
//01      MainList->Begin = Rear_;
//01      Rear_->Front = 0;
//01      free(Damager_);
//01    }
//02_DecommissionTime=202102182215
//02  void RemoveBegin(struct List* MainList)
//02    {
//02      MainList->Begin = MainList->Begin->Rear_;
//02      free(MainList->Begin->Front);
//02      MainList->Begin->Front = 0;
//02    }

//01_DecommissionTime=202102180030
//01  void RemoveEnd  (struct List* MainList)
//01    {
//01      struct Node* Damager_ = MainList->End__;
//01      struct Node* Front = Damager_->Front;
//01      MainList->End__ = Front;
//01      Front->Rear_ = 0;
//01      free(Damager_);
//01    }
//02_DecommissionTime=202102182215
//02  void RemoveEnd  (struct List* MainList)
//02    {
//02      MainList->End__ = MainList->End__->Front;
//02      free(MainList->End__->Rear_);
//02      MainList->End__->Rear_ = 0;
//02    }

//01_DecommissionTime=202102182300
//01  void Remove     (struct List* MainList,int Index)
//01    {
//01      struct Node* Damager_ = 0;
//01      // Focus
//01      if (0<=Index)
//01        {
//01          for (int i=0;i<=Index;i++)
//01            if (Damager_==MainList->End__)
//01              break;
//01            else if (i==0)
//01              Damager_ = MainList->Begin;
//01            else // if (i!=0)
//01              Damager_ = Damager_->Rear_;
//01        }
//01      else // if (Index<0)
//01        {
//01          for (int i=-1;i>=Index;i--)
//01            if (Damager_==MainList->Begin)
//01              break;
//01            else if (i==-1)
//01              Damager_ = MainList->End__;
//01            else // if (i!=-1)
//01              Damager_ = Damager_->Front;
//01        }
//01      // Process
//01      if ((Damager_!=MainList->Begin)&&(Damager_!=MainList->End__))
//01        {
//01          Damager_->Rear_->Front = Damager_->Front;
//01          Damager_->Front->Rear_ = Damager_->Rear_;
//01          free(Damager_);
//01        }
//01      else if (Damager_==MainList->Begin)
//01        RemoveBegin(MainList);
//01      else if (Damager_==MainList->End__)
//01        RemoveEnd  (MainList);
//01    }

//01_DecommissionTime=202102182300
//01  void Exchange(struct List* MainList,int Index_1,int Index_2)
//01    {
//01      struct Node* Node_1 = 0;
//01      struct Node* Node_2 = 0;
//01      // Focus Node_1
//01      if (0<=Index_1)
//01        {
//01          for (int i=0;i<=Index_1;i++)
//01            if (Node_1==MainList->End__)
//01              break;
//01            else if (i==0)
//01              Node_1 = MainList->Begin;
//01            else // if (i!=0)
//01              Node_1 = Node_1->Rear_;
//01        }
//01      else // if (Index_1<0)
//01        {
//01          for (int i=-1;i>=Index_1;i--)
//01            if (Node_1==MainList->Begin)
//01              break;
//01            else if (i==-1)
//01              Node_1 = MainList->End__;
//01            else // if (i!=-1)
//01              Node_1 = Node_1->Front;
//01        }
//01      // Focus Node_2
//01      if (0<=Index_2)
//01        {
//01          for (int i=0;i<=Index_2;i++)
//01            if (Node_2==MainList->End__)
//01              break;
//01            else if (i==0)
//01              Node_2 = MainList->Begin;
//01            else // if (i!=0)
//01              Node_2 = Node_2->Rear_;
//01        }
//01      else // if (Index_2<0)
//01        {
//01          for (int i=-1;i>=Index_2;i--)
//01            if (Node_2==MainList->Begin)
//01              break;
//01            else if (i==-1)
//01              Node_2 = MainList->End__;
//01            else // if (i!=-1)
//01              Node_2 = Node_2->Front;
//01        }
//01      // Process
//01      bool TempBegin = false;
//01      bool TempEnd__ = false;
//01      if ((Node_1==MainList->Begin)||(Node_2==MainList->Begin))
//01        {
//01          TempBegin = true;
//01          AddInBegin(MainList,MainList->Begin->Data);
//01        }
//01      if ((Node_1==MainList->End__)||(Node_2==MainList->End__))
//01        {
//01          TempEnd__ = true;
//01          AddInEnd  (MainList,MainList->End__->Data);
//01        }
//01      struct Node* Node_1_Front = Node_1->Front;
//01      struct Node* Node_1_Rear_ = Node_1->Rear_;
//01      struct Node* Node_2_Front = Node_2->Front;
//01      struct Node* Node_2_Rear_ = Node_2->Rear_;
//01      if (!(((Node_1_Rear_==Node_2)&&(Node_1==Node_2_Front))&&(Node_2_Rear_==Node_1)&&(Node_2==Node_1_Front))) // Node_1 and Node_2 are not Neighbors.
//01        {
//01          Node_1->Front = Node_2_Front;
//01          Node_1->Rear_ = Node_2_Rear_;
//01          Node_2->Front = Node_1_Front;
//01          Node_2->Rear_ = Node_1_Rear_;
//01          Node_1_Front->Rear_ = Node_2;
//01          Node_1_Rear_->Front = Node_2;
//01          Node_2_Front->Rear_ = Node_1;
//01          Node_2_Rear_->Front = Node_1;
//01        }
//01      else if ((Node_1_Rear_==Node_2)&&(Node_1==Node_2_Front)) // Node_1 and Node_2 are Neighbors, Node_1 is Front at Node_2, Node_2 is Rear at Node_1.
//01        {
//01          Node_1->Front = Node_2;
//01          Node_2->Rear_ = Node_1;
//01          Node_1->Rear_ = Node_2_Rear_;
//01          Node_2->Front = Node_1_Front;
//01          Node_1_Front->Rear_ = Node_2;
//01          Node_2_Rear_->Front = Node_1;
//01        }
//01      else if ((Node_2_Rear_==Node_1)&&(Node_2==Node_1_Front)) // Node_2 and Node_1 are Neighbors, Node_2 is Front at Node_1, Node_1 is Rear at Node_2.
//01        {
//01          Node_2->Front = Node_1;
//01          Node_1->Rear_ = Node_2;
//01          Node_2->Rear_ = Node_1_Rear_;
//01          Node_1->Front = Node_2_Front;
//01          Node_2_Front->Rear_ = Node_1;
//01          Node_1_Rear_->Front = Node_2;
//01        }
//01      if (TempBegin)
//01        RemoveBegin(MainList);
//01      if (TempEnd__)
//01        RemoveEnd  (MainList);
//01    }

//01_DecommissionTime=202102182300
//01  void Clear(struct List* MainList,int Index_Begin=0,int Index_End__=-1)
//01    {
//01      struct Node* Node_Begin = 0;
//01      struct Node* Node_End__ = 0;
//01      // Focus Node_Begin
//01      if (0<=Index_Begin)
//01        {
//01          for (int i=0;i<=Index_Begin;i++)
//01            if (Node_Begin==MainList->End__)
//01              break;
//01            else if (i==0)
//01              Node_Begin = MainList->Begin;
//01            else // if (i!=0)
//01              Node_Begin = Node_Begin->Rear_;
//01        }
//01      else // if (Index_Begin<0)
//01        {
//01          for (int i=-1;i>=Index_Begin;i--)
//01            if (Node_Begin==MainList->Begin)
//01              break;
//01            else if (i==-1)
//01              Node_Begin = MainList->End__;
//01            else // if (i!=-1)
//01              Node_Begin = Node_Begin->Front;
//01        }
//01      // Focus Node_End__
//01      if (0<=Index_End__)
//01        {
//01          for (int i=0;i<=Index_End__;i++)
//01            if (Node_End__==MainList->End__)
//01              break;
//01            else if (i==0)
//01              Node_End__ = MainList->Begin;
//01            else // if (i!=0)
//01              Node_End__ = Node_End__->Rear_;
//01        }
//01      else // if (Index_End__<0)
//01        {
//01          for (int i=-1;i>=Index_End__;i--)
//01            if (Node_End__==MainList->Begin)
//01              break;
//01            else if (i==-1)
//01              Node_End__ = MainList->End__;
//01            else // if (i!=-1)
//01              Node_End__ = Node_End__->Front;
//01        }
//01      // Process
//01      while (Node_Begin->Rear_!=Node_End__)
//01        {
//01          Remove(MainList,Index_Begin+1);
//01        }
//01      Remove(MainList,Index_Begin+1);
//01      Remove(MainList,Index_Begin);
//01    }

//01_DecommissionTime=202102182300
//01  void Copy (struct List* MainList,struct List* SubList,int Index_Begin=0,int Index_End__=-1)
//01    {
//01      struct Node* Node_Begin = 0;
//01      struct Node* Node_End__ = 0;
//01      // Focus Node_Begin
//01      if (0<=Index_Begin)
//01        {
//01          for (int i=0;i<=Index_Begin;i++)
//01            if (Node_Begin==SubList->End__)
//01              break;
//01            else if (i==0)
//01              Node_Begin = SubList->Begin;
//01            else // if (i!=0)
//01              Node_Begin = Node_Begin->Rear_;
//01        }
//01      else // if (Index_Begin<0)
//01        {
//01          for (int i=-1;i>=Index_Begin;i--)
//01            if (Node_Begin==SubList->Begin)
//01              break;
//01            else if (i==-1)
//01              Node_Begin = SubList->End__;
//01            else // if (i!=-1)
//01              Node_Begin = Node_Begin->Front;
//01        }
//01      // Focus Node_End__
//01      if (0<=Index_End__)
//01        {
//01          for (int i=0;i<=Index_End__;i++)
//01            if (Node_End__==SubList->End__)
//01              break;
//01            else if (i==0)
//01              Node_End__ = SubList->Begin;
//01            else // if (i!=0)
//01              Node_End__ = Node_End__->Rear_;
//01        }
//01      else // if (Index_End__<0)
//01        {
//01          for (int i=-1;i>=Index_End__;i--)
//01            if (Node_End__==SubList->Begin)
//01              break;
//01            else if (i==-1)
//01              Node_End__ = SubList->End__;
//01            else // if (i!=-1)
//01              Node_End__ = Node_End__->Front;
//01        }
//01      // Process
//01      struct Node* Current_ = 0;
//01      while (Current_!=Node_End__)
//01        {
//01          if (Current_==0)
//01            Current_ = Node_Begin;
//01          else // if (i!=-1)
//01            Current_ = Current_->Rear_;
//01          AddInEnd(MainList,Current_->Data);
//01        }
//01    }

//01_DecommissionTime=202102111725
//01  int main()
//01    {
//01      struct List* MainList = ((List*)(calloc(1,sizeof(List))));
//01      if (true) // Creat
//01        {
//01          struct Node* Creator;
//01          if (true) // Creat From Null
//01            {
//01              Creator        = ((Node*)(calloc(1,sizeof(Node))));
//01              Creator->Data  = 0 ;
//01              MainList->Begin = Creator ;
//01              MainList->End__ = Creator ;
//01            }
//01          if (true) // Insert A Element in Begin
//01            {
//01              Creator        = ((Node*)(calloc(1,sizeof(Node))));
//01              Creator->Data  = 1       ;
//01              Creator->Rear_ = MainList->Begin   ;
//01              MainList->Begin->Front = Creator ;
//01              MainList->Begin = Creator ;
//01            }
//01          if (true) // Insert A Element in End
//01            {
//01              Creator        = ((Node*)(calloc(1,sizeof(Node))));
//01              Creator->Data  = 2       ;
//01              Creator->Front = MainList->End__ ;
//01              MainList->End__->Rear_ = Creator ;
//01              MainList->End__ = Creator ;
//01            }
//01        }
//01      if (true) // Read
//01        {
//01          struct Node* Current;
//01          if (true) // Read From Begin
//01            {
//01              Current=MainList->Begin;
//01              for (int i=0;i<3;i++)
//01                {
//01                  std::cout << std::setw(10) << Current << " : " << std::setw(10) << (*Current).Front << "," << std::setw(5) << (*Current).Data << "," << std::setw(10) << (*Current).Rear_<< std::endl;
//01                  Current=(*Current).Rear_;
//01                }
//01            }std::cout << std::endl;
//01          if (true) // Read From End
//01            {
//01              Current=MainList->End__;
//01              for (int i=0;i<3;i++)
//01                {
//01                  std::cout << std::setw(10) << Current << " : " << std::setw(10) << (*Current).Front << "," << std::setw(5) << (*Current).Data << "," << std::setw(10) << (*Current).Rear_<< std::endl;
//01                  Current=(*Current).Front;
//01                }
//01            }std::cout << std::endl;
//01        }
//01    return 0;
//01    }
//02_DecommissionTime=202102182200
//02  int main()
//02    {
//02      struct List* MainList = ((List*)(calloc(1,sizeof(List))));
//02      std::cout << "AddInEnd(MainList,0);" << std::endl;
//02      AddInEnd(MainList,0);
//02      Read_FromBeginToEnd_Simple(MainList);std::cout << std::endl;
//02      std::cout << "AddInEnd(MainList,1);" << std::endl;
//02      AddInEnd(MainList,1);
//02      Read_FromBeginToEnd_Simple(MainList);std::cout << std::endl;
//02      std::cout << "AddInBegin(MainList,2);" << std::endl;
//02      AddInBegin(MainList,2);
//02      Read_FromBeginToEnd_Simple(MainList);std::cout << std::endl;
//02      std::cout << "AddInEnd(MainList,3);" << std::endl;
//02      AddInEnd(MainList,3);
//02      Read_FromBeginToEnd_Simple(MainList);std::cout << std::endl;
//02      std::cout << "AddInBegin(MainList,4);" << std::endl;
//02      AddInBegin(MainList,4);
//02      Read_FromBeginToEnd_Simple(MainList);std::cout << std::endl;
//02      std::cout << "Insert(MainList,-2,5);" << std::endl;
//02      Insert(MainList,-2,5);
//02      Read_FromBeginToEnd_Simple(MainList);std::cout << std::endl;
//02      std::cout << "Insert(MainList, 1,6);" << std::endl;
//02      Insert(MainList, 1,6);
//02      Read_FromBeginToEnd_Simple(MainList);std::cout << std::endl;
//02      std::cout << "RemoveEnd(MainList);" << std::endl;
//02      RemoveEnd(MainList);
//02      Read_FromBeginToEnd_Simple(MainList);std::cout << std::endl;
//02      std::cout << "RemoveBegin(MainList);" << std::endl;
//02      RemoveBegin(MainList);
//02      Read_FromBeginToEnd_Simple(MainList);std::cout << std::endl;
//02      std::cout << "Remove(MainList,-2);" << std::endl;
//02      Remove(MainList,-2);
//02      Read_FromBeginToEnd_Simple(MainList);std::cout << std::endl;
//02      std::cout << "Remove(MainList, 1);" << std::endl;
//02      Remove(MainList, 1);
//02      Read_FromBeginToEnd_Simple(MainList);std::cout << std::endl;
//02      for (int i=0;i<3;i++) {std::cout << "GetData(MainList, " << i << ") : " << GetData(MainList, i) << std::endl;} std::cout << std::endl;
//02      for (int i=0;i<3;i++) {std::cout << "SetData(MainList, " << i << ", " << i << ") ; " << std::endl;SetData(MainList, i, i);}
//02      for (int i=0;i<3;i++) {std::cout << "GetData(MainList, " << i << ") : " << GetData(MainList, i) << std::endl;} std::cout << std::endl;
//02    }
//03_DecommissionTime=
int main()
  {
    struct List* MainList = ((List*)(calloc(1,sizeof(List))));
    for (int i=0;i<10;i++)
      {
        std::cout << "AddInEnd(MainList," << i << ");" << std::endl;
        AddInEnd(MainList,i);
      } std::cout << std::endl; Read_FromBeginToEnd_Simple(MainList); std::cout << std::endl;
    std::cout << "Copy(MainList,1,5);" << std::endl;
    Copy (MainList,MainList,1,5);
    Read_FromBeginToEnd_Simple(MainList); std::cout << std::endl;
    std::cout << "Copy(MainList,5);" << std::endl;
    Copy (MainList,MainList,5);
    Read_FromBeginToEnd_Simple(MainList); std::cout << std::endl;
    std::cout << "Copy(MainList);" << std::endl;
    Copy (MainList,MainList);
    Read_FromBeginToEnd_Simple(MainList); std::cout << std::endl;
    std::cout << "Clear(MainList,1,5);" << std::endl;
    Clear(MainList,1,5);
    Read_FromBeginToEnd_Simple(MainList); std::cout << std::endl;
    std::cout << "Clear(MainList,5);" << std::endl;
    Clear(MainList,3);
    Read_FromBeginToEnd_Simple(MainList); std::cout << std::endl;
    std::cout << "Clear(MainList);" << std::endl;
    Clear(MainList);
    Read_FromBeginToEnd_Simple(MainList); std::cout << std::endl;
    for (int i=0;i<10;i++)
      {
        std::cout << "AddInEnd(MainList," << i << ");" << std::endl;
        AddInEnd(MainList,i);
      } std::cout << std::endl; Read_FromBeginToEnd_Simple(MainList); std::cout << std::endl;
    Read_FromBeginToEnd_Simple(MainList); std::cout << std::endl;
    for (int i=0;i<10;i++)
      {
        std::cout << "GetNode(MainList," << i << ") : " << GetNode(MainList,i) << std::endl;
        std::cout << "GetIndex(MainList,GetNode(MainList," << i << ")) : " << GetIndex(MainList,GetNode(MainList,i)) << std::endl;
      }
    Read_FromBeginToEnd_Simple(MainList); std::cout << std::endl;
    for (int i=0;i<10-1;i++) for (int j=0;j<10-1-i;j++) Exchange(MainList,j,j+1);
    Read_FromBeginToEnd_Simple(MainList); std::cout << std::endl;
  }