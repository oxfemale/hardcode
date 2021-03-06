/*
 * This file is part of "fingubni samselpla selsa'a" (FSS)
 * Copyright (C) 2017 PoroCYon
 *
 * FSS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3,
 * or at your option, any later version, as
 * published by the Free Software Foundation.
 *
 * FSS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with FSS. If not, see <https://www.gnu.org/licenses/>.
 */
/*
 * lo ti datnyvei cu pagbu la fingubni samselpla selsa'a goi fysysy
 * noi proga gi'e se fukyzifpo'e la'oi PoroCYon de'i li 2017
 *
 * .i fysysy fingubni .ija'ebo do .e'a ti fairgau gi'e galfi
 * ti ja'i la'o gy. GNU General Public License .gy poi se versiio
 * li su'o 3 gi'e se finti la'o gy. Free Software Foundation .gy
 *
 * .i fysysy se fairgau tezu'e lo nu plixau SECAU LO SI'O SIDJU kuku'i
 * .i .e'u ko catlu gypyly tezu'e lo nu zvafa'i lo tcila
 *
 * .i .a'o do te bevri lo fukpi be gypyly sepa'u fysysy .i va'onai
 * la'edi'u ko catlu zoi .url. https://www.gnu.org/licenses/ .url.
 */

#include <stdio.h>
#include <linux/fb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stropts.h>
#include <unistd.h>

int main() {
    struct fb_fix_screeninfo fbf;
    struct fb_var_screeninfo fbv;

    int filed = open("/dev/fb0", O_RDWR);
    ioctl(filed, FBIOGET_VSCREENINFO, &fbv);
    ioctl(filed, FBIOGET_FSCREENINFO, &fbf);
    close(filed);

    printf("xoff=%u, yoff=%u, bpp=%u, xres=%u, yres=%u, ll=%u\n",
            fbv.xoffset, fbv.yoffset, fbv.bits_per_pixel, fbv.xres, fbv.yres,
            fbf.line_length);

    return 0;
}

