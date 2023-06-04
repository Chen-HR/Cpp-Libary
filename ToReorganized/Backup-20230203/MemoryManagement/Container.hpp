#ifndef CONTAINER
  #define CONTAINER
  namespace Container
    {
      template <class ValueType, class ContainerType, class ObjectType> 
        ValueType sum(ContainerType& Container,ValueType (*convert)(ObjectType&))
          {
            ValueType result=0;
            for (ObjectType& item: Container)
              result += convert(item);
            return result;
          }
      template <class ValueType, class ContainerType, class ObjectType> 
        ValueType max(ContainerType& Container,ValueType (*convert)(ObjectType&))
          {
            ValueType max=convert(Container.front());
            for (ObjectType& item: Container)
              max = (max<convert(item))?convert(item):max;
            return max;
          }
      template <class ContainerType, class ObjectType, class ArgType> 
        bool exist(ContainerType& Container, ArgType& arg,bool (*rule)(ObjectType&, ArgType&))
          {
            for (ObjectType& item: Container)
              if (rule(item, arg)) return true;
            return false;
          }
      template <class ContainerType, class ObjectType, class ArgType> 
        ObjectType& select_reference(ContainerType& Container, ArgType& arg,bool (*rule)(ObjectType&, ArgType&))
          {
            for (ObjectType& item: Container)
              if (rule(item, arg)) return item;
          }
      template <class ContainerType, class ObjectType, class ArgType> 
        ObjectType* select_pointer(ContainerType& Container, ArgType& arg,bool (*rule)(ObjectType&, ArgType&))
          {
            for (ObjectType& item: Container)
              {
                if (rule(item, arg)) return &item;
              }
            return 0;
          }
      template <class ContainerType, class ObjectType> 
        void forEach(ContainerType& Container, void (*func)(ObjectType&))
          {
            for (ObjectType& item: Container) func(item);
          }
      template <class ContainerType, class ObjectType, class ArgType> 
        void forEach(ContainerType& Container, ArgType& arg, void (*func)(ObjectType&, ArgType&))
          {
            for (ObjectType& item: Container) func(item, arg);
          }
    }
#endif


