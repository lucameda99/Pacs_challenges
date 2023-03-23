
#include <muParser.h>

#include <memory>
#include <string>

class MuparserFun{
private:
    double     m_var1, m_var2;
    mu::Parser m_parser;
public:
  MuparserFun(const MuparserFun &m) : m_parser(m.m_parser){
      m_parser.DefineVar("t", &m_var1);
      m_parser.DefineVar("y", &m_var2);
  };

  MuparserFun(const std::string &s){
    try{
        m_parser.DefineVar("t", &m_var1);
        m_parser.DefineVar("y", &m_var2);
        m_parser.SetExpr(s);
      }catch (mu::Parser::exception_type &e){
        std::cerr << e.GetMsg() << std::endl;
      }
  };

  double operator()(const double &t, const double &y){
    double f = 0;

    m_var1 = t;
    m_var2 = y;

    try{
        f = m_parser.Eval();
      }catch (mu::Parser::exception_type &e){
        std::cerr << e.GetMsg() << std::endl;
      }
    return f;
  };

  double operator()(const double &t){
    double y = 0;

    m_var1 = t;

    try{
        y = m_parser.Eval();
      }catch (mu::Parser::exception_type &e){
        std::cerr << e.GetMsg() << std::endl;
      }
    return y;
  };

};