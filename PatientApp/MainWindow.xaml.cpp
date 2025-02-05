#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
using namespace winrt::Microsoft::UI::Xaml::Controls;

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::PatientApp::implementation
{
    winrt::Windows::Foundation::Collections::IObservableVector<winrt::PatientApp::Patient> MainWindow::PatientsList()
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

    void MainWindow::PatientsList(winrt::Windows::Foundation::Collections::IObservableVector<winrt::PatientApp::Patient> const& value)
    {
        //throw hresult_not_implemented();
    }

    winrt::PatientApp::Patient MainWindow::SelectedPatient()
    {
        return m_SelectedPatient;
    }

    void MainWindow::SelectedPatient(winrt::PatientApp::Patient const& value)
    {
        m_SelectedPatient.Name(value.Name());
        m_SelectedPatient.Age(value.Age());
        m_SelectedPatient.BalanceDue(value.BalanceDue());
	}

    void MainWindow::patientListView_ItemClick(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::ItemClickEventArgs const& e)
    {
        auto patient = e.ClickedItem().as<Patient>();
        ShowDialog(patient.get());
    }

    void MainWindow::ShowDialog(Patient *patient)
    {
        if (m_SelectedList == nullptr) {
            m_SelectedList = winrt::single_threaded_observable_vector<winrt::PatientApp::Patient>();
        }
        m_SelectedList.Clear();
		m_SelectedList.Append(*patient);

		SelectedPatient(*patient);

        auto top = Content().as<StackPanel>();
        auto dialog = top.FindName(L"EditPatientDlg").as<ContentDialog>();
        auto result = dialog.ShowAsync();
    }

    void MainWindow::EditPatient_PrimaryButtonClick(winrt::Microsoft::UI::Xaml::Controls::ContentDialog const& sender, winrt::Microsoft::UI::Xaml::Controls::ContentDialogButtonClickEventArgs const& args)
    {
		m_SelectedList.GetAt(0).Name(SelectedPatient().Name());
		m_SelectedList.GetAt(0).Age(SelectedPatient().Age());
		m_SelectedList.GetAt(0).BalanceDue(SelectedPatient().BalanceDue());
    }

    void MainWindow::TextBlock_PreviewKeyDown(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::KeyRoutedEventArgs const& e)
    {
        // Ignores negative sign, which might need to be handled for BalanceDue
        if (e.Key() < Windows::System::VirtualKey::Number0 && e.Key() > Windows::System::VirtualKey::Number9)
		{
			e.Handled(true);
        }
    }

}

