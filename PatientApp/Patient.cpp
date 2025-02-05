#include "pch.h"
#include "Patient.h"
#include "Patient.g.cpp"


namespace winrt::PatientApp::implementation
{
    hstring Patient::Name()
    {
		return m_name;
    }
    void Patient::Name(hstring const& value)
    {
		if (m_name != value)
		{
			m_name = value;
			RaisePropertyChanged(L"Name");
		}
    }

    int32_t Patient::Age()
    {
		return m_age;
    }
    void Patient::Age(int32_t value)
    {
        if (m_age != value)
        {
            m_age = value;
            RaisePropertyChanged(L"Age");
        }
    }

    int32_t Patient::BalanceDue()
    {
		return m_balanceDue;
    }
    void Patient::BalanceDue(int32_t value)
    {
        if (m_balanceDue != value)
        {
            m_balanceDue = value;
            RaisePropertyChanged(L"BalanceDue");
        }
    }

    winrt::event_token Patient::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
		return m_propertyChanged.add(handler);
    }
    void Patient::PropertyChanged(winrt::event_token const& token) noexcept
    {
		m_propertyChanged.remove(token);
    }

    void Patient::RaisePropertyChanged(hstring const& propertyName)
    {
        m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs(propertyName));
    }
}
