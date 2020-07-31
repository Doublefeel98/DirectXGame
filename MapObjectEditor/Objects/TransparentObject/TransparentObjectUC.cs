using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.TransparentObject
{
    public partial class TransparentObjectUC : UserControl
    {
        private TransparentObject transparentObject;
        public TransparentObjectUC(Obj obj)
        {
            InitializeComponent();
            transparentObject = (TransparentObject)obj;
            numItemX.Value = transparentObject.ItemX;
            numItemY.Value = transparentObject.ItemY;
            chkIsGrowUp.Checked = transparentObject.IsItemGrowUp == 1 ? true : false;
        }

        private void chkIsGrowUp_CheckedChanged(object sender, EventArgs e)
        {
            transparentObject.IsItemGrowUp = chkIsGrowUp.Checked ? 1 : 0;
        }

        private void numItemX_ValueChanged(object sender, EventArgs e)
        {
            transparentObject.ItemX = (int)numItemX.Value;
        }

        private void numItemX_KeyUp(object sender, KeyEventArgs e)
        {
            transparentObject.ItemX = (int)numItemX.Value;
        }

        private void numItemY_ValueChanged(object sender, EventArgs e)
        {
            transparentObject.ItemY = (int)numItemY.Value;
        }

        private void numItemY_KeyUp(object sender, KeyEventArgs e)
        {
            transparentObject.ItemY = (int)numItemY.Value;
        }
    }
}
