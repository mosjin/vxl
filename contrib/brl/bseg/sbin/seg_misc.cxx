#include <vgui/vgui.h>
#include <vgui/vgui_adaptor.h>
#include <vgui/vgui_window.h>
#include <segv/segv_misc_menus.h>
#include <segv/segv_misc_manager.h>

int main(int argc, char** argv)
{
#if 1
  int my_argc = argc+1;
  char** my_argv = new char*[argc+1];
  for (int i=0; i<argc; i++)
    my_argv[i] = argv[i];
  my_argv[argc] = "--mfc-use-gl";

   // Initialize the toolkit.
  vgui::init(my_argc, my_argv);
  delete [] my_argv;
#endif
//  vgui::init(argc, argv);
  vgui_menu menubar = segv_misc_menus::get_menu();
  unsigned w = 400, h = 340;
   vcl_string title = "MISC_TOOLS";
   vgui_window* win = vgui::produce_window(w, h, menubar, title);
   segv_misc_manager* segm = 
     segv_misc_manager::instance();
   segm->set_window(win);
   win->get_adaptor()->set_tableau(segm);
   win->set_statusbar(true);
   win->enable_vscrollbar(true);
   win->enable_hscrollbar(true);
   win->show();
   vgui::run();
   return 0;
}
