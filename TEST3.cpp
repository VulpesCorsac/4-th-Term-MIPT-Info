#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

#include <omp.h>

#define all(c) c.begin(), c.end()

using namespace std;

class Time {
private:
    int Year;
    int Month;
    int Day;
    int Hours;
    int Minutes;
    double Seconds;
    double All_Seconds;

    int round(double x) {
        return floor(x + 0.5);
    }

    void Clear() {
        this->Year = 0;
        this->Month = 0;
        this->Day = 0;
        this->Hours = 0;
        this->Minutes = 0;
        this->Seconds = 0;
        this->All_Seconds = 0;
    }

public:
    void Modify(bool From_All_Seconds = false) {
        if (From_All_Seconds)
            this->Seconds = this->All_Seconds;
        if (this->Seconds >= 60) {
            this->Minutes += round(this->Seconds / 60);
            this->Seconds -= round(this->Seconds / 60);
        }
        if (this->Minutes >= 60) {
            this->Hours += this->Minutes / 60;
            this->Minutes %= 60;
        }
        if (this->Hours >= 60) {
            this->Day += this->Hours / 60;
            this->Hours %= 60;
        }
        if (this->Day >= 30) {
            this->Month += this->Day / 30;
            this->Day %= 30;
        }
        if (this->Month >= 12) {
            this->Year += this->Month / 12;
            this->Month %= 12;
        }
        this->All_Seconds = Seconds + 60*(this->Minutes + 60*(this->Hours + 24*(this->Day + 30*(this->Month + 12*this->Year))));
    }

    double Get_All_Seconds() {
        Modify();
        return this->All_Seconds;
    }

    void Set_All_Seconds(const double &_Seconds = 0) {
        this->All_Seconds = _Seconds;
        Modify(true);
    }

    void Set_Time(const int &_Year = 0, const int &_Month = 0, const int &_Day = 0, const int &_Hours = 0, const int &_Minutes = 0, const double &_Seconds = 0) {
        this->Year = _Year;
        this->Month = _Month;
        this->Day = _Day;
        this->Hours = _Hours;
        this->Minutes = _Minutes;
        this->Seconds = _Seconds;
        Modify();
    }

    Time(const int &_Year, const int &_Month, const int &_Day, const int &_Hours, const int &_Minutes, const double &_Seconds) {
        Clear();
        Set_Time(_Year, _Month, _Day, _Hours, _Minutes, _Seconds);
    }

    Time(const double &_Seconds = 0) {
        Clear();
        Set_All_Seconds(_Seconds);
    }

    ~Time() {
        Clear();
    }

    friend Time operator + (Time &T1, Time &T2) {
        return Time(T1.Get_All_Seconds() + T2.Get_All_Seconds());
    }

    friend Time operator - (Time &T1, Time &T2) {
        if (T1.Get_All_Seconds() < T2.Get_All_Seconds()) {
            cerr << "Negative time!";
            throw -1;
        }
        return Time(T1.Get_All_Seconds() - T2.Get_All_Seconds());
    }

    friend Time operator * (double m, Time &T) {
        return Time(m*T.Get_All_Seconds());
    }

    friend std::ostream& operator << (std::ostream& outputstream, Time &T) {
        outputstream << T.Year << "y" << T.Month << "m" << T.Day << "d" << T.Hours << "h" << T.Minutes << "m" << T.Seconds << "s";
        return outputstream;
    }

    friend std::istream& operator >> (std::istream& inputstream, Time &T) {
        double _Seconds;
        inputstream >> _Seconds;
        T.Set_All_Seconds(_Seconds);
        return inputstream;
    }

    friend bool operator == (Time &left, Time &right) {
        return (left.Get_All_Seconds() == right.Get_All_Seconds());
    }

    friend bool operator != (Time &left, Time &right) {
        return (!(left == right));
    }

    friend bool operator < (Time &left, Time &right) {
        return (left.Get_All_Seconds() < right.Get_All_Seconds());
    }

    friend bool operator > (Time &left, Time &right) {
        return (left.Get_All_Seconds() > right.Get_All_Seconds());
    }

};

class Experiment_Data {
public:
    Time T;
    int Threads_Ammount;
};

bool comparator(Experiment_Data D1, Experiment_Data D2) {
    return (D1.T > D2.T);
}

class Experiment {
private:
    int Array_size;
    int Threads_max_ammount;

    vector < int > A;
    vector < int > B;
    vector < int > C;

    vector < Experiment_Data > Data;

    void Fill_Default_Arrays() {
        this->A.resize(this->Array_size);
        this->B.resize(this->Array_size);
        this->C.clear();
        for (int i = 0; i < this->Array_size; i++) {
            this->A[i] = i;
            this->B[i] = this->Array_size - i;
        }
    }

    void Run_Sum(int Threads) {
        C.clear();
        C.resize(Array_size);
        omp_set_num_threads(Threads);
        int i;
        Experiment_Data Current_Data;
        Current_Data.Threads_Ammount = Threads;
        Time T1(omp_get_wtime());
        #pragma omp parallel for
            for (i = 0; i < Array_size; i++)
                C[i] = A[i] + B[i];
        Time T2(omp_get_wtime());
        Current_Data.T = T2 - T1;
        Data.push_back(Current_Data);
    }

public:
    void Run() {
        Fill_Default_Arrays();
        int Threads = 1;
        while (Threads <= this->Threads_max_ammount) {
            Run_Sum(Threads);
            Threads *= 2;
        }
        sort(all(Data), comparator);
        for (size_t i = 0; i < Data.size(); i++)
            cout << "Threads:" << Data[i].Threads_Ammount << ", Time:" << Data[i].T << endl;
    }

    Experiment(int _Array_size = 1000000, int _Threads_max_ammount = 16) {
        this->Array_size = _Array_size;
        this->Threads_max_ammount = _Threads_max_ammount;
    }

    ~Experiment() {

    }
};

int main() {
    Experiment Ex;
    Ex.Run();

    return 0;
}
