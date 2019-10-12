using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapTool
{
    public partial class LoadMap : Form
    {
        public LoadMap()
        {
            InitializeComponent();
        }
        int tileWidth, tileHeight;
        List<Tile> listTileGet = new List<Tile>();
        Image j;
        private void btnGetTileMap_Click(object sender, EventArgs e)
        {

            DialogResult result = openFileDialog1.ShowDialog();
            if (result == DialogResult.OK)
            {
                j = Image.FromFile(openFileDialog1.FileName);
                picTileList.Width = j.Width;
                picTileList.Height = j.Height;
                picTileList.BackgroundImage = (Bitmap)j;

                tileWidth = int.Parse(txtTileWidth.Text);
                tileHeight = int.Parse(txtTileHeight.Text);
                int Count = picTileList.BackgroundImage.Width / tileWidth;
                for (int k = 0; k < Count; k++)
                {
                    Bitmap bmp = bmCrop(picTileList.BackgroundImage, new Rectangle(k * tileWidth, tileHeight, tileWidth, tileHeight));
                    Tile t = new Tile(bmp);
                    listTileGet.Add(t);
                }
                for (int k = 0; k < listTileGet.Count; k++)
                {
                    DrawImageToImage((Bitmap)picTileList.BackgroundImage, listTileGet[k].Image, new Point(k * tileWidth, 0));
                }
                picTileList.Invalidate();
                btnReadFile.Enabled = true;
            }
            
        }

        private void LoadMap_Load(object sender, EventArgs e)
        {
            btnReadFile.Enabled = false;
        }




        void DrawImageToImage(Bitmap bmDrawTo, Bitmap bmDraw, Point pos)
        {
            Graphics.FromImage(bmDrawTo).DrawImage(bmDraw,
                              new Rectangle(pos.X, pos.Y, bmDrawTo.Width, bmDrawTo.Height),
                              new Rectangle(0, 0, bmDrawTo.Width, bmDrawTo.Height),
                              GraphicsUnit.Pixel);
        }
        void DrawImageToImage(Bitmap bmDrawTo, Bitmap bmDraw, Point pos, Rectangle rectClip)
        {
            Graphics.FromImage(bmDrawTo).DrawImage(bmDraw,
                              new Rectangle(pos.X, pos.Y,
                              rectClip.Width, rectClip.Height),
                              rectClip,
                              GraphicsUnit.Pixel);
        }
        Bitmap bmCrop(Image src, Rectangle rectClip)
        {
            Bitmap b = new Bitmap(rectClip.Width, rectClip.Height);
            DrawImageToImage(b, (Bitmap)src, Point.Empty, rectClip);
            return b;
        }
        int[,] matranRead;
        int TileWidthCountRead, TileHeightCountRead;
        private void btnReadFile_Click(object sender, EventArgs e)
        {
            btnLoadMapFromTile.Enabled = true;
            String s = "";
            DialogResult result = openFileDialog1.ShowDialog();
            openFileDialog1.Filter = "Text Documents|*.txt";
            if (result == DialogResult.OK)
            {

                StreamReader rd = new StreamReader(openFileDialog1.FileName);


                String dong1 = rd.ReadLine();
                String TileCount = rd.ReadLine();
                String dong2 = rd.ReadLine();
                String TileWidth = rd.ReadLine();
                String dong3 = rd.ReadLine();
                String TileHeight = rd.ReadLine();
                String dong4 = rd.ReadLine();
                String TileWidthCount = rd.ReadLine();
                String dong5 = rd.ReadLine();
                String TileHeightCount = rd.ReadLine();
                TileWidthCountRead = int.Parse(TileWidthCount);
                TileHeightCountRead = int.Parse(TileHeightCount);
                matranRead = new int[int.Parse(TileHeightCount), int.Parse(TileWidthCount)];
                for (int k = 0; k < int.Parse(TileHeightCount); k++)
                {
                    s = "";
                    s += rd.ReadLine();
                    String[] p = s.Split(' ');
                    for (int h = 0; h < p.Length - 1; h++)
                    {
                        matranRead[k, h] = int.Parse(p[h]);
                    }
                }



                rd.Close();

                MessageBox.Show("Đã Đọc Xong Ma Trận");

            }
        }

        private void btnLoadMapFromTile_Click(object sender, EventArgs e)
        {
            tileWidth = int.Parse(txtTileWidth.Text);
            tileHeight = int.Parse(txtTileHeight.Text);
            List<Tile> listTileLoadMap = new List<Tile>();
            int Count = picTileList.BackgroundImage.Width / tileWidth;
            for (int k = 0; k < Count; k++)
            {
                Bitmap bmp = bmCrop(picTileList.BackgroundImage, new Rectangle(k * tileWidth, 0, tileWidth, tileHeight));
                Tile t = new Tile(bmp);
                listTileLoadMap.Add(t);
            }
            picMap.Width = TileWidthCountRead * tileWidth;
            picMap.Height = TileHeightCountRead * tileHeight;
            picMap.BackgroundImage = new Bitmap(picMap.Width, picMap.Height);
            for (int r = 0; r < TileHeightCountRead; r++)
                for (int c = 0; c < TileWidthCountRead; c++)
                    DrawImageToImage((Bitmap)picMap.BackgroundImage, listTileLoadMap[matranRead[r, c]].Image, new Point(c * tileWidth, r * tileHeight));
            picMap.Invalidate();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFile = new SaveFileDialog();
            DialogResult result = saveFile.ShowDialog();
            String name = saveFile.FileName;
            if (result == DialogResult.OK)
                saveMap(saveFile.FileName.Remove(saveFile.FileName.LastIndexOf("\\")), name);
        }

        private void saveMap(string forderpath, string name)
        {
            picMap.BackgroundImage.Save(forderpath + "\\" + "Map.png");
            MessageBox.Show("Đã Lưu Map");
        }
    }
}
