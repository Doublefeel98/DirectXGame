namespace MapEditor.Objects.Simon
{
    partial class SimonUC
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
            this.cboDirection = new System.Windows.Forms.ComboBox();
            this.cboState = new System.Windows.Forms.ComboBox();
            this.label17 = new System.Windows.Forms.Label();
            this.label16 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // cboDirection
            // 
            this.cboDirection.FormattingEnabled = true;
            this.cboDirection.Items.AddRange(new object[] {
            "Left",
            "Right"});
            this.cboDirection.Location = new System.Drawing.Point(109, 23);
            this.cboDirection.Name = "cboDirection";
            this.cboDirection.Size = new System.Drawing.Size(134, 21);
            this.cboDirection.TabIndex = 38;
            this.cboDirection.SelectedIndexChanged += new System.EventHandler(this.cboDirection_SelectedIndexChanged);
            // 
            // cboState
            // 
            this.cboState.FormattingEnabled = true;
            this.cboState.Items.AddRange(new object[] {
            "SIMON_STATE_IDLE",
            "SIMON_STATE_CLIMB_UP_STAIR",
            "SIMON_STATE_CLIMB_DOWN_STAIR"});
            this.cboState.Location = new System.Drawing.Point(313, 23);
            this.cboState.Name = "cboState";
            this.cboState.Size = new System.Drawing.Size(220, 21);
            this.cboState.TabIndex = 37;
            this.cboState.SelectedIndexChanged += new System.EventHandler(this.cboState_SelectedIndexChanged);
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(256, 26);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(35, 13);
            this.label17.TabIndex = 36;
            this.label17.Text = "State:";
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(51, 26);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(52, 13);
            this.label16.TabIndex = 35;
            this.label16.Text = "Direction:";
            // 
            // SimonUC
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.cboDirection);
            this.Controls.Add(this.cboState);
            this.Controls.Add(this.label17);
            this.Controls.Add(this.label16);
            this.Name = "SimonUC";
            this.Size = new System.Drawing.Size(1180, 80);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox cboDirection;
        private System.Windows.Forms.ComboBox cboState;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.Label label16;
    }
}
