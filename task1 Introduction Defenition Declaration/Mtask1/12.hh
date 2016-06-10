#ifdef MACRO_DEKL

#define DECL_12( prefix ) \
	void prefix##_one(); \
	void prefix##_two();

DECL_12(prepare)
DECL_12(work)

#endif // !MACRO_DEKL


