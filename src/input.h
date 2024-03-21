

#ifndef INPUT_H
#define INPUT_H

#include <string.h>
#include <gdk/gdk.h>
#ifdef GDK_WINDOWING_X11
#include <X11/extensions/XInput2.h>
#include <gdk/gdkx.h>
#endif
#ifdef GDK_WINDOWING_WAYLAND
#include <gdk/gdkwayland.h>
#endif
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

guint grab_keycode(GromitData *data, gint device_id, const char *key, int num_modifiers, XIGrabModifiers *key_modifiers, XIEventMask *mask);
guint ungrab_keycode(GromitData *data, gint device_id, const char *key, int num_modifiers, XIGrabModifiers *key_modifiers);

#endif
