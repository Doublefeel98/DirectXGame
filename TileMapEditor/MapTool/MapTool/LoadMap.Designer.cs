namespace MapTool
{
    partial class LoadMap
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(LoadMap));
            this.label4 = new System.Windows.Forms.Label();
            this.btnLoadMapFromTile = new System.Windows.Forms.Button();
            this.btnReadFile = new System.Windows.Forms.Button();
            this.panel2 = new System.Windows.Forms.Panel();
            this.picTileList = new System.Windows.Forms.PictureBox();
            this.btnGetTileMap = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.txtTileHeight = new System.Windows.Forms.TextBox();
            this.txtTileWidth = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.picMap = new System.Windows.Forms.PictureBox();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripButton1 = new System.Windows.Forms.ToolStripButton();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.openFolder = new System.Windows.Forms.FolderBrowserDialog();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picTileList)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picMap)).BeginInit();
            this.toolStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // label4
            // 
            this.label4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(2, 505);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(100, 13);
            this.label4.TabIndex = 52;
            this.label4.Text = "Load Map From File";
            // 
            // btnLoadMapFromTile
            // 
            this.btnLoadMapFromTile.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnLoadMapFromTile.Enabled = false;
            this.btnLoadMapFromTile.Location = new System.Drawing.Point(169, 534);
            this.btnLoadMapFromTile.Name = "btnLoadMapFromTile";
            this.btnLoadMapFromTile.Size = new System.Drawing.Size(75, 23);
            this.btnLoadMapFromTile.TabIndex = 51;
            this.btnLoadMapFromTile.Text = "Load Map";
            this.btnLoadMapFromTile.UseVisualStyleBackColor = true;
            this.btnLoadMapFromTile.Click += new System.EventHandler(this.btnLoadMapFromTile_Click);
            // 
            // btnReadFile
            // 
            this.btnReadFile.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnReadFile.Location = new System.Drawing.Point(88, 533);
            this.btnReadFile.Name = "btnReadFile";
            this.btnReadFile.Size = new System.Drawing.Size(75, 23);
            this.btnReadFile.TabIndex = 50;
            this.btnReadFile.Text = "MaTrix Map";
            this.btnReadFile.UseVisualStyleBackColor = true;
            this.btnReadFile.Click += new System.EventHandler(this.btnReadFile_Click);
            // 
            // panel2
            // 
            this.panel2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel2.AutoScroll = true;
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel2.Controls.Add(this.picTileList);
            this.panel2.Location = new System.Drawing.Point(3, 563);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(826, 60);
            this.panel2.TabIndex = 48;
            // 
            // picTileList
            // 
            this.picTileList.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.picTileList.Location = new System.Drawing.Point(0, 3);
            this.picTileList.Name = "picTileList";
            this.picTileList.Size = new System.Drawing.Size(100, 40);
            this.picTileList.TabIndex = 0;
            this.picTileList.TabStop = false;
            // 
            // btnGetTileMap
            // 
            this.btnGetTileMap.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnGetTileMap.Location = new System.Drawing.Point(2, 533);
            this.btnGetTileMap.Name = "btnGetTileMap";
            this.btnGetTileMap.Size = new System.Drawing.Size(80, 23);
            this.btnGetTileMap.TabIndex = 49;
            this.btnGetTileMap.Text = "Tile Map";
            this.btnGetTileMap.UseVisualStyleBackColor = true;
            this.btnGetTileMap.Click += new System.EventHandler(this.btnGetTileMap_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(217, 34);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(58, 13);
            this.label2.TabIndex = 41;
            this.label2.Text = "Tile Height";
            // 
            // txtTileHeight
            // 
            this.txtTileHeight.Location = new System.Drawing.Point(281, 27);
            this.txtTileHeight.Name = "txtTileHeight";
            this.txtTileHeight.Size = new System.Drawing.Size(100, 20);
            this.txtTileHeight.TabIndex = 40;
            this.txtTileHeight.Text = "16";
            // 
            // txtTileWidth
            // 
            this.txtTileWidth.Location = new System.Drawing.Point(88, 29);
            this.txtTileWidth.Name = "txtTileWidth";
            this.txtTileWidth.Size = new System.Drawing.Size(100, 20);
            this.txtTileWidth.TabIndex = 39;
            this.txtTileWidth.Text = "16";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(2, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(55, 13);
            this.label1.TabIndex = 38;
            this.label1.Text = "Tile Width";
            // 
            // panel1
            // 
            this.panel1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel1.AutoScroll = true;
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel1.Controls.Add(this.picMap);
            this.panel1.Location = new System.Drawing.Point(3, 68);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(829, 434);
            this.panel1.TabIndex = 36;
            // 
            // picMap
            // 
            this.picMap.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.picMap.Location = new System.Drawing.Point(0, 0);
            this.picMap.Name = "picMap";
            this.picMap.Size = new System.Drawing.Size(100, 50);
            this.picMap.TabIndex = 0;
            this.picMap.TabStop = false;
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripButton1});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(836, 25);
            this.toolStrip1.TabIndex = 53;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // toolStripButton1
            // 
            this.toolStripButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton1.Image")));
            this.toolStripButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton1.Name = "toolStripButton1";
            this.toolStripButton1.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton1.Text = "Save Image";
            this.toolStripButton1.Click += new System.EventHandler(this.toolStripButton1_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // LoadMap
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(836, 630);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.btnLoadMapFromTile);
            this.Controls.Add(this.btnReadFile);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.btnGetTileMap);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtTileHeight);
            this.Controls.Add(this.txtTileWidth);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.panel1);
            this.Name = "LoadMap";
            this.Text = "LoadMap";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Load += new System.EventHandler(this.LoadMap_Load);
            this.panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.picTileList)).EndInit();
            this.panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.picMap)).EndInit();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btnLoadMapFromTile;
        private System.Windows.Forms.Button btnReadFile;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.PictureBox picTileList;
        private System.Windows.Forms.Button btnGetTileMap;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtTileHeight;
        private System.Windows.Forms.TextBox txtTileWidth;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.PictureBox picMap;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton toolStripButton1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.FolderBrowserDialog openFolder;
    }
}