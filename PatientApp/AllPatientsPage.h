#pragma once

#include "AllPatientsPage.g.h"
#include "Patient.h"
#include "PatientViewModel.h"

namespace winrt::PatientApp::implementation
{
    struct AllPatientsPage : AllPatientsPageT<AllPatientsPage>
    {
        AllPatientsPage() 
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }
        winrt::PatientApp::PatientViewModel MainViewModel();

        winrt::PatientApp::Patient SelectedPatient();
        void SelectedPatient(winrt::PatientApp::Patient const& value);

    private:
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::PatientApp::Patient> m_PatientList;

        /// <summary>
        /// For binding to the edit dialog
        /// </summary>
        winrt::PatientApp::Patient m_SelectedPatient;

        /// <summary>
        /// Hold the patient object to update on Ok
        /// </summary>
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::PatientApp::Patient> m_SelectedList;

        void ShowDialog(Patient* patient);

    public:
        void patientListView_ItemClick(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::ItemClickEventArgs const& e);
        void EditPatient_PrimaryButtonClick(winrt::Microsoft::UI::Xaml::Controls::ContentDialog const& sender, winrt::Microsoft::UI::Xaml::Controls::ContentDialogButtonClickEventArgs const& args);
        void TextBlock_PreviewKeyDown(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::KeyRoutedEventArgs const& e);
    };
}

namespace winrt::PatientApp::factory_implementation
{
    struct AllPatientsPage : AllPatientsPageT<AllPatientsPage, implementation::AllPatientsPage>
    {
    };
}
