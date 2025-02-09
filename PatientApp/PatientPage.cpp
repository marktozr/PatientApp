#include "pch.h"
#include "PatientPage.h"
#if __has_include("PatientPage.g.cpp")
#include "PatientPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::PatientApp::implementation
{
    int32_t PatientPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void PatientPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void PatientPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
