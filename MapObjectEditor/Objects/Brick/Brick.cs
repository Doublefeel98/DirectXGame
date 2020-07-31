using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.Brick
{
    public class Brick : Obj
    {
        public const int TYPE = 19;
        public const int ANI_SET_ID = 34;

        public Brick(PictureBox pic, int posX, int posY,
            int width = 0, int height = 0) :
            base(pic, TYPE, posX, posY, width, height, ANI_SET_ID)
        {
        }

        public Brick(PictureBox pic, string[] infos) : base(pic, TYPE, ANI_SET_ID, infos)
        {
        }
    }
}
