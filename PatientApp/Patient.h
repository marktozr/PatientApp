#pragma once
#include "Patient.g.h"

namespace winrt::PatientApp::implementation
{
    struct Patient : PatientT<Patient>
    {
        Patient() = default;

        hstring Name();
        void Name(hstring const& value);

        int32_t Age();
        void Age(int32_t value);

        int32_t BalanceDue();
        void BalanceDue(int32_t value);

        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
        void RaisePropertyChanged(hstring const& propertyName);

    private:
        hstring m_name;
        int32_t m_age;
        int32_t m_balanceDue;
    };
}
namespace winrt::PatientApp::factory_implementation
{
    struct Patient : PatientT<Patient, implementation::Patient>
    {
    };
}
