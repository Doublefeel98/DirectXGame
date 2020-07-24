using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor.Objects.Portal
{
    public partial class PortalUC : UserControl
    {
        private Portal portal;
        public PortalUC(Obj obj)
        {
            InitializeComponent();
            this.portal = (Portal)obj;
            numPosition.Value = this.portal.Position;
            numSceneId.Value = this.portal.SceneId;
        }

        private void numPosition_ValueChanged(object sender, EventArgs e)
        {
            portal.Position = (int)numPosition.Value;
        }

        private void numPosition_KeyUp(object sender, KeyEventArgs e)
        {
            portal.Position = (int)numPosition.Value;
        }

        private void numSceneId_ValueChanged(object sender, EventArgs e)
        {
            portal.SceneId = (int)numSceneId.Value;
        }

        private void numSceneId_KeyUp(object sender, KeyEventArgs e)
        {
            portal.SceneId = (int)numSceneId.Value;
        }
    }
}
