

inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
����һ�乩���˾�ס�Ĵ��᷿�����ڼ���ʦ�ڱ���Ҳ������ͷ����
���ƽʱ���õ�����Ҳ�㲻�٣������������᷿׼���˺ܶ�䡣
LONG);


	set("exits", ([
		"north" : __DIR__"tingyuan",
	]));        
	setup();
	replace_program(ROOM);
}

