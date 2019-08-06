#include "Resistor.h"

Resistor::Resistor(const string &_name, Node *_n1, Node *_n2, double _r)
    : Device(_name)
{
    r = _r;
    n1 = _n1;
    n2 = _n2;
    n_pos = n1->GetLocation();
    n_neg = n2->GetLocation();
    SetType(RESISTOR_TYPE);
}

Resistor::~Resistor()
{
#ifdef DEBUG
    PRINT_LINE
#endif
}

void Resistor::SetupDC(Numeric *_numeric)
{
    // do nothing, because already allocate memory.
    numeric = _numeric;
}

void Resistor::SetupAC(Numeric *_numeric)
{
    // do nothing, because already allocate memory.
    numeric = _numeric;
}

void Resistor::SetupTran(Numeric *_numeric)
{
    // do nothing, because already allocate memory.
    numeric = _numeric;
}

void Resistor::LoadDC()
{
    /*       N+       N-
     *
     * N+    1/R    -1/R
     *
     * N-   -1/R     1/R
     */   

    numeric->AddMatrixValue(n_pos, n_pos, 1.0 / r);
    numeric->AddMatrixValue(n_pos, n_neg, -1.0 / r);
    numeric->AddMatrixValue(n_neg, n_pos, -1.0 / r);
    numeric->AddMatrixValue(n_neg, n_neg, 1.0 / r);
}

void Resistor::SetDCVoltage(double _dc_voltage)
{
    dc_voltage = _dc_voltage;
}

double Resistor::GetDCVoltage() const
{
    return dc_voltage;
}

void Resistor::SetDCCurrent(double _dc_current)
{
    dc_current = _dc_current;
}

double Resistor::GetDCCurrent() const
{
    return dc_current;
}

void Resistor::SetACVoltage(Complex _ac_voltage)
{
    ac_voltage = _ac_voltage;
}

Complex Resistor::GetACVoltage() const
{
    return ac_voltage;
}

void Resistor::SetACCurrent(Complex _ac_current)
{
    ac_current = _ac_current;
}

Complex Resistor::GetACCurrent() const
{
    return ac_current;
}
