template <unsigned M> struct Modular {
    using m = Modular;
    static constexpr unsigned mod = M;
    unsigned v;
    Modular(long long x = 0) : v((x %= mod) < 0 ? x + mod : x) {}
    m operator-() const { return m() -= *this; }
    m& operator+=(m b) { if ((int)(v += b.v - mod) < 0) v += mod; return *this; }
    m& operator-=(m b) { if ((int)(v -= b.v) < 0) v += mod; return *this; }
    m& operator*=(m b) { v = (uint64_t)v * b.v % mod; return *this; }
    m& operator/=(m b) { return *this *= power(b, mod - 2); }
    friend m operator+(m a, m b) { return a += b; }
    friend m operator-(m a, m b) { return a -= b; }
    friend m operator*(m a, m b) { return a *= b; }
    friend m operator/(m a, m b) { return a /= b; }
    friend bool operator==(m a, m b) { return a.v == b.v; }
};

// https://leetcode.com/problems/count-anagrams/submissions/864863202/  
