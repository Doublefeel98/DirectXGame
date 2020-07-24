using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.Torch
{
    public class Torch : Obj
    {
        public const int TYPE = 10;
        public const int ANI_SET_ID = 30;
        public Torch(PictureBox pic, int posX, int posY,
    int width = 0, int height = 0) :
    base(pic, TYPE, posX, posY, width, height, ANI_SET_ID)
        {
        }

        public Torch(PictureBox pic, string[] infos) : base(pic, TYPE, ANI_SET_ID, infos)
        {
        }
    }
}
