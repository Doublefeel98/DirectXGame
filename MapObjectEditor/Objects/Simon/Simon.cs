using System;
using System.Windows.Forms;

namespace MapEditor.Objects.Simon
{
    public class Simon : Obj
    {
        public const int TYPE = 1;
        public const int ANI_SET_ID = 1;
        public const int DIRECTION = -1;
        public const int STATE = 0;
        public int Direction { get; set; }
        public int State { get; set; }

        public Simon(PictureBox pic, int posX, int posY,
            int width = 0, int height = 0) :
            base(pic, TYPE, posX, posY, width, height, ANI_SET_ID)
        {
            this.Direction = DIRECTION;
            this.State = STATE;
        }

        public Simon(PictureBox pic, string[] infos) : base(pic, TYPE, ANI_SET_ID, infos)
        {
            if (infos.Length > 9)
            {
                Direction = Int32.Parse(infos[9]);
            }
            if (infos.Length > 10)
            {
                State = Int32.Parse(infos[10]);
            }
        }

        public override string toObjectStr()
        {
            string str = base.toObjectStr() + " " + Direction + " " + State;
            return str;
        }
    }
}
