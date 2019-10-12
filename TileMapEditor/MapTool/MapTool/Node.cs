using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapTool
{
    public class Node
    {
        public int iD;
        public string strID;
        public Rectangle rectNode;
        public List<ObjectInFile> objInNodeList = new List<ObjectInFile>();
        public Node nodeTL; 
        public Node nodeTR; 
        public Node nodeBL; 
        public Node nodeBR; 
        public Node(int id, Rectangle rect)
        {
            iD = id;
            rectNode = rect;
        }


        public static Node rootNode;

        public Node(string strid,Rectangle rect,List<ObjectInFile> list)
        {
            this.strID = strid;
            rectNode = rect;

            foreach (ObjectInFile obj in list)
            {
                if(rectNode.IntersectsWith(obj.Rect))
                {
                    objInNodeList.Add(obj);
                }
            }

            if(objInNodeList.Count==0)
            {
                return;
            }

            if(rect.Width>400)
            {
                Rectangle rTl, rTr, rBl, rBr;
                rTl = new Rectangle(rectNode.X, rectNode.Y, rectNode.Width / 2, rectNode.Height / 2);
                rTr = new Rectangle(rectNode.X + rectNode.Width / 2, rectNode.Y, rectNode.Width / 2, rectNode.Height / 2);
                rBl = new Rectangle(rectNode.X, rectNode.Y + rectNode.Height / 2, rectNode.Width / 2, rectNode.Height / 2);
                rBr = new Rectangle(rectNode.X + rectNode.Width / 2, rectNode.Y + rectNode.Height / 2, rectNode.Width / 2, rectNode.Height / 2);
                nodeTL = new Node(strID + "1", rTl, objInNodeList);
                nodeTR = new Node(strID + "2", rTr, objInNodeList);
                nodeBL = new Node(strID + "3", rBl, objInNodeList);
                nodeBR = new Node(strID + "4", rBr, objInNodeList);
                objInNodeList.Clear();
            }
        }


        public void drawRect(Graphics g)
        {
            g.DrawRectangle(new Pen(Brushes.Red,2),RectNode);

            if(nodeTL!=null)
            {
                nodeTL.drawRect(g);
                nodeTR.drawRect(g);
                nodeBL.drawRect(g);
                nodeBR.drawRect(g);
            }

        }

        public void save(StreamWriter writer)
        {
            writer.Write(strID + "\t"
                + rectNode.X + "\t"
                + rectNode.Y + "\t"
                + rectNode.Width + "\t"
                + rectNode.Height + "\t");

            if(nodeTL!=null)
            {
                writer.Write(4 + "\t0\t");

                writer.WriteLine();

                nodeTL.save(writer);
                nodeTR.save(writer);
                nodeBL.save(writer);
                nodeBR.save(writer);


                return;
            }
            else
            {
                writer.Write(0 + "\t" + ObjInNodeList.Count +"\t");

                foreach(ObjectInFile obj in ObjInNodeList)
                {
                    writer.Write(obj.index + "\t");
                }
            }

            writer.WriteLine();
        }

        public static void saveQuadTree(String path)
        {
            StreamWriter writer = new StreamWriter(path);

            rootNode.save(writer);
            writer.Close();

        }


        public Node()
        {

        }

        public Node(int id, Rectangle rect,List<ObjectInFile> list)
        {
            iD = id;
            rectNode = rect;
            objInNodeList = list;


            

        }
        public List<ObjectInFile> ObjInNodeList
        {
            get { return objInNodeList; }
            set { objInNodeList = value; }
        }
        public Rectangle RectNode
        {
            get { return rectNode; }
            set { rectNode = value; }
        }

        public int ID
        {
            get { return iD; }
            set { iD = value; }
        }
    }
}
