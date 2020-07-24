using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.Simon
{
    public partial class SimonUC : UserControl
    {
        private Simon simon;
        public SimonUC(Simon simon)
        {
            InitializeComponent();
            this.simon = simon;
            cboDirection.SelectedIndex = simon.Direction == 1 ? 1 : 0;
            cboState.SelectedIndex = simon.State;
        }

        private void cboDirection_SelectedIndexChanged(object sender, EventArgs e)
        {
            simon.Direction = (int)cboDirection.SelectedIndex == 0 ? -1 : 1;
        }

        private void cboState_SelectedIndexChanged(object sender, EventArgs e)
        {
            simon.State = (int)cboState.SelectedIndex;
        }
    }
}
