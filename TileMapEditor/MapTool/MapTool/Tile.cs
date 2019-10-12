using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapTool
{
    public class Tile
    {
        int id;
        Bitmap image;
        public Tile(Bitmap image = null, int id = 0)
        {
            Image = image;
            Id = id;
        }
        public Bitmap Image
        {
            get { return image; }
            set { image = value; }
        }
        public int Id
        {
            get { return id; }
            set { id = value; }
        }
        
    }
}
