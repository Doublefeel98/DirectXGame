using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapTool
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Lưu ý: Chỉnh kích thước (Tile Width , Tile Height) trước khi sử dụng");
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            TileMap tm = new TileMap();
            tm.ShowDialog();
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            LoadMap tm = new LoadMap();
            tm.ShowDialog();
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            MapEditor tm = new MapEditor();
            tm.ShowDialog();
        }
    }
}
