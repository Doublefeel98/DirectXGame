using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor
{
    class Object
    {

        public int Id { get; set; }

        public int Index { get; set; }

        public string Name { get; set; }

        public float PosX { get; set; }

        public float PosY { get; set; }

        public int Width { get; set; }

        public int Height { get; set; }

        public PictureBox Pic { get; set; }

        public int delay { get; set; }

        public Object(PictureBox Pic, int Id, string Name, int index, int PosX, int PosY, int delay = 0)
        {
            this.Id = Id;
            this.Index = index;
            this.Name = Name;
            this.PosX = PosX;
            this.PosY = PosY;
            this.Pic = Pic;
            Width = Pic.Width;
            Height = Pic.Height;
            this.delay = delay;
        }

        public Object(PictureBox Pic, int Id, int index, int PosX, int PosY, int Width, int Height, int delay = 0)
        {
            this.Pic = Pic;
            this.Id = Id;
            this.Index = index;
            this.delay = delay;
            if (this.Id == 1)
            {
                Name = "BrickOutCastle";
            }
            else if (this.Id == 2)
            {
                Name = "Torch";
            }
            else if (this.Id == 3)
            {
                Name = "BrickSceneOne";
            }
            else if (this.Id == 4)
            {
                Name = "Candle";
            }
            this.PosX = PosX;
            this.PosY = PosY;
            this.Width = Width;
            this.Height = Height;
        }

        public Object(PictureBox Pic, string Name, int index, int PosX, int PosY, int Width, int Height, int delay = 0)
        {
            this.Pic = Pic;
            this.Name = Name;
            this.Index = index;
            this.delay = delay;
            if (Name.Equals("BrickOutCastle"))
            {
                this.Id = 1;
            }
            else if (Name.Equals("Torch"))
            {
                this.Id = 2;
            }
            else if (Name.Equals("BrickSceneOne"))
            {
                this.Id = 3;
            }
            else if (Name.Equals("Candle"))
            {
                this.Id = 4;
            }
            this.PosX = PosX;
            this.PosY = PosY;
            this.Width = Width;
            this.Height = Height;
        }

        public static int getIdByName(string objectName)
        {
            int objectId = 0;

            if (objectName.Equals("BrickOutCastle"))
            {
                objectId = 1;
            }
            else if (objectName.Equals("Torch"))
            {
                objectId = 2;
            }
            else if (objectName.Equals("BrickSceneOne"))
            {
                objectId = 3;
            }
            else if (objectName.Equals("Candle"))
            {
                objectId = 4;
            }
            return objectId;
        }
    }
}
