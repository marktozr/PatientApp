#pragma once

#include "PatientViewModel.g.h"
#include "Patient.h"

namespace winrt::PatientApp::implementation
{
    struct PatientViewModel : PatientViewModelT<PatientViewModel>
    {
        PatientViewModel() = default;
        static winrt::PatientApp::PatientViewModel Instance();

        winrt::Windows::Foundation::Collections::IObservableVector<winrt::PatientApp::Patient> PatientList();

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
    };
}

namespace winrt::PatientApp::factory_implementation
{
    struct PatientViewModel : PatientViewModelT<PatientViewModel, implementation::PatientViewModel>
    {
    };
}
