inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
������һ��ר�����߰��㶫����С���ӣ���˵������ʲô��������
����Ŀ��˺ܶ࣬��С��������æ����ͣ����Ϊ�ط�С�����������Ե�
����������
LONG );
	set("exits", ([
		"west" : __DIR__"nanjie",
	]));
	set("objects",([
	   __DIR__"npc/xiaoer2":1,
	   ]));
	setup();
	replace_program(ROOM);
}

