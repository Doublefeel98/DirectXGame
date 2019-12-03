namespace MapEditor
{
    partial class Background
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxChuaLoc = new System.Windows.Forms.TextBox();
            this.textBoxDaLoc = new System.Windows.Forms.TextBox();
            this.buttonSlipt = new System.Windows.Forms.Button();
            this.buttonOpen = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.pictureBoxBG = new System.Windows.Forms.PictureBox();
            this.textBoxBGWidth = new System.Windows.Forms.TextBox();
            this.textBoxBGHeigth = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.pictureBoxAfter = new System.Windows.Forms.PictureBox();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.buttonSave = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxBG)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxAfter)).BeginInit();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(112, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Tổng số tile chưa lọc: ";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(16, 62);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(101, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Tổng số tile đã lọc: ";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // textBoxChuaLoc
            // 
            this.textBoxChuaLoc.Location = new System.Drawing.Point(120, 29);
            this.textBoxChuaLoc.Name = "textBoxChuaLoc";
            this.textBoxChuaLoc.ReadOnly = true;
            this.textBoxChuaLoc.Size = new System.Drawing.Size(144, 20);
            this.textBoxChuaLoc.TabIndex = 2;
            this.textBoxChuaLoc.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.textBoxChuaLoc.TextChanged += new System.EventHandler(this.textBoxChuaLoc_TextChanged);
            // 
            // textBoxDaLoc
            // 
            this.textBoxDaLoc.Location = new System.Drawing.Point(120, 62);
            this.textBoxDaLoc.Name = "textBoxDaLoc";
            this.textBoxDaLoc.ReadOnly = true;
            this.textBoxDaLoc.Size = new System.Drawing.Size(143, 20);
            this.textBoxDaLoc.TabIndex = 3;
            this.textBoxDaLoc.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.textBoxDaLoc.TextChanged += new System.EventHandler(this.textBoxDaLoc_TextChanged);
            // 
            // buttonSlipt
            // 
            this.buttonSlipt.Location = new System.Drawing.Point(57, 353);
            this.buttonSlipt.Name = "buttonSlipt";
            this.buttonSlipt.Size = new System.Drawing.Size(98, 20);
            this.buttonSlipt.TabIndex = 4;
            this.buttonSlipt.Text = "Slipt";
            this.buttonSlipt.UseVisualStyleBackColor = true;
            this.buttonSlipt.Click += new System.EventHandler(this.buttonSlipt_Click);
            // 
            // buttonOpen
            // 
            this.buttonOpen.Location = new System.Drawing.Point(57, 316);
            this.buttonOpen.Name = "buttonOpen";
            this.buttonOpen.Size = new System.Drawing.Size(98, 23);
            this.buttonOpen.TabIndex = 5;
            this.buttonOpen.Text = "Open";
            this.buttonOpen.UseVisualStyleBackColor = true;
            this.buttonOpen.Click += new System.EventHandler(this.buttonOpen_Click);
            // 
            // panel1
            // 
            this.panel1.AutoScroll = true;
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.pictureBoxBG);
            this.panel1.Location = new System.Drawing.Point(57, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(873, 274);
            this.panel1.TabIndex = 6;
            this.panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.panel1_Paint);
            // 
            // pictureBoxBG
            // 
            this.pictureBoxBG.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureBoxBG.Location = new System.Drawing.Point(0, 0);
            this.pictureBoxBG.Name = "pictureBoxBG";
            this.pictureBoxBG.Size = new System.Drawing.Size(871, 272);
            this.pictureBoxBG.TabIndex = 0;
            this.pictureBoxBG.TabStop = false;
            this.pictureBoxBG.Click += new System.EventHandler(this.pictureBoxBG_Click);
            // 
            // textBoxBGWidth
            // 
            this.textBoxBGWidth.Location = new System.Drawing.Point(65, 19);
            this.textBoxBGWidth.Name = "textBoxBGWidth";
            this.textBoxBGWidth.ReadOnly = true;
            this.textBoxBGWidth.Size = new System.Drawing.Size(192, 20);
            this.textBoxBGWidth.TabIndex = 7;
            this.textBoxBGWidth.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.textBoxBGWidth.TextChanged += new System.EventHandler(this.textBoxBGWidth_TextChanged);
            // 
            // textBoxBGHeigth
            // 
            this.textBoxBGHeigth.Location = new System.Drawing.Point(65, 66);
            this.textBoxBGHeigth.Name = "textBoxBGHeigth";
            this.textBoxBGHeigth.ReadOnly = true;
            this.textBoxBGHeigth.Size = new System.Drawing.Size(192, 20);
            this.textBoxBGHeigth.TabIndex = 8;
            this.textBoxBGHeigth.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.textBoxBGHeigth.TextChanged += new System.EventHandler(this.textBoxBGHeigth_TextChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.textBoxBGWidth);
            this.groupBox1.Controls.Add(this.textBoxBGHeigth);
            this.groupBox1.Location = new System.Drawing.Point(203, 302);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(292, 100);
            this.groupBox1.TabIndex = 9;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Background Size: ";
            this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(14, 66);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(47, 13);
            this.label4.TabIndex = 10;
            this.label4.Text = "Height : ";
            this.label4.Click += new System.EventHandler(this.label4_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(20, 26);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(41, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "Width :";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Controls.Add(this.textBox3);
            this.groupBox2.Controls.Add(this.textBox4);
            this.groupBox2.Location = new System.Drawing.Point(279, 413);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(216, 100);
            this.groupBox2.TabIndex = 10;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Tile Size: ";
            this.groupBox2.Enter += new System.EventHandler(this.groupBox2_Enter);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(14, 66);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(47, 13);
            this.label5.TabIndex = 10;
            this.label5.Text = "Height : ";
            this.label5.Click += new System.EventHandler(this.label5_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(20, 26);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(41, 13);
            this.label6.TabIndex = 9;
            this.label6.Text = "Width :";
            this.label6.Click += new System.EventHandler(this.label6_Click);
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(65, 19);
            this.textBox3.Name = "textBox3";
            this.textBox3.ReadOnly = true;
            this.textBox3.Size = new System.Drawing.Size(116, 20);
            this.textBox3.TabIndex = 7;
            this.textBox3.Text = "16 pixel";
            this.textBox3.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.textBox3.TextChanged += new System.EventHandler(this.textBox3_TextChanged);
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(65, 66);
            this.textBox4.Name = "textBox4";
            this.textBox4.ReadOnly = true;
            this.textBox4.Size = new System.Drawing.Size(116, 20);
            this.textBox4.TabIndex = 8;
            this.textBox4.Text = "16 pixel";
            this.textBox4.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.textBox4.TextChanged += new System.EventHandler(this.textBox4_TextChanged);
            // 
            // panel2
            // 
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel2.Controls.Add(this.pictureBoxAfter);
            this.panel2.Location = new System.Drawing.Point(507, 302);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(423, 226);
            this.panel2.TabIndex = 11;
            this.panel2.Paint += new System.Windows.Forms.PaintEventHandler(this.panel2_Paint);
            // 
            // pictureBoxAfter
            // 
            this.pictureBoxAfter.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureBoxAfter.Location = new System.Drawing.Point(0, 0);
            this.pictureBoxAfter.Name = "pictureBoxAfter";
            this.pictureBoxAfter.Size = new System.Drawing.Size(421, 224);
            this.pictureBoxAfter.TabIndex = 0;
            this.pictureBoxAfter.TabStop = false;
            this.pictureBoxAfter.Click += new System.EventHandler(this.pictureBoxAfter_Click);
            // 
            // saveFileDialog1
            // 
            this.saveFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler(this.saveFileDialog1_FileOk);
            // 
            // buttonSave
            // 
            this.buttonSave.Location = new System.Drawing.Point(64, 519);
            this.buttonSave.Name = "buttonSave";
            this.buttonSave.Size = new System.Drawing.Size(91, 23);
            this.buttonSave.TabIndex = 12;
            this.buttonSave.Text = "Save";
            this.buttonSave.UseVisualStyleBackColor = true;
            this.buttonSave.Click += new System.EventHandler(this.buttonSave_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.label1);
            this.groupBox3.Controls.Add(this.textBoxChuaLoc);
            this.groupBox3.Controls.Add(this.textBoxDaLoc);
            this.groupBox3.Controls.Add(this.label2);
            this.groupBox3.Location = new System.Drawing.Point(4, 413);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(285, 100);
            this.groupBox3.TabIndex = 13;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Slipt details :";
            this.groupBox3.Enter += new System.EventHandler(this.groupBox3_Enter);
            // 
            // Background
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(962, 561);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.buttonSave);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.buttonOpen);
            this.Controls.Add(this.buttonSlipt);
            this.MaximumSize = new System.Drawing.Size(978, 600);
            this.MinimumSize = new System.Drawing.Size(978, 600);
            this.Name = "Background";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Background";
            this.panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxBG)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxAfter)).EndInit();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxChuaLoc;
        private System.Windows.Forms.TextBox textBoxDaLoc;
        private System.Windows.Forms.Button buttonSlipt;
        private System.Windows.Forms.Button buttonOpen;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.PictureBox pictureBoxBG;
        private System.Windows.Forms.TextBox textBoxBGWidth;
        private System.Windows.Forms.TextBox textBoxBGHeigth;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.PictureBox pictureBoxAfter;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.Button buttonSave;
        private System.Windows.Forms.GroupBox groupBox3;
    }
}