// /d/taiyuan/road7.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ������ڻƺ��ϵ����ţ�����ʮ����Ļƺ�������������
��ȥ��һ��紵�����������ζ����㲻����ץ�������Ե����ӡ�
LONG );
	set("exits", ([
		"west"  : __DIR__"road9",
 		"east"  : __DIR__"road9b",
        		
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



