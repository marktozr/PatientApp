#include "pch.h"
#include "AllPatientsPage.h"
#if __has_include("AllPatientsPage.g.cpp")
#include "AllPatientsPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml::Controls;

namespace winrt::PatientApp::implementation
{
    winrt::PatientApp::PatientViewModel AllPatientsPage::MainViewModel()
    {
        return PatientViewModel::Instance();
    }

    winrt::PatientApp::Patient AllPatientsPage::SelectedPatient()
    {
        return m_SelectedPatient;
    }

    void AllPatientsPage::SelectedPatient(winrt::PatientApp::Patient const& value)
    {
        m_SelectedPatient.Name(value.Name());
        m_SelectedPatient.Age(value.Age());
        m_SelectedPatient.BalanceDue(value.BalanceDue());
    }

    void AllPatientsPage::patientListView_ItemClick(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::ItemClickEventArgs const& e)
    {
        auto patient = e.ClickedItem().as<Patient>();
        ShowDialog(patient.get());
    }

    void AllPatientsPage::ShowDialog(Patient* patient)
    {
        if (m_SelectedList == nullptr) {
            m_SelectedList = winrt::single_threaded_observable_vector<winrt::PatientApp::Patient>();
        }
        m_SelectedList.Clear();
        m_SelectedList.Append(*patient);

        SelectedPatient(*patient);

        auto top = Content().as<StackPanel>();
        auto dialog = top.FindName(L"EditPatientDlg").as<ContentDialog>();
        dialog.ShowAsync();
    }

    void AllPatientsPage::EditPatient_PrimaryButtonClick(winrt::Microsoft::UI::Xaml::Controls::ContentDialog const& sender, winrt::Microsoft::UI::Xaml::Controls::ContentDialogButtonClickEventArgs const& args)
    {
        m_SelectedList.GetAt(0).Name(SelectedPatient().Name());
        m_SelectedList.GetAt(0).Age(SelectedPatient().Age());
        m_SelectedList.GetAt(0).BalanceDue(SelectedPatient().BalanceDue());
    }

    void AllPatientsPage::TextBlock_PreviewKeyDown(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::KeyRoutedEventArgs const& e)
    {
        // Ignores negative sign, which might need to be handled for BalanceDue
        if (e.Key() < Windows::System::VirtualKey::Number0 && e.Key() > Windows::System::VirtualKey::Number9)
        {
            e.Handled(true);
        }
    }

}
