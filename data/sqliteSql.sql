DROP TABLE IF EXISTS HardwareCPUModule_processor;
CREATE TABLE IF NOT EXISTS HardwareCPUModule_processor (id INTEGER PRIMARY KEY, val1 VARCHAR(200) NOT NULL, val2 VARCHAR(200), val3 VARCHAR(200), val4 VARCHAR(200));
INSERT INTO HardwareCPUModule_processor VALUES(1,'processor',NULL,NULL,NULL);
INSERT INTO HardwareCPUModule_processor VALUES(2,':/icons/48x48/devices/cpu.png','Processor ',NULL,NULL);
INSERT INTO HardwareCPUModule_processor VALUES(3,'model name',NULL,NULL,NULL);
INSERT INTO HardwareCPUModule_processor VALUES(4,'vendor_id','Vendor: ',NULL,NULL);
INSERT INTO HardwareCPUModule_processor VALUES(5,'cpu family','Family: ',NULL,NULL);
INSERT INTO HardwareCPUModule_processor VALUES(6,'model','model name','Model: ',NULL);
INSERT INTO HardwareCPUModule_processor VALUES(7,'stepping','Revision: ',NULL,NULL);
INSERT INTO HardwareCPUModule_processor VALUES(8,'cpu MHz','bogomips',' - Bogomips: ','Frequency: ');
DROP TABLE IF EXISTS prueba;
CREATE TABLE IF NOT EXISTS prueba (id int primary key, texto varchar(20));
INSERT INTO prueba VALUES(1,'hooolaaa');

