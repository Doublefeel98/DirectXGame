using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.Ground
{
    public class Ground : Obj
    {
        public const int TYPE = 17;
        public const int ANI_SET_ID = -1;
        public Ground(PictureBox pic, int posX, int posY,
       int width = 0, int height = 0) :
       base(pic, TYPE, posX, posY, width, height, ANI_SET_ID)
        {
        }

        public Ground(PictureBox pic, string[] infos) : base(pic, TYPE, ANI_SET_ID, infos)
        {
            this.Type = TYPE;
            this.AniSetId = ANI_SET_ID;
        }
    }
}
