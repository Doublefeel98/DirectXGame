namespace MapEditor
{
    partial class MapEditor
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MapEditor));
            this.buttonLoad = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.pictureBoxBG = new System.Windows.Forms.PictureBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.textBoxNameOB = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.textBoxHeightOB = new System.Windows.Forms.TextBox();
            this.textBoxWidthOB = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.panel3 = new System.Windows.Forms.Panel();
            this.listViewOB = new System.Windows.Forms.ListView();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.textBoxBGWidth = new System.Windows.Forms.TextBox();
            this.textBoxBGHeigth = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.textBoxX = new System.Windows.Forms.TextBox();
            this.textBoxY = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.imageListOB = new System.Windows.Forms.ImageList(this.components);
            this.buttonSave = new System.Windows.Forms.Button();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.cancelPic = new System.Windows.Forms.PictureBox();
            this.removePic = new System.Windows.Forms.PictureBox();
            this.buttonSaveImg = new System.Windows.Forms.Button();
            this.saveImgFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.btnLoadObject = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.btnChangeCellSize = new System.Windows.Forms.Button();
            this.tbCellSize = new System.Windows.Forms.TextBox();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxBG)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.panel3.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cancelPic)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.removePic)).BeginInit();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // buttonLoad
            // 
            this.buttonLoad.Location = new System.Drawing.Point(17, 10);
            this.buttonLoad.Margin = new System.Windows.Forms.Padding(4);
            this.buttonLoad.Name = "buttonLoad";
            this.buttonLoad.Size = new System.Drawing.Size(151, 28);
            this.buttonLoad.TabIndex = 1;
            this.buttonLoad.Text = "Load Background";
            this.buttonLoad.UseVisualStyleBackColor = true;
            this.buttonLoad.Click += new System.EventHandler(this.button1_Click);
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.pictureBoxBG);
            this.panel1.Location = new System.Drawing.Point(17, 74);
            this.panel1.Margin = new System.Windows.Forms.Padding(4);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1313, 632);
            this.panel1.TabIndex = 2;
            // 
            // pictureBoxBG
            // 
            this.pictureBoxBG.Location = new System.Drawing.Point(-1, 4);
            this.pictureBoxBG.Margin = new System.Windows.Forms.Padding(4);
            this.pictureBoxBG.Name = "pictureBoxBG";
            this.pictureBoxBG.Size = new System.Drawing.Size(1293, 623);
            this.pictureBoxBG.TabIndex = 0;
            this.pictureBoxBG.TabStop = false;
            this.pictureBoxBG.Click += new System.EventHandler(this.pictureBoxBG_Click);
            this.pictureBoxBG.MouseLeave += new System.EventHandler(this.pictureBoxBG_MouseLeave);
            this.pictureBoxBG.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pictureBoxBG_MouseMove);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.textBoxNameOB);
            this.groupBox1.Controls.Add(this.label7);
            this.groupBox1.Controls.Add(this.textBoxHeightOB);
            this.groupBox1.Controls.Add(this.textBoxWidthOB);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(7, 576);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox1.Size = new System.Drawing.Size(236, 159);
            this.groupBox1.TabIndex = 5;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Detail : ";
            // 
            // textBoxNameOB
            // 
            this.textBoxNameOB.Location = new System.Drawing.Point(76, 128);
            this.textBoxNameOB.Margin = new System.Windows.Forms.Padding(4);
            this.textBoxNameOB.Name = "textBoxNameOB";
            this.textBoxNameOB.ReadOnly = true;
            this.textBoxNameOB.Size = new System.Drawing.Size(132, 22);
            this.textBoxNameOB.TabIndex = 5;
            this.textBoxNameOB.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(13, 132);
            this.label7.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(53, 17);
            this.label7.TabIndex = 4;
            this.label7.Text = "Name :";
            // 
            // textBoxHeightOB
            // 
            this.textBoxHeightOB.Location = new System.Drawing.Point(76, 87);
            this.textBoxHeightOB.Margin = new System.Windows.Forms.Padding(4);
            this.textBoxHeightOB.Name = "textBoxHeightOB";
            this.textBoxHeightOB.ReadOnly = true;
            this.textBoxHeightOB.Size = new System.Drawing.Size(61, 22);
            this.textBoxHeightOB.TabIndex = 3;
            this.textBoxHeightOB.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // textBoxWidthOB
            // 
            this.textBoxWidthOB.Location = new System.Drawing.Point(76, 44);
            this.textBoxWidthOB.Margin = new System.Windows.Forms.Padding(4);
            this.textBoxWidthOB.Name = "textBoxWidthOB";
            this.textBoxWidthOB.ReadOnly = true;
            this.textBoxWidthOB.Size = new System.Drawing.Size(61, 22);
            this.textBoxWidthOB.TabIndex = 2;
            this.textBoxWidthOB.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(13, 87);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(61, 17);
            this.label2.TabIndex = 1;
            this.label2.Text = "Height : ";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(17, 44);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(56, 17);
            this.label1.TabIndex = 0;
            this.label1.Text = "Width : ";
            // 
            // panel3
            // 
            this.panel3.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel3.Controls.Add(this.listViewOB);
            this.panel3.Controls.Add(this.groupBox1);
            this.panel3.Location = new System.Drawing.Point(1349, 5);
            this.panel3.Margin = new System.Windows.Forms.Padding(4);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(249, 740);
            this.panel3.TabIndex = 6;
            // 
            // listViewOB
            // 
            this.listViewOB.HideSelection = false;
            this.listViewOB.Location = new System.Drawing.Point(4, 4);
            this.listViewOB.Margin = new System.Windows.Forms.Padding(4);
            this.listViewOB.Name = "listViewOB";
            this.listViewOB.Size = new System.Drawing.Size(235, 564);
            this.listViewOB.TabIndex = 1;
            this.listViewOB.UseCompatibleStateImageBehavior = false;
            this.listViewOB.MouseClick += new System.Windows.Forms.MouseEventHandler(this.listViewOB_MouseClick);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.textBoxBGWidth);
            this.groupBox2.Controls.Add(this.textBoxBGHeigth);
            this.groupBox2.Location = new System.Drawing.Point(16, 714);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox2.Size = new System.Drawing.Size(452, 59);
            this.groupBox2.TabIndex = 10;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Background Size: ";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(259, 32);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(61, 17);
            this.label4.TabIndex = 10;
            this.label4.Text = "Height : ";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(27, 32);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(52, 17);
            this.label3.TabIndex = 9;
            this.label3.Text = "Width :";
            // 
            // textBoxBGWidth
            // 
            this.textBoxBGWidth.Location = new System.Drawing.Point(89, 28);
            this.textBoxBGWidth.Margin = new System.Windows.Forms.Padding(4);
            this.textBoxBGWidth.Name = "textBoxBGWidth";
            this.textBoxBGWidth.ReadOnly = true;
            this.textBoxBGWidth.Size = new System.Drawing.Size(116, 22);
            this.textBoxBGWidth.TabIndex = 7;
            this.textBoxBGWidth.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // textBoxBGHeigth
            // 
            this.textBoxBGHeigth.Location = new System.Drawing.Point(329, 28);
            this.textBoxBGHeigth.Margin = new System.Windows.Forms.Padding(4);
            this.textBoxBGHeigth.Name = "textBoxBGHeigth";
            this.textBoxBGHeigth.ReadOnly = true;
            this.textBoxBGHeigth.Size = new System.Drawing.Size(116, 22);
            this.textBoxBGHeigth.TabIndex = 8;
            this.textBoxBGHeigth.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.textBoxX);
            this.groupBox3.Controls.Add(this.textBoxY);
            this.groupBox3.Controls.Add(this.label6);
            this.groupBox3.Controls.Add(this.label5);
            this.groupBox3.Location = new System.Drawing.Point(778, 4);
            this.groupBox3.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox3.Size = new System.Drawing.Size(420, 59);
            this.groupBox3.TabIndex = 11;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Position : ";
            // 
            // textBoxX
            // 
            this.textBoxX.Location = new System.Drawing.Point(77, 28);
            this.textBoxX.Margin = new System.Windows.Forms.Padding(4);
            this.textBoxX.Name = "textBoxX";
            this.textBoxX.ReadOnly = true;
            this.textBoxX.Size = new System.Drawing.Size(116, 22);
            this.textBoxX.TabIndex = 3;
            this.textBoxX.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // textBoxY
            // 
            this.textBoxY.Location = new System.Drawing.Point(293, 28);
            this.textBoxY.Margin = new System.Windows.Forms.Padding(4);
            this.textBoxY.Name = "textBoxY";
            this.textBoxY.ReadOnly = true;
            this.textBoxY.Size = new System.Drawing.Size(116, 22);
            this.textBoxY.TabIndex = 2;
            this.textBoxY.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(251, 32);
            this.label6.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(33, 17);
            this.label6.TabIndex = 1;
            this.label6.Text = "Y = ";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(35, 32);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(33, 17);
            this.label5.TabIndex = 0;
            this.label5.Text = "X = ";
            // 
            // imageListOB
            // 
            this.imageListOB.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageListOB.ImageStream")));
            this.imageListOB.TransparentColor = System.Drawing.Color.Transparent;
            this.imageListOB.Images.SetKeyName(0, "Apple.png");
            this.imageListOB.Images.SetKeyName(1, "Ruby.png");
            this.imageListOB.Images.SetKeyName(2, "GenieFace.png");
            this.imageListOB.Images.SetKeyName(3, "GenieJar.png");
            this.imageListOB.Images.SetKeyName(4, "Bat.png");
            this.imageListOB.Images.SetKeyName(5, "NormalGuard.png");
            this.imageListOB.Images.SetKeyName(6, "ThinGuard.png");
            this.imageListOB.Images.SetKeyName(7, "FatGuard.png");
            this.imageListOB.Images.SetKeyName(8, "BoomSkeleton.png");
            this.imageListOB.Images.SetKeyName(9, "Peddler.png");
            this.imageListOB.Images.SetKeyName(10, "StoneBrick.png");
            this.imageListOB.Images.SetKeyName(11, "SharpTrap.png");
            this.imageListOB.Images.SetKeyName(12, "BallTrap.png");
            this.imageListOB.Images.SetKeyName(13, "Chains.png");
            this.imageListOB.Images.SetKeyName(14, "Fence.png");
            this.imageListOB.Images.SetKeyName(15, "StoneBar.png");
            this.imageListOB.Images.SetKeyName(16, "Wood.png");
            this.imageListOB.Images.SetKeyName(17, "Ground.png");
            // 
            // buttonSave
            // 
            this.buttonSave.Location = new System.Drawing.Point(413, 10);
            this.buttonSave.Margin = new System.Windows.Forms.Padding(4);
            this.buttonSave.Name = "buttonSave";
            this.buttonSave.Size = new System.Drawing.Size(100, 28);
            this.buttonSave.TabIndex = 12;
            this.buttonSave.Text = "Save File";
            this.buttonSave.UseVisualStyleBackColor = true;
            this.buttonSave.Click += new System.EventHandler(this.buttonSave_Click);
            // 
            // saveFileDialog1
            // 
            this.saveFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler(this.saveFileDialog1_FileOk);
            // 
            // cancelPic
            // 
            this.cancelPic.Image = ((System.Drawing.Image)(resources.GetObject("cancelPic.Image")));
            this.cancelPic.Location = new System.Drawing.Point(1240, 4);
            this.cancelPic.Margin = new System.Windows.Forms.Padding(4);
            this.cancelPic.Name = "cancelPic";
            this.cancelPic.Size = new System.Drawing.Size(39, 38);
            this.cancelPic.TabIndex = 14;
            this.cancelPic.TabStop = false;
            this.cancelPic.Click += new System.EventHandler(this.cancelPic_Click);
            // 
            // removePic
            // 
            this.removePic.Image = ((System.Drawing.Image)(resources.GetObject("removePic.Image")));
            this.removePic.Location = new System.Drawing.Point(1287, 5);
            this.removePic.Margin = new System.Windows.Forms.Padding(4);
            this.removePic.Name = "removePic";
            this.removePic.Size = new System.Drawing.Size(43, 41);
            this.removePic.TabIndex = 15;
            this.removePic.TabStop = false;
            this.removePic.Click += new System.EventHandler(this.removePic_Click);
            // 
            // buttonSaveImg
            // 
            this.buttonSaveImg.Location = new System.Drawing.Point(296, 10);
            this.buttonSaveImg.Margin = new System.Windows.Forms.Padding(4);
            this.buttonSaveImg.Name = "buttonSaveImg";
            this.buttonSaveImg.Size = new System.Drawing.Size(100, 28);
            this.buttonSaveImg.TabIndex = 16;
            this.buttonSaveImg.Text = "Save Image";
            this.buttonSaveImg.UseVisualStyleBackColor = true;
            this.buttonSaveImg.Click += new System.EventHandler(this.buttonSaveImg_Click);
            // 
            // saveImgFileDialog
            // 
            this.saveImgFileDialog.FileOk += new System.ComponentModel.CancelEventHandler(this.saveImgFileDialog_FileOk);
            // 
            // btnLoadObject
            // 
            this.btnLoadObject.Location = new System.Drawing.Point(175, 10);
            this.btnLoadObject.Name = "btnLoadObject";
            this.btnLoadObject.Size = new System.Drawing.Size(114, 27);
            this.btnLoadObject.TabIndex = 17;
            this.btnLoadObject.Text = "Load object";
            this.btnLoadObject.UseVisualStyleBackColor = true;
            this.btnLoadObject.Click += new System.EventHandler(this.btnLoadObject_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.btnChangeCellSize);
            this.groupBox4.Controls.Add(this.tbCellSize);
            this.groupBox4.Location = new System.Drawing.Point(520, 10);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(233, 53);
            this.groupBox4.TabIndex = 18;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Cell Size";
            // 
            // btnChangeCellSize
            // 
            this.btnChangeCellSize.Location = new System.Drawing.Point(141, 20);
            this.btnChangeCellSize.Name = "btnChangeCellSize";
            this.btnChangeCellSize.Size = new System.Drawing.Size(75, 27);
            this.btnChangeCellSize.TabIndex = 5;
            this.btnChangeCellSize.Text = "change";
            this.btnChangeCellSize.UseVisualStyleBackColor = true;
            this.btnChangeCellSize.Click += new System.EventHandler(this.btnChangeCellSize_Click);
            // 
            // tbCellSize
            // 
            this.tbCellSize.Location = new System.Drawing.Point(7, 22);
            this.tbCellSize.Margin = new System.Windows.Forms.Padding(4);
            this.tbCellSize.Name = "tbCellSize";
            this.tbCellSize.Size = new System.Drawing.Size(116, 22);
            this.tbCellSize.TabIndex = 4;
            this.tbCellSize.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // MapEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(1601, 784);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.btnLoadObject);
            this.Controls.Add(this.buttonSaveImg);
            this.Controls.Add(this.removePic);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.cancelPic);
            this.Controls.Add(this.buttonSave);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.buttonLoad);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "MapEditor";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Map Editor";
            this.panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxBG)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cancelPic)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.removePic)).EndInit();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Button buttonLoad;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.PictureBox pictureBoxBG;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox textBoxHeightOB;
        private System.Windows.Forms.TextBox textBoxWidthOB;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBoxBGWidth;
        private System.Windows.Forms.TextBox textBoxBGHeigth;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox textBoxX;
        private System.Windows.Forms.TextBox textBoxY;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ImageList imageListOB;
        private System.Windows.Forms.TextBox textBoxNameOB;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button buttonSave;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.ListView listViewOB;
        private System.Windows.Forms.PictureBox cancelPic;
        private System.Windows.Forms.PictureBox removePic;
        private System.Windows.Forms.Button buttonSaveImg;
        private System.Windows.Forms.SaveFileDialog saveImgFileDialog;
        private System.Windows.Forms.Button btnLoadObject;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Button btnChangeCellSize;
        private System.Windows.Forms.TextBox tbCellSize;
    }
}

