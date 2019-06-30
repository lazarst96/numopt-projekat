#include <string>
#include <map>
#include <iostream>
#include "functions.h"
#include "line_searches.h"
#include "methods.h"

using namespace std;
using namespace opt;

int main() {
    cout.precision(8);
    cout << fixed;

    typedef function::ext_rosenbrock<double> func;
    // typedef function::ext_himmelblau<double> func;
    // typedef function::gen_rosenbrock<double> func;
    // typedef function::raydan1<double> func;
    // typedef function::cube<double> func;
    // typedef function::full_hessian2<double> func;
    // typedef function::part_pert_quad<double> func;
    // typedef function::ext_psc1<double> func;
    // typedef function::ext_quad_pen_qp1<double> func;
    // typedef function::almost_pert_quad<double> func;
    // typedef function::diagonal1<double> func;
    // typedef function::gen_psc1<double> func;
    // typedef function::fletchcr<double> func;

    const int n = 1000;


    map<string, double> params;
    // line_search::binary<double> ls(params);
    // line_search::fixed_step_size<double> ls(params);
    // line_search::armijo<double> ls(params);
    // line_search::goldstein<double> ls(params);
    line_search::wolfe<double> ls(params);
    // line_search::strong_wolfe<double> ls(params);


    // method::gradient::gradient_descent<double> opt;
    // method::gradient::momentum<double> opt;
    // method::conjugate_gradient::fletcher_reeves<double> opt;
    // method::quasi_newton::sr1<double> opt;
    // method::quasi_newton::dfp<double> opt;
    // method::quasi_newton::bfgs<double> opt;
    method::quasi_newton::l_bfgs<double> opt;

    auto f = func::getFunction();
    auto x = f.starting_point(n);
    // la::vec<double> x({1, 2, 3, 4, 5, 6});

    // cout << "x:" << endl << x << endl;
    // cout << "func(x):" << endl << func::func(x) << endl;
    // cout << "grad(x):" << endl << func::gradient(x) << endl;
    // cout << "hess(x):" << endl << func::hessian(x) << endl; return 0;

    cout << "n: " << n << endl;
    cout << "Line search parameters:" << endl;
    for (auto e : params) {
        cout << e.first << ": " << e.second << endl;
    }

    opt(f, ls, x);

    // cout << "xMin: " << x << endl;
    cout << "fMin: " << opt.get_f_min() << endl;
    cout << "grNorm: " << opt.get_gr_norm() << endl;
    cout << "iterNum: " << opt.get_iter_count() << endl;
    cout << "cpuTime (s): " << opt.get_cpu_time() << endl;
    cout << "funcEval: " << opt.get_f_call_count() << endl;
    cout << "gradEval: " << opt.get_g_call_count() << endl;
    cout << "hessEval: " << opt.get_h_call_count() << endl;

    return 0;
}
