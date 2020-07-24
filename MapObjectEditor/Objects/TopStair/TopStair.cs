using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.TopStair
{
    public class TopStair: Obj
    {
        public const int TYPE = 16;
        public const int ANI_SET_ID = -1;
        public int Direction { get; set; }
        public TopStair(PictureBox pic, int posX, int posY,
    int width = 0, int height = 0) :
    base(pic, TYPE, posX, posY, width, height, ANI_SET_ID)
        {
        }

        public TopStair(PictureBox pic, string[] infos) : base(pic, TYPE, ANI_SET_ID, infos)
        {
            if (infos.Length > 9)
            {
                Direction = Int32.Parse(infos[9]);
            }
        }

        public override string toObjectStr()
        {
            string str = base.toObjectStr() + " " + Direction;
            return str;
        }
    }
}
