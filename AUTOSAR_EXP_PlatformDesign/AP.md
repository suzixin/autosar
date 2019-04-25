## stage management
AUTOSAR决定不再为Adaptive Platform提供CP中的BswM功能，仅指定一组基本服务接口并将实际仲裁逻辑封装到项目特定代码中。仲裁逻辑代码可以基于标准化配置参数单独开发或（部分）生成。

## Communication Management
### service-oriented communication
A service consists of a combination of  
 Events  
 Methods  
 Fields  
![](service-oriented_communication.PNG)  

### Language binding and Network binding
编程语言绑定是通常由服务接口定义提供的源代码生成器实现。
Network binding can be implemented based on Communication Management configuration (interface definition of the AUTOSAR meta model)
Service Registry也是Network Binding的一部分。

### Generated Proxies and Skeletons of C++ Language Binding
On the service implementation side, these generated classes are named **Service Provider Skeletons**. On the client side, they are called **Service Requester Proxies**. 

For Service Methods, a **Service Requester Proxy** provides mechanisms for synchronous (blocking the caller until the server returns a result) and asynchronous calling (called function returns immediately)——同步调用和异步调用。

### Static and dynamic configuration
- Full static configuration
- No discovery by application code
- Full service discovery in the application

## RESTful Communication
### 概述
该框架是模块化的，它使开发人员能够直接访问RESTful消息中涉及的不同层。相比之下，ara::com的重点是提供传统的函数调用接口，并隐藏其中的所有细节。另一个重要的区别是ara::rest可以与非AUTOSAR系统相互通信。

### 架构
![](ara_rest_stack_architecture_overview.PNG)

The generic REST layer of ara::rest only provides three fundamental abstractions: A tree-structured message payload (Object Graph), a URI and a request method (like GET or POST known from HTTP). 
当不需要进一步抽象时，Adaptive Application也可以直接使用ara::rest，而不是使用Domain API。

### 组件
![](ara_rest_components.PNG)  
Object Graph是ara::rest的基石，它建立从消息协议格式到c结构体的映射。
Router将通用REST具体化为特定类型的RESTful API。
ara::rest为服务器和客户端通信提供了所谓的（网络）端点。

## 诊断
### 概要
- realizes the ISO 14229-5 (UDSonIP) based on  
    - the ISO 14229-1 (UDS) 
    - the ISO 13400-2 (DoIP).
- language independent
- 从CP中的诊断服务DEXT发展而来，接口与CP保持一致，方便跨平台移植。
- The supported Transport Layer is DoIP. 
- the Adaptive Diagnostics Manager supports an own diagnostics Server instance for each installed SoftwareCluster having its own DiagnosticAddress. 

