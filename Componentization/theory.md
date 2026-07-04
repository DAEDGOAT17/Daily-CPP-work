this is a theory file for the componentization concept :
  every node we write gets compiled into its own indivisual standalone binary file . when we run five nodes , the operating system spawns five saprate processes if these processes needs to talk to each other data must be serialized and sent over a network socket and desearialized . this  adds a massive overhead .
  but in order to overcome this we compile this into a shared library  the node becomes a plugin module ----- called a component .
  because the nodes are now just a modular shared library  we can  now boot up a single master process wrapper called a component manager .
  this can now dynamically open and instantiate multiple nodes inside the exact same process container . 
 this help us in instantaneous data transfer and almost zero cpu overhead 
