namespace MapEditor.Objects.TransparentObject
{
    partial class TransparentObjectUC
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.numItemX = new System.Windows.Forms.NumericUpDown();
            this.numItemY = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.chkIsGrowUp = new System.Windows.Forms.CheckBox();
            ((System.ComponentModel.ISupportInitialize)(this.numItemX)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numItemY)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(44, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(79, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Item position X:";
            // 
            // numItemX
            // 
            this.numItemX.Location = new System.Drawing.Point(129, 30);
            this.numItemX.Maximum = new decimal(new int[] {
            276447232,
            23283,
            0,
            0});
            this.numItemX.Name = "numItemX";
            this.numItemX.Size = new System.Drawing.Size(120, 20);
            this.numItemX.TabIndex = 1;
            this.numItemX.ValueChanged += new System.EventHandler(this.numItemX_ValueChanged);
            this.numItemX.KeyUp += new System.Windows.Forms.KeyEventHandler(this.numItemX_KeyUp);
            // 
            // numItemY
            // 
            this.numItemY.Location = new System.Drawing.Point(358, 30);
            this.numItemY.Maximum = new decimal(new int[] {
            -1530494976,
            232830,
            0,
            0});
            this.numItemY.Name = "numItemY";
            this.numItemY.Size = new System.Drawing.Size(120, 20);
            this.numItemY.TabIndex = 3;
            this.numItemY.ValueChanged += new System.EventHandler(this.numItemY_ValueChanged);
            this.numItemY.KeyUp += new System.Windows.Forms.KeyEventHandler(this.numItemY_KeyUp);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(273, 32);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(79, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Item position Y:";
            // 
            // chkIsGrowUp
            // 
            this.chkIsGrowUp.AutoSize = true;
            this.chkIsGrowUp.Location = new System.Drawing.Point(545, 32);
            this.chkIsGrowUp.Name = "chkIsGrowUp";
            this.chkIsGrowUp.Size = new System.Drawing.Size(79, 17);
            this.chkIsGrowUp.TabIndex = 5;
            this.chkIsGrowUp.Text = "Is Grow Up";
            this.chkIsGrowUp.UseVisualStyleBackColor = true;
            this.chkIsGrowUp.CheckedChanged += new System.EventHandler(this.chkIsGrowUp_CheckedChanged);
            // 
            // TransparentObjectUC
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.chkIsGrowUp);
            this.Controls.Add(this.numItemY);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.numItemX);
            this.Controls.Add(this.label1);
            this.Name = "TransparentObjectUC";
            this.Size = new System.Drawing.Size(1180, 80);
            ((System.ComponentModel.ISupportInitialize)(this.numItemX)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numItemY)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown numItemX;
        private System.Windows.Forms.NumericUpDown numItemY;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.CheckBox chkIsGrowUp;
    }
}
