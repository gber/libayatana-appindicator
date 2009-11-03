#ifndef __CUSTOM_INDICATOR_H__
#define __CUSTOM_INDICATOR_H__

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

#define CUSTOM_INDICATOR_TYPE            (custom_indicator_get_type ())
#define CUSTOM_INDICATOR(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), CUSTOM_INDICATOR_TYPE, CustomIndicator))
#define CUSTOM_INDICATOR_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), CUSTOM_INDICATOR_TYPE, CustomIndicatorClass))
#define IS_CUSTOM_INDICATOR(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CUSTOM_INDICATOR_TYPE))
#define IS_CUSTOM_INDICATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CUSTOM_INDICATOR_TYPE))
#define CUSTOM_INDICATOR_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), CUSTOM_INDICATOR_TYPE, CustomIndicatorClass))

/**
	CustomIndicatorCategory:
	@CUSTOM_INDICATOR_CATEGORY_APPLICATION_STATUS: The indicator is used to display the status of the application.
	@CUSTOM_INDICATOR_CATEGORY_COMMUNICATIONS: The application is used for communication with other people.
	@CUSTOM_INDICATOR_CATEGORY_SYSTEM_SERVICES: A system indicator relating to something in the user's system.
	@CUSTOM_INDICATOR_CATEGORY_HARDWARE: An indicator relating to the user's hardware.
	@CUSTOM_INDICATOR_CATEGORY_OTHER: Something not defined in this enum, please don't use unless you really need it.

	The category provides grouping for the indicators so that
	users can find indicators that are similar together.
*/
typedef enum { /*< prefix=CUSTOM_INDICATOR_CATEGORY >*/
	CUSTOM_INDICATOR_CATEGORY_APPLICATION_STATUS,
	CUSTOM_INDICATOR_CATEGORY_COMMUNICATIONS,
	CUSTOM_INDICATOR_CATEGORY_SYSTEM_SERVICES,
	CUSTOM_INDICATOR_CATEGORY_HARDWARE,
	CUSTOM_INDICATOR_CATEGORY_OTHER
} CustomIndicatorCategory;

/**
	CustomIndicatorStatus:
	@CUSTOM_INDICATOR_STATUS_OFF: The indicator should not be shown to the user.
	@CUSTOM_INDICATOR_STATUS_ON: The indicator should be shown in it's default state.
	@CUSTOM_INDICATOR_STATUS_ATTENTION: The indicator should show it's attention icon.

	These are the states that the indicator can be on in
	the user's panel.  The indicator by default starts
	in the state @CUSTOM_INDICATOR_STATUS_OFF and can be
	shown by setting it to @CUSTOM_INDICATOR_STATUS_ON.
*/
typedef enum { /*< prefix=CUSTOM_INDICATOR_STATUS >*/
	CUSTOM_INDICATOR_STATUS_OFF,
	CUSTOM_INDICATOR_STATUS_ON,
	CUSTOM_INDICATOR_STATUS_ATTENTION
} CustomIndicatorStatus;

typedef struct _CustomIndicator      CustomIndicator;
typedef struct _CustomIndicatorClass CustomIndicatorClass;

struct _CustomIndicatorClass {
	GObjectClass parent_class;
};

struct _CustomIndicator {
	GObject parent;
};

/* GObject Stuff */
GType                           custom_indicator_get_type           (void);

/* Set properties */
void                            custom_indicator_set_id             (CustomIndicator * ci,
                                                                     const gchar * id);
void                            custom_indicator_set_category       (CustomIndicator * ci,
                                                                     CustomIndicatorCategory category);
void                            custom_indicator_set_status         (CustomIndicator * ci,
                                                                     CustomIndicatorStatus status);
void                            custom_indicator_set_icon           (CustomIndicator * ci,
                                                                     const gchar * icon_name);
void                            custom_indicator_set_attention_icon (CustomIndicator * ci,
                                                                     const gchar * icon_name);
void                            custom_indicator_set_menu           (CustomIndicator * ci,
                                                                     void * menu);

/* Get properties */
const gchar *                   custom_indicator_get_id             (CustomIndicator * ci);
CustomIndicatorCategory         custom_indicator_get_category       (CustomIndicator * ci);
CustomIndicatorStatus           custom_indicator_get_status         (CustomIndicator * ci);
const gchar *                   custom_indicator_get_icon           (CustomIndicator * ci);
const gchar *                   custom_indicator_get_attention_icon (CustomIndicator * ci);
void *                          custom_indicator_get_menu           (CustomIndicator * ci);

G_END_DECLS

#endif