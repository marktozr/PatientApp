#include "pch.h"
#include "PatientViewModel.h"
#if __has_include("PatientViewModel.g.cpp")
#include "PatientViewModel.g.cpp"
#endif

namespace winrt::PatientApp::implementation
{

    winrt::PatientApp::PatientViewModel PatientViewModel::Instance()
    {
        static auto instance = winrt::PatientApp::PatientViewModel();
        return instance;
    }

    winrt::Windows::Foundation::Collections::IObservableVector<winrt::PatientApp::Patient> PatientViewModel::PatientList()
    {
        if (m_PatientList == nullptr)
        {
            // Load some data
            auto children = winrt::single_threaded_observable_vector<winrt::PatientApp::Patient>();
            auto child = winrt::make<winrt::PatientApp::implementation::Patient>();
            child.Name(L"John Doe");
            child.Age(42);
            child.BalanceDue(120);
            children.Append(child);

            child = winrt::make<winrt::PatientApp::implementation::Patient>();
            child.Name(L"Jane Doe");
            child.Age(15);
            child.BalanceDue(0);
            children.Append(child);

            child = winrt::make<winrt::PatientApp::implementation::Patient>();
            child.Name(L"Jim Doe");
            child.Age(86);
            child.BalanceDue(20);
            children.Append(child);

            m_PatientList = children;
        }
        return m_PatientList;
    }

    winrt::PatientApp::Patient PatientViewModel::SelectedPatient()
    {
        return m_SelectedPatient;
    }

    void PatientViewModel::SelectedPatient(winrt::PatientApp::Patient const& value)
    {
        m_SelectedPatient.Name(value.Name());
        m_SelectedPatient.Age(value.Age());
        m_SelectedPatient.BalanceDue(value.BalanceDue());
    }
}
