# 介绍
- The AUTOSAR Diagnostic Extract Template (DEXT) [2] is the configuration input to the DM.  
- 函数簇的概念：The individual software packages are described by SoftwareClusters.   
    each SoftwareCluster have its own DiagnosticAddresses.  
DM is intended to support an own diagnostic server instance per installed SoftwareCluster. All diagnostic server instances share a single TransportLayer instance.
tester 就是诊断仪。