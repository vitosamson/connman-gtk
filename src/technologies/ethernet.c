/*
 * ConnMan GTK GUI
 *
 * Copyright (C) 2015 Intel Corporation. All rights reserved.
 * Author: Jaakko Hannikainen <jaakko.hannikainen@intel.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>

#include "ethernet.h"
#include "technology.h"

struct ethernet_technology {
	struct technology parent;
};

struct technology *technology_ethernet_create(void) {
	struct ethernet_technology *item = g_malloc(sizeof(*item));
	return (struct technology *)item;
}

void technology_ethernet_free(struct technology *tech) {
	technology_free(tech);
}

void technology_ethernet_service_add(struct service *service) {
}

void technology_ethernet_service_remove(const gchar *path) {
}

void technology_ethernet_init(struct technology *tech, GVariantDict *properties) {
	gtk_image_set_from_icon_name(GTK_IMAGE(tech->list_item->icon),
			"network-wired-symbolic", GTK_ICON_SIZE_LARGE_TOOLBAR);
	gtk_image_set_from_icon_name(GTK_IMAGE(tech->settings->icon),
			"network-wired", GTK_ICON_SIZE_DIALOG);
	tech->add_service = technology_ethernet_service_add;
	tech->remove_service = technology_ethernet_service_remove;
	tech->free = technology_ethernet_free;
}
