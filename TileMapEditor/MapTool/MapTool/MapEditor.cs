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
    public partial class MapEditor : Form
    {
        public MapEditor()
        {
            InitializeComponent();
        }
        List<Tile> listTile = new List<Tile>();//list tile map
        Bitmap b1;
        Image i;
        int tileWidth, tileHeight;
        int tileCountPerWidth, tileCountPerHeight;
        int[,] matrix;
        int indexHeightOfMap;

        Image j;
        List<Tile> listTileGet = new List<Tile>();
        int X;
        bool picked;
        int curPicMapX, curPicMapY;
        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            DialogResult result = openFileDialog1.ShowDialog();
            if (result == DialogResult.OK)
            {
                listTile.Clear();

                i = Image.FromFile(openFileDialog1.FileName);
                

                b1 = new Bitmap(i.Width, i.Width);
                Graphics.FromImage(b1).Clear(Color.Black);
                DrawImageToImage(b1, (Bitmap)i, new Point(0, i.Width-i.Height), new Rectangle(0, 0, i.Width, i.Height));
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

       

        private void InitTileImage()
        {
            matrix = new int[tileCountPerHeight,tileCountPerWidth];

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
        Bitmap currentDrawGrid;
        private void DrawGrid()
        {
            Bitmap frontImage =(Bitmap)  picMap.Image;
            
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
        Bitmap bmCrop(Image src, Rectangle rectClip)
        {
            Bitmap b = new Bitmap(rectClip.Width, rectClip.Height);
            DrawImageToImage(b, (Bitmap)src, Point.Empty, rectClip);
            return b;
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
        public bool CompareBitmap2(Bitmap bmp1, Bitmap bmp2)
        {
            string img_1, img_2;
            if (bmp1.Width == bmp2.Width && bmp1.Height == bmp2.Height)
            {
                for (int i = 0; i < bmp1.Width; i++)
                    for (int j = 0; j < bmp1.Height; j++)
                    {
                        img_1 = bmp1.GetPixel(i, j).ToString();
                        img_2 = bmp2.GetPixel(i, j).ToString();
                        if (img_1 != img_2) return false;
                    }
                return true;
            }
            else return true;
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

        
        private void saveTileAndMatrixTile(string forderpath)
        {
            System.IO.StreamWriter writer = new StreamWriter(forderpath + "\\TileMaTrix.txt");


            StringBuilder contentSave = new StringBuilder("");
            //contentSave.Append("Tile Count: " + "\r\n");
            contentSave.Append(listTile.Count + "\r\n");
           // contentSave.Append("Tile Width: " + "\r\n");
            contentSave.Append(tileWidth + "\r\n");
           // contentSave.Append("Tile Height: " + "\r\n");
            contentSave.Append(tileHeight + "\r\n");
           // contentSave.Append("Tile Number Width: " + "\r\n");
            contentSave.Append(tileCountPerWidth + "\r\n");
           // contentSave.Append("Tile Number Height: " + "\r\n");
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
        void reset()
        {
            picMap.BackgroundImage = null;
            picTileMapResult.BackgroundImage = null;
            listTile.Clear();
        }
        
        private void picMap_Paint(object sender, PaintEventArgs e)
        {
            if (objPickList.Count != 0 )
                e.Graphics.DrawImage((Bitmap)objPickList[Y].Bmp, new Point(curPicMapX, curPicMapY));
        }
        List<ObjectDraw> pointDrawObjectList = new List<ObjectDraw>();
        public List<ObjectInFile> listObj2 = new List<ObjectInFile>();
        bool isCheck;
        private void picMap_MouseDown(object sender, MouseEventArgs e)
        {
            if (objPickList.Count != 0 && isCheck==false)
            {
                
                ObjectDraw objDraw = new ObjectDraw(objPickList[Y].Bmp, new Point(curPicMapX, curPicMapY));
                pointDrawObjectList.Add(objDraw);

                foreach (ObjectDraw obj in pointDrawObjectList)
                    DrawImageToImage((Bitmap)picMap.Image, obj.Bm, obj.Point, new Rectangle(0, 0, obj.Bm.Width, obj.Bm.Height));
                //DrawGrid();

                ObjectInFile obj2 = new ObjectInFile();
                Rectangle rect2 = new Rectangle(curPicMapX, curPicMapY
                                    , objPickList[Y].Bmp.Width, objPickList[Y].Bmp.Height);
                obj2.Name = objPickList[Y].Name.ToString();
                obj2.Rect = rect2;
                AddObject(obj2);
                currentDrawGrid = (Bitmap)picMap.Image;
            }
        }


        void AddObject(ObjectInFile obj)
        {
            obj.index = listObj2.Count;
            listObj2.Add(obj);
        }

        Rectangle moveRect = new Rectangle();
        private void picMap_MouseMove(object sender, MouseEventArgs e)
        {
            lblMouseLocation.Text="( "+e.X+" , "+e.Y+" )";
            curPicMapX = e.X;
            curPicMapY = e.Y;
            if (picked)
            {
                moveRect.X = e.X;
                moveRect.Y = e.Y;
                moveRect.Width = objPickList[Y].Bmp.Width;
                moveRect.Height = objPickList[Y].Bmp.Height;
                picMap.Invalidate();
            }
        }
        int Y;
        int rectSizeinObject=128;
        private void picObject_MouseClick(object sender, MouseEventArgs e)
        {
            Y = e.Y / rectSizeinObject;
            picObject.Image = new Bitmap(picObject.Width, picObject.Height);
            Graphics.FromImage(picObject.Image).DrawRectangle(new Pen(Color.Blue)
                , new Rectangle(0, Y * rectSizeinObject, rectSizeinObject, rectSizeinObject));
            picObject.Invalidate();
            if (objPickList.Count != 0)
                picked = true;
        }
        String getName(String path)
        {
            path = path.Remove(path.IndexOf('.'));
            String[] l = path.Split('\\');

            return l[l.Count() - 1];
        }
        public List<ObjectInFile> objPickList = new List<ObjectInFile>();// list lưu ảnh obj trong panel bên phải
        public List<int> tempList = new List<int>();// list lưu tọa độ y của đối tượng trong panel bên phải

        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            try
            {
                openFolder.ShowDialog();
                tileWidth = int.Parse(txtTileWidth.Text);
                tileHeight = int.Parse(txtTileHeight.Text);
                String path = openFolder.SelectedPath;
                String[] listImage = Directory.GetFiles(path);
                for (int k = 0; k < listImage.Length; k++)
                {
                    String name = getName(listImage[k]);
                    Bitmap bm = (Bitmap)Bitmap.FromFile(listImage[k]);
                    objPickList.Add(new ObjectInFile(name, bm));
                    tempList.Add(k * rectSizeinObject);
                }
                picObject.Width = 200;
                picObject.Height = 0;
                for (int i = 0; i < objPickList.Count; i++)
                    picObject.Height += objPickList[i].Bmp.Height + tempList[i];
                //picObject.Height += objPickList[i].Height;
                picObject.BackgroundImage = new Bitmap(picObject.Width, picObject.Height);
                for (int i = 0; i < objPickList.Count; i++)
                    DrawImageToImage((Bitmap)picObject.BackgroundImage, objPickList[i].Bmp
                        , new Point(0, tempList[i]));
                picObject.Invalidate();
            }
            catch (Exception)
            {
                MessageBox.Show("Import Object");
            }
        }

        private void btnBack_Click(object sender, EventArgs e)
        {
            //picMap.Image = null;
            //picMap.Image = new Bitmap(i.Width, i.Height);
            //pointDrawObjectList.RemoveAt(pointDrawObjectList.Count-1);
            //foreach (ObjectDraw obj in pointDrawObjectList)
            //    DrawImageToImage((Bitmap)picMap.Image, obj.Bm, obj.Point, new Rectangle(0, 0, obj.Bm.Width, obj.Bm.Height));
            //DrawGrid();
        }

        

       
       
        private void button1_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < listObj2.Count; i++)
                listObj2[i].ID = i;
            // QuadTree(new Node(0, new Rectangle(0, 0, picMap.Width, picMap.Height)),listObj2);

            Node.rootNode = new Node("1", new Rectangle(0, 0, picMap.Width, picMap.Height), listObj2);

            SaveFileDialog saveFile = new SaveFileDialog();
            DialogResult result = saveFile.ShowDialog();
            if (result == DialogResult.OK)
            {

                if (!Directory.Exists(saveFile.FileName))
                {
                    Directory.CreateDirectory(saveFile.FileName);
                }
                saveObjectList(saveFile.FileName);
              //   saveQuadtree(saveFile.FileName);

                Node.saveQuadTree(saveFile.FileName + "\\QuadTree.txt");

                Node.rootNode.drawRect(Graphics.FromImage(picMap.Image));

                picMap.BackgroundImage.Save(saveFile.FileName + "\\" + "Map.png");
                picMap.Image.Save(saveFile.FileName + "\\" + "MapQuadTree.png");


                MessageBox.Show("Đã lưu!");


            }
        }

        private void saveObjectList(string forderpath)
        {
            System.IO.StreamWriter writer = new StreamWriter(forderpath + "\\ObjectList.txt");
            StringBuilder contentSave = new StringBuilder("");
           // contentSave.Append("Object Count:\r\n");
            contentSave.Append(listObj2.Count+"\t");
            contentSave.Append("\r\n");
            //contentSave.Append("ObjectID" + "\t" +
            //                    "Name" + "\t" +
            //                    "X" + "\t" +
            //                    "Y" + "\t" +
            //                    "Width" + "\t" +
            //                    "Height" + "\t" + "\r\n");
            for (int j = 0; j < listObj2.Count; j++)
            {
                contentSave.Append(listObj2[j].ID + "\t" +
                            listObj2[j].Name + "\t" +
                            listObj2[j].Rect.X + "\t" +
                            listObj2[j].Rect.Y + "\t" +
                            listObj2[j].Rect.Width + "\t" +
                            listObj2[j].Rect.Height + "\t");// + "0\t");

                contentSave.Append("\r\n");
            }
            writer.Write(contentSave);
            writer.Close();
        }

        private void saveQuadtree(string forderpath)
        {
            System.IO.StreamWriter writer = new StreamWriter(forderpath + "\\QuadTree.txt");
            StringBuilder contentSave = new StringBuilder("");
            //contentSave.Append("NodeID"+"\t" +
            //                    "XNode"+"\t" +
            //                    "YNode"+"\t" +
            //                    "WidthNode"+"\t" +
            //                    "HeightNode"+"\t" +
            //                    "ObjectCount"+"\t"+
            //                    "ObjectID" + "\t" + "\r\n");

            contentSave.Append("0\t0\t0\t"+picMap.Width+"\t"+picMap.Height+"\t"+listObj2.Count+"\t");
            for (int i = 0; i < listObj2.Count; i++)
                contentSave.Append(listObj2[i].ID+"\t");
            contentSave.Append("\r\n");

            for (int s = 0; s < nodeList.Count; s++)
            {
                contentSave.Append(nodeList[s].ID + "\t" +
                            nodeList[s].RectNode.X + "\t" +
                            nodeList[s].RectNode.Y + "\t" +
                            nodeList[s].RectNode.Width + "\t" +
                            nodeList[s].RectNode.Height + "\t" +
                            nodeList[s].ObjInNodeList.Count + "\t");
                for (int i = 0; i < nodeList[s].ObjInNodeList.Count; i++)
                    contentSave.Append(nodeList[s].ObjInNodeList[i].ID +" ");
                contentSave.Append("\r\n");
            }
            //contentSave.Append("\r\n");
            //contentSave.Append("ObjectID" + "\t" +
            //                    "Name" + "\t" +
            //                    "X" + "\t" +
            //                    "Y" + "\t" +
            //                    "Width" + "\t" +
            //                    "Height" + "\t" + "\r\n");
            //for (int j = 0; j < listObj2.Count; j++)
            //{
            //    contentSave.Append(listObj2[j].ID + "\t" +
            //                listObj2[j].Name + "\t" +
            //                listObj2[j].Rect.X + "\t" +
            //                listObj2[j].Rect.Y + "\t" +
            //                listObj2[j].Rect.Width + "\t"+
            //                listObj2[j].Rect.Height + "\t");
            //    contentSave.Append("\r\n");
            //}
            writer.Write(contentSave);
            writer.Close();
            MessageBox.Show("Đã lưu!");
        }
        List<Rectangle> drawQuadTreeList = new List<Rectangle>();
        private void QuadTree(Node root, List<ObjectInFile> Objlist)
        {


            

            //Bitmap frontImage = (Bitmap)picMap.Image;
            //if (frontImage == null)
            //    return;
            //Graphics gFront = Graphics.FromImage(frontImage);
            //Pen pGrid = new Pen(Color.Red,3);
            //if (Objlist.Count == 0)
            //    return;
            //if (root.RectNode.Height > 320)
            //{

            //    Rectangle rectTL= new Rectangle(root.RectNode.X, root.RectNode.Y, root.RectNode.Width / 2, root.RectNode.Height / 2);
            //    Rectangle rectTR = new Rectangle(root.RectNode.X + root.RectNode.Width / 2, root.RectNode.Y, root.RectNode.Width / 2, root.RectNode.Height / 2);
            //    Rectangle rectBL = new Rectangle(root.RectNode.X, root.RectNode.Y + root.RectNode.Height / 2, root.RectNode.Width / 2, root.RectNode.Height / 2);
            //    Rectangle rectBR = new Rectangle(root.RectNode.X + root.RectNode.Width / 2, root.RectNode.Y + root.RectNode.Height / 2, root.RectNode.Width / 2, root.RectNode.Height / 2);
            //    drawQuadTreeList.Add(rectTL);
            //    drawQuadTreeList.Add(rectTR);
            //    drawQuadTreeList.Add(rectBL);
            //    drawQuadTreeList.Add(rectBR);
            //    for (int k = 0; k < drawQuadTreeList.Count; k++)
            //        gFront.DrawRectangle(pGrid, drawQuadTreeList[k]);
                
            //    root.nodeTL = new Node(root.ID * 10 + 1,rectTL);// phân hoạch node
            //    clip(root.nodeTL, Objlist);//gắn đối tượng vào node
            //    QuadTree(root.nodeTL, root.nodeTL.ObjInNodeList);// lặp lại với mấy node con

            //    root.nodeTR = new Node(root.ID * 10 + 2,rectTR );
            //    clip(root.nodeTR, Objlist);
            //    QuadTree(root.nodeTR, root.nodeTR.ObjInNodeList);

            //    root.nodeBL = new Node(root.ID * 10 + 3,rectBL );
            //    clip(root.nodeBL, Objlist);
            //    QuadTree(root.nodeBL, root.nodeBL.ObjInNodeList);

            //    root.nodeBR = new Node(root.ID * 10 + 4,rectBR );
            //    clip(root.nodeBR, Objlist);
            //    QuadTree(root.nodeBR, root.nodeBR.ObjInNodeList);

            //    //int a = 1;

            //}
            //else
            //    return;
        }
        List<Node> nodeList = new List<Node>(); 
        public void clip(Node node, List<ObjectInFile> list)
        {
            foreach(ObjectInFile obj in list)
                if (AABBCheck(obj.Rect, node.RectNode))
                    node.ObjInNodeList.Add(obj);
            nodeList.Add(node);
        }
        public bool AABBCheck(Rectangle b1, Rectangle b2)
        {
            return ((b1.Y + b1.Height) >= b2.Y && b1.Y <= (b2.Y + b2.Height) &&
                    b1.X <= (b2.X + b2.Width) && (b1.X + b1.Width) >= b2.X);
        }

        private void picTileMapResult_MouseClick(object sender, MouseEventArgs e)
        {
            int tileSize = int.Parse(txtTileWidth.Text.ToString());
            X = e.X / tileSize;
            picTileMapResult.Image = new Bitmap(listTile.Count * tileWidth, tileHeight);
            Graphics.FromImage(picTileMapResult.Image).DrawRectangle(new Pen(Color.Yellow), new Rectangle(X * tileWidth, 0, tileWidth, tileHeight));
            picTileMapResult.Invalidate();
        }
        public List<Tile> groundTileList = new List<Tile>();// list lưu tile đối tượng gạch trên map

        private void btnGetGround_Click(object sender, EventArgs e)
        {
            currentDrawGrid = (Bitmap)picMap.Image;
            picGroundObject.Width = listTile.Count * tileWidth * 2;
            picGroundObject.Height = tileHeight;
            picGroundObject.BackgroundImage = new Bitmap(picGroundObject.Width, picGroundObject.Height);
            groundTileList.Add(listTile[X]);
            for (int k = 0; k < groundTileList.Count; k++)
            {
                DrawImageToImage((Bitmap)picGroundObject.BackgroundImage, groundTileList[k].Image, new Point(k * 32, 0));

                for (int i = indexHeightOfMap; i < tileCountPerHeight; i++)
                {
                    for (int j = 0; j < tileCountPerWidth; j++)
                    {
                        Bitmap bmp = bmCrop(picMap.BackgroundImage, new Rectangle(j * tileWidth, i * tileWidth, tileWidth, tileHeight));
                        Tile t = new Tile(bmp);
                        if (CompareBitmap(t.Image, groundTileList[k].Image))
                        {
                            Bitmap blackBmp = new Bitmap(groundTileList[k].Image.Width, groundTileList[k].Image.Height);
                            Graphics.FromImage((Bitmap)blackBmp).Clear(Color.Black);
                            DrawImageToImage((Bitmap)picMap.Image, blackBmp, new Point(j * tileWidth, i * tileHeight));
                            picMap.Invalidate();
                            AddObject(new ObjectInFile("0", new Rectangle(j * tileWidth, i * tileHeight, tileWidth, tileHeight)));
                        }
                    }
                }
                picGroundObject.Invalidate();
            }
        }
        // Phát Sinh Thêm
        public List<Tile> limitCameraTileList = new List<Tile>();// list lưu tile đối tượng limit camera trên map
        private void btnGetLimitCam_Click(object sender, EventArgs e)
        {
            currentDrawGrid = (Bitmap)picMap.Image;
            picGroundObject.Width = listTile.Count * tileWidth * 2;
            picGroundObject.Height = tileHeight;
            picGroundObject.BackgroundImage = new Bitmap(picGroundObject.Width, picGroundObject.Height);
            limitCameraTileList.Add(listTile[X]);
            for (int k = 0; k < limitCameraTileList.Count; k++)
            {
                DrawImageToImage((Bitmap)picGroundObject.BackgroundImage, limitCameraTileList[k].Image, new Point(k * 32+32, 0));

                for (int i = indexHeightOfMap; i < tileCountPerHeight; i++)
                {
                    for (int j = 0; j < tileCountPerWidth; j++)
                    {
                        Bitmap bmp = bmCrop(picMap.BackgroundImage, new Rectangle(j * tileWidth, i * tileWidth, tileWidth, tileHeight));
                        Tile t = new Tile(bmp);
                        if (CompareBitmap(t.Image, limitCameraTileList[k].Image))
                        {
                            Bitmap blackBmp = new Bitmap(limitCameraTileList[k].Image.Width, limitCameraTileList[k].Image.Height);
                            Graphics.FromImage((Bitmap)blackBmp).Clear(Color.Black);
                            DrawImageToImage((Bitmap)picMap.Image, blackBmp, new Point(j * tileWidth, i * tileHeight));
                            picMap.Invalidate();
                            AddObject(new ObjectInFile("9", new Rectangle(j * tileWidth, i * tileHeight, tileWidth, tileHeight)));
                        }
                    }
                }
                picGroundObject.Invalidate();
            }
        }
        // Phát Sinh Thêm
        private void toolStripButton3_Click_1(object sender, EventArgs e)
        {
            MessageBox.Show("1.Import background\n"+
                "2.Import object (.png)\n"+
                "3.Chọn các object rồi đặt vô map background \n"+
                "4.SaveQuadTree\n"+
                "Chức năng Get Brick để lấy nhanh đối tượng gạch (hỗ trợ cho bước 3 đỡ phải đặt từng viên gạch lên map)");
        }

     

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                isCheck = true;
                picMap.Image = new Bitmap(i.Width, i.Height);
            }
            else
            {
                isCheck = false;
                picMap.Image = currentDrawGrid;
            }
        }

        private void btnGetIDObject_Click(object sender, EventArgs e)
        {
            //for (int i = 0; i < listObj2.Count; i++)
            //    listObj2[i].ID = i;
            //MessageBox.Show("Đã Xong!");
        }


        private void toolStripButton4_Click(object sender, EventArgs e)
        {
            
        }


       

        
     
    }
}
