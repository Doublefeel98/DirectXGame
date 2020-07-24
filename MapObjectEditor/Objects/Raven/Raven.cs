using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.Raven
{
    public class Raven : Obj
    {
        public const int TYPE = 208;
        public const int ANI_SET_ID = 78;
        public Raven(PictureBox pic, int posX, int posY,
     int width = 0, int height = 0) :
     base(pic, TYPE, posX, posY, width, height, ANI_SET_ID)
        {
        }

        public Raven(PictureBox pic, string[] infos) : base(pic, TYPE, ANI_SET_ID, infos)
        {
        }
    }
}
