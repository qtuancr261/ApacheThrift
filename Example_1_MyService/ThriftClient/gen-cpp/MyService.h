/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef MyService_H
#define MyService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "thrift_file_types.h"

namespace ZTE {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class MyServiceIf {
 public:
  virtual ~MyServiceIf() {}
  virtual int64_t send(const std::string& p1, const int32_t p2, const int64_t p3, const std::vector<int32_t> & p4, const std::vector<std::string> & p5, const std::map<std::string, int32_t> & p6) = 0;
  virtual void receive(MyData& _return, const std::string& p1) = 0;
  virtual void getData(const std::string& p3) = 0;
};

class MyServiceIfFactory {
 public:
  typedef MyServiceIf Handler;

  virtual ~MyServiceIfFactory() {}

  virtual MyServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(MyServiceIf* /* handler */) = 0;
};

class MyServiceIfSingletonFactory : virtual public MyServiceIfFactory {
 public:
  MyServiceIfSingletonFactory(const boost::shared_ptr<MyServiceIf>& iface) : iface_(iface) {}
  virtual ~MyServiceIfSingletonFactory() {}

  virtual MyServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(MyServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<MyServiceIf> iface_;
};

class MyServiceNull : virtual public MyServiceIf {
 public:
  virtual ~MyServiceNull() {}
  int64_t send(const std::string& /* p1 */, const int32_t /* p2 */, const int64_t /* p3 */, const std::vector<int32_t> & /* p4 */, const std::vector<std::string> & /* p5 */, const std::map<std::string, int32_t> & /* p6 */) {
    int64_t _return = 0;
    return _return;
  }
  void receive(MyData& /* _return */, const std::string& /* p1 */) {
    return;
  }
  void getData(const std::string& /* p3 */) {
    return;
  }
};

typedef struct _MyService_send_args__isset {
  _MyService_send_args__isset() : p1(false), p2(false), p3(false), p4(false), p5(false), p6(false) {}
  bool p1 :1;
  bool p2 :1;
  bool p3 :1;
  bool p4 :1;
  bool p5 :1;
  bool p6 :1;
} _MyService_send_args__isset;

class MyService_send_args {
 public:

  MyService_send_args(const MyService_send_args&);
  MyService_send_args& operator=(const MyService_send_args&);
  MyService_send_args() : p1(), p2(0), p3(0) {
  }

  virtual ~MyService_send_args() throw();
  std::string p1;
  int32_t p2;
  int64_t p3;
  std::vector<int32_t>  p4;
  std::vector<std::string>  p5;
  std::map<std::string, int32_t>  p6;

  _MyService_send_args__isset __isset;

  void __set_p1(const std::string& val);

  void __set_p2(const int32_t val);

  void __set_p3(const int64_t val);

  void __set_p4(const std::vector<int32_t> & val);

  void __set_p5(const std::vector<std::string> & val);

  void __set_p6(const std::map<std::string, int32_t> & val);

  bool operator == (const MyService_send_args & rhs) const
  {
    if (!(p1 == rhs.p1))
      return false;
    if (!(p2 == rhs.p2))
      return false;
    if (!(p3 == rhs.p3))
      return false;
    if (!(p4 == rhs.p4))
      return false;
    if (!(p5 == rhs.p5))
      return false;
    if (!(p6 == rhs.p6))
      return false;
    return true;
  }
  bool operator != (const MyService_send_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MyService_send_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class MyService_send_pargs {
 public:


  virtual ~MyService_send_pargs() throw();
  const std::string* p1;
  const int32_t* p2;
  const int64_t* p3;
  const std::vector<int32_t> * p4;
  const std::vector<std::string> * p5;
  const std::map<std::string, int32_t> * p6;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MyService_send_result__isset {
  _MyService_send_result__isset() : success(false) {}
  bool success :1;
} _MyService_send_result__isset;

class MyService_send_result {
 public:

  MyService_send_result(const MyService_send_result&);
  MyService_send_result& operator=(const MyService_send_result&);
  MyService_send_result() : success(0) {
  }

  virtual ~MyService_send_result() throw();
  int64_t success;

  _MyService_send_result__isset __isset;

  void __set_success(const int64_t val);

  bool operator == (const MyService_send_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const MyService_send_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MyService_send_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MyService_send_presult__isset {
  _MyService_send_presult__isset() : success(false) {}
  bool success :1;
} _MyService_send_presult__isset;

class MyService_send_presult {
 public:


  virtual ~MyService_send_presult() throw();
  int64_t* success;

  _MyService_send_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _MyService_receive_args__isset {
  _MyService_receive_args__isset() : p1(false) {}
  bool p1 :1;
} _MyService_receive_args__isset;

class MyService_receive_args {
 public:

  MyService_receive_args(const MyService_receive_args&);
  MyService_receive_args& operator=(const MyService_receive_args&);
  MyService_receive_args() : p1() {
  }

  virtual ~MyService_receive_args() throw();
  std::string p1;

  _MyService_receive_args__isset __isset;

  void __set_p1(const std::string& val);

  bool operator == (const MyService_receive_args & rhs) const
  {
    if (!(p1 == rhs.p1))
      return false;
    return true;
  }
  bool operator != (const MyService_receive_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MyService_receive_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class MyService_receive_pargs {
 public:


  virtual ~MyService_receive_pargs() throw();
  const std::string* p1;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MyService_receive_result__isset {
  _MyService_receive_result__isset() : success(false) {}
  bool success :1;
} _MyService_receive_result__isset;

class MyService_receive_result {
 public:

  MyService_receive_result(const MyService_receive_result&);
  MyService_receive_result& operator=(const MyService_receive_result&);
  MyService_receive_result() {
  }

  virtual ~MyService_receive_result() throw();
  MyData success;

  _MyService_receive_result__isset __isset;

  void __set_success(const MyData& val);

  bool operator == (const MyService_receive_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const MyService_receive_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MyService_receive_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MyService_receive_presult__isset {
  _MyService_receive_presult__isset() : success(false) {}
  bool success :1;
} _MyService_receive_presult__isset;

class MyService_receive_presult {
 public:


  virtual ~MyService_receive_presult() throw();
  MyData* success;

  _MyService_receive_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _MyService_getData_args__isset {
  _MyService_getData_args__isset() : p3(false) {}
  bool p3 :1;
} _MyService_getData_args__isset;

class MyService_getData_args {
 public:

  MyService_getData_args(const MyService_getData_args&);
  MyService_getData_args& operator=(const MyService_getData_args&);
  MyService_getData_args() : p3() {
  }

  virtual ~MyService_getData_args() throw();
  std::string p3;

  _MyService_getData_args__isset __isset;

  void __set_p3(const std::string& val);

  bool operator == (const MyService_getData_args & rhs) const
  {
    if (!(p3 == rhs.p3))
      return false;
    return true;
  }
  bool operator != (const MyService_getData_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MyService_getData_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class MyService_getData_pargs {
 public:


  virtual ~MyService_getData_pargs() throw();
  const std::string* p3;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

class MyServiceClient : virtual public MyServiceIf {
 public:
  MyServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  MyServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int64_t send(const std::string& p1, const int32_t p2, const int64_t p3, const std::vector<int32_t> & p4, const std::vector<std::string> & p5, const std::map<std::string, int32_t> & p6);
  void send_send(const std::string& p1, const int32_t p2, const int64_t p3, const std::vector<int32_t> & p4, const std::vector<std::string> & p5, const std::map<std::string, int32_t> & p6);
  int64_t recv_send();
  void receive(MyData& _return, const std::string& p1);
  void send_receive(const std::string& p1);
  void recv_receive(MyData& _return);
  void getData(const std::string& p3);
  void send_getData(const std::string& p3);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class MyServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<MyServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (MyServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_send(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_receive(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getData(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  MyServiceProcessor(boost::shared_ptr<MyServiceIf> iface) :
    iface_(iface) {
    processMap_["send"] = &MyServiceProcessor::process_send;
    processMap_["receive"] = &MyServiceProcessor::process_receive;
    processMap_["getData"] = &MyServiceProcessor::process_getData;
  }

  virtual ~MyServiceProcessor() {}
};

class MyServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  MyServiceProcessorFactory(const ::boost::shared_ptr< MyServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< MyServiceIfFactory > handlerFactory_;
};

class MyServiceMultiface : virtual public MyServiceIf {
 public:
  MyServiceMultiface(std::vector<boost::shared_ptr<MyServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~MyServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<MyServiceIf> > ifaces_;
  MyServiceMultiface() {}
  void add(boost::shared_ptr<MyServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int64_t send(const std::string& p1, const int32_t p2, const int64_t p3, const std::vector<int32_t> & p4, const std::vector<std::string> & p5, const std::map<std::string, int32_t> & p6) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->send(p1, p2, p3, p4, p5, p6);
    }
    return ifaces_[i]->send(p1, p2, p3, p4, p5, p6);
  }

  void receive(MyData& _return, const std::string& p1) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->receive(_return, p1);
    }
    ifaces_[i]->receive(_return, p1);
    return;
  }

  void getData(const std::string& p3) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getData(p3);
    }
    ifaces_[i]->getData(p3);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class MyServiceConcurrentClient : virtual public MyServiceIf {
 public:
  MyServiceConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  MyServiceConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int64_t send(const std::string& p1, const int32_t p2, const int64_t p3, const std::vector<int32_t> & p4, const std::vector<std::string> & p5, const std::map<std::string, int32_t> & p6);
  int32_t send_send(const std::string& p1, const int32_t p2, const int64_t p3, const std::vector<int32_t> & p4, const std::vector<std::string> & p5, const std::map<std::string, int32_t> & p6);
  int64_t recv_send(const int32_t seqid);
  void receive(MyData& _return, const std::string& p1);
  int32_t send_receive(const std::string& p1);
  void recv_receive(MyData& _return, const int32_t seqid);
  void getData(const std::string& p3);
  void send_getData(const std::string& p3);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif
