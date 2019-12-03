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

        public int Index{ get; set; }

        public string Name { get; set; }

        public float PosX { get; set; }

        public float PosY { get; set; }
        
        public int Width { get; set; }
        
        public int Height { get; set; }

        public PictureBox Pic { get; set; }
        
        public Object(PictureBox Pic, int Id, string Name, int index,int PosX, int PosY)
        {
            this.Id = Id;
            this.Index = index;
            this.Name = Name;
            this.PosX = PosX;
            this.PosY = PosY;
            this.Pic = Pic;
            Width = Pic.Width;
            Height = Pic.Height;            
        }

        public Object(PictureBox Pic, int Id, int index, int PosX, int PosY, int Width, int Height)
        {
            this.Pic = Pic;
            this.Id = Id;
            this.Index = index;
            if (this.Id == 1)
            {
                Name = "Apple";
            }
            else if (this.Id == 2)
            {
                Name = "aaa";
            }
            else if (this.Id == 3)
            {
                Name = "GenieFace";
            }
            else if (this.Id == 4)
            {
                Name = "GenieJar";
            }
            else if (this.Id == 5)
            {
                Name = "Bat";
            }
            else if (this.Id == 6)
            {
                Name = "NormalGuard";
            }
            else if (this.Id == 7)
            {
                Name = "ThinGuard";
            }
            else if (this.Id == 8)
            {
                Name = "FatGuard";
            }
            else if (this.Id == 9)
            {
                Name = "BoomSkeleton";
            }
            else if (this.Id == 10)
            {
                Name = "Peddler";
            }
            else if (this.Id == 11)
            {
                Name = "StoneBrick";
            }
            else if (this.Id == 12)
            {
                Name = "SharpTrap";
            }
            else if (this.Id == 13)
            {
                Name = "BallTrap";
            }
            else if (this.Id == 14)
            {
                Name = "Chains";
            }
            else if (this.Id == 15)
            {
                Name = "Fence";
            }
            else if (this.Id == 16)
            {
                Name = "StoneBar";
            }
            else if (this.Id == 17)
            {
                Name = "Wood";
            }
            else if (this.Id == 18)
            {
                Name = "Ground";
            }
            else if (this.Id == 19)
            {
                Name = "Pilar";
            }
            this.PosX = PosX;
            this.PosY = PosY;
            this.Width = Width;
            this.Height = Height;            
        }

        public Object(PictureBox Pic, string Name, int index, int PosX, int PosY, int Width, int Height)
        {
            this.Pic = Pic;
            this.Name = Name;
            this.Index = index;
            if (Name.Equals("Apple"))
            {
                this.Id = 1;
            }
            else if (Name.Equals("Ruby"))
            {
                this.Id = 2;
            }
            else if(Name.Equals("GenieFace"))
            {
                this.Id = 3;
            }
            else if (Name.Equals("GenieJar"))
            {
                this.Id = 4;
            }
            else if (Name.Equals("Bat"))
            {
                this.Id = 5;
            }
            else if (Name.Equals("NormalGuard"))
            {
                this.Id = 6;
            }
            else if (Name.Equals("ThinGuard"))
            {
                this.Id = 7;
            }
            else if (Name.Equals("FatGuard"))
            {
                this.Id = 8;
            }
            else if (Name.Equals("BoomSkeleton"))
            {
                this.Id = 9;
            }
            else if (Name.Equals("Peddler"))
            {
                this.Id = 10;
            }
            else if (Name.Equals("StoneBrick"))
            {
                this.Id = 11;
            }
            else if (Name.Equals("SharpTrap"))
            {
                this.Id = 12;
            }
            else if (Name.Equals("BallTrap"))
            {
                this.Id = 13;
            }
            else if (Name.Equals("Chains"))
            {
                this.Id = 14;
            }
            else if (Name.Equals("Fence"))
            {
                this.Id = 15;
            }
            else if (Name.Equals("StoneBar"))
            {
                this.Id = 16;
            }
            else if (Name.Equals("Wood"))
            {
                this.Id = 17;
            }
            else if (Name.Equals("Ground"))
            {
                this.Id = 18;
            }
            else if (Name.Equals("Pilar"))
            {
                this.Id = 19;
            }
            this.PosX = PosX;
            this.PosY = PosY;
            this.Width = Width;
            this.Height = Height;
        }

        public static int getIdByName(string objectName)
        {
            int objectId = 0;

            if (objectName.Equals("Apple"))
            {
                objectId = 1;
            }
            else if (objectName.Equals("Ruby"))
            {
                objectId = 2;
            }
            else if (objectName.Equals("GenieFace"))
            {
                objectId = 3;
            }
            else if (objectName.Equals("GenieJar"))
            {
                objectId = 4;
            }
            else if (objectName.Equals("Bat"))
            {
                objectId = 5;
            }
            else if (objectName.Equals("NormalGuard"))
            {
                objectId = 6;
            }
            else if (objectName.Equals("ThinGuard"))
            {
                objectId = 7;
            }
            else if (objectName.Equals("FatGuard"))
            {
                objectId = 8;
            }
            else if (objectName.Equals("BoomSkeleton"))
            {
                objectId = 9;
            }
            else if (objectName.Equals("Peddler"))
            {
                objectId = 10;
            }
            else if (objectName.Equals("StoneBrick"))
            {
                objectId = 11;
            }
            else if (objectName.Equals("SharpTrap"))
            {
                objectId = 12;
            }
            else if (objectName.Equals("BallTrap"))
            {
                objectId = 13;
            }
            else if (objectName.Equals("Chains"))
            {
                objectId = 14;
            }
            else if (objectName.Equals("Fence"))
            {
                objectId = 15;
            }
            else if (objectName.Equals("StoneBar"))
            {
                objectId = 16;
            }
            else if (objectName.Equals("Wood"))
            {
                objectId = 17;
            }
            else if (objectName.Equals("Ground"))
            {
                objectId = 18;
            }
            else if (objectName.Equals("Pilar"))
            {
                objectId = 19;
            }
            return objectId;
        }
    }
}
