// Room:kedian2.c
// congw 980830 

inherit ROOM;

void create()
{
string *order = ({"master1", "master2", "master3","master4","master5","master6","master7",
"master8","master9","master10","master11","master12","master13","master14","master15","master16"});
	set("short", "�͵��¥");
	set("long", @LONG
�������ڿ͵��¥�������ϣ����������ӿͷ��ﲻʱ�غ����Ĵ�����һ��߹�һ
�󡣲�ʱ��˯�����ʵ��ÿͽ�����������¥�µ��ƹ񴦸���Ǯ������˯����
LONG
	);

	set("exits", ([
		"down" : __DIR__"kedian",
		"enter" : __DIR__"kedian3",
	]));

	
	setup();
	replace_program(ROOM);
}

