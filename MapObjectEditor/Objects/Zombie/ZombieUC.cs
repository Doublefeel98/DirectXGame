using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.Zombie
{
    public partial class ZombieUC : UserControl
    {
        private Zombie zombie;
        public ZombieUC(Obj obj)
        {
            InitializeComponent();
            zombie = (Zombie)obj;
            cboDirection.SelectedIndex = zombie.Direction == 1 ? 1 : 0;
        }

        private void cboDirection_SelectedIndexChanged(object sender, EventArgs e)
        {
            zombie.Direction = (int)cboDirection.SelectedIndex == 1 ? 1 : -1;
        }
    }
}
