using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.TopStair
{
    public partial class TopStairUC : UserControl
    {
        private TopStair topStair;
        public TopStairUC(Obj obj)
        {
            InitializeComponent();
            this.topStair = (TopStair)obj;
            cboDirection.SelectedIndex = topStair.Direction == 1 ? 1 : 0;
        }

        private void cboDirection_SelectedIndexChanged(object sender, EventArgs e)
        {
            topStair.Direction = (int)cboDirection.SelectedIndex == 1 ? 1 : -1;
        }
    }
}
