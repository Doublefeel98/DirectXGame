﻿namespace MapEditor.Objects.VampireBat
{
    partial class VampireBatUC
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
            this.numDistranceX = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.numDistranceX)).BeginInit();
            this.SuspendLayout();
            // 
            // numDistranceX
            // 
            this.numDistranceX.Location = new System.Drawing.Point(169, 33);
            this.numDistranceX.Margin = new System.Windows.Forms.Padding(2);
            this.numDistranceX.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.numDistranceX.Name = "numDistranceX";
            this.numDistranceX.Size = new System.Drawing.Size(41, 20);
            this.numDistranceX.TabIndex = 39;
            this.numDistranceX.ValueChanged += new System.EventHandler(this.numDistranceX_ValueChanged);
            this.numDistranceX.KeyUp += new System.Windows.Forms.KeyEventHandler(this.numDistranceX_KeyUp);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(68, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(96, 13);
            this.label1.TabIndex = 38;
            this.label1.Text = "Distance X Attack:";
            // 
            // VampireBatUC
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.numDistranceX);
            this.Controls.Add(this.label1);
            this.Name = "VampireBatUC";
            this.Size = new System.Drawing.Size(1180, 80);
            ((System.ComponentModel.ISupportInitialize)(this.numDistranceX)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.NumericUpDown numDistranceX;
        private System.Windows.Forms.Label label1;
    }
}
