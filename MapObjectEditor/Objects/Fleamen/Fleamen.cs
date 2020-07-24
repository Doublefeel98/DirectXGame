using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.Fleamen
{
    public class Fleamen: Obj
    {
        public const int TYPE = 206;
        public const int ANI_SET_ID = 76;
        public Fleamen(PictureBox pic, int posX, int posY,
         int width = 0, int height = 0) :
         base(pic, TYPE, posX, posY, width, height, ANI_SET_ID)
        {
        }

        public Fleamen(PictureBox pic, string[] infos) : base(pic, TYPE, ANI_SET_ID, infos)
        {
        }
    }
}
