// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�㳡");
	set("long", @LONG
����һ����㳡���㳡ռ�غܴ󣬹��ƿ���������ǧ�ˡ������Ǹ�
������̨���Ǹ����������ĵط���ÿ��������죬������ǧ��������
���ݣ��������׳�ۡ�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"southwest" : __DIR__"shanlu8",
        	"northup":__DIR__"tiantai",
	]));
       setup();
	
}

