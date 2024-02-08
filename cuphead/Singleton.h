#ifndef __Singleton
#define __Singleton

#define SINGLETON(type) public:\
							static type* GetInst( )\
							{\
								static type mgr;\
								return &mgr;\
							}\
						private:\
							type( );\
							~type( );

#endif	// __Singleton