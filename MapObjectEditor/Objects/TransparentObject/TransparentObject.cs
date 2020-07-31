using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.TransparentObject
{
    public class TransparentObject : Obj
    {
        public const int TYPE = 20;
        public const int ANI_SET_ID = -1;

        public int ItemX { get; set; }
        public int ItemY { get; set; }
        public int IsItemGrowUp { get; set; }

        public TransparentObject(PictureBox pic, int posX, int posY,
    int width = 0, int height = 0) :
    base(pic, TYPE, posX, posY, width, height, ANI_SET_ID)
        {
            ItemX = 0;
            ItemY = 0;
            IsItemGrowUp = 0;
        }

        public TransparentObject(PictureBox pic, string[] infos) : base(pic, TYPE, ANI_SET_ID, infos)
        {
            if (infos.Length > 10)
            {
                ItemX = Int32.Parse(infos[9]);
                ItemY = Int32.Parse(infos[10]);
                IsItemGrowUp = Int32.Parse(infos[11]);
            }
        }

        public override string toObjectStr()
        {
            string str = base.toObjectStr() + " " + ItemX + " " + ItemY + " " + IsItemGrowUp;
            return str;
        }
    }
}
