using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapTool
{
    public class ObjectInFile
    {

        public int index;

        String name;
        Bitmap bmp;
        Rectangle rect;
        int iD;

        public int ID
        {
            get { return iD; }
            set { iD = value; }
        }
        public Bitmap Bmp
        {
            get { return bmp; }
            set { bmp = value; }
        }
       

      
        public ObjectInFile()
        {
            
        }
        public ObjectInFile(String n, Bitmap r)
        {
            name = n;
            bmp = r;
        }
        public ObjectInFile(String n, Rectangle r)
        {
            name = n;
            rect = r;
        }
        public ObjectInFile(String n, Rectangle r,Bitmap bitmap)
        {
            name = n;
            rect = r;
            bmp = bitmap;
        }
        public Rectangle Rect
        {
            get { return rect; }
            set { rect = value; }
        }
        public String Name
        {
            get { return name; }
            set { name = value; }
        }
    }
}
