using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor
{
    enum CursorCur
    {
        ICON,
        OBJECT,
        NONE
    }

    public partial class MapEditor : Form
    {
        Image imageCursor = null;
        CursorCur CurrentCursor;
        private List<Object> listObject;
        private Grid grid;

        Bitmap bmpMap;

        private int objectId;

        private int objectIndexInfo;

        private const int CELL_SIZE = 160;

        private const int START_INDEX = 1;

        int widthBackground, heightBackground;

        public MapEditor()
        {
            InitializeComponent();
            // set panel background
            panel1.AutoScroll = true;
            panel1.HorizontalScroll.Enabled = true;
            panel1.HorizontalScroll.Visible = true;

            // List Object
            listViewOB.LargeImageList = imageListOB;
            listViewOB.View = View.LargeIcon;
            listViewOB.Items.Add("Apple", 0);
            listViewOB.Items.Add("Ruby", 1);
            listViewOB.Items.Add("GenieFace", 2);
            listViewOB.Items.Add("GenieJar", 3);
            listViewOB.Items.Add("Bat", 4);
            listViewOB.Items.Add("NormalGuard", 5);
            listViewOB.Items.Add("ThinGuard", 6);
            listViewOB.Items.Add("FatGuard", 7);
            listViewOB.Items.Add("BoomSkeleton", 8);
            listViewOB.Items.Add("Peddler", 9);
            listViewOB.Items.Add("StoneBrick", 10);
            listViewOB.Items.Add("SharpTrap", 11);
            listViewOB.Items.Add("BallTrap", 12);
            listViewOB.Items.Add("Chains", 13);
            listViewOB.Items.Add("Fence", 14);
            listViewOB.Items.Add("StoneBar", 15);
            listViewOB.Items.Add("Wood", 16);
            listViewOB.Items.Add("Ground", 17);
            listViewOB.Items.Add("Heart", 18);

            //imageListOB.TransparentColor = Color.Transparent;

            // other
            CurrentCursor = CursorCur.NONE;

            listObject = new List<Object>();
            if (listObject != null)
            {
                listObject.Clear();
            }

            tbCellSize.Text = CELL_SIZE + "";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFile = new OpenFileDialog();
            // Set filter options and filter index.
            openFile.Filter = "PNG Files (*.png)|*.png|All Files (*.*)|*.*";
            openFile.FilterIndex = 1;
            openFile.Title = "Open file background";

            if (openFile.ShowDialog() == DialogResult.OK)
            {
                Image image = Image.FromFile(openFile.FileName);
                pictureBoxBG.Image = image;
                pictureBoxBG.SizeMode = PictureBoxSizeMode.AutoSize;

                textBoxBGWidth.Text = "     " + image.Size.Width.ToString() + " pixel";
                textBoxBGHeigth.Text = "     " + image.Size.Height.ToString() + " pixel";

                widthBackground = image.Size.Width;
                heightBackground = image.Size.Height;

                grid = new Grid();
                grid.CreateGrid(widthBackground, heightBackground, int.Parse(tbCellSize.Text));
                //MessageBox.Show(grid.NumXCells.ToString());

                bmpMap = new Bitmap(pictureBoxBG.Image);
            }
        }

        private void listViewOB_MouseClick(object sender, MouseEventArgs e)
        {
            textBoxNameOB.Visible = true;
            CurrentCursor = CursorCur.OBJECT;
            resetObjInfo();

            // Lay image khi click + doi cursor          
            foreach (ListViewItem itm in listViewOB.SelectedItems)
            {
                int imgIndex = itm.ImageIndex;
                if (imgIndex >= 0 && imgIndex < this.imageListOB.Images.Count)
                {
                    imageCursor = this.imageListOB.Images[imgIndex];
                    if (imgIndex == 0)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 7, 7);
                    }
                    else if (imgIndex == 1)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 17, 16);
                    }
                    else if (imgIndex == 2)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 38, 50);
                    }
                    else if (imgIndex == 3)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 20, 33);
                    }
                    else if (imgIndex == 4)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 7, 16);
                    }
                    else if (imgIndex == 5)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 44, 53);
                    }
                    else if (imgIndex == 6)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 41, 60);
                    }
                    else if (imgIndex == 7)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 41, 60);
                    }
                    else if (imgIndex == 8)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 48, 75);
                    }
                    else if (imgIndex == 9)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 26, 52);
                    }
                    else if (imgIndex == 10)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 38, 21);
                    }
                    else if (imgIndex == 11)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 42, 34);
                    }
                    else if (imgIndex == 12)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 33, 52);
                    }
                    else if (imgIndex == 13)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 13, 122);
                    }
                    else if (imgIndex == 14)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 19, 22);
                    }
                    else if (imgIndex == 15)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 49, 8);
                    }
                    else if (imgIndex == 16)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 46, 15);
                    }
                    else if (imgIndex == 18)
                    {
                        imageCursor = Utilities.ResizeImage(imageCursor, 32, 42);
                    }
                }
            }

            this.Cursor = new Cursor(((Bitmap)imageCursor).GetHicon());
            textBoxHeightOB.Text = imageCursor.Height.ToString();
            textBoxWidthOB.Text = imageCursor.Width.ToString();
            textBoxNameOB.Text = listViewOB.SelectedItems[0].Text;
            objectId = listViewOB.SelectedItems[0].ImageIndex + 1;
        }

        private void pictureBoxBG_MouseMove(object sender, MouseEventArgs e)
        {
            MouseEventArgs me = (MouseEventArgs)e;
            Point coordinates = me.Location;
            if (pictureBoxBG.Image != null)
            {
                if (this.imageCursor == null)
                {
                    textBoxX.Text = "na";
                    textBoxY.Text = "na";
                }
                else
                {
                    // toa do top - left
                    if (coordinates.X - imageCursor.Width / 2 >= 0 && coordinates.Y - imageCursor.Height / 2 >= 0
                        && coordinates.X + imageCursor.Width / 2 <= pictureBoxBG.Width && coordinates.Y + imageCursor.Height / 2 <= pictureBoxBG.Height)
                    {
                        textBoxX.Text = (coordinates.X - imageCursor.Width / 2).ToString();
                        textBoxY.Text = (coordinates.Y - imageCursor.Height / 2).ToString();
                    }
                    else
                    {
                        textBoxX.Text = "x";
                        textBoxY.Text = "y";
                    }
                }
            }
        }

        private void pictureBoxBG_Click(object sender, EventArgs e)
        {
            if (CurrentCursor == CursorCur.OBJECT)
            {
                if (textBoxX.Text.Trim() != "x" && textBoxY.Text.Trim() != "y")
                {
                    // them hinh anh vao pictureBox           
                    MouseEventArgs me = (MouseEventArgs)e;
                    Point coordinates = me.Location;
                    PictureBox p = new PictureBox();
                    p.Image = imageCursor;
                    p.Location = new Point(me.Location.X - imageCursor.Width / 2, me.Location.Y - imageCursor.Height / 2);
                    p.SizeMode = PictureBoxSizeMode.AutoSize;
                    p.BackColor = Color.Transparent;

                    // them vao list  
                    string nameOb = textBoxNameOB.Text.Trim();

                    Object ob = new Object(p, objectId, nameOb, (START_INDEX + listObject.Count), Convert.ToInt32(textBoxX.Text.Trim()),
                        Convert.ToInt32(textBoxY.Text.Trim())/*, direction*/);

                    listObject.Add(ob);
                    listObject.ElementAt(listObject.Count - 1).Pic.Click += new System.EventHandler(PictureBoxes_Click);
                    listObject.ElementAt(listObject.Count - 1).Pic.MouseMove += new System.Windows.Forms.MouseEventHandler(PictureBoxes_MouseMove);
                    listObject.ElementAt(listObject.Count - 1).Pic.MouseLeave += new System.EventHandler(PictureBoxes_MouseLeave);
                    pictureBoxBG.Controls.Add(listObject.ElementAt(listObject.Count - 1).Pic);

                    drawImage(p);
                }
                else
                {
                    MessageBox.Show("Don't have background!");
                }
            }
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            if (listObject.Count > 0)
            {
                saveFileDialog1.Filter = "Text Files (*.txt)|*.txt|All files (*.*)|*.*";
                saveFileDialog1.FilterIndex = 1;
                saveFileDialog1.ShowDialog();
            }
            else
            {
                MessageBox.Show("No object in background!");
            }
        }

        private void pictureBoxBG_MouseLeave(object sender, EventArgs e)
        {
            textBoxX.Text = "x";
            textBoxY.Text = "y";

        }

        // click vo picbox new tren background
        private void PictureBoxes_Click(object sender, EventArgs e)
        {
            if (CurrentCursor == CursorCur.ICON)
            {
                // xoa pic tren background va list
                PictureBox p = (PictureBox)sender;

                for (int i = 0; i < listObject.Count; i++)
                {
                    if (listObject.ElementAt(i).Pic == p)
                    {
                        pictureBoxBG.Controls.Remove(listObject.ElementAt(i).Pic);
                        listObject.RemoveAt(i);
                        break;
                    }
                }
            }
            else if (CurrentCursor == CursorCur.NONE)
            {
                PictureBox p = (PictureBox)sender;

                for (int i = 0; i < listObject.Count; i++)
                {
                    if (listObject.ElementAt(i).Pic == p)
                    {
                        objectIndexInfo = i;

                        string id = listObject.ElementAt(i).Id.ToString();
                        string name = listObject.ElementAt(i).Name;
                        int posX = (int)listObject.ElementAt(i).PosX;
                        int posY = (int)listObject.ElementAt(i).PosY;
                        int w = listObject.ElementAt(i).Width;
                        int h = listObject.ElementAt(i).Height;
                        int delay = listObject.ElementAt(i).delay;

                        setOjectInfo(id, name, posX, posY, w, h, delay);

                        break;
                    }
                }
            }
        }

        private void resetObjInfo()
        {
            objectIndexInfo = -1;
            setOjectInfo("", "", 0, 0, 0, 0, 0);
        }

        private void setOjectInfo(string id, string name, int posX, int posY, int w, int h, int delay)
        {
            tbObjId.Text = id;
            tbObjName.Text = name;
            numX.Value = posX;
            numY.Value = posY;
            numWidth.Value = w;
            numHeight.Value = h;
            numObjDelay.Value = delay;
        }

        private void saveFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            grid.clearObject();
            for (int i = 0; i < listObject.Count; i++)
                grid.AddObjToCell(listObject[i]);

            Utilities.WriteFileTxTObj(saveFileDialog1, listObject);
            Utilities.WriteFileTxtGrid(saveFileDialog1, grid);
            MessageBox.Show("Save successfully!");
        }

        private void PictureBoxes_MouseMove(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Hand;
        }

        private void PictureBoxes_MouseLeave(object sender, EventArgs e)
        {
            if (imageCursor != null)
                this.Cursor = new Cursor(((Bitmap)imageCursor).GetHicon());
            else
                this.Cursor = Cursors.Default;
        }

        private void cancelPic_Click(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Default;
            CurrentCursor = CursorCur.NONE;
            imageCursor = null;
            resetObjInfo();
        }

        private void removePic_Click(object sender, EventArgs e)
        {
            imageCursor = this.removePic.Image;
            imageCursor = Utilities.ResizeImage(imageCursor, 8, 8);
            CurrentCursor = CursorCur.ICON;
            this.Cursor = new Cursor(((Bitmap)imageCursor).GetHicon());
            resetObjInfo();
        }

        private void buttonSaveImg_Click(object sender, EventArgs e)
        {
            saveImgFileDialog.Filter = "Image Files (*.png)|*.png|All files (*.*)|*.*";
            saveImgFileDialog.FilterIndex = 1;
            saveImgFileDialog.ShowDialog();
        }

        private void saveImgFileDialog_FileOk(object sender, CancelEventArgs e)
        {
            string path = System.IO.Path.Combine(System.IO.Path.GetDirectoryName(saveImgFileDialog.FileName),
            System.IO.Path.GetFileName(saveImgFileDialog.FileName));

            ImageCodecInfo myImageCodecInfo = GetEncoderInfo("image/jpeg");
            System.Drawing.Imaging.Encoder myEncoder;
            EncoderParameter myEncoderParameter;
            EncoderParameters myEncoderParameters = new EncoderParameters(1);

            myEncoder = System.Drawing.Imaging.Encoder.Quality;
            myEncoderParameter = new EncoderParameter(myEncoder, 100L); // 100% img quality
            myEncoderParameters.Param[0] = myEncoderParameter;

            //pictureBoxBG.Image.Save(@path, ImageFormat.Jpeg);
            //bmpMap.Save(@path, ImageFormat.Jpeg);
            bmpMap.Save(@path, myImageCodecInfo, myEncoderParameters);
            MessageBox.Show("Save image successfully!");
        }

        private static ImageCodecInfo GetEncoderInfo(String mimeType)
        {
            int j;
            ImageCodecInfo[] encoders;
            encoders = ImageCodecInfo.GetImageEncoders();
            for (j = 0; j < encoders.Length; ++j)
            {
                if (encoders[j].MimeType == mimeType)
                    return encoders[j];
            }
            return null;
        }

        private Image getImage(int imgIndex)
        {
            Image image = this.imageListOB.Images[imgIndex];
            if (imgIndex == 0)
            {
                image = Utilities.ResizeImage(image, 7, 7);
            }
            else if (imgIndex == 1)
            {
                image = Utilities.ResizeImage(image, 17, 16);
            }
            else if (imgIndex == 2)
            {
                image = Utilities.ResizeImage(image, 38, 50);
            }
            else if (imgIndex == 3)
            {
                image = Utilities.ResizeImage(image, 20, 33);
            }
            else if (imgIndex == 4)
            {
                image = Utilities.ResizeImage(image, 7, 16);
            }
            else if (imgIndex == 5)
            {
                image = Utilities.ResizeImage(image, 44, 53);
            }
            else if (imgIndex == 6)
            {
                image = Utilities.ResizeImage(image, 41, 60);
            }
            else if (imgIndex == 7)
            {
                image = Utilities.ResizeImage(image, 41, 60);
            }
            else if (imgIndex == 8)
            {
                image = Utilities.ResizeImage(image, 48, 75);
            }
            else if (imgIndex == 9)
            {
                image = Utilities.ResizeImage(image, 26, 52);
            }
            else if (imgIndex == 10)
            {
                image = Utilities.ResizeImage(image, 38, 21);
            }
            else if (imgIndex == 11)
            {
                image = Utilities.ResizeImage(image, 42, 34);
            }
            else if (imgIndex == 12)
            {
                image = Utilities.ResizeImage(image, 33, 52);
            }
            else if (imgIndex == 13)
            {
                image = Utilities.ResizeImage(image, 13, 122);
            }
            else if (imgIndex == 14)
            {
                image = Utilities.ResizeImage(image, 19, 22);
            }
            else if (imgIndex == 15)
            {
                image = Utilities.ResizeImage(image, 49, 8);
            }
            else if (imgIndex == 16)
            {
                image = Utilities.ResizeImage(image, 46, 15);
            }
            else if (imgIndex == 18)
            {
                image = Utilities.ResizeImage(imageCursor, 32, 42);
            }
            return image;
        }

        private void drawImage(PictureBox p)
        {
            Image imgObj = p.Image;
            using (Graphics graphic = Graphics.FromImage(bmpMap))
            {
                graphic.DrawImage(imgObj, p.Location.X, p.Location.Y);
            }
        }

        private void renderListImage()
        {
            if (listObject.Count > 0)
            {
                for (int i = 0; i < listObject.Count; i++)
                {
                    drawImage(listObject.ElementAt(i).Pic);
                }
            }
        }

        private void btnChangeCellSize_Click(object sender, EventArgs e)
        {
            if (textBoxX.Text.Trim() != "x" && textBoxY.Text.Trim() != "y")
            {
                grid.CreateGrid(widthBackground, heightBackground, int.Parse(tbCellSize.Text));
            }
            else
            {
                MessageBox.Show("Don't have background!");
            }
        }

        private void btnLoadObject_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFile = new OpenFileDialog();
            // Set filter options and filter index.
            openFile.Filter = "Text Files (*.txt)|*.txt|All files (*.*)|*.*";
            openFile.FilterIndex = 1;
            openFile.Title = "Load object from file";

            if (openFile.ShowDialog() == DialogResult.OK)
            {
                string[] lines = System.IO.File.ReadAllLines(openFile.FileName);
                string[] infos;
                Object obj;
                PictureBox p;
                int posX, posY, width, height, delay;
                int id;

                clearAllPictureBox();
                foreach (string line in lines)
                {
                    infos = line.Split(' ');

                    posX = int.Parse(infos[2]);
                    posY = int.Parse(infos[3]);
                    width = int.Parse(infos[4]);
                    height = int.Parse(infos[5]);

                    if (infos.Length > 6)
                    {
                        delay = int.Parse(infos[6]);
                    }
                    else
                    {
                        delay = 0;
                    }

                    if (int.TryParse(infos[1], out id))
                    {
                        p = new PictureBox();
                        p.Image = getImage(id - 1);
                        p.Location = new Point(posX, posY);
                        p.SizeMode = PictureBoxSizeMode.AutoSize;
                        p.BackColor = Color.Transparent;

                        obj = new Object(p, id, START_INDEX + listObject.Count, posX, posY, width, height, delay);
                    }
                    else
                    {
                        id = Object.getIdByName(infos[1]);

                        p = new PictureBox();
                        p.Image = getImage(id - 1);
                        p.Location = new Point(posX, posY);
                        p.SizeMode = PictureBoxSizeMode.AutoSize;
                        p.BackColor = Color.Transparent;

                        obj = new Object(p, infos[1], START_INDEX + listObject.Count, posX, posY, width, height, delay);
                    }

                    listObject.Add(obj);
                    listObject.ElementAt(listObject.Count - 1).Pic.Click += new System.EventHandler(PictureBoxes_Click);
                    listObject.ElementAt(listObject.Count - 1).Pic.MouseMove += new System.Windows.Forms.MouseEventHandler(PictureBoxes_MouseMove);
                    listObject.ElementAt(listObject.Count - 1).Pic.MouseLeave += new System.EventHandler(PictureBoxes_MouseLeave);
                    pictureBoxBG.Controls.Add(listObject.ElementAt(listObject.Count - 1).Pic);
                }
                renderListImage();
            }
        }

        private void numObjDelay_ValueChanged(object sender, EventArgs e)
        {
            if (objectIndexInfo != -1)
            {
                listObject.ElementAt(objectIndexInfo).delay = (int)numObjDelay.Value;
            }
        }

        private void numWidth_ValueChanged(object sender, EventArgs e)
        {
            if (objectIndexInfo != -1)
            {
                listObject.ElementAt(objectIndexInfo).Width = (int)numWidth.Value;
            }
        }

        private void numHeight_ValueChanged(object sender, EventArgs e)
        {
            if (objectIndexInfo != -1)
            {
                listObject.ElementAt(objectIndexInfo).Height = (int)numHeight.Value;
            }
        }

        private void numX_ValueChanged(object sender, EventArgs e)
        {
            if (objectIndexInfo != -1)
            {
                listObject.ElementAt(objectIndexInfo).PosX = (int)numX.Value;
            }
        }

        private void numY_ValueChanged(object sender, EventArgs e)
        {
            if (objectIndexInfo != -1)
            {
                listObject.ElementAt(objectIndexInfo).PosY = (int)numY.Value;
            }
        }

        private void clearAllPictureBox()
        {
            if (listObject.Count > 0)
            {
                for (int i = 0; i < listObject.Count; i++)
                {
                    pictureBoxBG.Controls.Remove(listObject.ElementAt(i).Pic);
                }
            }
        }

        //private void buttonRest_Click(object sender, EventArgs e)
        //{
        //    imageCursor = null;
        //    CurrentCursor = CursorCur.NONE;
        //    if (listObject.Count > 0)
        //    {
        //        for (int i = 0; i < listObject.Count; i++)
        //        {
        //            pictureBoxBG.Controls.Remove(listObject.ElementAt(i).Pic);
        //        }
        //    }
        //    listObject.Clear();

        //    pictureBoxBG.Image = null;
        //}
    }
}
