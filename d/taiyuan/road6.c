// /d/taiyuan/road6.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "˫����");
	set("long", @LONG
˫������̫ԭ���Ͻ���ׯ���ϡ���������ʮ����(1608��)��ɮ���Ƿ�뷽��졣
������Ҫ������ȫΪש�����˽�ʮ��������54.7�ס������н���̤�����ɵǶ��㣬
ƾ��Զ����̫ԭ���������Ŀ�����ǳ���̫ԭ��˫������ӳ����������Ϊ̫ԭ��
��־������ĵ����أ���Ϊ������ֲ��
LONG );
	set("exits", ([
	       "north" : "/d/mayi/xiaolu2",
		"southwest" : __DIR__"road5",
                "southeast" : __DIR__"road7",
	]));

	set("outdoors", "taiyuan");
	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



