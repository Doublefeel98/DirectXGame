using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor
{
    class Utilities
    {
        // ghi file txt toa do obj trong map
        public static void WriteFileTxTObj(SaveFileDialog saveFile, List<Object> listObj)
        {            
            string path = System.IO.Path.Combine(System.IO.Path.GetDirectoryName(saveFile.FileName),
            System.IO.Path.GetFileNameWithoutExtension(saveFile.FileName)) + "_obj.txt";
            System.IO.StreamWriter sWriter = new System.IO.StreamWriter(path);
            
            for (int i = 0; i < listObj.Count; i++)
            {
                string posX = listObj.ElementAt(i).PosX.ToString();
                string posY = listObj.ElementAt(i).PosY.ToString();
                string id = listObj.ElementAt(i).Id.ToString();
                string w = listObj.ElementAt(i).Width.ToString();
                string h = listObj.ElementAt(i).Height.ToString();
                string index = listObj.ElementAt(i).Index.ToString();
                sWriter.WriteLine(index + " " + id + " " + posX + " " + posY + " " + w + " " + h);
            }

            sWriter.Flush();
            sWriter.Close();
        }

        // ghi file txt cac obj trong tung cell cua grid
        public static void WriteFileTxtGrid(SaveFileDialog saveFile, Grid grid)
        {            
            string path = System.IO.Path.Combine(System.IO.Path.GetDirectoryName(saveFile.FileName),
            System.IO.Path.GetFileNameWithoutExtension(saveFile.FileName)) + "_grid.txt";
            System.IO.StreamWriter sWriter = new System.IO.StreamWriter(path);

            Cell cell;
            for (int i = 0; i < grid.numXCells; i++)
            {
                for (int j = 0; j < grid.numYCells; j++)
                {
                    cell = grid.listCells[i , j];
                    string strObj = "";
                    for (int k = 0; k < cell.listIdObj.Count; k ++)
                    {
                        strObj += " " + cell.listIdObj[k].ToString();
                    }
                    sWriter.WriteLine(i + " " + j + strObj);
                }

            }

            sWriter.Flush();
            sWriter.Close();

        }        

        // resize img
        public static Bitmap ResizeImage(Image image, int rWidth, int rHeight)
        {
            var newImg = new Bitmap(rWidth, rHeight);
            Graphics.FromImage(newImg).DrawImage(image, 0, 0, rWidth, rHeight);            
            Bitmap bmp = new Bitmap(newImg);
            return bmp;
        }
    }
}
