' Copyright (c) 2009-2013 Bruce A Henderson
' 
' Permission is hereby granted, free of charge, to any person obtaining a copy
' of this software and associated documentation files (the "Software"), to deal
' in the Software without restriction, including without limitation the rights
' to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
' copies of the Software, and to permit persons to whom the Software is
' furnished to do so, subject to the following conditions:
' 
' The above copyright notice and this permission notice shall be included in
' all copies or substantial portions of the Software.
' 
' THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
' IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
' FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
' AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
' LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
' OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
' THE SOFTWARE.
' 
SuperStrict

Import "common.bmx"

Rem
bbdoc: Defines a rectangle in the plane using integer precision.
about: A rectangle is normally expressed as an upper-left corner and a size. The size (width and height) of a QRect
is always equivalent to the mathematical rectangle that forms the basis for its rendering.
<p>A QRect can be constructed with a set of left, top, width and height integers.</p>
<p>The QRect class provides a collection of methods that return the various rectangle coordinates, and enable manipulation of these. QRect also
provide methods to move the rectangle relative to the various coordinates. In addition there is a #moveTo() method
that moves the rectangle, leaving its top left corner at the given coordinates. Alternatively, the #translate() method
moves the rectangle the given offset relative to the current position, and the #translated() method returns a
translated copy of this rectangle.</p>
<p>The #size() method returns the rectange's dimensions. The dimensions can also be retrieved separately using the
#width() and #height() methods. To manipulate the dimensions use the #setSize(), #setWidth() or #setHeight() methods.
Alternatively, the size can be changed by applying either of the methods setting the rectangle coordinates, for example,
#setBottom() or #setRight().</p>
<p>The #contains() method tells whether a given point is inside the rectangle or not, and the #intersects() method returns
true if this rectangle intersects with a given rectangle. The QRect class also provides the #intersected() method
which returns the intersection rectangle, and the #united() method which returns the rectangle that encloses the
given rectangle and this:</p>
<p><table align="center">
<tr valign="top"><td><img src="images/qrect-intersect.png" /></td><td><img src="images/qrect-unite.png" /></td></tr>
<tr valign="top"><td>#intersected()</td><td>#united()</td></tr>
</table></p>
<p>The #isEmpty() method returns true if #left() &gt; #right() or #top() &gt; #bottom(). Note that an
empty rectangle is not valid: The #isValid() method returns true if #left() &lt;= #right() <i>and</i> #top() &lt;= #bottom().
A null rectangle (#isNull() == true) on the other hand, has both width and height set to 0.</p>
<p>Note that due to the way QRect and <a href="qrectf.html">QRectF</a> are defined, an empty QRect is defined in essentially the
same way as <a href="qrectf.html">QRectF</a>.</p>
<h3>Rendering</h3>
<p>When using an <a href="qpainter.html#RenderHint-enum">anti-aliased</a> painter, the boundary line of a QRect will be rendered
symmetrically on both sides of the mathematical rectangle's boundary line. But when using an aliased painter (the default) other
rules apply.</p>
<p>Then, when rendering with a one pixel wide pen the QRect's boundary line will be rendered to the right and below the mathematical
rectangle's boundary line.</p>
<p>When rendering with a two pixels wide pen the boundary line will be split in the middle by the mathematical rectangle. This will
be the case whenever the pen is set to an even number of pixels, while rendering with a pen with an odd number of pixels, the spare
pixel will be rendered to the right and below the mathematical rectangle as in the one pixel case.</p>
<p><table align="center">
<tr valign="top"><td><img src="images/qrect-diagram-zero.png" /></td><td><img src="images/qrect-diagram-one.png" /></td></tr>
<tr valign="top"><td>Logical representation</td><td>One pixel wide pen</td></tr>
<tr valign="top"><td><img src="images/qrect-diagram-two.png" /></td><td><img src="images/qrect-diagram-three.png" /></td></tr>
<tr valign="top"><td>Two pixel wide pen</td><td>Three pixel wide pen</td></tr>
</table></p>
<h3>Coordinates</h3>
<p>The QRect class provides a collection of methods that return the various rectangle coordinates, and enable manipulation of these.
QRect also provide methods to move the rectangle relative to the various coordinates.</p>
<p>For example the #left(), #setLeft() and #moveLeft() methods as an example: #left() returns the x-coordinate
of the rectangle's left edge, #setLeft() sets the left edge of the rectangle to the given x coordinate (it may
change the width, but will never change the rectangle's right edge) and #moveLeft() moves the entire rectangle
horizontally, leaving the rectangle's left edge at the given x coordinate and its size unchanged.</p>
<p align="center"><img src="images/qrect-coordinates.png" /></p><p>Note that for historical reasons the values returned by the
#bottom() and #right() methods deviate from the true bottom-right corner of the rectangle:
The #right() method returns <i> #left() + #width() - 1</i> and the #bottom() method returns <i>#top() + #height() - 1</i>. The same is the
case for the point returned by the #bottomRight() convenience method. In addition, the x and y coordinate of
the #topRight() and #bottomLeft() methods, respectively, contain the same deviation from the true right and bottom edges.</p>
<p>We recommend that you use #x() + #width() and #y() + #height() to find the true bottom-right corner,
and avoid #right() and #bottom(). Another solution is to use <a href="qrectf.html">QRectF</a>: The <a href="qrectf.html">QRectF</a>
class defines a rectangle in the plane using floating point accuracy for coordinates, and the
<a href="qrectf.html#right">QRectF::right</a>() and <a href="qrectf.html#bottom">QRectF::bottom</a>()
methods <i>do</i> return the right and bottom coordinates.</p>
<p>It is also possible to add offsets to this rectangle's coordinates using the #adjust() method, as well as retrieve
a new rectangle based on adjustments of the original one using the #adjusted() method. If either of the width and
height is negative, use the #normalized() method to retrieve a rectangle where the corners are swapped.</p>
<p>In addition, QRect provides the #getCoords() method which extracts the position of the rectangle's top-left and
bottom-right corner, and the #getRect() method which extracts the rectangle's top-left corner, width and height. Use
the #setCoords() and #setRect() method to manipulate the rectangle's coordinates and
dimensions in one go.</p>
End Rem
Type QRect

	Field qObjectPtr:Byte Ptr
	
	Function _Create:QRect(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QRect = New QRect
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function

	Function CreateRect:QRect(x:Int, y:Int, w:Int, h:Int)
		Return New QRect.Create(x, y, w, h)
	End Function
	
	Method Create:QRect(x:Int, y:Int, w:Int, h:Int)
		qObjectPtr = bmx_qt_qrect_create(x, y, w, h)
		Return Self
	End Method

	Method adjust(dx1:Int, dy1:Int, dx2:Int, dy2:Int)
		bmx_qt_qrect_adjust(qObjectPtr, dx1, dy1, dx2, dy2)
	End Method
	
	Method adjusted:QRect(dx1:Int, dy1:Int, dx2:Int, dy2:Int)
		Return QRect._create(bmx_qt_qrect_adjusted(qObjectPtr, dx1, dy1, dx2, dy2))
	End Method
	
	Method bottom:Int()
		Return bmx_qt_qrect_bottom(qObjectPtr)
	End Method
	
	Method bottomLeft(x:Int Var, y:Int Var)
		bmx_qt_qrect_bottomleft(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method bottomRight(x:Int Var, y:Int Var)
		bmx_qt_qrect_bottomright(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method center(x:Int Var, y:Int Var)
		bmx_qt_qrect_center(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method contains:Int(x:Int, y:Int, proper:Int = False)
		Return bmx_qt_qrect_contains(qObjectPtr, x, y, proper)
	End Method
	
	Method containsRect:Int(rectangle:QRect, proper:Int = False)
		Return bmx_qt_qrect_containsrect(qObjectPtr, rectangle.qObjectPtr, proper)
	End Method
	
	Method getCoords(x1:Int Var, y1:Int Var, x2:Int Var, y2:Int Var)
		bmx_qt_qrect_getcoords(qObjectPtr, Varptr x1, Varptr y1, Varptr x2, Varptr y2)
	End Method
	
	Method getRect(x:Int Var, y:Int Var, width:Int Var, height:Int Var)
		bmx_qt_qrect_getrect(qObjectPtr, Varptr x, Varptr y, Varptr width, Varptr height)
	End Method
	
	Method height:Int()
		Return bmx_qt_qrect_height(qObjectPtr)
	End Method
	
	Method intersected:QRect(rectangle:QRect)
		Return QRect._create(bmx_qt_qrect_intersected(qObjectPtr, rectangle.qObjectPtr))
	End Method
	
	Method intersects:Int(rectangle:QRect)
		Return bmx_qt_qrect_intersects(qObjectPtr, rectangle.qObjectPtr)
	End Method
	
	Method isEmpty:Int()
		Return bmx_qt_qrect_isempty(qObjectPtr)
	End Method
	
	Method isNull:Int()
		Return bmx_qt_qrect_isnull(qObjectPtr)
	End Method
	
	Method isValid:Int()
		Return bmx_qt_qrect_isvalid(qObjectPtr)
	End Method
	
	Method Left:Int()
		Return bmx_qt_qrect_left(qObjectPtr)
	End Method
	
	Method moveBottom(y:Int)
		bmx_qt_qrect_movebottom(qObjectPtr, y)
	End Method
	
	Method moveBottomLeft(x:Int, y:Int)
		bmx_qt_qrect_movebottomleft(qObjectPtr, x, y)
	End Method
	
	Method moveBottomRight(x:Int, y:Int)
		bmx_qt_qrect_movebottomright(qObjectPtr, x, y)
	End Method
	
	Method moveCenter(x:Int, y:Int)
		bmx_qt_qrect_movecenter(qObjectPtr, x, y)
	End Method
	
	Method moveLeft(x:Int)
		bmx_qt_qrect_moveleft(qObjectPtr, x)
	End Method
	
	Method moveRight(x:Int)
		bmx_qt_qrect_moveright(qObjectPtr, x)
	End Method
	
	Method moveTo(x:Int, y:Int)
		bmx_qt_qrect_moveto(qObjectPtr, x, y)
	End Method
	
	Method moveTop(y:Int)
		bmx_qt_qrect_movetop(qObjectPtr, y)
	End Method
	
	Method moveTopLeft(x:Int, y:Int)
		bmx_qt_qrect_movetopleft(qObjectPtr, x, y)
	End Method
	
	Method moveTopRight(x:Int, y:Int)
		bmx_qt_qrect_movetopright(qObjectPtr, x, y)
	End Method
	
	Method normalized:QRect()
		Return QRect._create(bmx_qt_qrect_normalized(qObjectPtr))
	End Method
	
	Method Right:Int()
		Return bmx_qt_qrect_right(qObjectPtr)
	End Method
	
	Method setBottom(y:Int)
		bmx_qt_qrect_setbottom(qObjectPtr, y)
	End Method
	
	Method setBottomLeft(x:Int, y:Int)
		bmx_qt_qrect_setbottomleft(qObjectPtr, x, y)
	End Method
	
	Method setBottomRight(x:Int, y:Int)
		bmx_qt_qrect_setbottomright(qObjectPtr, x, y)
	End Method
	
	Method setCoords(x1:Int, y1:Int, x2:Int, y2:Int)
		bmx_qt_qrect_setcoords(qObjectPtr, x1, y1, x2, y2)
	End Method
	
	Method setHeight(height:Int)
		bmx_qt_qrect_setheight(qObjectPtr, height)
	End Method
	
	Method setLeft(x:Int)
		bmx_qt_qrect_setleft(qObjectPtr, x)
	End Method
	
	Method setRect(x:Int, y:Int, width:Int, height:Int)
		bmx_qt_qrect_setrect(qObjectPtr, x, y, width, height)
	End Method
	
	Method setRight(x:Int)
		bmx_qt_qrect_setright(qObjectPtr, x)
	End Method
	
	Method setSize(w:Int, h:Int)
		bmx_qt_qrect_setsize(qObjectPtr, w, h)
	End Method
	
	Method setTop(y:Int)
		bmx_qt_qrect_settop(qObjectPtr, y)
	End Method
	
	Method setTopLeft(x:Int, y:Int)
		bmx_qt_qrect_settopleft(qObjectPtr, x, y)
	End Method
	
	Method setTopRight(x:Int, y:Int)
		bmx_qt_qrect_settopright(qObjectPtr, x, y)
	End Method
	
	Method setWidth(width:Int)
		bmx_qt_qrect_setwidth(qObjectPtr, width)
	End Method
	
	Method setX(x:Int)
		bmx_qt_qrect_setx(qObjectPtr, x)
	End Method
	
	Method setY(y:Int)
		bmx_qt_qrect_sety(qObjectPtr, y)
	End Method
	
	Method size(w:Int Var, h:Int Var)
		bmx_qt_qrect_size(qObjectPtr, Varptr w, Varptr h)
	End Method
	
	Method top:Int()
		Return bmx_qt_qrect_top(qObjectPtr)
	End Method
	
	Method topLeft(x:Int Var, y:Int Var)
		bmx_qt_qrect_topleft(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method topRight(x:Int Var, y:Int Var)
		bmx_qt_qrect_topright(qObjectPtr, Varptr x, Varptr y)
	End Method
	
	Method translate(dx:Int, dy:Int)
		bmx_qt_qrect_translate(qObjectPtr, dx, dy)
	End Method
	
	Method translated:QRect(dx:Int, dy:Int)
		Return QRect._create(bmx_qt_qrect_translated(qObjectPtr, dx, dy))
	End Method
	
	Method united:QRect(rectangle:QRect)
		Return QRect._create(bmx_qt_qrect_united(qObjectPtr, rectangle.qObjectPtr))
	End Method
	
	Method width:Int()
		Return bmx_qt_qrect_width(qObjectPtr)
	End Method
	
	Method x:Int()
		Return bmx_qt_qrect_x(qObjectPtr)
	End Method
	
	Method y:Int()
		Return bmx_qt_qrect_y(qObjectPtr)
	End Method

	Method Free()
		If qObjectPtr Then
			bmx_qt_qrect_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method
	
End Type

