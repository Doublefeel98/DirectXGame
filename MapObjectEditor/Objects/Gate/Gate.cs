using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.Gate
{
    public class Gate: Obj
    {
        public const int TYPE = 12;
        public const int ANI_SET_ID = 32;
        public Gate(PictureBox pic, int posX, int posY,
        int width = 0, int height = 0) :
        base(pic, TYPE, posX, posY, width, height, ANI_SET_ID)
        {
        }

        public Gate(PictureBox pic, string[] infos) : base(pic, TYPE, ANI_SET_ID, infos)
        {
            this.Type = TYPE;
            this.AniSetId = ANI_SET_ID;
        }
    }
}
