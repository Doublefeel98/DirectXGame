namespace MapEditor.Objects.Portal
{
    partial class PortalUC
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
            this.numPosition = new System.Windows.Forms.NumericUpDown();
            this.label18 = new System.Windows.Forms.Label();
            this.numSceneId = new System.Windows.Forms.NumericUpDown();
            this.label13 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.numPosition)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numSceneId)).BeginInit();
            this.SuspendLayout();
            // 
            // numPosition
            // 
            this.numPosition.Location = new System.Drawing.Point(211, 24);
            this.numPosition.Margin = new System.Windows.Forms.Padding(2);
            this.numPosition.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.numPosition.Name = "numPosition";
            this.numPosition.Size = new System.Drawing.Size(41, 20);
            this.numPosition.TabIndex = 37;
            this.numPosition.ValueChanged += new System.EventHandler(this.numPosition_ValueChanged);
            this.numPosition.KeyUp += new System.Windows.Forms.KeyEventHandler(this.numPosition_KeyUp);
            // 
            // label18
            // 
            this.label18.Location = new System.Drawing.Point(155, 28);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(51, 13);
            this.label18.TabIndex = 34;
            this.label18.Text = "Position";
            // 
            // numSceneId
            // 
            this.numSceneId.Location = new System.Drawing.Point(89, 24);
            this.numSceneId.Margin = new System.Windows.Forms.Padding(2);
            this.numSceneId.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.numSceneId.Name = "numSceneId";
            this.numSceneId.Size = new System.Drawing.Size(41, 20);
            this.numSceneId.TabIndex = 36;
            this.numSceneId.ValueChanged += new System.EventHandler(this.numSceneId_ValueChanged);
            this.numSceneId.KeyUp += new System.Windows.Forms.KeyEventHandler(this.numSceneId_KeyUp);
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(38, 28);
            this.label13.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(47, 13);
            this.label13.TabIndex = 35;
            this.label13.Text = "SceneId";
            // 
            // PortalUC
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.numPosition);
            this.Controls.Add(this.label18);
            this.Controls.Add(this.numSceneId);
            this.Controls.Add(this.label13);
            this.Name = "PortalUC";
            this.Size = new System.Drawing.Size(1180, 80);
            ((System.ComponentModel.ISupportInitialize)(this.numPosition)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numSceneId)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.NumericUpDown numPosition;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.NumericUpDown numSceneId;
        private System.Windows.Forms.Label label13;
    }
}
