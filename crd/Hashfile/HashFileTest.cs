/*  Purpose   : Test Hashfile methods
 *  Functions : InsertKeys, FindKeys, DeleteKeys
 *  Author    : Rajesh Kayakkal
 *  email     : rajesh.kayakkal@bizken.com
 *  Date      : 20091009 (yyyymmdd)
 *  Version   : 1.1
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using HashFile;
using System.Diagnostics;

namespace HashFileTest1
{
    class Program
    {
        
        static void Main(string[] args)
        {

            //InsertKeys();  // read Test Keys from a file and submit it to HashFile.InsertKey()

            //DeleteKeys(); // read Test Keys from a file and submit it to HashFile.InsertKey()

            // FindKeys(); // read Test Keys from a file and submit it to HashFile.DeleteKey()



            TestGetKeys();  // Test Methods GetFirstKey, GetNextKey, GetPrevKey

            Console.ReadLine();
            

         
        }

        public static void TestGetKeys()
        {
            HashFile.HashFile HashFileTest1 = new HashFile.HashFile();
            HashFileTest1.Initialize("Test2", 50, 50);


            HashFileTest1.InsertKey("hello", "1",false);
            HashFileTest1.InsertKey("What", "2", false);
            HashFileTest1.InsertKey("Kelly", "3", false);

            HashFileTest1.GetFirstKey();

            int Success = HashFileTest1.GetFirstKey();
            switch(Success)
            {
                case -3:
                    Console.WriteLine("Error");
                    break;
                case -2:
                    Console.WriteLine("End");
                    break;
                case -1:
                    Console.WriteLine("Start");
                    break;
                default:
                Console.WriteLine(HashFileTest1.Key + "," + HashFileTest1.Value);
                break;
            }


            Success = HashFileTest1.GetNextKey();

            switch (Success)
            {
                case -3:
                    Console.WriteLine("Error");
                    break;
                case -2:
                    Console.WriteLine("End");
                    break;
                case -1:
                    Console.WriteLine("Start");
                    break;
                default:
                    Console.WriteLine(HashFileTest1.Key + "," + HashFileTest1.Value);
                    break;
            }


            Success = HashFileTest1.GetNextKey();

            switch (Success)
            {
                case -3:
                    Console.WriteLine("Error");
                    break;
                case -2:
                    Console.WriteLine("End");
                    break;
                case -1:
                    Console.WriteLine("Start");
                    break;
                default:
                    Console.WriteLine(HashFileTest1.Key + "," + HashFileTest1.Value);
                    break;
            }


            Success = HashFileTest1.GetNextKey();

            switch (Success)
            {
                case -3:
                    Console.WriteLine("Error");
                    break;
                case -2:
                    Console.WriteLine("End");
                    break;
                case -1:
                    Console.WriteLine("Start");
                    break;
                default:
                    Console.WriteLine(HashFileTest1.Key + "," + HashFileTest1.Value);
                    break;
            }


            Success = HashFileTest1.GetPrevKey();

            switch (Success)
            {
                case -3:
                    Console.WriteLine("Error");
                    break;
                case -2:
                    Console.WriteLine("End");
                    break;
                case -1:
                    Console.WriteLine("Start");
                    break;
                default:
                    Console.WriteLine(HashFileTest1.Key + "," + HashFileTest1.Value);
                    break;
            }

            Success = HashFileTest1.GetPrevKey();

            switch (Success)
            {
                case -3:
                    Console.WriteLine("Error");
                    break;
                case -2:
                    Console.WriteLine("End");
                    break;
                case -1:
                    Console.WriteLine("Start");
                    break;
                default:
                    Console.WriteLine(HashFileTest1.Key + "," + HashFileTest1.Value);
                    break;
            }

            Success = HashFileTest1.GetPrevKey();

            switch (Success)
            {
                case -3:
                    Console.WriteLine("Error");
                    break;
                case -2:
                    Console.WriteLine("End");
                    break;
                case -1:
                    Console.WriteLine("Start");
                    break;
                default:
                    Console.WriteLine(HashFileTest1.Key + "," + HashFileTest1.Value);
                    break;
            }

            Success = HashFileTest1.GetPrevKey();

            switch (Success)
            {
                case -3:
                    Console.WriteLine("Error");
                    break;
                case -2:
                    Console.WriteLine("End");
                    break;
                case -1:
                    Console.WriteLine("Start");
                    break;
                default:
                    Console.WriteLine(HashFileTest1.Key + "," + HashFileTest1.Value);
                    break;
            }


        }


      


        public static void InsertKeys()
        {

            HashFile.HashFile HashFileTest1 = new HashFile.HashFile();
            HashFileTest1.Initialize("Test1",50,50);

           StreamReader StreamReaderTestKeys = File.OpenText(@"D:\Documents and Settings\All Users\Documents\vs\EmailIDTEst\EmailIDTEst\bin\Debug\Keys.txt");
           //StreamReader StreamReaderTestKeys = File.OpenText(@"D:\Documents and Settings\All Users\Documents\vs\EmailIDTEst\EmailIDTEst\bin\Debug\Keys1.txt");

            Stopwatch StopWatchtest1 = new Stopwatch();
          
            int CountofTestKeys = 0;

            Console.WriteLine("Please Wait...");

            string TestKeyRecord = StreamReaderTestKeys.ReadLine();
            while (TestKeyRecord != null)
            {
                string[] TestKeyFields = TestKeyRecord.Split(' ',',');
                for (int i = 0; i < TestKeyFields.Length; i++)
                {
                    if (TestKeyFields[i].Contains("@"))
                    {                    
                        StopWatchtest1.Start();
                        int success = HashFileTest1.InsertKey(TestKeyFields[i].Trim(),CountofTestKeys.ToString(),false); // Call to HashFile.InsertKey
                        StopWatchtest1.Stop();

                        if (success < 1) // Failure to insert key
                            Console.WriteLine(TestKeyFields[i].Trim() + "," + success );

                        CountofTestKeys++;
                        
                    }
                }
                TestKeyRecord = StreamReaderTestKeys.ReadLine();
            }

            StreamReaderTestKeys.Close();
            Console.WriteLine("Records=" + CountofTestKeys + ",Ticks=" + StopWatchtest1.ElapsedTicks + ",Frequency=" + Stopwatch.Frequency + ",Average Write Time(ms)=" + (double)StopWatchtest1.ElapsedTicks / (double)Stopwatch.Frequency * 1000 / (double)CountofTestKeys + ", Avg Reads=" + (double)HashFileTest1.count / (double)CountofTestKeys);

        }

        public static void FindKeys()
        {

            HashFile.HashFile HashFileTest1 = new HashFile.HashFile();
            HashFileTest1.Initialize("Test1", 50, 50);

            StreamReader StreamReaderTestKeys = File.OpenText(@"D:\Documents and Settings\All Users\Documents\vs\EmailIDTEst\EmailIDTEst\bin\Debug\Keys.txt");

            //StreamReader StreamReaderTestKeys = File.OpenText(@"D:\Documents and Settings\All Users\Documents\vs\EmailIDTEst\EmailIDTEst\bin\Debug\Keys1.txt");

            Console.WriteLine("Please Wait...");

            Stopwatch StopWatchtest1 = new Stopwatch();
          
            int CountofTestKeys = 0;            
            string TestKeyRecord = StreamReaderTestKeys.ReadLine();
            while (TestKeyRecord != null)
            {
                string[] TestKeyFields = TestKeyRecord.Split(' ', ',');
                for (int i = 0; i < TestKeyFields.Length; i++)
                {
                    if (TestKeyFields[i].Contains("@"))
                    {
                        StopWatchtest1.Start();
                        uint success = HashFileTest1.FindKey(TestKeyFields[i].Trim()); // Call to HashFile.FindKey
                        StopWatchtest1.Stop();

                        if (success == uint.MaxValue) // Failure to find a key
                        {
                            Console.WriteLine(TestKeyFields[i].Trim());
                        }
                        else
                        {
                            //Console.WriteLine(hf.Key + "," + hf.Value + "," + hf.Flag);
                            // Console.Read();
                        }
                        CountofTestKeys++;
                    }
                }
                TestKeyRecord = StreamReaderTestKeys.ReadLine();
            }

            StreamReaderTestKeys.Close();
        
            Console.WriteLine("Records=" + CountofTestKeys + ",Ticks=" + StopWatchtest1.ElapsedTicks + ",Frequency=" + Stopwatch.Frequency + ",Average Read Time(ms)=" + (double)StopWatchtest1.ElapsedTicks / (double)Stopwatch.Frequency * 1000 / (double)CountofTestKeys + ", Avg Reads=" + (double)HashFileTest1.count / (double)CountofTestKeys);

        }

        public static void DeleteKeys()
        {

            HashFile.HashFile HashFileTest1 = new HashFile.HashFile();
            HashFileTest1.Initialize("Test1", 50, 50);

            //StreamReader StreamReaderTestKeys = File.OpenText(@"D:\Documents and Settings\All Users\Documents\vs\EmailIDTEst\EmailIDTEst\bin\Debug\Keys.txt");

            StreamReader StreamReaderTestKeys = File.OpenText(@"D:\Documents and Settings\All Users\Documents\vs\EmailIDTEst\EmailIDTEst\bin\Debug\keys1.txt");

            Console.WriteLine("Please Wait...");

            Stopwatch StopWatchtest1 = new Stopwatch();
         
            int CountofTestKeys = 0;
            string TestKeyRecord = StreamReaderTestKeys.ReadLine();
            while (TestKeyRecord != null)
            {
                string[] TestKeyFields = TestKeyRecord.Split(' ', ',');
                for (int i = 0; i < TestKeyFields.Length; i++)
                {
                    if (TestKeyFields[i].Contains("@"))
                    {
                        StopWatchtest1.Start();
                        uint success = HashFileTest1.DeleteKey(TestKeyFields[i].Trim()); // Call to HashFile.DeleteKey
                        StopWatchtest1.Stop();

                        if (success == uint.MaxValue) // Failure to Delete Key
                        {
                            Console.WriteLine(TestKeyFields[i].Trim());
                        }
                        else
                        {
                            //Console.WriteLine(hf.Key + "," + hf.Value + "," + hf.Flag);
                            // Console.Read();
                        }
                        CountofTestKeys++;
                    }
                }
                TestKeyRecord = StreamReaderTestKeys.ReadLine();
            }

            StreamReaderTestKeys.Close();       
            Console.WriteLine("Records=" + CountofTestKeys + ",Ticks=" + StopWatchtest1.ElapsedTicks + ",Frequency=" + Stopwatch.Frequency + ",Average Read Time(ms)=" + (double)StopWatchtest1.ElapsedTicks / (double)Stopwatch.Frequency * 1000 / (double)CountofTestKeys + ",Avg Reads=" + (double)HashFileTest1.count / (double)CountofTestKeys);

        }
       
    }
}
