using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapTool
{
    public class ObjectDraw
    {
        Point point;
        Bitmap bm;

        public ObjectDraw(Bitmap bmp, Point p)
        {
            bm = bmp;
            point = p;
        }
        public Bitmap Bm
        {
            get { return bm; }
            set { bm = value; }
        }
        public Point Point
        {
            get { return point; }
            set { point = value; }
        }
    }
}
