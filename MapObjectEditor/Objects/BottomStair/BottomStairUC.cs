using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.BottomStair
{
    public partial class BottomStairUC : UserControl
    {
        private BottomStair bottomStair;
        public BottomStairUC(Obj obj)
        {
            InitializeComponent();
            bottomStair = (BottomStair)obj;
            cboDirection.SelectedIndex = bottomStair.Direction == 1 ? 1 : 0;
            //cboDirection.SelectedItem = cboDirection.Items[cboDirection.SelectedIndex];
        }

        private void cboDirection_SelectedIndexChanged(object sender, EventArgs e)
        {
            bottomStair.Direction = (int)cboDirection.SelectedIndex == 0 ? -1 : 1;
        }
    }
}
