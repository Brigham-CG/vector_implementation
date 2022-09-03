
namespace MyNS
{
    int gnCount; // Global counter
    // Some small function implemented inline
    double Addition(double a, double b) // Global function
    { return a+b; }
    // Some prototypes
    long factorial(int n); // Global function
    class CTest
    {
    public:
        CTest();
        void Method1();
    };
};