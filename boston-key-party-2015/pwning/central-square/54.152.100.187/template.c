/*
 * Vulnerable image manipulator for Central Square vulnerable service.
 * Copyright (C) 2015 Robbie Harwood <rharwood@club.cc.cmu.edu>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>

#include "image.xpm" /* provides `static char *image[]` */

int main() {
  int i;

  printf("static char *image[] = {\n"); {
    for (i = 0; image[i]; i+=2) {
      printf("\"%s\",\n", image[i+1]);
      printf("\"%s\",\n", image[i]);
    }
  } printf("};\n");
  return 0;
}
