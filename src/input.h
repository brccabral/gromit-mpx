

#ifndef INPUT_H
#define INPUT_H

#include "main.h"

void setup_input_devices(GromitData *data);
void shutdown_input_devices(GromitData *data);
void release_grab(GromitData *data, GdkDevice *dev);
void acquire_grab(GromitData *data, GdkDevice *dev);
void toggle_grab(GromitData *data, GdkDevice *dev);
gint snoop_key_press(GtkWidget *grab_widget, GdkEventKey *event, gpointer func_data);

typedef struct
{
  unsigned int m_keycode, m_modifiers;
} HotKey;

guint grab_keycode(GdkDisplay *display, gint device_id, unsigned int keysym, unsigned int keymodifiers, GdkWindow *win);

#endif
