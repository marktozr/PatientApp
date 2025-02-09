﻿#pragma once

#include "PatientPage.g.h"

namespace winrt::PatientApp::implementation
{
    struct PatientPage : PatientPageT<PatientPage>
    {
        PatientPage() 
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::PatientApp::factory_implementation
{
    struct PatientPage : PatientPageT<PatientPage, implementation::PatientPage>
    {
    };
}
