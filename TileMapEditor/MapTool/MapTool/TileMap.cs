using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapTool
{
    public partial class TileMap : Form
    {
        public TileMap()
        {
            InitializeComponent();
        }
        List<Tile> listTile = new List<Tile>();//list tile map
        int tileWidth,tileHeight;
        Bitmap b1;
        Image i;
        int[,] matrix;
        int indexHeightOfMap;
        int tileCountPerWidth, tileCountPerHeight;

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            DialogResult result = openFileDialog1.ShowDialog();
            if (result == DialogResult.OK)
            {
                listTile.Clear();

                i = Image.FromFile(openFileDialog1.FileName);


                b1 = new Bitmap(i.Width, i.Width);
                Graphics.FromImage(b1).Clear(Color.Black);
                DrawImageToImage(b1, (Bitmap)i, new Point(0, i.Width - i.Height), new Rectangle(0, 0, i.Width, i.Height));
                picMap.Width = i.Width;
                picMap.Height = i.Width;
                picMap.BackgroundImage = b1;
                picMap.Image = new Bitmap(i.Width, i.Width);
                tileWidth = int.Parse(txtTileWidth.Text);
                tileHeight = int.Parse(txtTileHeight.Text);
                tileCountPerWidth = picMap.Width / tileWidth;
                tileCountPerHeight = picMap.Height / tileHeight;
                indexHeightOfMap = (i.Width - i.Height) / tileWidth;
                DrawGrid();

                InitTileImage();

                ShowTileMapResult();

            }
        }

        private void ShowTileMapResult()
        {
            picTileMapResult.Width = listTile.Count * tileWidth;
            picTileMapResult.BackgroundImage = new Bitmap(picTileMapResult.Width, picTileMapResult.Height);
            int listTileCount = listTile.Count;
            for (int i = 0; i < listTileCount; i++)
            {
                DrawImageToImage((Bitmap)picTileMapResult.BackgroundImage, listTile[i].Image, new Point(i * tileWidth, 0));
            }
            picTileMapResult.Invalidate();
        }

        private void InitTileImage()
        {
            matrix = new int[tileCountPerHeight, tileCountPerWidth];

            for (int i = indexHeightOfMap; i < tileCountPerHeight; i++)
            {
                for (int j = 0; j < tileCountPerWidth; j++)
                {
                    Bitmap bmp = bmCrop(picMap.BackgroundImage, new Rectangle(j * tileWidth, i * tileWidth, tileWidth, tileHeight));
                    Tile t = new Tile(bmp);
                    bool notexists = true;
                    for (int b = 0; b < listTile.Count; b++)
                    {
                        if (CompareBitmap(t.Image, listTile[b].Image))
                        {
                            notexists = false;

                            matrix[i, j] = listTile[b].Id;
                            break;
                        }
                    }
                    if (notexists)
                    {
                        listTile.Add(t);
                        t.Id = listTile.Count - 1;
                        matrix[i, j] = t.Id;
                    }

                }
            }
        }
        bool CompareBitmap(Bitmap bmp1, Bitmap bmp2)
        {
            if (bmp1 == null || bmp2 == null)
                return false;
            if (object.Equals(bmp1, bmp2))
                return true;
            if (!bmp1.Size.Equals(bmp2.Size) || !bmp1.PixelFormat.Equals(bmp2.PixelFormat))
                return false;

            int bytes = bmp1.Width * bmp1.Height * (Image.GetPixelFormatSize(bmp1.PixelFormat) / 8);

            bool result = true;
            byte[] b1bytes = new byte[bytes];
            byte[] b2bytes = new byte[bytes];

            BitmapData bitmapData1 = bmp1.LockBits(new Rectangle(0, 0, bmp1.Width - 1, bmp1.Height - 1), ImageLockMode.ReadOnly, bmp1.PixelFormat);
            BitmapData bitmapData2 = bmp2.LockBits(new Rectangle(0, 0, bmp2.Width - 1, bmp2.Height - 1), ImageLockMode.ReadOnly, bmp2.PixelFormat);

            Marshal.Copy(bitmapData1.Scan0, b1bytes, 0, bytes);
            Marshal.Copy(bitmapData2.Scan0, b2bytes, 0, bytes);

            for (int n = 0; n <= bytes - 1; n++)
            {
                if (b1bytes[n] != b2bytes[n])
                {
                    result = false;
                    break;
                }
            }
            bmp1.UnlockBits(bitmapData1);
            bmp2.UnlockBits(bitmapData2);

            return result;
        }
        private void DrawGrid()
        {
            Bitmap frontImage = (Bitmap)picMap.Image;

            if (frontImage == null)
                return;

            Graphics gFront = Graphics.FromImage(frontImage);
            Pen pGrid = new Pen(Color.Green);

            for (int k = 0; k < (b1.Width / tileWidth); k++)
            {
                gFront.DrawLine(pGrid, k * tileWidth, 0, k * tileWidth, frontImage.Height);
            }
            for (int j = 0; j < (b1.Height / tileHeight); j++)
            {
                gFront.DrawLine(pGrid, 0, j * tileWidth, frontImage.Width, j * tileWidth);
            }
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

        private void btnSaveTileMap_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFile = new SaveFileDialog();
            DialogResult result = saveFile.ShowDialog();
            if (result == DialogResult.OK)
            {

                if (!Directory.Exists(saveFile.FileName))
                {
                    Directory.CreateDirectory(saveFile.FileName);
                }
                saveTileAndMatrixTile(saveFile.FileName);
            }
        }

        private void saveTileAndMatrixTile(string forderpath)
        {
            System.IO.StreamWriter writer = new StreamWriter(forderpath + "\\TileMaTrix.txt");


            StringBuilder contentSave = new StringBuilder("");
            contentSave.Append("Tile Count: " + "\r\n");
            contentSave.Append(listTile.Count + "\r\n");
            contentSave.Append("Tile Width: " + "\r\n");
            contentSave.Append(tileWidth + "\r\n");
            contentSave.Append("Tile Height: " + "\r\n");
            contentSave.Append(tileHeight + "\r\n");
            contentSave.Append("Tile Count Width: " + "\r\n");
            contentSave.Append(tileCountPerWidth + "\r\n");
            contentSave.Append("Tile Count Height: " + "\r\n");
            contentSave.Append(tileCountPerHeight + "\r\n");



            for (int i = 0; i < tileCountPerHeight; i++)//cocount
            {
                for (int j = 0; j < tileCountPerWidth; j++)//rowcount
                {
                    contentSave.Append(matrix[i, j] + " ");
                }
                contentSave.Append("\r\n");
            }

            writer.Write(contentSave);
            writer.Close();
            picTileMapResult.BackgroundImage.Save(forderpath + "\\TileMap.png");
            if (!Directory.Exists(forderpath + "\\TileMapFolder"))
            {
                Directory.CreateDirectory(forderpath + "\\TileMapFolder");
            }
            for (int i = 0; i < listTile.Count; i++)
            {
                listTile[i].Image.Save(forderpath + "\\TileMapFolder\\" + listTile[i].Id + ".png");
            }
            MessageBox.Show("Đã lưu!");
        }
    }
}
