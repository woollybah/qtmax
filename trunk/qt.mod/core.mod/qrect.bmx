SuperStrict

Import "common.bmx"

Rem
bbdoc: Defines a rectangle in the plane using integer precision.
about: A rectangle is normally expressed as an upper-left corner and a size. The size (width and height) of a
QRect is always equivalent to the mathematical rectangle that forms the basis for its rendering.
<p>
A QRect can be constructed with a set of left, top, width and height integers. The following code demonstrates the creation of a QRect.
<pre>
 Local r1:QRect = New QRect.Create(100, 200, 11, 16)
</pre>
</p>
<p>
The QRect class provides a collection of methods that return the various rectangle coordinates, and enable manipulation of
these. QRect also provide methods to move the rectangle relative to the various coordinates. In addition there is a
moveTo() method that moves the rectangle, leaving its top left corner at the given coordinates. Alternatively, the
translate() method moves the rectangle the given offset relative to the current position, and the translated() method 
returns a translated copy of this rectangle.
</p>
<p>
The size() method returns the rectange's dimensions as a QSize. The dimensions can also be retrieved separately using the
width() and height() methods. To manipulate the dimensions use the setSize(), setWidth() or setHeight() methods.
Alternatively, the size can be changed by applying either of the methods setting the rectangle coordinates, for example,
setBottom() or setRight().
</p>
<p>
The contains() method tells whether a given point is inside the rectangle or not, and the intersects() method returns true
if this rectangle intersects with a given rectangle. The QRect class also provides the intersected() function which returns
the intersection rectangle, and the united() function which returns the rectangle that encloses the given rectangle and this:
</p>
<p><table align="center" cellpadding="2" cellspacing="1" border="0">
<tr valign="top"><td><img src="images/qrect-intersect.png" /></td><td><img src="images/qrect-unite.png" /></td></tr>
<tr valign="top"><td><a href="commands.html#intersected">intersected</a>()</td><td><a href="commands.html#united">united</a>()</td></tr>
</table></p>

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
	' TODO
	End Method
	
	Method adjusted:QRect(dx1:Int, dy1:Int, dx2:Int, dy2:Int)
	' TODO
	End Method
	
	Method bottom:Int()
	' TODO
	End Method
	
	Method bottomLeft(x:Int Var, y:Int Var)
	' TODO
	End Method
	
	Method bottomRight(x:Int Var, y:Int Var)
	' TODO
	End Method
	
	Method center(x:Int Var, y:Int Var)
	' TODO
	End Method
	
	Method contains:Int(x:Int, y:Int, proper:Int = False)
	' TODO
	End Method
	
	Method containsRect:Int(rectangle:QRect, proper:Int = False)
	' TODO
	End Method
	
	Method getCoords(x1:Int Var, y1:Int Var, x2:Int Var, y2:Int Var)
	' TODO
	End Method
	
	Method getRect(x:Int Var, y:Int Var, width:Int Var, height:Int Var)
	' TODO
	End Method
	
	Method height:Int()
	' TODO
	End Method
	
	Method intersected:QRect(rectangle:QRect)
	' TODO
	End Method
	
	Method intersects:Int(rectangle:QRect)
	' TODO
	End Method
	
	Method isEmpty:Int()
	' TODO
	End Method
	
	Method isNull:Int()
	' TODO
	End Method
	
	Method isValid:Int()
	' TODO
	End Method
	
	Method Left:Int()
	' TODO
	End Method
	
	Method moveBottom(y:Int)
	' TODO
	End Method
	
	Method moveBottomLeft(x:Int, y:Int)
	' TODO
	End Method
	
	Method moveBottomRight(x:Int, y:Int)
	' TODO
	End Method
	
	Method moveCenter(x:Int, y:Int)
	' TODO
	End Method
	
	Method moveLeft(x:Int)
	' TODO
	End Method
	
	Method moveRight(x:Int)
	' TODO
	End Method
	
	Method moveTo(x:Int, y:Int)
	' TODO
	End Method
	
	Method moveTop(y:Int)
	' TODO
	End Method
	
	Method moveTopLeft(x:Int, y:Int)
	' TODO
	End Method
	
	Method moveTopRight(x:Int, y:Int)
	' TODO
	End Method
	
	Method normalized:QRect()
	' TODO
	End Method
	
	Method Right:Int()
	' TODO
	End Method
	
	Method setBottom(y:Int)
	' TODO
	End Method
	
	Method setBottomLeft(x:Int, y:Int)
	' TODO
	End Method
	
	Method setBottomRight(x:Int, y:Int)
	' TODO
	End Method
	
	Method setCoords(x1:Int, y1:Int, x2:Int, y2:Int)
	' TODO
	End Method
	
	Method setHeight(height:Int)
	' TODO
	End Method
	
	Method setLeft(x:Int)
	' TODO
	End Method
	
	Method setRect(x:Int, y:Int, width:Int, height:Int)
	' TODO
	End Method
	
	Method setRight(x:Int)
	' TODO
	End Method
	
	Method setSize(w:Int, h:Int)
	' TODO
	End Method
	
	Method setTop(y:Int)
	' TODO
	End Method
	
	Method setTopLeft(x:Int, y:Int)
	' TODO
	End Method
	
	Method setTopRight(x:Int, y:Int)
	' TODO
	End Method
	
	Method setWidth(width:Int)
	' TODO
	End Method
	
	Method setX(x:Int)
	' TODO
	End Method
	
	Method setY(y:Int)
	' TODO
	End Method
	
	Method size(w:Int Var, h:Int Var)
	' TODO
	End Method
	
	Method top:Int()
	' TODO
	End Method
	
	Method topLeft(x:Int Var, y:Int Var)
	' TODO
	End Method
	
	Method topRight(x:Int Var, y:Int Var)
	' TODO
	End Method
	
	Method translate(dx:Int, dy:Int)
	' TODO
	End Method
	
	Method translated:QRect(dx:Int, dy:Int)
	' TODO
	End Method
	
	Method united:QRect(rectangle:QRect)
	' TODO
	End Method
	
	Method width:Int()
	' TODO
	End Method
	
	Method x:Int()
	' TODO
	End Method
	
	Method y:Int()
	' TODO
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

