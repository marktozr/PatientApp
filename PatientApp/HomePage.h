#pragma once

#include "HomePage.g.h"
#include "Patient.h"

namespace winrt::PatientApp::implementation
{
    struct HomePage : HomePageT<HomePage>
    {
        HomePage() 
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        winrt::Windows::Foundation::Collections::IObservableVector<winrt::PatientApp::Patient> PatientsList();
        void PatientsList(winrt::Windows::Foundation::Collections::IObservableVector<winrt::PatientApp::Patient> const& value);

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
    struct HomePage : HomePageT<HomePage, implementation::HomePage>
    {

    };
}
