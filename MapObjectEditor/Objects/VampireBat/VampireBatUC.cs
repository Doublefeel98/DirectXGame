using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.VampireBat
{
    public partial class VampireBatUC : UserControl
    {
        private VampireBat vampireBat;
        public VampireBatUC(Obj obj)
        {
            InitializeComponent();
            this.vampireBat = (VampireBat)obj;
            numDistranceX.Value = this.vampireBat.DistanceX;
        }

        private void numDistranceX_ValueChanged(object sender, EventArgs e)
        {
            vampireBat.DistanceX = (int)numDistranceX.Value;
        }

        private void numDistranceX_KeyUp(object sender, KeyEventArgs e)
        {
            vampireBat.DistanceX = (int)numDistranceX.Value;
        }
    }
}
