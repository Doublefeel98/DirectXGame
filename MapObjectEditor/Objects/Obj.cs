using System.Windows.Forms;

namespace MapEditor.Objects
{
    public class Obj
    {
        public int Type { get; set; }

        public int AniSetId { get; set; }

        public float PosX { get; set; }

        public float PosY { get; set; }

        public int Width { get; set; }

        public int Height { get; set; }

        public PictureBox Pic { get; set; }

        public int ItemType { get; set; }

        public Obj(PictureBox pic, int type, int aniSetId, string[] infos)
        {
            this.Pic = pic;
            this.Type = type;
            this.AniSetId = aniSetId;
            PosX = int.Parse(infos[3]);
            PosY = int.Parse(infos[4]);
            Width = int.Parse(infos[5]);
            Height = int.Parse(infos[6]);
            AniSetId = int.Parse(infos[7]);
            ItemType = int.Parse(infos[8]);
        }

        public Obj(PictureBox pic, int type, int posX, int posY, int width = 0,
            int height = 0, int aniSetId = -1,int itemType = -2)
        {
            this.Pic = pic;
            this.ItemType = itemType;
            this.AniSetId = aniSetId;
            this.Type = type;
            this.PosX = posX;
            this.PosY = posY;
            this.Width = width;
            this.Height = height;


            //if (this.Name == "Simon")
            //{
            //    Id = 1;
            //    AniSetId = 1;
            //}
            ////map object
            //else if (this.Name == "Torch")
            //{
            //    Id = 10;
            //    AniSetId = 30;
            //}
            //else if (this.Name == "Candle")
            //{
            //    Id = 11;
            //    AniSetId = 31;
            //}
            //else if (this.Name == "Gate")
            //{
            //    Id = 12;
            //    AniSetId = 32;
            //}
            //else if (this.Name == "BoundingMap")
            //{
            //    Id = 13;
            //    AniSetId = -1;
            //}
            //else if (this.Name == "Portal")
            //{
            //    Id = 14;
            //    AniSetId = sceneId;
            //}
            //else if (this.Name == "BottomStair")
            //{
            //    Id = 15;
            //    AniSetId = sceneId;
            //}
            //else if (this.Name == "TopStair")
            //{
            //    Id = 16;
            //    AniSetId = sceneId;
            //}
            //else if (this.Name == "Ground")
            //{
            //    Id = 17;
            //    AniSetId = -1;
            //}
            //else if (this.Name == "MovingPlatform")
            //{
            //    Id = 18;
            //    AniSetId = 33;
            //}
            ////item
            //else if (this.Name == "Whip")
            //{
            //    Id = 100;
            //    AniSetId = 40;
            //}
            //else if (this.Name == "SmallHeart")
            //{
            //    Id = 101;
            //    AniSetId = 40;
            //}
            //else if (this.Name == "Heart")
            //{
            //    Id = 102;
            //    AniSetId = 40;
            //}
            //else if (this.Name == "Knife")
            //{
            //    Id = 103;
            //    AniSetId = 40;
            //}
            //else if (this.Name == "Axe")
            //{
            //    Id = 104;
            //    AniSetId = 40;
            //}
            //else if (this.Name == "Boomerang")
            //{
            //    Id = 105;
            //    AniSetId = 40;
            //}
            //else if (this.Name == "Crown")
            //{
            //    Id = 106;
            //    AniSetId = 40;
            //}
            ////Enemy
            //else if (this.Name == "Zombie")
            //{
            //    Id = 200;
            //    AniSetId = 70;
            //}
            //else if (this.Name == "BlackLeopard")
            //{
            //    Id = 201;
            //    AniSetId = 71;
            //}
            //else if (this.Name == "VampireBat")
            //{
            //    Id = 202;
            //    AniSetId = 72;
            //}
            //else if (this.Name == "FishMan")
            //{
            //    Id = 203;
            //    AniSetId = 73;
            //}
            //else if (this.Name == "BlackKnight")
            //{
            //    Id = 204;
            //    AniSetId = 74;
            //}
            //else if (this.Name == "Ghost")
            //{
            //    Id = 205;
            //    AniSetId = 75;
            //}
            //else if (this.Name == "Fleamen")
            //{
            //    Id = 206;
            //    AniSetId = 76;
            //}
            //else if (this.Name == "Skeleton")
            //{
            //    Id = 207;
            //    AniSetId = 77;
            //}
            //else if (this.Name == "Raven")
            //{
            //    Id = 208;
            //    AniSetId = 78;
            //}
            //else if (this.Name == "PhantomBat")
            //{
            //    Id = 300;
            //    AniSetId = 80;
            //}

           
        }

        public virtual string toObjectStr()
        {
            string str = Type + " " + this.GetType().Name + " " + PosX + " " + PosY + " " + Width + " " + Height + " " + AniSetId + " " + ItemType;

            return str;
        }
    }
}
