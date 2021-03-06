/*
 * This file is part of the Obviously library.
 *
 * Copyright(c) 2010-2012 Georg-Simon-Ohm University, Nuremberg.
 * http://www.ohm-university.eu
 *
 * This file may be licensed under the terms of of the
 * GNU General Public License Version 2 (the ``GPL'').
 *
 * Software distributed under the License is distributed
 * on an ``AS IS'' basis, WITHOUT WARRANTY OF ANY KIND, either
 * express or implied. See the GPL for the specific language
 * governing rights and limitations.
 *
 * You should have received a copy of the GPL along with this
 * program. If not, go to http://www.gnu.org/licenses/gpl.html
 * or write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef OBVIOUS2D_H
#define OBVIOUS2D_H

#include "Obvious.h"

namespace obvious
{

#define TEXTMAX 10
  struct TextStruct
  {
    char text[256];
    unsigned int col;
    unsigned int row;
  };

  /**
   * GLUT-based 2D viewer
   * @author Stefan May
   */
  class Obvious2D
  {
  public:
    /**
     * Standard Constructor
     * @param[in] width Image width, i.e., number of columns
     * @param[in] height Image height, i.e., number of rows
     * @param[in] title Window title
     */
    Obvious2D(unsigned int width, unsigned int height, const char* title);

    /**
     * Destructor
     */
    ~Obvious2D();

    bool isAlive();

    /**
     * Draw image to screen
     * @param[in] image Pointer to image data (size = width*height*channels)
     * @param[in] width Image width
     * @param[in] height Image height
     * @param[in] channels Number of image channels
     */
    void draw(unsigned char* image, unsigned int width, unsigned int height, unsigned int channels);

    /**
     * Register keyboard events
     * @param callback pointer to callback function
     */
    void registerKeyboardCallback(char key, fptrKeyboardCallback callback);

    /**
     * Add a text to be displayed
     * @param[in] text Text buffer
     * @param[in] c Column of display position
     * @param[in] r Row of display position
     */
    void addText(char* text, unsigned int c, unsigned int r);

    /*
     * Clears the texts to be displayed
     */
    void clearText(void);

  private:

    /**
     * GLUT window handle
     */
    int _handle;

    /**
     * Width of GLUT window
     */
    unsigned int _width;

    /**
     * Height of GLUT window
     */
    unsigned int _height;

    /**
     * Text to be displayed
     */
    TextStruct _text[TEXTMAX];
    unsigned int _textCnt;

  };

}

#endif //OBVIOUS2D_H
