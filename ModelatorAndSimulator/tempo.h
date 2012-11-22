#ifndef TEMPO_H
#define TEMPO_H

class Time
{
public:
    double medida;

    Time();
    Time(double medida);
    bool operator<(const Time &aNode) const;
    Time& operator=(const Time& other);
};

#endif // TEMPO_H
