#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include "HomePage.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace winrt::Microsoft::UI::Xaml::Controls;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::PatientApp::implementation
{
 

    void MainWindow::NavView_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {

    }


    void MainWindow::NavView_SelectionChanged(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewSelectionChangedEventArgs const& args)
    {
        if (args.IsSettingsSelected())
        {
            //ContentFrame().Navigate(xaml_typename<PatientApp::SettingsPage>());
        }
        else
        {
            auto selectedItem = args.SelectedItem().as<winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem>();
            if (selectedItem != nullptr)
            {
                hstring selectedItemTag = selectedItem.Tag().as<hstring>();
                if (selectedItemTag == L"Home")
                {
					ContentFrame().Navigate(xaml_typename<PatientApp::HomePage>());
                }
                else if (selectedItemTag == L"Patients")
                {
                    //ContentFrame().Navigate(xaml_typename<PatientApp::PatientsPage>());
                }
            }
        }

    }

    void MainWindow::ContentFrame_Navigated(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
    {

    }

}




