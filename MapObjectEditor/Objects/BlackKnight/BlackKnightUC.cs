using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.BlackKnight
{
    public partial class BlackKnightUC : UserControl
    {
        private BlackKnight blackKnight;
        public BlackKnightUC(Obj obj)
        {
            InitializeComponent();
            this.blackKnight = (BlackKnight)obj;
            numDistranceX.Value = this.blackKnight.DistanceX;
        }

        private void numDistranceX_ValueChanged(object sender, EventArgs e)
        {
            blackKnight.DistanceX = (int)numDistranceX.Value;
        }

        private void numDistranceX_KeyUp(object sender, KeyEventArgs e)
        {
            blackKnight.DistanceX = (int)numDistranceX.Value;
        }
    }
}
