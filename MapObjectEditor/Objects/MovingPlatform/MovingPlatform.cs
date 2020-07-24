using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.MovingPlatform
{
    public class MovingPlatform: Obj
    {
        public const int TYPE = 18;
        public const int ANI_SET_ID = 33;
        public MovingPlatform(PictureBox pic, int posX, int posY,
        int width = 0, int height = 0) :
        base(pic, TYPE, posX, posY, width, height, ANI_SET_ID)
        {
        }

        public MovingPlatform(PictureBox pic, string[] infos) : base(pic, TYPE, ANI_SET_ID, infos)
        {
            this.Type = TYPE;
            this.AniSetId = ANI_SET_ID;
        }
    }
}
