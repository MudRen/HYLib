// /d/taiyuan/beidajie2.c
// Room in ̫ԭ
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
����ֵ������Ѿ������ˣ����������Ĺ㳡��������������ˮ������
�������̫ԭ�й��ˣ����Ƕ��ǴҴҶ���,�����ⶺ����
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"beidajie1", 
                "south" : __DIR__"center", 
                "east" : __DIR__"xinggong", 
	]));
       setup();
	replace_program(ROOM);
}	
