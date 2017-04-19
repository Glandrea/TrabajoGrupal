using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Threading;
using System.Net.Sockets;
using System.IO;



namespace ProcedimientosRemotos
{
    
    public partial class Form1 : Form
    {
        NetworkStream serverStream;

        string chatmessage = "";
        TcpListener serverSocket = new TcpListener(8888);
        TcpClient clientSocket;
        TcpClient cliente1;
        TcpClient[] myTcpClients = new TcpClient[10];
        string[] MyNickClients = new string[10];

        int counter = 0;


        public Form1()
        {
            InitializeComponent();
            cliente1 = new TcpClient();

            // Inicializamos array de clientes
            for (int i = 0; i < 10; i++)
            {
                myTcpClients[i] = new TcpClient();
                MyNickClients[i] = "";
            }

            IniciaServer();
            Thread newThread = new Thread(Escucha);
            newThread.Start();            
        }
        // Constructor que no realice ninguna accion
        public Form1(int variable)
        {
            InitializeComponent();


        }

        public static Form1 _Form1;

        public void Escucha()
        {
            clientSocket = default(TcpClient);
          
            serverSocket.Start();

            while (true)
            {

                counter += 1;
                clientSocket = serverSocket.AcceptTcpClient();

                // Running on the worker thread
                textBox1.Invoke((MethodInvoker)delegate {
                    // Running on the UI thread
                    textBox1.Text = textBox1.Text + "\r\n"  +  " Cliente no:" + Convert.ToString(counter) + " Iniciado " ;

                });

                doChat();
          
            }

        }

        public   void escribe(string texto)
        {

            textBox1.Text = textBox1.Text + "\r\n" + texto ;

        }

        private void button1_Click(object sender, EventArgs e)
        {

            string comando = textBox2.Text;
            comando = comando.Trim();

            string[] comandoSplit = new string[3];

            comandoSplit = comando.Split(' ');

            if (comandoSplit[0] == "connect")
            {

                string[] connectSplit = new string[2];

                connectSplit = comandoSplit[1].Split(':');
                int puerto = Convert.ToInt32(connectSplit[1]);

                ClientConnect(ref connectSplit[0], ref puerto);


            }else if (comandoSplit[0] == "send")
            {

       

                // para varios clietes
                for (int i = 0; i < 10; i++)
                {
                    if (myTcpClients[i].Connected == true)
                    {
                        NetworkStream serverStream = myTcpClients[i].GetStream();
                        byte[] outStream = System.Text.Encoding.ASCII.GetBytes("Local: " + comando.Substring(5));
                        serverStream.Write(outStream, 0, outStream.Length);
                        serverStream.Flush();
                    }
                }

            }
            else
            {
                textBox1.Text = textBox1.Text + "\r\n" + "Comando no Soportado!!! ";
            }
            textBox2.Text = " ";

        }

        public void IniciaServer()
        {

            textBox1.Text = "Inicia Servidor" ;

            serverSocket.Start();


        }


        public void ClientConnect ( ref string ip, ref int port)
            {
            int NoServerConnect = 0;
            try
            {
               // cliente1.Connect(ip, port);
                
                //textBox1.Text = textBox1.Text + "\r\n" + " Conectado a Servidor";


                for (int i = 0; i < 10; i++)
                {
                    if (myTcpClients[i].Connected == false)
                    {
                        NoServerConnect = i;
                        break;
                    }
                    
                }
                myTcpClients[NoServerConnect].Connect(ip, port);
                textBox1.Text = textBox1.Text + "\r\n" + " Conectado a Servidor";

            }

            catch (IOException f)
            {
                // Extract some information from this exception, and then   
                // throw it to the parent method.  
                MessageBox.Show("IOException source: {0}", f.Source);
            }

        }

        public void sendmessage(ref string mensaje)
        {
            NetworkStream serverStream = cliente1.GetStream();
            byte[] outStream = System.Text.Encoding.ASCII.GetBytes(mensaje);
            serverStream.Write(outStream, 0, outStream.Length);
            serverStream.Flush();

        }

        private void doChat()
        {
            int requestCount = 0;
            byte[] bytesFrom = new byte[65536];
            string dataFromClient = null;
            byte[] sendBytes = new byte[65536];
            string serverResponse = null;
            string rCount = null;
            string[] dirs;
            requestCount = 0;


            while ((true))
            {
                try
                {
                    requestCount = requestCount + 1;
                    NetworkStream networkStream = clientSocket.GetStream();
                    networkStream.Read(bytesFrom, 0, (int)clientSocket.ReceiveBufferSize);
                    dataFromClient = System.Text.Encoding.ASCII.GetString(bytesFrom);

    

                    // Running on the worker thread
                    textBox1.Invoke((MethodInvoker)delegate {
                        // Running on the UI thread
                        textBox1.Text = textBox1.Text  + "\r\n" + dataFromClient ;

                    });



                }
                catch (Exception ex)
                {
                    //    Console.WriteLine(" >> " + ex.ToString());
                }
            }
        }
        public void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }
    }

}
