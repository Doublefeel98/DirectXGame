using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.BlackKnight
{
    public class BlackKnight: Obj
    {
        public const int TYPE = 204;
        public const int ANI_SET_ID = 74;
        public BlackKnight(PictureBox pic, int posX, int posY,
            int width = 0, int height = 0) :
            base(pic, TYPE, posX, posY, width, height, ANI_SET_ID)
        {
        }

        public BlackKnight(PictureBox pic, string[] infos) : base(pic, TYPE, ANI_SET_ID, infos)
        {
        }
    }
}
