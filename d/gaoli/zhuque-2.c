// /d/gaoli/zhuquedajie1
// Room in ����
inherit ROOM;
void create()	
{
	set("short", "��ʤ���");
	set("long", @LONG
������һ��������ʯ�����ϣ�����Ϳ쵽�����ʹ��ˡ������Կ�
���ʹ���Χǽ�������Ǹ��������ŵ�ʤ�ţ�����ĵ��̵��������һ��
���ĵ��֣�����������ϲ�������洫��ߺ��������������Ǹ�����һ
�Ҷĳ���
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"south" : __DIR__"zhuquemen",
		"north" : __DIR__"zhuque-1",
                "east":__DIR__"dangpu",
                "west":__DIR__"duchang",    
	]));
	set("objects",([
"/clone/npc/man":2,
          ]));
       setup();
	replace_program(ROOM);
}	
