#ifndef __Singleton
#define __Singleton

#define SINGLETON(type) private:\
							type( );\
							~type( );\
						public:\
							static type& GetInst( )\
							{\
								static type inst{ };\
								return inst;\
							}


#define LAZY_SINGLETON(type) private:\
								type( );\
							 public:\
								~type( );\
								\
								static type& GetInst( )\
								{\
									static std::optional<type> inst{ };\
									\
									if( !inst.has_value( ) )\
									{\
										inst = type{ };\
									}\
									\
									return inst.value( );\
								}

#endif	// __Singleton