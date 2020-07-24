using MapEditor.Objects;
using MapEditor.Objects.BottomStair;
using MapEditor.Objects.Portal;
using MapEditor.Objects.Simon;
using MapEditor.Objects.TopStair;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
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
        private List<Obj> listObject;
        private Grid grid;

        Bitmap bmpMap;

        private int objectId;

        private int objectIndexInfo;

        public const int CELL_SIZE = 128;

        public const int START_INDEX = 0;

        int widthBackground, heightBackground;

        public MapEditor()
        {
            InitializeComponent();
            // set panel background
            panel1.AutoScroll = true;
            panel1.HorizontalScroll.Enabled = true;
            panel1.HorizontalScroll.Visible = true;

            // List Obj
            listViewOB.LargeImageList = imageListOB;
            listViewOB.View = View.LargeIcon;

            for (int i = 0; i < imageListOB.Images.Count; i++)
            {
                listViewOB.Items.Add(imageListOB.Images.Keys[i], i);
            }

            CurrentCursor = CursorCur.NONE;

            listObject = new List<Obj>();
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
                btnLoadObject.Enabled = true;
            }
        }

        private void listViewOB_MouseClick(object sender, MouseEventArgs e)
        {
            textBoxNameOB.Visible = true;
            CurrentCursor = CursorCur.OBJECT;
            resetObjInfo();
            int imgIndex = listViewOB.SelectedItems[0].ImageIndex;
            string name = listViewOB.SelectedItems[0].Text;
            imageCursor = this.imageListOB.Images[imgIndex];

            switch (name)
            {
                case "Simon":
                case "Torch":
                case "Zombie":
                case "FishMan":
                case "BlackKnight":
                case "Skeleton":
                    imageCursor = Utilities.ResizeImage(imageCursor, 16, 32);
                    break;
                case "Candle":
                    imageCursor = Utilities.ResizeImage(imageCursor, 8, 16);
                    break;
                case "Gate":
                    imageCursor = Utilities.ResizeImage(imageCursor, 8, 48);
                    break;
                case "BoundingMap":
                case "Portal":
                case "Ground":
                case "Whip":
                case "Money":
                case "Ball":
                case "SmallHeart":
                case "Ghost":
                case "Fleamen":
                case "PhantomBat":
                    imageCursor = Utilities.ResizeImage(imageCursor, 16, 16);
                    break;
                case "BottomStair":
                case "TopStair":
                case "Heart":
                    imageCursor = Utilities.ResizeImage(imageCursor, 8, 8);
                    break;
                case "Knife":
                case "Axe":
                case "Boomerang":
                    imageCursor = Utilities.ResizeImage(imageCursor, 15, 14);
                    break;
                case "Crown":
                    imageCursor = Utilities.ResizeImage(imageCursor, 15, 16);
                    break;
                case "BlackLeopard":
                    imageCursor = Utilities.ResizeImage(imageCursor, 24, 15);
                    break;
                case "VampireBat":
                    imageCursor = Utilities.ResizeImage(imageCursor, 12, 14);
                    break;
                case "MovingPlatform":
                    imageCursor = Utilities.ResizeImage(imageCursor, 32, 8);
                    break;
                case "Raven":
                    imageCursor = Utilities.ResizeImage(imageCursor, 16, 12);
                    break;
            }
            this.Cursor = new Cursor(((Bitmap)imageCursor).GetHicon());
            textBoxHeightOB.Text = imageCursor.Height.ToString();
            textBoxWidthOB.Text = imageCursor.Width.ToString();
            textBoxNameOB.Text = name;
            objectId = imgIndex + 1;
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
                gbDetail.Controls.Clear();
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

                    Obj ob = GetInstanceObject(nameOb, new object[] { p, Convert.ToInt32(textBoxX.Text.Trim()), Convert.ToInt32(textBoxY.Text.Trim()), p.Width, p.Height });

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

        private Obj GetInstanceObject(string name, object[] args)
        {
            string strFullyQualifiedName = " MapEditor.Objects." + name + "." + name;
            return (Obj)GetInstance(strFullyQualifiedName, args);
        }

        private UserControl GetInstanceObjectUC(string name, Obj obj)
        {
            string strFullyQualifiedName = " MapEditor.Objects." + name + "." + name + "UC";
            return (UserControl)GetInstance(strFullyQualifiedName, new object[] { obj });
        }

        private object GetInstance(string name, object[] args)
        {
            Type type = Type.GetType(name);
            if (type != null)
                return Activator.CreateInstance(type, args);
            foreach (var asm in AppDomain.CurrentDomain.GetAssemblies())
            {
                type = asm.GetType(name);
                if (type != null)
                    return Activator.CreateInstance(type);
            }
            return null;
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            if (listObject.Count > 0)
            {
                using (var folderBrowser = new OpenFileDialog())
                {
                    folderBrowser.ValidateNames = false;
                    folderBrowser.CheckFileExists = false;
                    folderBrowser.CheckPathExists = true;
                    // Always default to Folder Selection.
                    folderBrowser.FileName = "Folder Selection.";
                    if (folderBrowser.ShowDialog() == DialogResult.OK)
                    {
                        string folderPath = Path.GetDirectoryName(folderBrowser.FileName);
                        grid.clearObject();
                        for (int i = 0; i < listObject.Count; i++)
                            grid.AddObjToCell(listObject[i], i);

                        Utilities.WriteFileTxTObj(folderPath, listObject);
                        Utilities.WriteFileTxtGrid(folderPath, grid);
                        MessageBox.Show("Save successfully!");
                    }
                }
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
            gbDetail.Controls.Clear();
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

                        int id = listObject.ElementAt(i).Type;
                        string name = listObject.ElementAt(i).GetType().Name;
                        int posX = (int)listObject.ElementAt(i).PosX;
                        int posY = (int)listObject.ElementAt(i).PosY;
                        int w = listObject.ElementAt(i).Width;
                        int h = listObject.ElementAt(i).Height;
                        int itemType = listObject.ElementAt(i).ItemType;


                        UserControl userControl = GetInstanceObjectUC(name, listObject.ElementAt(i));
                        if (userControl != null)
                        {
                            userControl.Dock = DockStyle.Fill;
                            gbDetail.Controls.Add(userControl);
                        }

                        switch (listObject.ElementAt(i).Type)
                        {
                            case Portal.TYPE:
                                Portal portal = (Portal)listObject.ElementAt(i);
                                break;
                            case Simon.TYPE:
                                Simon simon = (Simon)listObject.ElementAt(i);
                                break;
                        }

                        setOjectInfo(id, name, posX, posY, w, h, itemType);

                        break;
                    }
                }
            }
        }

        private void resetObjInfo()
        {
            objectIndexInfo = -1;
            setOjectInfo(-1, "", 0, 0, 0, 0, -2);
        }

        private void setOjectInfo(int type, string name, int posX, int posY, int w, int h, int itemType)
        {
            tbObjId.Text = type == -1 ? "" : type.ToString();
            tbObjName.Text = name;
            numX.Value = posX;
            numY.Value = posY;
            numWidth.Value = w;
            numHeight.Value = h;

            switch (type)
            {
                case Portal.TYPE:
                case TopStair.TYPE:
                case BottomStair.TYPE:
                case Simon.TYPE:
                    cboItemType.SelectedIndex = 0;
                    cboItemType.Enabled = false;
                    break;
                default:
                    cboItemType.SelectedIndex = itemType + 2;
                    cboItemType.Enabled = true;
                    break;
            }
        }

        private void PictureBoxes_MouseMove(object sender, EventArgs e)
        {
            if (CurrentCursor != CursorCur.OBJECT)
            {
                this.Cursor = Cursors.Hand;
            }
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
            gbDetail.Controls.Clear();
            this.Cursor = Cursors.Default;
            CurrentCursor = CursorCur.NONE;
            imageCursor = null;
            resetObjInfo();
        }

        private void removePic_Click(object sender, EventArgs e)
        {
            gbDetail.Controls.Clear();
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

        private Image getImageByName(string name)
        {
            int imgIndex = getImageIndexByName(name);
            Image image = this.imageListOB.Images[imgIndex];
            return image;
        }

        private int getImageIndexByName(string name)
        {
            int imgIndex = 0;

            for (int i = 0; i < imageListOB.Images.Count; i++)
            {
                if (imageListOB.Images.Keys[i].Equals(name))
                {
                    return i;
                }
            }

            return imgIndex;
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
                Obj obj;
                PictureBox pic;
                int posX, posY, width, height;
                int id;
                string name;

                clearAllPictureBox();
                foreach (string line in lines)
                {
                    if (line.StartsWith("#") || line.StartsWith("//")) continue;
                    infos = line.Split(' ');

                    name = infos[2];
                    posX = int.Parse(infos[3]);
                    posY = int.Parse(infos[4]);
                    width = int.Parse(infos[5]);
                    height = int.Parse(infos[6]);

                    if (int.TryParse(infos[1], out id))
                    {
                        pic = new PictureBox();
                        pic.Image = Utilities.ResizeImage(getImageByName(name), width, height);
                        pic.Location = new Point(posX, posY);
                        pic.SizeMode = PictureBoxSizeMode.AutoSize;
                        pic.BackColor = Color.Transparent;

                        obj = GetInstanceObject(name, new object[] { pic, infos });

                        listObject.Add(obj);
                        listObject.ElementAt(listObject.Count - 1).Pic.Click += new System.EventHandler(PictureBoxes_Click);
                        listObject.ElementAt(listObject.Count - 1).Pic.MouseMove += new System.Windows.Forms.MouseEventHandler(PictureBoxes_MouseMove);
                        listObject.ElementAt(listObject.Count - 1).Pic.MouseLeave += new System.EventHandler(PictureBoxes_MouseLeave);
                        pictureBoxBG.Controls.Add(listObject.ElementAt(listObject.Count - 1).Pic);
                    }

                }
                renderListImage();
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

        private void cboItemType_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (objectIndexInfo != -1)
            {
                listObject.ElementAt(objectIndexInfo).ItemType = (int)cboItemType.SelectedIndex - 2;
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
    }
}
