typedef unsigned int uint;

enum l_e { o, I };

enum Ls { L };

struct eLs {};

eLs operator! (Ls) { return eLs(); }

struct g { template <typename T> operator T () const { return T(); } };

template <typename T, uint n> struct excls { excls<T, n + 1> operator! () const { return g(); } };

template <typename T, uint n> struct dashes: excls<dashes<T, n>, 0> { dashes<T, n + 1> operator-- (int) const { return g(); } };

template <typename, uint> struct L_s {};

template <typename T, uint n> L_s<T, n + 1> operator| (L_s<T, n>, Ls) { return g(); }

template <typename, uint> struct eL_s {};

template <typename T, uint n> eL_s<T, n + 1> operator| (eL_s<T, n>, eLs) { return g(); }

dashes<l_e, 1> operator-- (l_e, int) { return g(); }

excls<l_e, 1> operator! (l_e) { return g(); }

template <uint len> struct line: L_s<line<len>, 0>  { static uint const length; operator uint () const { return len; } };

template <uint x, uint y> struct R { static uint const A; };

template <uint x, uint y, uint z> struct C { static uint const V; };

template <uint x, uint y> uint const R<x, y>::A = x * y;

template <uint x, uint y, uint z> uint const C<x, y, z>::V = x * y * z;

line<0> operator- (l_e, l_e) { return g(); }

template <uint x> line<x> operator- (dashes<l_e, x>, l_e) { return g(); }

template <uint x, uint y> struct lower_R {};

template <uint excl_marks, uint x>
lower_R<x, (excl_marks + 1) / 2> operator- (excls<dashes<l_e, x>, excl_marks>, l_e)
{ return g(); }

template <uint x, uint y> R<x, y> operator| (line<x>, lower_R<x, y>) { return g(); }

template <uint x, uint y, uint z> struct C_T {};

template <uint x, uint y, uint z> struct H_C {};

template <uint x, uint n> C_T<x, n + 1, n> operator| (L_s<line<x>, n>, line<x>) { return g(); }

template <uint x, uint y, uint z, uint n>
eL_s<H_C<x, y + (n + 1) / 3, z>, 0>
operator| (C_T<x, y, z>, excls<l_e, n>) { return g(); }

template <uint x, uint y, uint z>
C<x, y, z> operator| (eL_s<H_C<x, y, z>, z>, lower_R<x, 1>) { return g(); }
