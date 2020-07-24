using System;
using System.Windows.Forms;

namespace MapEditor.Objects.Portal
{
    public class Portal : Obj
    {
        public const int TYPE = 14;
        public const int ANI_SET_ID = -1;
        public const int POSITION = 1;
        public const int SCENE_ID = 1;
        public int Position { get; set; }
        public int SceneId { get; set; }
        public Portal(PictureBox pic, int posX, int posY,
    int width = 0, int height = 0) :
            base(pic, TYPE, posX, posY, width, height, ANI_SET_ID, -2)
        {
            this.Position = POSITION;
            this.SceneId = SCENE_ID;
        }

        public Portal(PictureBox pic, string[] infos) : base(pic, TYPE, ANI_SET_ID, infos)
        {
            if (infos.Length > 9)
            {
                SceneId = Int32.Parse(infos[9]);
            }
            if (infos.Length > 10)
            {
                Position = Int32.Parse(infos[10]);
            }
        }

        public override string toObjectStr()
        {
            string str = base.toObjectStr() + " " + SceneId + " " + Position;
            return str;
        }
    }
}
